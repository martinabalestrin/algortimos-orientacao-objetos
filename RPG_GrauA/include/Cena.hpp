#pragma once

#include <string.h>
#include <string>

using namespace std;

class Cena {

    public:
        // Construtor
        Cena();
        // Destrutor
        ~Cena();

        // Setters
        void setId(int id);
        void setDescricao(string descricao);

        // Getters
        int getId() const;
        string getDescricao() const;

        // Métodos
        void contarHistoria();

    private:
        int id;
        string descricao;
};
