#include "CObjetoPoco.h"
//#include "CGnuplot.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <numbers>


CPoco CPoco::CriarParaModulo01(std::string nome, double profund, double pressao,
                               double D, double OD, double ID, double q) {
    CPoco poco;
    poco.nomePoco = nome;
    poco.profundidadeFinal = profund;
    poco.pressaoSuperficie = pressao;
    poco.diametroPoco = D;
    poco.diametroRevestimentoOD = OD;
    poco.diametroRevestimentoID = ID;
    poco.vazao = q;
    return poco;
}

CPoco CPoco::CriarParaModulo02(std::string nome, double profund, double pressao,
                               double tempTopoIni, double tempFundoIni,
                               double tempTopoFim, double tempFundoFim, double packer) {
    CPoco poco;
    poco.nomePoco = nome;
    poco.profundidadeFinal = profund;
    poco.pressaoSuperficie = pressao;
    poco.temperaturaTopoInicial = tempTopoIni;
    poco.temperaturaFundoInicial = tempFundoIni;
    poco.temperaturaTopoFinal = tempTopoFim;
    poco.temperaturaFundoFinal = tempFundoFim;
    poco.profundidadePacker = packer;
    return poco;
}

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

    trechos.push_back(std::move(TrechoPoco));
    profundidadeOcupada += ProfundidadeFluido;
    return true;
}

void CPoco::RemoverTrechoPoco(const std::string& nomeFluido) {
    for (auto it = trechos.begin(); it != trechos.end();) {
        if ((*it)->Nome() == nomeFluido) {
            double ProfundidadeFluido = (*it)->ProfundidadeFinal() - (*it)->ProfundidadeInicial();
            it = trechos.erase(it); // Remove o trecho e atualiza o iterador
            profundidadeOcupada -= ProfundidadeFluido;
        } else {
            ++it; // Apenas avança para o próximo
        }
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

std::pair<std::vector<double>, std::vector<double>> CPoco::PlotarProfundidadePorPressaoMedia() {

    std::vector<double> profundidades;
    std::vector<double> pressoes;

    for (double z = 0.0; z <= ProfundidadeTotal(); z += 1) {
        profundidades.push_back(z);
        pressoes.push_back(PressaoHidroestaticaNoPonto(z));
    }

    return std::make_pair(profundidades, pressoes);
}

std::pair<std::vector<double>, std::vector<double>> CPoco::PlotarProfundidadePorPressao() {

}

/*
double CargaInicial() const;
double DeltaLTemperatura() const;
double DeltaLEfeitoBalao() const;
double VariacaoCargaEfeitoPistao() const;
double DeltaLPistaoPacker() const;
double DeltaLPistaoCrossover() const;
double DeltaLForcaRestauradora() const;
double CargaInjecao(bool colunaFixa) const; // ou com enum
*/
#include <QDebug>
#include <QDebug>

double CPoco::CargaInicial(double profundidade) const { // calculos errados
    const double pi = 3.141592653589793;
    double cargaTotal = 0.0;

    // === 1. Pressão hidrostática interna no ponto ===
    for (const auto& trecho : trechos) {
        if (profundidade >= trecho->ProfundidadeInicial() &&
            profundidade <= trecho->ProfundidadeFinal()) {

            double di = trecho->DiametroInterno(); // polegadas
            double As = pi / 4.0 * (di * di);       // área da seção interna (in²)

            double rho = trecho->Fluido()->Densidade(); // lb/gal
            double P = 0.052 * rho * profundidade;      // psi

            double F = P * As; // lbf
            cargaTotal += F;

            qDebug() << "🔷 Pressão hidrostática interna:";
            qDebug() << "  Profundidade       =" << profundidade << "ft";
            qDebug() << "  Densidade (ρ)      =" << rho << "lb/gal";
            qDebug() << "  Pressão (P)        =" << P << "psi";
            qDebug() << "  Área seção (As)    =" << As << "in²";
            qDebug() << "  Força P·As         =" << F << "lbf";
            break;
        }
    }

    // === 2. Efeitos pistão de todos os crossovers acima ===
    for (size_t i = 1; i < trechos.size(); ++i) {
        const auto& cima = trechos[i - 1];
        const auto& baixo = trechos[i];

        double zCross = baixo->ProfundidadeInicial();

        if (zCross >= profundidade)
            continue;

        double rhoIn = cima->Fluido()->Densidade();
        double rhoOut = baixo->Fluido()->Densidade();

        double deltaPi = 0.052 * rhoIn * zCross;
        double deltaPo = 0.052 * rhoOut * zCross;

        double Ain = pi / 4.0 * (cima->DiametroInterno() * cima->DiametroInterno());
        double Aout = pi / 4.0 * (baixo->DiametroExterno() * baixo->DiametroExterno());

        double deltaF = deltaPi * Ain + deltaPo * Aout;
        cargaTotal += deltaF;

        qDebug() << "🔶 Efeito pistão no crossover em" << zCross << "ft:";
        qDebug() << "  ΔPi (P interno)     =" << deltaPi << "psi";
        qDebug() << "  ΔPo (P externo)     =" << deltaPo << "psi";
        qDebug() << "  Ain (área interna)  =" << Ain << "in²";
        qDebug() << "  Aout (área externa) =" << Aout << "in²";
        qDebug() << "  ΔF (empuxo pistão)  =" << deltaF << "lbf";
    }

    // === 3. Peso da coluna acima da profundidade ===
    for (const auto& trecho : trechos) {
        double zi = trecho->ProfundidadeInicial();
        double zf = trecho->ProfundidadeFinal();

        if (zf <= profundidade)
            continue;

        double z1 = std::max(profundidade, zi);
        double L = zf - z1;
        if (L > 0.0) {
            double pesoLinear = trecho->PesoUnidade(); // lb/ft
            double pesoTotal = pesoLinear * L;
            cargaTotal += pesoTotal;

            qDebug() << "🔷 Peso da coluna (trecho de" << z1 << "a" << zf << "ft):";
            qDebug() << "  Comprimento (L)     =" << L << "ft";
            qDebug() << "  Peso específico      =" << pesoLinear << "lb/ft";
            qDebug() << "  Força peso           =" << pesoTotal << "lbf";
        }
    }

    qDebug() << "✅ Carga total em" << profundidade << "ft = " << cargaTotal << "lbf";
    return cargaTotal;
}

double CPoco::DeltaLTemperaturaTotal() const {
    double deltaLTotal = 0.0;
    double Tref = TemperaturaTopoInicial(); // Temperatura inicial do poço (referência)

    for (const auto& trecho : trechos) {
        double z1 = trecho->ProfundidadeInicial();
        double z2 = trecho->ProfundidadeFinal();
        double L = z2 - z1;
        if (L <= 0.0)
            continue;

        double alpha = trecho->CoeficienteExpancaoTermica();

        double Tz1 = TemperaturaNoPonto(z1);
        double Tz2 = TemperaturaNoPonto(z2);
        double Tmed = (Tz1 + Tz2) / 2.0;
        double deltaT = Tref - Tmed;

        double deltaL = alpha * L * deltaT;
        deltaLTotal += deltaL;

        qDebug() << "Trecho:" << z1 << "→" << z2 << "ft";
        qDebug() << "  L       =" << L << "ft";
        qDebug() << "  α       =" << alpha;
        qDebug() << "  T(z1)   =" << Tz1 << "°F";
        qDebug() << "  T(z2)   =" << Tz2 << "°F";
        qDebug() << "  ΔT      =" << deltaT << "°F";
        qDebug() << "  ΔL      =" << deltaL << "ft";
    }

    qDebug() << "✅ ΔL térmico total da coluna = " << deltaLTotal << "ft";
    return deltaLTotal;
}


double CPoco::TemperaturaNoPonto(double profundidade) const {
    double Ttopo = TemperaturaTopoInicial();
    double Tfundo = TemperaturaFundoInicial();
    double H = ProfundidadeTotal();

    if (H <= 0.0)
        return Ttopo; // evita divisão por zero

    return Ttopo + (Tfundo - Ttopo) * (profundidade / H);
}
