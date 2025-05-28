#include <iostream>
#include <string>

#include "Pilha.hpp"

using namespace std;

int main() {

	Pilha<char> pilha;
	string formula;
	int continuar = 1;


	do {

		if (!pilha.empty()) {
			pilha.clear(); // Limpa a pilha antes de cada nova expressão
		}

		bool erro = false;
		
		cout << "Digite uma expressao aritmetica: ";
		getline(cin, formula);

		for (int i = 0; i < formula.length(); i++) {

			char c = formula[i];

			if (c == '(' || c == '[' || c == '{') {
				pilha.push(c);
			}

			else if (c == ')' || c == ']' || c == '}') {

				if (pilha.empty()) {
					cout << "Expressao invalida: " << c << " nao possui correspondente." << endl;
					erro = true;
					break;
				}

				else {
					char topo = pilha.top();

					cout << "Caracter: " << c << endl;
					cout << "Topo da pilha: " << topo << endl;

					if ((c == ')' && topo != '(') ||
						(c == ']' && topo != '[') ||
						(c == '}' && topo != '{')) {
						cout << "Expressao invalida: " << c << " nao possui correspondente." << endl;
						erro = true;
						break;
					}

					pilha.pop();
				}
			}
		}

		if (!erro && !pilha.empty()) {
			cout << "Expressao invalida: Parenteses nao balanceados." << endl;
			erro = true;
		}

		if (!erro) {
			cout << "Expressao valida." << endl;
		}

		cout << "Deseja continuar? (1 - Sim, 0 - Nao): ";
		cin >> continuar;
		cin.ignore(); // Limpa o buffer do cin para evitar problemas com getline na proxima iteração
	
	} while (continuar == 1);

	return 0;
}