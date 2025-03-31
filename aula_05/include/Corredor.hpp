#pragma once
#include "Atleta.hpp"
#include "Competicao.hpp"
#include <string>

using namespace std;

class Corredor: public Atleta {

    public:
        // Construtor
        Corredor();
        Corredor(Atleta *atleta, float peso, Competicao *competicao);
        // Destrutor
        ~Corredor();
        // Getters
        float getPeso();
        // Métodos
        void imprime_info() override;

    private:
        float peso;
        Atleta *atleta;
        Competicao *competicao;
};
