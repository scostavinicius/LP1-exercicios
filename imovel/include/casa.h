#ifndef CASA_H
#define CASA_H

#include "imovel.h"

enum TipoTelha { CERAMICA, POLICARBONATO };

class Casa : public Imovel {
 private:
  TipoTelha tipoTelha;

 public:
  Casa();
  Casa(const std::string& endereco, double precoBase, bool eNovo,
       TipoTelha tipoTelha);
  Casa(const Casa& c);
  virtual ~Casa() = default;

  TipoTelha getTipoTelha() const;
  void setTipoTelha(TipoTelha novoTipoTelha);

  void exibirDetalhes() const override;
};

#endif