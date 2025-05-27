#ifndef COBJETOPOCO_H
#define COBJETOPOCO_H

#include <vector>
#include <memory>
#include "CTrechoTubulacao.h"

// Classe CObjetoPoco representa o objeto principal que armazena os dados do poço e permite a execução de cálculos e simulações

class CObjetoPoco {
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

    double pressaoSuperficieFim = 0.0;
    double temperaturaTopoInicial = 0.0;
    double temperaturaFundoInicial = 0.0;
    double temperaturaTopoFinal = 0.0;
    double temperaturaFundoFinal = 0.0;
    double profundidadePacker = 0.0;

public:
    // Construtor e destrutor padrão
     CObjetoPoco() = default;
    ~CObjetoPoco() = default;

    // Evita cópia (pra evitar duplicação desnecessária dos trechos)
    CObjetoPoco(const CObjetoPoco&) = delete;
    CObjetoPoco& operator=(const CObjetoPoco&) = delete;

    // Permite movimentação (move semantics)
    CObjetoPoco(CObjetoPoco&&) = default;
    CObjetoPoco& operator=(CObjetoPoco&&) = default;

    // Métodos de criação estáticos, separando claramente os dados exigidos por cada módulo
    static CObjetoPoco CriarParaModulo01(std::string Nome, double Profund, double PressaoSup, double D , double OD, double ID, double q);
    static CObjetoPoco CriarParaModulo02(std::string Nome, double Profund, double diamPoco, double PressaoSup, double PressaoSupFinal, double TempTopoInicial, double TempFundoInicial, double TempTopoFinal, double TempFundoFinal, double profundidadePacker);

    // Getters para acessar os atributos de forma segura
    std::string NomePoco() const { return nomePoco; }
    double ProfundidadeTotal() const { return profundidadeFinal; }
    double ProfundidadeOcupada() const { return profundidadeOcupada; }
    double PressaoSuperficie() const { return pressaoSuperficie; }
    double PressaoSuperficieFim() const { return pressaoSuperficieFim; }
    double DiametroPoco() const { return diametroPoco; }
    double DiametroRevestimentoOD() const { return diametroRevestimentoOD; }
    double DiametroRevestimentoID() const { return diametroRevestimentoID; }
    double Vazao() const { return vazao; }
    double TemperaturaTopoInicial() const { return temperaturaTopoInicial; }
    double TemperaturaFundoInicial() const { return temperaturaFundoInicial; }
    double TemperaturaTopoFinal() const { return temperaturaTopoFinal; }
    double TemperaturaFundoFinal() const { return temperaturaFundoFinal; }
    double ProfundidadePacker() const { return profundidadePacker; }

    // Retorna os trechos adicionados ao poço (em forma de ponteiros brutos)
    std::vector<CTrechoPoco*> Trechos() const;

    // Setters permitem modificar os atributos do poço
    void NomePoco(std::string Nome) { nomePoco = Nome; }
    void ProfundidadeTotal(double Profundidade) { profundidadeFinal = Profundidade; }
    void ProfundidadeOcupada(double Profundidade) { profundidadeOcupada = Profundidade; }
    void PressaoSuperficie(double PressaoSuperior) { pressaoSuperficie = PressaoSuperior; }
    void PressaoSuperficieFim(double PressaoSuperior) { pressaoSuperficieFim = PressaoSuperior; }
    void DiametroPoco(double D) { diametroPoco = D; }
    void DiametroRevestimentoOD(double DiametroExterno) { diametroRevestimentoOD = DiametroExterno; }
    void DiametroRevestimentoID(double DiametroInterno) { diametroRevestimentoID = DiametroInterno; }
    void Vazao(double q) { vazao = q; }
    void TemperaturaTopoInicial(double temperatura) { temperaturaTopoInicial = temperatura; }
    void TemperaturaFundoInicial(double temperatura) { temperaturaFundoInicial = temperatura; }
    void TemperaturaTopoFinal(double temperatura) { temperaturaTopoFinal = temperatura; }
    void TemperaturaFundoFinal(double temperatura) { temperaturaFundoFinal = temperatura; }
    void ProfundidadePacker(double profundidade) { profundidadePacker = profundidade; }


    // Métodos de cálculo
    double PressaoHidroestaticaTotal() const;
    double PressaoHidroestaticaNoPonto(double profundidade) const;
    double DensidadeEfetivaTotal() const;
    double ViscosidadeEfetivaTotal() const;
    bool VerificarPreenchimentoColuna();
    double Carga(double profundidade, bool inicio) const;
    double DeltaLTemperatura(double profundidade) const;
    double DeltaLEfeitoBalao(double profundidade) const;
    double VariacaoCargaDevidoCrossover(double profundidade, double pressaoCabecaPoco = -1) const;
    double VariacaoCargaEfeitoPistao(double profundidade, double ID, double OD) const;
    double DeltaLPistaoPacker(double profundidade, double CargaPistao) const;
    double DeltaLPistaoCrossover(double profundidade, double pressaoCabecaPoco) const;
    double DeltaLForcaRestauradora(double profundidade, double pressaoCabecaPoco) const;
    double CargaInjecao(double profundidade) const;
    double TemperaturaNoPonto(double profundidade, double T_topo, double T_Fundo) const;

    bool AdicionarTrechoPoco(std::unique_ptr<CTrechoPoco> trechoParaAdicionar); // Função para adicionar um novo trecho ao poço
    void RemoverFluidoPoco(const std::string& nomeFluido); // Remove trecho do poço com base no nome do fluido
    void RemoverTrechoPoco(const std::string& nomeTrecho);

    // Métodos que retornam dados para gráficos
    std::pair<std::vector<double>, std::vector<double>> PlotarProfundidadePorPressao();
    std::pair<std::vector<double>, std::vector<double>> PlotarProfundidadePorPressaoMedia();
};

#endif
