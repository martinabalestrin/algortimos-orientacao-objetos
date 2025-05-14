#include "Batalha.hpp"
#include <iostream>

Batalha::Batalha(Jogador& jogador, Inimigo& inimigo) : jogador(jogador), inimigo(inimigo) {}

bool Batalha::iniciarBatalha() {

    bool resultado;

    std::cout << "=======================\n";
    std::cout << "   INICIO DA BATALHA\n";
    std::cout << "=======================\n";
    std::cout << "Inimigo: " << inimigo.getNome() << "\n";
    std::cout << "Energia do Inimigo: " << inimigo.getEnergia() << "\n";
    std::cout << "-----------------------\n";

    do {

        turnoJogador();

        if (inimigo.getEnergia() <= 0) break;

        turnoInimigo();

        std::cout << std::endl << "1. Próximo turno" << std::endl;
        std::cout << "2. Fugir" << std::endl;
        std::cout << std::endl << "Opção: ";
        int escolha;
        std::cin >> escolha;

        switch(escolha) {

        case 1:
            mostrarStatus();
            break;

        case 2:
            mostrarStatus();
            std::cout << "Não foi possível fugir da batalha!" << std::endl;
            break;

        default:
            std::cout << "Sua opção era inválida. Encaminhado para o turno seguinte!" << std::endl;
            mostrarStatus();
            break;
        }

    } while (jogador.getEnergia() > 0 && inimigo.getEnergia() > 0);

    system("cls");

    std::cout << "\n===============================\n";
    if (jogador.getEnergia() > 0) {
        std::cout << "   VOCE VENCEU A BATALHA!\n";
        std::cout << "===============================\n\n";
        resultado = 1;
    }
    else {
        std::cout << "   VOCE FOI DERROTADO...\n";
        std::cout << "===============================\n\n";
        resultado = 0;
    }

    return resultado;
}

void Batalha::turnoJogador() {
    std::cout << "\n=== SEU TURNO ===\n";
    std::cout << "1.  Atacar\n";
    std::cout << "2.  Usar Magia\n";
    std::cout << "\nEscolha: ";
    int escolha;
    std::cin >> escolha;

    switch (escolha) {
    case 1: {
        int dano = jogador.atacar();
        inimigo.receberDano(dano);
        break;
    }
    case 2:
        usarMagia();
        break;

    default:
        std::cout << "Opção inválida. Você perde a vez.\n";
        break;
    }
}

void Batalha::usarMagia() {
    const auto& magias = jogador.getInventario().getMagias();
    if (magias.empty()) {
        std::cout << "\nVoce nao possui magias para usar!\n";
        return;
    }

    std::cout << "\n--- Magias Disponiveis ---\n";
    for (size_t i = 0; i < magias.size(); ++i) {
        std::cout << i + 1 << ". " << magias[i].getNome()
            << " (Dano: " << magias[i].getDano() << ")\n";
    }

    std::cout << "Escolha a magia: ";
    int escolha;
    std::cin >> escolha;

    if (escolha < 1 || escolha > static_cast<int>(magias.size())) {
        std::cout << "Escolha invalida.\n";
        return;
    }

    Magia magiaEscolhida = magias[escolha - 1];
    std::cout << "Voce usou " << magiaEscolhida.getNome()
        << " causando " << magiaEscolhida.getDano() << " de dano!\n";
    inimigo.receberDano(magiaEscolhida.getDano());
}

void Batalha::turnoInimigo() {
    std::cout << "\n--- Turno do Inimigo ---\n";

    bool defesaJogador = jogador.defender();

    if(defesaJogador == false) {
        int dano = inimigo.atacar();
        jogador.receberDano(dano);
    }
}

void Batalha::mostrarStatus() {
    // Limpar a tela, muita poluição
    system("cls");

    std::cout << "[STATUS]\n";
    std::cout << "Jogador: " << jogador.getNome() << " | Energia: " << jogador.getEnergia() << "\n";
    std::cout << "Inimigo: " << inimigo.getNome() << " | Energia: " << inimigo.getEnergia() << "\n";
}
