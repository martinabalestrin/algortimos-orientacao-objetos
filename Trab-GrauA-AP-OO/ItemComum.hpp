#pragma once

#include "Item.hpp"
#include <iostream>

class ItemComum: public Item {

    public:
        // Construtor
        ItemComum();
        ItemComum(const std::string& nome);

        // M�todo
        void usar() override;

        void debugItem() const override;
};
