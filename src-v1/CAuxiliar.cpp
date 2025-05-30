#include "CAuxiliar.h"

// Funcao para limpar a tela (compativel com Windows e Linux)
void CAuxiliar::limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Funcao para desenhar bordas de um menu quadrado
void CAuxiliar::desenharBorda() {
    std::cout << "###################################################################\n";
}


void CAuxiliar::desenharLinhaTexto(const std::string& texto) {
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

void CAuxiliar::desenharAviso(const std::string& aviso) {
    int largura = 65;
    std::string avisoParaExibir;

    if (aviso.size() > static_cast<std::string::size_type>(largura - 2)) {
        avisoParaExibir = aviso.substr(0, largura - 2);
    } else {
        avisoParaExibir = aviso;
    }

    std::cout << "# [AVISO] ";
    std::cout << avisoParaExibir; // Texto do aviso
    std::cout << std::setw(largura - avisoParaExibir.size() - 10) << ""; // Ajusta o espaco restante
    std::cout << "#\n";
}

// Funcao para o cabecalho
void CAuxiliar::cabecalho() {
    limparTela();
    desenharBorda();
    desenharLinhaTexto("");
    desenharLinhaTexto("  SOFTWARE EDUCACIONAL PARA ANALISE   ");
    desenharLinhaTexto("  E SOLUCAO DE PROBLEMAS EM ENGENHARIA DE poco  ");
    desenharLinhaTexto("");
    desenharLinhaTexto("Nathan Rangel Magalhaes - nrmagalhaes@hotmail.com");
    desenharLinhaTexto("Thauan Ferreira Barbosa - thauanbarbosa@lenep.uenf.com");
    desenharLinhaTexto("Andre Duarte Bueno - andreduartebueno@gmail.com");
    desenharLinhaTexto("");
    desenharBorda();
    std::cout << "\nPressione Enter para continuar...";
    std::cin.get(); // Pausa ate pressionar Enter
}
