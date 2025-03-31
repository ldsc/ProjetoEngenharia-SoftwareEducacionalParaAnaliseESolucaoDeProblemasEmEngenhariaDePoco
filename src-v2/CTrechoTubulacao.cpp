#include "CTrechoTubulacao.h"
#include <iostream>

double CTrechoPoco::PressaoHidroestatica() {
    return ( (profundidadeFinal - profundidadeInicial) * 0.05195 * fluido->Densidade() );
}

double CTrechoPoco::PressaoHidroestatica(double profund) {
    return ( profund * 0.05195 * fluido->Densidade() ); 
}

double CTrechoPoco::DensidadeEquivalente() {
    return PressaoHidroestatica() / ( (profundidadeFinal - profundidadeInicial) * 0.05195 );
}
