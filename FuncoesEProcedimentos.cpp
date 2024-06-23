#include "Classes.cpp"
#include <iostream>

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
        cin >> nomeRuaCliente;

        cout << "Cep: ";
        cin >> Cep;

        cout << "Nome do bairro: ";
        cin >> BairroCliente;


        fflush(stdin);

        listaClientes[ContadorPessoas].setNome(nomeCliente);
        listaClientes[ContadorPessoas].setTelefone(telefone);
        listaClientes[ContadorPessoas].setCodigo(ContadorPessoas + 1);
        listaClientes[ContadorPessoas].setNumeroCasa(numeroCasaCliente);
        listaClientes[ContadorPessoas].setNomeRua(nomeRuaCliente);
        listaClientes[ContadorPessoas].setCep(Cep);
        listaClientes[ContadorPessoas].setBairro(BairroCliente);

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
        cin >> nomeFuncionario;

        cout << "Insira o codigo do funcionario: ";
        cin >> codigoFuncionario;

        cout << "Insira o telefone do funcionario: ";
        cin >> Telefone;

        cout << "Insira o cargo do funcionario: ";
        cin >> cargoFuncionario;

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

void CadastrarEstadia(Estadia listaEstadias[Max_Quartos], Cliente listaClientes[Max_Clientes], Quarto listaQuartos[Max_Quartos]){
    int codigoDoClienteHospede;
    int quantidadeHospedes;
    int codigoEstadia;
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

        listaEstadias[Max_estadias].setDia(diaEntrada);
        listaEstadias[Max_estadias].setMes(mesEntrada);
        listaEstadias[Max_estadias].setAno(anoEntrada);

        cout << "Insira a data de SAIDA abaixo: "<< endl;
        cout << "Dia: ";
        cin >> diaSaida;

        cout << "Mes:";
        cin >> mesSaida;

        cout << "Ano:";
        cin >> anoSaida;

        listaEstadias[Max_estadias].setDia(diaSaida);
        listaEstadias[Max_estadias].setMes(mesSaida);
        listaEstadias[Max_estadias].setAno(anoSaida);

        QuantidadeDiarias = diaSaida - diaEntrada; //calculo prévio, pois deve-se considerar mes, dia e ano no calculo correto (vou fazer depois)

        listaEstadias[Max_estadias].setCodigoEstadia(ContadorEstadias + 1);
        listaEstadias[Max_estadias].setQuantidadeDiarias(QuantidadeDiarias);

        //Busca no vetor um quarto existente e disponivel e um cliente existente

        //lista os cluentes cadastrados
        listarClientesCadastrados(listaClientes); //chama a função que lista os clientes

        int codigo, numero;

        cout << "Insira o seu codigo de cliente: ";
        cin >> codigo;

        cout << "Insira um numero de quarto: ";
        cin >> numero;

        Cliente *encontrado = buscarClientes(listaClientes,codigo);
        Quarto *EncontrarQuarto = BuscarQuarto(listaQuartos, numero);
        Quarto *verOcupacao = VerificaOcupacao(listaEstadias, numero);

        if(encontrado!=NULL && EncontrarQuarto!=NULL && verOcupacao!=NULL){ //verifica se é possível realizar o cadastro da estadia

            listaEstadias[Max_estadias].setCodigoCliente(encontrado);
            listaEstadias[Max_estadias].Mostrar(); //mostra o nome e codigo da pessoa
            listaEstadias[Max_estadias].setNumeroQuarto(EncontrarQuarto);
            listaEstadias[Max_estadias].MostraQuarto(); //mostra o código do quarto

            
        }else{
            cout << "Cliente nao encontrado!\n";
        }

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
        listaQuartos[ContadorQuartos].setNumeroQuarto(ContadorQuartos+1); //define número do quarto automaticamente
        listaQuartos[ContadorQuartos].setStatus(status);
        ContadorQuartos++;

        cout << "Cadastro realizado com sucesso " << endl;
    }else{
        cout << "Limite de cadastro excedido. " << endl;
    }

    cout << "------------------------------------------------" << endl;
}

Quarto *BuscarQuarto(Quarto listaQuartos[Max_Quartos], int numero){
    for(int i=0;i<Max_Quartos;i++){
        if(listaQuartos[i].getNumeroQuarto()==numero){ //quarto encontrado!
            return &listaQuartos[i];
        }
    }

    return NULL;
}

Quarto *VerificaOcupacao(Quarto listaQuartos[Max_Quartos], int numero){
    for(int i=0;i<Max_Quartos;i++){
        if(listaQuartos[i].getNumeroQuarto()==numero){ //quarto desocupado!
            if(listaQuartos[i].getStatus()==true){
                cout << "Quarto desocupado!" << endl;
                return &listaQuartos[i];
            }
        }
        
    }
    cout << "Quarto ocupado!" << endl;

    return NULL;
}

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


void MostrarEstadias(){

}

/*
procedimento antigo (não funciona)

void ListarQuartosDisponiveis(Quarto listaQuartos[Max_Quartos], int numero){
    int cont=0;
    Quarto *verificar = VerificaOcupacao(listaQuartos, numero);
    cout << "Lista de quartos disponiveis do hotel: "<<endl;
    for(int i=0;i<ContadorQuartos;i++){
        if(verificar!=NULL){
           //cout << "Numero do quarto: ";
        }
    }
}

*/

