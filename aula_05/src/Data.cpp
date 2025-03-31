#include "Data.hpp"
#include <iostream>

using namespace std;

Data::Data() {

}

Data::Data(int dia, int mes, int ano):
    dia(dia), mes(mes), ano(ano) {

}

Data::~Data() {

}

int Data::getDia() {
    return dia;
}

int Data::getMes() {
    return mes;
}

int Data::getAno() {
    return ano;
}

void Data::imprime_info() {
    cout << "Data: " << getDia() << "/" << getMes() << "/" << getAno() << endl;
}
