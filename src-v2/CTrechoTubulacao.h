#ifndef CTRECHOTUBULACAO_H
#define CTRECHOTUBULACAO_H

#include "CFluido.h"
#include <memory>

class CTrechoPoco {
protected:

    std::string trecho; // Dados a mais que precisam ser coletados caso rode a simulacao do modulo 02
    double profundidadeInicial = 0.0;
    double profundidadeFinal = 0.0;
    double diametroExterno = 0.0; // Dados a mais que precisam ser coletados caso rode a simulacao do modulo 02
    double diametroInterno = 0.0; // Dados a mais que precisam ser coletados caso rode a simulacao do modulo 02
    double coeficientePoisson = 0.0; // Dados a mais que precisam ser coletados caso rode a simulacao do modulo 02
    double moduloEslasticidade = 0.0; // Dados a mais que precisam ser coletados caso rode a simulacao do modulo 02
    double pesoUnidade = 0.0; // Dados a mais que precisam ser coletados caso rode a simulacao do modulo 02
    double coeficienteExpancaoTermica = 0.0; // Dados a mais que precisam ser coletados caso rode a simulacao do modulo 02

    std::unique_ptr<CFluido> fluido;

public:
    // Construtor
    CTrechoPoco() {}
    ~CTrechoPoco() {}
    CTrechoPoco(double ProfundidadeI, double ProfundidadeF, std::unique_ptr<CFluido> fluido)
        : profundidadeInicial(ProfundidadeI), profundidadeFinal(ProfundidadeF), fluido(std::move(fluido)) {} // Esse construtor nos leva os atributos que ira rodar na simulacao do Modulo 01

    CTrechoPoco(std::string trecho, double ProfundidadeI, double ProfundidadeF, double diametroE, double diametroI, double coefPoisson, double moduloEslast, double pesoUnid, double coefExpancaoTermica)
        : trecho(trecho), profundidadeInicial(ProfundidadeI), profundidadeFinal(ProfundidadeF), diametroExterno(diametroE), diametroInterno(diametroI), coeficientePoisson(coefPoisson), moduloEslasticidade(moduloEslast), pesoUnidade(pesoUnid), coeficienteExpancaoTermica(coefExpancaoTermica) {} // Esse construtor nos leva os atributos que ira rodar na simulacao do Modulo 02

    // Getters
    std::string Trecho() const { return trecho; }
    double ProfundidadeInicial() const { return profundidadeInicial; }
    double ProfundidadeFinal() const { return profundidadeFinal; }
    double DiametroExterno() const { return diametroExterno; }
    double DiametroInterno() const { return diametroInterno; }
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
