#include "FuncionarioCaixa.h"
#include "Calculadora.h"

// ----- CONSTRUTORES ----- //

FuncionarioCaixa::FuncionarioCaixa() {

}

FuncionarioCaixa::FuncionarioCaixa(string nome, string endereco, Calculadora calculadora) {
    this->nome = nome;
    this->endereco = endereco;
    this->calculadora = calculadora;
}

// ----- DESTRUTOR ----- //

FuncionarioCaixa::~FuncionarioCaixa() {

}

// ----- SETTERS ----- //

void FuncionarioCaixa::setNome(string nome) {
    this->nome = nome;
}

void FuncionarioCaixa::setEndereco(string endereco) {
    this->endereco = endereco;
}

void FuncionarioCaixa::setCalculadora(Calculadora x) {
    calculadora = x;
}

// ----- GETTERS ----- //

string FuncionarioCaixa::getNome() {
    return nome;
}

string FuncionarioCaixa::getEndereco() {
    return endereco;
}

void FuncionarioCaixa::getCalculadora() {
    cout << calculadora.getCor();
}

// ----- OPERAÇÕES ----- //

float FuncionarioCaixa::somar(float a, float b) {
    return calculadora.somar(a,b);
}

float FuncionarioCaixa::subtrair(float a, float b) {
    return calculadora.subtrair(a,b);
}

float FuncionarioCaixa::multiplicar(float a, float b) {
    return calculadora.multiplicar(a,b);
}

float FuncionarioCaixa::dividir(float a, float b) {
    return calculadora.dividir(a,b);
}

float FuncionarioCaixa::elevaQuadrado(float a) {
    return calculadora.elevaQuadrado(a);
}

float FuncionarioCaixa::elevaCubo(float a) {
    return calculadora.elevaCubo(a);
}

// ----- IMPRIMIR INFORMAÇÕES ----- //

void FuncionarioCaixa::imprimeInfo() {
    cout << "-- FUNCIONÁRIO ---" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Endereço: " << endereco << endl;
    cout << "Cor da calculadora: " << calculadora.getCor() << endl;
    cout << "Memória da calculadora: " << calculadora.getMemoria() << endl;
}
