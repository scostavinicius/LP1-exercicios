#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "imovel.h"

class Apartamento : public Imovel {
 private:
  int andar;

 public:
  Apartamento();
  Apartamento(const std::string& endereco, double precoBase, bool eNovo,
              int andar);
  Apartamento(const Apartamento& a);
  virtual ~Apartamento() = default;

  int getAndar() const;
  void setAndar(int novoNumeroAndar);

  void exibirDetalhes() const override;
};

#endif