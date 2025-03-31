#pragma once
#include "Fruta.hpp"

class Melancia: public Fruta {

    public:
        // Construtor
        Melancia();
        Melancia(double preco, double precoAdicional, bool epocaDaFruta);
        // Destrutor
        ~Melancia();
        // Setters
        void setPrecoAdicional(double pa);
        void setEpocaDaFruta(bool epoca);
        // Getters
        double getPrecoAdicional() const;
        bool getEpocaDaFruta() const;
        // Métodos
        double calcula_preco_final(double taxaImposto);

    private:
        double precoAdicional;
        bool epocaDaFruta;
};
