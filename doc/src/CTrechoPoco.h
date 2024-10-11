#ifndef CTRECHOPOCO_H
#define CTRECHOPOCO_H

#include "CFluido.h"
#include <string>

class CTrechoPoco {

protected:
    std::string Nome;
    double ProfundidadeInicial;
    double ProfundidadeFinal;
    CFluido* Fluido;  

public:
    // Construtor
    CTrechoPoco();
    CTrechoPoco(std::string nome, double ProfundidadeI, double ProfundidadeF, CFluido* Fluido)
        : Nome(nome), ProfundidadeInicial(ProfundidadeI), ProfundidadeFinal(ProfundidadeF), Fluido(Fluido) {}

    // Getters
    std::string GetNome() const { return Nome; }
    double GetProfundidadeInicial() const { return ProfundidadeInicial; }
    double GetProfundidadeFinal() const { return ProfundidadeFinal; }
    CFluido* GetFluido() const { return Fluido; }

    // Setters
    void SetNome(double nome) { Nome = nome; }
    void SetProfundidadeInicial(double ProfundI) { ProfundidadeInicial = ProfundI; }
    void SetProfundidadeFinal(double ProfundF) { ProfundidadeFinal = ProfundF; }

    // Métodos
    double PressaoHidroestatica();
    double PressaoHidroestaticaNoPonto(double Profund);
    void ExibePropriedades();
    double DensidadeEquivalente();



};

#endif

 // CTRECHOPOCO_H
