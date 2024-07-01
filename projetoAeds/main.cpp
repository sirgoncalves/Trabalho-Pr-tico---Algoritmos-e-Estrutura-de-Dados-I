#include "Pessoa.h"
#include "Cliente.h"
#include "Funcionario.h"
#include "Quarto.h"
#include "Estadia.h"
#include "Hotel.h"


int main() {
  Hotel hotel; // Inst�ncia da classe Hotel para gerenciar todas as opera��es

  int opcao; // Vari�vel para armazenar a op��o do menu escolhida pelo usu�rio

  // Loop do menu principal
  do {
    // Exibi��o das op��es do menu
    std::cout << "Menu:\n";
    std::cout << "1. Cadastrar Cliente\n";
    std::cout << "2. Cadastrar Funcion�rio\n";
    std::cout << "3. Cadastrar Quarto\n";
    std::cout << "4. Cadastrar Estadia\n";
    std::cout << "5. Dar Baixa em Estadia\n";
    std::cout << "6. Pesquisar Cliente por Nome ou C�digo\n";
    std::cout << "7. Pesquisar Funcion�rio por Nome ou C�digo\n";
    std::cout << "8. Mostrar Estadias de um Cliente\n";
    std::cout << "9. Calcular Pontos de Fidelidade de um Cliente\n";
    std::cout << "10. Mostrar lista de quartos\n";
    std::cout << "11. Listar funcionarios\n";
    std::cout << "12. Remover funcionario\n";
    std::cout << "13. Remover Cliente\n";
    std::cout << "14. Listar Clientes\n";
    std::cout << "0. Sair\n";
    std::cout << "Escolha uma op��o: ";
    std::cin >> opcao; // Leitura da op��o escolhida pelo usu�rio

    switch (opcao) {
    case 1: { // Op��o para cadastrar cliente
      std::string nome, telefone, endereco;
      std::cout << "Nome: ";
      std::cin.ignore();            // Ignora o '\n' residual do buffer
      std::getline(std::cin, nome); // L� o nome completo (com espacos)
      std::cout << "Telefone: ";
      std::getline(std::cin, telefone); // L� o telefone
      std::cout << "Endere�o: ";
      std::getline(std::cin, endereco); // L� o endere�o
      hotel.cadastrarCliente(
          nome, telefone,
          endereco); // Chama o m�todo de cadastro na classe Hotel-
      break;
    }
    case 2: { // Op��o para cadastrar funcion�rio
      std::string nome, telefone, cargo;
      double salario;
      std::cout << "N�o deixe nenhum campo vazio\n";
      std::cout << "Nome: ";
      std::cin.ignore();            // Ignora o '\n' residual do buffer
      std::getline(std::cin, nome); // L� o nome completo (com espacos)
      std::cout << "Telefone: ";
      std::getline(std::cin, telefone); // L� o telefone
      std::cout << "Cargo: ";
      std::getline(std::cin, cargo); // L� o cargo
      std::cout << "Sal�rio: ";
      std::cin >> salario; // L� o sal�rio
      hotel.cadastrarFuncionario(
          nome, telefone, cargo,
          salario); // Chama o m�todo de cadastro na classe Hotel
      break;
    }
    case 3: { // Op��o para cadastrar quarto
      int numero, qtdHospedes;
      double valorDiaria;
      std::cout << "N�mero do Quarto: ";
      std::cin >> numero; // L� o n�mero do quarto
      std::cout << "Quantidade de H�spedes: ";
      std::cin >> qtdHospedes; // L� a capacidade do quarto em h�spedes
      std::cout << "Valor da Di�ria: ";
      std::cin >> valorDiaria; // L� o valor da di�ria do quarto
      hotel.cadastrarQuarto(
          numero, qtdHospedes,
          valorDiaria); // Chama o m�todo de cadastro na classe Hotel
      break;
    }
    case 4: { // Op��o para cadastrar estadia
      int codCliente, qtdHospedes, qtdDiarias;
      std::string dataEntrada, dataSaida;
      std::cout << "C�digo do Cliente: ";
      std::cin >> codCliente; // L� o c�digo do cliente
      std::cout << "Data de Entrada (DD/MM/AAAA): ";
      std::cin.ignore();                   // Ignora o '\n' residual do buffer
      std::getline(std::cin, dataEntrada); // L� a data de entrada
      std::cout << "Data de Sa�da (DD/MM/AAAA): ";
      std::getline(std::cin, dataSaida); // L� a data de sa�da
      std::cout << "Quantidade de H�spedes: ";
      std::cin >> qtdHospedes; // L� a quantidade de h�spedes
      std::cout << "Quantidade de Di�rias: ";
      std::cin >> qtdDiarias; // L� a quantidade de di�rias
      hotel.cadastrarEstadia(
          codCliente, dataEntrada, dataSaida, qtdDiarias,
          qtdHospedes); // Chama o m�todo de cadastro na classe Hotel
      break;
    }
    case 5: { // Op��o para dar baixa em estadia
      int codigoEstadia;
      std::cout << "C�digo da Estadia: ";
      std::cin >> codigoEstadia;            // L� o c�digo da estadia
      hotel.darBaixaEstadia(codigoEstadia); // Chama o m�todo para dar baixa na
                                            // estadia na classe Hotel
      break;
    }
    case 6: { // Op��o para pesquisar cliente por nome ou c�digo
      std::string nome;
      int codigo;
      std::cout << "Nome do Cliente (deixe em branco se n�o quiser pesquisar "
                   "por nome): ";
      std::cin.ignore();            // Ignora o '\n' residual do buffer
      std::getline(std::cin, nome); // L� o nome completo (com espacos)
      std::cout
          << "C�digo do Cliente (deixe 0 se n�o quiser pesquisar por c�digo): ";
      std::cin >> codigo; // L� o c�digo do cliente
      hotel.pesquisarClientePorNomeOuCodigo(
          nome, codigo); // Chama o m�todo de pesquisa na classe Hotel
      break;
    }
    case 7: { // Op��o para pesquisar funcion�rio por nome ou c�digo
      std::string nome;
      int codigo;
      std::cout << "Nome do Funcion�rio (deixe em branco se n�o quiser "
                   "pesquisar por nome): ";
      std::cin.ignore();            // Ignora o '\n' residual do buffer
      std::getline(std::cin, nome); // L� o nome completo (com espacos)
      std::cout << "C�digo do Funcion�rio (deixe 0 se n�o quiser pesquisar por "
                   "c�digo): ";
      std::cin >> codigo; // L� o c�digo do funcion�rio
      hotel.pesquisarFuncionarioPorNomeOuCodigo(
          nome, codigo); // Chama o m�todo de pesquisa na classe Hotel
      break;
    }
    case 8: { // Op��o para mostrar estadias de um cliente
      int codigoCliente;
      std::cout << "C�digo do Cliente: ";
      std::cin >> codigoCliente; // L� o c�digo do cliente
      hotel.mostrarEstadiasCliente(
          codigoCliente); // Chama o m�todo para mostrar estadias na classe
                          // Hotel
      break;
    }
    case 9: { // Op��o para calcular pontos de fidelidade de um cliente
      int codigoCliente;
      std::cout << "C�digo do Cliente: ";
      std::cin >> codigoCliente; // L� o c�digo do cliente
      std::cout << "Pontos de Fidelidade do Cliente: "
                << hotel.calcularPontosFidelidade(codigoCliente)
                << std::endl; // Chama o m�todo para calcular pontos de
                              // fidelidade na classe Hotel
      break;
    }
    case 10: {                     // Op��o para mostrar lista de quartos
      hotel.mostrarListaQuartos(); // Chama o m�todo para mostrar a lista de
                                   // quartos na classe Hotel
      break;
    }
    case 11: {                    // Op��o para listar funcion�rios
      hotel.listarFuncionarios(); // Chama o m�todo para listar funcion�rios na
                                  // classe Hotel
      break;
    }
    case 12: { // Op��o para remover funcion�rio
      int codigo;
      std::cout << "Digite o c�digo do funcion�rio a ser removido: ";
      std::cin >> codigo; // L� o c�digo do funcion�rio a ser removido
      hotel.deletarFuncionario(
          codigo); // Chama o m�todo para remover funcion�rio na classe Hotel
      break;
    }
    case 13: { // Op��o para remover cliente
      int codigo;
      std::cout << "Digite o c�digo do cliente a ser removido: ";
      std::cin >> codigo; // L� o c�digo do cliente a ser removido
                          // hotel.deletarCliente(codigo); // Chama o m�todo
                          // para remover cliente na classe Hotel
      break;
    }
    case 14: {                // Op��o para listar clientes
      hotel.listarClientes(); // Chama o m�todo para listar clientes na classe
                              // Hotel
      break;
    }
    case 0: // Op��o para sair do programa
      std::cout << "Saindo...\n";
      break;
    default: // Tratamento de op��o inv�lida
      std::cout << "Op��o inv�lida!\n";
    }
  } while (opcao != 0); // Continua executando o loop enquanto a op��o escolhida
                        // n�o for 0 (sair do programa)

  return 0;
}
