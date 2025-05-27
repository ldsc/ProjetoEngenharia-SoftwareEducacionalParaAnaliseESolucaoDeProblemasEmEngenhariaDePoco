#include "CModeloPotencia.h"
#include <cmath>
#include <stdexcept>

// Retorna o fator de atrito para fluido da lei da potência com base em NRe e n
double CModeloPotencia::DeterminarFatorFriccao(double NRe, double n) {

    // Coeficientes obtidos via regressão log-log com base nos dados reais do gráfico
    const double n_vals[] = {1.0, 0.8, 0.6, 0.4, 0.2};
    const double a_vals[] = {-0.23285, -0.25049, -0.24695, -0.20192, -0.30519};
    const double b_vals[] = {-1.14079, -1.12562, -1.25944, -1.66278, -1.33815};

    // Interpolação linear entre os dois pontos mais próximos
    double a = 0.0, b = 0.0;
    for (int i = 1; i < 5; ++i) {
        if (n <= n_vals[i - 1] && n >= n_vals[i]) {
            double t = (n - n_vals[i]) / (n_vals[i - 1] - n_vals[i]);
            a = a_vals[i] + t * (a_vals[i - 1] - a_vals[i]);
            b = b_vals[i] + t * (b_vals[i - 1] - b_vals[i]);
            break;
        }
    }

    double logF = a * std::log10(NRe) + b;
    return std::pow(10.0, logF);
}

// Funcao generica para Reynolds critico (nao esta sendo usada diretamente aqui)
double CModeloPotencia::DeterminarReynoldsCritico(double Reynolds) {
    return 183.13 * std::pow(Reynolds, 0.3185);
}

// Calcula o numero de Reynolds para o escoamento no poco
double CModeloPotencia::DeterminarReynoldsPoco() {
    reynoldsPoco =
        ((89100 * poco->DensidadeEfetivaTotal() * std::pow(vMediaPoco, 2 - indiceDeComportamento)) / indiceDeConsistencia) *
        (std::pow((0.0416 * poco->DiametroRevestimentoID()) / (3 + (1 / indiceDeComportamento)), indiceDeComportamento));

    reynoldsCriticoPoco = DeterminarReynoldsCritico(reynoldsPoco);


    return reynoldsPoco;
}

// Calcula o numero de Reynolds no espaco anular
double CModeloPotencia::DeterminarReynoldsAnular() {
    reynoldsAnular =
        ((109000 * poco->DensidadeEfetivaTotal() * std::pow(vMediaAnular, 2 - indiceDeComportamento)) / indiceDeConsistencia) *
        (std::pow((0.0208 * (poco->DiametroPoco() - poco->DiametroRevestimentoOD())) / (2 + (1 / indiceDeComportamento)), indiceDeComportamento));

    reynoldsCriticoAnular = DeterminarReynoldsCritico(reynoldsAnular);

    return reynoldsAnular;
}

// Determina o tipo de fluxo no poco com base no valor de Reynolds calculado
std::string CModeloPotencia::DeterminarFluxoPoco() {
    vMediaPoco = DeterminarVelocidadeMediaPoco();
    reynoldsPoco = DeterminarReynoldsPoco();
    fluxoPoco = (reynoldsPoco <= reynoldsCriticoPoco) ? "Laminar" : "Turbulento";
    return fluxoPoco;
}

// Determina o tipo de fluxo no espaco anular
std::string CModeloPotencia::DeterminarFluxoAnular() {
    vMediaAnular = DeterminarVelocidadeMediaAnular();
    reynoldsAnular = DeterminarReynoldsAnular();
    fluxoAnular = (reynoldsAnular <= reynoldsCriticoAnular) ? "Laminar" : "Turbulento";
    return fluxoAnular;
}

// Calcula a perda de carga por friccao no poco, separando para fluxo laminar e turbulento
double CModeloPotencia::CalcularPerdaPorFriccaoPoco() {
    fatorFriccaoPoco = DeterminarFatorFriccao(reynoldsPoco, indiceDeComportamento);

    if (fluxoPoco == "Laminar") {
        return ((indiceDeConsistencia * std::pow(vMediaPoco, -indiceDeComportamento)) *
                std::pow(( (3 + (1 / indiceDeComportamento)) / 0.0416), indiceDeComportamento)) /
               (144000 * std::pow(poco->DiametroRevestimentoID(), 1 + indiceDeComportamento));
    } else {
        return (fatorFriccaoPoco * poco->DensidadeEfetivaTotal() * std::pow(vMediaPoco, 2)) /
               (25.8 * poco->DiametroRevestimentoID());
    }
}

// Calcula a perda de carga por friccao no espaco anular
double CModeloPotencia::CalcularPerdaPorFriccaoAnular() {
    double diametroAnular = poco->DiametroPoco() - poco->DiametroRevestimentoOD();
    fatorFriccaoAnular = DeterminarFatorFriccao(reynoldsAnular,indiceDeComportamento);

    if (fluxoAnular == "Laminar") {
        return ((indiceDeConsistencia * std::pow(vMediaAnular, -indiceDeComportamento)) *
                std::pow(((2 + (1 / indiceDeComportamento)) / 0.0208), indiceDeComportamento)) /
               (144000 * std::pow(diametroAnular, 1 + indiceDeComportamento));
    } else {
        return (fatorFriccaoAnular * poco->DensidadeEfetivaTotal() * std::pow(vMediaAnular, 2)) /
               (21.1 * diametroAnular);
    }
}
