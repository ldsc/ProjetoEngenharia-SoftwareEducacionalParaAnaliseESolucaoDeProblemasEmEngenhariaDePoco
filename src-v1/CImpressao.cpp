#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

#include "CImpressao.h"

void CImpressao::ArmazenarValorSeNecessario(std::string texto, double valor) {
    
    ArmazenarValorSeNecessario(texto, valor, "");
    
}

void CImpressao::ArmazenarValorSeNecessario(std::string texto, double valor, std::string unidade) {
    
    char resposta;
    std::cout << "Gostaria de armazenar o valor (s/n)? ";
    std::cin >> resposta;

    if (resposta == 's' || resposta == 'S') {

        std::ofstream arquivo("ResultadosSimulacaoPoco.dat", std::ios::app); // Cria/abre o arquivo para escrita
        arquivo << texto << valor << unidade << std::endl;
        arquivo.close(); // Fecha o arquivo
        
    }
}