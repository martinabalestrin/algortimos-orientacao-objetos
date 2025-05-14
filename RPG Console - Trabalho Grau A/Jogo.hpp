#pragma once

#include <iostream>
#include <algorithm>
#include <string>

#include "GerenciadorCenas.hpp"
#include "Jogador.hpp"
#include "Batalha.hpp"

    using namespace std;

    class Jogo {

        public:
            // Construtor
            Jogo();
            // Destrutor
            ~Jogo();

            // Getters
            bool getJogando();

            // Métodos
            void menuInicial();
            void jogar(int CenaId);
            void mostrarCreditos();
            void sairJogo();
            void comecarAventura();

            void salvarJogo(int numSave) const;
            bool carregarJogo(int numSave);

        private:
            // Atributos
            bool jogando;
            int saveEscolhido;
            GerenciadorCenas gerenciador;
            Jogador jogador;

            std::vector<int> cenasVistas;
            bool carregandoDeSave = false;
    };
