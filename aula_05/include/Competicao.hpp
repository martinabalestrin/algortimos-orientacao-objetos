#pragma once
#include <string>
#include "Data.hpp"

using namespace std;

class Competicao {

    public:
        // Construtor
        Competicao();
        Competicao(string nome, Data *data, string local);
        // Destrutor
        ~Competicao();
        // Getters
        string getNome();
        string getLocal();
        // Métodos
        void imprime_competicao();

    private:
        string nome;
        Data *data;
        string local;
};
