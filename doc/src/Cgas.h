#ifndef CGAS_H
#define CGAS_H

#include "Cfluido.h"

class Cgas : public Cfluido{
private:

    double MassaMolar;
    double FatorCompressibilidade;
    double Temperatura;
    double const_R = 1554;

public:
    // Construtor
    Cgas(double dens=0, double profundidade =0, double pressaoSup=0, double massaM = 0, double FatorC = 0, double temp=0){}
    double PressaoHidroestatica();

    // Getters
    double getMassaMolar() const { return MassaMolar; }
    double getFatorCompressibilidade() const { return FatorCompressibilidade; }
    double getTemperatura() const { return Temperatura; }
    double getconst_R() const { return const_R; }

    // Setters
    double setMassaMolar( double massaM ) const { return MassaMolar; }
    double setFatorCompressibilidade( double FatorC ) const { return FatorCompressibilidade; }
    double setTemperatura( double temp ) const { return temp; }
    double setconst_R( double constR ) const { return constR; }

    //Metodos 
    void exibePropriedades();
    double PressaoHidroestaticagas() ;

};

#endif 