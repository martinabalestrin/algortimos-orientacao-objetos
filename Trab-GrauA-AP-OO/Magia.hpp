#ifndef MAGIA_HPP
#define MAGIA_HPP

#include "Item.hpp"
#include <iostream>

class Magia: public Item {

    private:
        // Atributos
        int dano;

    public:
        // Construtor
        Magia(const std::string& nome, int dano);

        // Métodos
        void usar() override;

        // Getters
        int getDano() const;

        // DEBUG
        void debugItem() const override;
};

#endif
