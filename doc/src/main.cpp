#include <iostream>
#include "arquivos.cpp"

// Esse Main é apenas para testas se as classes, atributos e métodos estão rodando corretamente, favor desconsiderar códigos abaixos
int main() {

    CFluido Fluido1("m", 10.5);
    CFluido Fluido2("fl", 8.5);
    CFluido Fluido3("fc", 12.7);
    CFluido Fluido4("hc", 16.7);

    CTrechoPoco secao1("Secao1", 0, 7000, &Fluido1);
    CTrechoPoco secao2("Secao2", 7000, 7300, &Fluido2);
    CTrechoPoco secao3("Secao3", 7300, 9000, &Fluido3);
    CTrechoPoco secao4("Secao4", 9000, 10000, &Fluido4);
  
    CPoco Poco(10000, 0);

    Poco.AdicionarTrechoPoco(secao1);
    Poco.AdicionarTrechoPoco(secao2);
    Poco.AdicionarTrechoPoco(secao3);
    Poco.AdicionarTrechoPoco(secao4);

    std::cout << "\n";
    Poco.ExibeTrechos();
    std::cout << "\n";
    std::cout << "Pressao hidroestatica: " << Poco.PressaoHidroestaticaTotal() << " psi" << std::endl;
    std::cout << "Densidade Equivalente: " << Poco.DensidadeEfetivaTotal() << " lbm/gal" << std::endl;

    Poco.PlotarProfundidadePorDensidade();

    std::cout << "--------------------------------------------------------------\n";

    CFluido Fluido5("agua", 8.33, 1);
    CTrechoPoco secao5("Secao5", 0, 5000, &Fluido5);
    CPoco Poco2(5000, 0 , 6.5, 4.5, 3.826, 500);

    Poco2.AdicionarTrechoPoco(secao5);
    CModeloNewtoniano model(&Poco2);

    std::string fluxo = model.DeterminarFluxoPoco();
    double perda = model.CalcularPerdaPorFriccaoPoco();
    std::string fluxoA = model.DeterminarFluxoAnular();
    double perdaA = model.CalcularPerdaPorFriccaoAnular();

    std::cout << fluxo << std::endl;
    std::cout << perda << std::endl;
    std::cout << fluxoA << std::endl;
    std::cout << perdaA << std::endl;

    system("pause");

};
