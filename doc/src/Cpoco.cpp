#include "CPoco.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib> 


// Metodos
bool CPoco::AdicionarTrechoPoco(CTrechoPoco& TrechoPoco) {

    double ProfundidadeFluido = TrechoPoco.GetProfundidadeFinal() - TrechoPoco.GetProfundidadeInicial();

    // Verifica se a profundidade total ocupada + profundidade do novo fluido excede a profundidade total do poço
    if (ProfundidadeOcupada + ProfundidadeFluido <= ProfundidadeTotal) {
        Trechos.push_back(&TrechoPoco);
        ProfundidadeOcupada += ProfundidadeFluido;
        return true;

    } else {
        std::cout << "Erro: O fluido excede a profundidade total do poço!\n";
        return false;
    }
}

void CPoco::ExibeTrechos() const {
    for (size_t i = 0; i < Trechos.size(); ++i) {
        std::cout << "##### Camada: " << (i + 1) << " #####" << std::endl;

        Trechos[i]->ExibePropriedades();
        std::cout << std::endl;
    }
}

double CPoco::PressaoHidroestaticaTotal() const {

    double PressaoTotal = 0.0;

    for (const auto& Trecho : Trechos) {
        PressaoTotal += Trecho->PressaoHidroestatica();
    }
    return PressaoTotal + PressaoSuperficie;
}

void CPoco::VerificarPreenchimentoColuna() {

    double ProfundidadeNaoOcupada = ProfundidadeTotal - ProfundidadeOcupada;

    if (ProfundidadeNaoOcupada > 0) {

        std::cout << "Uma coluna de "<< ProfundidadeNaoOcupada << "ft de fluido precisa ser adicionada!" << std::endl;
        std::cout << std::endl;
    }

    else{
        std::cout << "A coluna de fluidos equivale a profundidade da coluna do poco! " << std::endl;
        std::cout << std::endl;
    }
}

double CPoco::DensidadeEfetivaTotal() const {

    double DensidadeTotal = 0.0;

    for (const auto& Trecho : Trechos) {
        DensidadeTotal += Trecho->DensidadeEquivalente();
    }
    return DensidadeTotal / Trechos.size();

}

double CPoco::ViscosidadeEfetivaTotal() const {

    double ViscosidadeTotal = 0.0;

    for (const auto& Trecho : Trechos) {
        ViscosidadeTotal += Trecho->GetFluido()->GetViscosidade();
    }
    return ViscosidadeTotal / Trechos.size();

}

void CPoco::PlotarProfundidadePorDensidade() { 
    std::vector<double> Profundidade;
    std::vector<double> Densidade;

    double ProfunTotal = 0;

    for (const auto& trecho : Trechos) {
        double Intervalo = trecho->GetProfundidadeFinal() - trecho->GetProfundidadeInicial();  

        for (double i = 0; i <= Intervalo; i += 1) {
            
            double Dens = PressaoHidroestaticaTotal() / ( (ProfunTotal) * 0.05195 );
   
            Densidade.push_back(Dens);
            Profundidade.push_back(ProfunTotal);

            ProfunTotal += 1;
        }
    }        

    std::ofstream outputFile("dados.txt");
    for (size_t j = 0; j < Profundidade.size(); ++j) {
        outputFile << Profundidade[j] << "\t" << Densidade[j] << std::endl;
    }
    outputFile.close();

    // Comando Gnuplot para plotar os dados
    std::ofstream gnuplotFile("plot_script.gp");
    gnuplotFile << "set title 'Profundidade vs Densidade'\n";
    gnuplotFile << "set xlabel 'Profundidade'\n";
    gnuplotFile << "set ylabel 'Densidade'\n";
    gnuplotFile << "plot 'dados.txt' using 1:2 with linespoints title 'Densidade vs Profundidade'\n";
    gnuplotFile << "pause -1\n"; // Pausa para que você possa ver o gráfico
    gnuplotFile.close();

    // Executa o Gnuplot com o script gerado
    std::system("gnuplot plot_script.gp");
}
