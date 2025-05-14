#include "Jogo.hpp"

// Construtor
Jogo::Jogo() {
    jogando = true;
    saveEscolhido = 0;
}

// Destrutor
Jogo::~Jogo() {

}

// Getters
bool Jogo::getJogando() {
    return jogando;
}

// Métodos
void Jogo::menuInicial() {

    int escolha;

    do {

        cout << "Seja bem-vindo ao 'Cidadela do Caos'!" << endl << endl;
        cout << ">> 1 - Novo jogo" << endl;
        cout << ">> 2 - Continuar" << endl;
        cout << ">> 3 - Créditos" << endl;
        cout << ">> 4 - Sair" << endl;
        cout << endl << "Opção: ";
        cin >> escolha;
        cout << endl;

        system("cls");

        switch(escolha) {

            case 1:
                // Novo Jogo
                cout << "--- NOVO JOGO ---\n\n";
                cout << "Escolha o número do save (1, 2, 3): ";
                cin >> saveEscolhido;
                comecarAventura();
                break;

            case 2:
                cout << "--- CARREGAR JOGO ---\n\n";
                cout << "Escolha o número do save (1, 2, 3): ";
                cin >> saveEscolhido;

                if (carregarJogo(saveEscolhido)) {
                    carregandoDeSave = true;
                    jogar(gerenciador.getCenaAtual().getId());
                    carregandoDeSave = false;
                }

                break;

            case 3:
                mostrarCreditos();
                break;
            case 4:

                sairJogo();
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl << endl;
        }

    } while(escolha < 1 || escolha > 4);
}

void Jogo::jogar(int CenaId) {

    // Define a cena que vai começar, se novo jogo vai ser 1, se carregar vai ser outra
    gerenciador.setCenaAtual(CenaId);
    salvarJogo(saveEscolhido);

    // Registra a primeira cena visitada
    int idAtual = gerenciador.getCenaAtual().getId();

    if (std::find(cenasVistas.begin(), cenasVistas.end(), idAtual) == cenasVistas.end()) {
        cenasVistas.push_back(idAtual);
    }
    if (!carregandoDeSave) {
        salvarJogo(saveEscolhido);
    }

    while (jogando) {
        system("cls"); // limpa a tela a cada iteração

        // Exibe descrição e decições
        gerenciador.mostrarCena();

        // Adiciona item se tiver
        if(gerenciador.getCenaAtual().getTemItem()) {
            // Adiciona ao inventário do jogador
            jogador.adicionarItem(gerenciador.getCenaAtual().getItem());
        }

        // Lida com decisões
        if (gerenciador.getCenaAtual().getTemDecisao()) {
            gerenciador.processarEscolha(jogador);

            // Atualiza ID da cena após processar a escolha
            idAtual = gerenciador.getCenaAtual().getId();
            if (std::find(cenasVistas.begin(), cenasVistas.end(), idAtual) == cenasVistas.end()) {
                cenasVistas.push_back(idAtual);
            }

            salvarJogo(saveEscolhido);

            continue; // Força nova iteração já com nova cena
        }

        // Lida com inimigo
        if(gerenciador.getCenaAtual().getTemInimigo()) {

            Inimigo inimigo = gerenciador.getCenaAtual().getInimigo();

            Batalha batalha(jogador, inimigo);

            // Inicia a batalha. Retorna 1 se vencer, 0 se perder
            bool resultadoBatalha = batalha.iniciarBatalha();
            int proxCenaId;

            // Verificação e seguimento dos capítulos a partir de resultadoBatalha
            if(resultadoBatalha == 1) {

                // Coleta de drops
                if (inimigo.getItem() != nullptr) {
                    jogador.adicionarItem(inimigo.getItem());
                }

                if (inimigo.getQntProvisao() > 0) {
                        jogador.getInventario().adicionaProvisao(inimigo.getQntProvisao());
                }

                if (inimigo.getTesouro().getValor() > 0) {
                    jogador.adicionarItem(new Tesouro("Tesouro", inimigo.getTesouro().getValor()));
                }

                gerenciador.seguirHistoria();
                // Continuar história
                proxCenaId = gerenciador.getCenaAtual().getInimigo().getCapSeGanhar();
                gerenciador.setCenaAtual(proxCenaId);
                salvarJogo(saveEscolhido);
            }

            else if(resultadoBatalha == 0) {
                proxCenaId = gerenciador.getCenaAtual().getInimigo().getCapSePerder();
                gerenciador.setCenaAtual(proxCenaId);
                salvarJogo(saveEscolhido);
            }
        }

        else {
            std::cout << "\n=================\n";
            std::cout << "   FIM DE JOGO\n";
            std::cout << "=================\n";

            // Remove o arquivo
            string nomeArquivo = "savegame" + to_string(saveEscolhido) + ".txt";
            remove(nomeArquivo.c_str());

            jogando = false;
            break;
        }
    }
}

void Jogo::mostrarCreditos() {

    int escolha;

    do {
        cout << "----- CRÉDITOS -----" << endl << endl;
        cout << "- Programadores -" << endl;
        cout << "Martina Portella Balestrin" << endl;
        cout << "Vinícius Teixeira Augustin" << endl;
        cout << endl;

        cout << ">> 1 - Voltar" << endl;
        cout << ">> 2 - Sair do Jogo" << endl;
        cout << endl << "Opção: ";
        cin >> escolha;
        cout << endl;

        system("cls");

        switch(escolha) {

            case 1:
                menuInicial();
                break;
            case 2:
                sairJogo();
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl << endl;
        }
    } while (escolha < 1 || escolha > 2);
}

void Jogo::sairJogo() {
    salvarJogo(saveEscolhido);
    cout << "Saindo do jogo..." << endl;
    jogando = false;
}

void Jogo::comecarAventura() {

    jogador.defJogador();

    salvarJogo(saveEscolhido);

    int escolha;

    do {
        cout << "Vamos começar sua aventura?" << endl << endl;
        cout << ">> 1 - Começar minha aventura" << endl;
        cout << ">> 2 - Sair do Jogo" << endl;
        cout << endl << "Opção: ";
        cin >> escolha;
        cout << endl;

        system("cls");

        switch(escolha) {

            case 1:
                jogar(1);
                break;
            case 2:
                sairJogo();
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl << endl;
        }
    } while (escolha < 1 || escolha > 2);
}

void Jogo::salvarJogo(int numSave) const {

    string nomeArquivo = "savegame" + to_string(numSave) + ".txt";
    std::ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao salvar jogo." << std::endl;
        return;
    }

    // Cena atual
    gerenciador.salvarCenaAtual(arquivo);

    // Cenas vistas
    arquivo << "CenasVistas:";
    for (int id : cenasVistas) {
        arquivo << " " << id;
    }
    arquivo << "\n";

    // Jogador
    arquivo << "Nome: " << jogador.getNome() << "\n";
    arquivo << "Habilidade: " << jogador.getHabilidade() << "\n";
    arquivo << "Energia: " << jogador.getEnergia() << "\n";
    arquivo << "Sorte: " << jogador.getSorte() << "\n";

    // Inventário
    arquivo << "Inventario:\n";
    jogador.getInventario().salvarParaArquivo(arquivo);

    std::cout << "[SALVO] Jogo salvo com sucesso!\n\n";
    arquivo.close();
}

bool Jogo::carregarJogo(int numSave) {

    string nomeArquivo = "savegame" + to_string(numSave) + ".txt";
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Nenhum jogo salvo encontrado.\n";
        return false;
    }

    gerenciador.carregarCenaSalva(arquivo);

    std::string linha;
    int cenaId = 1;

    while (std::getline(arquivo, linha)) {
        std::istringstream ss(linha);

        if (linha.find("CenaAtual:") == 0) {
            ss.ignore(11);
            ss >> cenaId;
        }
        else if (linha.find("CenasVistas:") == 0) {
            ss.ignore(13);
            int id;
            while (ss >> id) {
                cenasVistas.push_back(id);
            }
        }
        else if (linha.find("Nome:") == 0) {
            ss.ignore(6);
            std::string nome;
            ss >> nome;
            jogador.setNome(nome);
        }
        else if (linha.find("Habilidade:") == 0) {
            ss.ignore(11);
            int hab;
            ss >> hab;
            jogador.setHabilidade(hab);
        }
        else if (linha.find("Energia:") == 0) {
            ss.ignore(9);
            int ene;
            ss >> ene;
            jogador.setEnergia(ene);
        }
        else if (linha.find("Sorte:") == 0) {
            ss.ignore(7);
            int sorte;
            ss >> sorte;
            jogador.setSorte(sorte);
        }
        else if (linha.find("Inventario:") == 0) {
            jogador.getInventario().carregarDeArquivo(arquivo); // nova função que lê do stream
        }
    }

    jogador.getInventario().salvarParaArquivo("inventario.txt");

    arquivo.close();
    jogando = true;
    system("cls"); // Limpa a tela após carregar tudo
    return true;
}
