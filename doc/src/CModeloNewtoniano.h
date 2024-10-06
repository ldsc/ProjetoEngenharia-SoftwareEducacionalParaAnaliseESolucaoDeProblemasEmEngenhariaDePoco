#ifndef CMODELONEWTONIANO_H
#define CMODELONEWTONIANO_H

#include "CModeloReologico.h"


class CModeloNewtoniano : public CModeloReologico {

protected:
    std::string Fluxo = "";  

public:
    //Construtor
    CModeloNewtoniano(CPoco* poco) : CModeloReologico(poco){}
    
    //Métodos
    std::string DeterminarFluxo() override;
    double CalcularPerdaPorFriccao() override;

};

#endif