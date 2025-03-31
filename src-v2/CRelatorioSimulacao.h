#ifndef CRELATORIOSIMULACAO_H
#define CRELATORIOSIMULACAO_H

#include <string>
#include "CObjetoPoco.h"

class CRelatorioPoco {
protected:

public:
    // Construtor
    CRelatorioPoco() {}
    ~CRelatorioPoco() {}

    // Metodos
    void ArmazenarValor(std::string nomePoco, std::string texto, double valor, std::string unidade);
    void ArmazenarValor(std::string nomePoco, std::string texto, double valor);
    void criarArquivoDAT(const std::string& nomePoco, const std::unique_ptr<CPoco>& poco);
    
};

#endif
