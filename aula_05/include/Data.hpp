#pragma once

using namespace std;

class Data {

    public:
        // Construtor
        Data();
        Data(int dia, int mes, int ano);
        // Destrutor
        ~Data();
        // Getters
        int getDia();
        int getMes();
        int getAno();
        // M�todos
        void imprime_info();

    private:
        int dia;
        int mes;
        int ano;
};
