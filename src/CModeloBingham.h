#ifndef CMODELOPOTENCIA_H
#define CMODELOPOTENCIA_H

#include "CModeloReologico.h"


class CModeloBingham : public CModeloReologico {

protected:
    double pontoDeEscoamento;

public:
    //Construtor
    CModeloBingham() {}
    ~CModeloBingham() {}
    CModeloBingham(CPoco* poco) : CModeloReologico(poco){}

    // Getters
    std::string FluxoPoco() const { return fluxoPoco; }
    std::string ProfundidadeOcupada() const { return fluxoAnular; }
    
    // Setters
    void PontoDeEscoamento( double PontoE ) { pontoDeEscoamento = PontoE; }
    void FluxoPoco( double FluxoP ) { fluxoPoco = FluxoP; }
    void ProfundidadeTotal( double FloxoA ) { fluxoAnular = FloxoA; }
    
    //Métodos
    double DeterminarReynoldsCritico(double hedstron);
    double PontoDeEscoamento() const { return pontoDeEscoamento; }
    std::string DeterminarFluxoPoco() override;
    std::string DeterminarFluxoAnular() override;
    double CalcularPerdaPorFriccaoPoco() override;
    double CalcularPerdaPorFriccaoAnular() override;

};

#endif