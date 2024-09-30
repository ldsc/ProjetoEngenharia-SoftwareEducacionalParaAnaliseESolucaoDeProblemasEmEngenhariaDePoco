#ifndef CFLUIDO_H
#define CFLUIDO_H

class Cfluido {
protected:
    double densidade;
    double profundidadeInicial;
    double profundidadeFinal;
    double pressaoSuperficie;

public:
    // Construtor
    Cfluido(double dens, double profundidadeI, double profundidadeF, double pressaoSup)
    : densidade(dens), profundidadeInicial(profundidadeI), profundidadeFinal(profundidadeF), pressaoSuperficie(pressaoSup) {}

    // Getters
    double getDensidade() const { return densidade; }
    double getProfundidadeInicial() const { return profundidadeInicial; }
    double getProfundidadeFinal() const { return profundidadeFinal; }
    double getpressaoSuperficie() const { return pressaoSuperficie; }

    // Setters
    void setDensidade(double dens) { densidade = dens; }
    void setProdundidadeInicial(double profundidade) { profundidadeInicial = profundidade; }
    void setProdundidadeFinal(double profundidade) { profundidadeFinal = profundidade; }
    void setPressaoSuperficie(double pressaoSup) { densidade = pressaoSup; }

    //metodos
    virtual void exibePropriedades() = 0;
    virtual double PressaoHidroestatica() = 0;
    virtual double DensidadeEquivalente() = 0;
};

#endif
