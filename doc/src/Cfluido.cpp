#include "CFluido.h"
#include <iostream>
#include <cmath>

//Metodos
void CFluido::ExibePropriedades() {
    std::cout << "\n- nome: " << Nome() << " \n" \
            "- Densidade: " << Densidade() << " lb/gal\n" \
            "- Viscosidade: " << Viscosidade() << " cp";
}
