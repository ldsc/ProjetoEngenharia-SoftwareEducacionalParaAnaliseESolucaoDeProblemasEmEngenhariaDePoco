#ifndef CMODELONEWTONIANO_H
#define CMODELONEWTONIANO_H

#include "CModeloReologico.h"


class CModeloNewtoniano : public CModeloReologico {

protected:
    std::string fluxoPoco = ""; 
    std::string fluxoAnular = "";  

public:
    //Construtor
    CModeloNewtoniano(CPoco* poco) : CModeloReologico(poco){}

    // Getters
    std::string FluxoPoco() const { return fluxoPoco; }
    std::string ProfundidadeOcupada() const { return fluxoAnular; }
    
    // Setters
    void FluxoPoco( double FluxoP ) { fluxoPoco = FluxoP; }
    void ProfundidadeTotal( double FloxoA ) { fluxoAnular = FloxoA; }
    
    //Métodos
    std::string DeterminarFluxoPoco() override;
    std::string DeterminarFluxoAnular() override;
    double CalcularPerdaPorFriccaoPoco() override;
    double CalcularPerdaPorFriccaoAnular() override;

};

#endif