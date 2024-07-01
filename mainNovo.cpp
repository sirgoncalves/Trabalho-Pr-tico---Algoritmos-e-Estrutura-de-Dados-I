
#include <string>
#include <sstream>

class Pessoa
{
    public:
    // Construtor que inicializa os membros da classe
    Pessoa(int cod, std::string nome, std::string telefone): codigo(cod), nome(nome), telefone(telefone){}

    // M�todo getter para obter o c�digo da pessoa
    int getCodigo() const;

    // M�todo getter para obter o nome da pessoa
    std::string getNome() const;

    // M�todo getter para obter o telefone da pessoa
    std::string getTelefone() const;

    // M�todo setter para definir o nome da pessoa
    void setNome(const std::string &nome);

    // M�todo setter para definir o telefone da pessoa
    void setTelefone(const std::string &telefone);

    // M�todo para salvar os dados da pessoa em um fluxo de sa�da
    virtual void salvar(std::ostream &out) const;

    // M�todo para carregar os dados da pessoa de um fluxo de entrada
    virtual void carregar(std::istream &in);

    protected:
    int codigo;           // C�digo �nico da pessoa
    std::string nome;     // Nome da pessoa
    std::string telefone; // Telefone da pessoa


};







class Cliente:public Pessoa
{
    public:
    // Construtor que inicializa os membros da classe Cliente e chama o construtor
    // da classe base Pessoa
    Cliente(int cod, std::string nome, std::string telefone, std::string endereco): Pessoa(cod, nome, telefone), endereco(endereco) {}

    // M�todo getter para obter o endere�o do cliente
    std::string getEndereco() const;

    // M�todo setter para definir o endere�o do cliente
    void setEndereco(const std::string &endereco);

    // M�todo para salvar os dados do cliente em um fluxo de sa�da
    void salvar(std::ostream &out)const override;

    // M�todo para carregar os dados do cliente de um fluxo de entrada
    void carregar(std::istream &in) override;

    private:
    std::string endereco;// Endere�o do cliente
};






class Funcionario: public Pessoa
{

    private:
    std::string cargo; // Cargo do funcion�rio
    double salario;    // Sal�rio do funcion�rio

    public:
    // Construtor que inicializa os membros da classe Funcionario e chama o
    // construtor da classe base Pessoa
    Funcionario(int cod, std::string nome, std::string telefone,std::string cargo, double salario): Pessoa(cod, nome, telefone), cargo(cargo), salario(salario) {}

    // M�todo getter para obter o cargo do funcion�rio
    std::string getCargo() const;

    // M�todo getter para obter o sal�rio do funcion�rio
    double getSalario() const;

    // M�todo setter para definir o cargo do funcion�rio
    void setCargo(const std::string &cargo);

    // M�todo setter para definir o sal�rio do funcion�rio
    void setSalario(double salario);

    // M�todo para salvar os dados do funcion�rio em um fluxo de sa�da
    void salvar(std::ostream &out) const override;

    // M�todo para carregar os dados do funcion�rio de um fluxo de entrada
    void carregar(std::istream &in) override;


};


#include <string>
#include <sstream>

class Quarto
{
    private:
    int numero;             // N�mero do quarto
    int quantidadeHospedes; // Quantidade m�xima de h�spedes
    double valorDiaria;     // Valor da di�ria do quarto
    bool ocupado;           // Status de ocupa��o do quarto

    public:
    Quarto(int num, int qtdHospedes, double valorDiaria): numero(num), quantidadeHospedes(qtdHospedes), valorDiaria(valorDiaria),ocupado(false) {}

    // M�todo getter para obter o n�mero do quarto
    int getNumero() const;

    // M�todo getter para obter a quantidade m�xima de h�spedes
    int getQuantidadeHospedes() const;

    // M�todo getter para obter o valor da di�ria do quarto
    double getValorDiaria() const;

    // M�todo getter para verificar se o quarto est� ocupado
    bool isOcupado() const;

    // M�todo setter para definir o status de ocupa��o do quarto
    void setOcupado(bool status);

    // M�todo para salvar os dados do quarto em um fluxo de sa�da
    void salvar(std::ostream &out) const;

    // M�todo para carregar os dados do quarto de um fluxo de entrada
    void carregar(std::istream &in);

};




#include <string>
#include <sstream>

class Estadia
{
    private:
    int codigoEstadia;       // C�digo �nico da estadia
    std::string dataEntrada; // Data de entrada na estadia
    std::string dataSaida;   // Data de sa�da da estadia
    int quantidadeDiarias;   // Quantidade de di�rias da estadia
    int codigoCliente;       // C�digo do cliente associado � estadia
    int numeroQuarto;        // N�mero do quarto associado � estadia

    public:

    // Construtor da classe Estadia
    Estadia(int codEstadia, std::string entrada, std::string saida,int qtdDiarias, int codCliente, int numQuarto):
    codigoEstadia(codEstadia), dataEntrada(entrada), dataSaida(saida),
    quantidadeDiarias(qtdDiarias), codigoCliente(codCliente),
    numeroQuarto(numQuarto) {}

    // M�todos getters para acessar os atributos da classe
    int getCodigoEstadia() const;
    std::string getDataEntrada() const;
    std::string getDataSaida() const;
    int getQuantidadeDiarias() const;
    int getCodigoCliente() const;
    int getNumeroQuarto() const;

    // M�todo para salvar os dados da estadia em um arquivo bin�rio
    void salvar(std::ostream &out) const;

    // M�todo para carregar os dados da estadia de um arquivo bin�rio
    void carregar(std::istream &in);
};



#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


class Hotel
{
    private:
    std::vector<Cliente> clientes;
    std::vector<Funcionario> funcionarios;
    std::vector<Estadia> estadias;
    std::vector<Quarto> quartos;

    int gerarCodigoCliente();

    int gerarCodigoFuncionario();

    int gerarCodigoEstadia();

    void salvarClientes(const std::string &filename) const;

    void carregarClientes(const std::string &filename);

    bool existeCargo(const std::string &cargo) const;

    void salvarFuncionarios(const std::string &filename) const;

    void carregarFuncionarios(const std::string &filename);

    void salvarEstadias(const std::string &filename) const;

    void carregarEstadias(const std::string &filename);

    void salvarQuartos(const std::string &filename) const;

    void carregarQuartos(const std::string &filename);


    public:

    // Construtor que carrega dados dos arquivos bin�rios ao inicializar
    Hotel() {
    carregarClientes("clientes.bin");
    carregarFuncionarios("funcionarios.bin");
    carregarEstadias("estadias.bin");
    carregarQuartos("quartos.bin");
    }

    // Destrutor que salva dados nos arquivos bin�rios ao encerrar
    ~Hotel() {
    salvarClientes("clientes.bin");
    salvarFuncionarios("funcionarios.bin");
    salvarEstadias("estadias.bin");
    salvarQuartos("quartos.bin");
    }

    void mostrarListaQuartos() const;

 void cadastrarCliente(const std::string &nome, const std::string &telefone,
                        const std::string &endereco);
    void deletarFuncionario(int codigo);

    void listarClientes() const;

    void deletarCliente(int codigo);

    void checkFuncionarioCargo(const Funcionario &funcionario,const std::string &cargoToCheck);

    void listarFuncionarios() const;

    void cadastrarFuncionario(const std::string &nome,const std::string &telefone,const std::string &cargo, double salario);

    // Metodo para gerar c�digo �nico para funcionarios
    int gerarCodigoFuncionario() const;

    // Metodo para verificar se um cargo de funcionario j� existe
    bool cargoExists(const std::string &cargo);

    // M�todo para cadastrar um novo quarto
    void cadastrarQuarto(int numero, int qtdHospedes, double valorDiaria);

    // M�todo para cadastrar uma nova estadia
    void cadastrarEstadia(int codCliente, const std::string &dataEntrada,const std::string &dataSaida, int quantidadeDiarias,int qtdHospedes);

    void darBaixaEstadia(int codigoEstadia);

    void pesquisarClientePorNomeOuCodigo(const std::string &nome,int codigo) const;

    // M�todo para pesquisar funcion�rio por nome ou c�digo
    void pesquisarFuncionarioPorNomeOuCodigo(const std::string &nome,int codigo) const;

    // M�todo para mostrar estadias de um cliente pelo c�digo do cliente
    void mostrarEstadiasCliente(int codigoCliente) const;

    // M�todo para calcular pontos de fidelidade de um cliente pelo c�digo do
    // cliente
    int calcularPontosFidelidade(int codigoCliente) const;
};






int Pessoa::getCodigo() const{ return codigo;}

std::string Pessoa::getNome() const { return nome;}

std::string Pessoa::getTelefone() const { return telefone;}

void Pessoa::setNome(const std::string &nome) { this->nome = nome;}

void Pessoa::setTelefone(const std::string &telefone) { this->telefone = telefone;}

 void Pessoa::salvar (std::ostream &out) const {
    // Salva o c�digo como um bloco de bytes
    out.write(reinterpret_cast<const char *>(&codigo), sizeof(codigo));
    // Salva o nome como uma sequ�ncia de caracteres, incluindo o terminador
    // nulo
    out.write(nome.c_str(), nome.size() + 1);
    // Salva o telefone como uma sequ�ncia de caracteres, incluindo o terminador
    // nulo
    out.write(telefone.c_str(), telefone.size() + 1);
  }

   void Pessoa::carregar(std::istream &in) {
    // L� o c�digo como um bloco de bytes
    in.read(reinterpret_cast<char *>(&codigo), sizeof(codigo));
    // L� o nome at� encontrar um caractere nulo
    std::getline(in >> std::ws, nome, '\0');
    // L� o telefone at� encontrar um caractere nulo
    std::getline(in >> std::ws, telefone, '\0');
  }




std::string Cliente::getEndereco() const { return endereco;}

void Cliente::setEndereco(const std::string &endereco) { this->endereco = endereco;}

void Cliente::salvar (std::ostream &out) const  {
    Pessoa::salvar(out); // Salva os dados da classe base Pessoa
    out.write(endereco.c_str(),endereco.size() + 1); // Salva o endere�o como uma sequ�ncia de caracteres, incluindo o terminador nulo
  }

  void Cliente::carregar( std::istream &in)  {
    Pessoa::carregar(in); // Carrega os dados da classe base Pessoa
    std::getline(in >> std::ws, endereco,'\0'); // L� o endere�o at� encontrar um caractere nulo
  }





std::string Funcionario::getCargo() const { return cargo;}

double Funcionario::getSalario() const { return salario;}

void Funcionario::setCargo(const std::string &cargo) { this->cargo = cargo;}

void Funcionario::setSalario(double salario)  { this->salario = salario;}

void Funcionario::salvar (std::ostream &out) const  {
    Pessoa::salvar(out); // Salva os dados da classe base Pessoa
    out.write(cargo.c_str(),
              cargo.size() + 1); // Salva o cargo como uma sequ�ncia de
                                 // caracteres, incluindo o terminador nulo
    out.write(reinterpret_cast<const char *>(&salario),
              sizeof(salario)); // Salva o sal�rio como um bloco de bytes
  }

void Funcionario::carregar(std::istream &in)  {
    Pessoa::carregar(in); // Carrega os dados da classe base Pessoa
    std::getline(in >> std::ws, cargo,
                 '\0'); // L� o cargo at� encontrar um caractere nulo
    in.read(reinterpret_cast<char *>(&salario),
            sizeof(salario)); // L� o sal�rio como um bloco de bytes
  }






int Quarto::getNumero() const { return numero; }

int Quarto::getQuantidadeHospedes()const { return quantidadeHospedes; }

double Quarto::getValorDiaria() const { return valorDiaria; }

bool Quarto::isOcupado() const { return ocupado; }

void Quarto::setOcupado(bool status)  { ocupado = status; }

void Quarto::salvar(std::ostream &out) const {
    out.write(reinterpret_cast<const char *>(&numero),
              sizeof(numero)); // Salva o n�mero do quarto
    out.write(reinterpret_cast<const char *>(&quantidadeHospedes),
              sizeof(quantidadeHospedes)); // Salva a quantidade de h�spedes
    out.write(reinterpret_cast<const char *>(&valorDiaria),
              sizeof(valorDiaria)); // Salva o valor da di�ria
    out.write(reinterpret_cast<const char *>(&ocupado),
              sizeof(ocupado)); // Salva o status de ocupa��o
  }

void Quarto::carregar(std::istream &in) {
    in.read(reinterpret_cast<char *>(&numero),
            sizeof(numero)); // L� o n�mero do quarto
    in.read(reinterpret_cast<char *>(&quantidadeHospedes),
            sizeof(quantidadeHospedes)); // L� a quantidade de h�spedes
    in.read(reinterpret_cast<char *>(&valorDiaria),
            sizeof(valorDiaria)); // L� o valor da di�ria
    in.read(reinterpret_cast<char *>(&ocupado),
            sizeof(ocupado)); // L� o status de ocupa��o
  }






int Estadia::getCodigoEstadia() const { return codigoEstadia; }
std::string Estadia::getDataEntrada()  const { return dataEntrada; }
std::string Estadia::getDataSaida() const { return dataSaida; }
int Estadia::getQuantidadeDiarias() const { return quantidadeDiarias; }
int Estadia::getCodigoCliente() const { return codigoCliente; }
int Estadia::getNumeroQuarto() const { return numeroQuarto; }

void Estadia::salvar(std::ostream &out) const {
    // Escreve o c�digo da estadia no arquivo
    out.write(reinterpret_cast<const char *>(&codigoEstadia),
              sizeof(codigoEstadia));
    // Escreve a data de entrada no arquivo
    out.write(dataEntrada.c_str(), dataEntrada.size() + 1);
    // Escreve a data de sa�da no arquivo
    out.write(dataSaida.c_str(), dataSaida.size() + 1);
    // Escreve a quantidade de di�rias no arquivo
    out.write(reinterpret_cast<const char *>(&quantidadeDiarias),
              sizeof(quantidadeDiarias));
    // Escreve o c�digo do cliente no arquivo
    out.write(reinterpret_cast<const char *>(&codigoCliente),
              sizeof(codigoCliente));
    // Escreve o n�mero do quarto no arquivo
    out.write(reinterpret_cast<const char *>(&numeroQuarto),
              sizeof(numeroQuarto));
  }

  void Estadia::carregar(std::istream &in) {
    // L� o c�digo da estadia do arquivo
    in.read(reinterpret_cast<char *>(&codigoEstadia), sizeof(codigoEstadia));
    // L� a data de entrada do arquivo
    std::getline(in >> std::ws, dataEntrada, '\0');
    // L� a data de sa�da do arquivo
    std::getline(in >> std::ws, dataSaida, '\0');
    // L� a quantidade de di�rias do arquivo
    in.read(reinterpret_cast<char *>(&quantidadeDiarias),
            sizeof(quantidadeDiarias));
    // L� o c�digo do cliente do arquivo
    in.read(reinterpret_cast<char *>(&codigoCliente), sizeof(codigoCliente));
    // L� o n�mero do quarto do arquivo
    in.read(reinterpret_cast<char *>(&numeroQuarto), sizeof(numeroQuarto));
  }




int Hotel::gerarCodigoCliente() { return clientes.size() + 1; }
int Hotel::gerarCodigoFuncionario() { return funcionarios.size() + 1; }
int Hotel::gerarCodigoEstadia() { return estadias.size() + 1; }



void Hotel::salvarClientes(const std::string &filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
      for (const auto &cliente : clientes) {
        cliente.salvar(file); // Chama o m�todo salvar de cada cliente
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
                        "");    // Cliente tempor�rio para carregar dados
        cliente.carregar(file); // Chama o m�todo carregar de cada cliente
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
        funcionario.salvar(file); // Chama o m�todo salvar de cada funcion�rio
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
            0, "", "", "", 0.0); // Funcion�rio tempor�rio para carregar dados
        funcionario.carregar(
            file); // Chama o m�todo carregar de cada funcion�rio
        if (!file.eof()) {
          funcionarios.push_back(funcionario); // Adiciona funcion�rio ao vetor
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
        estadia.salvar(file); // Chama o m�todo salvar de cada estadia
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
                        0);     // Estadia tempor�ria para carregar dados
        estadia.carregar(file); // Chama o m�todo carregar de cada estadia
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
        quarto.salvar(file); // Chama o m�todo salvar de cada quarto
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
        Quarto quarto(0, 0, 0.0); // Quarto tempor�rio para carregar dados
        quarto.carregar(file);    // Chama o m�todo carregar de cada quarto
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

     // M�todo para mostrar lista de quartos
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

    // M�todo para cadastrar um novo cliente
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

    // M�todo para deletar um funcion�rio pelo c�digo
    void Hotel::deletarFuncionario(int codigo) {
    auto it = std::find_if(funcionarios.begin(), funcionarios.end(),
                           [codigo](const Funcionario &funcionario) {
                             return funcionario.getCodigo() == codigo;
                           });

    if (it != funcionarios.end()) {
      funcionarios.erase(it);
      std::cout << "Funcionario removido com sucesso." << std::endl;
    } else {
      std::cerr << "Funcionario nao encontrado." << std::endl;
    }
  }
    // M�todo para listar todos os clientes
    void Hotel::listarClientes() const {
    std::cout << "Lista de Clientes:" << std::endl;
    for (const auto &cliente : clientes) {
      std::cout << "Codigo: " << cliente.getCodigo() << std::endl;
      std::cout << "Nome: " << cliente.getNome() << std::endl;
      std::cout << "Telefone: " << cliente.getTelefone() << std::endl;
      std::cout << "Endereco: " << cliente.getEndereco() << std::endl;
      std::cout << "-------------------------" << std::endl;
    }
  }

     // M�todo para deletar um cliente pelo c�digo
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

    // M�todo para verificar se um funcion�rio possui determinado cargo
    void Hotel::checkFuncionarioCargo(const Funcionario &funcionario,
                             const std::string &cargoToCheck) {
    if (funcionario.getCargo() == cargoToCheck) {
      std::cout << "Funcionario " << funcionario.getNome()
                << " tem o cargo: " << cargoToCheck << std::endl;
    } else {
      std::cout << "Funcionario " << funcionario.getNome()
                << " nao tem o cargo: " << cargoToCheck << std::endl;
    }
  }

    // M�todo para listar todos os funcion�rios
    void Hotel::listarFuncionarios() const {
    std::cout << "Lista de Funcionarios:" << std::endl;
    for (const auto &funcionario : funcionarios) {
      std::cout << "Codigo: " << funcionario.getCodigo() << std::endl;
      std::cout << "Nome: " << funcionario.getNome() << std::endl;
      std::cout << "Telefone: " << funcionario.getTelefone() << std::endl;
      std::cout << "Cargo: " << funcionario.getCargo() << std::endl;
      std::cout << "Salario: R$ " << std::fixed << std::setprecision(2)
                << funcionario.getSalario() << std::endl;
      std::cout << "-------------------------" << std::endl;
    }
  }

    // M�todo para cadastrar um novo funcion�rio
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
                << " ja existe. Nao foi possivel cadastrar o funcionario."
                << std::endl;
    } else {
      int codigo = gerarCodigoFuncionario();
      funcionarios.emplace_back(codigo, nome, telefone, cargo, salario);
      std::cout << "Funcionario cadastrado com sucesso." << std::endl;
    }
  }

    // M�todo para gerar c�digo �nico para funcion�rios
    int Hotel::gerarCodigoFuncionario() const {
    static int proximoCodigo = 1;
    return proximoCodigo++;
  }

     // M�todo para verificar se um cargo de funcion�rio j� existe
     bool Hotel::cargoExists(const std::string &cargo) {
     for (const auto &funcionario : funcionarios) {
      if (funcionario.getCargo() == cargo) {
        return true;
      }
    }
    return false;
  }
    // M�todo para cadastrar um novo quarto
    void Hotel::cadastrarQuarto(int numero, int qtdHospedes, double valorDiaria) {
    if (numero <= 0 || qtdHospedes <= 0 || valorDiaria <= 0.0) {
        std::cerr << "Erro: Todos os campos devem ser preenchidos com valores v�lidos." << std::endl;
        return;
    }
    quartos.emplace_back(numero, qtdHospedes, valorDiaria);
    std::cout << "Quarto cadastrado com sucesso." << std::endl;
}

    // M�todo para cadastrar uma nova estadia
   void Hotel::cadastrarEstadia(int codCliente, const std::string &dataEntrada, const std::string &dataSaida,
                             int quantidadeDiarias, int qtdHospedes) {
    if (dataEntrada.empty() || dataSaida.empty() || quantidadeDiarias <= 0 || qtdHospedes <= 0) {
        std::cerr << "Erro: Nenhum dos campos pode estar vazio ou ter valores inv�lidos." << std::endl;
        return;
    }

    int numeroQuarto = -1; // L�gica para escolher quarto dispon�vel
    for (auto &quarto : quartos) {
        if (!quarto.isOcupado() && quarto.getQuantidadeHospedes() >= qtdHospedes) {
            numeroQuarto = quarto.getNumero();
            quarto.setOcupado(true);
            break;
        }
    }

    if (numeroQuarto == -1) {
        std::cerr << "Erro: Nenhum quarto disponivel para a quantidade de hospedes especificada." << std::endl;
        return;
    }

    // Logic to store the stay, if needed
    std::cout << "Estadia cadastrada com sucesso no quarto " << numeroQuarto << "." << std::endl;
}
    // M�todo para dar baixa em uma estadia pelo c�digo da estadia
    void Hotel::darBaixaEstadia(int codigoEstadia) {
    auto it = std::find_if(estadias.begin(), estadias.end(),
                           [codigoEstadia](const Estadia &estadia) {
                             return estadia.getCodigoEstadia() == codigoEstadia;
                           });

    if (it != estadias.end()) {
      int numeroQuarto = it->getNumeroQuarto();
      double valorDiaria = -1.0;

      // Encontra o valor da di�ria do quarto ocupado
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


     // M�todo para pesquisar cliente por nome ou c�digo
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

    // M�todo para pesquisar funcion�rio por nome ou c�digo
    void Hotel::pesquisarFuncionarioPorNomeOuCodigo(const std::string &nome,
                                           int codigo) const {
    if (codigo != 0) {
      auto it = std::find_if(funcionarios.begin(), funcionarios.end(),
                             [codigo](const Funcionario &funcionario) {
                               return funcionario.getCodigo() == codigo;
                             });
      if (it != funcionarios.end()) {
        std::cout << "Funcionario encontrado: " << it->getNome()
                  << ", Telefone: " << it->getTelefone()
                  << ", Cargo: " << it->getCargo()
                  << ", Salario: " << it->getSalario() << std::endl;
      } else {
        std::cerr << "Funcionario nao encontrado." << std::endl;
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
        std::cerr << "Funcionario nao encontrado." << std::endl;
      }
    }
  }

    // M�todo para mostrar estadias de um cliente pelo c�digo do cliente
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

  // M�todo para calcular pontos de fidelidade de um cliente pelo c�digo do cliente
  int Hotel::calcularPontosFidelidade(int codigoCliente) const {
    int pontos = 0;
    for (const auto &estadia : estadias) {
      if (estadia.getCodigoCliente() == codigoCliente) {
        pontos += estadia.getQuantidadeDiarias() * 10;
      }
    }
    return pontos;
  }



int main() {
  Hotel hotel; // Inst�ncia da classe Hotel para gerenciar todas as opera��es

  int opcao; // Vari�vel para armazenar a op��o do menu escolhida pelo usu�rio

  // Loop do menu principal
  do {
    // Exibi��o das op��es do menu
    std::cout << "Menu:\n";
    std::cout << "1. Cadastrar Cliente\n";
    std::cout << "2. Cadastrar Funcionario\n";
    std::cout << "3. Cadastrar Quarto\n";
    std::cout << "4. Cadastrar Estadia\n";
    std::cout << "5. Dar Baixa em Estadia\n";
    std::cout << "6. Pesquisar Cliente por Nome ou Codigo\n";
    std::cout << "7. Pesquisar Funcion�rio por Nome ou Codigo\n";
    std::cout << "8. Mostrar Estadias de um Cliente\n";
    std::cout << "9. Calcular Pontos de Fidelidade de um Cliente\n";
    std::cout << "10. Mostrar lista de quartos\n";
    std::cout << "11. Listar funcionarios\n";
    std::cout << "12. Remover funcionario\n";
    std::cout << "13. Remover Cliente\n";
    std::cout << "14. Listar Clientes\n";
    std::cout << "0. Sair\n";
    std::cout << "Escolha uma opcao: ";
    std::cin >> opcao; // Leitura da op��o escolhida pelo usu�rio

    switch (opcao) {
    case 1: { // Op��o para cadastrar cliente
      std::string nome, telefone, endereco;
      std::cout << "Nome: ";
      std::cin.ignore();            // Ignora o '\n' residual do buffer
      std::getline(std::cin, nome); // L� o nome completo (com espacos)
      std::cout << "Telefone: ";
      std::getline(std::cin, telefone); // L� o telefone
      std::cout << "Endereco: ";
      std::getline(std::cin, endereco); // L� o endere�o
      hotel.cadastrarCliente(
          nome, telefone,
          endereco); // Chama o m�todo de cadastro na classe Hotel-
      break;
    }
    case 2: { // Op��o para cadastrar funcion�rio
      std::string nome, telefone, cargo;
      double salario;
      std::cout << "Nao deixe nenhum campo vazio\n";
      std::cout << "Nome: ";
      std::cin.ignore();            // Ignora o '\n' residual do buffer
      std::getline(std::cin, nome); // L� o nome completo (com espacos)
      std::cout << "Telefone: ";
      std::getline(std::cin, telefone); // L� o telefone
      std::cout << "Cargo: ";
      std::getline(std::cin, cargo); // L� o cargo
      std::cout << "Salario: ";
      std::cin >> salario; // L� o sal�rio
      hotel.cadastrarFuncionario(
          nome, telefone, cargo,
          salario); // Chama o m�todo de cadastro na classe Hotel
      break;
    }
    case 3: { // Op��o para cadastrar quarto
      int numero, qtdHospedes;
      double valorDiaria;
      std::cout << "Numero do Quarto: ";
      std::cin >> numero; // L� o n�mero do quarto
      std::cout << "Quantidade de Hospedes: ";
      std::cin >> qtdHospedes; // L� a capacidade do quarto em h�spedes
      std::cout << "Valor da Diaria: ";
      std::cin >> valorDiaria; // L� o valor da di�ria do quarto
      hotel.cadastrarQuarto(
          numero, qtdHospedes,
          valorDiaria); // Chama o m�todo de cadastro na classe Hotel
      break;
    }
    case 4: { // Op��o para cadastrar estadia
      int codCliente, qtdHospedes, qtdDiarias;
      std::string dataEntrada, dataSaida;
      std::cout << "Codigo do Cliente: ";
      std::cin >> codCliente; // L� o c�digo do cliente
      std::cout << "Data de Entrada (DD/MM/AAAA): ";
      std::cin.ignore();                   // Ignora o '\n' residual do buffer
      std::getline(std::cin, dataEntrada); // L� a data de entrada
      std::cout << "Data de Saida (DD/MM/AAAA): ";
      std::getline(std::cin, dataSaida); // L� a data de sa�da
      std::cout << "Quantidade de Hospedes: ";
      std::cin >> qtdHospedes; // L� a quantidade de h�spedes
      std::cout << "Quantidade de Diarias: ";
      std::cin >> qtdDiarias; // L� a quantidade de di�rias
      hotel.cadastrarEstadia(
          codCliente, dataEntrada, dataSaida, qtdDiarias,
          qtdHospedes); // Chama o m�todo de cadastro na classe Hotel
      break;
    }
    case 5: { // Op��o para dar baixa em estadia
      int codigoEstadia;
      std::cout << "Codigo da Estadia: ";
      std::cin >> codigoEstadia;            // L� o c�digo da estadia
      hotel.darBaixaEstadia(codigoEstadia); // Chama o m�todo para dar baixa na
                                            // estadia na classe Hotel
      break;
    }
    case 6: { // Op��o para pesquisar cliente por nome ou c�digo
      std::string nome;
      int codigo;
      std::cout << "Nome do Cliente (deixe em branco se nao quiser pesquisar "
                   "por nome): ";
      std::cin.ignore();            // Ignora o '\n' residual do buffer
      std::getline(std::cin, nome); // L� o nome completo (com espacos)
      std::cout
          << "Codigo do Cliente (deixe 0 se nao quiser pesquisar por codigo): ";
      std::cin >> codigo; // L� o c�digo do cliente
      hotel.pesquisarClientePorNomeOuCodigo(
          nome, codigo); // Chama o m�todo de pesquisa na classe Hotel
      break;
    }
    case 7: { // Op��o para pesquisar funcion�rio por nome ou c�digo
      std::string nome;
      int codigo;
      std::cout << "Nome do Funcionario (deixe em branco se nao quiser "
                   "pesquisar por nome): ";
      std::cin.ignore();            // Ignora o '\n' residual do buffer
      std::getline(std::cin, nome); // L� o nome completo (com espacos)
      std::cout << "Codigo do Funcionario (deixe 0 se nao quiser pesquisar por "
                   "codigo): ";
      std::cin >> codigo; // L� o c�digo do funcion�rio
      hotel.pesquisarFuncionarioPorNomeOuCodigo(
          nome, codigo); // Chama o m�todo de pesquisa na classe Hotel
      break;
    }
    case 8: { // Op��o para mostrar estadias de um cliente
      int codigoCliente;
      std::cout << "Codigo do Cliente: ";
      std::cin >> codigoCliente; // L� o c�digo do cliente
      hotel.mostrarEstadiasCliente(
          codigoCliente); // Chama o m�todo para mostrar estadias na classe
                          // Hotel
      break;
    }
    case 9: { // Op��o para calcular pontos de fidelidade de um cliente
      int codigoCliente;
      std::cout << "Codigo do Cliente: ";
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
      std::cout << "Digite o codigo do funcionario a ser removido: ";
      std::cin >> codigo; // L� o c�digo do funcion�rio a ser removido
      hotel.deletarFuncionario(
          codigo); // Chama o m�todo para remover funcion�rio na classe Hotel
      break;
    }
    case 13: { // Op��o para remover cliente
      int codigo;
      std::cout << "Digite o codigo do cliente a ser removido: ";
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
      std::cout << "Opcao invalida!\n";
    }
  } while (opcao != 0); // Continua executando o loop enquanto a op��o escolhida
                        // n�o for 0 (sair do programa)

  return 0;
}
