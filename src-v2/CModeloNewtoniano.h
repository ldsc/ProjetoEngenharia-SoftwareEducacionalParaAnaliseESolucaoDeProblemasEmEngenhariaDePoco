#ifndef CMODELONEWTONIANO_H
#define CMODELONEWTONIANO_H

#include "CModeloReologico.h"

/*
Classe que representa o modelo reologico newtoniano
Nesse caso, a viscosidade e constante e independe da taxa de deformacao
A classe herda de CModeloReologico e implementa os metodos especificos para esse tipo de fluido
*/

class CModeloNewtoniano : public CModeloReologico {

public:
    // Construtores
    CModeloNewtoniano() {}
    ~CModeloNewtoniano() {}

    // Construtor que recebe o objeto do poco
    CModeloNewtoniano(CObjetoPoco* poco) : CModeloReologico(poco) {
        DeterminarFluxoPoco();
        DeterminarFluxoAnular();
    }

    // Metodos obrigatorios sobrescritos do modelo base
    std::string DeterminarFluxoPoco() override;
    std::string DeterminarFluxoAnular() override;
    double CalcularPerdaPorFriccaoPoco() override;
    double CalcularPerdaPorFriccaoAnular() override;
};

#endif // CMODELONEWTONIANO_H
