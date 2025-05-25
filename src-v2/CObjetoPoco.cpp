#include "CObjetoPoco.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <numbers>
#include <math.h>


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


CObjetoPoco CObjetoPoco::CriarParaModulo02(std::string nomeDoPoco, double profundidadeFinalDoPoco, double pressaoNaSuperficie,
                                           double temperaturaTopoInicial, double temperaturaFundoInicial,
                                           double temperaturaTopoFinal, double temperaturaFundoFinal, double profundidadeDoPacker) {
    CObjetoPoco objetoPoco;

    objetoPoco.nomePoco = nomeDoPoco;
    objetoPoco.profundidadeFinal = profundidadeFinalDoPoco;
    objetoPoco.pressaoSuperficie = pressaoNaSuperficie;
    objetoPoco.temperaturaTopoInicial = temperaturaTopoInicial;
    objetoPoco.temperaturaFundoInicial = temperaturaFundoInicial;
    objetoPoco.temperaturaTopoFinal = temperaturaTopoFinal;
    objetoPoco.temperaturaFundoFinal = temperaturaFundoFinal;
    objetoPoco.profundidadePacker = profundidadeDoPacker;

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

#include <QDebug>

double CObjetoPoco::CargaInicial(double profundidade) const {
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

        // Caso 3: considerando as Cargas por efeito pistão
        cargaTotal += VariacaoCargaEfeitoPistao(profundidade);


    }

    return cargaTotal;
}






double CObjetoPoco::DeltaLTemperatura(double profundidade) const {
    double deltaLTotal = 0.0;

    for (const auto& trecho : trechos) {
        double z_i = trecho->ProfundidadeInicial();
        double z_f = trecho->ProfundidadeFinal();
        double ct = trecho->CoeficienteExpancaoTermica();
        double z_medio = (TemperaturaNoPonto(z_i) + TemperaturaNoPonto(z_f)) / 2.0;
        double deltaT = TemperaturaTopoInicial() - z_medio;
        double L = 0.0;

        if (profundidade >= z_i && profundidade <= z_f) {
            L = profundidade - z_i;
            deltaLTotal += ct * L * deltaT;
        } else if (z_f < profundidade) {
            L = z_f - z_i;
            deltaLTotal += ct * L * deltaT;
        }
    }

    return deltaLTotal;
}

double CObjetoPoco::TemperaturaNoPonto(double profundidade) const {

    double inclinacao = (TemperaturaFundoInicial() - TemperaturaTopoInicial()) / ProfundidadeOcupada();
    double temperatura = TemperaturaTopoInicial() + inclinacao * profundidade;
    return temperatura;

}

double CObjetoPoco::VariacaoCargaEfeitoPistao(double profundidade) const {
    double pi = 3.141592653589793;
    double variacaoTotal = 0.0;

    if (trechos.size() < 2)
        return 0.0;

    // Varre todas as interfaces abaixo da profundidade fornecida
    for (size_t i = 1; i < trechos.size(); ++i) {
        const auto& trechoAcima = trechos[i - 1];
        const auto& trechoAbaixo = trechos[i];

        double z_interface = trechoAbaixo->ProfundidadeInicial();

        if ((z_interface - profundidade) > 1e-6) {
            double ID_acima = trechoAcima->DiametroInterno();
            double ID_abaixo = trechoAbaixo->DiametroInterno();
            double OD_acima = trechoAcima->DiametroExterno();
            double OD_abaixo = trechoAbaixo->DiametroExterno();

            if (std::abs(ID_acima - ID_abaixo) < 1e-6 &&
                std::abs(OD_acima - OD_abaixo) < 1e-6) {
                continue;
            }

            // Diferenca de area: sempre acima - abaixo
            double Ai = (pi / 4.0) * (ID_acima * ID_acima - ID_abaixo * ID_abaixo);
            double Ao = (pi / 4.0) * (OD_acima * OD_acima - OD_abaixo * OD_abaixo);
            double pressao = PressaoHidroestaticaNoPonto(z_interface);

            double variacaoCarga = pressao * (Ai - Ao);
            variacaoTotal += variacaoCarga;
        }
    }

    return variacaoTotal;
}
