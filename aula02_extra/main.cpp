#include <iostream>
#include <string>
#include <locale>
#include "Pais.hpp"

using namespace std;

void vizinhosComuns(Pais &a, Pais &b) {

    vector<string> vizinhosComuns = a.comparaFronteiras(b);

    cout << "Pa�ses vizinhos em comum entre " << a.getNome() << " e " << b.getNome() << endl;

    if(vizinhosComuns.empty()) {
        cout << "N�o h� pa�ses vizinhos em comum." << endl;
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
    Pais mexico("MEX", "M�xico", 1973000);
    Pais colombia("COL", "Col�mbia", 1142000);

    if(brasil.comparaPais(brasil)) {
        cout << "� o mesmo pa�s" << endl;
    } else {
        cout << "N�o � o mesmo pa�s" << endl;
    }

    if(brasil.comparaPais(argentina)) {
        cout << "� o mesmo pa�s" << endl;
    } else {
        cout << "N�o � o mesmo pa�s" << endl;
    }

    cout << "------" << endl;

    brasil.adicionarPaisFronteira(argentina);
    brasil.adicionarPaisFronteira(uruguai);
    argentina.adicionarPaisFronteira(uruguai);
    estados_unidos.adicionarPaisFronteira(mexico);
    colombia.adicionarPaisFronteira(brasil);

    if(brasil.verificaPaisFronteira(argentina)) {
        cout << "S�o pa�ses vizinhos" << endl;
    } else {
        cout << "N�o s�o pa�ses vizinhos" << endl;
    }

    if(uruguai.verificaPaisFronteira(argentina)) {
        cout << "S�o pa�ses vizinhos" << endl;
    } else {
        cout << "N�o s�o pa�ses vizinhos" << endl;
    }

    if(argentina.verificaPaisFronteira(estados_unidos)) {
        cout << "S�o pa�ses vizinhos" << endl;
    } else {
        cout << "N�o s�o pa�ses vizinhos" << endl;
    }

    cout << "------" << endl;

    estados_unidos.setPopulacao(340100000);

    cout << "A densidade demogr�fica dos EUA �: " << estados_unidos.densidade() << endl;
    cout << "A densidade demogr�fica do Brasil �: " << brasil.densidade() << endl;

    cout << "------" << endl;

    vizinhosComuns(brasil, argentina);
    vizinhosComuns(estados_unidos, brasil);

    return 0;
}
