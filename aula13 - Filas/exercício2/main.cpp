#include <iostream>
#include <string>

#include "Fila.hpp"
#include "FilaComPrioridade.hpp"

using namespace std;

int main() {

	Fila<string> filaCarros;
	int opcao = 0;
	string placa;

	while (opcao != 4) {

		cout << "MENU DE ESTACIONAMENTO" << endl;
		cout << "1. Adicionar carro" << endl;
		cout << "2. Ver estacionamento" << endl;
		cout << "3. Remover carro" << endl;
		cout << "4. Sair" << endl;
		cout << "Escolha uma opcao: ";
		std::cin >> opcao;

		switch (opcao) {

		case 1:
			cout << endl;
			cout << "Digite a placa do carro a ser adicionado: ";
			std::cin >> placa;
			filaCarros.push_back(placa);
			cout << endl;
			break;

		case 2:
			cout << endl;
			
			if(filaCarros.empty()) {
				cout << "Estacionamento vazio." << endl;
			}
			else {
				cout << "Carros no estacionamento: " << endl;
				for (int i = 0; i < filaCarros.getTam(); i++) {
					cout << filaCarros.getDados(i) << endl;
				}
			}

			cout << endl;
			break;

		case 3:
			cout << endl;
			if (!filaCarros.empty()) {
				cout << "Digite a placa do carro a ser removido: ";
				std::cin >> placa;
				filaCarros.pop_ByElement(placa);
			}
			else {
				cout << "Estacionamento vazio." << endl;
			}
			cout << endl;
			break;

		case 4:
			cout << "Saindo do programa." << endl;
			break;

		default:
			cout << "Opcao invalida. Tente novamente." << endl;
			break;
		}
	}
	return 0;
}