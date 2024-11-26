#include "../include/turma.h"

#include <algorithm>

Turma::Turma() : disciplina(""), codTurma("") {}

Turma::Turma(const std::string &d, const std::string &ct,
             const std::vector<Aluno> &la)
    : disciplina(d), codTurma(ct), alunos(la) {}

Turma::Turma(const Turma &t)
    : disciplina(t.getDisciplina()),
      codTurma(t.getCodTurma()),
      alunos(t.getAlunos()) {}

Turma::~Turma() {}

// Getters
std::string Turma::getDisciplina() const { return disciplina; }

std::string Turma::getCodTurma() const { return codTurma; }

const std::vector<Aluno> &Turma::getAlunos() const { return alunos; }

// Setters
void Turma::setDisciplina(const std::string &d) { disciplina = d; }

void Turma::setCodTurma(const std::string &ct) { codTurma = ct; }

void Turma::setAlunos(const std::vector<Aluno> &la) { alunos = la; }

// Métodos
void Turma::listarAlunos() {
  if (alunos.empty()) {
    std::cout << "Nao ha alunos cadastrados na turma." << std::endl;
    return;
  }

  std::cout << "Nome da disciplina: " << disciplina << std::endl;
  std::cout << "Codigo da turma: " << codTurma << std::endl;
  for (const Aluno &aluno : alunos) {
    std::cout << "Nome: " << aluno.getNome() << ", Idade: " << aluno.getIdade()
              << ", Matricula: " << aluno.getMatricula()
              << ", Periodo: " << aluno.getPeriodo()
              << ", Curso: " << aluno.getCurso() << std::endl;
  }
}

void Turma::adicionarAluno(const Aluno &aluno) { alunos.push_back(aluno); }

void Turma::removerAlunoPorMat(int mat) {
  // Usar um iterador para Aluno para o aluno a ser removido
  // Usa uma expressão lambda que captura a variável mat com argumento aluno
  // para retornar o iterador para alunoRemovido
  std::vector<Aluno>::iterator alunoRemovido = std::find_if(
      alunos.begin(), alunos.end(),
      [mat](const Aluno &aluno) { return aluno.getMatricula() == mat; });

  // Se o aluno foi encontrado, ele é removido através da função erase
  // Ca
  if (alunoRemovido != alunos.end()) {
    std::cout << "Aluno encontrado!" << std::endl;
    std::cout << "Nome: " << alunoRemovido->getNome()
              << ", Idade: " << alunoRemovido->getIdade()
              << ", Matricula: " << alunoRemovido->getMatricula()
              << ", Periodo: " << alunoRemovido->getPeriodo()
              << ", Curso: " << alunoRemovido->getCurso() << std::endl;
    std::cout << "Removendo aluno..." << std::endl;
    alunos.erase(alunoRemovido);
    std::cout << "Aluno removido com sucesso!!!" << std::endl;
  } else {
    std::cout << "O aluno a ser removido nao foi encontrado!" << std::endl;
  }
}