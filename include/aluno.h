#ifndef ALUNO_H
#define ALUNO_H

#include <string.h>
#include <string>
#include "pessoa.h"

class Aluno : public Pessoa
{
private:
	// Herda nome e idade de Pessoa
	int matricula;
	int periodo;
	std::string curso;

public:
	// Construtor, construtor cópia e destrutor 
	// O construtor deve chamar o construtor de Pessoa para os atributos n (nome) e i (idade)
	// O construtor cópia de Aluno deve chamar o construtor cópia de Pessoa
	Aluno(const std::string& n, int i, int m, int p, const std::string& c);
	Aluno(const Aluno& a);
	~Aluno();

	// Getters e Setters 
	// Eles serão definidos aqui para os atributos de Aluno, que herda nome e idade de Pessoa
	int getMatricula() const;
	void setMatricula(int m);

	int getPeriodo() const;
	void setPeriodo(int p);

	std::string getCurso() const;
	void setCurso(const std::string& c);
};

#endif