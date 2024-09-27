#include "Coleo.h"
#include <iostream>
#include <cmath>

//Construtor
Coleo::Coleo(double dens, double profundidadeI, double profundidadeF, double pressaoSup)
    : Cfluido(dens, profundidadeI, profundidadeF, pressaoSup) {}


//Metodos
void Coleo::exibePropriedades() {
    std::cout << "- Densidade: " << getDensidade() << " lb/gal" << std::endl;
    std::cout << "- Profundidade inicial do fluido: " << getProfundidadeInicial() << " ft" << std::endl;
    std::cout << "- Profundidade final do fluido: " << getProfundidadeFinal() << " ft" << std::endl;
    std::cout << "- Pressao na Superficie: " << getpressaoSuperficie() << " psi" << std::endl;
}

double Coleo::PressaoHidroestatica() {

    double pressaosup = getpressaoSuperficie();
    double dens = getDensidade();
    double produndidadeI = getProfundidadeInicial();
    double produndidadeF = getProfundidadeFinal();

    return pressaosup + ( ( dens * (produndidadeF-produndidadeI))  * 0.052);
}

double Coleo::DensidadeEquivalente(){

    double produndidadeF = getProfundidadeFinal();

    return PressaoHidroestatica() / (produndidadeF * 0.05195);

}