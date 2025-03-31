#pragma once
#include <string>
#include <vector>

using namespace std;

class Pais {

    public:
        // Construtor
        Pais();
        Pais(string codigoISO, string nome, double dimensao);
        // Destrutor
        ~Pais();

        // Setters
        void setCodigoISO(string codigoISO);
        void setNome(string nome);
        void setPopulacao(int populacao);
        void setDimensao(double dimensao);
        // Getters
        string getCodigoISO() const;
        string getNome() const;
        int getPopulacao() const;
        double getDimensao() const;

        // Métodos
        bool comparaPais(const Pais &pais) const;
        void adicionarPaisFronteira(Pais &pais);
        bool verificaPaisFronteira(const Pais &pais) const;
        double densidade() const;
        vector<string> comparaFronteiras(const Pais &pais) const;

    private:
        // Atributos
        string codigoISO;
        string nome;
        int populacao = 0;
        double dimensao;
        vector<string> paisesFronteira;
};
