#ifndef CTRECHOTUBULACAO_H
#define CTRECHOTUBULACAO_H

#include "CFluido.h"
#include <memory>
#include <string>

// Essa classe representa um trecho da coluna do poço, contendo as informacoes geometricas
// e termomecanicas, alem do fluido presente nesse intervalo
class CTrechoPoco {
protected:
    std::string nome;
    double profundidadeInicial = 0.0;
    double profundidadeFinal = 0.0;
    std::unique_ptr<CFluido> fluido;

    // Parametros adicionais para simulacoes mecanicas (Modulo 02)
    double diametroExterno = 0.0;
    double diametroInterno = 0.0;
    double coeficientePoisson = 0.0;
    double moduloEslasticidade = 0.0;
    double pesoUnidade = 0.0;
    double coeficienteExpancaoTermica = 0.0;

public:
    // Construtor padrao (sem dados iniciais)
    CTrechoPoco() = default;

    // Destrutor padrao
    ~CTrechoPoco() = default;

    // Construtor para o Modulo 01 (fluido + profundidades)
    CTrechoPoco(double profundI, double profundF, std::unique_ptr<CFluido> fluidoPtr)
        : profundidadeInicial(profundI),
        profundidadeFinal(profundF),
        fluido(std::move(fluidoPtr)) {}

    // Construtor completo para o Modulo 02 (inclui dados mecanicos e nome do trecho)
    CTrechoPoco(std::string nomeTrecho,
                double profundI, double profundF,
                std::unique_ptr<CFluido> fluidoPtr,
                double diamExt, double diamInt,
                double coefPoisson, double moduloE,
                double pesoUnit, double coefExp)
        : nome(std::move(nomeTrecho)),
        profundidadeInicial(profundI),
        profundidadeFinal(profundF),
        fluido(std::move(fluidoPtr)),
        diametroExterno(diamExt),
        diametroInterno(diamInt),
        coeficientePoisson(coefPoisson),
        moduloEslasticidade(moduloE),
        pesoUnidade(pesoUnit),
        coeficienteExpancaoTermica(coefExp) {}

    // Getters
    std::string Nome() const { return nome; }
    double ProfundidadeInicial() const { return profundidadeInicial; }
    double ProfundidadeFinal() const { return profundidadeFinal; }
    double DiametroExterno() const { return diametroExterno; }
    double DiametroInterno() const { return diametroInterno; }
    double CoeficientePoisson() const { return coeficientePoisson; }
    double ModuloEslasticidade() const { return moduloEslasticidade; }
    double PesoUnidade() const { return pesoUnidade; }
    double CoeficienteExpancaoTermica() const { return coeficienteExpancaoTermica; }
    CFluido* Fluido() const { return fluido.get(); }

    // Setters
    void Nome(const std::string& novoNome) { nome = novoNome; }
    void ProfundidadeInicial(double profundI) { profundidadeInicial = profundI; }
    void ProfundidadeFinal(double profundF) { profundidadeFinal = profundF; }
    void DiametroExterno(double diam) { diametroExterno = diam; }
    void DiametroInterno(double diam) { diametroInterno = diam; }
    void CoeficientePoisson(double coef) { coeficientePoisson = coef; }
    void ModuloEslasticidade(double coef) { moduloEslasticidade = coef; }
    void PesoUnidade(double peso) { pesoUnidade = peso; }
    void CoeficienteExpancaoTermica(double coef) { coeficienteExpancaoTermica = coef; }


    // Metodos de calculo
    double PressaoHidroestatica();
    double PressaoHidroestatica(double profund);
    double DensidadeEquivalente();
};

#endif // CTRECHOTUBULACAO_H
