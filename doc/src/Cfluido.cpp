#include "Cfluido.h"
#include <iostream>


//Construtor
Cfluido::Cfluido(double dens, double profundidade, double pressaoSup)
    : densidade(dens), camadaProfundidade(profundidade), pressaoSuperficie(pressaoSup) {}

//Destrutor
Cfluido::~Cfluido() {}

//Metodos
void Cfluido::exibePropriedades(){
    std::cout << "Densidade: " << getDensidade() << "lb/gal" << std::endl;
    std::cout << "Profundidade do fluido: " << getCamadaProfundidade() << "ft" << std::endl;
    std::cout << "Presão na Superficie: " << getpressaoSuperficie() << "psi" << std::endl;
}

double Cfluido::PressaoHidroestatica(){

    double pressaosup = getpressaoSuperficie();
    double dens = getDensidade();
    double produndidade = getCamadaProfundidade();

    return pressaosup + ( ( dens * produndidade)  * 0.052);

}
