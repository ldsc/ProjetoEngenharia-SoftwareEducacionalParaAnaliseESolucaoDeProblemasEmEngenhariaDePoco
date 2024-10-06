#ifndef CPOCO_H
#define CPOCO_H

#include <vector>
#include <memory>
#include "CFluido.h"
#include "CTrechoPoco.h"

class CPoco {
protected:
    double ProfundidadeTotal;
    double ProfundidadeOcupada = 0;
    double PressaoSuperficie;
    double Diametro;
    double Vazao;
    std::vector<CTrechoPoco*> Trechos;

public:
    //construtor
    CPoco();
    CPoco(double Profund, double PressaoSup, double D = 1, double q = 1);

    // Getters
    double GetProfundidadeTotal() const { return ProfundidadeTotal; }
    double GetProfundidadeOcupada() const { return ProfundidadeOcupada; }
    double GetPressaoSuperficie() const { return PressaoSuperficie; }
    double GetDiametro() const { return Diametro; }
    double GetVazao() const { return Vazao; }

    // Setters
    void SetProfundidadeTotal( double Profund ) { ProfundidadeTotal = Profund; }
    void SetProfundidadeOcupada( double Profund ) { ProfundidadeOcupada = Profund; }
    void SetPressaoSuperficie( double PressaoSup ) { PressaoSuperficie = PressaoSup; }
    void SetDiametro( double D ) { Diametro = D; }
    void SetVazao( double q ) { Vazao = q; }

    // Metodos
    bool AdicionarTrechoPoco(CTrechoPoco& TrechoPoco);
    void ExibeTrechos() const;
    double PressaoHidroestaticaTotal() const;
    double DensidadeEfetivaTotal() const;
    double ViscosidadeEfetivaTotal() const;
    void VerificarPreenchimentoColuna();
    void PlotarProfundidadePorDensidade();

};

#endif
