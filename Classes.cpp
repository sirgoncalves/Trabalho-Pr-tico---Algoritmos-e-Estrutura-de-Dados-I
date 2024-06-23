#include <iostream>
#include <string.h> // Para strcpy
#include <stdio.h>
#define Max_Clientes 100 //definindo a quantidade máxima de clientes
#define Max_Funcionarios 20 //definindo a quantidade máxima de funcionários (proporção de 2 funcionários para cada 10 clientes)
#define Max_Quartos 100 //quantidade máxima de quartos disponíveis no hotel (deve ser igual à quantidade máxima de clientes)
#define Max_estadias 100 // quantidade máxima de estadias (igual à quatidade de quartos)
int ContadorPessoas=0; //contador de pessoas
int ContadorQuartos=0;
int ContadorFuncionarios=0;
int ContadorEstadias=0;
using namespace std;

//Declaração das classes

// Classe Pessoa
class Pessoa {
private:
    char nome[80];
    int codigo;
    int telefone;

public:
    // Construtor padrão
    Pessoa() {
        strcpy(nome, "Nome Pessoa");
        codigo = -1;
        telefone = 0;
    }

    //construtor sobrecarregado
    Pessoa(char nome[80], int codigo, int telefone){
        this-> codigo = codigo;
        strcpy(this->nome, nome);
        this-> telefone = telefone;

    }


    // Getters
    const char* getNome() const {
        return nome;
    }

    int getCodigo() const {
        return codigo;
    }

    int getTelefone() const {
        return telefone;
    }

    // Setters
    void setNome(const char* novoNome) {
        strcpy(nome, novoNome);
    }

    void setCodigo(int novoCodigo) {
        codigo = novoCodigo;
    }

    void setTelefone(int novoTelefone) {
        telefone = novoTelefone;
    }

    void Mostrar(){
        cout << " Nome Pessoa: " << nome ; //mostra o nome da pessoa
        cout << " | Codigo da Pessoa: " << codigo << endl; //mostra o codigo da pessoa
        //cout << "Telefone da pessoa: " << telefone << endl; //mostra o telefone da pessoa
    }
};




// Classe Endereco
class Endereco {
private:
    int Numero_Casa;
    char Nome_Rua[30];
    int Cep;
    char Bairro[20];

public:
    // Construtor padrão
    Endereco() {
        Numero_Casa = 0;
        strcpy(Nome_Rua, "Rua X");
        Cep = 0;
        strcpy(Bairro, "Bairro Y");
    }

    //construtor Sobrecarregado
    Endereco(int Numero_Casa, char Nome_Rua[30], int Cep, char Bairro[20]){
        this-> Numero_Casa = Numero_Casa;
        strcpy(this->Nome_Rua, Nome_Rua);
        this-> Cep = Cep;
         strcpy(this->Bairro, Bairro);

    }

    // Getters
    int getNumeroCasa() const {
        return Numero_Casa;
    }

    const char* getNomeRua() const {
        return Nome_Rua;
    }

    int getCep() const {
        return Cep;
    }

    const char* getBairro() const {
        return Bairro;
    }

    // Setters
    void setNumeroCasa(int numero) {
        Numero_Casa = numero;
    }

    void setNomeRua(const char* nome) {
        strcpy(Nome_Rua, nome);
    }

    void setCep(int cep) {
        Cep = cep;
    }

    void setBairro(const char* bairro) {
        strcpy(Bairro, bairro);
    }

};

//classe Cliente - herda de Pessoa
class Cliente : public Pessoa, public Endereco{
private:
    Endereco *endereco;
    

public:

    Cliente(Endereco endereco){
        this-> endereco = &endereco;
    }

     // Getters e Setters
    void setEndereco(Endereco *x) { //consertar essa parte
        x=0;
    }
};

/*

// Classe Pessoa
class Pessoa {
private:
    char nome[80];
    int codigo;
    int telefone;
    Endereco *endereco;

public:
    // Construtor padrão
    Pessoa() {
        strcpy(nome, "Nome Pessoa");
        codigo = -1;
        telefone = 0;
    }

    //construtor sobrecarregado
    Pessoa(char nome[80], int codigo, int telefone, Endereco endereco){
        this-> codigo = codigo;
        strcpy(this->nome, nome);
        this-> telefone = telefone;
        this-> endereco = &endereco;

    }


    // Getters
    const char* getNome() const {
        return nome;
    }

    int getCodigo() const {
        return codigo;
    }

    int getTelefone() const {
        return telefone;
    }

    void setEndereco(Endereco *x) { //consertar essa parte
        x=0;
    }

    // Setters
    void setNome(const char* novoNome) {
        strcpy(nome, novoNome);
    }

    void setCodigo(int novoCodigo) {
        codigo = novoCodigo;
    }

    void setTelefone(int novoTelefone) {
        telefone = novoTelefone;
    }

    void Mostrar(){
        cout << " Nome Pessoa: " << nome ; //mostra o nome da pessoa
        cout << " | Codigo da Pessoa: " << codigo << endl; //mostra o codigo da pessoa
        //cout << "Telefone da pessoa: " << telefone << endl; //mostra o telefone da pessoa
    }
};
*/



// Classe Funcionario - herda de Pessoa
class Funcionario : public Pessoa {
private:
    char Cargo_Funcionario[40];
    float Salario_Funcionario;

public:
    // Construtor padrão
    Funcionario() {
        strcpy(Cargo_Funcionario, "Cargo Padrão");
        Salario_Funcionario = 0.0f;
    }

    // Getters
    const char* getCargo() const {
        return Cargo_Funcionario;
    }

    float getSalario() const {
        return Salario_Funcionario;
    }

    // Setters
    void setCargo(const char* cargo) {
        strcpy(Cargo_Funcionario, cargo);
    }

    void setSalario(float salario) {
        Salario_Funcionario = salario;
    }

    void Mostrar(){ //é realmente necessário?

    }
};

/*
* ESTADIA = código da estadia, data de entrada, data de saída, quantidade de diárias, código do
cliente, número do quarto
* QUARTO = número do quarto, quantidade de hospedes, valor diária, status
*/

//classe data
class Data{
private:

    int dia;
    int mes;
    int ano;

public:
    //construtor padrão
    Data(){
        dia = 0;
        mes = 0;
        ano = 0;
    }

    //construtor sobrecarregado
    Data(int dia, int mes, int ano){
        this->dia=dia;
        this->mes=mes;
        this->ano=ano;
    }

       // Getters
    int getDia() const {
        return dia;
    }

    int getMes() const {
        return mes;
    }

    int getAno() const {
        return ano;
    }

    // Setters
    void setDia(int dia) {
        this->dia = dia;
    }

    void setMes(int mes) {
        this->mes = mes;
    }

    void setAno(int ano) {
        this->ano = ano;
    }
};

//classe estadia
class Estadia : public Data, public Cliente, public Quarto {
private:

    int codigoEstadia;
    Data saida;
    Data entrada;
    int QuantidadeDiarias;
    Quarto numero;
    Cliente *codigoCliente;
    Quarto *numeroQuarto;

public:

    //construtor padrão
    // A chamada dos construtores das classes base é implícita aqui
    // Não há necessidade de inicializar explicitamente Data, Cliente e Quarto,
    // pois os construtores padrão de cada classe base são chamados automaticamente.

    Estadia(){
        codigoEstadia = 0;
        QuantidadeDiarias = 0;
        codigoCliente = nullptr;
        numeroQuarto = nullptr;
    }

    //construtor sobrecarregado
    Estadia(int codigoEstadia, int QuantidadeDiarias){
        this->codigoEstadia = codigoEstadia;
        this->QuantidadeDiarias = QuantidadeDiarias;
        this->codigoCliente = nullptr;
        this->numeroQuarto = nullptr;

    }


    // Getters
    int getCodigoEstadia() const {
        return codigoEstadia;
    }

    Data getSaida() const {
        return saida;
    }

    Data getEntrada() const {
        return entrada;
    }

    int getQuantidadeDiarias() const {
        return QuantidadeDiarias;
    }

    Quarto getNumero() const {
        return numero;
    }

    Cliente* getCodigoCliente() const {
        return codigoCliente;
    }

    Quarto* getNumeroQuarto() const {
        return numeroQuarto;
    }

    // Setters
    void setCodigoEstadia(int codigoEstadia) {
        this->codigoEstadia = codigoEstadia;
    }

    void setSaida(const Data& saida) {
        this->saida = saida;
    }

    void setEntrada(const Data& entrada) {
        this->entrada = entrada;
    }

    void setQuantidadeDiarias(int QuantidadeDiarias) {
        this->QuantidadeDiarias = QuantidadeDiarias;
    }

    void setNumero(const Quarto& numero) {
        this->numero = numero;
    }

    void setCodigoCliente(Cliente* codigoCliente) {
        this->codigoCliente = codigoCliente;
    }

    void setNumeroQuarto(Quarto* numeroQuarto) {
        this->numeroQuarto = numeroQuarto;
    }




};

//classe quarto
class Quarto{
private:

    int NumeroQuarto;
    int QuantidadeHospedes;
    float ValorDiaria = 90.0;
    bool status;

public:
    //construtor padrão
    Quarto(){
        NumeroQuarto = -1;
        QuantidadeHospedes = 0;
        ValorDiaria = 0.0f;
        status = true;
     }

    //construtor sobrecarregado
    Quarto(int NumeroQuarto, int QuantidadeHospedes, float ValorDiaria, bool status){
        this->NumeroQuarto=NumeroQuarto;
        this->QuantidadeHospedes=QuantidadeHospedes;
        this->ValorDiaria=ValorDiaria;
        this->status=status;
    }

    // Getters e Setters
    int getNumeroQuarto() const {
        return NumeroQuarto;
    }

    void setNumeroQuarto(int NumeroQuarto) {
        this->NumeroQuarto = NumeroQuarto;
    }

    int getQuantidadeHospedes() const {
        return QuantidadeHospedes;
    }

    void setQuantidadeHospedes(int QuantidadeHospedes) {
        this->QuantidadeHospedes = QuantidadeHospedes;
    }

    float getValorDiaria() const {
        return ValorDiaria;
    }

    void setValorDiaria(float ValorDiaria) {
        this->ValorDiaria = ValorDiaria;
    }

    bool getStatus() const {
        return status;
    }

    void setStatus(bool status) {
        this->status = status;
    }

    void MostraQuarto(){
        cout << "Numero do quarto: " << NumeroQuarto << endl;
    }
};
