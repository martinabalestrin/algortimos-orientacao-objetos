#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP

#include "Item.hpp"
#include "Tesouro.hpp"
#include "Provisao.hpp"
#include "Magia.hpp"
#include "Ferramenta.hpp"
#include "ItemComum.hpp"
#include <fstream>
#include <string>
#include <vector>

class Inventario {

    private:
        Item* itens[10];
        int quantidade;
        std::vector<Magia> magias;
        int qntProvisao;

    public:
        Inventario();
        ~Inventario();

        void adicionarItem(Item* item);
        void removerItemPorNome(const std::string& nomeItem);
        void mostrar() const;
        int contarProvisoes() const;

        Item* getItem(int index) const;
        int getQuantidade() const;

        void salvarParaArquivo(const std::string& nomeArquivo) const;
        void carregarDeArquivo(const std::string& nomeArquivo);

        void salvarParaArquivo(std::ostream& out) const;
        void carregarDeArquivo(std::istream& in);

        std::vector<Magia> getMagias() const;
        std::vector<Ferramenta> getFerramentas() const;
        int getQntProvisao() const;

        void adicionaProvisao(int qnt);
};

#endif
