#include <iostream>
#include <string>
#include <locale>
#include "Pais.hpp"

using namespace std;

void vizinhosComuns(Pais &a, Pais &b) {

    vector<string> vizinhosComuns = a.comparaFronteiras(b);

    cout << "Países vizinhos em comum entre " << a.getNome() << " e " << b.getNome() << endl;

    if(vizinhosComuns.empty()) {
        cout << "Não há países vizinhos em comum." << endl;
    }

    else {
        for(size_t i=0; i<vizinhosComuns.size(); i++) {
            cout << "- " << vizinhosComuns[i] << endl;
        }
    }
}

int main() {

    setlocale(LC_ALL, "Portuguese");

    Pais brasil("BRA", "Brasil", 8510000);
    Pais argentina("ARG", "Argentina", 2780000);
    Pais uruguai("URY", "Uruguai", 176215);
    Pais estados_unidos("USA", "Estados Unidos", 9867000);
    Pais mexico("MEX", "México", 1973000);
    Pais colombia("COL", "Colômbia", 1142000);

    if(brasil.comparaPais(brasil)) {
        cout << "É o mesmo país" << endl;
    } else {
        cout << "Não é o mesmo país" << endl;
    }

    if(brasil.comparaPais(argentina)) {
        cout << "É o mesmo país" << endl;
    } else {
        cout << "Não é o mesmo país" << endl;
    }

    cout << "------" << endl;

    brasil.adicionarPaisFronteira(argentina);
    brasil.adicionarPaisFronteira(uruguai);
    argentina.adicionarPaisFronteira(uruguai);
    estados_unidos.adicionarPaisFronteira(mexico);
    colombia.adicionarPaisFronteira(brasil);

    if(brasil.verificaPaisFronteira(argentina)) {
        cout << "São países vizinhos" << endl;
    } else {
        cout << "Não são países vizinhos" << endl;
    }

    if(uruguai.verificaPaisFronteira(argentina)) {
        cout << "São países vizinhos" << endl;
    } else {
        cout << "Não são países vizinhos" << endl;
    }

    if(argentina.verificaPaisFronteira(estados_unidos)) {
        cout << "São países vizinhos" << endl;
    } else {
        cout << "Não são países vizinhos" << endl;
    }

    cout << "------" << endl;

    estados_unidos.setPopulacao(340100000);

    cout << "A densidade demográfica dos EUA é: " << estados_unidos.densidade() << endl;
    cout << "A densidade demográfica do Brasil é: " << brasil.densidade() << endl;

    cout << "------" << endl;

    vizinhosComuns(brasil, argentina);
    vizinhosComuns(estados_unidos, brasil);

    return 0;
}
