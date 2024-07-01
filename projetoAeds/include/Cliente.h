#ifndef CLIENTE_H
#define CLIENTE_H
#include "Pessoa.h"


class Cliente:public Pessoa
{
    public:
    // Construtor que inicializa os membros da classe Cliente e chama o construtor
    // da classe base Pessoa
    Cliente(int cod, std::string nome, std::string telefone, std::string endereco): Pessoa(cod, nome, telefone), endereco(endereco) {}

    // Método getter para obter o endereço do cliente
    std::string getEndereco() const;

    // Método setter para definir o endereço do cliente
    void setEndereco(const std::string &endereco);

    // Método para salvar os dados do cliente em um fluxo de saída
    void salvar(std::ostream &out)const override;

    // Método para carregar os dados do cliente de um fluxo de entrada
    void carregar(std::istream &in) override;

    private:
    std::string endereco;// Endereço do cliente
};

#endif // CLIENTE_H
