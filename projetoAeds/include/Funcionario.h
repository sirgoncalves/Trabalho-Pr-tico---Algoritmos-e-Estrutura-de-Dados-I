#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include "Pessoa.h"

class Funcionario: public Pessoa
{

    private:
    std::string cargo; // Cargo do funcion�rio
    double salario;    // Sal�rio do funcion�rio

    public:
    // Construtor que inicializa os membros da classe Funcionario e chama o
    // construtor da classe base Pessoa
    Funcionario(int cod, std::string nome, std::string telefone,std::string cargo, double salario): Pessoa(cod, nome, telefone), cargo(cargo), salario(salario) {}

    // M�todo getter para obter o cargo do funcion�rio
    std::string getCargo() const;

    // M�todo getter para obter o sal�rio do funcion�rio
    double getSalario() const;

    // M�todo setter para definir o cargo do funcion�rio
    void setCargo(const std::string &cargo);

    // M�todo setter para definir o sal�rio do funcion�rio
    void setSalario(double salario);

    // M�todo para salvar os dados do funcion�rio em um fluxo de sa�da
    void salvar(std::ostream &out) const override;

    // M�todo para carregar os dados do funcion�rio de um fluxo de entrada
    void carregar(std::istream &in) override;


};

#endif // FUNCIONARIO_H
