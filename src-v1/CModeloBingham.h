#ifndef CMODELOBINGHAM_H
#define CMODELOBINGHAM_H

#include "CModeloReologico.h"


class CModeloBingham : public CModeloReologico {

protected:
    double viscosidadePlastica = 0.0;
    double pontoDeEscoamento = 0.0;
    double reynoldsCriticoPoco = 0.0;
    double reynoldsCriticoAnular = 0.0;
    double reynoldsHedstronPoco = 0.0;
    double reynoldsHedstronAnular = 0.0;

public:
    //Construtor
    CModeloBingham() {}
    ~CModeloBingham() {}
    CModeloBingham(CPoco* poco) : CModeloReologico(poco){}

    // Getters
    double PontoDeEscoamento() const { return pontoDeEscoamento; }
    double ReynoldsCriticoPoco() const { return reynoldsCriticoPoco; }
    double ReynoldsCriticoAnular() const { return reynoldsCriticoAnular; }
    double ReynoldsHedstronPoco() const { return reynoldsHedstronPoco; }
    double ReynoldsHedstronAnular() const { return reynoldsHedstronAnular; }
    
    // Setters
    void PontoDeEscoamento( double PontoE ) { pontoDeEscoamento = PontoE; }
    void ViscosidadePlastica( double ViscosidadeP ) { viscosidadePlastica = ViscosidadeP; }
    
    //Metodos
    
    double DeterminarReynoldsCritico(double hedstron);
    double DeterminarReynoldsHedstronPoco(double densidade, double pontoDeEscoamento, double diametroRevestimentoID, double viscosidade);
    double DeterminarReynoldsHedstronAnular(double densidade, double pontoDeEscoamento, double diametroAnular, double viscosidade);
    std::string DeterminarFluxoPoco() override;
    std::string DeterminarFluxoAnular() override;
    double CalcularPerdaPorFriccaoPoco() override;
    double CalcularPerdaPorFriccaoAnular() override;

};

#endif