#ifndef CSIMULADORPOCO_H
#define CSIMULADORPOCO_H

#include "CPoco.h"
#include "CTrechoPoco.h"
#include "CModeloNewtoniano.h"
#include "CModeloBingham.h"
#include "CModeloPotencia.h"
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


public:
    // Construtor e destrutor
    CSimuladorPoco() {}
    ~CSimuladorPoco() {}

    // Menus principais
    void menuPrincipal();
    void menuConfigurarSimulador();
    void menuPressaoHidrostatica();
    void menuPerdaDeCarga();
    void menuModeloNewtoniano();
    void menuModeloBingham();
    void menuModeloPotencia();
    

    // Métodos auxiliares para configurar o poço e fluidos
    void configurarPoco();
    void configurarFluido();
    void configurarPorArquivo(const std::string& arquivo);
    void definirModeloReologico();
    void imprimirResultados();

    // Métodos de simulação
    void simularPerdaDeCarga();
    void simularPressaoHidrostatica();
    void exibirPropriedades();

};

#endif // CSIMULADORPOCO_H