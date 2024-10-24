#ifndef CMODELOREOLOGICO_H
#define CMODELOREOLOGICO_H

#include <string>
#include "CPoco.h"

class CModeloReologico {

protected:
    double fatorFriccao;
    double reynoldsPoco;
    double reynoldsAnular;
    std::string fluxoPoco; 
    std::string fluxoAnular; 
    CPoco* poco;

public:
    //Construtores
    CModeloReologico() {}
    virtual ~CModeloReologico() {}
    CModeloReologico(CPoco* poco) : poco(poco) {}

    //Métodos
    double DeterminarFatorFriccao(double re, double n);
    virtual std::string DeterminarFluxoPoco() = 0;
    virtual std::string DeterminarFluxoAnular() = 0;
    virtual double CalcularPerdaPorFriccaoPoco() = 0;
    virtual double CalcularPerdaPorFriccaoAnular() = 0;
};

#endif