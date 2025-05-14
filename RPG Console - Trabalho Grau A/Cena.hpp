#pragma once

#include <string.h>
#include <string>

#include "Decisao.hpp"
#include "Ferramenta.hpp"
#include "Inimigo.hpp"
#include "Jogador.hpp"

#define MAX_DECISOES 3

using namespace std;

class Cena {

    public:
        // Construtor
        Cena();
        // Destrutor
        ~Cena();

        // Setters
        // Cenas Info
        void setId(int id);
        void setDescricao(string descricao);
        // Decisao
        void setQntOpcoes(int qntOpcoes);
        void setDecisao(Decisao d);
        void setTemDecisao(bool);
        // Item
        void setItem(Item* i);
        void setTemItem(bool);
        // Inimigo
        void setInimigo(Inimigo i);
        void setTemInimigo(bool);

        // Getters
        // Infos da Cena
        int getId() const;
        string getDescricao() const;
        // Decisao
        Decisao getDecisao(int i);
        int getQntOpcoes() const;
        bool getTemDecisao() const;
        // Item
        bool getTemItem() const;
        Item* getItem() const;
        // Inimigo
        bool getTemInimigo() const;
        Inimigo getInimigo() const;

        // Métodos
        void contarHistoria();
        Decisao escolherDecisao(Jogador &jogador);
        // void adicionarItem(Item *i);

        // void mostrarEscolhas() const;
        // Decisao escolherDecisao() const;

        std::string getProximaCena() const { return proximaCena; }
        bool temProximaCena() const { return !proximaCena.empty(); }

        // DEBUG
        void debugInimigo() const;
        void debugItens() const;

    private:
        // Infos da Cena
        int id;
        string descricao;
        std::string proximaCena;
        // Decisão
        Decisao decisao[MAX_DECISOES];
        int qntOpcoes;
        int escolha;
        bool temDecisao;
        // Item
        Item *item;
        bool temItem;
        // Inimigo
        Inimigo inimigo;
        bool temInimigo;
        // Jogador
        Jogador jogador;
};
