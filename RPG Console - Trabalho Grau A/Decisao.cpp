#include "Decisao.hpp"

// Construtor
Decisao::Decisao() {

}

Decisao::Decisao(int proxCenaId, const std::string& texto) {
    this->proxCenaId = proxCenaId;
    this->decisao = texto;
}

// Destrutor
Decisao::~Decisao() {

}

// Setters
void Decisao::setDecisao(string decisao) {
    this->decisao=decisao;
}

void Decisao::setProxCenaId(int proxCenaId) {
    this->proxCenaId=proxCenaId;
}

// Getters
string Decisao::getDecisao() const {
    return decisao;
}

int Decisao::getProxCenaId() const {
    return proxCenaId;
}

