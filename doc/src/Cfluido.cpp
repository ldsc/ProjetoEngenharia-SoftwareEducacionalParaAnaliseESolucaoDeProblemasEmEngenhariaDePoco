#include "CFluido.h"
#include <iostream>
#include <cmath>


//Metodos
void CFluido::ExibePropriedades() {
    std::cout << "\n- Nome: " << GetNome() << " lb/gal ";
    std::cout << "\n- Densidade: " << GetDensidade() << " lb/gal";
    std::cout << "\n- Viscosidade: " << GetDensidade() << " cp";
}
