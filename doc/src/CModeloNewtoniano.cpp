#include "CModeloNewtoniano.h"
#include <iostring>

std::string CModeloNewtoniano::DeterminarFluxo(){

    double VMedioPoco = Poco->GetVazao() /( 2.448 * Poco->GetDiametro() * Poco->GetDiametro() );
    double Reynolds = ( 928 * Poco->DensidadeEfetivaTotal() * VMedioPoco * Poco->GetDiametro() ) / Poco->ViscosidadeEfetivaTotal();

    if (Reynolds <= 2100 ){

        Fluxo = "Laminar";
        return Fluxo;
    }

    else{

        Fluxo = "Turbulento";
        return Fluxo;
    }

}

double CModeloNewtoniano::CalcularPerdaPorFriccao(){

    double VMedioPoco = Poco->GetVazao() /( 2.448 * Poco->GetDiametro() * Poco->GetDiametro() );

    if(Fluxo == ""){
        std::cout << "O Valor de Reynolds nao foi definido, não foi possivel determina o fluxo do escoamento!\n";
        return 0;
    }

    else if(Fluxo == "Laminar"){
        
        return (Poco->ViscosidadeEfetivaTotal() * VMedioPoco) / (1500 * Poco->GetDiametro() * Poco->GetDiametro() )

    }

    else{

        

    }

}
