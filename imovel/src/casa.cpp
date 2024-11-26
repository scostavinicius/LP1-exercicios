#include "../include/casa.h"

Casa::Casa() : Imovel(), tipoTelha(CERAMICA) {}

Casa::Casa(const std::string& endereco, double precoBase, bool eNovo,
           TipoTelha tipoTelha)
    : Imovel(endereco, CASA, precoBase, eNovo), tipoTelha(tipoTelha) {}

TipoTelha Casa::getTipoTelha() const { return tipoTelha; }
void Casa::setTipoTelha(TipoTelha novoTipo) { tipoTelha = novoTipo; }

// Implementação do método abstrato
void Casa::exibirDetalhes() const {
  std::cout << "Casa no endereco: " << getEndereco() << "\n";
  std::cout << "Preco: " << precoFinal() << "\n";
  std::cout << (isNovo() ? "Imovel Novo" : "Imovel Velho") << "\n";
  if (isNovo()) {
    std::cout << "Prazo de Garantia: " << getPrazoGarantia() << " meses\n";
  } else {
    std::cout << "Ultimo Dono: " << getUltimoDono() << "\n";
  }
  std::cout << "Tipo de Telhado: "
            << (tipoTelha == CERAMICA ? "Ceramica" : "Policarbonato") << "\n";
}