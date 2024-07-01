#ifndef PESSOA_H
#define PESSOA_H
#include <string>
#include <sstream>

class Pessoa
{
    public:
    // Construtor que inicializa os membros da classe
    Pessoa(int cod, std::string nome, std::string telefone): codigo(cod), nome(nome), telefone(telefone){}

    // M�todo getter para obter o c�digo da pessoa
    int getCodigo() const;

    // M�todo getter para obter o nome da pessoa
    std::string getNome() const;

    // M�todo getter para obter o telefone da pessoa
    std::string getTelefone() const;

    // M�todo setter para definir o nome da pessoa
    void setNome(const std::string &nome);

    // M�todo setter para definir o telefone da pessoa
    void setTelefone(const std::string &telefone);

    // M�todo para salvar os dados da pessoa em um fluxo de sa�da
    virtual void salvar(std::ostream &out) const;

    // M�todo para carregar os dados da pessoa de um fluxo de entrada
    virtual void carregar(std::istream &in);

    protected:
    int codigo;           // C�digo �nico da pessoa
    std::string nome;     // Nome da pessoa
    std::string telefone; // Telefone da pessoa


};

#endif // PESSOA_H
