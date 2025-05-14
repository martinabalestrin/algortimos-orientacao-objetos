#pragma once

#include "Jogador.hpp"
#include "Inimigo.hpp"
#include "Magia.hpp"

class Batalha {

    private:
        Jogador& jogador;
        Inimigo& inimigo;

    public:
        Batalha(Jogador& jogador, Inimigo& inimigo);
        bool iniciarBatalha();
        void turnoJogador();
        void turnoInimigo();
        void usarMagia();
        void mostrarStatus();
};
