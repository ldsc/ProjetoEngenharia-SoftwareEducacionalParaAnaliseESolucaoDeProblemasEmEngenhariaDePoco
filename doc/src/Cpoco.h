#ifndef CPOCO_H
#define CPOCO_H

#include <vector>
#include <memory>
#include "Cfluido.h"

class Cpoco {
private:
    double ProfundidadeTotal;
    double profundidadeOcupada;
    std::vector<Cfluido*> fluidos;
    
public:
    //construtor
    Cpoco(double Profund);

    // Getters
    double getProfundidadeTotal() const { return ProfundidadeTotal; }
    double getprofundidadeOcupada() const { return profundidadeOcupada; }

    // Setters
    void setProfundidadeTotal( double Profund ) { ProfundidadeTotal = Profund; }
    void setprofundidadeOcupada( double Profund ) { profundidadeOcupada = Profund; }

    // Metodos
    bool adicionarFluido(Cfluido& fluido);
    void exibeFluidos() const;
    double pressaoHidroestaticaTotal() const;
    double DensidadeEfetivaTotal() const;
    void verificarPreenchimentoColuna();

};

#endif 