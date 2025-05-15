#ifndef CFLUIDO_H
#define CFLUIDO_H

#include <string>

/*
Classe que representa um fluido qualquer do sistema
Aqui sao armazenados nome, densidade e viscosidade
Essas informacoes sao usadas nos calculos de pressao, perda de carga, etc
*/

class CFluido {
protected:
    std::string nomeFluido;         // nome do fluido (ex: oleo ou agua)
    double densidadeFluido = 0.0;   // densidade em lbm/gal
    double viscosidadeFluido = 0.0; // viscosidade em cP

public:
    CFluido() {}
    ~CFluido() {}

    // Construtor para inicializar com todos os dados
    CFluido(std::string nome, double densidade, double viscosidade)
        : nomeFluido(nome), densidadeFluido(densidade), viscosidadeFluido(viscosidade) {}

    // getters
    std::string Nome() const { return nomeFluido; }
    double Densidade() const { return densidadeFluido; }
    double Viscosidade() const { return viscosidadeFluido; }

    // setters
    void Nome(const std::string& novoNome) { nomeFluido = novoNome; }
    void Densidade(double novaDensidade) { densidadeFluido = novaDensidade; }
    void Viscosidade(double novaViscosidade) { viscosidadeFluido = novaViscosidade; }
};

#endif
