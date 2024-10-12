#include "CModeloNewtoniano.h"
#include <iostream>
#include <cmath>

std::string CModeloNewtoniano::DeterminarFluxoPoco() {
    
    double VMedioPoco = poco->Vazao() / (2.448 * std::pow(poco->DiametroRevestimentoID(), 2)); // Cálculo da velocidade média
    double Reynolds = (928 * poco->DensidadeEfetivaTotal() * VMedioPoco * poco->DiametroRevestimentoID()) / poco->ViscosidadeEfetivaTotal(); // Cálculo Reynolds
    
    // Definir o tipo de fluxo com base no número de Reynolds
    if (Reynolds <= 2100) {
        fluxoPoco = "Laminar";
    } else {
        fluxoPoco = "Turbulento";
    }
    return fluxoPoco;
}


std::string CModeloNewtoniano::DeterminarFluxoAnular() {
    
    double DiametroAnular = poco->DiametroPoco() - poco->DiametroRevestimentoOD(); // Cálculo do diâmetro anular
    
    double VMedioPoco = poco->Vazao() / (2.448 * (std::pow(poco->DiametroPoco(), 2) - std::pow(poco->DiametroRevestimentoOD(), 2))); // Cálculo da velocidade média do fluido
    double Reynolds = (757 * poco->DensidadeEfetivaTotal() * VMedioPoco * DiametroAnular) / poco->ViscosidadeEfetivaTotal(); // Cálculo Reynolds 

    // Definir o tipo de fluxo com base no número de Reynolds
    if (Reynolds <= 2100) {
        fluxoAnular = "Laminar";
    } else {
        fluxoAnular = "Turbulento";
    }
    return fluxoAnular;
}


double CModeloNewtoniano::CalcularPerdaPorFriccaoPoco() {
    
    double VMedioPoco = poco->Vazao() / (2.448 * std::pow(poco->DiametroRevestimentoID(), 2)); // Cálculo da velocidade média do fluido no poço
    
    // Verifica se o tipo de fluxo já foi determinado
    if (fluxoPoco == "") {
        std::cout << "O valor de Reynolds nao foi definido, nao foi possivel determinar o fluxo do escoamento!\n";
        return 0;
    }
    
    // Cálculo da perda por fricção dependendo do tipo de fluxo
    if (fluxoPoco == "Laminar") {
        return (poco->ViscosidadeEfetivaTotal() * VMedioPoco) / (1500 * std::pow(poco->DiametroRevestimentoID(), 2));
    } else {  // Fluxo turbulento
        return (std::pow(poco->DensidadeEfetivaTotal(), 0.75) * std::pow(VMedioPoco, 1.75) * std::pow(poco->ViscosidadeEfetivaTotal(), 0.25)) 
               / (1800 * std::pow(poco->DiametroRevestimentoID(), 1.25));
    }
}


double CModeloNewtoniano::CalcularPerdaPorFriccaoAnular() {
    
    double DiametroAnular = poco->DiametroPoco() - poco->DiametroRevestimentoOD(); // Cálculo do diâmetro anular
    double VMedioPoco = poco->Vazao() / (2.448 * (std::pow(poco->DiametroPoco(), 2) - std::pow(poco->DiametroRevestimentoOD(), 2))); // Cálculo da velocidade média do fluido no espaço anular
    
    // Verifica se o tipo de fluxo já foi determinado
    if (fluxoAnular == "") {
        std::cout << "O valor de Reynolds nao foi definido, nao foi possivel determinar o fluxo do escoamento!\n";
        return 0;
    }
    
    // Cálculo da perda por fricção dependendo do tipo de fluxo
    if (fluxoAnular == "Laminar") {
        return (poco->ViscosidadeEfetivaTotal() * VMedioPoco) / (1000 * std::pow(DiametroAnular, 2));
    } else {  // Fluxo turbulento
        return (std::pow(poco->DensidadeEfetivaTotal(), 0.75) * std::pow(VMedioPoco, 1.75) * std::pow(poco->ViscosidadeEfetivaTotal(), 0.25)) 
               / (1396 * std::pow(DiametroAnular, 1.25));
    }
}
