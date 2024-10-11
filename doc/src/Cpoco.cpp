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
        std::cout << "##### Trecho: " << (i + 1) << " ##### \n";

        Trechos[i]->ExibePropriedades();
        std::cout << std::endl;
    }
}

void CPoco::ExibePropriedades() const {
    std::cout << "\n- Profundidade Total: " << GetProfundidadeTotal() << " ft" \
                 "\n- Profunidade Ocupada: " << GetProfundidadeOcupada() << " ft" \
                 "\n- Pressao Superficie: " << GetPressaoSuperficie() << " psi" \
                 "\n- Diametro Poco: " << GetDiametroPoco() << " in" \
                 "\n- Diametro Revestimento OD: " << GetDiametroRevestimentoOD() << " in" \
                 "\n- Diametro Revestimento ID: " << GetDiametroRevestimentoID() << " in" \
                 "\n- Vazao: " << GetVazao() << " gal/min\n";
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

        std::cout << "Uma coluna de "<< ProfundidadeNaoOcupada << "ft de fluido precisa ser adicionada!\n";
        std::cout << std::endl;
    }

    else{
        std::cout << "A coluna de fluidos equivale a profundidade da coluna do poco!\n";
        std::cout << std::endl;
    }
}

double CPoco::DensidadeEfetivaTotal() const {

    double DensidadeTotal = 0.0;
    double ComprimentoTotal = 0.0;

    for (const auto& Trecho : Trechos) {
        double ComprimentoTrecho = Trecho->GetProfundidadeFinal() - Trecho->GetProfundidadeInicial();
        DensidadeTotal += Trecho->DensidadeEquivalente() * ComprimentoTrecho;
        ComprimentoTotal += ComprimentoTrecho;
    }

    return DensidadeTotal / ComprimentoTotal;
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

    // Coletar dados para a profundidade e densidade
    for (const auto& trecho : Trechos) {
        double Intervalo = trecho->GetProfundidadeFinal() - trecho->GetProfundidadeInicial();  

        for (double i = 0; i <= Intervalo; i += 1) {
            double ProfundidadeAtual = ProfunTotal + i; // Atualiza a profundidade em cada iteração
            double Dens = PressaoHidroestaticaTotal() / (ProfundidadeAtual * 0.05195);
   
            Densidade.push_back(Dens);
            Profundidade.push_back(ProfundidadeAtual); // Armazena a profundidade atual
        }
        ProfunTotal += Intervalo; // Avança a profundidade total
    }        

    std::ofstream outputFile("dados.txt");
    for (size_t j = 0; j < Profundidade.size(); ++j) {
        outputFile << Profundidade[j] << "\t" << Densidade[j] << std::endl;
    }
    outputFile.close();

    // Comando Gnuplot para plotar os dados
    std::ofstream gnuplotFile("plot_script.gp");
    gnuplotFile << "set title 'Profundidade vs Densidade'\n";
    gnuplotFile << "set xlabel 'ESD, lbm/gal'\n";
    gnuplotFile << "set ylabel 'Depth, ft'\n";
    gnuplotFile << "set yrange [20:0] \n"; // Inverter o eixo Y
    gnuplotFile << "set grid\n"; // Adicionar grade ao gráfico
    gnuplotFile << "set style data linespoints\n"; // Estilo de linha com pontos

    // Plota apenas uma curva
    gnuplotFile << "plot 'dados.txt' using 2:1 with linespoints title 'Densidade vs Profundidade'\n"; 
    gnuplotFile << "pause -1\n"; // Pausa para que você possa ver o gráfico
    gnuplotFile.close();

    // Executa o Gnuplot com o script gerado
    std::system("gnuplot plot_script.gp");
}

