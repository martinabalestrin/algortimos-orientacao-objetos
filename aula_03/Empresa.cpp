#include "Empresa.h"
#include "FuncionarioCaixa.h"
#include "Calculadora.h"

// ----- CONSTRUTORES ----- //

Empresa::Empresa() {

}

Empresa::Empresa(string nome, FuncionarioCaixa f1, FuncionarioCaixa f2) {
    nomeEmpresa = nome;
    funcionario1 = f1;
    funcionario2 = f2;
}

// ----- DESTRUTOR ----- //

Empresa::~Empresa() {

}

// ----- SETTERS ----- //

void Empresa::setFuncionario1 (FuncionarioCaixa f1) {
    funcionario1 = f1;
}

void Empresa::setFuncionario2 (FuncionarioCaixa f2) {
    funcionario2 = f2;
}

void Empresa::setNomeEmpresa (string nome) {
    nomeEmpresa = nome;
}

// ----- GETTERS ----- //

FuncionarioCaixa Empresa::getFuncionario1() {
    return funcionario1;
}

FuncionarioCaixa Empresa::getFuncionario2() {
    return funcionario2;
}

string Empresa::getNomeEmpresa() {
    return nomeEmpresa;
}

// ----- IMPRIMIR INFORMAÇÕES ----- //

void Empresa::imprimeInfo() {
    cout << "-- EMPRESA ---\n" << endl;
    cout << "Nome: " << nomeEmpresa << endl;
    cout << "Funcionários: " << endl;
    cout << funcionario1.getNome() << " | " << funcionario1.getEndereco() << " | ";
    funcionario1.getCalculadora();
    cout << endl;
    cout << funcionario2.getNome() << " | " << funcionario2.getEndereco() << " | ";
    funcionario2.getCalculadora();
    cout << endl;
}
