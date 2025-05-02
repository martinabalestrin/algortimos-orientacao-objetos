#include "Inventario.hpp"
#include <iostream>
#include <sstream>

Inventario::Inventario() : quantidade(0) {
    for (int i = 0; i < 10; ++i) {
        itens[i] = nullptr;
    }
    qntProvisao = 0;
}

Inventario::~Inventario() {
    for (int i = 0; i < quantidade; ++i) {
        delete itens[i];
    }
}

void Inventario::adicionarItem(Item* item) {
    if (quantidade < 10) {
        itens[quantidade++] = item;
        std::cout << "=================================================\n";
        std::cout << "Item adicionado: " << item->getNome() << std::endl;
        std::cout << "=================================================\n";
    }
    else {
        std::cout << "Inventário cheio." << std::endl;
    }
}

void Inventario::removerItemPorNome(const std::string& nomeItem) {
    for (int i = 0; i < quantidade; ++i) {
        if (itens[i]->getNome() == nomeItem) {
            delete itens[i];
            for (int j = i; j < quantidade - 1; ++j) {
                itens[j] = itens[j + 1];
            }
            itens[--quantidade] = nullptr;
            std::cout << "Item \"" << nomeItem << "\" removido com sucesso." << std::endl;
            return;
        }
    }
    std::cout << "Item \"" << nomeItem << "\" nao encontrado." << std::endl;
}

void Inventario::mostrar() const {
    std::cout << "Inventario:\n";

    int totalTesouro = 0;
    int totalProvisao = qntProvisao;

    for (int i = 0; i < quantidade; ++i) {
        if (auto* t = dynamic_cast<Tesouro*>(itens[i])) {
            totalTesouro += t->getValor();
        }
        else if (auto* f = dynamic_cast<Ferramenta*>(itens[i])) {
            std::cout << "- Ferramenta: " << f->getNome() << "\n";
        }
        else if (auto* m = dynamic_cast<Magia*>(itens[i])) {
            std::cout << "- Magia: " << m->getNome() << " (Dano: " << m->getDano() << ")\n";
        }
        else if (auto* iC = dynamic_cast<ItemComum*>(itens[i])) {
            std::cout << "- Item: " << iC->getNome() << "\n";
        }
    }

    if (totalTesouro > 0)
        std::cout << "- Tesouro: " << totalTesouro << " moedas de ouro\n";

    if (totalProvisao > 0)
        std::cout << "- Provisão: " << totalProvisao << " de energia\n";

    if (quantidade == 0 && qntProvisao == 0)
        std::cout << "Sem itens no inventario\n";
}

void Inventario::salvarParaArquivo(const std::string& nomeArquivo) const {
    std::ofstream out(nomeArquivo);
    if (!out.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para escrita." << std::endl;
        return;
    }

    salvarParaArquivo(out); // chamada à versão com ostream
    out.close();
}

void Inventario::carregarDeArquivo(const std::string& nomeArquivo) {
    std::ifstream in(nomeArquivo);
    if (!in.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para leitura." << std::endl;
        return;
    }

    carregarDeArquivo(in); // chamada à versão com istream
    in.close();
}

std::vector<Magia> Inventario::getMagias() const {
    std::vector<Magia> magias;
    for (int i = 0; i < quantidade; ++i) {
        if (auto* magia = dynamic_cast<Magia*>(itens[i])) {
            magias.push_back(*magia);
        }
    }
    return magias;
}

int Inventario::getQntProvisao() const {
    return qntProvisao;
}

void Inventario::adicionaProvisao(int qnt) {
    qntProvisao += qnt;
    if (qntProvisao > 15) qntProvisao = 15; // limite para evitar bugs
    if (qntProvisao < 0) qntProvisao = 0;
}

// NOVAS FUNÇÕES PARA SALVAR/CARREGAR VIA STREAM

void Inventario::salvarParaArquivo(std::ostream& out) const {
    for (int i = 0; i < quantidade; ++i) {
        if (auto* t = dynamic_cast<Tesouro*>(itens[i])) {
            out << "TESOURO " << t->getNome() << "|" << t->getValor() << "\n";
        }
        else if (auto* p = dynamic_cast<Provisao*>(itens[i])) {
            out << "PROVISAO " << p->getNome() << "|" << p->energia() << "\n";
        }
        else if (auto* m = dynamic_cast<Magia*>(itens[i])) {
            out << "MAGIA " << m->getNome() << "|" << m->getDano() << "\n";
        }
        else if (auto* f = dynamic_cast<Ferramenta*>(itens[i])) {
            out << "FERRAMENTA " << f->getNome() << "|" << f->getTipo() << "|" << f->isCombate()
                << "|" << f->getBonusFA() << "|" << f->getDano() << "\n";
        }
    }
}

void Inventario::carregarDeArquivo(std::istream& in) {
    for (int i = 0; i < quantidade; ++i) {
        delete itens[i];
        itens[i] = nullptr;
    }
    quantidade = 0;

    std::string linha;
    while (std::getline(in, linha)) {
        if (linha.empty()) break;

        std::istringstream ss(linha);
        std::string tipo;
        ss >> tipo;

        if (tipo == "TESOURO") {
            std::string nome;
            int valor;
            std::getline(ss >> std::ws, nome, '|');
            ss >> valor;
            adicionarItem(new Tesouro(nome, valor));
        }
        else if (tipo == "PROVISAO") {
            std::string nome;
            int energia;
            std::getline(ss >> std::ws, nome, '|');
            ss >> energia;
            adicionarItem(new Provisao(nome, energia));
        }
        else if (tipo == "MAGIA") {
            std::string nome;
            int dano;
            std::getline(ss >> std::ws, nome, '|');
            ss >> dano;
            adicionarItem(new Magia(nome, dano));
        }
        else if (tipo == "FERRAMENTA") {
            std::string nome;
            char tipoFerramenta;
            bool combate;
            int bonusFA, dano;

            std::getline(ss >> std::ws, nome, '|');
            ss >> tipoFerramenta;
            ss.ignore(); // ignora '|'
            ss >> combate;
            ss.ignore(); // ignora '|'
            ss >> bonusFA;
            ss.ignore(); // ignora '|'
            ss >> dano;

            adicionarItem(new Ferramenta(nome, tipoFerramenta, combate, bonusFA, dano));
        }
    }
}

Item* Inventario::getItem(int index) const {
    if (index >= 0 && index < quantidade) {
        return itens[index];
    }
    return nullptr;
}

int Inventario::getQuantidade() const {
    return quantidade;
}

std::vector<Ferramenta> Inventario::getFerramentas() const {
    std::vector<Ferramenta> ferramentas;
    for (int i = 0; i < quantidade; ++i) {
        if (auto* f = dynamic_cast<Ferramenta*>(itens[i])) {
            ferramentas.push_back(*f);
        }
    }
    return ferramentas;
}
