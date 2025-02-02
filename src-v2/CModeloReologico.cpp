#include <iostream>
#include <cmath>
#include <iomanip>

#include "CModeloReologico.h"



double CModeloReologico::DeterminarReynoldsPoco(double densidade, double VMedioPoco, double diametroRevestimentoID, double viscosidade) {
    reynoldsPoco = (928 * densidade * VMedioPoco * diametroRevestimentoID) / viscosidade;
    return reynoldsPoco;
}

double CModeloReologico::DeterminarReynoldsAnular(double densidade, double VMedioAnular, double diametroAnular, double viscosidade){
    reynoldsAnular = (757 * densidade * VMedioAnular * diametroAnular) / viscosidade;
    return reynoldsAnular;
}

double CModeloReologico::DeterminarVelocidadeMediaPoco(double vazao, double diametroRevestimentoID){
    vMediaPoco = vazao / (2.448 * std::pow(diametroRevestimentoID, 2));
    return vMediaPoco;
}

double CModeloReologico::DeterminarVelocidadeMediaAnular(double vazao, double diametroPoco, double diametroRevestimentoOD){
    vMediaAnular = vazao / (2.448 * (std::pow(diametroPoco, 2) - std::pow(diametroRevestimentoOD, 2)));
    return vMediaAnular;
}


double CModeloReologico::DeterminarFatorFriccao(double re) {
    // Funcao auxiliar para o calculo do fator laminar (este nao esta sendo usado, mas se precisar, pode ser ativado)
    auto laminar_fator = [](double re) {
        return 0.0791 / std::pow(re, 0.25);
    };

    // Definir a equacao f(x) que precisa ser resolvida
    auto f = [re](double x) {
        return 1 / std::sqrt(x) - 4 * std::log10(re * std::sqrt(x)) + 0.395;
    };

    // Definir a derivada de f(x) para o metodo de Newton-Raphson
    auto df = [](double x) {
        return -0.5 / (x * std::sqrt(x)) - (2 / (x * std::log(10)));
    };

    // Metodo de Newton-Raphson para resolver f(x) = 0
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

    // Estimar o chute inicial usando o fator laminar
    double x0 = laminar_fator(re);

    // Resolver a equacao de Fanning usando Newton-Raphson
    return newtonRaphson(x0);
}
