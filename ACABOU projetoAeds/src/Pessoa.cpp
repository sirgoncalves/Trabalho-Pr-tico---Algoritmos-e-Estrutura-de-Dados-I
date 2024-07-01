#include "Pessoa.h"


int Pessoa::getCodigo() const{ return codigo;}

std::string Pessoa::getNome() const { return nome;}

std::string Pessoa::getTelefone() const { return telefone;}

void Pessoa::setNome(const std::string &nome) { this->nome = nome;}

void Pessoa::setTelefone(const std::string &telefone) { this->telefone = telefone;}

 void Pessoa::salvar (std::ostream &out) const {
    // Salva o código como um bloco de bytes
    out.write(reinterpret_cast<const char *>(&codigo), sizeof(codigo));
    // Salva o nome como uma sequência de caracteres, incluindo o terminador
    // nulo
    out.write(nome.c_str(), nome.size() + 1);
    // Salva o telefone como uma sequência de caracteres, incluindo o terminador
    // nulo
    out.write(telefone.c_str(), telefone.size() + 1);
  }

   void Pessoa::carregar(std::istream &in) {
    // Lê o código como um bloco de bytes
    in.read(reinterpret_cast<char *>(&codigo), sizeof(codigo));
    // Lê o nome até encontrar um caractere nulo
    std::getline(in >> std::ws, nome, '\0');
    // Lê o telefone até encontrar um caractere nulo
    std::getline(in >> std::ws, telefone, '\0');
  }
