#include "../include/aluno.h"

// Definições do construtor, construtor cópia e do destrutor
// Parâmetros herdados de Pessoa: str::string nome; int idade;
// Parâmetros de Aluno: int matricula; int periodo; std::string curso;
Aluno::Aluno(const std::string &n, int i, int m, int p, const std::string &c)
    : Pessoa(n, i),  // Chama o construtor de Pessoa para atribuir nome e idade
      matricula(m),
      periodo(p),
      curso(c) {}

Aluno::Aluno(const Aluno &a)
    : Pessoa(a),
      matricula(a.getMatricula()),
      periodo(a.getPeriodo()),
      curso(a.getCurso()) {}

Aluno::~Aluno() {}

// Getters
int Aluno::getMatricula() const { return matricula; }

int Aluno::getPeriodo() const { return periodo; }

std::string Aluno::getCurso() const { return curso; }

// Setters
void Aluno::setMatricula(int m) { matricula = m; }

void Aluno::setPeriodo(int p) { periodo = p; }

void Aluno::setCurso(const std::string &c) { curso = c; }