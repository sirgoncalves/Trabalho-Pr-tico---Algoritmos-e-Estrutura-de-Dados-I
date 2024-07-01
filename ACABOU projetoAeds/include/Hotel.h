#ifndef HOTEL_H
#define HOTEL_H


#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Pessoa.h"
#include "Cliente.h"
#include "Funcionario.h"
#include "Quarto.h"
#include "Estadia.h"

class Hotel
{
    private:
    std::vector<Cliente> clientes;
    std::vector<Funcionario> funcionarios;
    std::vector<Estadia> estadias;
    std::vector<Quarto> quartos;

    int gerarCodigoCliente();

    int gerarCodigoFuncionario();

    int gerarCodigoEstadia();

    void salvarClientes(const std::string &filename) const;

    void carregarClientes(const std::string &filename);

    bool existeCargo(const std::string &cargo) const;

    void salvarFuncionarios(const std::string &filename) const;

    void carregarFuncionarios(const std::string &filename);

    void salvarEstadias(const std::string &filename) const;

    void carregarEstadias(const std::string &filename);

    void salvarQuartos(const std::string &filename) const;

    void carregarQuartos(const std::string &filename);


    public:

    // Construtor que carrega dados dos arquivos bin�rios ao inicializar
    Hotel() {
    carregarClientes("clientes.bin");
    carregarFuncionarios("funcionarios.bin");
    carregarEstadias("estadias.bin");
    carregarQuartos("quartos.bin");
    }

    // Destrutor que salva dados nos arquivos bin�rios ao encerrar
    ~Hotel() {
    salvarClientes("clientes.bin");
    salvarFuncionarios("funcionarios.bin");
    salvarEstadias("estadias.bin");
    salvarQuartos("quartos.bin");
    }

    void mostrarListaQuartos() const;

 void cadastrarCliente(const std::string &nome, const std::string &telefone,
                        const std::string &endereco);
    void deletarFuncionario(int codigo);

    void listarClientes() const;

    void deletarCliente(int codigo);

    void checkFuncionarioCargo(const Funcionario &funcionario,const std::string &cargoToCheck);

    void listarFuncionarios() const;

    void cadastrarFuncionario(const std::string &nome,const std::string &telefone,const std::string &cargo, double salario);

    // Metodo para gerar c�digo �nico para funcionarios
    int gerarCodigoFuncionario() const;

    // Metodo para verificar se um cargo de funcionario j� existe
    bool cargoExists(const std::string &cargo);

    // M�todo para cadastrar um novo quarto
    void cadastrarQuarto(int numero, int qtdHospedes, double valorDiaria);

    // M�todo para cadastrar uma nova estadia
    void cadastrarEstadia(int codCliente, const std::string &dataEntrada,const std::string &dataSaida, int quantidadeDiarias,int qtdHospedes);

    void darBaixaEstadia(int codigoEstadia);

    void pesquisarClientePorNomeOuCodigo(const std::string &nome,int codigo) const;

    // M�todo para pesquisar funcion�rio por nome ou c�digo
    void pesquisarFuncionarioPorNomeOuCodigo(const std::string &nome,int codigo) const;

    // M�todo para mostrar estadias de um cliente pelo c�digo do cliente
    void mostrarEstadiasCliente(int codigoCliente) const;

    // M�todo para calcular pontos de fidelidade de um cliente pelo c�digo do
    // cliente
    int calcularPontosFidelidade(int codigoCliente) const;
};

#endif // HOTEL_H
