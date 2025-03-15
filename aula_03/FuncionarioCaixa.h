#pragma once

#include <iostream>
#include <string>

#include "Calculadora.h"

using namespace std;

class FuncionarioCaixa {

    public:
        // --- CONSTRUTOR ---
        FuncionarioCaixa();
        FuncionarioCaixa(string, string, Calculadora);
        // --- DESTRUTOR ---
        ~FuncionarioCaixa();

        // --- MÉTODOS ---

        // Operações
        float somar(float, float);
        float subtrair(float, float);
        float multiplicar(float, float);
        float dividir(float, float);
        float elevaQuadrado(float);
        float elevaCubo(float);

        // Setters
        void setNome(string);
        void setEndereco(string);
        void setCalculadora(Calculadora);

        // Getters
        string getNome();
        string getEndereco();
        void getCalculadora();

        // Imprimir Informações
        void imprimeInfo();

    private:
        // --- ATRIBUTOS ---
        string nome;
        string endereco;
        Calculadora calculadora;
};

