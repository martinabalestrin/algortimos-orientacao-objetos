#include <iostream>
#include <string>

#include "Calculadora.h"
#include "FuncionarioCaixa.h"
#include "Empresa.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "Portuguese");

    Calculadora calculadora1("Amarelo");
    Calculadora calculadora2("Verde");

    FuncionarioCaixa funcionario1("Martina", "Novo Hamburgo", calculadora1);
    FuncionarioCaixa funcionario2("Júlia", "Porto Alegre", calculadora2);

    cout << "Operações realizadas com a calculadora do primeiro funcionário: " << endl;
    cout << "- " << funcionario1.somar(2,2) << endl;
    cout << "- " << funcionario1.subtrair(5,4) << endl;
    cout << "- " << funcionario1.multiplicar(2,3) << endl;
    cout << "\n" << endl;

    cout << "Operações realizadas com a calculadora do segundo funcionário: " << endl;
    cout << "- " << funcionario2.dividir(6,3) << endl;
    cout << "- " << funcionario2.somar(7,2) << endl;
    cout << "- " << funcionario2.multiplicar(8,3) << endl;
    cout << "\n" << endl;

    Empresa empresa("Tina Corporation", funcionario1, funcionario2);

    empresa.imprimeInfo();

    return 0;
}
