#pragma once
#include "Fruta.hpp"
#include <string>

using namespace std;

class Banana: public Fruta {

    public:
        // Construtores
        Banana();
        Banana(double preco, string tipo);
        // Destrutor
        ~Banana();
        // Setters
        void SetTipo(string t);
        // Getters
        string getTipo();

    private:
        string tipo;
};
