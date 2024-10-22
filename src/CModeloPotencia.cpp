#include "CModeloPotencia.h"
#include <iostream>
#include <cmath>

// Função para determinar o tipo de fluxo no poço
std::string CModeloPotencia::DeterminarFluxoPoco() {
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
std::string CModeloPotencia::DeterminarFluxoAnular() {
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
double CModeloPotencia::CalcularPerdaPorFriccaoPoco() {
    if (fluxoPoco == "") {
        DeterminarFluxoPoco();
    }

    double diametroRevestimentoID = poco->DiametroRevestimentoID();
    double vazao = poco->Vazao();
    double viscosidade = poco->ViscosidadeEfetivaTotal();
    double densidade = poco->DensidadeEfetivaTotal();

    double VMedioPoco = vazao / (2.448 * std::pow(diametroRevestimentoID, 2)); // Cálculo da velocidade média

    if (fluxoPoco == "Laminar") {
        return ((indiceDeConsistencia * std::pow(VMedioPoco, -indiceDeComportamento)) * std::pow(( (3+(1/indiceDeComportamento) ) / 0.0416), indiceDeComportamento)) 
        / (144000 * std::pow(diametroRevestimentoID, (1+indiceDeComportamento)));
    } else {  // Fluxo turbulento
        return (friccao * densidade * std::pow(VMedioPoco, 2)) / (25.8 * diametroRevestimentoID);
    }
}

// Função para calcular a perda de carga por fricção no espaço anular
double CModeloPotencia::CalcularPerdaPorFriccaoAnular() {
    if (fluxoAnular == "") {
        DeterminarFluxoAnular();
    }

    double diametroAnular = poco->DiametroPoco() - poco->DiametroRevestimentoOD();
    double vazao = poco->Vazao();
    double viscosidade = poco->ViscosidadeEfetivaTotal();
    double densidade = poco->DensidadeEfetivaTotal();

    double VMedioAnular = vazao / (2.448 * (std::pow(poco->DiametroPoco(), 2) - std::pow(poco->DiametroRevestimentoOD(), 2))); // Cálculo da velocidade média

    if (fluxoAnular == "Laminar") {
        return ((indiceDeConsistencia * std::pow(VMedioAnular, -indiceDeComportamento)) * std::pow(( (2+(1/indiceDeComportamento) ) / 0.0208), indiceDeComportamento)) 
        / (144000 * std::pow(diametroAnular, (1+indiceDeComportamento)));
    } else {  // Fluxo turbulento
        return (friccao * densidade * std::pow(VMedioAnular, 2)) / (21.1 * diametroAnular);
    }
}
