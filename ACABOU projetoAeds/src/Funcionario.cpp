#include "Funcionario.h"


std::string Funcionario::getCargo() const { return cargo;}

double Funcionario::getSalario() const { return salario;}

void Funcionario::setCargo(const std::string &cargo) { this->cargo = cargo;}

void Funcionario::setSalario(double salario)  { this->salario = salario;}

void Funcionario::salvar (std::ostream &out) const  {
    Pessoa::salvar(out); // Salva os dados da classe base Pessoa
    out.write(cargo.c_str(),
              cargo.size() + 1); // Salva o cargo como uma sequência de
                                 // caracteres, incluindo o terminador nulo
    out.write(reinterpret_cast<const char *>(&salario),
              sizeof(salario)); // Salva o salário como um bloco de bytes
  }

void Funcionario::carregar(std::istream &in)  {
    Pessoa::carregar(in); // Carrega os dados da classe base Pessoa
    std::getline(in >> std::ws, cargo,
                 '\0'); // Lê o cargo até encontrar um caractere nulo
    in.read(reinterpret_cast<char *>(&salario),
            sizeof(salario)); // Lê o salário como um bloco de bytes
  }
