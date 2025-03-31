#include "Melancia.hpp"

Melancia::Melancia() {

}

Melancia::Melancia(double preco, double precoAdicional, bool epocaDaFruta):
    Fruta(preco), precoAdicional(precoAdicional), epocaDaFruta(epocaDaFruta) {

}

Melancia::~Melancia() {

}

void Melancia::setPrecoAdicional(double pa) {
    precoAdicional = pa;
}

void Melancia::setEpocaDaFruta(bool epoca) {
    epocaDaFruta = epoca;
}

double Melancia::getPrecoAdicional() const {
    return precoAdicional;
}

bool Melancia::getEpocaDaFruta() const {
    return epocaDaFruta;
}

double Melancia::calcula_preco_final(double taxaImposto) {
    if(epocaDaFruta) {
        return preco + precoAdicional;
    } else {
        return calcula_preco(taxaImposto);
    }
}
