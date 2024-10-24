#include "CModeloNewtoniano.h"
#include <iostream>
#include <cmath>

// Função para determinar o tipo de fluxo no poço
std::string CModeloNewtoniano::DeterminarFluxoPoco() {
    double diametroRevestimentoID = poco->DiametroRevestimentoID();
    double vazao = poco->Vazao();
    double densidade = poco->DensidadeEfetivaTotal();
    double viscosidade = poco->ViscosidadeEfetivaTotal();

    double VMedioPoco = vazao / (2.448 * std::pow(diametroRevestimentoID, 2)); // Cálculo da velocidade média
    reynoldsPoco = (928 * densidade * VMedioPoco * diametroRevestimentoID) / viscosidade; // Cálculo de Reynolds

    fluxoPoco = (reynoldsPoco <= 2100) ? "Laminar" : "Turbulento"; // Determinação do fluxo
    return fluxoPoco;
}

// Função para determinar o tipo de fluxo no espaço anular
std::string CModeloNewtoniano::DeterminarFluxoAnular() {
    double diametroAnular = poco->DiametroPoco() - poco->DiametroRevestimentoOD();
    double vazao = poco->Vazao();
    double densidade = poco->DensidadeEfetivaTotal();
    double viscosidade = poco->ViscosidadeEfetivaTotal();

    double VMedioAnular = vazao / (2.448 * (std::pow(poco->DiametroPoco(), 2) - std::pow(poco->DiametroRevestimentoOD(), 2))); // Cálculo da velocidade média
    reynoldsAnular = (757 * densidade * VMedioAnular * diametroAnular) / viscosidade; // Cálculo de Reynolds

    fluxoAnular = (reynoldsAnular <= 2100) ? "Laminar" : "Turbulento"; // Determinação do fluxo
    return fluxoAnular;
}

// Função para calcular a perda de carga por fricção no poço
double CModeloNewtoniano::CalcularPerdaPorFriccaoPoco() {
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
        return (viscosidade * VMedioPoco) / (1500 * std::pow(diametroRevestimentoID, 2));
    } else {  // Fluxo turbulento
        return (fatorFriccao * densidade * std::pow(VMedioPoco, 2) ) / (25.8 * diametroRevestimentoID);
    }
}

// Função para calcular a perda de carga por fricção no espaço anular
double CModeloNewtoniano::CalcularPerdaPorFriccaoAnular() {
    if (fluxoAnular.empty()) {
        DeterminarFluxoAnular();
    }

    double diametroAnular = poco->DiametroPoco() - poco->DiametroRevestimentoOD();
    double vazao = poco->Vazao();
    double viscosidade = poco->ViscosidadeEfetivaTotal();
    double densidade = poco->DensidadeEfetivaTotal();
    fatorFriccao = DeterminarFatorFriccao(reynoldsAnular, 1.0);

    double VMedioAnular = vazao / (2.448 * (std::pow(poco->DiametroPoco(), 2) - std::pow(poco->DiametroRevestimentoOD(), 2))); // Cálculo da velocidade média

    if (fluxoAnular == "Laminar") {
        return (viscosidade * VMedioAnular) / (1000 * std::pow(diametroAnular, 2));
    } else {  // Fluxo turbulento
        return (fatorFriccao * densidade * std::pow(VMedioAnular, 2) ) / (21.1 * diametroAnular);
    }
}
