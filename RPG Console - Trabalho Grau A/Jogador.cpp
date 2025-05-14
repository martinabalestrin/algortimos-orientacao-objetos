#include "Jogador.hpp"
#include <iostream>

Jogador::Jogador() : Personagem("", 6, 12, 6) {
    qntProvisao = 0;
}

void Jogador::defJogador() {
    std::cout << "Digite o nome do jogador: ";
    std::cin >> nome;

    int escolhaModo;
    std::cout << "\nEscolha o modo de distribuição de pontos:\n" << std::endl;
    std::cout << "1 - Manual" << std::endl;
    std::cout << "2 - Aleatorio\n" << std::endl;
    std::cout << "Opcao: ";
    std::cin >> escolhaModo;

    int pontosTotais = 12;
    int addHabilidade = 0, addEnergia = 0, addSorte = 0;

    if (escolhaModo == 1) {
        std::cout << std::endl << "Voce possui 12 pontos para distribuir entre Habilidade, Energia e Sorte." << std::endl << std::endl;

        while (true) {
            int pontosRestantes = pontosTotais;

            std::cout << "Pontos restantes: " << pontosRestantes << std::endl;
            std::cout << "Distribua para Habilidade: ";
            std::cin >> addHabilidade;

            if (addHabilidade < 0 || addHabilidade > pontosRestantes) {
                std::cout << "Valor invalido! Tente novamente.\n\n";
                continue;
            }

            pontosRestantes -= addHabilidade;

            std::cout << "Pontos restantes: " << pontosRestantes << std::endl;
            std::cout << "Distribua para Energia: ";
            std::cin >> addEnergia;

            if (addEnergia < 0 || addEnergia > pontosRestantes) {
                std::cout << "Valor invalido! Tente novamente.\n\n";
                continue;
            }

            pontosRestantes -= addEnergia;

            std::cout << "Pontos restantes: " << pontosRestantes << std::endl;
            std::cout << "Distribua para Sorte: ";
            std::cin >> addSorte;

            if (addSorte < 0 || addSorte > pontosRestantes) {
                std::cout << "Valor invalido! Tente novamente.\n\n";
                continue;
            }

            if (addHabilidade + addEnergia + addSorte == pontosTotais) {
                break;
            }
            else {
                std::cout << std::endl << "Distribuição invalida! A soma deve ser 12." << std::endl << std::endl;
            }
        }
    }
    else if (escolhaModo == 2) {
        srand(time(0)); // inicializa aleatoriedade
        addHabilidade = rand() % (pontosTotais + 1);
        int restantes = pontosTotais - addHabilidade;
        addEnergia = rand() % (restantes + 1);
        addSorte = restantes - addEnergia;

        std::cout << "\nDistribuição aleatoria feita!\n";
        std::cout << "Habilidade: " << addHabilidade << "\n";
        std::cout << "Energia: " << addEnergia << "\n";
        std::cout << "Sorte: " << addSorte << "\n\n";
    }
    else {
        std::cout << "Opção invalida. Usando modo aleatório por padrão.\n";
        srand(time(0));
        addHabilidade = rand() % (pontosTotais + 1);
        int restantes = pontosTotais - addHabilidade;
        addEnergia = rand() % (restantes + 1);
        addSorte = restantes - addEnergia;
    }

    habilidade += addHabilidade;
    energia += addEnergia;
    sorte += addSorte;

    system("cls");

    std::cout << "Jogador criado com sucesso!" << std::endl << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Habilidade: " << habilidade << std::endl;
    std::cout << "Energia: " << energia << std::endl;
    std::cout << "Sorte: " << sorte << std::endl << std::endl;
    std::cout << "--------------------------" << std::endl << std::endl;
}

int Jogador::atacar() {

    int dano;
    int FA = habilidade + dado.rolar(); // FA é habilidade + dado
    bool escolheuTestar = false;
    bool resultadoSorte = false;

    std::cout << nome << " deseja testar a sorte antes do ataque? (1 = SIM / 0 = NAO): ";
    std::cin >> escolheuTestar;

    if(escolheuTestar) {
        resultadoSorte = testarSorte(); // só testa se quiser
    }

    if (temFerramentaCombate && ferramentaCombate.isCombate()) {
        FA += ferramentaCombate.getBonusFA();
        dano = FA + ferramentaCombate.getDano();

        if (escolheuTestar)
            dano += resultadoSorte ? 2 : -1;

        std::cout << nome << " ataca com bônus da " << ferramentaCombate.getNome()
                  << " causando " << dano << " de dano!\n";
    } else {
        dano = FA;
        if (escolheuTestar)
            dano += resultadoSorte ? 2 : -1;

        std::cout << nome << " ataca com " << dano << " de dano!\n";
    }

    return dano;
}

bool Jogador::defender() {

    bool escolheuTestar = false;
    bool resultadoSorte = false;

    std::cout << nome << " deseja testar a sorte para se defender? (1 = SIM / 0 = NÃO): ";
    std::cin >> escolheuTestar;

    if(escolheuTestar) {
        resultadoSorte = testarSorte(); // só testa se quiser
    }

    if (resultadoSorte) {
        std::cout << "Voce se defendeu com sucesso usando a sorte!\n";
        return true;
    }
    else {
        return false;
    }
}

void Jogador::receberDano(int dano) {
    energia -= dano;
    if (energia < 0) energia = 0;
    std::cout << nome << " recebeu " << dano << " de dano! Energia atual: " << energia << "\n";
}

bool Jogador::testarSorte() {

    std::cout << nome << " está testando a sorte... ";
    bool sucesso = dado.testarSorte(sorte);

    if(sorte > 0) sorte--; // decrementa a sorte

    if (sucesso) {
        std::cout << "SUCESSO!" << std::endl;
    }

    else {
        std::cout << "FRACASSO!" << std::endl;
    }

    return sucesso;
}

void Jogador::usarItem(Item& item) {
    std::cout << nome << " usou o item." << std::endl;
}

bool Jogador::usarProvisao() {
    int qnt = inventario.getQntProvisao();

    if(qnt > 0) {
        energia += qnt;
        if(energia > MAX_ENERGIA) energia = MAX_ENERGIA;

        std::cout << "Você usou todas as provisões (" << qnt << "). Energia atual: " << energia << "\n";

        inventario.adicionaProvisao(-qnt); // zera as provisões
        return true;
    } else {
        std::cout << "Você não possui provisões!\n";
        return false;
    }
}

void Jogador::usarMagia() {
    std::cout << nome << " usou uma magia!" << std::endl;
}

void Jogador::equiparFerramenta(Ferramenta& ferramenta) {

    // Equipar a ferramente de acordo com o tipo + validação se já está equipada
    if (ferramenta.getTipo() == 'w') { // Combate

        if (temFerramentaCombate && ferramenta.getNome() == ferramentaCombate.getNome()) {
            std::cout << "Voce ja equipou essa ferramenta de combate.\n";
            return;
        }

        ferramentaCombate = ferramenta;
        temFerramentaCombate = true;
        std::cout << nome << " equipou ferramenta de combate: " << ferramenta.getNome() << "\n";
    }

    else if (ferramenta.getTipo() == 'r') { // Vida

        if (temFerramentaSuporte && ferramenta.getNome() == ferramentaSuporte.getNome()) {
            std::cout << "Voce ja equipou essa ferramenta de suporte.\n";
            return;
        }

        if (temFerramentaSuporte) {
            // Se já existe uma ferramenta equipada, remove o bônus anterior
            energia -= ferramentaSuporte.getBonusFA();
            if (energia < 0) energia = 0;
        }

        ferramentaSuporte = ferramenta;
        temFerramentaSuporte = true;
        energia += ferramenta.getBonusFA(); // Aumenta a energia
        if (energia > MAX_ENERGIA) energia = MAX_ENERGIA;

        std::cout << nome << " equipou ferramenta de suporte: " << ferramenta.getNome()
            << " (+ " << ferramenta.getBonusFA() << " de energia!)\n";
    }

    else {
        std::cout << "Ocorreu um erro no sistema.\n";
    }
}

void Jogador::mostrarInventario() const {
    inventario.mostrar();
}

void Jogador::adicionarItem(Item* item) {
    inventario.adicionarItem(item);
    inventario.salvarParaArquivo("inventario.txt");
}

void Jogador::salvarEmArquivo(const std::string& nomeArquivo) const {
    std::ofstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        arquivo << "Nome: " << nome << '\n';
        arquivo << "Habilidade: " << habilidade << '\n';
        arquivo << "Energia: " << energia << '\n';
        arquivo << "Sorte: " << sorte << '\n';
        arquivo.close();
    }
    else {
        std::cerr << "Erro ao abrir o arquivo para escrita.\n";
    }
}

Inventario& Jogador::getInventario() {
    return inventario;
}

const Inventario& Jogador::getInventario() const {
    return inventario;
}

void Jogador::exibirInventario() {
    int opcao;

    system("cls");

    do {
        std::cout << "\n============= INVENTARIO =============\n";
        std::cout << "Nome: " << nome << std::endl;
        std::cout << "Habilidade: " << habilidade << std::endl;
        std::cout << "Energia: " << energia << std::endl;
        std::cout << "Sorte: " << sorte << std::endl;
        inventario.mostrar();
        std::cout << "======================================\n";

        std::cout << "1. Usar Provisao (recupera energia)\n";
        std::cout << "2. Equipar Ferramenta\n";
        std::cout << "3. Voltar ao jogo\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        system("cls");

        switch(opcao) {
            case 1:
                usarProvisao();
                break;

            case 2: {
                // Listar as ferramentas no inventário
                std::vector<Ferramenta> ferramentas = inventario.getFerramentas();

                if (ferramentas.empty()) {
                    std::cout << "Voce nao possui ferramentas para equipar.\n";
                    break;
                }

                std::cout << "\nFerramentas disponiveis:\n";
                for (size_t i = 0; i < ferramentas.size(); ++i) {
                    std::cout << i + 1 << ". " << ferramentas[i].getNome()
                        << " (Tipo: " << ferramentas[i].getTipo()
                        << ", FA: " << ferramentas[i].getBonusFA()
                        << ", Dano: " << ferramentas[i].getDano() << ")\n";
                }

                std::cout << std::endl;
                std::cout << "Escolha a ferramenta para equipar: ";
                int escolha;
                std::cin >> escolha;

                if (escolha >= 1 && escolha <= static_cast<int>(ferramentas.size())) {
                    equiparFerramenta(ferramentas[escolha - 1]);
                } else {
                    std::cout << std::endl;
                    std::cout << "Escolha invalida.\n";
                }

                break;
            }

            case 3:
                std::cout << "Voltando ao jogo...\n";
                break;

            default:
                std::cout << "Opcao invalida. Tente novamente.\n";
        }

    } while(opcao != 3);
}
