#ifndef PROVISAO_HPP
#define PROVISAO_HPP

#include "Item.hpp"
#include <iostream>

class Provisao : public Item {
private:
    // Atributo
    int energiaGanhar;

public:
    // Construtor
    Provisao();
    Provisao(const std::string& nome, int energia);

    // Atributo
    int energia() const;
    // Método
    void usar() override;

    void debugItem() const override;
};

#endif
