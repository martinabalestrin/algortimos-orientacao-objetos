#include "GerenciadorCenas.hpp"

// Construtor
GerenciadorCenas::GerenciadorCenas() {

}

// Destrutor
GerenciadorCenas::~GerenciadorCenas() {

}

// Setters
void GerenciadorCenas::setCenaAtual(int id) {
    this->cenaAtual = arquivoCena.carregarCena(id);
}

// Getters
Cena GerenciadorCenas::getCenaAtual() const {
    return cenaAtual;
}

// M�todos
void GerenciadorCenas::mostrarCena() {

    system("cls"); // limpa a tela a cada nova cena
    cenaAtual.contarHistoria();

    std::cout << "\n";
    // cenaAtual.mostrarEscolhas(); // MOSTRA AS OP��ES AQUI APENAS UMA VEZ
}

void GerenciadorCenas::processarEscolha(Jogador &jogador) {

    bool repetirEscolha = true;

    while(repetirEscolha) {

        // Captura a escolha do jogador
        Decisao d = cenaAtual.escolherDecisao(jogador);

        if (d.getProxCenaId() == -1) {
            // -1 significa "Abrir Invent�rio"
            jogador.exibirInventario();
            // Depois de voltar, reexibir a cena e perguntar de novo
            system("cls");
            cenaAtual.contarHistoria();
            std::cout << "\n";
        } else if (d.getProxCenaId() == 0) {
            return;
        } else {
            setCenaAtual(d.getProxCenaId());
            system("cls");
            return;
        }
    }
}

void GerenciadorCenas::seguirHistoria() {

std::cout << "=================================================\n";
    std::cout << "1. Seguir hist�ria" << std::endl;
    std::cout << "=================================================\n";

    std::cout << std::endl << "Op��o: ";
    int escolha;
    std::cin >> escolha;

    while(escolha != 1) {
        cout << "Escolha inv�lida, selecione novamente: ";
        cin >> escolha;
    }

    // Limpa a tela
    system("cls");
}

void GerenciadorCenas::salvarCenaAtual(std::ostream& out) const {
    out << "CenaAtual: " << cenaAtual.getId() << "\n";
}

int GerenciadorCenas::carregarCenaSalva(std::istream& in) {
    std::string linha;
    int id = 1; // valor padr�o de seguran�a

    while (std::getline(in, linha)) {
        if (linha.find("CenaAtual:") == 0) {
            std::istringstream ss(linha);
            ss.ignore(11); // ignora "CenaAtual: "
            ss >> id;

            // Verifica se o ID � v�lido
            if (id < 1) id = 1;
            break;
        }
    }

    setCenaAtual(id);
    return id;
}

void GerenciadorCenas::avancarCena() {
    if (cenaAtual.temProximaCena()) {
        setCenaAtual(std::stoi(cenaAtual.getProximaCena())); // convers�o de string para int
    }
    else {
        std::cout << "Fim da historia!" << std::endl;
        exit(0);
    }
}
