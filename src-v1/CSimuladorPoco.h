#ifndef CSIMULADORPOCO_H
#define CSIMULADORPOCO_H

#include "CPoco.h"
#include "CTrechoPoco.h"
#include "CModeloNewtoniano.h"
#include "CModeloBingham.h"
#include "CModeloPotencia.h"
#include "CAuxiliar.h"
#include "CRelatorioPoco.h"
#include "CInputUsuario.h"
#include <memory>
#include <vector>

class CSimuladorPoco {
protected:
    std::unique_ptr<CPoco> poco;
    std::unique_ptr<CTrechoPoco> trechoPoco;
    std::unique_ptr<CFluido> fluido;
    std::unique_ptr<CModeloNewtoniano> modeloNewtoniano;
    std::unique_ptr<CModeloBingham> modeloBingham;
    std::unique_ptr<CModeloPotencia> modeloPotencia;
    std::unique_ptr<CAuxiliar> auxiliar;
    std::unique_ptr<CRelatorioPoco> relatorioPoco;
    std::unique_ptr<CInputUsuario> inputUsuario;

    bool armazenarPropriedadesPoco = true;
    bool armazenarHistoricoPressaoHidrostatica = true;
    bool armazenarHistoricoPerdaCarga = true;


public:
    // Construtor e destrutor
    CSimuladorPoco() {}
    ~CSimuladorPoco() {}

    // Menus principais
    void MenuPrincipal();
    void MenuConfigurarSimulador();
    void MenuPressaoHidrostatica();
    void MenuPerdaDeCarga();
    void MenuModeloNewtoniano();
    void MenuModeloBingham();
    void MenuModeloPotencia();
    void MenuPreferencias();
    

    // Metodos auxiliares para configurar o poco e fluidos
    void ConfigurarPoco();
    void ConfigurarFluido();
    void ConfigurarPorArquivo(const std::string& arquivo);

    // Metodos de simulacao
    void ExibirPropriedades();

};

#endif // CSIMULADORPOCO_H