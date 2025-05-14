#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>

class Item {
    private:
        // Atributo
        std::string nome;

    public:
        // Construtores
        Item();
        Item(const std::string& n);
        // Destrutor
        virtual ~Item() {}

        // Método virtual
        virtual void usar() = 0;

        // Getters
        std::string getNome() const;

        // DEBUG
        virtual void debugItem() const = 0;
};

#endif
