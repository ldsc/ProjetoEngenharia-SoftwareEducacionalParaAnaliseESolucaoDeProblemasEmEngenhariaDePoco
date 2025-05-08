#ifndef COBJETOPOCO_H
#define COBJETOPOCO_H

#include <vector>
#include <memory>
#include "CTrechoTubulacao.h"

class CPoco {
protected:
    std::string nomePoco;
    double profundidadeFinal = 0.0;
    double profundidadeOcupada = 0.0;
    double pressaoSuperficie = 0.0;
    double diametroPoco = 0.0;
    double diametroRevestimentoOD = 0.0;
    double diametroRevestimentoID = 0.0;
    double vazao = 0.0;
    std::vector<std::unique_ptr<CTrechoPoco>> trechos;

    // Dados a mais que precisam ser coletados caso rode a simulacao do modulo 02
    double temperaturaTopoInicial = 0.0;
    double temperaturaFundoInicial = 0.0;
    double temperaturaTopoFinal = 0.0;
    double temperaturaFundoFinal = 0.0;
    double profundidadePacker = 0.0;

public:
    //construtor
    CPoco() = default;
    ~CPoco() = default;

    // Desativa a cópia
    CPoco(const CPoco&) = delete;
    CPoco& operator=(const CPoco&) = delete;

    // Habilita movimento
    CPoco(CPoco&&) = default;
    CPoco& operator=(CPoco&&) = default;

    static CPoco CriarParaModulo01(std::string Nome, double Profund, double PressaoSup, double D , double OD, double ID, double q);
    static CPoco CriarParaModulo02(std::string Nome, double Profund, double PressaoSup, double TempTopoInicial, double TempFundoInicial, double TempTopoFinal, double TempFundoFinal, double profundidadePacker);

    // Getters
    std::string NomePoco() const { return nomePoco; }
    double ProfundidadeTotal() const { return profundidadeFinal; }
    double ProfundidadeOcupada() const { return profundidadeOcupada; }
    double PressaoSuperficie() const { return pressaoSuperficie; }
    double DiametroPoco() const { return diametroPoco; }
    double DiametroRevestimentoOD() const { return diametroRevestimentoOD; }
    double DiametroRevestimentoID() const { return diametroRevestimentoID; }
    double Vazao() const { return vazao; }

    double TemperaturaTopoInicial() const { return temperaturaTopoInicial; }
    double TemperaturaFundoInicial() const { return temperaturaFundoInicial; }
    double TemperaturaTopoFinal() const { return temperaturaTopoFinal; }
    double TemperaturaFundoFinal() const { return temperaturaFundoFinal; }
    double ProfundidadePacker() const { return profundidadePacker; }

    std::vector<CTrechoPoco*> Trechos() const;
    
    // Setters
    void NomePoco( std::string Nome ) { nomePoco = Nome; }
    void ProfundidadeTotal( double Profund ) { profundidadeFinal = Profund; }
    void ProfundidadeOcupada( double Profund ) { profundidadeOcupada = Profund; }
    void PressaoSuperficie( double PressaoSup ) { pressaoSuperficie = PressaoSup; }
    void DiametroPoco( double D ) { diametroPoco = D; }
    void DiametroRevestimentoOD( double OD ) { diametroRevestimentoOD = OD; }
    void DiametroRevestimentoID( double ID ) { diametroRevestimentoID = ID; }
    void Vazao( double q ) { vazao = q; }

    void TemperaturaTopoInicial(double temperatura) { temperaturaTopoInicial = temperatura; }
    void TemperaturaFundoInicial(double temperatura) { temperaturaFundoInicial = temperatura; }
    void TemperaturaTopoFinal(double temperatura) { temperaturaTopoFinal = temperatura; }
    void TemperaturaFundoFinal(double temperatura) { temperaturaFundoFinal = temperatura; }
    void ProfundidadePacker(double profundidade) { profundidadePacker = profundidade; }

    // Metodos
    bool AdicionarTrechoPoco(std::unique_ptr<CTrechoPoco> TrechoPoco);
    double PressaoHidroestaticaTotal() const;
    double PressaoHidroestaticaNoPonto(double profundidade) const;
    double DensidadeEfetivaTotal() const;
    double ViscosidadeEfetivaTotal() const;
    bool VerificarPreenchimentoColuna();
    std::pair<std::vector<double>, std::vector<double>> PlotarProfundidadePorPressao();
    std::pair<std::vector<double>, std::vector<double>> PlotarProfundidadePorPressaoMedia();
    void RemoverTrechoPoco(const std::string& nomeFluido);

    double CargaInicial(double profundidade) const;
    double DeltaLTemperaturaTotal() const;
    double DeltaLEfeitoBalao(double profundidade) const;
    double VariacaoCargaEfeitoPistao(double profundidade) const;
    double DeltaLPistaoPacker(double profundidade) const;
    double DeltaLPistaoCrossover(double profundidade) const;
    double DeltaLForcaRestauradora(double profundidade) const;
    double CargaInjecao(double profundidade, bool colunaFixa) const;

    double TemperaturaNoPonto(double profundidade) const;

};

#endif
