#ifndef CLIENTE_H
#define CLIENTE_H
#include "Pessoa.h"


class Cliente:public Pessoa
{
    public:
    // Construtor que inicializa os membros da classe Cliente e chama o construtor
    // da classe base Pessoa
    Cliente(int cod, std::string nome, std::string telefone, std::string endereco): Pessoa(cod, nome, telefone), endereco(endereco) {}

    // M�todo getter para obter o endere�o do cliente
    std::string getEndereco() const;

    // M�todo setter para definir o endere�o do cliente
    void setEndereco(const std::string &endereco);

    // M�todo para salvar os dados do cliente em um fluxo de sa�da
    void salvar(std::ostream &out)const override;

    // M�todo para carregar os dados do cliente de um fluxo de entrada
    void carregar(std::istream &in) override;

    private:
    std::string endereco;// Endere�o do cliente
};

#endif // CLIENTE_H
