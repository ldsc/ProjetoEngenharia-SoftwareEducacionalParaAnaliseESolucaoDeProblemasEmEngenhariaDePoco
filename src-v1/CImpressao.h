#ifndef CIMPRESSAO_H
#define CIMPRESSAO_H

#include <string>

class CImpressao {
protected:
    double pressaoHidroestatica = 0.0;
    double perdadeFriccaoAnularNewtoniano = 0.0;
    double perdadeFriccaoAnularBingham = 0.0;
    double perdadeFriccaoAnularPotencia = 0.0;
    double perdadeFriccaoPocoNewtoniano = 0.0;
    double perdadeFriccaoPocoBingham = 0.0;
    double perdadeFriccaoPocoPotencia = 0.0;

public:
    // Construtor
    CImpressao() {}
    ~CImpressao() {}

    // Getters
    double PressaoHidroestatica() const { return pressaoHidroestatica; }
    double PerdadeFriccaoAnularNewtoniano() const { return perdadeFriccaoAnularNewtoniano; }
    double PerdadeFriccaoAnularBingham() const { return perdadeFriccaoAnularBingham; }
    double PerdadeFriccaoAnularPotencia() const { return perdadeFriccaoAnularPotencia; }
    double PerdadeFriccaoPocoNewtoniano() const { return perdadeFriccaoPocoNewtoniano; }
    double PerdadeFriccaoPocoBingham() const { return perdadeFriccaoPocoBingham; }
    double PerdadeFriccaoPocoPotencia() const { return perdadeFriccaoPocoPotencia; }

    // Setters
    void PressaoHidroestatica(double pressaoHidro) { pressaoHidroestatica = pressaoHidro; }
    void PerdadeFriccaoAnularNewtoniano(double anularNewtoniano) { perdadeFriccaoAnularNewtoniano = anularNewtoniano; }
    void PerdadeFriccaoAnularBingham(double anularBingham) { perdadeFriccaoAnularBingham = anularBingham; }
    void PerdadeFriccaoAnularPotencia(double anularPotencia) { perdadeFriccaoAnularPotencia = anularPotencia; }
    void PerdadeFriccaoPocoNewtoniano(double pocoNewtoniano) { perdadeFriccaoPocoNewtoniano = pocoNewtoniano; }
    void PerdadeFriccaoPocoBingham(double pocoBingham) { perdadeFriccaoPocoBingham = pocoBingham; }
    void PerdadeFriccaoPocoPotencia(double pocoPotencia) { perdadeFriccaoPocoPotencia = pocoPotencia; }

    // Metodos
    void ArmazenarValorSeNecessario(std::string texto, double valor, std::string unidade);
    void ArmazenarValorSeNecessario(std::string texto, double valor);
    
};

#endif