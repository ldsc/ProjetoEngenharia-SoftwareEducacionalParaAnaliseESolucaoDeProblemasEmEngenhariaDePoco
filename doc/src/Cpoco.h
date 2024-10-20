#ifndef CPOCO_H
#define CPOCO_H

#include <vector>
#include <memory>
#include "CFluido.h"
#include "CTrechoPoco.h"

class CPoco {
protected:
    double profundidadeFinal;
    double profundidadeOcupada = 0;
    double pressaoSuperficie;
    double diametroPoco;
    double diametroRevestimentoOD;
    double diametroRevestimentoID;
    double vazao;
    std::vector<std::unique_ptr<CTrechoPoco>> trechos;

public:
    //construtor
    CPoco() {}
    ~CPoco() {}
    CPoco(double Profund, double PressaoSup, double D = 1, double OD= 1, double ID= 1, double q = 1)
    : profundidadeFinal(Profund), pressaoSuperficie(PressaoSup), diametroPoco(D), diametroRevestimentoOD(OD), diametroRevestimentoID(ID), vazao(q) {}

    // Getters
    double ProfundidadeTotal() const { return profundidadeFinal; }
    double ProfundidadeOcupada() const { return profundidadeOcupada; }
    double PressaoSuperficie() const { return pressaoSuperficie; }
    double DiametroPoco() const { return diametroPoco; }
    double DiametroRevestimentoOD() const { return diametroRevestimentoOD; }
    double DiametroRevestimentoID() const { return diametroRevestimentoID; }
    double Vazao() const { return vazao; }
    std::vector<CTrechoPoco*> Trechos() const;
    
    // Setters
    void ProfundidadeTotal( double Profund ) { profundidadeFinal = Profund; }
    void ProfundidadeOcupada( double Profund ) { profundidadeOcupada = Profund; }
    void PressaoSuperficie( double PressaoSup ) { pressaoSuperficie = PressaoSup; }
    void DiametroPoco( double D ) { diametroPoco = D; }
    void DiametroRevestimentoOD( double OD ) { diametroRevestimentoOD = OD; }
    void DiametroRevestimentoID( double ID ) { diametroRevestimentoID = ID; }
    void Vazao( double q ) { vazao = q; }

    // Metodos
    bool AdicionarTrechoPoco(std::unique_ptr<CTrechoPoco> TrechoPoco);
    void ExibeTrechos() const;
    void ExibePropriedades() const;
    double PressaoHidroestaticaTotal() const;
    double DensidadeEfetivaTotal() const;
    double ViscosidadeEfetivaTotal() const;
    void VerificarPreenchimentoColuna();
    void PlotarProfundidadePorDensidade();

};

#endif
