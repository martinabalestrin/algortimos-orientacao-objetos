#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "Personagem.hpp"
#include "Item.hpp"
#include "Tesouro.hpp"
#include "Provisao.hpp"

class Inimigo: public Personagem {

    private:
        // Atributos
        // Item
        Item* itemDropado;
        // Tesouro
        Tesouro tesouro;
        // Provis�o
        Provisao provisao;
        int qntProvisao;
        // Hist�ria
        int capSeGanhar;
        int capSePerder;

    public:
        // Construtores
        Inimigo(std::string nome, int hab, int ene, int sorte,
            Item* item, Tesouro t, Provisao p);
        Inimigo();

        // Setters
        void setItem(Item *item);
        void setTesouro(int valor);
        void setQntProvisao(int quantidade);
        void setCapSeGanhar(int cap);
        void setCapSeperder(int cap);

        // Getters
        Item* getItem() const;
        Tesouro getTesouro() const;
        int getQntProvisao() const;
        int getCapSeGanhar() const;
        int getCapSePerder() const;

        // M�todos
        int atacar() override;
        bool temDrop() const;
        void receberDano(int dano) override;
        // Provisao sorteiaProvisao();
        // implementar!
};

#endif
