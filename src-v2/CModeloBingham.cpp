#include "CModeloBingham.h"
#include <iostream>
#include <cmath>

#include <cmath>
#include <iostream>


double CModeloBingham::DeterminarReynoldsCritico(double hedstron) {
    // Define a função f(x) que representa a equação para Reynolds crítico
    auto func = [hedstron](double x) {
        return ((x / std::pow(1 - x, 3)) * 16800) - hedstron;
    };

    // Define a derivada de f(x)
    auto derivadaFunc = [](double x) {
        return (16800 * (1 + x) / std::pow(1 - x, 4));
    };

    // Método de Newton-Raphson para encontrar a raiz
    auto newtonRaphson = [&](double x) {
        for (int i = 0; i < 10000; ++i) {
            x = x - func(x) / derivadaFunc(x);
            if (fabs(func(x)) < 1e-2) break; // Verifica a convergência
        }
        return x;
    };

    // Aplica Newton-Raphson a partir de um chute inicial 
    double y = newtonRaphson(0.99);

    // Calcula e retorna o Reynolds crítico usando o valor encontrado
    return ((1 - ((4.0 / 3.0) * y) + ((1.0 / 3.0) * std::pow(y, 4))) * hedstron) / (8 * y);
}

double CModeloBingham::DeterminarReynoldsHedstronPoco(double densidade, double pontoDeEscoamento, double diametroRevestimentoID, double viscosidade) {
    reynoldsCriticoPoco = DeterminarReynoldsCritico(reynoldsHedstronPoco);
    return (37100 * densidade * pontoDeEscoamento * std::pow(diametroRevestimentoID, 2))/ (std::pow(viscosidade, 2));
}

double CModeloBingham::DeterminarReynoldsHedstronAnular(double densidade, double pontoDeEscoamento, double diametroAnular, double viscosidade) {
    reynoldsCriticoAnular = DeterminarReynoldsCritico(reynoldsHedstronAnular);
    return (24700 * densidade * pontoDeEscoamento * std::pow(diametroAnular, 2))/ (std::pow(viscosidade, 2));
}
// Função para determinar o tipo de fluxo no poço
std::string CModeloBingham::DeterminarFluxoPoco() {

    vMediaPoco = DeterminarVelocidadeMediaPoco(poco->Vazao(), poco->DiametroRevestimentoID());
    reynoldsPoco = DeterminarReynoldsPoco(poco->DensidadeEfetivaTotal(), vMediaPoco, poco->DiametroRevestimentoID(), viscosidadePlastica);
    
    reynoldsHedstronPoco = DeterminarReynoldsHedstronPoco(poco->DensidadeEfetivaTotal(), pontoDeEscoamento, poco->DiametroRevestimentoID(), viscosidadePlastica);

    fluxoPoco = (reynoldsPoco <= reynoldsCriticoPoco) ? "Laminar" : "Turbulento"; // Determinação do fluxo
    return fluxoPoco;
}

// Função para determinar o tipo de fluxo no espaço anular
std::string CModeloBingham::DeterminarFluxoAnular() {

    double diametroAnular = poco->DiametroPoco() - poco->DiametroRevestimentoOD();

    vMediaAnular = DeterminarVelocidadeMediaAnular(poco->Vazao(), poco->DiametroPoco(), poco->DiametroRevestimentoOD());
    reynoldsAnular = DeterminarReynoldsAnular(poco->DensidadeEfetivaTotal(), vMediaAnular, diametroAnular, viscosidadePlastica);
    reynoldsHedstronAnular = DeterminarReynoldsHedstronAnular(poco->DensidadeEfetivaTotal(), pontoDeEscoamento, diametroAnular, viscosidadePlastica);

    fluxoAnular = (reynoldsAnular <= reynoldsCriticoAnular) ? "Laminar" : "Turbulento"; // Determinação do fluxo
    return fluxoAnular;
}

// Função para calcular a perda de carga por fricção no poço
double CModeloBingham::CalcularPerdaPorFriccaoPoco() {
    if (fluxoPoco.empty()) {
        DeterminarFluxoPoco();
    }

    fatorFriccaoPoco = DeterminarFatorFriccao(reynoldsPoco);
    std::cout << viscosidadePlastica << std::endl;
    std::cout << vMediaPoco << std::endl;
    std::cout << poco->DiametroRevestimentoID() << std::endl;
    std::cout <<pontoDeEscoamento << std::endl;

    if (fluxoPoco == "Laminar") {
        return  ((viscosidadePlastica * vMediaPoco) / (1500 * (std::pow(poco->DiametroRevestimentoID(), 2)))) + (pontoDeEscoamento/(225*poco->DiametroRevestimentoID()));
    } else {  // Fluxo turbulento
        return (fatorFriccaoPoco * poco->DensidadeEfetivaTotal() * std::pow(vMediaPoco, 2) ) / (25.8 * poco->DiametroRevestimentoID());
    }
}

// Função para calcular a perda de carga por fricção no espaço anular
double CModeloBingham::CalcularPerdaPorFriccaoAnular() {
    if (fluxoAnular.empty()) {
        DeterminarFluxoAnular();
    }

    double diametroAnular = poco->DiametroPoco() - poco->DiametroRevestimentoOD();
    fatorFriccaoAnular = DeterminarFatorFriccao(reynoldsAnular);

    if (fluxoAnular == "Laminar") {
        return ((viscosidadePlastica * vMediaAnular) / (1000 * std::pow(diametroAnular, 2))) + (pontoDeEscoamento/(200*diametroAnular));
    } else {  // Fluxo turbulento
        return (fatorFriccaoAnular * poco->DensidadeEfetivaTotal() * std::pow(vMediaAnular, 2) ) / (21.1 * diametroAnular);
    }
}
