#include "Menu.h"

Menu::Menu() {
	jogando = true;
}

Menu::~Menu() {}

void Menu::menuPrincipal() {

	int opcao;

	while (jogando) {

		std::cout << "\n-- MENU PRINCIPAL --" << std::endl;
		std::cout << "1 - Cadastrar aluno" << std::endl;
		std::cout << "2 - Cadastrar nota" << std::endl;
		std::cout << "3 - Calcular media de um aluno" << std::endl;
		std::cout << "4 - Listar os nomes dos alunos sem notas" << std::endl;
		std::cout << "5 - Excluir aluno" << std::endl;
		std::cout << "6 - Excluir nota" << std::endl;
		std::cout << "7 - Sair" << std::endl;
		std::cout << "\nEscolha uma opcao: ";
		std::cin >> opcao;

		switch (opcao) {

		case 1:
			cadastrarAluno();
			break;

		case 2:
			cadastrarNota();
			break;

		case 3:
			calcularMedia();
			break;

		case 4:
			listarAlunosSemNotas();
			break;
			
		case 5:
			excluirAluno();
			break;

		case 6:
			excluirNota();
			break;

		case 7:
			jogando = false;
			break;

		default:
			break;
		}
	}
	
}

void Menu::cadastrarAluno() {

	std::string nome;

	std::cout << "Informe o nome do aluno: ";
	std::cin >> nome;

	Aluno a(nome);

	pilhaAlunos.push(a);

	std::cout << "Aluno cadastrado: " << a.getNumero() << " - " << a.getNome() << std::endl;
}

void Menu::cadastrarNota() {

	int numero;

	std::cout << "Informe o numero do aluno: ";
	std::cin >> numero;

	if (pilhaAlunos.findByID(numero)) {
		
		float nota;

		std::cout << "Informe a nota: ";
		std::cin >> nota;

		Nota n(numero, nota);

		filaNotas.push_back(n);

		std::cout << "Nota cadastrada!" << std::endl;
	}

	else {
		std::cout << "Aluno nao cadastrado.\n";
		return;
	}
}

void Menu::calcularMedia() {

	int numero;

	std::cout << "Informe o numero do aluno: ";
	std::cin >> numero;

	if (!pilhaAlunos.findByID(numero)) {
		std::cout << "Aluno nao cadastrado.\n";
		return;
	}

	if (!filaNotas.findByNumAluno(numero)) {
		std::cout << "Aluno sem notas!\n";
		return;
	}

	// Calcular média
	float soma = 0;
	int qntNotas = 0;
	int tam = filaNotas.getTam();

	for (int i = 0; i < tam; i++) {
		Nota n = filaNotas.front();
		filaNotas.pop_front();

		if (n.getNumAluno() == numero) {
			soma += n.getNota();
			qntNotas++;
		}

		filaNotas.push_back(n); // Reinsere no final para manter a fila
	}

	float media = soma / qntNotas;
	std::cout << "Media do aluno = " << media << std::endl;
}

void Menu::listarAlunosSemNotas() {

	int qntAlunos = pilhaAlunos.getTam();
	bool encontrou = false;

	std::cout << "\nAlunos sem nota: " << std::endl;

	for (int i = 1; i <= qntAlunos; i++) {

		bool alunoComNotas = filaNotas.findByNumAluno(i);

		if (!alunoComNotas) {
			std::cout << i << " - " << pilhaAlunos.getNomeByID(i) << std::endl;
			encontrou = true;
		}
	}

	if (!encontrou) {
		std::cout << "Nao ha alunos sem notas.\n";
	}
}

void Menu::excluirAluno() {

	if (pilhaAlunos.empty()) {
		std::cout << "Pilha vazia!\n";
		return;
	}

	Aluno a = pilhaAlunos.top();
	int topo = a.getNumero();
	bool alunoComNotas = filaNotas.findByNumAluno(topo);

	if (alunoComNotas) {
		std::cout << "Este aluno possui notas!\n";
	}

	else {
		pilhaAlunos.pop();
		std::cout << "Aluno excluido!\n";
	}
}

void Menu::excluirNota() {

	if (filaNotas.empty()) {
		std::cout << "Fila vazia!\n";
	}

	else {
		filaNotas.pop_front(); 
		std::cout << "Nota excluida!\n";
	}
}