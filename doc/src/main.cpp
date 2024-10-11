#include <iostream>
#include <iomanip> // Para melhorar formatação numérica
#include "arquivos.cpp"

// Funcao para o submenu de Perda de Carga por Friccao
void menuPerdaDeCarga() {
    int escolha = 0;
    CFluido FluidoA("Fluido_A", 8.34, 1.5);
    CTrechoPoco Trecho1("Trecho_1", 0, 9842, &FluidoA);
    CPoco Poco1(9842, 1450, 7.87, 7.09, 6.3, 132);
    CModeloNewtoniano model(&Poco1);
    Poco1.AdicionarTrechoPoco(Trecho1);

    while (true) {
        limparTela();
        desenharBorda();
        desenharLinhaTexto("Menu de Perda de Carga");
        desenharBorda();

        std::cout << "\n1. Verificar Fluxo no Poco\n"
                     "2. Calcular Perda de Friccao no Poco\n"
                     "3. Verificar Fluxo no Anular\n"
                     "4. Calcular Perda de Friccao no Anular\n"
                     "0. Voltar\n";
        std::cout << "Escolha: ";
        std::cin >> escolha;


        switch (escolha) {
            case 1:
                std::cout << "\nTipo de Fluxo no Poco: " << model.DeterminarFluxoPoco() << "\n";
                break;
            case 2:
                std::cout << "\nPerda Friccional no Poco: " << model.CalcularPerdaPorFriccaoPoco() << " psi/ft\n";
                break;
            case 3:
                std::cout << "\nTipo de Fluxo no Anular: " << model.DeterminarFluxoAnular() << "\n";
                break;
            case 4:
                std::cout << "\nPerda Friccional no Anular: " << model.CalcularPerdaPorFriccaoAnular() << " psi/ft\n";
                break;
            case 0:
                return; // Volta ao menu principal
            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
                break;
        }
        std::cout << "\nPressione Enter para continuar...";
        std::cin.ignore().get(); // Pausa ate pressionar Enter
    }
}

// Funcao para o menu principal
void menuPrincipal() {
    int escolha = 0;
    CFluido FluidoA("Fluido_A", 8.34, 1.5);
    CTrechoPoco Trecho1("Trecho_1", 0, 9842, &FluidoA);
    CPoco Poco1(9842, 1450, 7.87, 7.09, 6.3, 132);
    CModeloNewtoniano model(&Poco1);
    Poco1.AdicionarTrechoPoco(Trecho1);

    while (true) {

        limparTela();
        desenharBorda();
        desenharLinhaTexto("   Menu Principal   ");
        desenharBorda();

        std::cout << "\n1. Exibir Propriedades do Poco\n"
                     "2. Calcular Pressao Hidrostatica e Densidade no Poco\n"
                     "3. Plotar Perfil Profundidade vs Densidade\n"
                     "4. Calcular Perda de Carga por Friccao\n"
                     "0. Sair\n";
        std::cout << "Escolha: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                std::cout << "\n##### Propriedades do Poco #####\n";
                Poco1.ExibePropriedades();
                std::cout << "\n";
                Poco1.ExibeTrechos();
                break;

            case 2:
                std::cout << "\nPressao Hidrostatica Total: " << Poco1.PressaoHidroestaticaTotal() << " psi\n";
                std::cout << "Densidade Media: " << Poco1.DensidadeEfetivaTotal() << " lb/ga\n";
                break;

            case 3:
                Poco1.PlotarProfundidadePorDensidade();
                break;

            case 4:
                menuPerdaDeCarga();
                break;

            case 0:
                std::cout << "Saindo...\n";
                return; // Termina o programa

            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
                break;
        }
        std::cout << "\nPressione Enter para continuar...";
        std::cin.ignore().get(); // Pausa ate pressionar Enter
    }
}

// Funcao principal
int main() {

    cabecalho();
    menuPrincipal();
    
    return 0;
}