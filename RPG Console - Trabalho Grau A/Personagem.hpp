#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include <iostream>
#include <string>

class Personagem {
protected:
    std::string nome;
    int habilidade;
    int energia;
    int sorte;

public:
    // Construtor
    Personagem(std::string nome, int habilidade, int energia, int sorte);
    Personagem();
    // Destrutor
    virtual ~Personagem() = default;

    // Métodos virtuais
    virtual int atacar() = 0;
    virtual void receberDano(int dano);

    // Getters
    std::string getNome() const;
    int getEnergia() const;
    int getHabilidade() const;
    int getSorte() const;
    // Setters
    void setEnergia(int novaEnergia);
    void setHabilidade(int novaHabilidade);
    void setSorte(int novaSorte);
    void setNome(std::string nome);
};

#endif
