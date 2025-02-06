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
    CModeloBingham(CPoco* poco, double viscosidadePlastica, double pontoDeEscoamento) : CModeloReologico(poco), viscosidadePlastica(viscosidadePlastica), pontoDeEscoamento(pontoDeEscoamento){
        DeterminarFluxoPoco();
        DeterminarFluxoAnular();
    }

    // Getters
    double PontoDeEscoamento() const { return pontoDeEscoamento; }
    double ReynoldsCriticoPoco() const { return reynoldsCriticoPoco; }
    double ReynoldsCriticoAnular() const { return reynoldsCriticoAnular; }
    double ReynoldsHedstronPoco() const { return reynoldsHedstronPoco; }
    double ReynoldsHedstronAnular() const { return reynoldsHedstronAnular; }
    double ViscosidadePlastica() const { return viscosidadePlastica; }

    // Setters
    void PontoDeEscoamento( double PontoE ) { pontoDeEscoamento = PontoE; }
    void ViscosidadePlastica( double ViscosidadeP ) { viscosidadePlastica = ViscosidadeP; }
    
    //Metodos
    
    double DeterminarReynoldsCritico(double hedstron);
    double DeterminarReynoldsHedstronPoco();
    double DeterminarReynoldsHedstronAnular();
    std::string DeterminarFluxoPoco() override;
    std::string DeterminarFluxoAnular() override;
    double CalcularPerdaPorFriccaoPoco() override;
    double CalcularPerdaPorFriccaoAnular() override;

};

#endif
