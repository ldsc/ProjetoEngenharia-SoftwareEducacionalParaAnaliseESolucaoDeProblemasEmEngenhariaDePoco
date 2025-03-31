#ifndef CPOCO_H
#define CPOCO_H

#include <vector>
#include <memory>
#include "CFluido.h"
#include "CTrechoPoco.h"

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
    double temperaturaTopoInicial;
    double temperaturaFundoInicial;
    double temperaturaTopoFnicial;
    double tempperaturaFundoFinal;



public:
    //construtor
    CPoco() {}
    ~CPoco() {}
    
    CPoco(std::string Nome, double Profund, double PressaoSup, double D , double OD, double ID, double q)
    : nomePoco(Nome),profundidadeFinal(Profund), pressaoSuperficie(PressaoSup), diametroPoco(D), diametroRevestimentoOD(OD), diametroRevestimentoID(ID), vazao(q) {} // Esse construtor nos leva os atributos que ira rodar na simulacao do Modulo 01

    // Getters
    std::string NomePoco() const { return nomePoco; }
    double ProfundidadeTotal() const { return profundidadeFinal; }
    double ProfundidadeOcupada() const { return profundidadeOcupada; }
    double PressaoSuperficie() const { return pressaoSuperficie; }
    double DiametroPoco() const { return diametroPoco; }
    double DiametroRevestimentoOD() const { return diametroRevestimentoOD; }
    double DiametroRevestimentoID() const { return diametroRevestimentoID; }
    double Vazao() const { return vazao; }
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

    // Metodos
    bool AdicionarTrechoPoco(std::unique_ptr<CTrechoPoco> TrechoPoco);
    double PressaoHidroestaticaTotal() const;
    double PressaoHidroestaticaNoPonto(double profundidade) const;
    double DensidadeEfetivaTotal() const;
    double ViscosidadeEfetivaTotal() const;
    bool VerificarPreenchimentoColuna();
    void PlotarProfundidadePorDensidade();
    void RemoverTrechoPoco(const std::string& nomeFluido);

};

#endif
