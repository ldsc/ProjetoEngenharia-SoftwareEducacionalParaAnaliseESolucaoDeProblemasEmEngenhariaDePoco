#ifndef CSIMULADORPOCO_H
#define CSIMULADORPOCO_H

#include "CPoco.h"
#include "CTrechoPoco.h"
#include "CModeloNewtoniano.h"
#include <memory>
#include <vector>

class CSimuladorPoco {
protected:
    std::unique_ptr<CPoco> poco;
    std::unique_ptr<CTrechoPoco> trechoPoco;
    std::unique_ptr<CFluido> fluido;
    std::unique_ptr<CModeloNewtoniano> modeloNewtoniano;

public:
    // Construtor e destrutor
    CSimuladorPoco() {}
    ~CSimuladorPoco() {}

    // Menus principais
    void menuPerdaDeCarga();
    void menuPrincipal();
    void menuConfigurarSimulador();

    // Métodos auxiliares para configurar o poço e fluidos
    void configurarPoco();
    void configurarFluido();
    void configurarPorArquivo(const std::string& arquivo);
    void definirModeloReologico();

    // Métodos de simulação
    void simularPerdaDeCarga();
    void simularPressaoHidrostatica();
    void exibirPropriedades();

};

#endif // CSIMULADORPOCO_H
