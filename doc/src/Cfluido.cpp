#include "CFluido.h"
#include <iostream>
#include <cmath>


//Metodos
void CFluido::ExibePropriedades() {
    std::cout << "\n- Nome: " << GetNome() << " lb/gal\n" \
            "- Densidade: " << GetDensidade() << " lb/gal\n" \
            "- Viscosidade: " << GetDensidade() << " cp";
}
