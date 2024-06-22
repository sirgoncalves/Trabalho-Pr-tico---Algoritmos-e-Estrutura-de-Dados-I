#include "Classes.cpp"
#include "FuncoesEProcedimentos.cpp"
#include <iostream>

int main() {
    int opcao;
    Cliente ClientesDoHotel[Max_Clientes]; //vetor para armazenar pessoas
    //char Funcionarios[n];
    
    do {
        cout << "Bem-Vindo!\n";
        cout << "Escolha uma opcao: \n";
        cout << "1 - Cadastrar Cliente\n";
        cout << "2 - Cadastrar Funcionario\n";
        cout << "3 - Obter Uma Estadia\n";
        cout << "4 - Sair\n";
        cin >> opcao;
        cout << "-------------------------------------\n";

        switch (opcao) {
            case 1: {
                // Implementar cadastro de cliente
                break;
            }
            case 2: {
                // Implementar cadastro de funcionário
                break;
            }
            case 3: {
                // Implementar obtenção de estadia
                break;
            }
            default:
                break;
        }

    } while (opcao != 4);

    return 0;
}


/*
void CadastrarClientes(Cliente listaClientes[Max_Clientes]){
    char nome[80];
    if(ContadorPessoas<Max_Clientes){
        cout << "Cadastrando Clientes " << endl;
        cout << "Insira seu nome: " <<endl;
        cin >> nome;
        fflush(stdin);
        listaVeiculos[ContadorPessoas].setNome(nome);
        listaVeiculos[ContadorPessoas].setCodigo(novoCodigo+1);
    }
}
*/
