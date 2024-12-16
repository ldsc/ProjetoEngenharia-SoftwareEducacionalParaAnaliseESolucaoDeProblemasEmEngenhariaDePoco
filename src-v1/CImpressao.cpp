#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

#include "CImpressao.h"

void CImpressao::ArmazenarValor(double valor, int ref) {
    
    std::ofstream arquivo("ResultadosSimulacaoPoco.dat", std::ios::app); // Cria/abre o arquivo para escrita
    
    if (ref == 0){
        PressaoHidroestatica(valor);
        arquivo << "O Valor da Pressao Hidrostatica: " << PressaoHidroestatica() << " psi" << std::endl;

    }
    else if(ref == 1){
        PerdadeFriccaoAnularNewtoniano(valor);
        arquivo << "O Valor da Perdade Friccao no Anular para o Modelo Newtoniano: " << PerdadeFriccaoAnularNewtoniano() << " psi/ft" << std::endl;

    }
    else if(ref == 2){
        PerdadeFriccaoAnularBingham(valor);
        arquivo << "O Valor da Perdade Friccao no Anular para o Modelo Bingham: " << PerdadeFriccaoAnularBingham() << " psi/ft" << std::endl;

    }
    else if(ref == 3){
        PerdadeFriccaoAnularPotencia(valor);
        arquivo << "O Valor da Perdade Friccao no Anular para o Modelo Potencia: " << PerdadeFriccaoAnularPotencia() << " psi/ft" << std::endl;

    }
    else if(ref == 4){
        PerdadeFriccaoPocoNewtoniano(valor);
        arquivo << "O Valor da Perdade Friccao no Poco para o Modelo Newtoniano: " << PerdadeFriccaoPocoNewtoniano() << " psi/ft" << std::endl;

    }
    else if(ref == 5){
        PerdadeFriccaoPocoBingham(valor);
        arquivo << "O Valor da Perdade Friccao no Poco para o Modelo Bingham: " << PerdadeFriccaoPocoBingham() << " psi/ft" << std::endl;

    }
    else if(ref == 6){
        PerdadeFriccaoPocoPotencia(valor);
        arquivo << "O Valor da Perdade Friccao no Poco para o Modelo Potencia: " << PerdadeFriccaoPocoPotencia() << " psi/ft" << std::endl;

    }
    arquivo.close(); // Fecha o arquivo
}
