#include "Pais.hpp"
#include <iostream>

Pais::Pais() {

}

Pais::Pais(string codigoISO, string nome, double dimensao):
    codigoISO(codigoISO), nome(nome), dimensao(dimensao) {

}

Pais::~Pais() {

}

void Pais::setCodigoISO(string codigoISO) {
    this->codigoISO=codigoISO;
}

void Pais::setNome(string nome) {
    this->nome=nome;
}

void Pais::setPopulacao(int populacao) {
    this->populacao=populacao;
}

void Pais::setDimensao(double dimensao) {
    this->dimensao=dimensao;
}

string Pais::getCodigoISO() const {
    return codigoISO;
}

string Pais::getNome() const {
    return nome;
}

int Pais::getPopulacao() const {
    return populacao;
}

double Pais::getDimensao() const {
    return dimensao;
}

bool Pais::comparaPais(const Pais &pais) const {
    // Compara se esse pa�s e o par�metro s�o o mesmo, com base no c�digo ISO
    return pais.getCodigoISO() == this->codigoISO;
}

void Pais::adicionarPaisFronteira(Pais &pais) {
    // Coloca o pa�s vizinho na lista deste pa�s
    paisesFronteira.push_back(pais.getNome());
    // Coloca esse pa�s na lista do pa�s vizinho
    pais.paisesFronteira.push_back(this->getNome());
}

bool Pais::verificaPaisFronteira(const Pais &pais) const {
    // Verifica se o pa�s passado por par�metro est� na lista de pa�ses que este pa�s faz fronteira
    for(int i = 0; i < paisesFronteira.size(); i++) {
        if(paisesFronteira[i] == pais.getNome()) {
            return true;
        }
    }
    return false;
}

double Pais::densidade() const {
    // Calcula a densidade do pa�s. A popula��o deve ter sido informada por meio de setPopulacao()
    if(populacao == 0) {
        cout << "Erro. Popula��o n�o informada. ";
        return 0;
    } else {
        return populacao/dimensao;
    }
}

vector<string> Pais::comparaFronteiras(const Pais &pais) const {

    vector<string> vizinhosComuns;

    for(size_t i = 0; i < this->paisesFronteira.size(); i++) {
        for( size_t j = 0; j < pais.paisesFronteira.size(); j++) {

            if(this->paisesFronteira[i] == pais.paisesFronteira[j]) {
                vizinhosComuns.push_back(this->paisesFronteira[i]);
            }
        }
    }

    return vizinhosComuns;
}
