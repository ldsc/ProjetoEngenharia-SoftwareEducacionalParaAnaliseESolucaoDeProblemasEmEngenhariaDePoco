#ifndef CFLUIDO_H
#define CFLUIDO_H

#include <string>

class CFluido {
protected:
    std::string Nome;
    double Densidade;

public:
    // Construtor
    CFluido();
    CFluido(std::string nome, double Dens)
    : Nome(nome), Densidade(Dens) {}

    // Getters
    std::string GetNome() const { return Nome; }
    double GetDensidade() const { return Densidade; }

    // Setters
    void SetNome(double nome) { Nome = nome; }
    void SetDensidade(double Dens) { Densidade = Dens; }

    //metodos
    void ExibePropriedades();
};

#endif
