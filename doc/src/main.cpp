#include <iostream>
#include "Coleo.cpp"
#include "Cgas.cpp"
#include "Cpoco.cpp"



int main() {

    Coleo oleo(11, 0, 12000, 0);

    std::cout << "\n";
    oleo.exibePropriedades();
    std::cout << "\n";
    std::cout << "Pressao hidroestatica:" << oleo.PressaoHidroestatica() << " psi" << std::endl;
    std::cout << "Densidade Equivalente:" << oleo.DensidadeEquivalente() << " lbm/gal" << std::endl;

    std::cout << "\n";
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "\n";

    Cgas gas(1, 5500, 6000, 4000, 16, 1, 629);
    std::cout << "\n";
    gas.exibePropriedades();
    std::cout << "\n";
    std::cout << "Pressao hidroestatica:" << gas.PressaoHidroestatica() << " psi" << std::endl;
    std::cout << "Densidade Equivalente:" << gas.DensidadeEquivalente() << " lbm/gal" << std::endl;
    std::cout << "\n";

    std::cout << "\n";
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "\n";

    Cpoco poco(12500);
    poco.adicionarFluido(oleo);
    poco.adicionarFluido(gas);
    poco.exibeFluidos();
    poco.verificarPreenchimentoColuna();
    std::cout << "Pressao hidroestatica Total:" << poco.pressaoHidroestaticaTotal() << " psi" << std::endl; 
    std::cout << "Densidade Efetiva Total:" << poco.DensidadeEfetivaTotal() << " psi" << std::endl; 

    system("pause");

};