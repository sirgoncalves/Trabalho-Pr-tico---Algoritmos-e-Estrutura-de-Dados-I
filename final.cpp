#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Pessoa {
protected:
  int codigo;
  std::string nome;
  std::string telefone;

public:
  Pessoa(int cod, std::string nome, std::string telefone)
      : codigo(cod), nome(nome), telefone(telefone) {}

  virtual ~Pessoa() {}

  int getCodigo() const { return codigo; }
  std::string getNome() const { return nome; }
  std::string getTelefone() const { return telefone; }

  void setNome(const std::string &nome) { this->nome = nome; }
  void setTelefone(const std::string &telefone) { this->telefone = telefone; }

  virtual void salvar(std::ostream &out) const {
    out.write(reinterpret_cast<const char *>(&codigo), sizeof(codigo));
    out.write(nome.c_str(),
              nome.size() + 1);
    out.write(telefone.c_str(), telefone.size() + 1);
  }

  virtual void carregar(std::istream &in) {
    in.read(reinterpret_cast<char *>(&codigo), sizeof(codigo));
    std::getline(in >> std::ws, nome, '\0'); // Lê o nome até não encontrar mais nada
    std::getline(in >> std::ws, telefone,
                 '\0'); // Lê o telefone até não ter mais nada para ler
  }
};

class Cliente : public Pessoa {
private:
  std::string endereco;

public:
  Cliente(int cod, std::string nome, std::string telefone, std::string endereco)
      : Pessoa(cod, nome, telefone), endereco(endereco) {}

  std::string getEndereco() const { return endereco; }
  void setEndereco(const std::string &endereco) { this->endereco = endereco; }

  void salvar(std::ostream &out) const override {
    Pessoa::salvar(out);
    out.write(endereco.c_str(), endereco.size() + 1);
  }

  void carregar(std::istream &in) override {
    Pessoa::carregar(in);
    std::getline(in >> std::ws, endereco,
                 '\0'); 
  }
};

class Funcionario : public Pessoa {
private:
  std::string cargo;
  double salario;

public:
  Funcionario(int cod, std::string nome, std::string telefone,
              std::string cargo, double salario)
      : Pessoa(cod, nome, telefone), cargo(cargo), salario(salario) {}

  std::string getCargo() const { return cargo; }
  double getSalario() const { return salario; }

  void setCargo(const std::string &cargo) { this->cargo = cargo; }
  void setSalario(double salario) { this->salario = salario; }

  void salvar(std::ostream &out) const override {
    Pessoa::salvar(out);
    out.write(cargo.c_str(), cargo.size() + 1);
    out.write(reinterpret_cast<const char *>(&salario), sizeof(salario));
  }

  void carregar(std::istream &in) override {
    Pessoa::carregar(in);
    std::getline(in >> std::ws, cargo, '\0'); 
    in.read(reinterpret_cast<char *>(&salario), sizeof(salario));
  }
};

class Quarto {
private:
  int numero;
  int quantidadeHospedes;
  double valorDiaria;
  bool ocupado;

public:
  Quarto(int num, int qtdHospedes, double valorDiaria)
      : numero(num), quantidadeHospedes(qtdHospedes), valorDiaria(valorDiaria),
        ocupado(false) {}

  int getNumero() const { return numero; }
  int getQuantidadeHospedes() const { return quantidadeHospedes; }
  double getValorDiaria() const { return valorDiaria; }
  bool isOcupado() const { return ocupado; }

  void setOcupado(bool status) { ocupado = status; }

  void salvar(std::ostream &out) const {
    out.write(reinterpret_cast<const char *>(&numero), sizeof(numero));
    out.write(reinterpret_cast<const char *>(&quantidadeHospedes),
              sizeof(quantidadeHospedes));
    out.write(reinterpret_cast<const char *>(&valorDiaria),
              sizeof(valorDiaria));
    out.write(reinterpret_cast<const char *>(&ocupado), sizeof(ocupado));
  }

  void carregar(std::istream &in) {
    in.read(reinterpret_cast<char *>(&numero), sizeof(numero));
    in.read(reinterpret_cast<char *>(&quantidadeHospedes),
            sizeof(quantidadeHospedes));
    in.read(reinterpret_cast<char *>(&valorDiaria), sizeof(valorDiaria));
    in.read(reinterpret_cast<char *>(&ocupado), sizeof(ocupado));
  }
};

class Estadia {
private:
  int codigoEstadia;
  std::string dataEntrada;
  std::string dataSaida;
  int quantidadeDiarias;
  int codigoCliente;
  int numeroQuarto;

public:
  Estadia(int codEstadia, std::string entrada, std::string saida,
          int qtdDiarias, int codCliente, int numQuarto)
      : codigoEstadia(codEstadia), dataEntrada(entrada), dataSaida(saida),
        quantidadeDiarias(qtdDiarias), codigoCliente(codCliente),
        numeroQuarto(numQuarto) {}

  int getCodigoEstadia() const { return codigoEstadia; }
  std::string getDataEntrada() const { return dataEntrada; }
  std::string getDataSaida() const { return dataSaida; }
  int getQuantidadeDiarias() const { return quantidadeDiarias; }
  int getCodigoCliente() const { return codigoCliente; }
  int getNumeroQuarto() const { return numeroQuarto; }

  void salvar(std::ostream &out) const {
    out.write(reinterpret_cast<const char *>(&codigoEstadia),
              sizeof(codigoEstadia));
    out.write(dataEntrada.c_str(), dataEntrada.size() + 1);
    out.write(dataSaida.c_str(), dataSaida.size() + 1);
    out.write(reinterpret_cast<const char *>(&quantidadeDiarias),
              sizeof(quantidadeDiarias));
    out.write(reinterpret_cast<const char *>(&codigoCliente),
              sizeof(codigoCliente));
    out.write(reinterpret_cast<const char *>(&numeroQuarto),
              sizeof(numeroQuarto));
  }

  void carregar(std::istream &in) {
    in.read(reinterpret_cast<char *>(&codigoEstadia), sizeof(codigoEstadia));
    std::getline(in >> std::ws, dataEntrada, '\0');
    std::getline(in >> std::ws, dataSaida, '\0');
    in.read(reinterpret_cast<char *>(&quantidadeDiarias),
            sizeof(quantidadeDiarias));
    in.read(reinterpret_cast<char *>(&codigoCliente), sizeof(codigoCliente));
    in.read(reinterpret_cast<char *>(&numeroQuarto), sizeof(numeroQuarto));
  }
};

class Hotel {
private:
  std::vector<Cliente> clientes;
  std::vector<Funcionario> funcionarios;
  std::vector<Estadia> estadias;
  std::vector<Quarto> quartos;

  int gerarCodigoCliente() {
    return clientes.size() + 1; 
  }

  int gerarCodigoFuncionario() {
    return funcionarios.size() + 1; 
  }

  int gerarCodigoEstadia() {
    return estadias.size() + 1;
  }

  void salvarClientes(const std::string &filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
      for (const auto &cliente : clientes) {
        cliente.salvar(file);
      }
      file.close();
    } else {
      std::cerr << "Erro ao abrir o arquivo " << filename << " para escrita."
                << std::endl;
    }
  }

  bool existeCargo(const std::string &cargo) const {
    auto it = std::find_if(
        funcionarios.begin(), funcionarios.end(),
        [&](const Funcionario &f) { return f.getCargo() == cargo; });
    return it != funcionarios.end();
  }

  void carregarClientes(const std::string &filename) {
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open()) {
      while (!file.eof()) {
        Cliente cliente(0, "", "", "");
        cliente.carregar(file);
        if (!file.eof()) {
          clientes.push_back(cliente);
        }
      }
      file.close();
    } else {
      std::cerr << "Erro ao abrir o arquivo " << filename << " para leitura."
                << std::endl;
    }
  }
  void salvarFuncionarios(const std::string &filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
      for (const auto &funcionario : funcionarios) {
        funcionario.salvar(file);
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
        Funcionario funcionario(0, "", "", "", 0.0);
        funcionario.carregar(file);
        if (!file.eof()) {
          funcionarios.push_back(funcionario);
        }
      }
      file.close();
    } else {
      std::cerr << "Erro ao abrir o arquivo " << filename << " para leitura."
                << std::endl;
    }
  }

  void salvarEstadias(const std::string &filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
      for (const auto &estadia : estadias) {
        estadia.salvar(file);
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
        Estadia estadia(0, "", "", 0, 0, 0);
        estadia.carregar(file);
        if (!file.eof()) {
          estadias.push_back(estadia);
        }
      }
      file.close();
    } else {
      std::cerr << "Erro ao abrir o arquivo " << filename << " para leitura."
                << std::endl;
    }
  }

  void salvarQuartos(const std::string &filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
      for (const auto &quarto : quartos) {
        quarto.salvar(file);
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
        Quarto quarto(0, 0, 0.0);
        quarto.carregar(file);
        if (!file.eof()) {
          quartos.push_back(quarto);
        }
      }
      file.close();
    } else {
      std::cerr << "Erro ao abrir o arquivo " << filename << " para leitura."
                << std::endl;
    }
  }

public:
  Hotel() {
    carregarClientes("clientes.bin");
    carregarFuncionarios("funcionarios.bin");
    carregarEstadias("estadias.bin");
    carregarQuartos("quartos.bin");
  }

  ~Hotel() {
    salvarClientes("clientes.bin");
    salvarFuncionarios("funcionarios.bin");
    salvarEstadias("estadias.bin");
    salvarQuartos("quartos.bin");
  }

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
  void cadastrarCliente(const std::string &nome, const std::string &telefone,
                        const std::string &endereco) {
    int codigo = gerarCodigoCliente();
    clientes.emplace_back(codigo, nome, telefone, endereco);
  }

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
  void checkFuncionarioCargo(const Funcionario &funcionario,
                             const std::string &cargoToCheck) {
   
    if (funcionario.getCargo() == cargoToCheck) {
      std::cout << "Funcionario " << funcionario.getNome()
                << " has the cargo: " << cargoToCheck << std::endl;
    } else {
      std::cout << "Funcionario " << funcionario.getNome()
                << " does not have the cargo: " << cargoToCheck << std::endl;
    }
  }
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

  int gerarCodigoFuncionario() const {
    static int proximoCodigo =
        1; 
    return proximoCodigo++;
  }

  bool cargoExists(const std::string &cargo) {
    for (const auto &funcionario : funcionarios) {
      if (funcionario.getCargo() == cargo) {
        return true;
      }
    }
    return false;
  }

  void cadastrarQuarto(int numero, int qtdHospedes, double valorDiaria) {
    quartos.emplace_back(numero, qtdHospedes, valorDiaria);
  }

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
  Hotel hotel;
  int opcao;

  do {
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
    std::cout << "0. Sair\n";
    std::cout << "Escolha uma opção: ";
    std::cin >> opcao;

    switch (opcao) {
    case 1: {
      std::string nome, telefone, endereco;
      std::cout << "Nome: ";
      std::cin.ignore();
      std::getline(std::cin, nome);
      std::cout << "Telefone: ";
      std::getline(std::cin, telefone);
      std::cout << "Endereço: ";
      std::getline(std::cin, endereco);
      hotel.cadastrarCliente(nome, telefone, endereco);
      break;
    }
    case 2: {
      std::string nome, telefone, cargo;
      double salario;
      std::cout << "Nome: ";
      std::cin.ignore();
      std::getline(std::cin, nome);
      std::cout << "Telefone: ";
      std::getline(std::cin, telefone);
      std::cout << "Cargo: ";
      std::getline(std::cin, cargo);
      std::cout << "Salário: ";
      std::cin >> salario;
      hotel.cadastrarFuncionario(nome, telefone, cargo, salario);
      break;
    }
    case 3: {
      int numero, qtdHospedes;
      double valorDiaria;
      std::cout << "Número do Quarto: ";
      std::cin >> numero;
      std::cout << "Quantidade de Hóspedes: ";
      std::cin >> qtdHospedes;
      std::cout << "Valor da Diária: ";
      std::cin >> valorDiaria;
      hotel.cadastrarQuarto(numero, qtdHospedes, valorDiaria);
      break;
    }
    case 4: {
      int codCliente, qtdHospedes, qtdDiarias;
      std::string dataEntrada, dataSaida;
      std::cout << "Código do Cliente: ";
      std::cin >> codCliente;
      std::cout << "Data de Entrada (DD/MM/AAAA): ";
      std::cin.ignore();
      std::getline(std::cin, dataEntrada);
      std::cout << "Data de Saída (DD/MM/AAAA): ";
      std::getline(std::cin, dataSaida);
      std::cout << "Quantidade de Hóspedes: ";
      std::cin >> qtdHospedes;
      std::cout << "Quantidade de Diárias: ";
      std::cin >> qtdDiarias;
      hotel.cadastrarEstadia(codCliente, dataEntrada, dataSaida, qtdDiarias,
                             qtdHospedes);
      break;
    }
    case 5: {
      int codigoEstadia;
      std::cout << "Código da Estadia: ";
      std::cin >> codigoEstadia;
      hotel.darBaixaEstadia(codigoEstadia);
      break;
    }
    case 6: {
      std::string nome;
      int codigo;
      std::cout << "Nome do Cliente (deixe em branco se não quiser pesquisar "
                   "por nome): ";
      std::cin.ignore();
      std::getline(std::cin, nome);
      std::cout
          << "Código do Cliente (deixe 0 se não quiser pesquisar por código): ";
      std::cin >> codigo;
      hotel.pesquisarClientePorNomeOuCodigo(nome, codigo);
      break;
    }
    case 7: {
      std::string nome;
      int codigo;
      std::cout << "Nome do Funcionário (deixe em branco se não quiser "
                   "pesquisar por nome): ";
      std::cin.ignore();
      std::getline(std::cin, nome);
      std::cout << "Código do Funcionário (deixe 0 se não quiser pesquisar por "
                   "código): ";
      std::cin >> codigo;
      hotel.pesquisarFuncionarioPorNomeOuCodigo(nome, codigo);
      break;
    }
    case 8: {
      int codigoCliente;
      std::cout << "Código do Cliente: ";
      std::cin >> codigoCliente;
      hotel.mostrarEstadiasCliente(codigoCliente);
      break;
    }
    case 9: {
      int codigoCliente;
      std::cout << "Código do Cliente: ";
      std::cin >> codigoCliente;
      std::cout << "Pontos de Fidelidade do Cliente: "
                << hotel.calcularPontosFidelidade(codigoCliente) << std::endl;
      break;
    }
    case 10: {
      hotel.mostrarListaQuartos();
      break;
    }
    case 11: {
      hotel.listarFuncionarios();
      break;
    }
    case 12: {
      int codigo;
      std::cout << "Digite o código do funcionário a ser removido: ";
      std::cin >> codigo;
      hotel.deletarFuncionario(codigo);
      break;
    }
    case 13: {
      int codigo;
      std::cout << "Digite o código do cliente a ser removido: ";
      std::cin >> codigo;
      hotel.deletarCliente(codigo);
      break;
    }
    case 0:
      std::cout << "Saindo...\n";
      break;
    default:
      std::cout << "Opção inválida!\n";
    }
  } while (opcao != 0);

  return 0;
}
