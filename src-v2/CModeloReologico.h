#ifndef CMODELOREOLOGICO_H
#define CMODELOREOLOGICO_H

#include <string>
#include "CObjetoPoco.h"

class CModeloReologico {

protected:
    double fatorFriccaoPoco = 0.0;
    double fatorFriccaoAnular = 0.0;
    double reynoldsPoco = 0.0;
    double reynoldsAnular = 0.0;
    double vMediaPoco = 0.0;
    double vMediaAnular = 0.0;
    std::string fluxoPoco;
    std::string fluxoAnular;
    CPoco* poco;

public:
    //Construtores
    CModeloReologico() {}
    virtual ~CModeloReologico() {}
    CModeloReologico(CPoco* poco) : poco(poco) {}

    //Getters
    double FatorFriccaoPoco() const { return fatorFriccaoPoco; }
    double FatorFriccaoAnular() const { return fatorFriccaoAnular; }
    double ReynoldsPoco() const { return reynoldsPoco; }
    double ReynoldsAnular() const { return reynoldsAnular; }
    double VMediaPoco() const { return vMediaPoco; }
    double VMediaAnular() const { return vMediaAnular; }
    std::string FluxoPoco() const { return fluxoPoco; }
    std::string FluxoAnular() const { return fluxoAnular; }

    //Metodos
    double DeterminarFatorFriccao(double re);
    double DeterminarReynoldsPoco();
    double DeterminarReynoldsPoco(double viscosidade);
    double DeterminarReynoldsAnular();
    double DeterminarReynoldsAnular(double viscosidade);
    double DeterminarVelocidadeMediaPoco();
    double DeterminarVelocidadeMediaAnular();
    virtual std::string DeterminarFluxoPoco() = 0;
    virtual std::string DeterminarFluxoAnular() = 0;
    virtual double CalcularPerdaPorFriccaoPoco() = 0;
    virtual double CalcularPerdaPorFriccaoAnular() = 0;
};

#endif
