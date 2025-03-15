#pragma once

#include <iostream>
#include <string>

using namespace std;

class Calculadora {

    public:

        // --- CONSTRUTORES ---
        Calculadora();
        Calculadora(string);
        // --- DESTRUTOR ---
        ~Calculadora();

        // --- M�TODOS ---

        // Opera��es
        float somar(float, float);
        float subtrair(float, float);
        float multiplicar(float, float);
        float dividir(float, float);
        float elevaQuadrado(float);
        float elevaCubo(float);

        // Setters
        void setCor(string);
        void setMemoria(int);

        // Getters
        string getCor();
        int getMemoria();

        // Imprimir Informa��es
        void imprimeInfo();

    private:

        // --- ATRIBUTOS ---
        int memoria = 0;
        string cor;
};

