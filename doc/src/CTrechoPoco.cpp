#include "CTrechoPoco.h"
#include <iostream>

double CTrechoPoco::PressaoHidroestatica() {


    return ( (profundidadeFinal - profundidadeInicial)  * 0.05195 * fluido->GetDensidade());

}

double CTrechoPoco::PressaoHidroestaticaNoPonto(double profund) {


    return ( (profund)  * 0.05195 * fluido->GetDensidade());

}

void CTrechoPoco::ExibePropriedades(){

    std::cout << "- nome da secao: " << Nome() << "\n" \
                 "- Profundidade Inicial: " << ProfundidadeInicial() << " ft \n" \
                 "- Profundidade Final: " << ProfundidadeFinal() << " ft \n" \
                 "- nome do fluido: " << fluido->Nome() << " ft \n" \
                 "- Densidade do fluido: " << fluido->GetDensidade() << " lb/gal" << std::endl;
            
}

double CTrechoPoco::DensidadeEquivalente(){
    return PressaoHidroestatica() / ( (profundidadeFinal - profundidadeInicial) * 0.05195 );
}
