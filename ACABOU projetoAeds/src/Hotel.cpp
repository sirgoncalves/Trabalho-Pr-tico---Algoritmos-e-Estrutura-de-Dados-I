#include "Hotel.h"

int Hotel::gerarCodigoCliente() { return clientes.size() + 1; }
int Hotel::gerarCodigoFuncionario() { return funcionarios.size() + 1; }
int Hotel::gerarCodigoEstadia() { return estadias.size() + 1; }



void Hotel::salvarClientes(const std::string &filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
      for (const auto &cliente : clientes) {
        cliente.salvar(file); // Chama o método salvar de cada cliente
      }
      file.close();
    } else {
      std::cerr << "Erro ao abrir o arquivo " << filename << " para escrita."
                << std::endl;
    }
  }

   void Hotel::carregarClientes(const std::string &filename) {
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open()) {
      while (!file.eof()) {
        Cliente cliente(0, "", "",
                        "");    // Cliente temporário para carregar dados
        cliente.carregar(file); // Chama o método carregar de cada cliente
        if (!file.eof()) {
          clientes.push_back(cliente); // Adiciona cliente ao vetor
        }
      }
      file.close();
    } else {
      std::cerr << "Erro ao abrir o arquivo " << filename << " para leitura."
                << std::endl;
    }
  }

  bool Hotel::existeCargo(const std::string &cargo) const {
    auto it = std::find_if(
        funcionarios.begin(), funcionarios.end(),
        [&](const Funcionario &f) { return f.getCargo() == cargo; });
    return it != funcionarios.end();
  }

    void Hotel::salvarFuncionarios(const std::string &filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
      for (const auto &funcionario : funcionarios) {
        funcionario.salvar(file); // Chama o método salvar de cada funcionário
      }
      file.close();
    } else {
      std::cerr << "Erro ao abrir o arquivo " << filename << " para escrita."
                << std::endl;
    }
  }

     void  Hotel::carregarFuncionarios(const std::string &filename) {
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open()) {
      while (!file.eof()) {
        Funcionario funcionario(
            0, "", "", "", 0.0); // Funcionário temporário para carregar dados
        funcionario.carregar(
            file); // Chama o método carregar de cada funcionário
        if (!file.eof()) {
          funcionarios.push_back(funcionario); // Adiciona funcionário ao vetor
        }
      }
      file.close();
    } else {
      std::cerr << "Erro ao abrir o arquivo " << filename << " para leitura."
                << std::endl;
    }
  }

    void Hotel::salvarEstadias(const std::string &filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
      for (const auto &estadia : estadias) {
        estadia.salvar(file); // Chama o método salvar de cada estadia
      }
      file.close();
    } else {
      std::cerr << "Erro ao abrir o arquivo " << filename << " para escrita."
                << std::endl;
    }
  }

    void Hotel::carregarEstadias(const std::string &filename) {
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open()) {
      while (!file.eof()) {
        Estadia estadia(0, "", "", 0, 0,
                        0);     // Estadia temporária para carregar dados
        estadia.carregar(file); // Chama o método carregar de cada estadia
        if (!file.eof()) {
          estadias.push_back(estadia); // Adiciona estadia ao vetor
        }
      }
      file.close();
    } else {
      std::cerr << "Erro ao abrir o arquivo " << filename << " para leitura."
                << std::endl;
    }
  }

    // Salvar e carregar dados de quartos
    void Hotel::salvarQuartos(const std::string &filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
      for (const auto &quarto : quartos) {
        quarto.salvar(file); // Chama o método salvar de cada quarto
      }
      file.close();
    } else {
      std::cerr << "Erro ao abrir o arquivo " << filename << " para escrita."
                << std::endl;
    }
  }

  void Hotel::carregarQuartos(const std::string &filename) {
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open()) {
      while (!file.eof()) {
        Quarto quarto(0, 0, 0.0); // Quarto temporário para carregar dados
        quarto.carregar(file);    // Chama o método carregar de cada quarto
        if (!file.eof()) {
          quartos.push_back(quarto); // Adiciona quarto ao vetor
        }
      }
      file.close();
    } else {
      std::cerr << "Erro ao abrir o arquivo " << filename << " para leitura."
                << std::endl;
    }
  }

     // Método para mostrar lista de quartos
    void Hotel::mostrarListaQuartos() const {
    std::cout << "Lista de Quartos:" << std::endl;
    for (const auto &quarto : quartos) {
      std::cout << "Numero: " << quarto.getNumero() << std::endl;
      std::cout << "Capacidade: " << quarto.getQuantidadeHospedes()
                << " pessoas" << std::endl;
      std::cout << "Valor da Diaria: R$ " << std::fixed << std::setprecision(2)
                << quarto.getValorDiaria() << std::endl;
      std::cout << "Ocupado: " << (quarto.isOcupado() ? "Sim" : "Nao")
                << std::endl;
      std::cout << "-------------------------" << std::endl;
    }
  }

    // Método para cadastrar um novo cliente
    void Hotel::cadastrarCliente(const std::string &nome, const std::string &telefone,
                        const std::string &endereco) {
    if (nome.empty() || telefone.empty() || endereco.empty()) {
      std::cerr << "Erro: Nenhum dos campos pode estar vazio." << std::endl;
      return;
    }
    int codigo = gerarCodigoCliente();
    clientes.emplace_back(codigo, nome, telefone, endereco);
    std::cout << "Cliente cadastrado com sucesso." << std::endl;
  }

    // Método para deletar um funcionário pelo código
    void Hotel::deletarFuncionario(int codigo) {
    auto it = std::find_if(funcionarios.begin(), funcionarios.end(),
                           [codigo](const Funcionario &funcionario) {
                             return funcionario.getCodigo() == codigo;
                           });

    if (it != funcionarios.end()) {
      funcionarios.erase(it);
      std::cout << "Funcionario removido com sucesso." << std::endl;
    } else {
      std::cerr << "Funcionario não encontrado." << std::endl;
    }
  }
    // Método para listar todos os clientes
    void Hotel::listarClientes() const {
    std::cout << "Lista de Clientes:" << std::endl;
    for (const auto &cliente : clientes) {
      std::cout << "Codigo: " << cliente.getCodigo() << std::endl;
      std::cout << "Nome: " << cliente.getNome() << std::endl;
      std::cout << "Telefone: " << cliente.getTelefone() << std::endl;
      std::cout << "Endereço: " << cliente.getEndereco() << std::endl;
      std::cout << "-------------------------" << std::endl;
    }
  }

     // Método para deletar um cliente pelo código
     void Hotel::deletarCliente(int codigo) {
    auto it = std::find_if(clientes.begin(), clientes.end(),
                           [codigo](const Cliente &cliente) {
                             return cliente.getCodigo() == codigo;
                           });

    if (it != clientes.end()) {
      clientes.erase(it);
      std::cout << "Cliente removido com sucesso." << std::endl;
    } else {
      std::cerr << "Cliente nao encontrado." << std::endl;
    }
  }

    // Método para verificar se um funcionário possui determinado cargo
    void Hotel::checkFuncionarioCargo(const Funcionario &funcionario,
                             const std::string &cargoToCheck) {
    if (funcionario.getCargo() == cargoToCheck) {
      std::cout << "Funcionario " << funcionario.getNome()
                << " tem o cargo: " << cargoToCheck << std::endl;
    } else {
      std::cout << "Funcionario " << funcionario.getNome()
                << " não tem o cargo: " << cargoToCheck << std::endl;
    }
  }

    // Método para listar todos os funcionários
    void Hotel::listarFuncionarios() const {
    std::cout << "Lista de Funcionarios:" << std::endl;
    for (const auto &funcionario : funcionarios) {
      std::cout << "Codigo: " << funcionario.getCodigo() << std::endl;
      std::cout << "Nome: " << funcionario.getNome() << std::endl;
      std::cout << "Telefone: " << funcionario.getTelefone() << std::endl;
      std::cout << "Cargo: " << funcionario.getCargo() << std::endl;
      std::cout << "Salário: R$ " << std::fixed << std::setprecision(2)
                << funcionario.getSalario() << std::endl;
      std::cout << "-------------------------" << std::endl;
    }
  }

    // Método para cadastrar um novo funcionário
    void Hotel::cadastrarFuncionario(const std::string &nome,
                            const std::string &telefone,
                            const std::string &cargo, double salario) {

    if (nome.empty() || telefone.empty() || cargo.empty() || salario <= 0.0) {
      std::cerr << "Erro: Nenhum dos campos pode estar vazio e o salario deve "
                   "ser maior que zero."
                << std::endl;
      return;
    }

    if (cargoExists(cargo)) {
      std::cout << "Cargo " << cargo
                << " ja existe. Nao foi possível cadastrar o funcionario."
                << std::endl;
    } else {
      int codigo = gerarCodigoFuncionario();
      funcionarios.emplace_back(codigo, nome, telefone, cargo, salario);
      std::cout << "Funcionario cadastrado com sucesso." << std::endl;
    }
  }

    // Método para gerar código único para funcionários
    int Hotel::gerarCodigoFuncionario() const {
    static int proximoCodigo = 1;
    return proximoCodigo++;
  }

     // Método para verificar se um cargo de funcionário já existe
     bool Hotel::cargoExists(const std::string &cargo) {
     for (const auto &funcionario : funcionarios) {
      if (funcionario.getCargo() == cargo) {
        return true;
      }
    }
    return false;
  }
    // Método para cadastrar um novo quarto
    void Hotel::cadastrarQuarto(int numero, int qtdHospedes, double valorDiaria) {
    if (numero <= 0 || qtdHospedes <= 0 || valorDiaria <= 0.0) {
        std::cerr << "Erro: Todos os campos devem ser preenchidos com valores válidos." << std::endl;
        return;
    }
    quartos.emplace_back(numero, qtdHospedes, valorDiaria);
    std::cout << "Quarto cadastrado com sucesso." << std::endl;
}

    // Método para cadastrar uma nova estadia
   void Hotel::cadastrarEstadia(int codCliente, const std::string &dataEntrada, const std::string &dataSaida,
                             int quantidadeDiarias, int qtdHospedes) {
    if (dataEntrada.empty() || dataSaida.empty() || quantidadeDiarias <= 0 || qtdHospedes <= 0) {
        std::cerr << "Erro: Nenhum dos campos pode estar vazio ou ter valores inválidos." << std::endl;
        return;
    }

    int numeroQuarto = -1; // Lógica para escolher quarto disponível
    for (auto &quarto : quartos) {
        if (!quarto.isOcupado() && quarto.getQuantidadeHospedes() >= qtdHospedes) {
            numeroQuarto = quarto.getNumero();
            quarto.setOcupado(true);
            break;
        }
    }

    if (numeroQuarto == -1) {
        std::cerr << "Erro: Nenhum quarto disponível para a quantidade de hóspedes especificada." << std::endl;
        return;
    }

    // Logic to store the stay, if needed
    std::cout << "Estadia cadastrada com sucesso no quarto " << numeroQuarto << "." << std::endl;
}
    // Método para dar baixa em uma estadia pelo código da estadia
    void Hotel::darBaixaEstadia(int codigoEstadia) {
    auto it = std::find_if(estadias.begin(), estadias.end(),
                           [codigoEstadia](const Estadia &estadia) {
                             return estadia.getCodigoEstadia() == codigoEstadia;
                           });

    if (it != estadias.end()) {
      int numeroQuarto = it->getNumeroQuarto();
      double valorDiaria = -1.0;

      // Encontra o valor da diária do quarto ocupado
      for (const auto &quarto : quartos) {
        if (quarto.getNumero() == numeroQuarto) {
          valorDiaria = quarto.getValorDiaria();
          break;
        }
      }

      if (valorDiaria < 0.0) {
        std::cerr << "Erro: Quarto da estadia nao encontrado." << std::endl;
        return;
      }

      // Calcula o valor total da estadia
      double valorTotal = it->getQuantidadeDiarias() * valorDiaria;

      // Define o quarto como desocupado
      for (auto &quarto : quartos) {
        if (quarto.getNumero() == numeroQuarto) {
          quarto.setOcupado(false);
          break;
        }
      }
      // Mostra o valor a ser pago
      std::cout << "Valor a ser pago pela estadia: R$ " << std::fixed
                << std::setprecision(2) << valorTotal << std::endl;
    } else {
      std::cerr << "Estadia nao encontrada." << std::endl;
    }
  }


     // Método para pesquisar cliente por nome ou código
     void Hotel::pesquisarClientePorNomeOuCodigo(const std::string &nome,
                                       int codigo) const {
    if (codigo != 0) {
      auto it = std::find_if(clientes.begin(), clientes.end(),
                             [codigo](const Cliente &cliente) {
                               return cliente.getCodigo() == codigo;
                             });

      if (it != clientes.end()) {
        std::cout << "Cliente encontrado: " << it->getNome()
                  << ", Telefone: " << it->getTelefone()
                  << ", Endereco: " << it->getEndereco() << std::endl;
      } else {
        std::cerr << "Cliente nao encontrado." << std::endl;
      }
    } else {
      auto it = std::find_if(
          clientes.begin(), clientes.end(),
          [nome](const Cliente &cliente) { return cliente.getNome() == nome; });

      if (it != clientes.end()) {
        std::cout << "Cliente encontrado: " << it->getNome()
                  << ", Telefone: " << it->getTelefone()
                  << ", Endereco: " << it->getEndereco() << std::endl;
      } else {
        std::cerr << "Cliente nao encontrado." << std::endl;
      }
    }
  }

    // Método para pesquisar funcionário por nome ou código
    void Hotel::pesquisarFuncionarioPorNomeOuCodigo(const std::string &nome,
                                           int codigo) const {
    if (codigo != 0) {
      auto it = std::find_if(funcionarios.begin(), funcionarios.end(),
                             [codigo](const Funcionario &funcionario) {
                               return funcionario.getCodigo() == codigo;
                             });
      if (it != funcionarios.end()) {
        std::cout << "Funcionário encontrado: " << it->getNome()
                  << ", Telefone: " << it->getTelefone()
                  << ", Cargo: " << it->getCargo()
                  << ", Salario: " << it->getSalario() << std::endl;
      } else {
        std::cerr << "Funcionario não encontrado." << std::endl;
      }
    } else {
      auto it = std::find_if(funcionarios.begin(), funcionarios.end(),
                             [nome](const Funcionario &funcionario) {
                               return funcionario.getNome() == nome;
                             });

      if (it != funcionarios.end()) {
        std::cout << "Funcionario encontrado: " << it->getNome()
                  << ", Telefone: " << it->getTelefone()
                  << ", Cargo: " << it->getCargo()
                  << ", Salario: " << it->getSalario() << std::endl;
      } else {
        std::cerr << "Funcionario não encontrado." << std::endl;
      }
    }
  }

    // Método para mostrar estadias de um cliente pelo código do cliente
    void Hotel::mostrarEstadiasCliente(int codigoCliente) const {
    auto it = std::find_if(clientes.begin(), clientes.end(),
                           [codigoCliente](const Cliente &cliente) {
                             return cliente.getCodigo() == codigoCliente;
                           });

    if (it != clientes.end()) {
      std::cout << "Estadias do cliente " << it->getNome() << ":" << std::endl;
      for (const auto &estadia : estadias) {
        if (estadia.getCodigoCliente() == codigoCliente) {
          std::cout << "Codigo da Estadia: " << estadia.getCodigoEstadia()
                    << ", Quarto: " << estadia.getNumeroQuarto()
                    << ", Data de Entrada: " << estadia.getDataEntrada()
                    << ", Data de Saida: " << estadia.getDataSaida()
                    << std::endl;
        }
      }
    } else {
      std::cerr << "Cliente nao encontrado." << std::endl;
    }
  }

  // Método para calcular pontos de fidelidade de um cliente pelo código do cliente
  int Hotel::calcularPontosFidelidade(int codigoCliente) const {
    int pontos = 0;
    for (const auto &estadia : estadias) {
      if (estadia.getCodigoCliente() == codigoCliente) {
        pontos += estadia.getQuantidadeDiarias() * 10;
      }
    }
    return pontos;
  }




