#ifndef TURMA_H
#define TURMA_H

#include <iostream>
#include <vector>

#include "aluno.h"

class Turma {
 private:
  std::string disciplina;
  std::string codTurma;
  std::vector<Aluno> alunos;

 public:
  // Construtores
  Turma();
  Turma(const std::string &d, const std::string &ct,
        const std::vector<Aluno> &la);
  Turma(const Turma &t);
  ~Turma();

  // Getters e Setters
  std::string getDisciplina() const;
  void setDisciplina(const std::string &d);

  std::string getCodTurma() const;
  void setCodTurma(const std::string &ct);

  const std::vector<Aluno> &getAlunos() const;
  void setAlunos(const std::vector<Aluno> &la);

  // Métodos
  void listarAlunos();
  void adicionarAluno(const Aluno &aluno);
  void removerAlunoPorMat(int mat);
};

#endif