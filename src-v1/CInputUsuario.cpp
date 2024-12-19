#include <iostream>
#include <string>

#include "CInputUsuario.h"

double CInputUsuario::getDouble(std::string prompt) {

    double input;

    std::cout << prompt;
    while (!(std::cin >> input)){
        
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Entrada invalida (deve ser um numero). Tente novamente: ";
    }
    return input;  
}

bool CInputUsuario::getSimNao(std::string prompt) {
    char input;
    std::cout << prompt;

    while (true) {
        std::cin >> input;
        std::cin.ignore(1000, '\n'); // Limpa o buffer para evitar problemas com entradas adicionais

        // Valida a entrada
        if (input == 's' || input == 'S') {
            return true; // Sim
        } else if (input == 'n' || input == 'N') {
            return false; // Não
        } else {
            std::cout << "Entrada inválida (use 's', 'S', 'n' ou 'N'). Tente novamente: ";
        }
    }
}

std::string CInputUsuario::getString(std::string prompt) {
    std::cout << prompt;

    while (true) {
        std::string input;
        std::getline(std::cin, input);

        // Valida e processa a entrada
        std::string resultado;
        bool entradaValida = true;

        for (char& ch : input) {
            if (std::isalpha(ch, std::locale()) || ch == ' ') {
                // Remove acentos
                switch (ch) {
                    case 'á': case 'à': case 'ã': case 'â': case 'ä': ch = 'a'; break;
                    case 'é': case 'è': case 'ê': case 'ë': ch = 'e'; break;
                    case 'í': case 'ì': case 'î': case 'ï': ch = 'i'; break;
                    case 'ó': case 'ò': case 'õ': case 'ô': case 'ö': ch = 'o'; break;
                    case 'ú': case 'ù': case 'û': case 'ü': ch = 'u'; break;
                    case 'ç': ch = 'c'; break;
                    case 'Á': case 'À': case 'Ã': case 'Â': case 'Ä': ch = 'A'; break;
                    case 'É': case 'È': case 'Ê': case 'Ë': ch = 'E'; break;
                    case 'Í': case 'Ì': case 'Î': case 'Ï': ch = 'I'; break;
                    case 'Ó': case 'Ò': case 'Õ': case 'Ô': case 'Ö': ch = 'O'; break;
                    case 'Ú': case 'Ù': case 'Û': case 'Ü': ch = 'U'; break;
                    case 'Ç': ch = 'C'; break;
                }
                // Substitui espaços por underscores
                resultado += (ch == ' ') ? '_' : ch;
            } else {
                entradaValida = false; // Marca como inválida se não for letra ou espaço
                break;
            }
        }

        if (entradaValida) {
            return resultado;
        } else {
            std::cout << "Entrada inválida (apenas letras e espaços são permitidos). Tente novamente: ";
        }
    }
}