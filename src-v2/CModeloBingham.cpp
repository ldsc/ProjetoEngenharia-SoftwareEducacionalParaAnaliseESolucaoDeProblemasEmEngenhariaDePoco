#include "CModeloBingham.h"
#include <cmath>
#include <QApplication>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>

// Determina o valor de Reynolds critico com base no numero de Hedstron
// Utiliza metodo numerico de Newton-Raphson para resolver a equacao implicita
double CModeloBingham::DeterminarReynoldsCritico(double hedstron) {
    // f(x) = ((x / (1 - x)^3) * 16800) - Hedstron
    auto func = [hedstron](double x) {
        return ((x / std::pow(1 - x, 3)) * 16800) - hedstron;
    };

    // Derivada de f(x)
    auto derivadaFunc = [](double x) {
        return (16800 * (1 + x) / std::pow(1 - x, 4));
    };

    // Metodo de Newton-Raphson para aproximar a raiz
    auto newtonRaphson = [&](double x) {
        for (int i = 0; i < 10000; ++i) {
            x = x - func(x) / derivadaFunc(x);
            if (fabs(func(x)) < 1e-2) break;
        }
        return x;
    };

    // Chute inicial
    double y = newtonRaphson(0.99);

    // Retorna o Reynolds critico com base em y encontrado
    return ((1 - ((4.0 / 3.0) * y) + ((1.0 / 3.0) * std::pow(y, 4))) * hedstron) / (8 * y);
}

// Calcula o numero de Hedstron para o escoamento no poco
double CModeloBingham::DeterminarReynoldsHedstronPoco() {
    reynoldsHedstronPoco =
        (37100 * poco->DensidadeEfetivaTotal() * pontoDeEscoamento *
         std::pow(poco->DiametroRevestimentoID(), 2)) /
        std::pow(viscosidadePlastica, 2);

    return reynoldsHedstronPoco;
}

// Calcula o numero de Hedstron para o escoamento no espaco anular
double CModeloBingham::DeterminarReynoldsHedstronAnular() {
    double diametroAnular = poco->DiametroPoco() - poco->DiametroRevestimentoOD();

    reynoldsHedstronAnular =
        (24700 * poco->DensidadeEfetivaTotal() * pontoDeEscoamento *
         std::pow(diametroAnular, 2)) /
        std::pow(viscosidadePlastica, 2);

    return reynoldsHedstronAnular;
}

// Determina o tipo de fluxo no poco (laminar ou turbulento)
std::string CModeloBingham::DeterminarFluxoPoco() {
    DeterminarVelocidadeMediaPoco();
    DeterminarReynoldsPoco(viscosidadePlastica);
    DeterminarReynoldsHedstronPoco();

    reynoldsCriticoPoco = DeterminarReynoldsCritico(reynoldsHedstronPoco);

    fluxoPoco = (reynoldsPoco <= reynoldsCriticoPoco) ? "Laminar" : "Turbulento";
    return fluxoPoco;
}

// Determina o tipo de fluxo no espaco anular
std::string CModeloBingham::DeterminarFluxoAnular() {
    DeterminarVelocidadeMediaAnular();
    DeterminarReynoldsAnular(viscosidadePlastica);
    DeterminarReynoldsHedstronAnular();

    reynoldsCriticoAnular = DeterminarReynoldsCritico(reynoldsHedstronAnular);

    fluxoAnular = (reynoldsAnular <= reynoldsCriticoAnular) ? "Laminar" : "Turbulento";
    return fluxoAnular;
}

// Calcula a perda de carga por friccao no poco
double CModeloBingham::CalcularPerdaPorFriccaoPoco() {
    if (fluxoPoco == "Laminar") {
        return ((viscosidadePlastica * vMediaPoco) /
                (1500 * std::pow(poco->DiametroRevestimentoID(), 2))) +
               (pontoDeEscoamento / (225 * poco->DiametroRevestimentoID()));
    } else {
        return (fatorFriccaoPoco * poco->DensidadeEfetivaTotal() *
                std::pow(vMediaPoco, 2)) /
               (25.8 * poco->DiametroRevestimentoID());
    }
}

// Calcula a perda de carga por friccao no espaco anular
double CModeloBingham::CalcularPerdaPorFriccaoAnular() {
    double diametroAnular = poco->DiametroPoco() - poco->DiametroRevestimentoOD();
    fatorFriccaoAnular = DeterminarFatorFriccao(reynoldsAnular);

    if (fluxoAnular == "Laminar") {
        return ((viscosidadePlastica * vMediaAnular) /
                (1000 * std::pow(diametroAnular, 2))) +
               (pontoDeEscoamento / (200 * diametroAnular));
    } else {
        return (fatorFriccaoAnular * poco->DensidadeEfetivaTotal() *
                std::pow(vMediaAnular, 2)) /
               (21.1 * diametroAnular);
    }
}
