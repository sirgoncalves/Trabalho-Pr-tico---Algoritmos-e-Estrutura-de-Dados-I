#include <iostream>
#include <string.h> // Para strcpy
#include <stdio.h>

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
class Cliente : public Pessoa {
private:
    Endereco endereco;

public:
    // Construtor padrão
    Cliente() {
        // Chama o construtor padrão de Pessoa automaticamente
    }

    // Construtor sobrecarregado
    Cliente(const char* nome, int codigo, int telefone, const Endereco& endereco) {
    setNome(nome);
    setCodigo(codigo);
    setTelefone(telefone);
    this->endereco = endereco;
}

    // Getters
    const Endereco& getEndereco() const {
        return endereco;
    }

    // Setter
    void setEndereco(const Endereco& endereco) {
        this->endereco = endereco;
    }
};

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

//classe estadia
class Estadia{
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

#define Max_Clientes 100 
#define Max_Funcionarios 20 
#define Max_Quartos 100 
#define Max_estadias 100 

int ContadorPessoas=0; //contador de pessoas
int ContadorQuartos=0;
int ContadorFuncionarios=0;
int ContadorEstadias=0;



void CadastrarClientes(Cliente listaClientes[Max_Clientes]) {
    if (ContadorPessoas < Max_Clientes) {
        char nomeCliente[80], nomeRuaCliente[30], BairroCliente[20];
        int telefone, numeroCasaCliente, Cep;
        Endereco enderecoCliente;

        cout << "Insira seu nome: ";
        cin >> nomeCliente;

        cout << "Insira seu telefone: ";
        cin >> telefone;

        cout << "Insira seu endereco abaixo!" << endl;

        cout << "Numero da casa: ";
        cin >> numeroCasaCliente;

        cout << "Nome da rua:";
        cin.ignore(); // Ignora o caractere de nova linha no buffer
        cin.getline(nomeRuaCliente, 30);

        cout << "Cep: ";
        cin >> Cep;

        cout << "Nome do bairro: ";
        cin.ignore(); // Ignora o caractere de nova linha no buffer
        cin.getline(BairroCliente, 20);


        fflush(stdin);
        //chama construtor sobrecarregado
        listaClientes[ContadorPessoas] = Cliente(nomeCliente, ContadorPessoas + 1, telefone, Endereco(numeroCasaCliente, nomeRuaCliente, Cep, BairroCliente));

        ContadorPessoas++;
        cout << "Cadastro Realizado com sucesso!" << endl;
    } else {
        cout << "Limite de cadastros excedido!" << endl;
    }

    cout << "------------------------------------------------" << endl;
}



void listarClientesCadastrados(Cliente listarClientesCadastrados[Max_Clientes]){
    int cont=0;
    cout << "Lista de clientes:"<< endl;
    for(int i=0;i<ContadorPessoas;i++){
        if(listarClientesCadastrados[i].getCodigo() != -1){
          cout << "Codigo do Cliente: " << listarClientesCadastrados[i].getCodigo() << endl;
          cout << "Nome do cliente: " << listarClientesCadastrados[i].getNome() << endl;
          cont++;
        }
    }

    cout << "Quantidade de clientes cadastrados: " << cont << endl;
    cout << "------------------------------------------------" << endl;
}

Cliente *buscarClientes(Cliente listaClientes[Max_Clientes], int codigo){
    for(int i = 0;i < Max_Clientes; i++){
       if(listaClientes[i].getCodigo() == codigo){//cliente encontrado
            return &listaClientes[i];
        }
    }
    return NULL;
}


void CadastrarFuncionarios(Funcionario listaFuncionarios[Max_Funcionarios]){
    if(ContadorFuncionarios<Max_Funcionarios){
        char nomeFuncionario[80], cargoFuncionario[40];
        int codigoFuncionario, Telefone;

        cout << "Insira o nome do funcionario: ";
        cin.ignore(); // Limpa o buffer do teclado para evitar problemas com getline()
        cin.getline(nomeFuncionario, 80); // Permite ler espaços no nome completo

        cout << "Insira o codigo do funcionario: ";
        cin >> codigoFuncionario;

        cout << "Insira o telefone do funcionario: ";
        cin >> Telefone;

        cout << "Insira o cargo do funcionario: ";
        cin.ignore();
        cin.getline(cargoFuncionario, 40);

        fflush(stdin);


        listaFuncionarios[ContadorFuncionarios].setNome(nomeFuncionario);
        listaFuncionarios[ContadorFuncionarios].setCodigo(ContadorFuncionarios + 1);
        listaFuncionarios[ContadorFuncionarios].setTelefone(Telefone);
        listaFuncionarios[ContadorFuncionarios].setCargo(cargoFuncionario);

        ContadorFuncionarios++;

        cout << "Cadastro Realizado com sucesso!" << endl;
    }else{
        cout << "Limite de cadastros excedido!" << endl;
    }
    cout << "------------------------------------------------" << endl;
}

void ListarFuncionariosCadastrados(Funcionario listarFuncionarios[Max_Funcionarios]){
    int cont=0;
    cout << "Lista de Funcionario do Hotel:"<< endl;
    for(int i=0;i<ContadorFuncionarios;i++){
        if(listarFuncionarios[i].getCodigo() != -1){
          cout << "Codigo do funcionario: " << listarFuncionarios[i].getCodigo() << endl;
          cout << "Nome do funcionario: " << listarFuncionarios[i].getNome() << endl;
          cont++;
        }
    }

    cout << "Quantidade de Funcionarios cadastrados: " << cont << endl;
    cout << "------------------------------------------------" << endl;
}

//relacionamento (cliente, estadia e quarto):
/*

cliente --------estadia-------quarto   (associação <=>estadia é intermediária)

1------n (um cliente pode ter varios quartos e um quarto pode ser de apenas um cliente)
*/

void ListarQuartosDisponiveis(Quarto listaQuartos[Max_Quartos]){
    int cont=0;
    cout << "Lista de quartos disponiveis do hotel: "<<endl;
    for(int i=0;i<ContadorQuartos;i++){
        if(listaQuartos[i].getStatus()){ // Verifica se o quarto está disponível
           cout << "Numero do quarto: " << listaQuartos[i].getNumeroQuarto() << endl;
           cont++;
        }
    }
    cout << "Quantidade de quartos disponiveis: " << cont << endl;
    cout << "------------------------------------------------" << endl;
}

Quarto* BuscarQuarto(Quarto listaQuartos[Max_Quartos], int numero){
    for(int i=0;i<Max_Quartos;i++){
        if(listaQuartos[i].getNumeroQuarto()==numero){ //quarto encontrado!
            return &listaQuartos[i];
        }
    }

    return NULL;
}

Quarto *VerificaOcupacao(Quarto listaQuartos[], int numeroQuarto){
    for(int i=0;i<Max_Quartos;i++){
        if(listaQuartos[i].getNumeroQuarto()==numeroQuarto){ //quarto desocupado!
            if(listaQuartos[i].getStatus()==true){
                cout << "Quarto desocupado!" << endl;
                return &listaQuartos[i];
            }
        }

    }
    cout << "Quarto ocupado!" << endl;

    return NULL;
}



void CadastrarEstadia(Estadia listaEstadias[Max_Quartos], Cliente listaClientes[Max_Clientes], Quarto listaQuartos[Max_Quartos]){
    int codigoDoClienteHospede;
    //int quantidadeHospedes;
    //int codigoEstadia; é automatico
    int QuantidadeDiarias;
    int diaEntrada, mesEntrada, anoEntrada, diaSaida, mesSaida, anoSaida;

    if(ContadorEstadias<Max_estadias){
        cout << "Insira a data de ENTRADA abaixo: "<< endl;
        cout << "Dia: ";
        cin >> diaEntrada;

        cout << "Mes:";
        cin >> mesEntrada;

        cout << "Ano:";
        cin >> anoEntrada;


        cout << "Insira a data de SAIDA abaixo: "<< endl;
        cout << "Dia: ";
        cin >> diaSaida;

        cout << "Mes:";
        cin >> mesSaida;

        cout << "Ano:";
        cin >> anoSaida;

        Data entrada(diaEntrada, mesEntrada, anoEntrada);
        Data saida(diaSaida, mesSaida, anoSaida);

        QuantidadeDiarias = diaSaida - diaEntrada; //calculo prévio, pois deve-se considerar mes, dia e ano no calculo correto (vou fazer depois)

        listaEstadias[ContadorEstadias].setEntrada(entrada);
        listaEstadias[ContadorEstadias].setSaida(saida);
        listaEstadias[ContadorEstadias].setCodigoEstadia(ContadorEstadias + 1);


        // Listar os clientes cadastrados para seleção
        listarClientesCadastrados(listaClientes);

        cout << "Insira o codigo do cliente: ";
        cin >> codigoDoClienteHospede;

        Cliente* clienteEncontrado = buscarClientes(listaClientes, codigoDoClienteHospede);

        if (clienteEncontrado != nullptr){
            listaEstadias[ContadorEstadias].setCodigoCliente(clienteEncontrado);

            // Listar quartos disponíveis para seleção
               ListarQuartosDisponiveis(listaQuartos);

            int numeroQuarto;
            cout << "Insira o numero do quarto desejado: ";
            cin >> numeroQuarto;

            Quarto* quartoEncontrado = BuscarQuarto(listaQuartos, numeroQuarto);

            if (quartoEncontrado != nullptr) {
            Quarto* quartoOcupado = VerificaOcupacao(listaQuartos, numeroQuarto);

                if (quartoOcupado == nullptr) {
                    listaEstadias[ContadorEstadias].setNumero(*quartoEncontrado);
                    listaEstadias[ContadorEstadias].setNumeroQuarto(quartoEncontrado);
                    ContadorEstadias++;
                    cout << "Estadia cadastrada com sucesso!" << endl;
                }else{
                    cout << "O quarto selecionado esta ocupado." << endl;
                }
            } else {
                cout << "Numero de quarto invalido." << endl;
            }
        } else {
            cout << "Cliente nao encontrado." << endl;
        }
    } else {
        cout << "Limite de estadias cadastradas atingido." << endl;
    }
    cout << "------------------------------------------------" << endl;
}




void cadastrarQuarto(Quarto listaQuartos[Max_Quartos]){
    int quantHospedes;
    bool status;
    if(ContadorQuartos<Max_Quartos){
        cout << "Cadastrando Quartos do Hotel" << endl;

        cout << "Insira a qantidade de hospedes: " << endl;
        cin >> quantHospedes;

        cout << "Insira a situação do quarto: ";
        cin >> status;


        listaQuartos[ContadorQuartos].setQuantidadeHospedes(quantHospedes);
        listaQuartos[ContadorQuartos].setNumeroQuarto(ContadorQuartos+1); 
        listaQuartos[ContadorQuartos].setStatus(status);
        ContadorQuartos++;

        cout << "Cadastro realizado com sucesso " << endl;
    }else{
        cout << "Limite de cadastro excedido. " << endl;
    }

    cout << "------------------------------------------------" << endl;
}


int main() {
    int opcao;
    Cliente ClientesDoHotel[Max_Clientes]; //vetor para armazenar clientes
    Funcionario listaFuncionarios[Max_Funcionarios]; //vetor para armazenar funcionários
    Estadia EstadiaHotel[Max_estadias];
    Quarto QuartosHotel[Max_Quartos];

    do {
        cout << "Bem-Vindo!\n";
        cout << "Escolha uma opcao: \n";
        cout << "1 - Cadastrar Cliente\n";
        cout << "2 - Listar Clientes\n";
        cout << "3 - Cadastrar Funcionario\n";
        cout << "4 - Listar Funcionarios\n";
        cout << "5 - Obter Uma Estadia\n";
        cout << "6 - Listar Estadias\n";
        cout << "7 - cadastrar Quarto\n";
        cout << "0 - Sair\n";
        cin >> opcao;
        cout << "------------------------------------------------" << endl;

        switch (opcao) {
            case 1: {
                CadastrarClientes(ClientesDoHotel);
                break;
            }
            case 2: {
                listarClientesCadastrados(ClientesDoHotel);
                break;
            }
            case 3: {
                CadastrarFuncionarios(listaFuncionarios);
                break;
            }
            case 4: {
                ListarFuncionariosCadastrados(listaFuncionarios);
                break;
            }
            case 5: {
                CadastrarEstadia(EstadiaHotel, ClientesDoHotel, QuartosHotel);
                break;
            }
            case 6:{
                //botar aqui haha
                break;
            }
            case 7: {
                cadastrarQuarto(QuartosHotel);
                break;
            }
            case 0: {

                break;
            }
            default:
                cout << "Opcao invalida!";
                break;
        }

    } while (opcao != 0);

    return 0;
}

