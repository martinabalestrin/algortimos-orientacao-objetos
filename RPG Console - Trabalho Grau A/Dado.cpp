#include "Dado.hpp"
#include <cstdlib>
#include <ctime>

dado::dado(){
	std::srand(std::time(nullptr));
}

int dado::sortear(int min, int max) {
	return min + (std::rand() % (max - min + 1));
}

int dado::rolar() {
	return sortear(1, 10);
}

bool dado::testarSorte(int valor) {
	int resultado = rolar() + rolar();
	return resultado <= valor;
}