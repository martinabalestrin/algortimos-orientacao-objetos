#pragma once
#include "Pessoa.hpp"

using namespace std;

class Aluno: public Pessoa {

    public:
        // Construtor
        Aluno();
        Aluno(Pessoa *pessoa, double nota);
        // Destrutor
        ~Aluno();

        // Setters
        void setNota(double nota);
        // Getters
        double getNota() const;

        // Métodos
        void imprime_dados();

    private:
        double nota;
        Pessoa *pessoa;
};
