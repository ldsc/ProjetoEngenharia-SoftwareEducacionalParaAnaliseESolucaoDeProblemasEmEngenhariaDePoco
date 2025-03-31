#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

#include "CRelatorioSimulacao.h"

void CRelatorioPoco::ArmazenarValor(std::string nomePoco, std::string texto, double valor) {
    
    ArmazenarValor(nomePoco, texto, valor, "");
    
}


void CRelatorioPoco::ArmazenarValor(std::string nomePoco, std::string texto, double valor, std::string unidade) {

    std::ofstream arquivo("ArquivoPoco-" + nomePoco + ".dat", std::ios::app);

    if (arquivo.is_open()) {
        // Escreve os dados no arquivo, incluindo o texto, valor e unidade, seguidos de uma nova linha
        arquivo << texto << valor << unidade << std::endl;
    } else {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
    }   
}

void CRelatorioPoco::criarArquivoDAT(const std::string& nomePoco, const std::unique_ptr<CPoco>& poco) {
    // O nome do arquivo será o nome do poço com a extensão .dat
    std::string nomeArquivo = "ArquivoPoco-" + nomePoco + ".dat";

    // Verificar se o arquivo já existe, tentando abrir em modo de leitura
    std::ifstream arquivoExistente(nomeArquivo);
    if (arquivoExistente.is_open()) {
        std::cout << "### O relatorio " << nomeArquivo << " ja existe. Nao sera criado novamente." << std::endl;
        return;
    }

    // Caso o arquivo não exista, cria um arquivo em branco com o nome do poço
    std::ofstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        // Arquivo criado com o nome do poço, mas vazio
        arquivo << "\nPropriedades do Poco:" << std::endl;
            arquivo << std::setw(30) << "Nome Poco:"
                    << std::setw(15) << poco->NomePoco() << std::endl;

            arquivo << std::setw(30) << "Profundidade Total:" 
                    << std::setw(15) << poco->ProfundidadeTotal() << " ft" << std::endl;

            arquivo << std::setw(30) << "Profundidade Ocupada:" 
                    << std::setw(15) << poco->ProfundidadeOcupada() << " ft" << std::endl;

            arquivo << std::setw(30) << "Pressao Superficie:" 
                    << std::setw(15) << poco->PressaoSuperficie() << " psi" << std::endl;

            arquivo << std::setw(30) << "Diametro Poco:" 
                    << std::setw(15) << poco->DiametroPoco() << " in" << std::endl;

            arquivo << std::setw(30) << "Diametro Revestimento OD:" 
                    << std::setw(15) << poco->DiametroRevestimentoOD() << " in" << std::endl;

            arquivo << std::setw(30) << "Diametro Revestimento ID:" 
                    << std::setw(15) << poco->DiametroRevestimentoID() << " in" << std::endl;

            arquivo << std::setw(30) << "Vazao:" 
                    << std::setw(15) << poco->Vazao() << " gal/min" << std::endl;

            arquivo << std::setw(30) << "Densidade Media:" 
                    << std::setw(15) << poco->DensidadeEfetivaTotal() << " lb/ga" << std::endl;

            arquivo << std::setw(30) << "Viscosidade Media:" 
                    << std::setw(15) << poco->ViscosidadeEfetivaTotal() << " cP" << std::endl;

            // Cabecalho da tabela
            arquivo << std::endl;
            arquivo << std::setw(20) << "Nome do Fluido" 
                    << std::setw(20) << "Densidade (lb/gal)" 
                    << std::setw(20) << "Viscosidade (cP)" 
                    << std::setw(20) << "Prof. Inicial (ft)" 
                    << std::setw(20) << "Prof. Final (ft)" << std::endl;

            // Linha de separacao
            arquivo << std::string(100, '-') << std::endl;

            // Exibir dados dos fluidos
            for (const auto& trecho : poco->Trechos()) {
                arquivo << std::setw(20) << trecho->Fluido()->Nome()
                        << std::setw(20) << trecho->Fluido()->Densidade()
                        << std::setw(20) << trecho->Fluido()->Viscosidade()
                        << std::setw(20) << trecho->ProfundidadeInicial()
                        << std::setw(20) << trecho->ProfundidadeFinal() << std::endl;
            }

            arquivo << std::endl;
            arquivo << "\nHistorico de operacoes:" << std::endl;
            arquivo << std::string(100, '-') << std::endl;

        std::cout << "### O relatorio " << nomeArquivo << " foi criado com sucesso!" << std::endl;
        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << std::endl;
    }
}
