#include <iostream>
#include "arquivos.cpp"



// Função para o submenu de Perda de Carga por Fricção
void menuPerdaDeCarga() {
    int escolha = 0;
    while (true) {
        std::cout << "\n=== Menu de Perda de Carga por Friccao ===\n" \
                     "1. Verificar Fluxo no Poco\n" \
                     "2. Calcular Perda de Friccao no Poco\n" \
                     "3. Verificar Fluxo no Anular\n" \
                     "4. Calcular Perda de Friccao no Anular\n" \
                     "0. Voltar\n" \
                     "Escolha: ";
        std::cin >> escolha;

        CFluido FluidoA("Fluido_A", 8.34, 1.5);
        CTrechoPoco Trecho1("Trecho_1", 0, 9842, &FluidoA);
        CPoco Poco1(9842, 1450, 7.87, 7.09, 6.3, 132);
        CModeloNewtoniano model(&Poco1);
        Poco1.AdicionarTrechoPoco(Trecho1);
        mode

        switch (escolha) {
            case 1:
                
                std::cout << "Tipo de Fluxo Poco: " << model.DeterminarFluxoPoco() << "\n";
                break;
            case 2:
                std::cout << "Perda Friccional Poco: " << model.CalcularPerdaPorFriccaoPoco() << " psi/ft\n";
                break;
            case 3:
                std::cout << "Tipo de Fluxo Anular: " << model.DeterminarFluxoAnular() << "\n";
                break;
            case 4:
                system("cls");
                std::cout << "Perda Friccional Anular: " << model.CalcularPerdaPorFriccaoAnular() << " psi/ft\n";
    
                break;
            case 0:
                return;
            default:
                std::cout << "Opcao invalida!\n";
                break;
        }
    }
}

// Função para o menu principal
void menuPrincipal() {
    int escolha = 0;
    while (true) {
        std::cout << "\n=== Menu Principal ===\n" \
                     "1. Exibir Propriedade\n" \
                     "2. Calcular Pressao Hidrostatica do Poco\n" \
                     "3. Calcular Perda de Carga por Friccao\n" \
                     "0. Sair\n" \
                     "Escolha: ";
        std::cin >> escolha;

        CFluido FluidoA("Fluido_A", 8.34, 1.5);
        CTrechoPoco Trecho1("Trecho_1", 0, 9842, &FluidoA);
        CPoco Poco1(9842, 1450, 7.87, 7.09, 6.3, 132);
        CModeloNewtoniano model(&Poco1);
        Poco1.AdicionarTrechoPoco(Trecho1);

        switch (escolha) {
            case 1:

                std::cout << "\n";
                std::cout << "##### Propriedades do Poco #####";
                Poco1.ExibePropriedades();
                std::cout << "\n";
                Poco1.ExibeTrechos();

                break;

            case 2:

                std::cout << "Pressao Hidroestatica: " << Poco1.PressaoHidroestaticaTotal() << " psi\n";
                std::cout << "Densidade Media: " << Poco1.DensidadeEfetivaTotal() << " lb/ga\n";
                std::cout << "\n";

                break;

            case 3:
                menuPerdaDeCarga();
                break;

            case 0:
                std::cout << "Saindo...\n";
                return;

            default:
                std::cout << "Opcao invalida!\n";
                break;
        }
    }
}

// Função principal
int main() {

    CFluido FluidoA();
    CTrechoPoco Trecho1();
    CPoco Poco1();

    menuPrincipal();
    return 0;
}
