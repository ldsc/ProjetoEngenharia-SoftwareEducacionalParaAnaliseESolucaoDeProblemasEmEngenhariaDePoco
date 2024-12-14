#ifndef CMODELONEWTONIANO_H
#define CMODELONEWTONIANO_H

#include "CModeloReologico.h"


class CModeloNewtoniano : public CModeloReologico { 


public:
    //Construtor
    CModeloNewtoniano() {}
    ~CModeloNewtoniano() {}
    CModeloNewtoniano(CPoco* poco) : CModeloReologico(poco){}

    //Metodos
    std::string DeterminarFluxoPoco() override;
    std::string DeterminarFluxoAnular() override;
    double CalcularPerdaPorFriccaoPoco() override;
    double CalcularPerdaPorFriccaoAnular() override;

};

#endif