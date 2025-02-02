#ifndef CMODELONEWTONIANO_H
#define CMODELONEWTONIANO_H

#include "CModeloReologico.h"

#include <iostream>
#include <fstream>
#include <QApplication>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>

class CModeloNewtoniano : public CModeloReologico {

public:
    //Construtor
    CModeloNewtoniano() {}
    ~CModeloNewtoniano() {}
    CModeloNewtoniano(CPoco* poco) : CModeloReologico(poco){
        DeterminarFluxoPoco();
        DeterminarFluxoAnular();
    }

    //Metodos
    std::string DeterminarFluxoPoco() override;
    std::string DeterminarFluxoAnular() override;
    double CalcularPerdaPorFriccaoPoco() override;
    double CalcularPerdaPorFriccaoAnular() override;

};

#endif
