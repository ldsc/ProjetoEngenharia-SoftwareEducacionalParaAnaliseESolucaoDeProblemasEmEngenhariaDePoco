#include "CTrechoPoco.h"
#include <iostream>

double CTrechoPoco::PressaoHidroestatica() {


    return ( (ProfundidadeFinal - ProfundidadeInicial)  * 0.05195 * Fluido->GetDensidade());

}

void CTrechoPoco::ExibePropriedades(){

    std::cout << "- Nome da secao: " << GetNome() << "\n" \
                 "- Profundidade Inicial: " << GetProfundidadeInicial() << " ft \n" \
                 "- Profundidade Final: " << GetProfundidadeFinal() << " ft \n" \
                 "- Nome do Fluido: " << Fluido->GetNome() << " ft \n" \
                 "- Densidade do Fluido: " << Fluido->GetDensidade() << " lb/gal" << std::endl;
            
}

double CTrechoPoco::DensidadeEquivalente(){
    return PressaoHidroestatica() / ( (ProfundidadeFinal - ProfundidadeInicial) * 0.05195 );
}
