#include "CObjetoPoco.h"
//#include "CGnuplot.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>


CPoco CPoco::CriarParaModulo01(std::string nome, double profund, double pressao,
                               double D, double OD, double ID, double q) {
    CPoco poco;
    poco.nomePoco = nome;
    poco.profundidadeFinal = profund;
    poco.pressaoSuperficie = pressao;
    poco.diametroPoco = D;
    poco.diametroRevestimentoOD = OD;
    poco.diametroRevestimentoID = ID;
    poco.vazao = q;
    return poco;
}

CPoco CPoco::CriarParaModulo02(std::string nome, double profund, double pressao,
                               double tempTopoIni, double tempFundoIni,
                               double tempTopoFim, double tempFundoFim) {
    CPoco poco;
    poco.nomePoco = nome;
    poco.profundidadeFinal = profund;
    poco.pressaoSuperficie = pressao;
    poco.temperaturaTopoInicial = tempTopoIni;
    poco.temperaturaFundoInicial = tempFundoIni;
    poco.temperaturaTopoFinal = tempTopoFim;
    poco.temperaturaFundoFinal = tempFundoFim;
    return poco;
}

// Metodos

std::vector<CTrechoPoco*> CPoco::Trechos() const {
    std::vector<CTrechoPoco*> trechosPonteiros;
    for (const auto& trecho : trechos) {
        trechosPonteiros.push_back(trecho.get()); // Adiciona o ponteiro do trecho ao vetor
    }
    return trechosPonteiros; // Retorna o vetor de ponteiros
}

bool CPoco::AdicionarTrechoPoco(std::unique_ptr<CTrechoPoco> TrechoPoco) {
    double ProfundidadeFluido = TrechoPoco->ProfundidadeFinal() - TrechoPoco->ProfundidadeInicial();

    // Verifica se a profundidade total ocupada + profundidade do novo fluido excede a profundidade total do poco
    if (profundidadeOcupada + ProfundidadeFluido <= profundidadeFinal) {
        trechos.push_back(std::move(TrechoPoco)); 
        profundidadeOcupada += ProfundidadeFluido;
        return true;
    } else {
        std::cout << "Erro: O fluido excede a profundidade total do poco!\n";
        return false;
    }
}

void CPoco::RemoverTrechoPoco(const std::string& nomeFluido) {
    for (auto it = trechos.begin(); it != trechos.end();) {
        if ((*it)->Fluido()->Nome() == nomeFluido) {
            double ProfundidadeFluido = (*it)->ProfundidadeFinal() - (*it)->ProfundidadeInicial();
            it = trechos.erase(it); // Remove o trecho e atualiza o iterador
            profundidadeOcupada -= ProfundidadeFluido;
        } else {
            ++it; // Apenas avança para o próximo
        }
    }
}

double CPoco::PressaoHidroestaticaTotal() const {

    double pressaoTotal = 0.0;

    for (const auto& Trecho : trechos) {
        pressaoTotal += Trecho->PressaoHidroestatica();
    }
    return pressaoTotal + pressaoSuperficie;
}

double CPoco::PressaoHidroestaticaNoPonto(double profundidade) const {
    double pressaoTotal = pressaoSuperficie;
    double profundidadeAcumulada = 0.0;

    for (const auto& Trecho : trechos) {
        double profundidadeTrecho = Trecho->ProfundidadeFinal() - Trecho->ProfundidadeInicial();
        
        // Verifica se a profundidade esta dentro do trecho atual
        if (profundidade <= profundidadeAcumulada + profundidadeTrecho) {
            // Calcula a contribuicao do trecho ate a profundidade desejada
            pressaoTotal += Trecho->PressaoHidroestatica(profundidade - profundidadeAcumulada);
            break;
        } else {
            // Adiciona a pressao hidrostatica do trecho completo
            pressaoTotal += Trecho->PressaoHidroestatica();
            profundidadeAcumulada += profundidadeTrecho;
        }
    }

    return pressaoTotal;
}

bool CPoco::VerificarPreenchimentoColuna() {
    double ProfundidadeNaoOcupada = profundidadeFinal - profundidadeOcupada;

    if (ProfundidadeNaoOcupada > 0) {
        std::cout << "Uma coluna de " << ProfundidadeNaoOcupada << " ft de fluido precisa ser adicionada!\n";
        std::cout << std::endl;
        return false; // Caluna nao preenchida
    } else {
        std::cout << "A coluna de fluidos equivale à profundidade da coluna do poco!\n";
        std::cout << std::endl;
        return true; // coluna preenchida
    }
}


double CPoco::DensidadeEfetivaTotal() const {
    double densidadeTotal = 0.0;
    double comprimentoTotal = 0.0;
    double comprimentoTrecho =0.0;

    for (const auto& Trecho : trechos) {
        comprimentoTrecho = Trecho->ProfundidadeFinal() - Trecho->ProfundidadeInicial();
        densidadeTotal += Trecho->DensidadeEquivalente() * comprimentoTrecho;
        comprimentoTotal += comprimentoTrecho;
    }

    return densidadeTotal / comprimentoTotal;
}

double CPoco::ViscosidadeEfetivaTotal() const {
    
    double viscosidadeTotal = 0.0;

    for (const auto& Trecho : trechos) {
        viscosidadeTotal += Trecho->Fluido()->Viscosidade();
    }
    return viscosidadeTotal / trechos.size();
}

std::pair<std::vector<double>, std::vector<double>> CPoco::PlotarProfundidadePorPressaoMedia() {

    std::vector<double> profundidades;
    std::vector<double> pressoes;

    for (double z = 0.0; z <= ProfundidadeTotal(); z += 1) {
        profundidades.push_back(z);
        pressoes.push_back(PressaoHidroestaticaNoPonto(z));
    }

    return std::make_pair(profundidades, pressoes);
}

std::pair<std::vector<double>, std::vector<double>> CPoco::PlotarProfundidadePorPressao() {

}
