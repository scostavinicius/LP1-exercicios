#include <iostream>

#include "include/turma.h"

int main(int argc, char const *argv[]) {
  Aluno carlos = Aluno("carlos", 20, 123, 2, "BTI");
  Aluno jessica = Aluno("jessica", 18, 423, 1, "BTI");
  Aluno jose = Aluno("jose", 21, 242, 6, "BTI");
  Aluno adriana = Aluno("adriana", 20, 346, 2, "BTI");
  Aluno joao = Aluno("joao", 22, 678, 4, "BTI");

  Turma turma;

  turma.setDisciplina("FMC");
  turma.setCodTurma("IMD-1014");

  turma.adicionarAluno(carlos);
  turma.adicionarAluno(jessica);
  turma.adicionarAluno(jose);
  turma.adicionarAluno(adriana);
  turma.adicionarAluno(joao);

  std::cout << "-----Primeira listagem-----" << std::endl << std::endl;
  turma.listarAlunos();
  std::cout << "-------------------------------" << std::endl << std::endl;

  std::cout << "-----Remocao de joao-----" << std::endl << std::endl;
  turma.removerAlunoPorMat(678);
  std::cout << "-------------------------------" << std::endl << std::endl;

  std::cout << "-----Listagem apos a remocao de joao-----";
  turma.listarAlunos();
  std::cout << "-------------------------------" << std::endl << std::endl;

  Aluno marcos = Aluno("marcos", 24, 001, 7, "BTI");
  turma.adicionarAluno(marcos);
  std::cout << "-----Listagem apos adicao de marcos-----";
  turma.listarAlunos();

  return 0;
}