#include <iostream>
#include <iomanip> 


// Funcao para limpar a tela (compatível com Windows e Linux)
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Funcao para desenhar bordas de um menu quadrado
void desenharBorda() {
    std::cout << "###################################################################\n";
}


void desenharLinhaTexto(const std::string& texto) {
    int largura = 65; 
    int espacos = (largura - texto.size() - 2) / 2; 

    std::string textoParaExibir;
    if (texto.size() > static_cast<std::string::size_type>(largura - 2)) {
        textoParaExibir = texto.substr(0, largura - 2);
    } else {
        textoParaExibir = texto;
    }

    std::cout << "#"; 
    std::cout << std::setw(espacos) << ""; 
    std::cout << textoParaExibir; // Texto centralizado
    std::cout << std::setw(largura - textoParaExibir.size() - espacos - 1) << ""; 
    std::cout << "#\n";
}

// Funcao para o cabeçalho
void cabecalho() {
    limparTela();
    desenharBorda();
    desenharLinhaTexto("");
    desenharLinhaTexto("  SOFTWARE EDUCACIONAL PARA ANALISE   ");
    desenharLinhaTexto("  E SOLUCAO DE PROBLEMAS EM ENGENHARIA DE POCO  ");
    desenharLinhaTexto("");
    desenharLinhaTexto("Nathan Rangel Magalhaes - nrmagalhaes@hotmail.com");
    desenharLinhaTexto("Thauan Ferreira Barbosa - thauanbarbosa@lenep.uenf.com");
    desenharLinhaTexto("Andre Duarte Bueno - andreduartebueno@gmail.com");
    desenharLinhaTexto("");
    desenharBorda();
    std::cout << "\nPressione Enter para continuar...";
    std::cin.ignore().get(); // Pausa ate pressionar Enter
}