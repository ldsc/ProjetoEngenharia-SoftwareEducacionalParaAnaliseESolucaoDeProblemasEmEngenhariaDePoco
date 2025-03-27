#ifndef CTRECHOPOCO_H
#define CTRECHOPOCO_H

#include "CFluido.h"
#include <memory>
#include <iostream>
#include <optional>

class CTrechoPoco {
protected:
    double profundidadeInicial = 0.0;
    double profundidadeFinal = 0.0;
    std::unique_ptr<CFluido> fluido;

    // Dados a mais que precisam ser coletados caso rode a simulacao do modulo 02
    std::optional<double> coefPoisson; 
    std::optional<double> moduloEslasticidade;
    std::optional<double> pesoUnid;
    std::optional<double> coefExpancaoTermica;

public:
    // Construtor
    CTrechoPoco() {}
    ~CTrechoPoco() {}
    CTrechoPoco(double ProfundidadeI, double ProfundidadeF, std::unique_ptr<CFluido> fluido)
        : profundidadeInicial(ProfundidadeI), profundidadeFinal(ProfundidadeF), fluido(std::move(fluido)) {} // Esse construtor nos leva os atributos que ira rodar na simulacao do Modulo 01

    CTrechoPoco(double ProfundidadeI, double ProfundidadeF, std::unique_ptr<CFluido> fluido, std::optional<double> CoefPoisson, std::optional<double> ModuloEslasticidade, std::optional<double> PesoUnid, std::optional<double> CoefExpancaoTermica)
        : profundidadeInicial(ProfundidadeI), profundidadeFinal(ProfundidadeF), fluido(std::move(fluido), coefPoisson(CoefPoisson), moduloEslasticidade(ModuloEslasticidade), PesoUnid(pesoUnid), CoefExpancaoTermica(coefExpancaoTermica)) {} // Esse construtor nos leva os atributos que ira rodar na simulacao do Modulo 02
    
    // Getters
    double ProfundidadeInicial() const { return profundidadeInicial; }
    double ProfundidadeFinal() const { return profundidadeFinal; }
    CFluido* Fluido() const { return fluido.get(); }

    // Setters
    void ProfundidadeInicial(double ProfundI) { profundidadeInicial = ProfundI; }
    void ProfundidadeFinal(double ProfundF) { profundidadeFinal = ProfundF; }

    // Metodos
    double PressaoHidroestatica();
    double PressaoHidroestatica(double profund);
    double DensidadeEquivalente();
};

#endif // CTRECHOPOCO_H
