#ifndef CTRECHOPOCO_H
#define CTRECHOPOCO_H

#include "CFluido.h"
#include <memory>
#include <iostream>

class CTrechoPoco {
protected:
    double profundidadeInicial = 0.0;
    double profundidadeFinal = 0.0;
    std::unique_ptr<CFluido> fluido;

public:
    // Construtor
    CTrechoPoco() {}
    ~CTrechoPoco() {}
    CTrechoPoco(double ProfundidadeI, double ProfundidadeF, std::unique_ptr<CFluido> fluido)
        : profundidadeInicial(ProfundidadeI), profundidadeFinal(ProfundidadeF), fluido(std::move(fluido)) {}
    
    // Getters
    double ProfundidadeInicial() const { return profundidadeInicial; }
    double ProfundidadeFinal() const { return profundidadeFinal; }
    CFluido* Fluido() const { return fluido.get(); }

    // Setters
    void ProfundidadeInicial(double ProfundI) { profundidadeInicial = ProfundI; }
    void ProfundidadeFinal(double ProfundF) { profundidadeFinal = ProfundF; }

    // Métodos
    double PressaoHidroestatica();
    double PressaoHidroestaticaNoPonto(double profund);
    double DensidadeEquivalente();
};

#endif // CTRECHOPOCO_H
