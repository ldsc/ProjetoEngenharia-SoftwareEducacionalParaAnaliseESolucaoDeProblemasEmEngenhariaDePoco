#include <iostream>
#include "arquivos.cpp"

// Esse Main é apenas para testas se as classes, atributos e métodos estão rodando corretamente, favor desconsiderar códigos abaixos
int main() {

    CFluido FluidoA("Fluido_A", 8.34, 1.5);
    CTrechoPoco Trecho1("Trecho_1", 0, 9842, &FluidoA);
    CPoco Poco1(9842, 1450, 7.87, 7.09, 6.3, 132);

    Poco1.AdicionarTrechoPoco(Trecho1);

    std::cout << "\n";
    std::cout << "##### Propriedades do Poco #####";
    Poco1.ExibePropriedades();
    std::cout << "\n";
    Poco1.ExibeTrechos();

    std::cout << "Pressao Hidroestatica: " << Poco1.PressaoHidroestaticaTotal() << " psi\n";
    std::cout << "Densidade Media: " << Poco1.DensidadeEfetivaTotal() << " lb/ga\n";
    std::cout << "\n";
    
    CModeloNewtoniano model(&Poco1);
    std::cout << "Tipo de Fluxo Poco: " << model.DeterminarFluxoPoco() << "\n";
    std::cout << "Perda Friccional Poco: " << model.CalcularPerdaPorFriccaoPoco() << " psi/ft\n";
    std::cout << "\n";
    std::cout << "Tipo de Fluxo Anular: " << model.DeterminarFluxoAnular() << "\n";
    std::cout << "Perda Friccional Anular: " << model.CalcularPerdaPorFriccaoAnular() << " psi/ft\n";
    std::cout << "\n";

    Poco1.PlotarProfundidadePorDensidade();
    
    system("pause");

};
