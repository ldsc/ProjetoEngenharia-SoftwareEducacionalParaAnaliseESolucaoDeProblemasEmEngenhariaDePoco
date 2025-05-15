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


void CObjetoPoco::RemoverTrechoPoco(const std::string& nomeFluido) {
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

double CObjetoPoco::CargaInicial(double profundidadeAlvo) const {
    const double pi = 3.141592653589793;
    double cargaTotal = 0.0;

    // === 1. Pressao hidrostática interna no ponto analisado ===
    for (const auto& trechoAtual : trechos) {
        if (profundidadeAlvo >= trechoAtual->ProfundidadeInicial() &&
            profundidadeAlvo <= trechoAtual->ProfundidadeFinal()) {

            double diametroInterno = trechoAtual->DiametroInterno(); // polegadas
            double areaInterna = pi / 4.0 * (diametroInterno * diametroInterno); // in²

            double densidadeFluido = trechoAtual->Fluido()->Densidade(); // lb/gal
            double pressaoNoPonto = 0.052 * densidadeFluido * profundidadeAlvo; // psi

            double forcaInterna = pressaoNoPonto * areaInterna; // lbf
            cargaTotal += forcaInterna;

            break; // só considera o primeiro trecho que cobre a profundidade
        }
    }

    // === 2. Efeito pistao (crossovers acima do ponto) ===
    for (size_t i = 1; i < trechos.size(); ++i) {
        const auto& trechoAcima = trechos[i - 1];
        const auto& trechoAbaixo = trechos[i];

        double profundidadeCrossover = trechoAbaixo->ProfundidadeInicial();

        if (profundidadeCrossover >= profundidadeAlvo)
            continue;

        double densidadeInterna = trechoAcima->Fluido()->Densidade();
        double densidadeExterna = trechoAbaixo->Fluido()->Densidade();

        double pressaoInterna = 0.052 * densidadeInterna * profundidadeCrossover;
        double pressaoExterna = 0.052 * densidadeExterna * profundidadeCrossover;

        double areaInterna = pi / 4.0 * pow(trechoAcima->DiametroInterno(), 2);
        double areaExterna = pi / 4.0 * pow(trechoAbaixo->DiametroExterno(), 2);

        double forcaPistao = pressaoInterna * areaInterna + pressaoExterna * areaExterna;
        cargaTotal += forcaPistao;
    }

    // === 3. Peso da coluna acima da profundidade ===
    for (const auto& trechoAtual : trechos) {
        double profundidadeInicialTrecho = trechoAtual->ProfundidadeInicial();
        double profundidadeFinalTrecho = trechoAtual->ProfundidadeFinal();

        if (profundidadeFinalTrecho <= profundidadeAlvo)
            continue;

        double profundidadeUtil = std::max(profundidadeAlvo, profundidadeInicialTrecho);
        double comprimentoConsiderado = profundidadeFinalTrecho - profundidadeUtil;

        if (comprimentoConsiderado > 0.0) {
            double pesoPorMetro = trechoAtual->PesoUnidade(); // lb/ft
            double pesoTotal = pesoPorMetro * comprimentoConsiderado;
            cargaTotal += pesoTotal;
        }
    }

    return cargaTotal;
}

double CObjetoPoco::DeltaLTemperaturaTotal() const {
    double variacaoTotalComprimento = 0.0;
    double temperaturaReferencia = TemperaturaTopoInicial(); // temperatura do topo como base

    for (const auto& trechoAtual : trechos) {
        double profundidadeInicial = trechoAtual->ProfundidadeInicial();
        double profundidadeFinal = trechoAtual->ProfundidadeFinal();
        double comprimentoTrecho = profundidadeFinal - profundidadeInicial;

        if (comprimentoTrecho <= 0.0)
            continue; // ignora trechos nulos ou invertidos

        double coefExpansaoTermica = trechoAtual->CoeficienteExpancaoTermica();

        // temperatura média do trecho considerando variação linear
        double temperaturaInicial = TemperaturaNoPonto(profundidadeInicial);
        double temperaturaFinal = TemperaturaNoPonto(profundidadeFinal);
        double temperaturaMedia = (temperaturaInicial + temperaturaFinal) / 2.0;

        double variacaoTemperatura = temperaturaReferencia - temperaturaMedia;

        // aplica a fórmula de dilatação linear: ΔL = α * L * ΔT
        double deltaComprimento = coefExpansaoTermica * comprimentoTrecho * variacaoTemperatura;
        variacaoTotalComprimento += deltaComprimento;
    }

    return variacaoTotalComprimento;
}


double CObjetoPoco::TemperaturaNoPonto(double profundidadeDesejada) const {
    double temperaturaNoTopo = TemperaturaTopoInicial();
    double temperaturaNoFundo = TemperaturaFundoInicial();
    double profundidadeTotalDoPoco = ProfundidadeTotal();

    // evita divisão por zero no caso de profundidade inválida
    if (profundidadeTotalDoPoco <= 0.0)
        return temperaturaNoTopo;

    // aplica interpolação linear para calcular a temperatura no ponto
    return temperaturaNoTopo + (temperaturaNoFundo - temperaturaNoTopo) * (profundidadeDesejada / profundidadeTotalDoPoco);
}
