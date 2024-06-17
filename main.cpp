#include <iostream>
#include <stdio.h>
#include <stdbool.h>
//classe pessoa
class Pessoa{
    public:
    char nome[80];
    int codigo;
    int telefone;
};

//classe data
class Data{
    public:
    int dia;
    int mes;
    int ano;
};

//classe endereço
class Endereco{
    public:
    int Numero_Casa;
    char Nome_Rua[30];
    int Cep;
    char Bairro[20];
};

//classe cliente - herda atributos da classe "Pessoa"
class Cliente : public Pessoa{
    public:
    Endereco Endereco_Cliente;
};

//classe funcionário - herda atributos da classe "Pessoa"

class Funcionario : public Pessoa{
    public:
    char Cargo_Funcionario[40];
    float Salario_Funcionario;

};

//classe estadia
class Estadia{
    int Codigo_Estadia;
    int Quantidade_Diarias;
    //codigo do cliente (herança)
};

//classe quarto
class Quarto{
    int NUmero_Quarto;
    int quantidade_Hospedes;
    float Valor_Diaria;
    bool status_Quarto;
};

int main(){

    do
    {
        /* code */
    } while (/* condition */);
    
    printf("Cadastrar");
}
