#include <iostream>

#include "Personagem.hpp"

// ------------------
// Construtor
// ------------------

Personagem::Personagem() {

}

Personagem::Personagem(string nome, int habilidade, int energia, int sorte):
    nome(nome), habilidade(habilidade), energia(energia), sorte(sorte) {

}

// ------------------
// Destrutor
// ------------------

Personagem::~Personagem() {

}
