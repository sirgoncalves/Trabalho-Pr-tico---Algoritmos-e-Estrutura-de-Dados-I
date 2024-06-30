#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Pessoa {
protected:
  int codigo;           // Código único da pessoa
  std::string nome;     // Nome da pessoa
  std::string telefone; // Telefone da pessoa

public:
  // Construtor que inicializa os membros da classe
  Pessoa(int cod, std::string nome, std::string telefone)
      : codigo(cod), nome(nome), telefone(telefone) {}

  // Destrutor virtual para permitir a correta destruição de objetos derivados
  virtual ~Pessoa() {}

  // Método getter para obter o código da pessoa
  int getCodigo() const { return codigo; }

  // Método getter para obter o nome da pessoa
  std::string getNome() const { return nome; }

  // Método getter para obter o telefone da pessoa
  std::string getTelefone() const { return telefone; }

  // Método setter para definir o nome da pessoa
  void setNome(const std::string &nome) { this->nome = nome; }

  // Método setter para definir o telefone da pessoa
  void setTelefone(const std::string &telefone) { this->telefone = telefone; }

  // Método para salvar os dados da pessoa em um fluxo de saída
  virtual void salvar(std::ostream &out) const {
    // Salva o código como um bloco de bytes
    out.write(reinterpret_cast<const char *>(&codigo), sizeof(codigo));
    // Salva o nome como uma sequência de caracteres, incluindo o terminador
    // nulo
    out.write(nome.c_str(), nome.size() + 1);
    // Salva o telefone como uma sequência de caracteres, incluindo o terminador
    // nulo
    out.write(telefone.c_str(), telefone.size() + 1);
  }

  // Método para carregar os dados da pessoa de um fluxo de entrada
  virtual void carregar(std::istream &in) {
    // Lê o código como um bloco de bytes
    in.read(reinterpret_cast<char *>(&codigo), sizeof(codigo));
    // Lê o nome até encontrar um caractere nulo
    std::getline(in >> std::ws, nome, '\0');
    // Lê o telefone até encontrar um caractere nulo
    std::getline(in >> std::ws, telefone, '\0');
  }
};

class Cliente : public Pessoa {
private:
  std::string endereco; // Endereço do cliente

public:
  // Construtor que inicializa os membros da classe Cliente e chama o construtor
  // da classe base Pessoa
  Cliente(int cod, std::string nome, std::string telefone, std::string endereco)
      : Pessoa(cod, nome, telefone), endereco(endereco) {}

  // Método getter para obter o endereço do cliente
  std::string getEndereco() const { return endereco; }

  // Método setter para definir o endereço do cliente
  void setEndereco(const std::string &endereco) { this->endereco = endereco; }

  // Método para salvar os dados do cliente em um fluxo de saída
  void salvar(std::ostream &out) const override {
    Pessoa::salvar(out); // Salva os dados da classe base Pessoa
    out.write(endereco.c_str(),
              endereco.size() + 1); // Salva o endereço como uma sequência de
                                    // caracteres, incluindo o terminador nulo
  }

  // Método para carregar os dados do cliente de um fluxo de entrada
  void carregar(std::istream &in) override {
    Pessoa::carregar(in); // Carrega os dados da classe base Pessoa
    std::getline(in >> std::ws, endereco,
                 '\0'); // Lê o endereço até encontrar um caractere nulo
  }
};

class Funcionario : public Pessoa {
private:
  std::string cargo; // Cargo do funcionário
  double salario;    // Salário do funcionário

public:
  // Construtor que inicializa os membros da classe Funcionario e chama o
  // construtor da classe base Pessoa
  Funcionario(int cod, std::string nome, std::string telefone,
              std::string cargo, double salario)
      : Pessoa(cod, nome, telefone), cargo(cargo), salario(salario) {}

  // Método getter para obter o cargo do funcionário
  std::string getCargo() const { return cargo; }

  // Método getter para obter o salário do funcionário
  double getSalario() const { return salario; }

  // Método setter para definir o cargo do funcionário
  void setCargo(const std::string &cargo) { this->cargo = cargo; }

  // Método setter para definir o salário do funcionário
  void setSalario(double salario) { this->salario = salario; }

  // Método para salvar os dados do funcionário em um fluxo de saída
  void salvar(std::ostream &out) const override {
    Pessoa::salvar(out); // Salva os dados da classe base Pessoa
    out.write(cargo.c_str(),
              cargo.size() + 1); // Salva o cargo como uma sequência de
                                 // caracteres, incluindo o terminador nulo
    out.write(reinterpret_cast<const char *>(&salario),
              sizeof(salario)); // Salva o salário como um bloco de bytes
  }

  // Método para carregar os dados do funcionário de um fluxo de entrada
  void carregar(std::istream &in) override {
    Pessoa::carregar(in); // Carrega os dados da classe base Pessoa
    std::getline(in >> std::ws, cargo,
                 '\0'); // Lê o cargo até encontrar um caractere nulo
    in.read(reinterpret_cast<char *>(&salario),
            sizeof(salario)); // Lê o salário como um bloco de bytes
  }
};

class Quarto {
private:
  int numero;             // Número do quarto
  int quantidadeHospedes; // Quantidade máxima de hóspedes
  double valorDiaria;     // Valor da diária do quarto
  bool ocupado;           // Status de ocupação do quarto

public:
  // Construtor que inicializa os membros da classe Quarto
  Quarto(int num, int qtdHospedes, double valorDiaria)
      : numero(num), quantidadeHospedes(qtdHospedes), valorDiaria(valorDiaria),
        ocupado(false) {}

  // Método getter para obter o número do quarto
  int getNumero() const { return numero; }

  // Método getter para obter a quantidade máxima de hóspedes
  int getQuantidadeHospedes() const { return quantidadeHospedes; }

  // Método getter para obter o valor da diária do quarto
  double getValorDiaria() const { return valorDiaria; }

  // Método getter para verificar se o quarto está ocupado
  bool isOcupado() const { return ocupado; }

  // Método setter para definir o status de ocupação do quarto
  void setOcupado(bool status) { ocupado = status; }

  // Método para salvar os dados do quarto em um fluxo de saída
  void salvar(std::ostream &out) const {
    out.write(reinterpret_cast<const char *>(&numero),
              sizeof(numero)); // Salva o número do quarto
    out.write(reinterpret_cast<const char *>(&quantidadeHospedes),
              sizeof(quantidadeHospedes)); // Salva a quantidade de hóspedes
    out.write(reinterpret_cast<const char *>(&valorDiaria),
              sizeof(valorDiaria)); // Salva o valor da diária
    out.write(reinterpret_cast<const char *>(&ocupado),
              sizeof(ocupado)); // Salva o status de ocupação
  }

  // Método para carregar os dados do quarto de um fluxo de entrada
  void carregar(std::istream &in) {
    in.read(reinterpret_cast<char *>(&numero),
            sizeof(numero)); // Lê o número do quarto
    in.read(reinterpret_cast<char *>(&quantidadeHospedes),
            sizeof(quantidadeHospedes)); // Lê a quantidade de hóspedes
    in.read(reinterpret_cast<char *>(&valorDiaria),
            sizeof(valorDiaria)); // Lê o valor da diária
    in.read(reinterpret_cast<char *>(&ocupado),
            sizeof(ocupado)); // Lê o status de ocupação
  }
};

class Estadia {
private:
  int codigoEstadia;       // Código único da estadia
  std::string dataEntrada; // Data de entrada na estadia
  std::string dataSaida;   // Data de saída da estadia
  int quantidadeDiarias;   // Quantidade de diárias da estadia
  int codigoCliente;       // Código do cliente associado à estadia
  int numeroQuarto;        // Número do quarto associado à estadia

public:
  // Construtor da classe Estadia
  Estadia(int codEstadia, std::string entrada, std::string saida,
          int qtdDiarias, int codCliente, int numQuarto)
      : codigoEstadia(codEstadia), dataEntrada(entrada), dataSaida(saida),
        quantidadeDiarias(qtdDiarias), codigoCliente(codCliente),
        numeroQuarto(numQuarto) {}

  // Métodos getters para acessar os atributos da classe
  int getCodigoEstadia() const { return codigoEstadia; }
  std::string getDataEntrada() const { return dataEntrada; }
  std::string getDataSaida() const { return dataSaida; }
  int getQuantidadeDiarias() const { return quantidadeDiarias; }
  int getCodigoCliente() const { return codigoCliente; }
  int getNumeroQuarto() const { return numeroQuarto; }

  // Método para salvar os dados da estadia em um arquivo binário
  void salvar(std::ostream &out) const {
    // Escreve o código da estadia no arquivo
    out.write(reinterpret_cast<const char *>(&codigoEstadia),
              sizeof(codigoEstadia));
    // Escreve a data de entrada no arquivo
    out.write(dataEntrada.c_str(), dataEntrada.size() + 1);
    // Escreve a data de saída no arquivo
    out.write(dataSaida.c_str(), dataSaida.size() + 1);
    // Escreve a quantidade de diárias no arquivo
    out.write(reinterpret_cast<const char *>(&quantidadeDiarias),
              sizeof(quantidadeDiarias));
    // Escreve o código do cliente no arquivo
    out.write(reinterpret_cast<const char *>(&codigoCliente),
              sizeof(codigoCliente));
    // Escreve o número do quarto no arquivo
    out.write(reinterpret_cast<const char *>(&numeroQuarto),
              sizeof(numeroQuarto));
  }

  // Método para carregar os dados da estadia de um arquivo binário
  void carregar(std::istream &in) {
    // Lê o código da estadia do arquivo
    in.read(reinterpret_cast<char *>(&codigoEstadia), sizeof(codigoEstadia));
    // Lê a data de entrada do arquivo
    std::getline(in >> std::ws, dataEntrada, '\0');
    // Lê a data de saída do arquivo
    std::getline(in >> std::ws, dataSaida, '\0');
    // Lê a quantidade de diárias do arquivo
    in.read(reinterpret_cast<char *>(&quantidadeDiarias),
            sizeof(quantidadeDiarias));
    // Lê o código do cliente do arquivo
    in.read(reinterpret_cast<char *>(&codigoCliente), sizeof(codigoCliente));
    // Lê o número do quarto do arquivo
    in.read(reinterpret_cast<char *>(&numeroQuarto), sizeof(numeroQuarto));
  }
};

class Hotel {
private:
  std::vector<Cliente> clientes;
  std::vector<Funcionario> funcionarios;
  std::vector<Estadia> estadias;
  std::vector<Quarto> quartos;

  // Funções para gerar códigos únicos baseados no tamanho dos vetores
  int gerarCodigoCliente() { return clientes.size() + 1; }
  int gerarCodigoFuncionario() { return funcionarios.size() + 1; }
  int gerarCodigoEstadia() { return estadias.size() + 1; }

  // Salvar e carregar dados de clientes
  void salvarClientes(const std::string &filename) const {
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

  void carregarClientes(const std::string &filename) {
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

  // Verifica se existe funcionário com determinado cargo
  bool existeCargo(const std::string &cargo) const {
    auto it = std::find_if(
        funcionarios.begin(), funcionarios.end(),
        [&](const Funcionario &f) { return f.getCargo() == cargo; });
    return it != funcionarios.end();
  }

  // Salvar e carregar dados de funcionários
  void salvarFuncionarios(const std::string &filename) const {
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

  void carregarFuncionarios(const std::string &filename) {
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

  // Salvar e carregar dados de estadias
  void salvarEstadias(const std::string &filename) const {
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

  void carregarEstadias(const std::string &filename) {
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
  void salvarQuartos(const std::string &filename) const {
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

  void carregarQuartos(const std::string &filename) {
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

public:
  // Construtor que carrega dados dos arquivos binários ao inicializar
  Hotel() {
    carregarClientes("clientes.bin");
    carregarFuncionarios("funcionarios.bin");
    carregarEstadias("estadias.bin");
    carregarQuartos("quartos.bin");
  }

  // Destrutor que salva dados nos arquivos binários ao encerrar
  ~Hotel() {
    salvarClientes("clientes.bin");
    salvarFuncionarios("funcionarios.bin");
    salvarEstadias("estadias.bin");
    salvarQuartos("quartos.bin");
  }

  // Método para mostrar lista de quartos
  void mostrarListaQuartos() const {
    std::cout << "Lista de Quartos:" << std::endl;
    for (const auto &quarto : quartos) {
      std::cout << "Número: " << quarto.getNumero() << std::endl;
      std::cout << "Capacidade: " << quarto.getQuantidadeHospedes()
                << " pessoas" << std::endl;
      std::cout << "Valor da Diária: R$ " << std::fixed << std::setprecision(2)
                << quarto.getValorDiaria() << std::endl;
      std::cout << "Ocupado: " << (quarto.isOcupado() ? "Sim" : "Não")
                << std::endl;
      std::cout << "-------------------------" << std::endl;
    }
  }

  // Método para cadastrar um novo cliente
  void cadastrarCliente(const std::string &nome, const std::string &telefone,
                        const std::string &endereco) {
    int codigo = gerarCodigoCliente();
    clientes.emplace_back(codigo, nome, telefone, endereco);
  }

  // Método para deletar um funcionário pelo código
  void deletarFuncionario(int codigo) {
    auto it = std::find_if(funcionarios.begin(), funcionarios.end(),
                           [codigo](const Funcionario &funcionario) {
                             return funcionario.getCodigo() == codigo;
                           });

    if (it != funcionarios.end()) {
      funcionarios.erase(it);
      std::cout << "Funcionário removido com sucesso." << std::endl;
    } else {
      std::cerr << "Funcionário não encontrado." << std::endl;
    }
  }

  // Método para listar todos os clientes
  void listarClientes() const {
    std::cout << "Lista de Clientes:" << std::endl;
    for (const auto &cliente : clientes) {
      std::cout << "Código: " << cliente.getCodigo() << std::endl;
      std::cout << "Nome: " << cliente.getNome() << std::endl;
      std::cout << "Telefone: " << cliente.getTelefone() << std::endl;
      std::cout << "Endereço: " << cliente.getEndereco() << std::endl;
      std::cout << "-------------------------" << std::endl;
    }
  }

  // Método para deletar um cliente pelo código
  void deletarCliente(int codigo) {
    auto it = std::find_if(clientes.begin(), clientes.end(),
                           [codigo](const Cliente &cliente) {
                             return cliente.getCodigo() == codigo;
                           });

    if (it != clientes.end()) {
      clientes.erase(it);
      std::cout << "Cliente removido com sucesso." << std::endl;
    } else {
      std::cerr << "Cliente não encontrado." << std::endl;
    }
  }

  // Método para verificar se um funcionário possui determinado cargo
  void checkFuncionarioCargo(const Funcionario &funcionario,
                             const std::string &cargoToCheck) {
    if (funcionario.getCargo() == cargoToCheck) {
      std::cout << "Funcionário " << funcionario.getNome()
                << " tem o cargo: " << cargoToCheck << std::endl;
    } else {
      std::cout << "Funcionário " << funcionario.getNome()
                << " não tem o cargo: " << cargoToCheck << std::endl;
    }
  }

  // Método para listar todos os funcionários
  void listarFuncionarios() const {
    std::cout << "Lista de Funcionários:" << std::endl;
    for (const auto &funcionario : funcionarios) {
      std::cout << "Código: " << funcionario.getCodigo() << std::endl;
      std::cout << "Nome: " << funcionario.getNome() << std::endl;
      std::cout << "Telefone: " << funcionario.getTelefone() << std::endl;
      std::cout << "Cargo: " << funcionario.getCargo() << std::endl;
      std::cout << "Salário: R$ " << std::fixed << std::setprecision(2)
                << funcionario.getSalario() << std::endl;
      std::cout << "-------------------------" << std::endl;
    }
  }

  // Método para cadastrar um novo funcionário
  void cadastrarFuncionario(const std::string &nome,
                            const std::string &telefone,
                            const std::string &cargo, double salario) {
    if (cargoExists(cargo)) {
      std::cout << "Cargo " << cargo
                << " já existe. Não foi possível cadastrar o funcionário."
                << std::endl;
    } else {
      int codigo = gerarCodigoFuncionario();
      funcionarios.emplace_back(codigo, nome, telefone, cargo, salario);
      std::cout << "Funcionário cadastrado com sucesso." << std::endl;
    }
  }

  // Método para gerar código único para funcionários
  int gerarCodigoFuncionario() const {
    static int proximoCodigo = 1;
    return proximoCodigo++;
  }

  // Método para verificar se um cargo de funcionário já existe
  bool cargoExists(const std::string &cargo) {
    for (const auto &funcionario : funcionarios) {
      if (funcionario.getCargo() == cargo) {
        return true;
      }
    }
    return false;
  }

  // Método para cadastrar um novo quarto
  void cadastrarQuarto(int numero, int qtdHospedes, double valorDiaria) {
    quartos.emplace_back(numero, qtdHospedes, valorDiaria);
  }

  // Método para cadastrar uma nova estadia
  void cadastrarEstadia(int codCliente, const std::string &dataEntrada,
                        const std::string &dataSaida, int quantidadeDiarias,
                        int qtdHospedes) {
    int numeroQuarto = -1; // Lógica para escolher quarto disponível
    for (auto &quarto : quartos) {
      if (!quarto.isOcupado() &&
          quarto.getQuantidadeHospedes() >= qtdHospedes) {
        numeroQuarto = quarto.getNumero();
        quarto.setOcupado(true);
        break;
      }
    }

    if (numeroQuarto == -1) {
      std::cerr << "Não há quartos disponíveis para a quantidade de hóspedes "
                   "desejada."
                << std::endl;
      return;
    }

    int codigoEstadia = gerarCodigoEstadia();
    estadias.emplace_back(codigoEstadia, dataEntrada, dataSaida,
                          quantidadeDiarias, codCliente, numeroQuarto);
  }

  // Método para dar baixa em uma estadia pelo código da estadia
  void darBaixaEstadia(int codigoEstadia) {
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
        std::cerr << "Erro: Quarto da estadia não encontrado." << std::endl;
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
      std::cerr << "Estadia não encontrada." << std::endl;
    }
  }

  // Método para pesquisar cliente por nome ou código
  void pesquisarClientePorNomeOuCodigo(const std::string &nome,
                                       int codigo) const {
    if (codigo != 0) {
      auto it = std::find_if(clientes.begin(), clientes.end(),
                             [codigo](const Cliente &cliente) {
                               return cliente.getCodigo() == codigo;
                             });

      if (it != clientes.end()) {
        std::cout << "Cliente encontrado: " << it->getNome()
                  << ", Telefone: " << it->getTelefone()
                  << ", Endereço: " << it->getEndereco() << std::endl;
      } else {
        std::cerr << "Cliente não encontrado." << std::endl;
      }
    } else {
      auto it = std::find_if(
          clientes.begin(), clientes.end(),
          [nome](const Cliente &cliente) { return cliente.getNome() == nome; });

      if (it != clientes.end()) {
        std::cout << "Cliente encontrado: " << it->getNome()
                  << ", Telefone: " << it->getTelefone()
                  << ", Endereço: " << it->getEndereco() << std::endl;
      } else {
        std::cerr << "Cliente não encontrado." << std::endl;
      }
    }
  }

  // Método para pesquisar funcionário por nome ou código
  void pesquisarFuncionarioPorNomeOuCodigo(const std::string &nome,
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
                  << ", Salário: " << it->getSalario() << std::endl;
      } else {
        std::cerr << "Funcionário não encontrado." << std::endl;
      }
    } else {
      auto it = std::find_if(funcionarios.begin(), funcionarios.end(),
                             [nome](const Funcionario &funcionario) {
                               return funcionario.getNome() == nome;
                             });

      if (it != funcionarios.end()) {
        std::cout << "Funcionário encontrado: " << it->getNome()
                  << ", Telefone: " << it->getTelefone()
                  << ", Cargo: " << it->getCargo()
                  << ", Salário: " << it->getSalario() << std::endl;
      } else {
        std::cerr << "Funcionário não encontrado." << std::endl;
      }
    }
  }

  // Método para mostrar estadias de um cliente pelo código do cliente
  void mostrarEstadiasCliente(int codigoCliente) const {
    auto it = std::find_if(clientes.begin(), clientes.end(),
                           [codigoCliente](const Cliente &cliente) {
                             return cliente.getCodigo() == codigoCliente;
                           });

    if (it != clientes.end()) {
      std::cout << "Estadias do cliente " << it->getNome() << ":" << std::endl;
      for (const auto &estadia : estadias) {
        if (estadia.getCodigoCliente() == codigoCliente) {
          std::cout << "Código da Estadia: " << estadia.getCodigoEstadia()
                    << ", Quarto: " << estadia.getNumeroQuarto()
                    << ", Data de Entrada: " << estadia.getDataEntrada()
                    << ", Data de Saída: " << estadia.getDataSaida()
                    << std::endl;
        }
      }
    } else {
      std::cerr << "Cliente não encontrado." << std::endl;
    }
  }

  // Método para calcular pontos de fidelidade de um cliente pelo código do
  // cliente
  int calcularPontosFidelidade(int codigoCliente) const {
    int pontos = 0;
    for (const auto &estadia : estadias) {
      if (estadia.getCodigoCliente() == codigoCliente) {
        pontos += estadia.getQuantidadeDiarias() * 10;
      }
    }
    return pontos;
  }
};

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
          endereco); // Chama o método de cadastro na classe Hotel
      break;
    }
    case 2: { // Opção para cadastrar funcionário
      std::string nome, telefone, cargo;
      double salario;
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
      hotel.deletarCliente(
          codigo); // Chama o método para remover cliente na classe Hotel
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
