#include "../include/apartamento.h"

Apartamento::Apartamento() : Imovel(), andar(0) {}

Apartamento::Apartamento(const std::string& endereco, double precoBase,
                         bool eNovo, int andar)
    : Imovel(endereco, APARTAMENTO, precoBase, eNovo), andar(andar) {}

int Apartamento::getAndar() const { return andar; }
void Apartamento::setAndar(int novoAndar) { andar = novoAndar; }

// Implementação do método abstrato
void Apartamento::exibirDetalhes() const {
  std::cout << "Apartamento no endereço: " << getEndereco() << "\n";
  std::cout << "Preco: " << precoFinal() << "\n";
  std::cout << (isNovo() ? "Imovel Novo" : "Imovel Velho") << "\n";
  if (isNovo()) {
    std::cout << "Prazo de Garantia: " << getPrazoGarantia() << " meses\n";
  } else {
    std::cout << "Ultimo Dono: " << getUltimoDono() << "\n";
  }
  std::cout << "Andar: " << andar << "\n";
}