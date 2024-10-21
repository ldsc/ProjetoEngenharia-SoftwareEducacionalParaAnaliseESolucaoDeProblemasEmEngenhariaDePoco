#include "CModeloBingham.h"
#include <iostream>
#include <cmath>

// Função para determinar o tipo de fluxo no poço
std::string CModeloBingham::DeterminarFluxoPoco() {
    double diametroRevestimentoID = poco->DiametroRevestimentoID();
    double vazao = poco->Vazao();
    double densidade = poco->DensidadeEfetivaTotal();
    double viscosidade = poco->ViscosidadeEfetivaTotal();

    double VMedioPoco = vazao / (2.448 * std::pow(diametroRevestimentoID, 2)); // Cálculo da velocidade média
    double Reynolds = (928 * densidade * VMedioPoco * diametroRevestimentoID) / viscosidade; // Cálculo de Reynolds

    fluxoPoco = (Reynolds <= 2100) ? "Laminar" : "Turbulento"; // Determinação do fluxo
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

    fluxoAnular = (Reynolds <= 2100) ? "Laminar" : "Turbulento"; // Determinação do fluxo
    return fluxoAnular;
}

// Função para calcular a perda de carga por fricção no poço
double CModeloBingham::CalcularPerdaPorFriccaoPoco() {
    if (fluxoPoco == "") {
        DeterminarFluxoPoco();
    }

    double diametroRevestimentoID = poco->DiametroRevestimentoID();
    double vazao = poco->Vazao();
    double viscosidade = poco->ViscosidadeEfetivaTotal();
    double densidade = poco->DensidadeEfetivaTotal();

    double VMedioPoco = vazao / (2.448 * std::pow(diametroRevestimentoID, 2)); // Cálculo da velocidade média

    if (fluxoPoco == "Laminar") {
        return  ((viscosidade * VMedioPoco) / (1500 * std::pow(diametroRevestimentoID, 2))) + (pontoDeEscoamento/(225*diametroRevestimentoID));
    } else {  // Fluxo turbulento
        return (std::pow(densidade, 0.75) * std::pow(VMedioPoco, 1.75) * std::pow(viscosidade, 0.25)) 
               / (1800 * std::pow(diametroRevestimentoID, 1.25));
    }
}

// Função para calcular a perda de carga por fricção no espaço anular
double CModeloBingham::CalcularPerdaPorFriccaoAnular() {
    if (fluxoAnular == "") {
        DeterminarFluxoAnular();
    }

    double diametroAnular = poco->DiametroPoco() - poco->DiametroRevestimentoOD();
    double vazao = poco->Vazao();
    double viscosidade = poco->ViscosidadeEfetivaTotal();
    double densidade = poco->DensidadeEfetivaTotal();

    double VMedioAnular = vazao / (2.448 * (std::pow(poco->DiametroPoco(), 2) - std::pow(poco->DiametroRevestimentoOD(), 2))); // Cálculo da velocidade média

    if (fluxoAnular == "Laminar") {
        return ((viscosidade * VMedioAnular) / (1000 * std::pow(diametroAnular, 2))) + (pontoDeEscoamento/(200*diametroAnular));
    } else {  // Fluxo turbulento
        return (std::pow(densidade, 0.75) * std::pow(VMedioAnular, 1.75) * std::pow(viscosidade, 0.25)) 
               / (1396 * std::pow(diametroAnular, 1.25));
    }
}
