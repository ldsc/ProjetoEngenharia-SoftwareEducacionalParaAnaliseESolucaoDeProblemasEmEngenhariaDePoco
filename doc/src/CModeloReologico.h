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
    virtual std::string DeterminarFluxo() = 0;
    virtual double CalcularPerdaPorFriccao() = 0;
};

#endif