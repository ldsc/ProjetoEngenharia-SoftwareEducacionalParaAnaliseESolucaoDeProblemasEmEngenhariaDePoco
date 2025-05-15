#ifndef CMODELOBINGHAM_H
#define CMODELOBINGHAM_H

#include "CModeloReologico.h"

/*
Classe que representa o modelo reologico de Bingham
Esse modelo e usado para fluidos com um ponto de escoamento definido
A implementacao baseia-se na heranca da classe CModeloReologico
*/

class CModeloBingham : public CModeloReologico {

protected:
    // Parametros especificos do modelo de Bingham
    double viscosidadePlastica = 0.0;
    double pontoDeEscoamento = 0.0;

    // Valores criticos de Reynolds (poco e anular)
    double reynoldsCriticoPoco = 0.0;
    double reynoldsCriticoAnular = 0.0;

    // Numeros de Hedstron (relacionados ao tipo de escoamento)
    double reynoldsHedstronPoco = 0.0;
    double reynoldsHedstronAnular = 0.0;

public:
    // Construtores
    CModeloBingham() {}
    ~CModeloBingham() {}

    // Construtor com ponteiro para o objeto CObjetoPoco
    CModeloBingham(CObjetoPoco* poco) : CModeloReologico(poco) {}

    // Construtor completo com parametros do modelo
    CModeloBingham(CObjetoPoco* poco, double viscosidadePlastica, double pontoDeEscoamento)
        : CModeloReologico(poco),
        viscosidadePlastica(viscosidadePlastica),
        pontoDeEscoamento(pontoDeEscoamento)
    {
        DeterminarFluxoPoco();
        DeterminarFluxoAnular();
    }

    // Getters
    double ViscosidadePlastica() const { return viscosidadePlastica; }
    double PontoDeEscoamento() const { return pontoDeEscoamento; }
    double ReynoldsCriticoPoco() const { return reynoldsCriticoPoco; }
    double ReynoldsCriticoAnular() const { return reynoldsCriticoAnular; }
    double ReynoldsHedstronPoco() const { return reynoldsHedstronPoco; }
    double ReynoldsHedstronAnular() const { return reynoldsHedstronAnular; }

    // Setters
    void ViscosidadePlastica(double valor) { viscosidadePlastica = valor; }
    void PontoDeEscoamento(double valor) { pontoDeEscoamento = valor; }

    // Metodos especificos do modelo de Bingham
    double DeterminarReynoldsCritico(double hedstron);
    double DeterminarReynoldsHedstronPoco();
    double DeterminarReynoldsHedstronAnular();
    std::string DeterminarFluxoPoco() override;
    std::string DeterminarFluxoAnular() override;
    double CalcularPerdaPorFriccaoPoco() override;
    double CalcularPerdaPorFriccaoAnular() override;
};

#endif // CMODELOBINGHAM_H
