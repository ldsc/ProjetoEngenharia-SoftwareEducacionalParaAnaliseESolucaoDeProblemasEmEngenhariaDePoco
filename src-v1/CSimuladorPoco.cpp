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
auto inputUsuario = std::make_unique<CInputUsuario>();

void CSimuladorPoco::ExibirPropriedades() {
        // Exibir propriedades do poco
            std::cout << "\nPropriedades do Poco:" << std::endl;
            std::cout << std::setw(30) << "Nome Poco:"
                    << std::setw(15) << poco->NomePoco() << std::endl;

            std::cout << std::setw(30) << "Profundidade Total:" 
                    << std::setw(15) << poco->ProfundidadeTotal() << " ft" << std::endl;

            std::cout << std::setw(30) << "Profundidade Ocupada:" 
                    << std::setw(15) << poco->ProfundidadeOcupada() << " ft" << std::endl;

            std::cout << std::setw(30) << "Pressao Superficie:" 
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

            // Cabecalho da tabela
            std::cout << std::endl;
            std::cout << std::setw(20) << "Nome do Fluido" 
                    << std::setw(20) << "Densidade (lb/gal)" 
                    << std::setw(20) << "Viscosidade (cP)" 
                    << std::setw(20) << "Prof. Inicial (ft)" 
                    << std::setw(20) << "Prof. Final (ft)" << std::endl;

            // Linha de separacao
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
    bool pocoConfigurado = (poco != nullptr);

    if (!pocoConfigurado) {
        // Solicita todas as informações para configurar o poço pela primeira vez.
        std::string nomePoco = inputUsuario->getString("Informe o nome do poco: ");
        double profundidade = inputUsuario->getDouble("Informe a profundidade total do poco [ft]: ");
        double pressaoSuperficie = inputUsuario->getDouble("Informe a pressao na superficie do poco [psia]: ");
        double diametro = inputUsuario->getDouble("Informe o diametro do poco [in]: ");
        double OD = inputUsuario->getDouble("Informe o OD do revestimento [in]: ");
        double ID = inputUsuario->getDouble("Informe o ID do revestimento [in]: ");
        double vazao = inputUsuario->getDouble("Informe a vazao do poco [gal/min]: ");

        // Cria o poço com os valores fornecidos.
        poco = std::make_unique<CPoco>(nomePoco, profundidade, pressaoSuperficie, diametro, OD, ID, vazao);
    } else {
        // Pergunta se o usuário deseja atualizar os dados do poço existente.
        int atualizar = inputUsuario->getSimNao("Gostaria de atualizar os dados do poco, isso ira deletar os dados de fluidos existentes? (s|n): ");
        if (atualizar) {
            // Solicita as novas informações.
            double profundidade = inputUsuario->getDouble("Informe a profundidade total do poco [ft]: ");
            double pressaoSuperficie = inputUsuario->getDouble("Informe a pressao na superficie do poco [psia]: ");
            double diametro = inputUsuario->getDouble("Informe o diametro do poco [in]: ");
            double OD = inputUsuario->getDouble("Informe o OD do revestimento [in]: ");
            double ID = inputUsuario->getDouble("Informe o ID do revestimento [in]: ");
            double vazao = inputUsuario->getDouble("Informe a vazao do poco [gal/min]: ");

        // Cria o poço com os valores fornecidos.
            poco = std::make_unique<CPoco>(poco->NomePoco(), profundidade, pressaoSuperficie, diametro, OD, ID, vazao);   
        }
    }
}

void CSimuladorPoco::ConfigurarFluido() {
    std::vector<std::unique_ptr<CTrechoPoco>> trechos; // Vetor para armazenar os trechos
                char continuar;

                do {
                    std::string nome;
                    double densidade, viscosidade, profInicial, profFinal;

                    nome = inputUsuario->getString("Informe o nome do fluido: ");
                    densidade = inputUsuario->getDouble("Informe a densidade do fluido: ");
                    viscosidade = inputUsuario->getDouble("Informe a viscosidade do fluido: ");
                    profInicial = inputUsuario->getDouble("Informe a profundidade inicial do fluido: ");
                    profFinal = inputUsuario->getDouble("Informe a profundidade final do fluido: ");

                    // Cria um novo objeto CFluido e CTrechoPoco
                    auto fluido = std::make_unique<CFluido>(nome, densidade, viscosidade);
                    auto trechoPoco = std::make_unique<CTrechoPoco>(profInicial, profFinal, std::move(fluido));

                    // Armazena o trecho no vetor
                    trechos.push_back(std::move(trechoPoco));

                    continuar = inputUsuario->getSimNao("Deseja adicionar mais fluidos? (s|n): ");

                } while (continuar); // Continua enquanto o usuario quiser

                // Adiciona todos os trechos ao poco
                for (auto& trecho : trechos) {
                    poco->AdicionarTrechoPoco(std::move(trecho));
                }
}

void CSimuladorPoco::ConfigurarPorArquivo(const std::string& arquivo) {
    std::ifstream file(arquivo);
    
    if (!file) {
        std::cerr << "\n ### Erro ao abrir o arquivo: " << arquivo << std::endl;
        return;
    }

    std::string linha;
    bool lendoFluidos = false; // Comeca lendo dados do poco

    while (std::getline(file, linha)) {
        // Ignorar linhas vazias ou comentários
        if (linha.empty() || linha[0] == '#') {
            if (linha.find("Configuração dos Fluidos") != std::string::npos) {
                lendoFluidos = true; // Mudar para leitura de fluidos
            }
            continue;
        }

        if (!lendoFluidos) {
            // Ler os dados do poço
            std::istringstream iss(linha);
            std::string nome;
            double profundidade, pressaoSuperficie, diametro, OD, ID, vazao;

            // Verificando se os dados do poço estão na linha
            if (iss >> nome >> profundidade >> pressaoSuperficie >> diametro >> OD >> ID >> vazao) {
                poco = std::make_unique<CPoco>(nome, profundidade, pressaoSuperficie, diametro, OD, ID, vazao);
                std::cout << "\n ### Poco configurado a partir do arquivo " << arquivo << " com sucesso!" << std::endl;
            } else {
                std::cerr << "\n ### Erro ao ler dados do poço na linha: " << linha << std::endl;
            }
        } else {
            // Ler os dados dos fluidos
            std::istringstream iss(linha);
            std::string nome;
            double densidade, viscosidade, profInicial, profFinal;

            // Verificando se os dados do fluido estão na linha
            if (iss >> nome >> densidade >> viscosidade >> profInicial >> profFinal) {
                auto fluido = std::make_unique<CFluido>(nome, densidade, viscosidade);
                auto trechoPoco = std::make_unique<CTrechoPoco>(profInicial, profFinal, std::move(fluido));
                
                if (!poco->AdicionarTrechoPoco(std::move(trechoPoco))) {
                    std::cerr << "\n ### Erro ao adicionar trecho ao poço!" << std::endl;
                }
            } else {
                std::cerr << "\n ### Erro ao ler linha de fluido: " << linha << std::endl;
            }
        }
    }

    file.close();
}

// Funcao para o menu principal
void CSimuladorPoco::MenuPrincipal() {

    auxiliar->cabecalho();

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
                  << "6. Configurar preferencias de armazenamento\n"
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

            case 6:
                MenuPreferencias();
                break;

            default:
                if (!pocoConfigurado) {
                    std::cout << "Opcao invalida ou indisponivel! Configure o poco primeiro.\n";
                } else {
                    switch (escolha) {
                        case 2:
                            ExibirPropriedades();
                            std::cout << "\nPressione Enter para continuar...";
                            std::cin.ignore().get(); // Pausa ate pressionar Enter
                            break;

                        case 3:
                            MenuPressaoHidrostatica();
                            break;

                        case 4:
                            poco->PlotarProfundidadePorDensidade();
                            std::cout << "\nPressione Enter para continuar...";
                            std::cin.ignore().get(); // Pausa ate pressionar Enter
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
                     "2. Criar Fluido\n"
                     "3. Carregar Dados do Poco e Fluido a Partir de Arquivo (.dat)\n"
                     "0. Voltar\n";
        std::cout << "Escolha: ";
        std::cin >> escolha;

        auto RelatorioPoco = std::make_unique<CRelatorioPoco>();
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

                if (armazenarHistoricoPressaoHidrostatica == true || armazenarHistoricoPerdaCarga == true) {
                    relatorioPoco->criarArquivoDAT(poco->NomePoco(), poco);

                }

                std::cout << "\nPressione Enter para continuar...";
                std::cin.ignore().get(); // Pausa ate pressionar Enter
                break;
            }
            case 0:
                return; // Volta ao menu principal
            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
                
                break;
        }
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

        std::string texto;

        std::cout << "\n1. Calcular Pressao Hidroestatica (Fundo de poco)\n"
                     "2. Calcular Pressao Hidroestatica em um Ponto do Poco\n"
                     "0. Voltar\n";
        std::cout << "Escolha: ";
        std::cin >> escolha;

        switch (escolha) {

            case 1:
                std::cout << "\nPressao Hidrostatica Total: " << poco->PressaoHidroestaticaTotal() << " psi\n";

                texto = "O Valor da Pressao Hidrostatica: ";
                if (armazenarHistoricoPressaoHidrostatica == true) relatorioPoco->ArmazenarValor(poco->NomePoco(), texto, poco->PressaoHidroestaticaTotal(), " psi");    

                break;
                
            case 2:
                profundidade = inputUsuario->getDouble("Informe a profundidade que deseja calcular [ft]: ");

                std::cout << "\nPressao Hidrostatica: " << poco->PressaoHidroestaticaNoPonto(profundidade) << " psi\n";
                texto = "O Valor da Pressao Hidrostatica no ponto " + std::to_string(profundidade) + " ft: ";
                if (armazenarHistoricoPressaoHidrostatica == true) relatorioPoco->ArmazenarValor(poco->NomePoco(), texto, poco->PressaoHidroestaticaTotal(), " psi"); 
                
                break;
            case 0:
                return; // Volta ao menu principal
            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
                break;
        }

        std::cout << "\nPressione Enter para continuar...";
        std::cin.ignore().get(); // Pausa ate pressionar Enter
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
    }
}

void CSimuladorPoco::MenuModeloNewtoniano() {
    int escolha;
    std::string armazena;

    while (true) {
        auxiliar->limparTela();
        auxiliar->desenharBorda();
        auxiliar->desenharLinhaTexto("Menu de Perda de Carga - Newtoniano");
        auxiliar->desenharBorda();

        std::string texto;

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

                texto = "O Valor da Perda de Friccao no Poco para o Modelo Newtoniano: ";
                if (armazenarHistoricoPerdaCarga == true) relatorioPoco->ArmazenarValor(poco->NomePoco(),texto, modeloNewtoniano->FatorFriccaoPoco(), " psi/ft"); 
                
                break;
            case 2:
                std::cout << "\nVelocidade no anular: " << modeloNewtoniano->VMediaAnular() << " ft/s"
                          << "\nReynolds no anular: " << modeloNewtoniano->ReynoldsAnular()
                          << "\nTipo de Fluxo no anular: " << modeloNewtoniano->DeterminarFluxoAnular() 
                          << "\nPerda Friccional no Anular: " << modeloNewtoniano->CalcularPerdaPorFriccaoAnular() << " psi/ft\n";

                if (modeloNewtoniano->FluxoAnular() == "Turbulento") {
                    std::cout << "\nFator de Friccao no Anular: " << modeloNewtoniano->FatorFriccaoAnular() << "\n";
                }

                texto = "O Valor da Perda de Friccao no Anular para o Modelo Newtoniano: ";
                if (armazenarHistoricoPerdaCarga == true) relatorioPoco->ArmazenarValor(poco->NomePoco(),texto, modeloNewtoniano->FatorFriccaoAnular(), " psi/ft");
                
                break;
            case 0:
                return; // Volta ao menu principal
            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
                break;
        }

        std::cout << "\nPressione Enter para continuar...";
        std::cin.ignore().get(); // Pausa ate pressionar Enter
    }
}

void CSimuladorPoco::MenuModeloBingham() {
    int escolha;
    std::string armazena;

    while (true) {
        double pontoDeEscoamento, viscosidadePlastica;

        auxiliar->limparTela();
        auxiliar->desenharBorda();
        auxiliar->desenharLinhaTexto("Menu de Perda de Carga - Bingham");
        auxiliar->desenharBorda();

        std::string texto;

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

                texto = "O Valor da Perda de Friccao no Poco para o Modelo Bingham: ";
                if (armazenarHistoricoPerdaCarga == true) relatorioPoco->ArmazenarValor(poco->NomePoco(),texto, modeloBingham->FatorFriccaoPoco(), " psi/ft");

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

                texto = "O Valor da Perda de Friccao no Anular para o Modelo Bingham: ";
                if (armazenarHistoricoPerdaCarga == true) relatorioPoco->ArmazenarValor(poco->NomePoco(),texto, modeloBingham->FatorFriccaoAnular(), " psi/ft");

                break;
            case 0:
                return; // Volta ao menu principal
            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
                break;
        }

        std::cout << "\nPressione Enter para continuar...";
        std::cin.ignore().get(); // Pausa ate pressionar Enter
    }
}

void CSimuladorPoco::MenuModeloPotencia() {
    int escolha;
    std::string armazena;

    while (true) {
        double indiceDeConsistencia;

        auxiliar->limparTela();
        auxiliar->desenharBorda();
        auxiliar->desenharLinhaTexto("Menu de Perda de Carga - Potencia");
        auxiliar->desenharBorda();

        std::string texto;

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
                
                texto = "O Valor da Perda de Friccao no Poco para o Modelo Potencia: ";
                if (armazenarHistoricoPerdaCarga == true) relatorioPoco->ArmazenarValor(poco->NomePoco(),texto, modeloPotencia->FatorFriccaoPoco(), " psi/ft");

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

                texto = "O Valor da Perda de Friccao no Anular para o Modelo Potencia: ";
                if (armazenarHistoricoPerdaCarga == true) relatorioPoco->ArmazenarValor(poco->NomePoco(),texto, modeloPotencia->FatorFriccaoAnular(), " psi/ft");

                break;
            case 0:
                return; // Volta ao menu principal
            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
                break;
        }

        std::cout << "\nPressione Enter para continuar...";
        std::cin.ignore().get(); // Pausa ate pressionar Enter
    }
}

void CSimuladorPoco::MenuPreferencias() {
    int escolha;
    do {
        std::cout << "\n=== Configuração da Interface CLI ===\n";

        // Mostrar configuração atual
        std::cout << "1. Armazenar propriedades do poco: " 
                  << (armazenarPropriedadesPoco ? "True" : "False") << "\n";
        std::cout << "2. Armazenar historico de presao hidroestatica do poco: " 
                  << (armazenarHistoricoPressaoHidrostatica ? "True" : "False") << "\n";
        std::cout << "3. Armazenar historico de perda de carga do poco: " 
                  << (armazenarHistoricoPerdaCarga ? "True" : "False") << "\n";

        std::cout << "\nEscolha a configuração para alternar (1, 2, 3) ou 0 para sair: ";
        std::cin >> escolha;

        if (escolha == 0) {
            break;  // Sair do menu
        }

        // Verificar se a escolha é válida (1, 2 ou 3)
        if (escolha == 1) {
            armazenarPropriedadesPoco = !armazenarPropriedadesPoco;
        } else if (escolha == 2) {
            armazenarHistoricoPressaoHidrostatica = !armazenarHistoricoPressaoHidrostatica;
        } else if (escolha == 3) {
            armazenarHistoricoPerdaCarga = !armazenarHistoricoPerdaCarga;
        } else {
            std::cout << "Opção inválida. Tente novamente.\n";
        }

    } while (true);  // Continua até o usuário escolher sair
}