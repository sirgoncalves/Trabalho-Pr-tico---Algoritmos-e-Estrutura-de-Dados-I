#include "Quarto.h"



int Quarto::getNumero() const { return numero; }

int Quarto::getQuantidadeHospedes()const { return quantidadeHospedes; }

double Quarto::getValorDiaria() const { return valorDiaria; }

bool Quarto::isOcupado() const { return ocupado; }

void Quarto::setOcupado(bool status)  { ocupado = status; }

void Quarto::salvar(std::ostream &out) const {
    out.write(reinterpret_cast<const char *>(&numero),
              sizeof(numero)); // Salva o n�mero do quarto
    out.write(reinterpret_cast<const char *>(&quantidadeHospedes),
              sizeof(quantidadeHospedes)); // Salva a quantidade de h�spedes
    out.write(reinterpret_cast<const char *>(&valorDiaria),
              sizeof(valorDiaria)); // Salva o valor da di�ria
    out.write(reinterpret_cast<const char *>(&ocupado),
              sizeof(ocupado)); // Salva o status de ocupa��o
  }

void Quarto::carregar(std::istream &in) {
    in.read(reinterpret_cast<char *>(&numero),
            sizeof(numero)); // L� o n�mero do quarto
    in.read(reinterpret_cast<char *>(&quantidadeHospedes),
            sizeof(quantidadeHospedes)); // L� a quantidade de h�spedes
    in.read(reinterpret_cast<char *>(&valorDiaria),
            sizeof(valorDiaria)); // L� o valor da di�ria
    in.read(reinterpret_cast<char *>(&ocupado),
            sizeof(ocupado)); // L� o status de ocupa��o
  }




