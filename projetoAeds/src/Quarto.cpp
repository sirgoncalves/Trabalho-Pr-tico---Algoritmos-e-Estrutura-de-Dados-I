#include "Quarto.h"



int Quarto::getNumero() const { return numero; }

int Quarto::getQuantidadeHospedes()const { return quantidadeHospedes; }

double Quarto::getValorDiaria() const { return valorDiaria; }

bool Quarto::isOcupado() const { return ocupado; }

void Quarto::setOcupado(bool status)  { ocupado = status; }

void Quarto::salvar(std::ostream &out) const {
    out.write(reinterpret_cast<const char *>(&numero),
              sizeof(numero)); // Salva o número do quarto
    out.write(reinterpret_cast<const char *>(&quantidadeHospedes),
              sizeof(quantidadeHospedes)); // Salva a quantidade de hóspedes
    out.write(reinterpret_cast<const char *>(&valorDiaria),
              sizeof(valorDiaria)); // Salva o valor da diária
    out.write(reinterpret_cast<const char *>(&ocupado),
              sizeof(ocupado)); // Salva o status de ocupação
  }

void Quarto::carregar(std::istream &in) {
    in.read(reinterpret_cast<char *>(&numero),
            sizeof(numero)); // Lê o número do quarto
    in.read(reinterpret_cast<char *>(&quantidadeHospedes),
            sizeof(quantidadeHospedes)); // Lê a quantidade de hóspedes
    in.read(reinterpret_cast<char *>(&valorDiaria),
            sizeof(valorDiaria)); // Lê o valor da diária
    in.read(reinterpret_cast<char *>(&ocupado),
            sizeof(ocupado)); // Lê o status de ocupação
  }




