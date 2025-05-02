#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "Personagem.hpp"
#include "Inventario.hpp"
#include "Ferramenta.hpp"
#include "Item.hpp"
#include "Dado.hpp"

#define MAX_ENERGIA 24

class Jogador: public Personagem {

    private:
        // Atributos
        Inventario inventario;
        dado dado;
        int qntProvisao;

    public:
        // Construtor
        Jogador();
        void defJogador();

        // Métodos de Personagem
        int atacar() override;
        bool defender() override;
        void receberDano(int dano) override;

        // Métodos
        bool testarSorte();
        void usarItem(Item& item);
        bool usarProvisao();
        void usarMagia();
        void equiparFerramenta(Ferramenta& ferramenta);

        void mostrarInventario() const;
        void adicionarItem(Item* item);

        void salvarEmArquivo(const std::string& nomeArquivo) const;

        Inventario& getInventario(); // acesso para uso
        const Inventario& getInventario() const; // acesso para leitura

        Ferramenta ferramentaCombate;
        Ferramenta ferramentaSuporte;
        bool temFerramentaCombate = false;
        bool temFerramentaSuporte = false;

        void exibirInventario();
};

#endif
