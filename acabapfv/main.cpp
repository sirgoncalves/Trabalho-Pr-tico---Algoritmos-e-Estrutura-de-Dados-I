#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

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

    void setNome(const std::string& nome) { this->nome = nome; }
    void setTelefone(const std::string& telefone) { this->telefone = telefone; }
};

class Cliente : public Pessoa {
private:
    std::string endereco;

public:
    Cliente(int cod, std::string nome, std::string telefone, std::string endereco)
        : Pessoa(cod, nome, telefone), endereco(endereco) {}

    std::string getEndereco() const { return endereco; }
    void setEndereco(const std::string& endereco) { this->endereco = endereco; }
};

class Funcionario : public Pessoa {
private:
    std::string cargo;
    double salario;

public:
    Funcionario(int cod, std::string nome, std::string telefone, std::string cargo, double salario)
        : Pessoa(cod, nome, telefone), cargo(cargo), salario(salario) {}

    std::string getCargo() const { return cargo; }
    double getSalario() const { return salario; }

    void setCargo(const std::string& cargo) { this->cargo = cargo; }
    void setSalario(double salario) { this->salario = salario; }
};
class Quarto {
private:
    int numero;
    int quantidadeHospedes;
    double valorDiaria;
    bool ocupado;

public:
    Quarto(int num, int qtdHospedes, double valorDiaria)
        : numero(num), quantidadeHospedes(qtdHospedes), valorDiaria(valorDiaria), ocupado(false) {}

    int getNumero() const { return numero; }
    int getQuantidadeHospedes() const { return quantidadeHospedes; }
    double getValorDiaria() const { return valorDiaria; }
    bool isOcupado() const { return ocupado; }

    void setOcupado(bool status) { ocupado = status; }
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
    Estadia(int codEstadia, std::string entrada, std::string saida, int qtdDiarias, int codCliente, int numQuarto)
        : codigoEstadia(codEstadia), dataEntrada(entrada), dataSaida(saida), quantidadeDiarias(qtdDiarias), codigoCliente(codCliente), numeroQuarto(numQuarto) {}

    int getCodigoEstadia() const { return codigoEstadia; }
    std::string getDataEntrada() const { return dataEntrada; }
    std::string getDataSaida() const { return dataSaida; }
    int getQuantidadeDiarias() const { return quantidadeDiarias; }
    int getCodigoCliente() const { return codigoCliente; }
    int getNumeroQuarto() const { return numeroQuarto; }
};
class Hotel {
private:
    std::vector<Cliente> clientes;
    std::vector<Funcionario> funcionarios;
    std::vector<Estadia> estadias;
    std::vector<Quarto> quartos;

    int gerarCodigoCliente() {
        return clientes.size() + 1; // Código simples gerado sequencialmente
    }

    int gerarCodigoFuncionario() {
        return funcionarios.size() + 1; // Código simples gerado sequencialmente
    }

    int gerarCodigoEstadia() {
        return estadias.size() + 1; // Código simples gerado sequencialmente
    }

public:
    void cadastrarCliente(std::string nome, std::string telefone, std::string endereco) {
        int codigo = gerarCodigoCliente();
        clientes.push_back(Cliente(codigo, nome, telefone, endereco));
        std::cout << "Cliente cadastrado com sucesso! Código: " << codigo << std::endl;
    }

    void cadastrarFuncionario(std::string nome, std::string telefone, std::string cargo, double salario) {
    // Verifica se o cargo já está ocupado
    for (const auto& funcionario : funcionarios) {
        if (funcionario.getCargo() == cargo) {
            std::cout << "Erro: Já existe um funcionário com o cargo " << cargo << std::endl;
            return;
        }
    }
    int codigo = gerarCodigoFuncionario();
    funcionarios.push_back(Funcionario(codigo, nome, telefone, cargo, salario));
    std::cout << "Funcionario cadastrado com sucesso! Código: " << codigo << std::endl;
}
    void cadastrarQuarto(int numero, int qtdHospedes, double valorDiaria) {
        quartos.push_back(Quarto(numero, qtdHospedes, valorDiaria));
        std::cout << "Quarto cadastrado com sucesso! Número: " << numero << std::endl;
    }

    void cadastrarEstadia(int codCliente, std::string dataEntrada, std::string dataSaida, int quantidadeDiarias, int qtdHospedes) {
        for (auto& quarto : quartos) {
            if (!quarto.isOcupado() && quarto.getQuantidadeHospedes() >= qtdHospedes) {
                int codigoEstadia = gerarCodigoEstadia();
                estadias.push_back(Estadia(codigoEstadia, dataEntrada, dataSaida, quantidadeDiarias, codCliente, quarto.getNumero()));
                quarto.setOcupado(true);
                std::cout << "Estadia cadastrada com sucesso! Código: " << codigoEstadia << std::endl;
                return;
            }
        }
        std::cout << "Não há quartos disponíveis para a quantidade de hóspedes desejada." << std::endl;
    }

    void darBaixaEstadia(int codigoEstadia) {
        for (auto& estadia : estadias) {
            if (estadia.getCodigoEstadia() == codigoEstadia) {
                for (auto& quarto : quartos) {
                    if (quarto.getNumero() == estadia.getNumeroQuarto()) {
                        quarto.setOcupado(false);
                        double valorTotal = estadia.getQuantidadeDiarias() * quarto.getValorDiaria();
                        std::cout << "Estadia finalizada. Valor total: R$ " << valorTotal << std::endl;
                        return;
                    }
                }
            }
        }
        std::cout << "Estadia não encontrada." << std::endl;
    }

    void pesquisarClientePorNomeOuCodigo(const std::string& nome, int codigo) {
        for (const auto& cliente : clientes) {
            if (cliente.getNome() == nome || cliente.getCodigo() == codigo) {
                std::cout << "Cliente encontrado: " << cliente.getNome() << ", Código: " << cliente.getCodigo() << std::endl;
                return;
            }
        }
        std::cout << "Cliente não encontrado." << std::endl;
    }

    void pesquisarFuncionarioPorNomeOuCodigo(const std::string& nome, int codigo) {
        for (const auto& funcionario : funcionarios) {
            if (funcionario.getNome() == nome || funcionario.getCodigo() == codigo) {
                std::cout << "Funcionario encontrado: " << funcionario.getNome() << ", Código: " << funcionario.getCodigo() << std::endl;
                return;
            }
        }
        std::cout << "Funcionario não encontrado." << std::endl;
    }

    void mostrarEstadiasCliente(int codigoCliente) {
        for (const auto& estadia : estadias) {
            if (estadia.getCodigoCliente() == codigoCliente) {
                std::cout << "Estadia: " << estadia.getCodigoEstadia() << ", Quarto: " << estadia.getNumeroQuarto()
                          << ", Entrada: " << estadia.getDataEntrada() << ", Saída: " << estadia.getDataSaida()
                          << ", Diárias: " << estadia.getQuantidadeDiarias() << std::endl;
            }
        }
    }

    int calcularPontosFidelidade(int codigoCliente) {
        int pontos = 0;
        for (const auto& estadia : estadias) {
            if (estadia.getCodigoCliente() == codigoCliente) {
                pontos += estadia.getQuantidadeDiarias() * 10;
            }
        }
        return pontos;
    }


    void carregarDados(const std::string& nomeArquivo) {
        std::ifstream arquivo(nomeArquivo, std::ios::binary);

        if (!arquivo) {
            std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << " para leitura." << std::endl;
            return;
        }

        // Limpar dados atuais
        clientes.clear();
        funcionarios.clear();
        estadias.clear();
        quartos.clear();

        // Ler quantidade de clientes
        int numClientes;
        arquivo.read(reinterpret_cast<char*>(&numClientes), sizeof(numClientes));

        // Ler clientes
        for (int i = 0; i < numClientes; ++i) {
            Cliente cliente(0, "", "", "");
            arquivo.read(reinterpret_cast<char*>(&cliente), sizeof(cliente));
            clientes.push_back(cliente);
        }

        // Ler quantidade de funcionários
        int numFuncionarios;
        arquivo.read(reinterpret_cast<char*>(&numFuncionarios), sizeof(numFuncionarios));

        // Ler funcionários
        for (int i = 0; i < numFuncionarios; ++i) {
            Funcionario funcionario(0, "", "", "", 0.0);
            arquivo.read(reinterpret_cast<char*>(&funcionario), sizeof(funcionario));
            funcionarios.push_back(funcionario);
        }

        // Ler quantidade de estadias
        int numEstadias;
        arquivo.read(reinterpret_cast<char*>(&numEstadias), sizeof(numEstadias));

        // Ler estadias
        for (int i = 0; i < numEstadias; ++i) {
            Estadia estadia(0, "", "", 0, 0, 0);
            arquivo.read(reinterpret_cast<char*>(&estadia), sizeof(estadia));
            estadias.push_back(estadia);
        }

        // Ler quantidade de quartos
        int numQuartos;
        arquivo.read(reinterpret_cast<char*>(&numQuartos), sizeof(numQuartos));

        // Ler quartos
        for (int i = 0; i < numQuartos; ++i) {
            Quarto quarto(0, 0, 0.0);
            arquivo.read(reinterpret_cast<char*>(&quarto), sizeof(quarto));
            quartos.push_back(quarto);
        }

        arquivo.close();
    }

    // Métodos de acesso aos vetores
    const std::vector<Cliente>& getClientes() const { return clientes; }
    const std::vector<Funcionario>& getFuncionarios() const { return funcionarios; }
    const std::vector<Estadia>& getEstadias() const { return estadias; }
    const std::vector<Quarto>& getQuartos() const { return quartos; }







};
int main() {
    Hotel hotel;
    int opcao;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Cadastrar Cliente\n";
        std::cout << "2. Cadastrar Funcionario\n";
        std::cout << "3. Cadastrar Quarto\n";
        std::cout << "4. Cadastrar Estadia\n";
        std::cout << "5. Dar Baixa em Estadia\n";
        std::cout << "6. Pesquisar Cliente\n";
        std::cout << "7. Pesquisar Funcionario\n";
        std::cout << "8. Mostrar Estadias de Cliente\n";
        std::cout << "9. Calcular Pontos de Fidelidade\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch(opcao) {
            case 1: {
                std::string nome, telefone, endereco;
                std::cout << "Nome: "; std::cin >> nome;
                std::cout << "Telefone: "; std::cin >> telefone;
                std::cout << "Endereco: "; std::cin >> endereco;
                hotel.cadastrarCliente(nome, telefone, endereco);
                break;
            }
            case 2: {
                std::string nome, telefone, cargo;
                double salario;
                std::cout << "Nome: "; std::cin >> nome;
                std::cout << "Telefone: "; std::cin >> telefone;
                std::cout << "Cargo: "; std::cin >> cargo;
                std::cout << "Salario: "; std::cin >> salario;
                hotel.cadastrarFuncionario(nome, telefone, cargo, salario);
                break;
            }
            case 3: {
                int numero, qtdHospedes;
                double valorDiaria;
                std::cout << "Numero do quarto: "; std::cin >> numero;
                std::cout << "Quantidade de hospedes: "; std::cin >> qtdHospedes;
                std::cout << "Valor da diaria: "; std::cin >> valorDiaria;
                hotel.cadastrarQuarto(numero, qtdHospedes, valorDiaria);
                break;
            }
            case 4: {
                int codCliente, qtdHospedes;
                std::string dataEntrada, dataSaida;
                int quantidadeDiarias;
                std::cout << "Codigo do cliente: "; std::cin >> codCliente;
                std::cout << "Data de entrada (DD/MM/AAAA): "; std::cin >> dataEntrada;
                std::cout << "Data de saida (DD/MM/AAAA): "; std::cin >> dataSaida;
                std::cout << "Quantidade de diarias: "; std::cin >> quantidadeDiarias;
                std::cout << "Quantidade de hospedes: "; std::cin >> qtdHospedes;
                hotel.cadastrarEstadia(codCliente, dataEntrada, dataSaida, quantidadeDiarias, qtdHospedes);
                break;
            }
            case 5: {
                int codigoEstadia;
                std::cout << "Codigo da estadia: "; std::cin >> codigoEstadia;
                hotel.darBaixaEstadia(codigoEstadia);
                break;
            }
            case 6: {
                std::string nome;
                int codigo;
                std::cout << "Nome ou codigo do cliente: "; std::cin >> nome;
                std::cout << "Codigo do cliente (se aplicável): "; std::cin >> codigo;
                hotel.pesquisarClientePorNomeOuCodigo(nome, codigo);
                break;
            }
            case 7: {
                std::string nome;
                int codigo;
                std::cout << "Nome ou codigo do funcionario: "; std::cin >> nome;
                std::cout << "Codigo do funcionario (se aplicável): "; std::cin >> codigo;
                hotel.pesquisarFuncionarioPorNomeOuCodigo(nome, codigo);
                break;
            }
            case 8: {
                int codigoCliente;
                std::cout << "Codigo do cliente: "; std::cin >> codigoCliente;
                hotel.mostrarEstadiasCliente(codigoCliente);
                break;
            }
            case 9: {
                int codigoCliente;
                std::cout << "Codigo do cliente: "; std::cin >> codigoCliente;
                int pontos = hotel.calcularPontosFidelidade(codigoCliente);
                std::cout << "Pontos de fidelidade: " << pontos << std::endl;
                break;
            }
        }
    } while (opcao != 0);

    return 0;
}
