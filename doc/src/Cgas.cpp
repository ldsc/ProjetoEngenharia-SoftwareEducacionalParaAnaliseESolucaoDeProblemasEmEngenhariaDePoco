#include "Cgas.h"
#include <iostream>
#include <cmath>

//Construtor
Cgas::Cgas(double dens, double profundidadeI, double profundidadeF, double pressaoSup, double massaM, double FatorC, double temp)
  : Cfluido(dens, profundidadeI, profundidadeF, pressaoSup), MassaMolar(massaM), FatorCompressibilidade(FatorC), Temperatura(temp) {}

//Metodos
void Cgas::exibePropriedades(){
  std::cout << "\n- Profundidade inicial do fluido: " << getProfundidadeInicial() << " ft"
            << "\n- Profundidade final do fluido: " << getProfundidadeFinal() << " ft"
            << "\n- Pressao na Superficie: " << getpressaoSuperficie() << " psi"
            << "\n- Massa Molar " << getMassaMolar() << " lb/mol"
            << "\n- Z (fator de compressibilidade): " << getFatorCompressibilidade()
            << "\n- Temperatura: " << getTemperatura() << " K"
            << "\n- Constante R: " << getconst_R();
}

double Cgas::PressaoHidroestatica() {
  return pressaoSuperficie * exp( ( MassaMolar / (FatorCompressibilidade * Temperatura * const_R) * ( profundidadeInicial  - profundidadeFinal) ));

}

double Cgas::DensidadeEquivalente() {
  return PressaoHidroestatica()     / (profundidadeFinal  * 0.05195);

}
