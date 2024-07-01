#include "Cliente.h"


std::string Cliente::getEndereco() const { return endereco;}

void Cliente::setEndereco(const std::string &endereco) { this->endereco = endereco;}

void Cliente::salvar (std::ostream &out) const  {
    Pessoa::salvar(out); // Salva os dados da classe base Pessoa
    out.write(endereco.c_str(),endereco.size() + 1); // Salva o endere�o como uma sequ�ncia de caracteres, incluindo o terminador nulo
  }

  void Cliente::carregar( std::istream &in)  {
    Pessoa::carregar(in); // Carrega os dados da classe base Pessoa
    std::getline(in >> std::ws, endereco,'\0'); // L� o endere�o at� encontrar um caractere nulo
  }
