#include "Aluno.h"

Aluno::Aluno() {}

Aluno::Aluno(std::string nome) : nome(nome), numero(proximoNumero++) {}

Aluno::~Aluno() {}

int Aluno::proximoNumero = 1;