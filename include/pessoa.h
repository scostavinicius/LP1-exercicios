#ifndef PESSOA_H
#define PESSOA_H

#include <string.h>

#include <string>

class Pessoa {
 protected:
  std::string nome;
  int idade;

 public:
  // Construtor, construtor cópia e destrutor
  Pessoa(const std::string &n, int i);
  Pessoa(const Pessoa &p);
  ~Pessoa();

  // Getters e setters
  std::string getNome() const;
  void setNome(const std::string &n);

  int getIdade() const;
  void setIdade(int i);
};

#endif