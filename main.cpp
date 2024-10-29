#include <iostream>
#include "include/aluno.h"

int main(int argc, char const *argv[])
{
	Aluno aluno("Carlos", 19, 123456, 2, "BTI");

	std::cout << "Nome: " << aluno.getNome() << std::endl;
	std::cout << "Idade: " << aluno.getIdade() << std::endl;
	std::cout << "Matricula: " << aluno.getMatricula() << std::endl;
	std::cout << "Período: " << aluno.getPeriodo() << std::endl;
	std::cout << "Curso: " << aluno.getCurso() << std::endl;

	return 0;
}