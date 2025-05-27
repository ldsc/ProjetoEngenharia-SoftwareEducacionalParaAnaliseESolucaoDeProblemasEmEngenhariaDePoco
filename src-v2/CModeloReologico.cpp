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

