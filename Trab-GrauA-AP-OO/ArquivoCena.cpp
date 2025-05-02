#include "ArquivoCena.hpp"

ArquivoCena::ArquivoCena() {

}

ArquivoCena::~ArquivoCena() {

}

Cena ArquivoCena::carregarCena(int id) {
    // Proteção contra ID inválido (ex: 0)
    if (id < 1) {
        std::cerr << "[ERRO] ID de cena inválido: " << id << std::endl;
        return Cena(); // retorna cena vazia
    }

    std::ifstream arqEntrada;
    string nomeArquivo = montarNomeArquivo(id);

    arqEntrada.open(nomeArquivo);
    if (!arqEntrada.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return Cena();
    }

    Cena cena;
    cena.setId(id);
    string linha;
    string descricao;

    getline(arqEntrada, linha);

    if (linha[0] == 'm') {
        // Cena de batalha
        while (getline(arqEntrada, linha) && !(linha.rfind("N:", 0) == 0)) {
            descricao += linha + "\n";
        }
        cena.setDescricao(descricao);

        Inimigo i = lerInimigo(arqEntrada, linha);
        cena.setInimigo(i);
        cena.setTemInimigo(true);
    }
    else {
        lerDescricao(arqEntrada, cena);
    }

    return cena;
}

string ArquivoCena::montarNomeArquivo(int id) {

    // Montando nome do arquivo
    stringstream ss;

    ss << id << ".txt";
    string nomeArquivo = ss.str();

    return nomeArquivo;
}

void ArquivoCena::lerDescricao(ifstream &arquivo, Cena &cena) {

    string linha;
    string descricao;
    bool descricaoLida = false;

    while(getline(arquivo, linha)) {

        // rfind(o que quer encontrar, posicao), retorna 0 se der certo

        if(linha.rfind("I:", 0) == 0) {
            Item* i = lerItem(linha.substr(3)); // remove o "I: "
            cena.setItem(i);
            cena.setTemItem(true);
            descricaoLida = true;
        }

        else if(linha.rfind("#", 0) == 0) {
            Decisao d = lerDecisao(linha);
            cena.setDecisao(d);
            cena.setTemDecisao(true);
        }

        else if(descricaoLida == false) {
            descricao += linha;
        }
    }
    descricao += "\n";
    cena.setDescricao(descricao);
}

Decisao ArquivoCena::lerDecisao(const string &linha) {

    Decisao d;
    stringstream ss(linha); // transforma a linha em stream para separar com delimitadores
    string parte;
    string descricao;

    // getline(leitura, localArmazenado, delimitador)

    getline(ss, parte, '#'); // para ignorar o #
    getline(ss, parte, ':'); // para ignorar o :
    d.setProxCenaId(stoi(parte)); // set id da proxima cena e transforma string para int
    getline(ss, descricao); // set descricao da decisao
    d.setDecisao(descricao);

    return d;
}

Item* ArquivoCena::lerItem(const string &linha) {

    stringstream ss(linha); // ignorar o "I: "
    string parte;

    // getline(leitura, localArmazenado, delimitador)
    // nome;tipo;combate;FA;dano

    string nome;
    char tipo;
    bool combate;
    int fa;
    int dano;

    // Nome
    getline(ss, nome, ';');
    // Tipo
    getline(ss, parte, ';');
    tipo = parte[0];
    // Combate (bool)
    getline(ss, parte, ';');
    combate = stoi(parte);
    // FA
    getline(ss, parte, ';');
    fa = stoi(parte);
    // Dano (ou Cura)
    getline(ss, parte);
    dano = stoi(parte);

    // W = ARMA
    // R = ARMADURA
    // C = ITEM COMUM
    // M = MAGIA

    // Exemplo de Ferramenta
    // I: Espada Flamejante;w;1;2;4

    if(tipo=='w' || tipo=='r') {
        Item* i = new Ferramenta(nome, tipo, combate, fa, dano);
        return i;
    }

    // Exemplo de Magia
    // I: Luz Ardente;m;0;0;6

    else if(tipo=='m') {
        Item* i = new Magia(nome, dano);
        return i;
    }

    // Exemplo de Item comum
    // I: Chifre do Minotauro;c;0;0;0

    else if(tipo=='c') {
        Item* i = new ItemComum(nome);
        return i;
    }

    return nullptr; // retorna vazio
}

Inimigo ArquivoCena::lerInimigo(ifstream &arquivo, const string &linhaInicial) {

    Inimigo inimigo;
    string linha = linhaInicial;

    while(true) {

        // rfind(o que quer encontrar, posicao) -> retorna 0 se der certo
        // substr(posicao) -> substring da linha a partir da posicao que indicar

        // Leitura dos dados do inimigo
        // Nome
        if (linha.rfind("N:", 0) == 0) {
            string nome = linha.substr(3); // Substring a partir do índice 3
            // Remove espaços no começo e no fim usando o método erase
            nome.erase(0, nome.find_first_not_of(" \t\n\r"));  // Remove espaços no começo
            nome.erase(nome.find_last_not_of(" \t\n\r") + 1);  // Remove espaços no final
            inimigo.setNome(nome);
        }
        // Habilidade
        else if(linha.rfind("H:", 0) == 0) inimigo.setHabilidade(stoi(linha.substr(3)));
        // Energia
        else if(linha.rfind("E:", 0) == 0) inimigo.setEnergia(stoi(linha.substr(3)));
        // Sorte
        else if(linha.rfind("S:", 0) == 0) inimigo.setSorte(stoi(linha.substr(3)));
        // Tesouro
        else if(linha.rfind("T:", 0) == 0) inimigo.setTesouro(stoi(linha.substr(3)));
        // Provisão
        else if(linha.rfind("P:", 0) == 0) inimigo.setQntProvisao(stoi(linha.substr(3)));
        // Item (Ferramenta)
        else if(linha.rfind("I:", 0) == 0) {
            Item* i = lerItem(linha.substr(3));
            inimigo.setItem(i);
        }
        // Capítulos se perder/ganhar
        else {
            stringstream ss(linha);
            string parte;
            // Se ganhar (antes do ;)
            getline(ss, parte, ';');
            inimigo.setCapSeGanhar(stoi(parte));
            // Se perder (depois do ;)
            getline(ss, parte);
            inimigo.setCapSeperder(stoi(parte));
        }

        if(!(getline(arquivo, linha))) break;
    }

    return inimigo;
}

