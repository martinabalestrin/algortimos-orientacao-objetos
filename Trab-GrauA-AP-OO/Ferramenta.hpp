#ifndef FERRAMENTA_HPP
#define FERRAMENTA_HPP

#include "Item.hpp"
#include <iostream>

class Ferramenta: public Item {

    private:
        char tipo;
        bool combate;
        int bonusFA;
        int dano;

    public:
        // Construtores
        Ferramenta();
        Ferramenta(const std::string& nome, char tipo, bool combate, int bonusFA, int dano);

        // Métodos
        void usar() override;

        // Getters
        char getTipo() const;
        bool isCombate() const;
        int getBonusFA() const;
        int getDano() const;

        // DEBUG
        void debugItem() const;

};

#endif
