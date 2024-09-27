#include "Cpoco.h"
#include "Cgas.h"
#include <iostream>

// Construtor
Cpoco::Cpoco(double Profund) 
    : ProfundidadeTotal(Profund), profundidadeOcupada(0.0) {}



// Metodos
bool Cpoco::adicionarFluido(Cfluido& fluido) {

    double profundidadeFluido = fluido.getProfundidadeFinal() - fluido.getProfundidadeInicial();

    // Verifica se a profundidade total ocupada + profundidade do novo fluido excede a profundidade total do poço
    if (profundidadeOcupada + profundidadeFluido <= ProfundidadeTotal) {
        fluidos.push_back(&fluido);
        profundidadeOcupada += profundidadeFluido;
        return true;

    } else {
        std::cout << "Erro: O fluido excede a profundidade total do poço!" << std::endl;
        return false;
    }
}

void Cpoco::exibeFluidos() const {
    for (size_t i = 0; i < fluidos.size(); ++i) {
        std::cout << "##### Exibe fluido " << (i + 1) << " #####" << std::endl; 
        
        fluidos[i]->exibePropriedades();
        std::cout << std::endl; 
    }
}

double Cpoco::pressaoHidroestaticaTotal() const {

    double pressaoTotal = 0.0;

    for (const auto& fluido : fluidos) {
        pressaoTotal += fluido->PressaoHidroestatica();
    }
    return pressaoTotal;
}

void Cpoco::verificarPreenchimentoColuna() {

    double profundidadeNaoOcupada = ProfundidadeTotal - profundidadeOcupada;

    if (profundidadeNaoOcupada > 0) {
  
        double profundidadeInicialAr = ProfundidadeTotal - profundidadeOcupada;
        double profundidadeFinalAr = ProfundidadeTotal;

        Cgas Ar(1, 0, 0, profundidadeInicialAr, 16, 1, profundidadeFinalAr);
        
        adicionarFluido(Ar);
        std::cout << "Uma coluna de "<< profundidadeNaoOcupada << "ft de ar foi adicionada!" << std::endl;
        std::cout << std::endl;
    }

    else{
        std::cout << "A coluna de fluidos equivale a profundidade da coluna do poco! " << std::endl;
        std::cout << std::endl;
    }
}

double Cpoco::DensidadeEfetivaTotal() const {

    double DensidadeTotal = 0.0;

    for (const auto& fluido : fluidos) {
        DensidadeTotal += fluido->DensidadeEquivalente();
    }
    return DensidadeTotal / fluidos.size();

}