#include "Cgas.h"
#include <iostream>
#include <cmath>

//Construtor
Cgas::Cgas(double dens, double profundidadeI, double profundidadeF, double pressaoSup, double massaM, double FatorC, double temp)
    : Cfluido(dens, profundidadeI, profundidadeF, pressaoSup), MassaMolar(massaM), FatorCompressibilidade(FatorC), Temperatura(temp) {}

//Metodos
void Cgas::exibePropriedades(){
    std::cout << "- Profundidade inicial do fluido: " << getProfundidadeInicial() << " ft" << std::endl;
    std::cout << "- Profundidade final do fluido: " << getProfundidadeFinal() << " ft" << std::endl;
    std::cout << "- Pressao na Superficie: " << getpressaoSuperficie() << " psi" << std::endl;
    std::cout << "- Massa Molar " << getMassaMolar() << " lb/mol" << std::endl;
    std::cout << "- Z (fator de compressibilidade): " << getFatorCompressibilidade() << std::endl;
    std::cout << "- Temperatura: " << getTemperatura() << " K" << std::endl;
    std::cout << "- Constante R: " << getconst_R() << std::endl;
    
}

double Cgas::PressaoHidroestatica(){

    double pressaosup = getpressaoSuperficie();
    double produndidadeI = getProfundidadeInicial();
    double produndidadeF = getProfundidadeFinal();
    double massaM = getMassaMolar();
    double FatorC = getFatorCompressibilidade();
    double temp = getTemperatura();

    return pressaosup * exp( (massaM/(FatorC*temp*getconst_R())) * (produndidadeI-produndidadeF) );

}

double Cgas::DensidadeEquivalente(){

    double produndidadeF = getProfundidadeFinal();

    return PressaoHidroestatica() / (produndidadeF * 0.05195);

}