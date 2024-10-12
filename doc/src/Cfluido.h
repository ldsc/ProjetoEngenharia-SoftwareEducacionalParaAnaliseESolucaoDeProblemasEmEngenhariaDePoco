#ifndef CFLUIDO_H
#define CFLUIDO_H

#include <string>

class CFluido {
protected:
    std::string nome;
    double Densidade;
    double Viscosidade;

public:
    // Construtor
    CFluido();
    CFluido(std::string nome, double Dens, double visc = 0)
    : nome(nome), Densidade(Dens), Viscosidade(visc) {}

    // Getters
    std::string Nome() const { return nome; }
    double GetDensidade() const { return Densidade; }
    double GetViscosidade() const { return Viscosidade; }

    // Setters
    void Nome(double nome) { nome = nome; }
    void SetDensidade(double Dens) { Densidade = Dens; }
    void SetViscosidade(double visc) { Viscosidade = visc; }

    //metodos
    void ExibePropriedades();
};

#endif
