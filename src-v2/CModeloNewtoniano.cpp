#include "CModeloNewtoniano.h"
#include <iostream>
#include <cmath>

// Função para determinar o tipo de fluxo no poço
std::string CModeloNewtoniano::DeterminarFluxoPoco() {

    DeterminarVelocidadeMediaPoco(poco->Vazao(), poco->DiametroRevestimentoID());
    DeterminarReynoldsPoco(poco->DensidadeEfetivaTotal(), vMediaPoco, poco->DiametroRevestimentoID(), poco->ViscosidadeEfetivaTotal());
    fluxoPoco = (reynoldsPoco <= 2100) ? "Laminar" : "Turbulento"; // Determinação do fluxo

    return fluxoPoco;
}

// Função para determinar o tipo de fluxo no espaço anular
std::string CModeloNewtoniano::DeterminarFluxoAnular() {

    double diametroAnular = poco->DiametroPoco() - poco->DiametroRevestimentoOD();

    DeterminarVelocidadeMediaAnular(poco->Vazao(), poco->DiametroPoco(), poco->DiametroRevestimentoOD());
    DeterminarReynoldsAnular(poco->DensidadeEfetivaTotal(), vMediaAnular, diametroAnular, poco->ViscosidadeEfetivaTotal());
    this->fluxoAnular = (reynoldsAnular <= 2100) ? "Laminar" : "Turbulento"; // Determinação do fluxo

    return fluxoAnular;
}

// Função para calcular a perda de carga por fricção no poço
double CModeloNewtoniano::CalcularPerdaPorFriccaoPoco() {
    if (fluxoPoco.empty()) {
        DeterminarFluxoPoco();
    }

    this->fatorFriccaoPoco = DeterminarFatorFriccao(reynoldsPoco);

    if (fluxoPoco == "Laminar") {
        return (poco->ViscosidadeEfetivaTotal() * vMediaPoco) / (1500 * std::pow(poco->DiametroRevestimentoID(), 2));
    } else {  // Fluxo turbulento
        return (fatorFriccaoPoco * poco->DensidadeEfetivaTotal() * std::pow(vMediaPoco, 2) ) / (25.8 * poco->DiametroRevestimentoID());
    }
}

// Função para calcular a perda de carga por fricção no espaço anular
double CModeloNewtoniano::CalcularPerdaPorFriccaoAnular() {
    if (fluxoAnular.empty()) {
        DeterminarFluxoAnular();
    }

    double diametroAnular = poco->DiametroPoco() - poco->DiametroRevestimentoOD();
    this->fatorFriccaoAnular = DeterminarFatorFriccao(reynoldsAnular);

    if (fluxoAnular == "Laminar") {
        return (poco->ViscosidadeEfetivaTotal() * vMediaAnular) / (1000 * std::pow(diametroAnular, 2));
    } else {  // Fluxo turbulento
        return (fatorFriccaoAnular * poco->DensidadeEfetivaTotal() * std::pow(vMediaAnular, 2) ) / (21.1 * diametroAnular);
    }
}
