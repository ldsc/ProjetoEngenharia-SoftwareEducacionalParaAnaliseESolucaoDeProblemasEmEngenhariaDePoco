#include <iostream>
#include <cmath>
#include <iomanip>

#include "CModeloReologico.h"

// Calcula o número de Reynolds no poco usando a viscosidade total do fluido
double CModeloReologico::DeterminarReynoldsPoco() {
    reynoldsPoco = (928 * poco->DensidadeEfetivaTotal() * vMediaPoco * poco->DiametroRevestimentoID()) /
                   poco->ViscosidadeEfetivaTotal();
    return reynoldsPoco;
}

// Mesmo calculo, mas permitindo passar a viscosidade como parametro
double CModeloReologico::DeterminarReynoldsPoco(double viscosidade) {
    reynoldsPoco = (928 * poco->DensidadeEfetivaTotal() * vMediaPoco * poco->DiametroRevestimentoID()) /
                   viscosidade;
    return reynoldsPoco;
}

// Calcula o número de Reynolds no espaco anular
double CModeloReologico::DeterminarReynoldsAnular() {
    reynoldsAnular = (757 * poco->DensidadeEfetivaTotal() * vMediaAnular *
                      (poco->DiametroPoco() - poco->DiametroRevestimentoOD())) /
                     poco->ViscosidadeEfetivaTotal();
    return reynoldsAnular;
}

// Mesmo calculo para o anular, com viscosidade recebida externamente
double CModeloReologico::DeterminarReynoldsAnular(double viscosidade) {
    reynoldsAnular = (757 * poco->DensidadeEfetivaTotal() * vMediaAnular *
                      (poco->DiametroPoco() - poco->DiametroRevestimentoOD())) /
                     viscosidade;
    return reynoldsAnular;
}

// Calcula a velocidade média do fluido no interior da coluna (poco)
double CModeloReologico::DeterminarVelocidadeMediaPoco() {
    vMediaPoco = poco->Vazao() / (2.448 * std::pow(poco->DiametroRevestimentoID(), 2));
    return vMediaPoco;
}

// Calcula a velocidade média no espaco anular entre a coluna e o revestimento
double CModeloReologico::DeterminarVelocidadeMediaAnular() {
    vMediaAnular = poco->Vazao() /
                   (2.448 * (std::pow(poco->DiametroPoco(), 2) - std::pow(poco->DiametroRevestimentoOD(), 2)));
    return vMediaAnular;
}

// Calcula o fator de fricção usando a equação implícita de Fanning com Newton-Raphson
double CModeloReologico::DeterminarFatorFriccao(double re) {
    // Estimativa inicial baseada em escoamento laminar (nao e usada diretamente, mas serve como chute)
    auto laminar_fator = [](double re) {
        return 0.0791 / std::pow(re, 0.25);
    };

    // Equacao de Fanning: 1/sqrt(f) - 4log10(Re*sqrt(f)) + 0.395 = 0
    auto f = [re](double x) {
        return 1 / std::sqrt(x) - 4 * std::log10(re * std::sqrt(x)) + 0.395;
    };

    // Derivada da equacao de Fanning
    auto df = [](double x) {
        return -0.5 / (x * std::sqrt(x)) - (2 / (x * std::log(10)));
    };

    // Metodo de Newton-Raphson para resolver a equacao
    auto newtonRaphson = [&](double x0, double tol = 1e-6, int max_iter = 1000000) {
        double x = x0;
        for (int i = 0; i < max_iter; i++) {
            double fx = f(x);
            double dfx = df(x);
            if (std::abs(fx) < tol) {
                return x;
            }
            x -= fx / dfx;
        }
        return x;
    };

    // Chute inicial com base no fator para fluxo laminar
    double x0 = laminar_fator(re);

    // Retorna o valor resolvido
    return newtonRaphson(x0);
}
