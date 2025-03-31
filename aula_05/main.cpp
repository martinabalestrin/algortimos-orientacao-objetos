#include <iostream>
#include <locale.h>
#include "Atleta.hpp"
#include "Data.hpp"
#include "Nadador.hpp"
#include "Corredor.hpp"
#include "Competicao.hpp"
#include "InformacoesAtleta.hpp"
#include "Fruta.hpp"
#include "Banana.hpp"
#include "Melancia.hpp"
#include "Pessoa.hpp"
#include "Programador.hpp"
#include "Aluno.hpp"

using namespace std;

int main2() {

    setlocale(LC_ALL, "Portuguese");

    Atleta a1("Martina", 19);
    Nadador n(&a1, "Borboleta");
    n.imprime_info();

    cout << "-------------" << endl;

    Data data(30,03,2025);
    Competicao competicao("Uma corrida aí", &data, "Usina do Gasômetro");

    Atleta a2("Júlia", 20);
    Corredor c(&a2, 57.9, &competicao);
    c.imprime_info();

    cout << "-------------" << endl;

    InformacoesAtleta infos;
    infos.imprime_exclusivos_atleta(&n);
    infos.imprime_exclusivos_atleta(&c);

    cout << "-------------" << endl;

    infos.imprime_informacoes_atleta(&a1);
    infos.imprime_informacoes_atleta(&a2);

    cout << "-------------" << endl;

    Banana b(12, "Prata");
    cout << "BANANA" << endl;
    cout << "Preço: " << b.getPreco() << endl;
    cout << "Tipo: " << b.getTipo() << endl;
    cout << "Preço com imposto (10%): " << b.calcula_preco(10) << endl;

    cout << "-------------" << endl;

    Melancia m(15, 3, true); // está na época da melancia
    cout << "MELANCIA - Em época" << endl;
    cout << "Preço: " << m.getPreco() << endl;
    cout << "Preço Adicional: " << m.getPrecoAdicional() << endl;
    cout << "Preço com imposto (15%): " << m.calcula_preco_final(15) << endl;

    cout << "-------------" << endl;

    Melancia m2(15, 3, false); // NÃO está na época da melancia
    cout << "MELANCIA - Fora de época" << endl;
    cout << "Preço: " << m2.getPreco() << endl;
    cout << "Preço Adicional: " << m2.getPrecoAdicional() << endl;
    cout << "Preço com imposto (15%): " << m2.calcula_preco_final(15) << endl;

    cout << "-------------" << endl;

    Pessoa p("Haewon", 22);
    Programador pg(&p, "Java");
    pg.imprime_dados();

    cout << "-------------" << endl;

    Pessoa p2("Sullyoon", 21);
    Aluno aluno(&p2, 9.7);
    aluno.imprime_dados();

    cout << "-------------" << endl;

    Aluno aluno2(&p, 9.8);
    aluno2.imprime_dados();

    cout << "-------------" << endl;

    cout << "Pessoa(s): " << p.getContador() << endl;

    return 0;
}

int main() {

    setlocale(LC_ALL, "Portuguese");

    string nome;
    int idade;
    int tipoPessoa;

    cout << "Vamos criar uma Pessoa!\n\nInforme o nome: " << endl;
    cin >> nome;

    cout << "\nInforme a idade: " << endl;
    cin >> idade;

    Pessoa umaPessoa(nome, idade);

    cout << "\nSe a pessoa for um Programador, digite 1. Se a pessoa for um Aluno, digite 2." << endl;
    cin >> tipoPessoa;

    if(tipoPessoa == 1) {

        string linguagem;

        cout << "\nInforme a linguagem preferida desta pessoa: " << endl;
        cin >> linguagem;

        Programador programador(&umaPessoa, linguagem);
        cout << "\n------\n" << endl;
        programador.imprime_dados();
    }

    else if(tipoPessoa == 2) {

        double nota;

        cout << "\nInforme a nota desta pessoa: " << endl;
        cin >> nota;

        Aluno aluno(&umaPessoa, nota);
        cout << "\n------\n" << endl;
        aluno.imprime_dados();
    }

    else {
        cout << "Erro. Entrada inválida." << endl;
    }

    return 0;
}
