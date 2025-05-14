#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "Cena.hpp"
#include "Decisao.hpp"
#include "Ferramenta.hpp"
#include "Inimigo.hpp"

using namespace std;

class ArquivoCena {

    public:
        // Construtor
        ArquivoCena();
        // Destrutor
        ~ArquivoCena();

        // Métodos
        Cena carregarCena(int id);
        string montarNomeArquivo(int id);
        Decisao lerDecisao(const string &linha);
        Item* lerItem(const string &linha);
        Inimigo lerInimigo(ifstream &arquivo, const string &linhaInicial);
        void lerDescricao(ifstream &arquivo, Cena &cena);
};
