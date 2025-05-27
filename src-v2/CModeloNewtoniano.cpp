#include "CModeloNewtoniano.h"
#include <cmath>

// Determina o tipo de fluxo no poco com base no numero de Reynolds
std::string CModeloNewtoniano::DeterminarFluxoPoco() {
    DeterminarVelocidadeMediaPoco();
    DeterminarReynoldsPoco();

    // Valor limite de 2100 usado para separar regime laminar e turbulento
    fluxoPoco = (reynoldsPoco <= 2100) ? "Laminar" : "Turbulento";
    return fluxoPoco;
}

// Determina o tipo de fluxo no espaco anular com base no numero de Reynolds
std::string CModeloNewtoniano::DeterminarFluxoAnular() {
    DeterminarVelocidadeMediaAnular();
    DeterminarReynoldsAnular();

    fluxoAnular = (reynoldsAnular <= 2100) ? "Laminar" : "Turbulento";
    return fluxoAnular;
}

// Calcula a perda de carga por friccao no poco para regime laminar ou turbulento
double CModeloNewtoniano::CalcularPerdaPorFriccaoPoco() {
    if (fluxoPoco.empty()) {
        DeterminarFluxoPoco();
    }

    if (fluxoPoco == "Laminar") {
        return (poco->ViscosidadeEfetivaTotal() * vMediaPoco) /
               (1500 * std::pow(poco->DiametroRevestimentoID(), 2));
    } else {
        return (std::pow(poco->DensidadeEfetivaTotal(), 0.75) * std::pow(vMediaPoco, 1.75) *
                std::pow(poco->ViscosidadeEfetivaTotal(), 0.25)) /
               (1800 * std::pow(poco->DiametroRevestimentoID(), 1.25));
    }
}

// Calcula a perda de carga por friccao no espaco anular
double CModeloNewtoniano::CalcularPerdaPorFriccaoAnular() {
    if (fluxoAnular.empty()) {
        DeterminarFluxoAnular();
    }

    double diametroAnular = poco->DiametroPoco() - poco->DiametroRevestimentoOD();

    if (fluxoAnular == "Laminar") {
        return (poco->ViscosidadeEfetivaTotal() * vMediaAnular) /
               (1000 * std::pow(diametroAnular, 2));
    } else {
        return (std::pow(poco->DensidadeEfetivaTotal(), 0.75) * std::pow(vMediaAnular, 1.75) *
                std::pow(poco->ViscosidadeEfetivaTotal(), 0.25)) /
               (1396 * std::pow(diametroAnular, 1.25));
    }
}
