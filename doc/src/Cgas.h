#ifndef CGAS_H
#define CGAS_H

#include "Cfluido.h"

class Cgas : public Cfluido{
protected:

    double MassaMolar;
    double FatorCompressibilidade;
    double Temperatura;
    double const_R = 1544.0;

public:
    // Construtor
    Cgas(double dens, double profundidadeI, double profundidadeF, double pressaoSup, double massaM, double FatorC, double temp);

    // Getters
    double getMassaMolar() const { return MassaMolar; }
    double getFatorCompressibilidade() const { return FatorCompressibilidade; }
    double getTemperatura() const { return Temperatura; }
    double getconst_R() const { return const_R; }

    // Setters
    void setMassaMolar( double massaM ) { MassaMolar = massaM; }
    void setFatorCompressibilidade( double FatorC ) { FatorCompressibilidade = FatorC; }
    void setTemperatura( double temp ) { Temperatura = temp; }
    void setconst_R( double constR ) { const_R = constR; }

    //Metodos
    void exibePropriedades() override;
    double PressaoHidroestatica() override;
    double DensidadeEquivalente() override;
};

#endif
