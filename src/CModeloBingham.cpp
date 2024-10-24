#include "CModeloBingham.h"
#include <iostream>
#include <cmath>

double CModeloBingham::DeterminarReynoldsCritico(double hedstron) {

    double x = std::sqrt(16800.0 / hedstron);
    
    return ((1 - ((4/3) * x) + ((1/3) * std::pow(x, 4))) * hedstron)/ (8*x);
    
}

// Função para determinar o tipo de fluxo no poço
std::string CModeloBingham::DeterminarFluxoPoco() {
    double diametroRevestimentoID = poco->DiametroRevestimentoID();
    double vazao = poco->Vazao();
    double densidade = poco->DensidadeEfetivaTotal();
    double viscosidade = poco->ViscosidadeEfetivaTotal();

    double VMedioPoco = vazao / (2.448 * std::pow(diametroRevestimentoID, 2)); // Cálculo da velocidade média
    double Reynolds = (928 * densidade * VMedioPoco * diametroRevestimentoID) / viscosidade; // Cálculo de Reynolds
    double Hedstron = (37100 * densidade * pontoDeEscoamento * std::pow(diametroRevestimentoID, 2))/ (std::pow(viscosidade, 2));
    double ReynoldsCritico = DeterminarReynoldsCritico(Hedstron);

    fluxoPoco = (Reynolds <= ReynoldsCritico) ? "Laminar" : "Turbulento"; // Determinação do fluxo
    return fluxoPoco;
}

// Função para determinar o tipo de fluxo no espaço anular
std::string CModeloBingham::DeterminarFluxoAnular() {
    double diametroAnular = poco->DiametroPoco() - poco->DiametroRevestimentoOD();
    double vazao = poco->Vazao();
    double densidade = poco->DensidadeEfetivaTotal();
    double viscosidade = poco->ViscosidadeEfetivaTotal();

    double VMedioAnular = vazao / (2.448 * (std::pow(poco->DiametroPoco(), 2) - std::pow(poco->DiametroRevestimentoOD(), 2))); // Cálculo da velocidade média
    double Reynolds = (757 * densidade * VMedioAnular * diametroAnular) / viscosidade; // Cálculo de Reynolds
    double Hedstron = (24700 * densidade * pontoDeEscoamento * std::pow(diametroAnular, 2)) / (std::pow(viscosidade, 2));
    double ReynoldsCritico = DeterminarReynoldsCritico(Hedstron);

    fluxoAnular = (Reynolds <= ReynoldsCritico) ? "Laminar" : "Turbulento"; // Determinação do fluxo
    return fluxoAnular;
}

// Função para calcular a perda de carga por fricção no poço
double CModeloBingham::CalcularPerdaPorFriccaoPoco() {
    if (fluxoPoco.empty()) {
        DeterminarFluxoPoco();
    }

    double diametroRevestimentoID = poco->DiametroRevestimentoID();
    double vazao = poco->Vazao();
    double viscosidade = poco->ViscosidadeEfetivaTotal();
    double densidade = poco->DensidadeEfetivaTotal();
    fatorFriccao = DeterminarFatorFriccao(reynoldsPoco, 1.0);

    double VMedioPoco = vazao / (2.448 * std::pow(diametroRevestimentoID, 2)); // Cálculo da velocidade média

    if (fluxoPoco == "Laminar") {
        return  ((viscosidade * VMedioPoco) / (1500 * std::pow(diametroRevestimentoID, 2))) + (pontoDeEscoamento/(225*diametroRevestimentoID));
    } else {  // Fluxo turbulento
        return (fatorFriccao * densidade * std::pow(VMedioPoco, 2) ) / (25.8 * diametroRevestimentoID);
    }
}

// Função para calcular a perda de carga por fricção no espaço anular
double CModeloBingham::CalcularPerdaPorFriccaoAnular() {
    if (fluxoAnular.empty()) {
        DeterminarFluxoAnular();
    }

    double diametroAnular = poco->DiametroPoco() - poco->DiametroRevestimentoOD();
    double vazao = poco->Vazao();
    double viscosidade = poco->ViscosidadeEfetivaTotal();
    double densidade = poco->DensidadeEfetivaTotal();
    fatorFriccao = DeterminarFatorFriccao(reynoldsPoco, 1.0);

    double VMedioAnular = vazao / (2.448 * (std::pow(poco->DiametroPoco(), 2) - std::pow(poco->DiametroRevestimentoOD(), 2))); // Cálculo da velocidade média

    if (fluxoAnular == "Laminar") {
        return ((viscosidade * VMedioAnular) / (1000 * std::pow(diametroAnular, 2))) + (pontoDeEscoamento/(200*diametroAnular));
    } else {  // Fluxo turbulento
        return (fatorFriccao * densidade * std::pow(VMedioAnular, 2) ) / (21.1 * diametroAnular);
    }
}
