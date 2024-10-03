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
    std::vector<CTrechoPoco*> Trechos;

public:
    //construtor
    CPoco();
    CPoco(double Profund, double PressaoSup);

    // Getters
    double GetProfundidadeTotal() const { return ProfundidadeTotal; }
    double GetProfundidadeOcupada() const { return ProfundidadeOcupada; }
    double GetPressaoSuperficie() const { return PressaoSuperficie; }

    // Setters
    void SetProfundidadeTotal( double Profund ) { ProfundidadeTotal = Profund; }
    void SetProfundidadeOcupada( double Profund ) { ProfundidadeOcupada = Profund; }
    void SetPressaoSuperficie( double PressaoSup ) { PressaoSuperficie = PressaoSup; }

    // Metodos
    bool AdicionarTrechoPoco(CTrechoPoco& TrechoPoco);
    void ExibeTrechos() const;
    double PressaoHidroestaticaTotal() const;
    double DensidadeEfetivaTotal() const;
    void VerificarPreenchimentoColuna();
    void PlotarProfundidadePorDensidade();

};

#endif
