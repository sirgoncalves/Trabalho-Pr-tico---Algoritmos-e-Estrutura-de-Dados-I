#include "Pessoa.h"


int Pessoa::getCodigo() const{ return codigo;}

std::string Pessoa::getNome() const { return nome;}

std::string Pessoa::getTelefone() const { return telefone;}

void Pessoa::setNome(const std::string &nome) { this->nome = nome;}

void Pessoa::setTelefone(const std::string &telefone) { this->telefone = telefone;}

 void Pessoa::salvar (std::ostream &out) const {
    // Salva o c�digo como um bloco de bytes
    out.write(reinterpret_cast<const char *>(&codigo), sizeof(codigo));
    // Salva o nome como uma sequ�ncia de caracteres, incluindo o terminador
    // nulo
    out.write(nome.c_str(), nome.size() + 1);
    // Salva o telefone como uma sequ�ncia de caracteres, incluindo o terminador
    // nulo
    out.write(telefone.c_str(), telefone.size() + 1);
  }

   void Pessoa::carregar(std::istream &in) {
    // L� o c�digo como um bloco de bytes
    in.read(reinterpret_cast<char *>(&codigo), sizeof(codigo));
    // L� o nome at� encontrar um caractere nulo
    std::getline(in >> std::ws, nome, '\0');
    // L� o telefone at� encontrar um caractere nulo
    std::getline(in >> std::ws, telefone, '\0');
  }
