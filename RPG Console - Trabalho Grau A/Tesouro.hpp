#ifndef TESOURO_HPP
#define TESOURO_HPP

#include "Item.hpp"
#include <iostream>

class Tesouro: public Item {

    private:
        // Atributos
        int valor;

    public:
        // Construtor
        Tesouro(const std::string& nome, int valor);
        Tesouro();

        // M�todos
        void usar() override;
        int getValor() const;

        // Setters
        void SetValor(int valor);

        // DEBUG
        void debugItem() const override;
};

#endif
