//o main está incompleto
#include "Classes.cpp"
#include "FuncoesEProcedimentos.cpp"
#include <iostream>

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
        cout << "6 - Listar estadias\n";
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
                cadastrarQuarto(QuartosHotel);
                break;
            }
            case 7: {
                cout << "Ate logo!";
                break;
            }
            default:
                cout << "Opcao invalida!";
                break;
        }

    } while (opcao != 0);

    return 0;
}
