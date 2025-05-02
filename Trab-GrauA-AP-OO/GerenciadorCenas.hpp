#pragma once

#include <iostream>
#include <fstream>

#include "Cena.hpp"
#include "ArquivoCena.hpp"
#include "Jogador.hpp"

using namespace std;

class GerenciadorCenas {

    public:
        // Construtor
        GerenciadorCenas();
        // Destrutor
        ~GerenciadorCenas();

        // Setters
        void setCenaAtual(int id);
        // Getters
        Cena getCenaAtual() const;

        // Métodos
        void mostrarCena();
        void processarEscolha(Jogador &jogador);
        void seguirHistoria();

        void salvarCenaAtual(std::ostream& out) const;
        int carregarCenaSalva(std::istream& in);

        void avancarCena();

    private:
        ArquivoCena arquivoCena;
        Cena cenaAtual;
};
