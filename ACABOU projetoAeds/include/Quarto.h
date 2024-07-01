#ifndef QUARTO_H
#define QUARTO_H
#include <string>
#include <sstream>

class Quarto
{
    private:
    int numero;             // N�mero do quarto
    int quantidadeHospedes; // Quantidade m�xima de h�spedes
    double valorDiaria;     // Valor da di�ria do quarto
    bool ocupado;           // Status de ocupa��o do quarto

    public:
    Quarto(int num, int qtdHospedes, double valorDiaria): numero(num), quantidadeHospedes(qtdHospedes), valorDiaria(valorDiaria),ocupado(false) {}

    // M�todo getter para obter o n�mero do quarto
    int getNumero() const;

    // M�todo getter para obter a quantidade m�xima de h�spedes
    int getQuantidadeHospedes() const;

    // M�todo getter para obter o valor da di�ria do quarto
    double getValorDiaria() const;

    // M�todo getter para verificar se o quarto est� ocupado
    bool isOcupado() const;

    // M�todo setter para definir o status de ocupa��o do quarto
    void setOcupado(bool status);

    // M�todo para salvar os dados do quarto em um fluxo de sa�da
    void salvar(std::ostream &out) const;

    // M�todo para carregar os dados do quarto de um fluxo de entrada
    void carregar(std::istream &in);

};

#endif // QUARTO_H
