#include "CModeloBingham.h"
#include <iostream>
#include <cmath>

#include <cmath>
#include <iostream>

#include <iostream>
#include <fstream>
#include <QApplication>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>

double CModeloBingham::DeterminarReynoldsCritico(double hedstron) {
    // Define a funcaoo f(x) que representa a equacao para Reynolds critico
    auto func = [hedstron](double x) {
        return ((x / std::pow(1 - x, 3)) * 16800) - hedstron;
    };

    // Define a derivada de f(x)
    auto derivadaFunc = [](double x) {
        return (16800 * (1 + x) / std::pow(1 - x, 4));
    };

    // Metodo de Newton-Raphson para encontrar a raiz
    auto newtonRaphson = [&](double x) {
        for (int i = 0; i < 10000; ++i) {
            x = x - func(x) / derivadaFunc(x);
            if (fabs(func(x)) < 1e-2) break; // Verifica a convergencia
        }
        return x;
    };

    // Aplica Newton-Raphson a partir de um chute inicial 
    double y = newtonRaphson(0.99);

    // Calcula e retorna o Reynolds critico usando o valor encontrado
    return ((1 - ((4.0 / 3.0) * y) + ((1.0 / 3.0) * std::pow(y, 4))) * hedstron) / (8 * y);
}

double CModeloBingham::DeterminarReynoldsHedstronPoco(double densidade, double pontoDeEscoamento, double diametroRevestimentoID, double viscosidade) {
    DeterminarReynoldsCritico(reynoldsHedstronPoco);
    return (37100 * densidade * pontoDeEscoamento * std::pow(diametroRevestimentoID, 2))/ (std::pow(viscosidade, 2));
}

double CModeloBingham::DeterminarReynoldsHedstronAnular(double densidade, double pontoDeEscoamento, double diametroAnular, double viscosidade) {
    reynoldsCriticoAnular = DeterminarReynoldsCritico(reynoldsHedstronAnular);
    return (24700 * densidade * pontoDeEscoamento * std::pow(diametroAnular, 2))/ (std::pow(viscosidade, 2));
}
// Funcaoo para determinar o tipo de fluxo no poco
std::string CModeloBingham::DeterminarFluxoPoco() {

    DeterminarVelocidadeMediaPoco(poco->Vazao(), poco->DiametroRevestimentoID());
    DeterminarReynoldsPoco(poco->DensidadeEfetivaTotal(), vMediaPoco, poco->DiametroRevestimentoID(), viscosidadePlastica);
    
    DeterminarReynoldsHedstronPoco(poco->DensidadeEfetivaTotal(), pontoDeEscoamento, poco->DiametroRevestimentoID(), viscosidadePlastica);

    fluxoPoco = (reynoldsPoco <= reynoldsCriticoPoco) ? "Laminar" : "Turbulento"; // Determinacao do fluxo

    qDebug() << vMediaPoco;
    qDebug() << reynoldsPoco;
    qDebug() << reynoldsHedstronPoco;
    qDebug() << fluxoPoco;

    return fluxoPoco;
}

// Funcao para determinar o tipo de fluxo no espaco anular
std::string CModeloBingham::DeterminarFluxoAnular() {

    double diametroAnular = poco->DiametroPoco() - poco->DiametroRevestimentoOD();

    DeterminarVelocidadeMediaAnular(poco->Vazao(), poco->DiametroPoco(), poco->DiametroRevestimentoOD());
    DeterminarReynoldsAnular(poco->DensidadeEfetivaTotal(), vMediaAnular, diametroAnular, viscosidadePlastica);
    DeterminarReynoldsHedstronAnular(poco->DensidadeEfetivaTotal(), pontoDeEscoamento, diametroAnular, viscosidadePlastica);

    fluxoAnular = (reynoldsAnular <= reynoldsCriticoAnular) ? "Laminar" : "Turbulento"; // Determinacao do fluxo
    return fluxoAnular;
}

// Funcao para calcular a perda de carga por friccao no poco
double CModeloBingham::CalcularPerdaPorFriccaoPoco() {
    if (fluxoPoco.empty()) {
        DeterminarFluxoPoco();
    }

    fatorFriccaoPoco = DeterminarFatorFriccao(reynoldsPoco);

    if (fluxoPoco == "Laminar") {
        return  ((viscosidadePlastica * vMediaPoco) / (1500 * (std::pow(poco->DiametroRevestimentoID(), 2)))) + (pontoDeEscoamento/(225*poco->DiametroRevestimentoID()));
    } else {  // Fluxo turbulento
        return (fatorFriccaoPoco * poco->DensidadeEfetivaTotal() * std::pow(vMediaPoco, 2) ) / (25.8 * poco->DiametroRevestimentoID());
    }
}

// Funcao para calcular a perda de carga por friccao no espaco anular
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
