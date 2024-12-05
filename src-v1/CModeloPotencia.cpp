#include "CModeloPotencia.h"
#include <iostream>
#include <cmath>

double CModeloPotencia::DeterminarReynoldsCritico(double Reynolds) {

    return 0.0;
}

double CModeloPotencia::DeterminarReynoldsPoco(double densidade, double VMedioPoco, double diametroRevestimentoID, double indiceDeConsistencia, double indiceDeComportamento) {
    reynoldsPoco = ((89100 * densidade * std::pow(VMedioPoco, 2-indiceDeComportamento)) / indiceDeConsistencia) * (std::pow((0.0416 * diametroRevestimentoID)/(3+(1/indiceDeComportamento)),indiceDeComportamento));
    
    if (indiceDeComportamento < 0.4){
        reynoldsCriticoPoco = DeterminarReynoldsCritico(reynoldsPoco);
    }
    return reynoldsPoco;
}

double CModeloPotencia::DeterminarReynoldsAnular(double densidade, double VMedioPoco, double diametroAnular, double indiceDeConsistencia, double indiceDeComportamento) {
    reynoldsAnular = ((109000 * densidade * std::pow(VMedioPoco, 2-indiceDeComportamento)) / indiceDeConsistencia) * (std::pow((0.0208 * diametroAnular)/(2+(1/indiceDeComportamento)),indiceDeComportamento));
    
    if (indiceDeComportamento < 0.4){
        reynoldsCriticoAnular = DeterminarReynoldsCritico(reynoldsAnular);
    }

    return reynoldsAnular;
}

// Função para determinar o tipo de fluxo no poço
std::string CModeloPotencia::DeterminarFluxoPoco() {

    vMediaPoco = DeterminarVelocidadeMediaPoco(poco->Vazao(), poco->DiametroRevestimentoID());
    reynoldsPoco = DeterminarReynoldsPoco(poco->DensidadeEfetivaTotal(), vMediaPoco, poco->DiametroRevestimentoID(), indiceDeConsistencia, indiceDeComportamento);

    fluxoPoco = (reynoldsPoco <= reynoldsCriticoPoco) ? "Laminar" : "Turbulento"; // Determinação do fluxo
    return fluxoPoco;
}

// Função para determinar o tipo de fluxo no espaço anular
std::string CModeloPotencia::DeterminarFluxoAnular() {

    double diametroAnular = poco->DiametroPoco() - poco->DiametroRevestimentoOD();
    vMediaAnular = DeterminarVelocidadeMediaAnular(poco->Vazao(), poco->DiametroPoco(), poco->DiametroRevestimentoOD());
    reynoldsAnular = DeterminarReynoldsAnular(poco->DensidadeEfetivaTotal(), vMediaAnular, diametroAnular, indiceDeConsistencia, indiceDeComportamento);

    fluxoAnular = (reynoldsAnular <= reynoldsCriticoAnular) ? "Laminar" : "Turbulento"; // Determinação do fluxo
    return fluxoAnular;
}

// Função para calcular a perda de carga por fricção no poço
double CModeloPotencia::CalcularPerdaPorFriccaoPoco() {
    if (fluxoPoco.empty()) {
        DeterminarFluxoPoco();
    }

    fatorFriccaoPoco = DeterminarFatorFriccao(reynoldsPoco);

    if (fluxoPoco == "Laminar") {
        return ((indiceDeConsistencia * std::pow(vMediaPoco, -indiceDeComportamento)) * std::pow(( (3+(1/indiceDeComportamento) ) / 0.0416), indiceDeComportamento)) 
        / (144000 * std::pow(poco->DiametroRevestimentoID(), (1+indiceDeComportamento)));
    } else {  // Fluxo turbulento
        return (fatorFriccaoPoco * poco->DensidadeEfetivaTotal() * std::pow(vMediaPoco, 2) ) / (25.8 * poco->DiametroRevestimentoID());
    }
}

// Função para calcular a perda de carga por fricção no espaço anular
double CModeloPotencia::CalcularPerdaPorFriccaoAnular() {
    if (fluxoAnular.empty()) {
        DeterminarFluxoAnular();
    }

    double diametroAnular = poco->DiametroPoco() - poco->DiametroRevestimentoOD();
    fatorFriccaoAnular = DeterminarFatorFriccao(reynoldsAnular);

    if (fluxoAnular == "Laminar") {
        return ((indiceDeConsistencia * std::pow(vMediaAnular, -indiceDeComportamento)) * std::pow(( (2+(1/indiceDeComportamento) ) / 0.0208), indiceDeComportamento)) 
        / (144000 * std::pow(diametroAnular, (1+indiceDeComportamento)));
    } else {  // Fluxo turbulento
        return (fatorFriccaoAnular * poco->DensidadeEfetivaTotal() * std::pow(vMediaAnular, 2) ) / (21.1 * diametroAnular);
    }
}
