#include "CObjetoPoco.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <numbers>
#include <math.h>
#include <QDebug>


CObjetoPoco CObjetoPoco::CriarParaModulo01(std::string nomeDoPoco, double profundidadeFinalDoPoco, double pressaoNaSuperficie,
                                           double diametroDoPoco, double diametroRevestimentoExterno, double diametroRevestimentoInterno, double vazaoDoPoco) {
    CObjetoPoco objetoPoco;

    objetoPoco.nomePoco = nomeDoPoco;
    objetoPoco.profundidadeFinal = profundidadeFinalDoPoco;
    objetoPoco.pressaoSuperficie = pressaoNaSuperficie;
    objetoPoco.diametroPoco = diametroDoPoco;
    objetoPoco.diametroRevestimentoOD = diametroRevestimentoExterno;
    objetoPoco.diametroRevestimentoID = diametroRevestimentoInterno;
    objetoPoco.vazao = vazaoDoPoco;

    return objetoPoco;
}


CObjetoPoco CObjetoPoco::CriarParaModulo02(std::string nomeDoPoco, double profundidadeFinalDoPoco, double diamPoco, double pressaoNaSuperficie, double pressaoNaSuperficieFim,
                                           double temperaturaTopoInicial, double temperaturaFundoInicial,
                                           double temperaturaTopoFinal, double temperaturaFundoFinal, bool haPacker) {
    CObjetoPoco objetoPoco;

    objetoPoco.nomePoco = nomeDoPoco;
    objetoPoco.profundidadeFinal = profundidadeFinalDoPoco;
    objetoPoco.diametroPoco = diamPoco;
    objetoPoco.pressaoSuperficie = pressaoNaSuperficie;
    objetoPoco.pressaoSuperficieFim = pressaoNaSuperficieFim;
    objetoPoco.temperaturaTopoInicial = temperaturaTopoInicial;
    objetoPoco.temperaturaFundoInicial = temperaturaFundoInicial;
    objetoPoco.temperaturaTopoFinal = temperaturaTopoFinal;
    objetoPoco.temperaturaFundoFinal = temperaturaFundoFinal;
    objetoPoco.packer = haPacker;

    return objetoPoco;
}


std::vector<CTrechoPoco*> CObjetoPoco::Trechos() const {
    std::vector<CTrechoPoco*> vetorDePonteirosParaTrechos;

    // percorre todos os trechos armazenados no poço
    for (const auto& trechoUnico : trechos) {
        // adiciona o ponteiro cru (não único) de cada trecho ao vetor de saída
        vetorDePonteirosParaTrechos.push_back(trechoUnico.get());
    }

    // retorna o vetor contendo os ponteiros dos trechos
    return vetorDePonteirosParaTrechos;
}

bool CObjetoPoco::AdicionarTrechoPoco(std::unique_ptr<CTrechoPoco> trechoParaAdicionar) {
    // calcula o comprimento do trecho com base nas profundidades inicial e final
    double comprimentoDoTrecho = trechoParaAdicionar->ProfundidadeFinal() - trechoParaAdicionar->ProfundidadeInicial();

    // move o trecho para dentro do vetor principal do poço
    trechos.push_back(std::move(trechoParaAdicionar));

    // atualiza a profundidade total ocupada no poço somando o novo trecho
    profundidadeOcupada += comprimentoDoTrecho;

    return true; // operação realizada com sucesso
}


void CObjetoPoco::RemoverFluidoPoco(const std::string& nomeFluido) {
    for (auto it = trechos.begin(); it != trechos.end();) {
        if ((*it)->Fluido()->Nome() == nomeFluido) {
            double comprimento = (*it)->ProfundidadeFinal() - (*it)->ProfundidadeInicial();
            it = trechos.erase(it);
            profundidadeOcupada -= comprimento;
        } else {
            ++it;
        }
    }
}

void CObjetoPoco::RemoverTrechoPoco(const std::string& nomeTrecho) {
    for (auto it = trechos.begin(); it != trechos.end();) {
        if ((*it)->Nome() == nomeTrecho) {
            double comprimento = (*it)->ProfundidadeFinal() - (*it)->ProfundidadeInicial();
            it = trechos.erase(it);
            profundidadeOcupada -= comprimento;
        } else {
            ++it;
        }
    }
}

double CObjetoPoco::PressaoHidroestaticaTotal() const {
    double pressaoTotalHidrostatica = 0.0;

    // soma a pressao hidrostatica de todos os trechos do poço
    for (const auto& trechoAtual : trechos) {
        pressaoTotalHidrostatica += trechoAtual->PressaoHidroestatica();
    }

    // adiciona a pressao da superficie para obter a pressao total
    return pressaoTotalHidrostatica + pressaoSuperficie;
}

double CObjetoPoco::PressaoHidroestaticaNoPonto(double profundidadeDesejada) const {
    double pressaoAcumulada = pressaoSuperficie;
    double profundidadeJaCalculada = 0.0;

    // percorre cada trecho verificando se ele contem a profundidade desejada
    for (const auto& trechoAtual : trechos) {
        double comprimentoDoTrecho = trechoAtual->ProfundidadeFinal() - trechoAtual->ProfundidadeInicial();

        // se a profundidade estiver dentro do trecho atual
        if (profundidadeDesejada <= profundidadeJaCalculada + comprimentoDoTrecho) {
            double profundidadeDentroDoTrecho = profundidadeDesejada - profundidadeJaCalculada;

            // adiciona somente a parte proporcional da pressao no trecho
            pressaoAcumulada += trechoAtual->PressaoHidroestatica(profundidadeDentroDoTrecho);
            break;
        } else {
            // adiciona a pressao total do trecho completo
            pressaoAcumulada += trechoAtual->PressaoHidroestatica();
            profundidadeJaCalculada += comprimentoDoTrecho;
        }
    }

    return pressaoAcumulada;
}

bool CObjetoPoco::VerificarPreenchimentoColuna() {
    double profundidadeNaoPreenchida = profundidadeFinal - profundidadeOcupada;

    if (profundidadeNaoPreenchida > 0) {
        std::cout << "Uma coluna de " << profundidadeNaoPreenchida << " ft de fluido precisa ser adicionada!" << std::endl;
        return false; // coluna incompleta
    } else {
        std::cout << "A coluna de fluidos equivale à profundidade total do poço!" << std::endl;
        return true; // coluna completamente preenchida
    }
}


double CObjetoPoco::DensidadeEfetivaTotal() const {
    double somaDensidadePonderada = 0.0;
    double comprimentoTotalDaColuna = 0.0;

    for (const auto& trechoAtual : trechos) {
        double comprimentoTrecho = trechoAtual->ProfundidadeFinal() - trechoAtual->ProfundidadeInicial();

        // multiplica a densidade equivalente pelo comprimento do trecho para ponderar
        somaDensidadePonderada += trechoAtual->DensidadeEquivalente() * comprimentoTrecho;
        comprimentoTotalDaColuna += comprimentoTrecho;
    }

    return somaDensidadePonderada / comprimentoTotalDaColuna;
}

double CObjetoPoco::ViscosidadeEfetivaTotal() const {
    double somaDasViscosidades = 0.0;

    // percorre todos os trechos para somar as viscosidades dos fluidos
    for (const auto& trechoAtual : trechos) {
        somaDasViscosidades += trechoAtual->Fluido()->Viscosidade();
    }

    // retorna a media simples das viscosidades
    return somaDasViscosidades / trechos.size();
}

std::pair<std::vector<double>, std::vector<double>> CObjetoPoco::PlotarProfundidadePorPressaoMedia() {
    std::vector<double> vetorDeProfundidades;
    std::vector<double> vetorDePressoes;

    // percorre cada metro ao longo da profundidade total do poço
    for (double profundidadeAtual = 0.0; profundidadeAtual <= ProfundidadeTotal(); profundidadeAtual += 1.0) {
        vetorDeProfundidades.push_back(profundidadeAtual);

        // calcula a pressao no ponto atual usando a funcao apropriada
        double pressaoNoPonto = PressaoHidroestaticaNoPonto(profundidadeAtual);
        vetorDePressoes.push_back(pressaoNoPonto);
    }

    // retorna as duas listas para serem usadas na geracao do grafico
    return std::make_pair(vetorDeProfundidades, vetorDePressoes);
}

double CObjetoPoco::Carga(double profundidade, bool inicio) const {
    double cargaTotal = 0.0;
    double pi = 3.141592653589793;

    if (trechos.empty())
        return 0.0;

    // 1. Pressao no fundo do poco (base)
    double profundidadeBase = 0.0;
    double OD_base = 0.0;
    double ID_base = 0.0;

    for (const auto& trecho : trechos) {
        if (trecho->ProfundidadeFinal() > profundidadeBase) {
            profundidadeBase = trecho->ProfundidadeFinal();
            OD_base = trecho->DiametroExterno();
            ID_base = trecho->DiametroInterno();
        }
    }

    // 2. Carga por pressao no fundo (negativa)
    double pressaoBase = PressaoHidroestaticaNoPonto(profundidadeBase);
    if (inicio == false){
        pressaoBase = PressaoHidroestaticaNoPonto(profundidadeBase) + PressaoSuperficieFim();
    }

    double areaBase = (pi / 4.0) * (OD_base * OD_base - ID_base * ID_base);
    double cargaPressao = -1.0 * pressaoBase * areaBase;
    cargaTotal += cargaPressao;

    // 3. Soma pesos de trechos abaixo da profundidade
    for (const auto& trecho : trechos) {
        double z_i = trecho->ProfundidadeInicial();
        double z_f = trecho->ProfundidadeFinal();
        double pesoUnit = trecho->PesoUnidade();

        // Caso 1: trecho totalmente abaixo da profundidade
        if (z_i >= profundidade) {
            double L_total = z_f - z_i;
            double cargaPeso = L_total * pesoUnit;
            cargaTotal += cargaPeso;
        }

        // Caso 2: profundidade dentro do trecho
        else if (profundidade > z_i && profundidade < z_f) {
            double L_parcial = z_f - profundidade;
            double cargaPeso = L_parcial * pesoUnit;
            cargaTotal += cargaPeso;

        }

    }

    // 4. considerando as Cargas por efeito pistão
    if (inicio){
        cargaTotal += VariacaoCargaDevidoCrossover(profundidade, false, true);
    }
    else{
        cargaTotal += VariacaoCargaDevidoCrossover(profundidade, false, false);
    }

    return cargaTotal;
}

double CObjetoPoco::DeltaLTemperatura(double profundidade) const {
    double deltaLTotal = 0.0;

    for (const auto& trecho : trechos) {
        double z_i = trecho->ProfundidadeInicial();
        double z_f = trecho->ProfundidadeFinal();
        double ct = trecho->CoeficienteExpancaoTermica();

        // Ignora trechos que estao totalmente abaixo da profundidade informada
        if (z_i >= profundidade)
            continue;

        // Calcula temperatura media inicial e final do trecho
        double tMedioInicial = (
                                   TemperaturaNoPonto(z_i, TemperaturaTopoInicial(), TemperaturaFundoInicial()) +
                                   TemperaturaNoPonto(z_f, TemperaturaTopoInicial(), TemperaturaFundoInicial())
                                   ) / 2.0;

        double tMedioFinal = (
                                 TemperaturaNoPonto(z_i, TemperaturaTopoFinal(), TemperaturaFundoFinal()) +
                                 TemperaturaNoPonto(z_f, TemperaturaTopoFinal(), TemperaturaFundoFinal())
                                 ) / 2.0;

        // Variacao de temperatura final - inicial
        double deltaT = tMedioFinal - tMedioInicial;

        // Caso raro onde nao houve variacao de temperatura entre as duas condicoes
        // A gente força um deltaT usando a temperatura no ponto zero como referencia
        if (deltaT == 0) {
            double media = (
                               TemperaturaNoPonto(z_i, TemperaturaTopoFinal(), TemperaturaFundoFinal()) +
                               TemperaturaNoPonto(z_f, TemperaturaTopoFinal(), TemperaturaFundoFinal())
                               ) / 2.0;

            deltaT = TemperaturaNoPonto(0, TemperaturaTopoFinal(), TemperaturaFundoFinal()) - media;
        }

        double L = 0.0;

        // Se a profundidade estiver dentro do trecho, calcula o comprimento parcial
        if (profundidade > z_i && profundidade < z_f) {
            L = profundidade - z_i;
        }
        // Se o trecho estiver totalmente acima da profundidade, considera L total
        else if (z_f <= profundidade) {
            L = z_f - z_i;
        }

        // Soma o deltaL do trecho na variavel acumuladora
        deltaLTotal += ct * L * deltaT;
    }

    return deltaLTotal;
}




double CObjetoPoco::TemperaturaNoPonto(double profundidade, double T_topo, double T_Fundo) const {

    double inclinacao = (T_Fundo - T_topo) / ProfundidadeOcupada();
    double temperatura = T_topo + inclinacao * profundidade;
    return temperatura;

}

double CObjetoPoco::VariacaoCargaDevidoCrossover(double profundidade, bool deCimaParaBaixo, bool inicio) const {
    double pi = 3.141592653589793;
    double variacao_total = 0.0;

    // tolerancia para comparacoes de ponto flutuante
    constexpr double tolerancia = 1e-5;

    if (trechos.size() < 2)
        return 0.0;

    // percorre todas as interfaces entre os trechos consecutivos
    for (size_t i = 1; i < trechos.size(); ++i) {
        const auto& trecho_acima = trechos[i - 1];
        const auto& trecho_abaixo = trechos[i];

        double z_interface = trecho_abaixo->ProfundidadeInicial();

        // define se a interface deve ser considerada com base na direcao da analise
        bool considerar = false;
        if (!deCimaParaBaixo && z_interface >= profundidade - tolerancia)
            considerar = true;
        if ( deCimaParaBaixo && z_interface <= profundidade + tolerancia)
            considerar = true;

        if (!considerar)
            continue;

        // coleta diametros internos e externos dos dois trechos
        double ID_acima = trecho_acima->DiametroInterno();
        double ID_abaixo = trecho_abaixo->DiametroInterno();
        double OD_acima = trecho_acima->DiametroExterno();
        double OD_abaixo = trecho_abaixo->DiametroExterno();

        // se nao houver mudanca de diametro, nao ha efeito pistao
        if (std::abs(ID_acima - ID_abaixo) < 1e-6 &&
            std::abs(OD_acima - OD_abaixo) < 1e-6) {
            continue;
        }

        // calcula diferenca de area interna e externa
        double Ai = (pi / 4.0) * (ID_acima * ID_acima - ID_abaixo * ID_abaixo);
        double Ao = (pi / 4.0) * (OD_acima * OD_acima - OD_abaixo * OD_abaixo);

        // pressao no ponto da interface
        double pressao = PressaoHidroestaticaNoPonto(z_interface);
        double carga_crossover = 0.0;

        // tratamento com ou sem packer
        if (Packer()) {
            if (inicio) {
                // no inicio da coluna: pressao interna = externa = pressao hidrostática
                carga_crossover = pressao * (Ai - Ao);
            } else {
                // no fim da coluna: pressao interna = pressao hidrostática + pressao superficial final
                carga_crossover = (pressao - (pressao + PressaoSuperficieFim())) * Ai;
            }
        } else {
            // sem packer: pressao interna e externa sao iguais
            carga_crossover = pressao * (Ai - Ao);
        }

        variacao_total += carga_crossover;
    }

    return variacao_total;
}


#include <QDebug>
double CObjetoPoco::VariacaoCargaEfeitoPistao(double profundidade, double ID, double OD) const {
    const double pi = 3.141592653589793;

    // Área da parede interna do tubo
    double Ain = (pi / 4.0) * (OD * OD - ID * ID);


    double Aout = Ain;


    // Pressões internas
    double Pin_inicio = PressaoHidroestaticaNoPonto(profundidade) + PressaoSuperficie();
    double Pin_fim = PressaoHidroestaticaNoPonto(profundidade) + PressaoSuperficieFim();
    double deltaPin = Pin_fim - Pin_inicio;

    // Pressões externas
    double Pout_inicio;
    double Pout_fim;

    if (Packer() == true) {
        Pout_inicio = 0;
        Pout_fim = 0;
    } else {
        Pout_inicio = 0;
        Pout_fim = 0;
    }

    double deltaPout = Pout_fim - Pout_inicio;

    // Resultado final
    if (Packer() == true) {
        return -deltaPin * Ain - deltaPout * Aout;
    } else {
        return deltaPin * Ain - deltaPout * Aout;

    }
}

double CObjetoPoco::DeltaLPistaoPacker(double profundidade) const {
    double pi = 3.141592653589793;
    double deltaL_total = 0.0;

    // verifica se ha qualquer mudanca de diametro externo entre os trechos
    bool possuiDiferencaOD = false;
    double primeiroOD = trechos[0]->DiametroExterno();
    for (const auto& trecho : trechos) {
        if (std::abs(trecho->DiametroExterno() - primeiroOD) > 1e-6) {
            possuiDiferencaOD = true;
            break;
        }
    }

    for (size_t i = 0; i < trechos.size(); ++i) {
        const auto& trecho = trechos[i];
        double z_i = trecho->ProfundidadeInicial();
        double z_f = trecho->ProfundidadeFinal();
        double OD = trecho->DiametroExterno();
        double ID = trecho->DiametroInterno();
        double E = trecho->ModuloEslasticidade();

        double area_anular = (pi / 4.0) * (OD * OD - ID * ID);
        if (E <= 0.0 || area_anular <= 0.0)
            continue;

        double L = 0.0;

        if (profundidade > z_i && profundidade < z_f) {
            L = profundidade - z_i;
        } else if (z_f <= profundidade) {
            L = z_f - z_i;
        } else {
            continue;
        }

        double CargaPistao = 0.0;
        if (possuiDiferencaOD) {
            // qualquer mudanca de OD: usa ID e OD do trecho
            CargaPistao = VariacaoCargaEfeitoPistao(z_i, ID, OD);
        } else {
            // todos os trechos iguais: usa ID e o diametro total do poco
            CargaPistao = VariacaoCargaEfeitoPistao(z_i, ID, DiametroPoco());
        }

        double deltaL_trecho = (CargaPistao * L) / (E * area_anular);
        deltaL_total += deltaL_trecho;
    }

    return deltaL_total;
}



double CObjetoPoco::DeltaLEfeitoBalao(double profundidade) const {
    double pi = 3.141592653589793;
    double deltaL_total = 0.0;

    for (size_t i = 0; i < trechos.size(); ++i) {
        const auto& trecho = trechos[i];
        double z_i = trecho->ProfundidadeInicial();
        double z_f = trecho->ProfundidadeFinal();
        double OD = trecho->DiametroExterno();
        double ID = trecho->DiametroInterno();
        double E = trecho->ModuloEslasticidade();
        double v = trecho->CoeficientePoisson();

        double area_anular = (pi / 4.0) * (OD * OD - ID * ID);

        if (E <= 0.0 || area_anular <= 0.0)
            continue;

        double L = 0.0;

        if (profundidade > z_i && profundidade < z_f) {
            // trecho parcialmente acima da profundidade
            L = profundidade - z_i;
        } else if (z_f <= profundidade) {
            // trecho totalmente acima da profundidade
            L = z_f - z_i;
        } else {
            continue; // trecho abaixo da profundidade, ignora
        }

        double CargaPistao = VariacaoCargaEfeitoPistao(z_i, 0, ID);
        double deltaL_trecho =  2 * v *(CargaPistao * (L)) / (E * area_anular); // o x12 é uma unidade de conversão de ft para in

        deltaL_total += deltaL_trecho;
    }

    return deltaL_total;
}

double CObjetoPoco::DeltaLPistaoCrossover(double profundidade) const {
    double pi = 3.141592653589793;
    double deltaL_total = 0.0;

    for (size_t i = 1; i < trechos.size(); ++i) {
        const auto& trechoAcima = trechos[i - 1];
        const auto& trechoAbaixo = trechos[i];

        // Profundidade onde ocorre a mudanca de trecho
        double z_interface = trechoAbaixo->ProfundidadeInicial();

        // Ignora se a interface estiver abaixo da profundidade analisada
        if (z_interface > profundidade)
            continue;

        // Coleta os diametros externos para comparar se ha mudanca
        double OD_acima = trechoAcima->DiametroExterno();
        double ID_acima = trechoAcima->DiametroInterno();
        double OD_abaixo = trechoAbaixo->DiametroExterno();

        // Se os diametros forem quase iguais, nao ha efeito pistao relevante
        if (std::abs(OD_acima - OD_abaixo) < 1e-6)
            continue;

        // Area da secao transversal da coluna acima (quem vai deformar)
        double area_secao = (pi / 4.0) * (OD_acima * OD_acima - ID_acima * ID_acima);

        // Obtem o modulo de elasticidade medio entre os dois trechos
        double E1 = trechoAcima->ModuloEslasticidade();
        double E2 = trechoAbaixo->ModuloEslasticidade();
        double E_medio = (E1 + E2) / 2.0;

        if (E_medio <= 0.0 || area_secao <= 0.0)
            continue;

        // Carga causada pelo efeito pistao na interface
        double cargaPistao = VariacaoCargaEfeitoPistao(z_interface, OD_abaixo, OD_acima);

        // L = comprimento da coluna acima da interface
        double L = z_interface;

        // Deformacao axial provocada pela carga
        double deltaL = (cargaPistao * L) / (E_medio * area_secao);
        deltaL_total += deltaL;
    }

    return deltaL_total;
}

double CObjetoPoco::DeltaLForcaRestauradora(double profundidade) const{

    double deltaLTemperatura = DeltaLTemperatura(profundidade);
    double deltaLBalao = DeltaLEfeitoBalao(profundidade);
    double deltaLPacker = DeltaLPistaoPacker(profundidade);
    double deltaLCrossover = DeltaLPistaoCrossover(profundidade);

    return deltaLTemperatura + deltaLBalao + deltaLPacker + deltaLCrossover;

}

double CObjetoPoco::CargaInjecao(double profundidade) const {
    const double pi = 3.141592653589793;
    double denominador = 0.0;

    // Deformacao total desejada
    double deltaL = DeltaLForcaRestauradora(profundidade);

    for (const auto& trecho : trechos) {
        double z_i = trecho->ProfundidadeInicial();
        double z_f = trecho->ProfundidadeFinal();

        // Pula trechos abaixo da profundidade desejada
        if (z_i > profundidade)
            continue;

        double limiteSuperior = std::min(z_f, profundidade);
        double comprimentoUtil = limiteSuperior - z_i;

        if (comprimentoUtil <= 0.0)
            continue;

        double E = trecho->ModuloEslasticidade();
        double OD = trecho->DiametroExterno();
        double ID = trecho->DiametroInterno();
        double area = (pi / 4.0) * (OD * OD - ID * ID);

        // soma das flexibilidades: L / (E*A)
        denominador += comprimentoUtil / (E * area);
    }

    if (denominador == 0.0)
        return 0.0;

    // pressao = deformacao total / soma das flexibilidades
    return deltaL / denominador;
}

