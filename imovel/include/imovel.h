#ifndef IMOVEL_H
#define IMOVEL_H

#include <iostream>
#include <stdexcept>
#include <string>

enum TipoImovel { CASA, APARTAMENTO };

class Imovel {
 protected:
  std::string endereco;
  TipoImovel tipoImovel;
  double precoBase;
  bool eNovo;
  // Atributos condicionais
  int prazoGarantia;
  std::string ultimoDono;

 public:
  Imovel();
  Imovel(const std::string& endereco, TipoImovel tipoImovel, double precoBase,
         bool eNovo);
  Imovel(const Imovel& i);
  // Destruidor virtual que será substituído pelo destruidor da classe base
  virtual ~Imovel() = default;

  std::string getEndereco() const;
  void setEndereco(const std::string& novoEndereco);

  TipoImovel getTipo() const;
  void setTipo(TipoImovel novoTipo);

  double getPrecoBase() const;
  void setPrecoBase(double novoPrecoBase);

  bool isNovo() const;
  void setNovo(bool novo);

  // Getters e Setters dos atributos condicionais. Eles dependem do valor de
  // eNovo para terem seus valores definidos
  int getPrazoGarantia() const;
  void setPrazoGarantia(int novoPrazo);

  std::string getUltimoDono() const;
  void setUltimoDono(const std::string& novoUltimoDono);

  double precoFinal() const;
  // Método virtual para definir Imovel como classe abstrata
  virtual void exibirDetalhes() const = 0;
};

#endif