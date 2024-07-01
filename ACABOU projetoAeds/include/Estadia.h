#ifndef ESTADIA_H
#define ESTADIA_H
#include <string>
#include <sstream>

class Estadia
{
    private:
    int codigoEstadia;       // Código único da estadia
    std::string dataEntrada; // Data de entrada na estadia
    std::string dataSaida;   // Data de saída da estadia
    int quantidadeDiarias;   // Quantidade de diárias da estadia
    int codigoCliente;       // Código do cliente associado à estadia
    int numeroQuarto;        // Número do quarto associado à estadia

    public:

    // Construtor da classe Estadia
    Estadia(int codEstadia, std::string entrada, std::string saida,int qtdDiarias, int codCliente, int numQuarto):
    codigoEstadia(codEstadia), dataEntrada(entrada), dataSaida(saida),
    quantidadeDiarias(qtdDiarias), codigoCliente(codCliente),
    numeroQuarto(numQuarto) {}

    // Métodos getters para acessar os atributos da classe
    int getCodigoEstadia() const;
    std::string getDataEntrada() const;
    std::string getDataSaida() const;
    int getQuantidadeDiarias() const;
    int getCodigoCliente() const;
    getNumeroQuarto() const;

    // Método para salvar os dados da estadia em um arquivo binário
    void salvar(std::ostream &out) const;

    // Método para carregar os dados da estadia de um arquivo binário
    void carregar(std::istream &in);
};

#endif // ESTADIA_H
