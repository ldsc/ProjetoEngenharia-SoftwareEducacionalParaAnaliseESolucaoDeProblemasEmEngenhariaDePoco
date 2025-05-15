#include "CModeloPotencia.h"
#include <cmath>

// Funcao generica para Reynolds critico (nao esta sendo usada diretamente aqui)
double CModeloPotencia::DeterminarReynoldsCritico(double Reynolds) {
    (void) Reynolds; // evita warning por parametro nao usado
    return 0.0;
}

// Calcula o numero de Reynolds para o escoamento no poco
double CModeloPotencia::DeterminarReynoldsPoco() {
    reynoldsPoco =
        ((89100 * poco->DensidadeEfetivaTotal() * std::pow(vMediaPoco, 2 - indiceDeComportamento)) / indiceDeConsistencia) *
        (std::pow((0.0416 * poco->DiametroRevestimentoID()) / (3 + (1 / indiceDeComportamento)), indiceDeComportamento));

    // Para fluidos com n muito baixo (pseudoplastico forte), pode ajustar o critico
    if (indiceDeComportamento < 0.4) {
        reynoldsCriticoPoco = DeterminarReynoldsCritico(reynoldsPoco);
    }

    return reynoldsPoco;
}

// Calcula o numero de Reynolds no espaco anular
double CModeloPotencia::DeterminarReynoldsAnular() {
    reynoldsAnular =
        ((109000 * poco->DensidadeEfetivaTotal() * std::pow(vMediaAnular, 2 - indiceDeComportamento)) / indiceDeConsistencia) *
        (std::pow((0.0208 * (poco->DiametroPoco() - poco->DiametroRevestimentoOD())) / (2 + (1 / indiceDeComportamento)), indiceDeComportamento));

    if (indiceDeComportamento < 0.4) {
        reynoldsCriticoAnular = DeterminarReynoldsCritico(reynoldsAnular);
    }

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
    fatorFriccaoPoco = DeterminarFatorFriccao(reynoldsPoco);

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
    fatorFriccaoAnular = DeterminarFatorFriccao(reynoldsAnular);

    if (fluxoAnular == "Laminar") {
        return ((indiceDeConsistencia * std::pow(vMediaAnular, -indiceDeComportamento)) *
                std::pow(((2 + (1 / indiceDeComportamento)) / 0.0208), indiceDeComportamento)) /
               (144000 * std::pow(diametroAnular, 1 + indiceDeComportamento));
    } else {
        return (fatorFriccaoAnular * poco->DensidadeEfetivaTotal() * std::pow(vMediaAnular, 2)) /
               (21.1 * diametroAnular);
    }
}
