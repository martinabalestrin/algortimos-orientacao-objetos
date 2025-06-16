#pragma once

#include <iostream>
#include <string>

#include "PilhaAluno.hpp"
#include "Aluno.h"
#include "FilaNota.hpp"
#include "Nota.h"

class Menu {

public:
	Menu();
	~Menu();

	void menuPrincipal();
	void cadastrarAluno();
	void cadastrarNota();
	void calcularMedia();
	void listarAlunosSemNotas();
	void excluirAluno();
	void excluirNota();

private:
	PilhaAluno pilhaAlunos;
	FilaNota filaNotas;
	bool jogando;
};
