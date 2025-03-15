#include "Calculadora.h"

// ----- CONSTRUTORES ----- //

Calculadora::Calculadora() {

}

Calculadora::Calculadora(string cor) {
    this->cor = cor;
}

// ----- DESTRUTOR ----- //

Calculadora::~Calculadora() {

}

// ----- OPERAÇÕES ----- //

float Calculadora::somar(float a, float b) {
    return a + b;
}

float Calculadora::subtrair(float a, float b) {
    return a - b;
}

float Calculadora::multiplicar(float a, float b) {
    return a * b;
}

float Calculadora::dividir(float a, float b) {
    return a / b;
}

float Calculadora::elevaQuadrado(float a) {
    return a * a;
}

float Calculadora::elevaCubo(float a) {
    return a * a * a;
}

// ----- SETTERS ----- //

void Calculadora::setCor(string cor) {
    this->cor = cor;
}

void Calculadora::setMemoria(int memoria) {
    this->memoria = memoria;
}

// ----- GETTERS ----- //

string Calculadora::getCor() {
    return cor;
}

int Calculadora::getMemoria() {
    return memoria;
}

// ----- IMPRIMIR INFORMAÇÕES ----- //

void Calculadora::imprimeInfo() {
    cout << "-- CALCULADORA ---" << endl;
    cout << "Memória: " << memoria << endl;
    cout << "Cor: " << cor << endl;
}

