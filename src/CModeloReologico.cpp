#include <iostream>
#include <cmath>
#include <iomanip>

#include "CModeloReologico.h"

double CModeloReologico::DeterminarFatorFriccao(double re, double n) {
    // Função auxiliar para o cálculo do fator laminar (este não está sendo usado, mas se precisar, pode ser ativado)
    auto laminar_fator = [](double re) {
        return 0.0791 / std::pow(re, 0.25);
    };

    // Definir a equação f(x) que precisa ser resolvida
    auto f = [re](double x) {
        return 1 / std::sqrt(x) - 4 * std::log10(re * std::sqrt(x)) + 0.395;
    };

    // Definir a derivada de f(x) para o método de Newton-Raphson
    auto df = [](double x) {
        return -0.5 / (x * std::sqrt(x)) - (2 / (x * std::log(10)));
    };

    // Método de Newton-Raphson para resolver f(x) = 0
    auto newtonRaphson = [&](double x0, double tol = 1e-6, int max_iter = 1000) {
        double x = x0;
        for (int i = 0; i < max_iter; i++) {
            double fx = f(x);
            double dfx = df(x);
            if (std::abs(fx) < tol) {
                return x;
            }
            x -= fx / dfx;
        }
        std::cerr << "Solução não encontrada após " << max_iter << " iterações." << std::endl;
        return x;
    };

    // Estimar o chute inicial usando o fator laminar
    double x0 = laminar_fator(re);

    // Resolver a equação de Fanning usando Newton-Raphson
    return newtonRaphson(x0);
}
