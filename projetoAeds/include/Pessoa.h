#ifndef PESSOA_H
#define PESSOA_H
#include <string>
#include <sstream>

class Pessoa
{
    public:
    // Construtor que inicializa os membros da classe
    Pessoa(int cod, std::string nome, std::string telefone): codigo(cod), nome(nome), telefone(telefone){}

    // Método getter para obter o código da pessoa
    int getCodigo() const;

    // Método getter para obter o nome da pessoa
    std::string getNome() const;

    // Método getter para obter o telefone da pessoa
    std::string getTelefone() const;

    // Método setter para definir o nome da pessoa
    void setNome(const std::string &nome);

    // Método setter para definir o telefone da pessoa
    void setTelefone(const std::string &telefone);

    // Método para salvar os dados da pessoa em um fluxo de saída
    virtual void salvar(std::ostream &out) const;

    // Método para carregar os dados da pessoa de um fluxo de entrada
    virtual void carregar(std::istream &in);

    protected:
    int codigo;           // Código único da pessoa
    std::string nome;     // Nome da pessoa
    std::string telefone; // Telefone da pessoa


};

#endif // PESSOA_H
