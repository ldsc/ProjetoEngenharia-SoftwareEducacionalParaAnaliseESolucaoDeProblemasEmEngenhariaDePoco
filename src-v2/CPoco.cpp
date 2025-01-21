#include "CPoco.h"
//#include "CGnuplot.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib> 

// Metodos

std::vector<CTrechoPoco*> CPoco::Trechos() const {
    std::vector<CTrechoPoco*> trechosPonteiros;
    for (const auto& trecho : trechos) {
        trechosPonteiros.push_back(trecho.get()); // Adiciona o ponteiro do trecho ao vetor
    }
    return trechosPonteiros; // Retorna o vetor de ponteiros
}

bool CPoco::AdicionarTrechoPoco(std::unique_ptr<CTrechoPoco> TrechoPoco) {
    double ProfundidadeFluido = TrechoPoco->ProfundidadeFinal() - TrechoPoco->ProfundidadeInicial();

    // Verifica se a profundidade total ocupada + profundidade do novo fluido excede a profundidade total do poco
    if (profundidadeOcupada + ProfundidadeFluido <= profundidadeFinal) {
        trechos.push_back(std::move(TrechoPoco)); 
        profundidadeOcupada += ProfundidadeFluido;
        return true;
    } else {
        std::cout << "Erro: O fluido excede a profundidade total do poco!\n";
        return false;
    }
}

double CPoco::PressaoHidroestaticaTotal() const {

    double pressaoTotal = 0.0;

    for (const auto& Trecho : trechos) {
        pressaoTotal += Trecho->PressaoHidroestatica();
    }
    return pressaoTotal + pressaoSuperficie;
}

double CPoco::PressaoHidroestaticaNoPonto(double profundidade) const {
    double pressaoTotal = pressaoSuperficie;
    double profundidadeAcumulada = 0.0;

    for (const auto& Trecho : trechos) {
        double profundidadeTrecho = Trecho->ProfundidadeFinal() - Trecho->ProfundidadeInicial();
        
        // Verifica se a profundidade esta dentro do trecho atual
        if (profundidade <= profundidadeAcumulada + profundidadeTrecho) {
            // Calcula a contribuicao do trecho ate a profundidade desejada
            pressaoTotal += Trecho->PressaoHidroestatica(profundidade - profundidadeAcumulada);
            break;
        } else {
            // Adiciona a pressao hidrostatica do trecho completo
            pressaoTotal += Trecho->PressaoHidroestatica();
            profundidadeAcumulada += profundidadeTrecho;
        }
    }

    return pressaoTotal;
}

bool CPoco::VerificarPreenchimentoColuna() {
    double ProfundidadeNaoOcupada = profundidadeFinal - profundidadeOcupada;

    if (ProfundidadeNaoOcupada > 0) {
        std::cout << "Uma coluna de " << ProfundidadeNaoOcupada << " ft de fluido precisa ser adicionada!\n";
        std::cout << std::endl;
        return false; // Caluna nao preenchida
    } else {
        std::cout << "A coluna de fluidos equivale à profundidade da coluna do poco!\n";
        std::cout << std::endl;
        return true; // coluna preenchida
    }
}

double CPoco::DensidadeEfetivaTotal() const {
    double densidadeTotal = 0.0;
    double comprimentoTotal = 0.0;
    double comprimentoTrecho =0.0;

    for (const auto& Trecho : trechos) {
        comprimentoTrecho = Trecho->ProfundidadeFinal() - Trecho->ProfundidadeInicial();
        densidadeTotal += Trecho->DensidadeEquivalente() * comprimentoTrecho;
        comprimentoTotal += comprimentoTrecho;
    }

    return densidadeTotal / comprimentoTotal;
}

double CPoco::ViscosidadeEfetivaTotal() const {
    
    double viscosidadeTotal = 0.0;

    for (const auto& Trecho : trechos) {
        viscosidadeTotal += Trecho->Fluido()->Viscosidade();
    }
    return viscosidadeTotal / trechos.size();
}

void CPoco::PlotarProfundidadePorDensidade() { 
    std::vector<double> Profundidade;
    std::vector<double> Densidade;

    double profundidadeTotal = 0;

    // Coletar dados para a profundidade e densidade
    for (const auto& trecho : trechos) {
        
        double Intervalo = trecho->ProfundidadeFinal() - trecho->ProfundidadeInicial();  

        for (double i = 0; i <= Intervalo; i += 1) { // Usando um incremento menor
            double ProfundidadeAtual = profundidadeTotal + i; // Atualiza a profundidade em cada iteracao
            double Dens = PressaoHidroestaticaNoPonto(ProfundidadeAtual) / (ProfundidadeAtual * 0.05195);
   
            Densidade.push_back(Dens);
            Profundidade.push_back(ProfundidadeAtual); // Armazena a profundidade atual
        }
        profundidadeTotal += Intervalo; // Avanca a profundidade total
    }        

    // Escrever dados em arquivo
    std::ofstream outputFile("dadosSimulacaoPoco_Gnuplot.dat");
    
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
    gnuplotFile << "set grid\n"; // Adicionar grade ao grafico
    gnuplotFile << "set style data linespoints\n"; // Estilo de linha com pontos

    // Plota apenas uma curva
    gnuplotFile << "plot 'dados.txt' using 2:1 with linespoints title 'Densidade vs Profundidade'\n"; 
    gnuplotFile << "set terminal pngcairo size 1920,1080\n";
    gnuplotFile << "set output 'Profundidade_vs_densidade.png'\n";
    gnuplotFile << "pause -1\n"; // Pausa para que voce possa ver o grafico
    gnuplotFile.close();

    // Executa o Gnuplot com o script gerado
    std::system("gnuplot -persist plot_script.gp");
}
