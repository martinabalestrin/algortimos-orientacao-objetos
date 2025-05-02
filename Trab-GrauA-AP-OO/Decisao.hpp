#pragma once

#include <iostream>
#include <string>

using namespace std;

class Decisao {

    public:
        // Construtor
        Decisao();
        Decisao(int proxCenaId, const std::string& texto);
        // Destrutor
        ~Decisao();

        // Setters
        void setDecisao(string decisao);
        void setProxCenaId(int proxCenaId);

        // Getters
        string getDecisao() const;
        int getProxCenaId() const;

    private:
        string decisao;
        int proxCenaId;
};
