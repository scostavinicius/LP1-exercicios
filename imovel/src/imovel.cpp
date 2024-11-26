#include "../include/imovel.h"

Imovel::Imovel()
    : endereco(""),
      tipoImovel(CASA),
      precoBase(0.0),
      eNovo(true),
      prazoGarantia(12),
      ultimoDono("") {}

Imovel::Imovel(const std::string& endereco, TipoImovel tipoImovel,
               double precoBase, bool eNovo)
    : endereco(endereco),
      tipoImovel(tipoImovel),
      precoBase(precoBase),
      eNovo(eNovo),
      prazoGarantia(eNovo ? 12 : 0),
      ultimoDono(eNovo ? "" : "Desconhecido") {}

Imovel::Imovel(const Imovel& i)
    : endereco(i.endereco),
      tipoImovel(i.tipoImovel),
      precoBase(i.precoBase),
      eNovo(i.eNovo),
      prazoGarantia(i.prazoGarantia),
      ultimoDono(i.ultimoDono) {}

std::string Imovel::getEndereco() const { return endereco; }
void Imovel::setEndereco(const std::string& novoEndereco) {
  endereco = novoEndereco;
}

TipoImovel Imovel::getTipo() const { return tipoImovel; }
void Imovel::setTipo(const TipoImovel novoTipo) { tipoImovel = novoTipo; }

double Imovel::getPrecoBase() const { return precoBase; }
void Imovel::setPrecoBase(double novoPrecoBase) { precoBase = novoPrecoBase; }

bool Imovel::isNovo() const { return eNovo; }
void Imovel::setNovo(bool novo) {
  eNovo = novo;
  if (eNovo) {
    prazoGarantia = 12;
    ultimoDono = "";
  } else {
    prazoGarantia = 0;
    ultimoDono = "Desconhecido";
  }
}

int Imovel::getPrazoGarantia() const {
  if (!eNovo) {
    throw std::logic_error("Imóveis velhos não possuem prazo de garantia.");
  }
  return prazoGarantia;
}

void Imovel::setPrazoGarantia(int novoPrazo) {
  if (!eNovo) {
    throw std::logic_error("Imóveis velhos não podem ter prazo de garantia.");
  }
  prazoGarantia = novoPrazo;
}

std::string Imovel::getUltimoDono() const {
  if (eNovo) {
    throw std::logic_error("Imóveis novos não possuem último dono.");
  }
  return ultimoDono;
}

void Imovel::setUltimoDono(const std::string& novoUltimoDono) {
  if (eNovo) {
    throw std::logic_error("Imóveis novos não podem ter último dono.");
  }
  ultimoDono = novoUltimoDono;
}

double Imovel::precoFinal() const {
  if (!eNovo) {
    return precoBase * 0.9;
  }
  return precoBase;
}