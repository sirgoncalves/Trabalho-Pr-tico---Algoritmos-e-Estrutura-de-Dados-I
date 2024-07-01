#include "Estadia.h"


int Estadia::getCodigoEstadia() const { return codigoEstadia; }
std::string Estadia::getDataEntrada()  const { return dataEntrada; }
std::string Estadia::getDataSaida() const { return dataSaida; }
int Estadia::getQuantidadeDiarias() const { return quantidadeDiarias; }
int Estadia::getCodigoCliente() const { return codigoCliente; }
int Estadia::getNumeroQuarto() const { return numeroQuarto; }

void Estadia::salvar(std::ostream &out) const {
    // Escreve o código da estadia no arquivo
    out.write(reinterpret_cast<const char *>(&codigoEstadia),
              sizeof(codigoEstadia));
    // Escreve a data de entrada no arquivo
    out.write(dataEntrada.c_str(), dataEntrada.size() + 1);
    // Escreve a data de saída no arquivo
    out.write(dataSaida.c_str(), dataSaida.size() + 1);
    // Escreve a quantidade de diárias no arquivo
    out.write(reinterpret_cast<const char *>(&quantidadeDiarias),
              sizeof(quantidadeDiarias));
    // Escreve o código do cliente no arquivo
    out.write(reinterpret_cast<const char *>(&codigoCliente),
              sizeof(codigoCliente));
    // Escreve o número do quarto no arquivo
    out.write(reinterpret_cast<const char *>(&numeroQuarto),
              sizeof(numeroQuarto));
  }

  void Estadia::carregar(std::istream &in) {
    // Lê o código da estadia do arquivo
    in.read(reinterpret_cast<char *>(&codigoEstadia), sizeof(codigoEstadia));
    // Lê a data de entrada do arquivo
    std::getline(in >> std::ws, dataEntrada, '\0');
    // Lê a data de saída do arquivo
    std::getline(in >> std::ws, dataSaida, '\0');
    // Lê a quantidade de diárias do arquivo
    in.read(reinterpret_cast<char *>(&quantidadeDiarias),
            sizeof(quantidadeDiarias));
    // Lê o código do cliente do arquivo
    in.read(reinterpret_cast<char *>(&codigoCliente), sizeof(codigoCliente));
    // Lê o número do quarto do arquivo
    in.read(reinterpret_cast<char *>(&numeroQuarto), sizeof(numeroQuarto));
  }
