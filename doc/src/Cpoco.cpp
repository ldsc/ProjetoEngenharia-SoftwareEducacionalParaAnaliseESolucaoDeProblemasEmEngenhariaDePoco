#include "CPoco.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib> 

// Métodos

std::vector<CTrechoPoco*> CPoco::Trechos() const {
    std::vector<CTrechoPoco*> trechosPonteiros;
    for (const auto& trecho : trechos) {
        trechosPonteiros.push_back(trecho.get()); // Adiciona o ponteiro do trecho ao vetor
    }
    return trechosPonteiros; // Retorna o vetor de ponteiros
}

bool CPoco::AdicionarTrechoPoco(std::unique_ptr<CTrechoPoco> TrechoPoco) {
    double ProfundidadeFluido = TrechoPoco->ProfundidadeFinal() - TrechoPoco->ProfundidadeInicial();

    // Verifica se a profundidade total ocupada + profundidade do novo fluido excede a profundidade total do poço
    if (profundidadeOcupada + ProfundidadeFluido <= profundidadeFinal) {
        trechos.push_back(std::move(TrechoPoco)); 
        profundidadeOcupada += ProfundidadeFluido;
        return true;
    } else {
        std::cout << "Erro: O fluido excede a profundidade total do poço!\n";
        return false;
    }
}

double CPoco::PressaoHidroestaticaTotal() const {
    double PressaoTotal = 0.0;
    for (const auto& Trecho : trechos) {
        PressaoTotal += Trecho->PressaoHidroestatica();
    }
    return PressaoTotal + pressaoSuperficie;
}

void CPoco::VerificarPreenchimentoColuna() {
    double ProfundidadeNaoOcupada = profundidadeFinal - profundidadeOcupada;

    if (ProfundidadeNaoOcupada > 0) {
        std::cout << "Uma coluna de " << ProfundidadeNaoOcupada << " ft de fluido precisa ser adicionada!\n";
        std::cout << std::endl;
    } else {
        std::cout << "A coluna de fluidos equivale à profundidade da coluna do poço!\n";
        std::cout << std::endl;
    }
}

double CPoco::DensidadeEfetivaTotal() const {
    double DensidadeTotal = 0.0;
    double ComprimentoTotal = 0.0;

    for (const auto& Trecho : trechos) {
        double ComprimentoTrecho = Trecho->ProfundidadeFinal() - Trecho->ProfundidadeInicial();
        DensidadeTotal += Trecho->DensidadeEquivalente() * ComprimentoTrecho;
        ComprimentoTotal += ComprimentoTrecho;
    }

    return DensidadeTotal / ComprimentoTotal;
}

double CPoco::ViscosidadeEfetivaTotal() const {
    double ViscosidadeTotal = 0.0;
    for (const auto& Trecho : trechos) {
        ViscosidadeTotal += Trecho->Fluido()->Viscosidade();
    }
    return ViscosidadeTotal / trechos.size();
}

void CPoco::PlotarProfundidadePorDensidade() { 
    std::vector<double> Profundidade;
    std::vector<double> Densidade;

    double ProfunTotal = 0;

    // Coletar dados para a profundidade e densidade
    for (const auto& trecho : trechos) {
        double Intervalo = trecho->ProfundidadeFinal() - trecho->ProfundidadeInicial();  

        for (double i = 0; i <= Intervalo; i += 0.1) { // Usando um incremento menor
            double ProfundidadeAtual = ProfunTotal + i; // Atualiza a profundidade em cada iteração
            double Dens = PressaoHidroestaticaTotal() / (ProfundidadeAtual * 0.05195);
   
            Densidade.push_back(Dens);
            Profundidade.push_back(ProfundidadeAtual); // Armazena a profundidade atual
        }
        ProfunTotal += Intervalo; // Avança a profundidade total
    }        

    // Escrever dados em arquivo
    std::ofstream outputFile("dados.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo dados.txt para escrita." << std::endl;
        return;
    }
    
    for (size_t j = 0; j < Profundidade.size(); ++j) {
        outputFile << Profundidade[j] << "\t" << Densidade[j] << std::endl;
    }
    outputFile.close();

    // Comando Gnuplot para plotar os dados
    std::ofstream gnuplotFile("plot_script.gp");
    if (!gnuplotFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo plot_script.gp para escrita." << std::endl;
        return;
    }
    
    gnuplotFile << "set title 'Profundidade vs Densidade'\n";
    gnuplotFile << "set xlabel 'Densidade, lbm/gal'\n"; // Corrigido o label
    gnuplotFile << "set ylabel 'Profundidade, ft'\n"; // Corrigido o label
    gnuplotFile << "set yrange [20:0]\n"; // Inverter o eixo Y
    gnuplotFile << "set grid\n"; // Adicionar grade ao gráfico
    gnuplotFile << "set style data linespoints\n"; // Estilo de linha com pontos

    // Plota apenas uma curva
    gnuplotFile << "plot 'dados.txt' using 2:1 with linespoints title 'Densidade vs Profundidade'\n"; 
    gnuplotFile << "pause -1\n"; // Pausa para que você possa ver o gráfico
    gnuplotFile.close();

    // Executa o Gnuplot com o script gerado
    std::system("gnuplot plot_script.gp");
}
