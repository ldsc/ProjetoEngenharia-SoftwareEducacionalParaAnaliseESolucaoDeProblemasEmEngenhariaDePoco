#include "CTrechoTubulacao.h"
#include <iostream>

// Calcula a pressao hidrostatica total do trecho (de profundidadeInicial ate profundidadeFinal)
double CTrechoPoco::PressaoHidroestatica() {
    double comprimento = profundidadeFinal - profundidadeInicial;
    return comprimento * 0.05195 * fluido->Densidade(); // 0.05195 é o fator de conversao para psi
}

// Calcula a pressao hidrostatica ate uma profundidade relativa passada como argumento
double CTrechoPoco::PressaoHidroestatica(double profundidadeRelativa) {
    return profundidadeRelativa * 0.05195 * fluido->Densidade();
}

// Calcula a densidade equivalente do trecho com base na pressao hidrostatica
double CTrechoPoco::DensidadeEquivalente() {
    double comprimento = profundidadeFinal - profundidadeInicial;

    // evita divisao por zero no caso de profundidades iguais
    if (comprimento <= 0.0)
        return 0.0;

    return PressaoHidroestatica() / (comprimento * 0.05195);
}
