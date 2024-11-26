#include <iostream>
#include <string>

#include "../include/apartamento.h"
#include "../include/casa.h"
#include "../include/imovel.h"

int main() {
  std::string endereco;
  double precoBase;
  bool eNovo;
  std::string tipoImovelStr;
  TipoImovel tipoImovel;
  std::string tipoTelhaStr;
  TipoTelha tipoTelha;
  int numeroAndar;

  std::cout << "Informe o tipo do imovel (casa ou apartamento): ";
  std::getline(std::cin, tipoImovelStr);

  if (tipoImovelStr == "casa") {
    tipoImovel = CASA;
  } else if (tipoImovelStr == "apartamento") {
    tipoImovel = APARTAMENTO;
  } else {
    std::cout << "Tipo de imovel invalido!" << std::endl;
    return 1;
  }

  std::cout << "Informe o endereço do imovel: ";
  std::getline(std::cin, endereco);

  std::cout << "Informe o preço base do imovel: ";
  std::cin >> precoBase;

  std::cout << "O imovel e novo? (1 para sim, 0 para nao): ";
  std::cin >> eNovo;
  std::cin.ignore();

  if (tipoImovel == CASA) {
    std::cout << "Informe o tipo de telha (ceramica ou policarbonato): ";
    std::getline(std::cin, tipoTelhaStr);

    if (tipoTelhaStr == "ceramica") {
      tipoTelha = CERAMICA;
    } else if (tipoTelhaStr == "policarbonato") {
      tipoTelha = POLICARBONATO;
    } else {
      std::cout << "Tipo de telha invalido!" << std::endl;
      return 1;
    }
    Casa casa(endereco, precoBase, eNovo, tipoTelha);
    casa.exibirDetalhes();

  } else if (tipoImovel == APARTAMENTO) {
    std::cout << "Informe o numero do andar: ";
    std::cin >> numeroAndar;

    Apartamento apartamento(endereco, precoBase, eNovo, numeroAndar);
    apartamento.exibirDetalhes();
  }

  return 0;
}
