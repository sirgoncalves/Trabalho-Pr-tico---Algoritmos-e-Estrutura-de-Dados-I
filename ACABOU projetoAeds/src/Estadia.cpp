#include "Estadia.h"


int Estadia::getCodigoEstadia() const { return codigoEstadia; }
std::string Estadia::getDataEntrada()  const { return dataEntrada; }
std::string Estadia::getDataSaida() const { return dataSaida; }
int Estadia::getQuantidadeDiarias() const { return quantidadeDiarias; }
int Estadia::getCodigoCliente() const { return codigoCliente; }
int Estadia::getNumeroQuarto() const { return numeroQuarto; }

void Estadia::salvar(std::ostream &out) const {
    // Escreve o c�digo da estadia no arquivo
    out.write(reinterpret_cast<const char *>(&codigoEstadia),
              sizeof(codigoEstadia));
    // Escreve a data de entrada no arquivo
    out.write(dataEntrada.c_str(), dataEntrada.size() + 1);
    // Escreve a data de sa�da no arquivo
    out.write(dataSaida.c_str(), dataSaida.size() + 1);
    // Escreve a quantidade de di�rias no arquivo
    out.write(reinterpret_cast<const char *>(&quantidadeDiarias),
              sizeof(quantidadeDiarias));
    // Escreve o c�digo do cliente no arquivo
    out.write(reinterpret_cast<const char *>(&codigoCliente),
              sizeof(codigoCliente));
    // Escreve o n�mero do quarto no arquivo
    out.write(reinterpret_cast<const char *>(&numeroQuarto),
              sizeof(numeroQuarto));
  }

  void Estadia::carregar(std::istream &in) {
    // L� o c�digo da estadia do arquivo
    in.read(reinterpret_cast<char *>(&codigoEstadia), sizeof(codigoEstadia));
    // L� a data de entrada do arquivo
    std::getline(in >> std::ws, dataEntrada, '\0');
    // L� a data de sa�da do arquivo
    std::getline(in >> std::ws, dataSaida, '\0');
    // L� a quantidade de di�rias do arquivo
    in.read(reinterpret_cast<char *>(&quantidadeDiarias),
            sizeof(quantidadeDiarias));
    // L� o c�digo do cliente do arquivo
    in.read(reinterpret_cast<char *>(&codigoCliente), sizeof(codigoCliente));
    // L� o n�mero do quarto do arquivo
    in.read(reinterpret_cast<char *>(&numeroQuarto), sizeof(numeroQuarto));
  }
