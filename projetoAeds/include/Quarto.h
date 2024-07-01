#ifndef QUARTO_H
#define QUARTO_H
#include <string>
#include <sstream>

class Quarto
{
    private:
    int numero;             // Número do quarto
    int quantidadeHospedes; // Quantidade máxima de hóspedes
    double valorDiaria;     // Valor da diária do quarto
    bool ocupado;           // Status de ocupação do quarto

    public:
    Quarto(int num, int qtdHospedes, double valorDiaria): numero(num), quantidadeHospedes(qtdHospedes), valorDiaria(valorDiaria),ocupado(false) {}

    // Método getter para obter o número do quarto
    int getNumero() const;

    // Método getter para obter a quantidade máxima de hóspedes
    int getQuantidadeHospedes() const;

    // Método getter para obter o valor da diária do quarto
    double getValorDiaria() const;

    // Método getter para verificar se o quarto está ocupado
    bool isOcupado() const;

    // Método setter para definir o status de ocupação do quarto
    void setOcupado(bool status);

    // Método para salvar os dados do quarto em um fluxo de saída
    void salvar(std::ostream &out) const;

    // Método para carregar os dados do quarto de um fluxo de entrada
    void carregar(std::istream &in);

};

#endif // QUARTO_H
