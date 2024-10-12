#ifndef CTRECHOPOCO_H
#define CTRECHOPOCO_H

#include "CFluido.h"
#include <string>

class CTrechoPoco {

protected:
    std::string nome;
    double profundidadeInicial;
    double profundidadeFinal;
    CFluido* fluido;  

public:
    // Construtor
    CTrechoPoco();
    CTrechoPoco(std::string nome, double ProfundidadeI, double ProfundidadeF, CFluido* fluido)
        : nome(nome), profundidadeInicial(ProfundidadeI), profundidadeFinal(ProfundidadeF), fluido(fluido) {}

    // Getters
    std::string Nome() const { return nome; }
    double ProfundidadeInicial() const { return profundidadeInicial; }
    double ProfundidadeFinal() const { return profundidadeFinal; }
    CFluido* Fluido() const { return fluido; }

    // Setters
    void Nome(double nome) { nome = nome; }
    void ProfundidadeInicial(double ProfundI) { profundidadeInicial = ProfundI; }
    void ProfundidadeFinal(double ProfundF) { profundidadeFinal = ProfundF; }

    // Métodos
    double PressaoHidroestatica();
    double PressaoHidroestaticaNoPonto(double Profund);
    void ExibePropriedades();
    double DensidadeEquivalente();



};

#endif

 // CTRECHOPOCO_H
