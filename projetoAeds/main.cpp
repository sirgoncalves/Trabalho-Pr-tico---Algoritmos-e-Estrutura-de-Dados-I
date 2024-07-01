#include "Pessoa.h"
#include "Cliente.h"
#include "Funcionario.h"
#include "Quarto.h"
#include "Estadia.h"
#include "Hotel.h"


int main() {
  Hotel hotel; // Instância da classe Hotel para gerenciar todas as operações

  int opcao; // Variável para armazenar a opção do menu escolhida pelo usuário

  // Loop do menu principal
  do {
    // Exibição das opções do menu
    std::cout << "Menu:\n";
    std::cout << "1. Cadastrar Cliente\n";
    std::cout << "2. Cadastrar Funcionário\n";
    std::cout << "3. Cadastrar Quarto\n";
    std::cout << "4. Cadastrar Estadia\n";
    std::cout << "5. Dar Baixa em Estadia\n";
    std::cout << "6. Pesquisar Cliente por Nome ou Código\n";
    std::cout << "7. Pesquisar Funcionário por Nome ou Código\n";
    std::cout << "8. Mostrar Estadias de um Cliente\n";
    std::cout << "9. Calcular Pontos de Fidelidade de um Cliente\n";
    std::cout << "10. Mostrar lista de quartos\n";
    std::cout << "11. Listar funcionarios\n";
    std::cout << "12. Remover funcionario\n";
    std::cout << "13. Remover Cliente\n";
    std::cout << "14. Listar Clientes\n";
    std::cout << "0. Sair\n";
    std::cout << "Escolha uma opção: ";
    std::cin >> opcao; // Leitura da opção escolhida pelo usuário

    switch (opcao) {
    case 1: { // Opção para cadastrar cliente
      std::string nome, telefone, endereco;
      std::cout << "Nome: ";
      std::cin.ignore();            // Ignora o '\n' residual do buffer
      std::getline(std::cin, nome); // Lê o nome completo (com espacos)
      std::cout << "Telefone: ";
      std::getline(std::cin, telefone); // Lê o telefone
      std::cout << "Endereço: ";
      std::getline(std::cin, endereco); // Lê o endereço
      hotel.cadastrarCliente(
          nome, telefone,
          endereco); // Chama o método de cadastro na classe Hotel-
      break;
    }
    case 2: { // Opção para cadastrar funcionário
      std::string nome, telefone, cargo;
      double salario;
      std::cout << "Não deixe nenhum campo vazio\n";
      std::cout << "Nome: ";
      std::cin.ignore();            // Ignora o '\n' residual do buffer
      std::getline(std::cin, nome); // Lê o nome completo (com espacos)
      std::cout << "Telefone: ";
      std::getline(std::cin, telefone); // Lê o telefone
      std::cout << "Cargo: ";
      std::getline(std::cin, cargo); // Lê o cargo
      std::cout << "Salário: ";
      std::cin >> salario; // Lê o salário
      hotel.cadastrarFuncionario(
          nome, telefone, cargo,
          salario); // Chama o método de cadastro na classe Hotel
      break;
    }
    case 3: { // Opção para cadastrar quarto
      int numero, qtdHospedes;
      double valorDiaria;
      std::cout << "Número do Quarto: ";
      std::cin >> numero; // Lê o número do quarto
      std::cout << "Quantidade de Hóspedes: ";
      std::cin >> qtdHospedes; // Lê a capacidade do quarto em hóspedes
      std::cout << "Valor da Diária: ";
      std::cin >> valorDiaria; // Lê o valor da diária do quarto
      hotel.cadastrarQuarto(
          numero, qtdHospedes,
          valorDiaria); // Chama o método de cadastro na classe Hotel
      break;
    }
    case 4: { // Opção para cadastrar estadia
      int codCliente, qtdHospedes, qtdDiarias;
      std::string dataEntrada, dataSaida;
      std::cout << "Código do Cliente: ";
      std::cin >> codCliente; // Lê o código do cliente
      std::cout << "Data de Entrada (DD/MM/AAAA): ";
      std::cin.ignore();                   // Ignora o '\n' residual do buffer
      std::getline(std::cin, dataEntrada); // Lê a data de entrada
      std::cout << "Data de Saída (DD/MM/AAAA): ";
      std::getline(std::cin, dataSaida); // Lê a data de saída
      std::cout << "Quantidade de Hóspedes: ";
      std::cin >> qtdHospedes; // Lê a quantidade de hóspedes
      std::cout << "Quantidade de Diárias: ";
      std::cin >> qtdDiarias; // Lê a quantidade de diárias
      hotel.cadastrarEstadia(
          codCliente, dataEntrada, dataSaida, qtdDiarias,
          qtdHospedes); // Chama o método de cadastro na classe Hotel
      break;
    }
    case 5: { // Opção para dar baixa em estadia
      int codigoEstadia;
      std::cout << "Código da Estadia: ";
      std::cin >> codigoEstadia;            // Lê o código da estadia
      hotel.darBaixaEstadia(codigoEstadia); // Chama o método para dar baixa na
                                            // estadia na classe Hotel
      break;
    }
    case 6: { // Opção para pesquisar cliente por nome ou código
      std::string nome;
      int codigo;
      std::cout << "Nome do Cliente (deixe em branco se não quiser pesquisar "
                   "por nome): ";
      std::cin.ignore();            // Ignora o '\n' residual do buffer
      std::getline(std::cin, nome); // Lê o nome completo (com espacos)
      std::cout
          << "Código do Cliente (deixe 0 se não quiser pesquisar por código): ";
      std::cin >> codigo; // Lê o código do cliente
      hotel.pesquisarClientePorNomeOuCodigo(
          nome, codigo); // Chama o método de pesquisa na classe Hotel
      break;
    }
    case 7: { // Opção para pesquisar funcionário por nome ou código
      std::string nome;
      int codigo;
      std::cout << "Nome do Funcionário (deixe em branco se não quiser "
                   "pesquisar por nome): ";
      std::cin.ignore();            // Ignora o '\n' residual do buffer
      std::getline(std::cin, nome); // Lê o nome completo (com espacos)
      std::cout << "Código do Funcionário (deixe 0 se não quiser pesquisar por "
                   "código): ";
      std::cin >> codigo; // Lê o código do funcionário
      hotel.pesquisarFuncionarioPorNomeOuCodigo(
          nome, codigo); // Chama o método de pesquisa na classe Hotel
      break;
    }
    case 8: { // Opção para mostrar estadias de um cliente
      int codigoCliente;
      std::cout << "Código do Cliente: ";
      std::cin >> codigoCliente; // Lê o código do cliente
      hotel.mostrarEstadiasCliente(
          codigoCliente); // Chama o método para mostrar estadias na classe
                          // Hotel
      break;
    }
    case 9: { // Opção para calcular pontos de fidelidade de um cliente
      int codigoCliente;
      std::cout << "Código do Cliente: ";
      std::cin >> codigoCliente; // Lê o código do cliente
      std::cout << "Pontos de Fidelidade do Cliente: "
                << hotel.calcularPontosFidelidade(codigoCliente)
                << std::endl; // Chama o método para calcular pontos de
                              // fidelidade na classe Hotel
      break;
    }
    case 10: {                     // Opção para mostrar lista de quartos
      hotel.mostrarListaQuartos(); // Chama o método para mostrar a lista de
                                   // quartos na classe Hotel
      break;
    }
    case 11: {                    // Opção para listar funcionários
      hotel.listarFuncionarios(); // Chama o método para listar funcionários na
                                  // classe Hotel
      break;
    }
    case 12: { // Opção para remover funcionário
      int codigo;
      std::cout << "Digite o código do funcionário a ser removido: ";
      std::cin >> codigo; // Lê o código do funcionário a ser removido
      hotel.deletarFuncionario(
          codigo); // Chama o método para remover funcionário na classe Hotel
      break;
    }
    case 13: { // Opção para remover cliente
      int codigo;
      std::cout << "Digite o código do cliente a ser removido: ";
      std::cin >> codigo; // Lê o código do cliente a ser removido
                          // hotel.deletarCliente(codigo); // Chama o método
                          // para remover cliente na classe Hotel
      break;
    }
    case 14: {                // Opção para listar clientes
      hotel.listarClientes(); // Chama o método para listar clientes na classe
                              // Hotel
      break;
    }
    case 0: // Opção para sair do programa
      std::cout << "Saindo...\n";
      break;
    default: // Tratamento de opção inválida
      std::cout << "Opção inválida!\n";
    }
  } while (opcao != 0); // Continua executando o loop enquanto a opção escolhida
                        // não for 0 (sair do programa)

  return 0;
}
