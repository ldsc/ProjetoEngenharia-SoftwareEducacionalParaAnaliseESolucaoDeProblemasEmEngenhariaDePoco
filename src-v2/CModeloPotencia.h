#ifndef CMODELOPOTENCIA_H
#define CMODELOPOTENCIA_H

#include "CModeloReologico.h"

/*
Classe que representa o modelo reologico da Lei da Potencia
Esse modelo e aplicado a fluidos pseudoplastico ou dilatante (n diferente de 1)
A classe herda de CModeloReologico e implementa os metodos especificos do modelo
*/

class CModeloPotencia : public CModeloReologico {

protected:
    // Parametros do modelo da potencia
    double indiceDeConsistencia = 0.0;     // K
    double indiceDeComportamento = 1.0;    // n

    // Reynolds critico arbitrario (2100 como base de separacao)
    double reynoldsCriticoPoco = 2100.0;
    double reynoldsCriticoAnular = 2100.0;

public:
    // Construtores
    CModeloPotencia() {}
    ~CModeloPotencia() {}

    // Construtor com inicializacao do poco e do indice de consistencia
    CModeloPotencia(CObjetoPoco* poco, double indiceDeConsistencia)
        : CModeloReologico(poco),
        indiceDeConsistencia(indiceDeConsistencia)
    {
        DeterminarFluxoPoco();
        DeterminarFluxoAnular();
    }

    // Getters
    double ReynoldsCriticoPoco() const { return reynoldsCriticoPoco; }
    double ReynoldsCriticoAnular() const { return reynoldsCriticoAnular; }
    double IndiceDeConsistencia() const { return indiceDeConsistencia; }
    double IndiceDeComportamento() const { return indiceDeComportamento; }
    std::string FluxoPoco() const { return fluxoPoco; }
    std::string FluxoAnular() const { return fluxoAnular; }

    // Setters
    void IndiceDeConsistencia(double valor) { indiceDeConsistencia = valor; }
    void IndiceDeComportamento(double valor) { indiceDeComportamento = valor; }
    void FluxoPoco(const std::string& fluxo) { fluxoPoco = fluxo; }
    void FluxoAnular(const std::string& fluxo) { fluxoAnular = fluxo; }

    // Metodos especificos do modelo de potencia
    double DeterminarReynoldsCritico(double reynolds);
    double DeterminarReynoldsPoco();
    double DeterminarReynoldsAnular();
    std::string DeterminarFluxoPoco() override;
    std::string DeterminarFluxoAnular() override;
    double CalcularPerdaPorFriccaoPoco() override;
    double CalcularPerdaPorFriccaoAnular() override;
};

#endif // CMODELOPOTENCIA_H
