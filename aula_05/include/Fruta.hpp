#pragma once
#include <string>

using namespace std;

class Fruta {

    public:
        // Construtor
        Fruta();
        Fruta(double preco);
        // Destrutor
        ~Fruta();
        // Setters
        void setPreco(double p);
        // Getters
        double getPreco();
        // M�todos
        double calcula_preco(double taxaImposto);

    protected:
        double preco;
};
