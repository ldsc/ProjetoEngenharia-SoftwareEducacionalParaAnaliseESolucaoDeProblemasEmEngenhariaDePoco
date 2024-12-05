#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <vector>
#include <fstream>
#include <sstream>
#include "CAuxiliar.h"
#include "CSimuladorPoco.h"

auto auxiliar = std::make_unique<CAuxiliar>();

void CSimuladorPoco::ExibirPropriedades() {
        // Exibir propriedades do poço
            std::cout << "\nPropriedades do Poco:" << std::endl;
            std::cout << std::setw(30) << "Profundidade Total:" 
                    << std::setw(15) << poco->ProfundidadeTotal() << " ft" << std::endl;

            std::cout << std::setw(30) << "Profundidade Ocupada:" 
                    << std::setw(15) << poco->ProfundidadeOcupada() << " ft" << std::endl;

            std::cout << std::setw(30) << "Pressão Superficie:" 
                    << std::setw(15) << poco->PressaoSuperficie() << " psi" << std::endl;

            std::cout << std::setw(30) << "Diametro Poco:" 
                    << std::setw(15) << poco->DiametroPoco() << " in" << std::endl;

            std::cout << std::setw(30) << "Diametro Revestimento OD:" 
                    << std::setw(15) << poco->DiametroRevestimentoOD() << " in" << std::endl;

            std::cout << std::setw(30) << "Diametro Revestimento ID:" 
                    << std::setw(15) << poco->DiametroRevestimentoID() << " in" << std::endl;

            std::cout << std::setw(30) << "Vazao:" 
                    << std::setw(15) << poco->Vazao() << " gal/min" << std::endl;

            std::cout << std::setw(30) << "Densidade Media:" 
                    << std::setw(15) << poco->DensidadeEfetivaTotal() << " lb/ga" << std::endl;

            std::cout << std::setw(30) << "Viscosidade Media:" 
                    << std::setw(15) << poco->ViscosidadeEfetivaTotal() << " cP" << std::endl;

            // Cabeçalho da tabela
            std::cout << std::setw(20) << "Nome do Fluido" 
                    << std::setw(20) << "Densidade (lb/gal)" 
                    << std::setw(20) << "Viscosidade (cP)" 
                    << std::setw(20) << "Prof. Inicial (ft)" 
                    << std::setw(20) << "Prof. Final (ft)" << std::endl;

            // Linha de separação
            std::cout << std::string(100, '-') << std::endl;

            // Exibir dados dos fluidos
            for (const auto& trecho : poco->Trechos()) {
                std::cout << std::setw(20) << trecho->Fluido()->Nome()
                        << std::setw(20) << trecho->Fluido()->Densidade()
                        << std::setw(20) << trecho->Fluido()->Viscosidade()
                        << std::setw(20) << trecho->ProfundidadeInicial()
                        << std::setw(20) << trecho->ProfundidadeFinal() << std::endl;
            }
}

void CSimuladorPoco::ConfigurarPoco() {
    double profundidade, pressaoSuperficie, diametro, OD, ID, vazao;

    std::cout << "\nInforme a profundidade total do poco [ft]: ";
    std::cin >> profundidade;

    std::cout << "Informe a pressao na superficie do poco [psia]: ";
    std::cin >> pressaoSuperficie;

    std::cout << "Informe o diametro do poco [in]: ";
    std::cin >> diametro;

    std::cout << "Informe o OD do poco [in]: ";
    std::cin >> OD;

    std::cout << "Informe o ID do poco [in]: ";
    std::cin >> ID;

    std::cout << "Informe a vazao do poco [gal/min]: ";
    std::cin >> vazao;

    // Cria um novo objeto CPoco
    poco = std::make_unique<CPoco>(profundidade, pressaoSuperficie, diametro, OD, ID, vazao);
}

void CSimuladorPoco::ConfigurarFluido() {
    std::vector<std::unique_ptr<CTrechoPoco>> trechos; // Vetor para armazenar os trechos
                char continuar;

                do {
                    std::string nome;
                    double densidade, viscosidade, profInicial, profFinal;

                    std::cout << "\nInforme um nome para o fluido: ";
                    std::cin >> nome;

                    std::cout << "Informe a densidade do fluido: ";
                    std::cin >> densidade;

                    std::cout << "Informe a viscosidade do fluido: ";
                    std::cin >> viscosidade;

                    std::cout << "Informe a profundidade inicial do fluido: ";
                    std::cin >> profInicial;

                    std::cout << "Informe a profundidade final do fluido: ";
                    std::cin >> profFinal;

                    // Cria um novo objeto CFluido e CTrechoPoco
                    auto fluido = std::make_unique<CFluido>(nome, densidade, viscosidade);
                    auto trechoPoco = std::make_unique<CTrechoPoco>(profInicial, profFinal, std::move(fluido));

                    // Armazena o trecho no vetor
                    trechos.push_back(std::move(trechoPoco));

                    std::cout << "Deseja adicionar outro fluido? (s/n): ";
                    std::cin >> continuar;

                } while (continuar == 's' || continuar == 'S'); // Continua enquanto o usuário quiser

                // Adiciona todos os trechos ao poço
                for (auto& trecho : trechos) {
                    poco->AdicionarTrechoPoco(std::move(trecho));
                }
}

void CSimuladorPoco::ConfigurarPorArquivo(const std::string& arquivo) {
    std::ifstream file(arquivo);
    
    if (!file) {
        std::cerr << "Erro ao abrir o arquivo: " << arquivo << std::endl;
        return;
    }

    std::string linha;
    bool lendoFluidos = false; // Começa lendo dados do poço

    while (std::getline(file, linha)) {
        // Ignorar linhas vazias ou comentários
        if (linha.empty() || linha[0] == '#') {
            if (linha.find("Fluidos") != std::string::npos) {
                lendoFluidos = true; // Mudar para leitura de fluidos
            }
            continue;
        }

        if (!lendoFluidos) {
            // Ler os dados do poço
            std::istringstream iss(linha);
            double profundidade, pressaoSuperficie, diametro, OD, ID, vazao;

            if (iss >> profundidade >> pressaoSuperficie >> diametro >> OD >> ID >> vazao) {
                poco = std::make_unique<CPoco>(profundidade, pressaoSuperficie, diametro, OD, ID, vazao);
                std::cout << "Poco configurado a partir do arquivo " << arquivo << " com sucesso!" << std::endl;
            } else {
                std::cerr << "Erro ao ler dados do poço na linha: " << linha << std::endl;
            }
        } else {
            // Ler os dados dos fluidos
            std::istringstream iss(linha);
            std::string nome;
            double densidade, viscosidade, profInicial, profFinal;

            if (iss >> nome >> densidade >> viscosidade >> profInicial >> profFinal) {
                auto fluido = std::make_unique<CFluido>(nome, densidade, viscosidade);
                auto trechoPoco = std::make_unique<CTrechoPoco>(profInicial, profFinal, std::move(fluido));
                if (!poco->AdicionarTrechoPoco(std::move(trechoPoco))) {
                    std::cerr << "Erro ao adicionar trecho ao poço!" << std::endl;
                }
            } else {
                std::cerr << "Erro ao ler linha de fluido: " << linha << std::endl;
            }
        }
    }

    file.close();
}
// Função para o menu principal
void CSimuladorPoco::MenuPrincipal() {
    while (true) {
        int escolha;

        auxiliar->limparTela();
        auxiliar->desenharBorda();
        auxiliar->desenharLinhaTexto("   Menu Principal   ");
        auxiliar->desenharBorda();

        bool pocoConfigurado = (poco != nullptr);

        std::cout << "\n1. Configurar Poco\n"
                  << (pocoConfigurado ? "2. Exibir Propriedades do Poco\n"
                                      : "2. [X] Exibir Propriedades do Poco\n")
                  << (pocoConfigurado ? "3. Calcular Pressao Hidrostatica do Poco\n"
                                      : "3. [X] Calcular Pressao Hidrostatica do Poco\n")
                  << (pocoConfigurado ? "4. Plotar Perfil Profundidade vs Densidade\n"
                                      : "4. [X] Plotar Perfil Profundidade vs Densidade\n")
                  << (pocoConfigurado ? "5. Calcular Perda de Carga por Friccao\n"
                                      : "5. [X] Calcular Perda de Carga por Friccao\n")
                  << "0. Sair\n\n";

        if (!pocoConfigurado)
            std::cout << "Nenhum poco configurado. Por favor, configure um poco antes de prosseguir.\n";

        std::cout << "Escolha: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                MenuConfigurarSimulador();
                break;

            case 0:
                std::cout << "Saindo...\n";
                return;

            default:
                if (!pocoConfigurado) {
                    std::cout << "Opcao invalida ou indisponível! Configure o poço primeiro.\n";
                } else {
                    switch (escolha) {
                        case 2:
                            ExibirPropriedades();
                            break;

                        case 3:
                            MenuPressaoHidrostatica();
                            break;

                        case 4:
                            poco->PlotarProfundidadePorDensidade();
                            break;

                        case 5:
                            MenuPerdaDeCarga();
                            break;

                        default:
                            std::cout << "Opcao invalida! Tente novamente.\n";
                            break;
                    }
                }
        }
        std::cout << "\nPressione Enter para continuar...";
        std::cin.ignore().get();
    }
}

void CSimuladorPoco::MenuConfigurarSimulador() {
    int escolha;

    while (true) {
        auxiliar->limparTela();
        auxiliar->desenharBorda();
        auxiliar->desenharLinhaTexto("Configurar Poco");
        auxiliar->desenharBorda();

        std::cout << "\n1. Criar Poco\n"
                     "2. Adicionar Fluido\n"
                     "3. Carregar Dados a Partir de Arquivo (.dat)\n"
                     "0. Voltar\n";
        std::cout << "Escolha: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1: {
                ConfigurarPoco();
                break;
            }

            case 2: {
                auxiliar->desenharAviso("Voce pode adicionar multiplos fluidos");
                ConfigurarFluido();
                break;

            case 3:
                ConfigurarPorArquivo("ArquivoPoco.dat");
                break;
            }
            case 0:
                return; // Volta ao menu principal
            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
                break;
        }

        std::cout << "\nPressione Enter para continuar...";
        std::cin.ignore().get(); // Pausa até pressionar Enter
    }
}

void CSimuladorPoco::MenuPressaoHidrostatica() {
    int escolha;
    double profundidade;

    while (true) {
        auxiliar->limparTela();
        auxiliar->desenharBorda();
        auxiliar->desenharLinhaTexto("Menu de Pressao Hidrostatica");
        auxiliar->desenharBorda();

        std::cout << "\n1. Calcular Pressao Hidroestatica (Fundo de poco)\n"
                     "2. Calcular Pressao Hidroestatica em um Ponto do Poco\n"
                     "0. Voltar\n";
        std::cout << "Escolha: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                std::cout << "\nPressao Hidrostatica Total: " << poco->PressaoHidroestaticaTotal() << " psi\n";
                break;
                
            case 2:

                std::cout << "\nInforme a profundidade que deseja calcular [ft]: ";
                std::cin >> profundidade;

                std::cout << "\nPressao Hidrostatica: " << poco->PressaoHidroestaticaNoPonto(profundidade) << " psi\n";
                break;
            case 0:
                return; // Volta ao menu principal
            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
                break;
        }

        std::cout << "\nPressione Enter para continuar...";
        std::cin.ignore().get(); // Pausa até pressionar Enter
    }
}

void CSimuladorPoco::MenuPerdaDeCarga() {
    int escolha;

    while (true) {
        auxiliar->limparTela();
        auxiliar->desenharBorda();
        auxiliar->desenharLinhaTexto("Menu de Perda de Carga");
        auxiliar->desenharBorda();

        std::cout << "\n1. Modelo Newtoniano\n"
                     "2. Modelo Bingham\n"
                     "3. Modelo de Potencia\n"
                     "0. Voltar\n";
        std::cout << "Escolha: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                MenuModeloNewtoniano();
                break;
                
            case 2:
                MenuModeloBingham();
                break;
            case 3:
                MenuModeloPotencia();
                break;
            case 0:
                return; // Volta ao menu principal
            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
                break;
        }

        std::cout << "\nPressione Enter para continuar...";
        std::cin.ignore().get(); // Pausa até pressionar Enter
    }
}

void CSimuladorPoco::MenuModeloNewtoniano() {
    int escolha;

    while (true) {
        auxiliar->limparTela();
        auxiliar->desenharBorda();
        auxiliar->desenharLinhaTexto("Menu de Perda de Carga - Newtoniano");
        auxiliar->desenharBorda();

        std::cout << "\n1. Determinar Perda de Carga no Poco\n"
                     "2. Determinar Perda de Carga no Anular\n"
                     "0. Voltar\n";
        std::cout << "Escolha: ";
        std::cin >> escolha;

        modeloNewtoniano = std::make_unique<CModeloNewtoniano>(poco.get());

        switch (escolha) {
            case 1:
                std::cout << "\nVelocidade no Poco: " << modeloNewtoniano->VMediaPoco() << " ft/s"
                          << "\nReynolds no Poco: " << modeloNewtoniano->ReynoldsPoco()
                          << "\nTipo de Fluxo no Poco: " << modeloNewtoniano->DeterminarFluxoPoco() 
                          << "\nPerda Friccional no Poco: " << modeloNewtoniano->CalcularPerdaPorFriccaoPoco() << " psi/ft\n";

                if (modeloNewtoniano->FluxoPoco() == "Turbulento") {
                    std::cout << "\nFator de Friccao no Poco: " << modeloNewtoniano->FatorFriccaoPoco() << "\n"; 
                }
                break;
            case 2:
                std::cout << "\nVelocidade no anular: " << modeloNewtoniano->VMediaAnular() << " ft/s"
                          << "\nReynolds no anular: " << modeloNewtoniano->ReynoldsAnular()
                          << "\nTipo de Fluxo no anular: " << modeloNewtoniano->DeterminarFluxoAnular() 
                          << "\nPerda Friccional no Anular: " << modeloNewtoniano->CalcularPerdaPorFriccaoAnular() << " psi/ft\n";

                if (modeloNewtoniano->FluxoAnular() == "Turbulento") {
                    std::cout << "\nFator de Friccao no Anular: " << modeloNewtoniano->FatorFriccaoAnular() << "\n";
                }
                break;
            case 0:
                return; // Volta ao menu principal
            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
                break;
        }

        std::cout << "\nPressione Enter para continuar...";
        std::cin.ignore().get(); // Pausa até pressionar Enter
    }
}

void CSimuladorPoco::MenuModeloBingham() {
    int escolha;

    while (true) {
        double pontoDeEscoamento, viscosidadePlastica;

        auxiliar->limparTela();
        auxiliar->desenharBorda();
        auxiliar->desenharLinhaTexto("Menu de Perda de Carga - Bingham");
        auxiliar->desenharBorda();

        std::cout << "\n1. Determinar Perda de Carga no Poco\n"
                     "2. Determinar Perda de Carga no Anular\n"
                     "0. Voltar\n";
        std::cout << "Escolha: ";
        std::cin >> escolha;

        modeloBingham = std::make_unique<CModeloBingham>(poco.get());

        switch (escolha) {
            case 1:
                std::cout << "\nInforme o valor do pontoDeEscoamento [lbf/100 sq.ft]: ";
                std::cin >> pontoDeEscoamento;
                modeloBingham->PontoDeEscoamento(pontoDeEscoamento);

                std::cout << "Informe o valor da viscosidade Plastica [cP]: ";
                std::cin >> viscosidadePlastica;
                modeloBingham->ViscosidadePlastica(viscosidadePlastica);

                std::cout << "\nVelocidade no Poco: " << modeloBingham->VMediaPoco() << " ft/s"
                          << "\nReynolds no Poco: " << modeloBingham->ReynoldsPoco()
                          << "\nReynolds Hedstrom no Poco: " << modeloBingham->ReynoldsHedstronPoco()
                          << "\nReynolds Critico no Poco: " << modeloBingham->ReynoldsCriticoPoco()
                          << "\nTipo de Fluxo no Poco: " << modeloBingham->DeterminarFluxoPoco() 
                          << "\nPerda Friccional no Poco: " << modeloBingham->CalcularPerdaPorFriccaoPoco() << " psi/ft\n";

                if (modeloBingham->FluxoPoco() == "Turbulento") {
                    std::cout << "\nFator de Friccao: " << modeloBingham->FatorFriccaoPoco() << "\n"; 
                }
                break;
            case 2:
                std::cout << "\nInforme o valor do pontoDeEscoamento [lbf/100 sq.ft]: ";
                std::cin >> pontoDeEscoamento;
                modeloBingham->PontoDeEscoamento(pontoDeEscoamento);

                std::cout << "Informe o valor da viscosidade Plastica [cP]: ";
                std::cin >> viscosidadePlastica;
                modeloBingham->ViscosidadePlastica(viscosidadePlastica);

                std::cout << "\nVelocidade no anular: " << modeloBingham->VMediaAnular() << " ft/s"
                          << "\nReynolds no anular: " << modeloBingham->ReynoldsAnular()
                          << "\nReynolds de Hedstrom no anular: " << modeloBingham->ReynoldsHedstronAnular()
                          << "\nReynolds Critico no anular: " << modeloBingham->ReynoldsCriticoAnular()
                          << "\nTipo de Fluxo no anular: " << modeloBingham->DeterminarFluxoAnular() 
                          << "\nPerda Friccional no Anular: " << modeloBingham->CalcularPerdaPorFriccaoAnular() << " psi/ft\n";

                if (modeloBingham->FluxoAnular() == "Turbulento") {
                    std::cout << "\nFator de Friccao: " << modeloBingham->FatorFriccaoAnular() << "\n";
                }
                         
                break;
            case 0:
                return; // Volta ao menu principal
            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
                break;
        }

        std::cout << "\nPressione Enter para continuar...";
        std::cin.ignore().get(); // Pausa até pressionar Enter
    }
}

void CSimuladorPoco::MenuModeloPotencia() {
    int escolha;

    while (true) {
        double indiceDeConsistencia;

        auxiliar->limparTela();
        auxiliar->desenharBorda();
        auxiliar->desenharLinhaTexto("Menu de Perda de Carga - Potencia");
        auxiliar->desenharBorda();

        std::cout << "\n1. Determinar Perda de Carga no Poco\n"
                     "2. Determinar Perda de Carga no Anular\n"
                     "0. Voltar\n";
        std::cout << "Escolha: ";
        std::cin >> escolha;

        modeloPotencia = std::make_unique<CModeloPotencia>(poco.get());

        switch (escolha) {
            case 1:
                std::cout << "\nInforme o valor do indice de consistencia [Cp eq]: ";
                std::cin >> indiceDeConsistencia;
                modeloPotencia->IndiceDeConsistencia(indiceDeConsistencia);

                std::cout << "\nVelocidade no Poco: " << modeloPotencia->VMediaPoco() << " ft/s"
                          << "\nReynolds no Poco: " << modeloPotencia->ReynoldsPoco()
                          << "\nReynolds Critico no Poco: " << modeloPotencia->ReynoldsCriticoPoco()
                          << "\nTipo de Fluxo no Poco: " << modeloPotencia->DeterminarFluxoPoco() 
                          << "\nPerda Friccional no Poco: " << modeloPotencia->CalcularPerdaPorFriccaoPoco() << " psi/ft\n";

                if (modeloPotencia->FluxoPoco() == "Turbulento") {
                    std::cout << "\nFator de Friccao: " << modeloPotencia->FatorFriccaoPoco() << "\n"; 
                }
                break;
            case 2:
                std::cout << "\nInforme o valor do indice de consistencia [Cp eq]: ";
                std::cin >> indiceDeConsistencia;
                modeloPotencia->IndiceDeConsistencia(indiceDeConsistencia);

                std::cout << "\nVelocidade no anular: " << modeloPotencia->VMediaAnular() << " ft/s"
                          << "\nReynolds no anular: " << modeloPotencia->ReynoldsAnular()
                          << "\nReynolds Critico no anular: " << modeloPotencia->ReynoldsCriticoAnular()
                          << "\nTipo de Fluxo no anular: " << modeloPotencia->DeterminarFluxoAnular() 
                          << "\nPerda Friccional no Anular: " << modeloPotencia->CalcularPerdaPorFriccaoAnular() << " psi/ft\n";

                if (modeloPotencia->FluxoAnular() == "Turbulento") {
                    std::cout << "\nFator de Friccao: " << modeloPotencia->FatorFriccaoAnular() << "\n";
                }
                break;
            case 0:
                return; // Volta ao menu principal
            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
                break;
        }

        std::cout << "\nPressione Enter para continuar...";
        std::cin.ignore().get(); // Pausa até pressionar Enter
    }
}