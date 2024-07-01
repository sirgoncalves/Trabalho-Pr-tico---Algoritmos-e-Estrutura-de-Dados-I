#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include "Pessoa.h"

class Funcionario: public Pessoa
{

    private:
    std::string cargo; // Cargo do funcionário
    double salario;    // Salário do funcionário

    public:
    // Construtor que inicializa os membros da classe Funcionario e chama o
    // construtor da classe base Pessoa
    Funcionario(int cod, std::string nome, std::string telefone,std::string cargo, double salario): Pessoa(cod, nome, telefone), cargo(cargo), salario(salario) {}

    // Método getter para obter o cargo do funcionário
    std::string getCargo() const;

    // Método getter para obter o salário do funcionário
    double getSalario() const;

    // Método setter para definir o cargo do funcionário
    void setCargo(const std::string &cargo);

    // Método setter para definir o salário do funcionário
    void setSalario(double salario);

    // Método para salvar os dados do funcionário em um fluxo de saída
    void salvar(std::ostream &out) const override;

    // Método para carregar os dados do funcionário de um fluxo de entrada
    void carregar(std::istream &in) override;


};

#endif // FUNCIONARIO_H
