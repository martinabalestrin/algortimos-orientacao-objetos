#pragma once

#include <iostream>
#include "Aluno.h"

class Nota {

public:
	Nota();
	Nota(int numAluno, float nota);
	~Nota();

	float getNota() { return nota; }
	int getNumAluno() { return numAluno; }

private:
	int numAluno;
	float nota;
};