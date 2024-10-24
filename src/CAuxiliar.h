#ifndef CAUXILIAR_H
#define CAUXILIAR_H

#include <iostream>
#include <iomanip>

class CAuxiliar {
    
    public:
    void limparTela();
    void desenharBorda();
    void desenharLinhaTexto(const std::string& texto);
    void desenharAviso(const std::string& aviso);
    void cabecalho();
};

#endif
