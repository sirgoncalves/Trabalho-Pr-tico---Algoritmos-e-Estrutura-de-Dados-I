#include "Funcionario.h"


std::string Funcionario::getCargo() const { return cargo;}

double Funcionario::getSalario() const { return salario;}

void Funcionario::setCargo(const std::string &cargo) { this->cargo = cargo;}

void Funcionario::setSalario(double salario)  { this->salario = salario;}

void Funcionario::salvar (std::ostream &out) const  {
    Pessoa::salvar(out); // Salva os dados da classe base Pessoa
    out.write(cargo.c_str(),
              cargo.size() + 1); // Salva o cargo como uma sequ�ncia de
                                 // caracteres, incluindo o terminador nulo
    out.write(reinterpret_cast<const char *>(&salario),
              sizeof(salario)); // Salva o sal�rio como um bloco de bytes
  }

void Funcionario::carregar(std::istream &in)  {
    Pessoa::carregar(in); // Carrega os dados da classe base Pessoa
    std::getline(in >> std::ws, cargo,
                 '\0'); // L� o cargo at� encontrar um caractere nulo
    in.read(reinterpret_cast<char *>(&salario),
            sizeof(salario)); // L� o sal�rio como um bloco de bytes
  }
