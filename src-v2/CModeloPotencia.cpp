#include "CModeloPotencia.h"
#include <iostream>
#include <cmath>

double CModeloPotencia::DeterminarReynoldsCritico(double Reynolds) {

    return 0.0;
}

double CModeloPotencia::DeterminarReynoldsPoco() {
    reynoldsPoco = ((89100 * poco->DensidadeEfetivaTotal() * std::pow(vMediaPoco, 2-indiceDeComportamento)) / indiceDeConsistencia) * (std::pow((0.0416 * poco->DiametroRevestimentoID())/(3+(1/indiceDeComportamento)),indiceDeComportamento));
    
    if (indiceDeComportamento < 0.4){
        reynoldsCriticoPoco = DeterminarReynoldsCritico(reynoldsPoco);
    }
    return reynoldsPoco;
}

double CModeloPotencia::DeterminarReynoldsAnular() {
    reynoldsAnular = ((109000 * poco->DensidadeEfetivaTotal() * std::pow(vMediaAnular, 2-indiceDeComportamento)) / indiceDeConsistencia) * (std::pow((0.0208 * poco->DiametroPoco() - poco->DiametroRevestimentoOD())/(2+(1/indiceDeComportamento)),indiceDeComportamento));
    
    if (indiceDeComportamento < 0.4){
        reynoldsCriticoAnular = DeterminarReynoldsCritico(reynoldsAnular);
    }

    return reynoldsAnular;
}

// Funcao para determinar o tipo de fluxo no poco
std::string CModeloPotencia::DeterminarFluxoPoco() {

    vMediaPoco = DeterminarVelocidadeMediaPoco();
    reynoldsPoco = DeterminarReynoldsPoco();

    fluxoPoco = (reynoldsPoco <= reynoldsCriticoPoco) ? "Laminar" : "Turbulento"; // Determinacao do fluxo
    return fluxoPoco;
}

// Funcao para determinar o tipo de fluxo no espaco anular
std::string CModeloPotencia::DeterminarFluxoAnular() {

    double diametroAnular = poco->DiametroPoco() - poco->DiametroRevestimentoOD();
    vMediaAnular = DeterminarVelocidadeMediaAnular();
    reynoldsAnular = DeterminarReynoldsAnular();

    fluxoAnular = (reynoldsAnular <= reynoldsCriticoAnular) ? "Laminar" : "Turbulento"; // Determinacao do fluxo
    return fluxoAnular;
}

// Funcao para calcular a perda de carga por friccao no poco
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

// Funcao para calcular a perda de carga por friccao no espaco anular
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
