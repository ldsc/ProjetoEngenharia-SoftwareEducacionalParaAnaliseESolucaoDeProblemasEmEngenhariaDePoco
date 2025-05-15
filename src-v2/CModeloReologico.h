#ifndef CMODELOREOLOGICO_H
#define CMODELOREOLOGICO_H

#include <string>
#include "CObjetoPoco.h"

/*
Classe base abstrata para os modelos reologicos
Define as propriedades e metodos que devem ser implementados pelos modelos concretos
Serve como interface para modelos como newtoniano, Bingham e lei da potencia
*/

class CModeloReologico {

protected:
    // Propriedades relacionadas ao escoamento e calculos
    double fatorFriccaoPoco = 0.0;
    double fatorFriccaoAnular = 0.0;
    double reynoldsPoco = 0.0;
    double reynoldsAnular = 0.0;
    double vMediaPoco = 0.0;
    double vMediaAnular = 0.0;

    // Tipo de fluxo (laminar ou turbulento)
    std::string fluxoPoco;
    std::string fluxoAnular;

    // Objeto que contem as propriedades do poco
    CObjetoPoco* poco;

public:
    // Construtores
    CModeloReologico() {}
    virtual ~CModeloReologico() {}
    CModeloReologico(CObjetoPoco* poco) : poco(poco) {}

    // Getters
    double FatorFriccaoPoco() const { return fatorFriccaoPoco; }
    double FatorFriccaoAnular() const { return fatorFriccaoAnular; }
    double ReynoldsPoco() const { return reynoldsPoco; }
    double ReynoldsAnular() const { return reynoldsAnular; }
    double VMediaPoco() const { return vMediaPoco; }
    double VMediaAnular() const { return vMediaAnular; }
    std::string FluxoPoco() const { return fluxoPoco; }
    std::string FluxoAnular() const { return fluxoAnular; }

    // Métodos para determinar fatores e velocidades
    double DeterminarFatorFriccao(double re);
    double DeterminarReynoldsPoco();
    double DeterminarReynoldsPoco(double viscosidade);
    double DeterminarReynoldsAnular();
    double DeterminarReynoldsAnular(double viscosidade);
    double DeterminarVelocidadeMediaPoco();
    double DeterminarVelocidadeMediaAnular();

    // Métodos puros (devem ser implementados pelas classes filhas)
    virtual std::string DeterminarFluxoPoco() = 0;
    virtual std::string DeterminarFluxoAnular() = 0;
    virtual double CalcularPerdaPorFriccaoPoco() = 0;
    virtual double CalcularPerdaPorFriccaoAnular() = 0;
};

#endif // CMODELOREOLOGICO_H
