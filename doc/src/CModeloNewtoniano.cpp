#include "CModeloNewtoniano.h"
#include <iostream>
#include <cmath>

std::string CModeloNewtoniano::DeterminarFluxoPoco() {
    
    double VMedioPoco = Poco->GetVazao() / (2.448 * std::pow(Poco->GetDiametroRevestimentoID(), 2)); // Cálculo da velocidade média
    double Reynolds = (928 * Poco->DensidadeEfetivaTotal() * VMedioPoco * Poco->GetDiametroRevestimentoID()) / Poco->ViscosidadeEfetivaTotal(); // Cálculo Reynolds
    
    // Definir o tipo de fluxo com base no número de Reynolds
    if (Reynolds <= 2100) {
        FluxoPoco = "Laminar";
    } else {
        FluxoPoco = "Turbulento";
    }
    return FluxoPoco;
}


std::string CModeloNewtoniano::DeterminarFluxoAnular() {
    
    double DiametroAnular = Poco->GetDiametroPoco() - Poco->GetDiametroRevestimentoOD(); // Cálculo do diâmetro anular
    
    double VMedioPoco = Poco->GetVazao() / (2.448 * (std::pow(Poco->GetDiametroPoco(), 2) - std::pow(Poco->GetDiametroRevestimentoOD(), 2))); // Cálculo da velocidade média do fluido
    double Reynolds = (757 * Poco->DensidadeEfetivaTotal() * VMedioPoco * DiametroAnular) / Poco->ViscosidadeEfetivaTotal(); // Cálculo Reynolds 

    // Definir o tipo de fluxo com base no número de Reynolds
    if (Reynolds <= 2100) {
        FluxoAnular = "Laminar";
    } else {
        FluxoAnular = "Turbulento";
    }
    return FluxoAnular;
}


double CModeloNewtoniano::CalcularPerdaPorFriccaoPoco() {
    
    double VMedioPoco = Poco->GetVazao() / (2.448 * std::pow(Poco->GetDiametroRevestimentoID(), 2)); // Cálculo da velocidade média do fluido no poço
    
    // Verifica se o tipo de fluxo já foi determinado
    if (FluxoPoco == "") {
        std::cout << "O valor de Reynolds nao foi definido, nao foi possivel determinar o fluxo do escoamento!\n";
        return 0;
    }
    
    // Cálculo da perda por fricção dependendo do tipo de fluxo
    if (FluxoPoco == "Laminar") {
        return (Poco->ViscosidadeEfetivaTotal() * VMedioPoco) / (1500 * std::pow(Poco->GetDiametroRevestimentoID(), 2));
    } else {  // Fluxo turbulento
        return (std::pow(Poco->DensidadeEfetivaTotal(), 0.75) * std::pow(VMedioPoco, 1.75) * std::pow(Poco->ViscosidadeEfetivaTotal(), 0.25)) 
               / (1800 * std::pow(Poco->GetDiametroRevestimentoID(), 1.25));
    }
}


double CModeloNewtoniano::CalcularPerdaPorFriccaoAnular() {
    
    double DiametroAnular = Poco->GetDiametroPoco() - Poco->GetDiametroRevestimentoOD(); // Cálculo do diâmetro anular
    double VMedioPoco = Poco->GetVazao() / (2.448 * (std::pow(Poco->GetDiametroPoco(), 2) - std::pow(Poco->GetDiametroRevestimentoOD(), 2))); // Cálculo da velocidade média do fluido no espaço anular
    
    // Verifica se o tipo de fluxo já foi determinado
    if (FluxoAnular == "") {
        std::cout << "O valor de Reynolds nao foi definido, nao foi possivel determinar o fluxo do escoamento!\n";
        return 0;
    }
    
    // Cálculo da perda por fricção dependendo do tipo de fluxo
    if (FluxoAnular == "Laminar") {
        return (Poco->ViscosidadeEfetivaTotal() * VMedioPoco) / (1000 * std::pow(DiametroAnular, 2));
    } else {  // Fluxo turbulento
        return (std::pow(Poco->DensidadeEfetivaTotal(), 0.75) * std::pow(VMedioPoco, 1.75) * std::pow(Poco->ViscosidadeEfetivaTotal(), 0.25)) 
               / (1396 * std::pow(DiametroAnular, 1.25));
    }
}
