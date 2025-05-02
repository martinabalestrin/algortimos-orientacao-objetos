#ifndef DADO_HPP
#define DADO_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class dado {
public:
	dado();
	int sortear(int min, int max);
	int rolar();
	bool testarSorte(int valor);
};

#endif
