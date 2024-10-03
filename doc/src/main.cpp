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

    system("pause");

};
