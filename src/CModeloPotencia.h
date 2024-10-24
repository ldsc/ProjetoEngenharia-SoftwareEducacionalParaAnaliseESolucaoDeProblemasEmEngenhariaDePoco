#ifndef CMODELOBINGHAM_H
#define CMODELOBINGHAM_H

#include "CModeloReologico.h"


class CModeloPotencia : public CModeloReologico {

protected:
    double indiceDeConsistencia;
    double indiceDeComportamento;

public:
    //Construtor
    CModeloPotencia() {}
    ~CModeloPotencia() {}
    CModeloPotencia(CPoco* poco) : CModeloReologico(poco){}

    // Getters
    double IndiceDeConsistencia() const { return indiceDeConsistencia; }
    double IndiceDeComportamento() const { return indiceDeComportamento; }
    std::string FluxoPoco() const { return fluxoPoco; }
    std::string FluxoAnular() const { return fluxoAnular; }
    
    
    // Setters
    void IndiceDeConsistencia( double IndiceC ) { indiceDeConsistencia = IndiceC; }
    void IndiceDeComportamento( double IndiceC ) { indiceDeComportamento = IndiceC; }
    void FluxoPoco( double FluxoP ) { fluxoPoco = FluxoP; }
    void ProfundidadeTotal( double FloxoA ) { fluxoAnular = FloxoA; }
    
    //Métodos
    double DeterminarReynoldsCritico(double hedstron);
    std::string DeterminarFluxoPoco() override;
    std::string DeterminarFluxoAnular() override;
    double CalcularPerdaPorFriccaoPoco() override;
    double CalcularPerdaPorFriccaoAnular() override;

};

#endif