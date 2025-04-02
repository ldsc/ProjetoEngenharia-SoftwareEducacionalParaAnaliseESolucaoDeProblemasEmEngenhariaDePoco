#ifndef CTRECHOTUBULACAO_H
#define CTRECHOTUBULACAO_H

#include "CFluido.h"
#include <memory>

class CTrechoPoco {
protected:
    double profundidadeInicial = 0.0;
    double profundidadeFinal = 0.0;
    std::unique_ptr<CFluido> fluido;

    // Dados a mais que precisam ser coletados caso rode a simulacao do modulo 02
    double coeficientePoisson = 0.0;
    double moduloEslasticidade = 0.0;
    double pesoUnidade = 0.0;
    double coeficienteExpancaoTermica = 0.0;

public:
    // Construtor
    CTrechoPoco() {}
    ~CTrechoPoco() {}
    CTrechoPoco(double ProfundidadeI, double ProfundidadeF, std::unique_ptr<CFluido> fluido)
        : profundidadeInicial(ProfundidadeI), profundidadeFinal(ProfundidadeF), fluido(std::move(fluido)) {} // Esse construtor nos leva os atributos que ira rodar na simulacao do Modulo 01

    CTrechoPoco(double ProfundidadeI, double ProfundidadeF, std::unique_ptr<CFluido> fluido, double coefPoisson, double moduloEslast, double pesoUnid, double coefExpancaoTermica)
        : profundidadeInicial(ProfundidadeI), profundidadeFinal(ProfundidadeF), fluido(std::move(fluido)), coeficientePoisson(coefPoisson), moduloEslasticidade(moduloEslast), pesoUnidade(pesoUnid), coeficienteExpancaoTermica(coefExpancaoTermica) {} // Esse construtor nos leva os atributos que ira rodar na simulacao do Modulo 02

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

#endif // CTRECHOTUBULACAO_H
