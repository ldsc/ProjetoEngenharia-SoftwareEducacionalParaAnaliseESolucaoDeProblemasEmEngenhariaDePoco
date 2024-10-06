#ifndef CFLUIDO_H
#define CFLUIDO_H

#include <string>

class CFluido {
protected:
    std::string Nome;
    double Densidade;
    double Viscosidade;

public:
    // Construtor
    CFluido();
    CFluido(std::string nome, double Dens, double visc = 0)
    : Nome(nome), Densidade(Dens), Viscosidade(visc) {}

    // Getters
    std::string GetNome() const { return Nome; }
    double GetDensidade() const { return Densidade; }
    double GetViscosidade() const { return Viscosidade; }

    // Setters
    void SetNome(double nome) { Nome = nome; }
    void SetDensidade(double Dens) { Densidade = Dens; }
    void SetViscosidade(double visc) { Viscosidade = visc; }

    //metodos
    void ExibePropriedades();
};

#endif
