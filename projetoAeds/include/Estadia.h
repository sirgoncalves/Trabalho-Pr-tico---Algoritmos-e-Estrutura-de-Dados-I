#ifndef ESTADIA_H
#define ESTADIA_H
#include <string>
#include <sstream>

class Estadia
{
    private:
    int codigoEstadia;       // C�digo �nico da estadia
    std::string dataEntrada; // Data de entrada na estadia
    std::string dataSaida;   // Data de sa�da da estadia
    int quantidadeDiarias;   // Quantidade de di�rias da estadia
    int codigoCliente;       // C�digo do cliente associado � estadia
    int numeroQuarto;        // N�mero do quarto associado � estadia

    public:

    // Construtor da classe Estadia
    Estadia(int codEstadia, std::string entrada, std::string saida,int qtdDiarias, int codCliente, int numQuarto):
    codigoEstadia(codEstadia), dataEntrada(entrada), dataSaida(saida),
    quantidadeDiarias(qtdDiarias), codigoCliente(codCliente),
    numeroQuarto(numQuarto) {}

    // M�todos getters para acessar os atributos da classe
    int getCodigoEstadia() const;
    std::string getDataEntrada() const;
    std::string getDataSaida() const;
    int getQuantidadeDiarias() const;
    int getCodigoCliente() const;
    getNumeroQuarto() const;

    // M�todo para salvar os dados da estadia em um arquivo bin�rio
    void salvar(std::ostream &out) const;

    // M�todo para carregar os dados da estadia de um arquivo bin�rio
    void carregar(std::istream &in);
};

#endif // ESTADIA_H
