#pragma once

#include <iostream>
#include <string>

#include "FuncionarioCaixa.h"

using namespace std;

class Empresa {

    public:
        // --- CONSTRUTOR ---
        Empresa();
        Empresa(string, FuncionarioCaixa, FuncionarioCaixa);
        // --- DESTRUTOR ---
        ~Empresa();

        // --- M�TODOS ---

        // Setters
        void setFuncionario1 (FuncionarioCaixa);
        void setFuncionario2 (FuncionarioCaixa);
        void setNomeEmpresa (string);

        // Getters
        FuncionarioCaixa getFuncionario1();
        FuncionarioCaixa getFuncionario2();
        string getNomeEmpresa();

        // Imprimir Informa��es
        void imprimeInfo();

    private:
        // --- ATRIBUTOS ---
        FuncionarioCaixa funcionario1;
        FuncionarioCaixa funcionario2;
        string nomeEmpresa;
};

