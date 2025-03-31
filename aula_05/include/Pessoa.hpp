#pragma once
#include <string>

using namespace std;

class Pessoa {

    public:
        // Construtor
        Pessoa();
        Pessoa(string nome, int idade);
        // Destrutor
        ~Pessoa();

        //Setters
        void setNome(string nome);
        void setIdade(int idade);
        // Getters
        string getNome();
        int getIdade();

        // Métodos
        void imprime_dados();
        static int contador;
        static int getContador();

    private:
        string nome;
        int idade;
};
