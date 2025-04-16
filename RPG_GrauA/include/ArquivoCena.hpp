#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>

#include "Cena.hpp"
// includes nas classes Inimigo, Item(Ferramenta?), Decisao

#define MAX_LINHAS 20
#define TAM_LINHA 256
#define MAX_DECISOES 3

using namespace std;

class ArquivoCena {

    public:
        // Construtor
        ArquivoCena();
        // Destrutor
        ~ArquivoCena();

        // Métodos
        Cena carregarCena(int id);

};
