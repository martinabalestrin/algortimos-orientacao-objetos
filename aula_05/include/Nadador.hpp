#pragma once
#include <string>
#include "Atleta.hpp"

using namespace std;

class Nadador: public Atleta {

    public:
        // Construtor
        Nadador();
        Nadador(Atleta *atleta, string categoria);
        // Destrutor
        ~Nadador();
        // Getters
        string getCategoria();
        // Métodos
        void imprime_info() override;

    private:
        // Atributos
        string categoria;
        Atleta *atleta;
};
