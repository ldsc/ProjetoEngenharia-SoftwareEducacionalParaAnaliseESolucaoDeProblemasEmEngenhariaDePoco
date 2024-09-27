#ifndef COLEO_H
#define COLEO_H

#include "Cfluido.h"

class Coleo : public Cfluido{

public:
    // Construtor
    Coleo(double dens, double profundidadeI, double profundidadeF, double pressaoSup);

    //Metodos 
    void exibePropriedades() override;
    double PressaoHidroestatica() override;
    double DensidadeEquivalente() override;
};

#endif 