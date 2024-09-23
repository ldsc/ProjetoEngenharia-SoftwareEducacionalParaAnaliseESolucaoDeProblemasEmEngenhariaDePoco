#ifndef CFLUIDO_H
#define CFLUIDO_H

class Cfluido {
private:
    double densidade;
    double camadaProfundidade;
    double pressaoSuperficie;

public:
    // Construtor
    Cfluido (double dens, double profundidade, double pressaoSup);

    // Destrutor
    virtual ~Cfluido() {}

    // Getters
    double getDensidade() const { return densidade; }
    double getCamadaProfundidade() const { return camadaProfundidade; }
    double getpressaoSuperficie() const { return pressaoSuperficie; }

    // Setters
    void setDensidade(double dens) { densidade = dens; }
    void setCamadaProdundidade(double profundidade) { camadaProfundidade = profundidade; }
    void setPressaoSuperficie(double pressaoSup) { densidade = pressaoSup; }
    
    //Metodos 
    void exibePropriedades();
    double PressaoHidroestatica();
};

#endif 