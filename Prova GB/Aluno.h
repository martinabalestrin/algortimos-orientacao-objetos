#pragma once

#include <iostream>
#include <string>

class Aluno {

public:
	Aluno();
	Aluno(std::string nome);
	~Aluno();

	int getNumero() { return numero; }
	std::string getNome() { return nome; }

private:
	std::string nome;
	int numero;    
	static int proximoNumero;
};