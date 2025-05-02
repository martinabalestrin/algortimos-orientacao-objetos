#include "Cena.hpp"

// Construtor
Cena::Cena() {
    qntOpcoes = 0;
    temItem = false;
    temDecisao = false;
    temInimigo = false;
    escolha = 0;
    id = 0;
    item = nullptr;
}

// Destrutor
Cena::~Cena() {

}

// Setters
void Cena::setId(int id) {
    this->id=id;
}

void Cena::setDescricao(string descricao) {
    this->descricao=descricao;
}

void Cena::setQntOpcoes(int qntOpcoes) {
    this->qntOpcoes=qntOpcoes;
}

void Cena::setDecisao(Decisao d) {
    this->decisao[qntOpcoes] = d;
    qntOpcoes++;
}

void Cena::setTemDecisao(bool temDecisao) {
    this->temDecisao=temDecisao;
}

void Cena::setItem(Item* i) {
    this->item=i;
}

void Cena::setTemItem(bool temItem) {
    this->temItem=temItem;
}

void Cena::setInimigo(Inimigo i) {
    this->inimigo=i;
}

void Cena::setTemInimigo(bool temInimigo) {
    this->temInimigo=temInimigo;
}

// Getters
int Cena::getId() const {
    return id;
}

string Cena::getDescricao() const {
    return descricao;
}

Decisao Cena::getDecisao(int i) {
    return decisao[i];
}

int Cena::getQntOpcoes() const {
    return qntOpcoes;
}

bool Cena::getTemDecisao() const {
    return temDecisao;
}

bool Cena::getTemItem() const {
    return temItem;
}

Item* Cena::getItem() const {
    return item;
}

bool Cena::getTemInimigo() const {
    return temInimigo;
}

Inimigo Cena::getInimigo() const {
    return inimigo;
}

// Métodos
void Cena::contarHistoria() {

    // Descrição da história
    cout << descricao;
}

Decisao Cena::escolherDecisao(Jogador &jogador) {

    while(true) {
        cout << "=================================================\n";
        cout << "0.  Abrir inventario\n";

        // Opções de escolha
        for (int i = 0; i < qntOpcoes; ++i) {
            cout << i + 1 << ". " << decisao[i].getDecisao() << endl;
        }
        cout << "=================================================\n";

        std::cout << "Escolha qual opção seguir: ";
        std::cin >> escolha;

        while (escolha < 0 || escolha > qntOpcoes) {
            std::cout << "Opção inválida, selecione novamente: ";
            std::cin >> escolha;
        }

        if (escolha == 0) {
            return Decisao(-1, "Abrir Inventário");
        }

        return decisao[escolha - 1];
    }
}

// DEBUG
void Cena::debugInimigo() const {
    if (temInimigo) {
        cout << "\n[DEBUG INIMIGO]" << endl;
        cout << "Nome: " << inimigo.getNome() << endl;
        cout << "Habilidade: " << inimigo.getHabilidade() << endl;
        cout << "Energia: " << inimigo.getEnergia() << endl;
        cout << "Sorte: " << inimigo.getSorte() << endl;
        cout << "Tesouro: " << inimigo.getTesouro().getValor() << endl;
        cout << "Provisão: " << inimigo.getQntProvisao() << endl;
        cout << "Capítulo se ganhar: " << inimigo.getCapSeGanhar() << endl;
        cout << "Capítulo se perder: " << inimigo.getCapSePerder() << endl;

        if (inimigo.getItem() != nullptr) {
            cout << "Item dropado: " << inimigo.getItem()->getNome() << endl;
        } else {
            cout << "Item dropado: Nenhum" << endl;
        }
        cout << "-------------------------" << endl;
    } else {
        cout << "[DEBUG INIMIGO] Nenhum inimigo nesta cena.\n";
    }
}

void Cena::debugItens() const {
    if (temItem) {
        item->debugItem();
    } else {
        cout << "[DEBUG ITEM] Nenhum item nesta cena." << endl;
    }
}
