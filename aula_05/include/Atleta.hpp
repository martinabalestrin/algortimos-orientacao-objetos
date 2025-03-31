#pragma once
#include <string>

using namespace std;

class Atleta {
    public:
        // Construtor
        Atleta();
        Atleta(string nome, int idade);

        // Destrutor
        ~Atleta();

        // Getters
        string getNome();
        int getIdade();

        // M�todos
        virtual void imprime_info();

    private:
        // Atributos
        string nome;
        int idade;
};
