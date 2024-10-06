#ifndef CMODELOREOLOGICO_H
#define CMODELOREOLOGICO_H

#include <string>
#include "CPoco.h"

class CModeloReologico {

protected:
    CPoco* Poco;

public:
    //Construtores
    CModeloReologico() {}
    CModeloReologico(CPoco* poco) : Poco(poco) {}

    //Métodos
    virtual std::string DeterminarFluxoPoco() = 0;
    virtual std::string DeterminarFluxoAnular() = 0;
    virtual double CalcularPerdaPorFriccaoPoco() = 0;
    virtual double CalcularPerdaPorFriccaoAnular() = 0;
};

#endif