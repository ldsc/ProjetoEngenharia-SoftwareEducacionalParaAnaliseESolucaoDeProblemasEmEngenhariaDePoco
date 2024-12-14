#ifndef CMODELOPOTENCIA_H
#define CMODELOPOTENCIA_H

#include "CModeloReologico.h"


class CModeloPotencia : public CModeloReologico {

protected:
    double indiceDeConsistencia = 0.0;
    double indiceDeComportamento = 1.0;
    double reynoldsCriticoPoco = 2100.0;
    double reynoldsCriticoAnular = 2100.0;

public:
    //Construtor
    CModeloPotencia() {}
    ~CModeloPotencia() {}
    CModeloPotencia(CPoco* poco) : CModeloReologico(poco){}

    // Getters
    double ReynoldsCriticoPoco() const { return reynoldsCriticoPoco; }
    double ReynoldsCriticoAnular() const { return reynoldsCriticoAnular; }
    double IndiceDeConsistencia() const { return indiceDeConsistencia; }
    double IndiceDeComportamento() const { return indiceDeComportamento; }
    std::string FluxoPoco() const { return fluxoPoco; }
    std::string FluxoAnular() const { return fluxoAnular; }
    
    
    // Setters
    void IndiceDeConsistencia( double IndiceC ) { indiceDeConsistencia = IndiceC; }
    void IndiceDeComportamento( double IndiceC ) { indiceDeComportamento = IndiceC; }
    void FluxoPoco( double FluxoP ) { fluxoPoco = FluxoP; }
    void ProfundidadeTotal( double FloxoA ) { fluxoAnular = FloxoA; }
    
    //Metodos
    double DeterminarReynoldsCritico(double Reynolds);
    double DeterminarReynoldsPoco(double densidade, double VMedioPoco, double diametroRevestimentoID, double indiceDeConsistencia, double indiceDeComportamento);
    double DeterminarReynoldsAnular(double densidade, double VMedioPoco, double diametroAnular, double indiceDeConsistencia, double indiceDeComportamento);
    std::string DeterminarFluxoPoco() override;
    std::string DeterminarFluxoAnular() override;
    double CalcularPerdaPorFriccaoPoco() override;
    double CalcularPerdaPorFriccaoAnular() override;

};

#endif