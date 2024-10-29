#include "../include/pessoa.h"

// Definições do construtor, construtor cópia e destrutor
// Parâmetros: std::string nome; int idade;
Pessoa::Pessoa(const std::string& n, int i) :
	nome(n),
	idade(i) {}

Pessoa::Pessoa(const Pessoa& p) :
	nome(p.nome),
	idade(p.idade) {}


Pessoa::~Pessoa() {}

// Getters 
std::string Pessoa::getNome() const {
	return nome;
}

int Pessoa::getIdade() const {
	return idade;
}

// Setters
void Pessoa::setNome(const std::string& n) {
	nome = n;
}

void Pessoa::setIdade(int i) {
	idade = i;
}