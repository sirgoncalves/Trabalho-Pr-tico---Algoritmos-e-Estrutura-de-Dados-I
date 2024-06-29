#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int Max_Clientes = 100;
const int Max_Funcionarios = 100;
const int Max_estadias = 100;
const int Max_Quartos = 100;

int ContadorClientes = 0;
int ContadorFuncionarios = 0;
int ContadorEstadias = 0;
int ContadorQuartos = 0;

class Cliente {
private:
    string Nome;
    string CPF;
    int Codigo;
public:
    void setNome(string nome) { Nome = nome; }
    void setCPF(string cpf) { CPF = cpf; }
    void setCodigo(int codigo) { Codigo = codigo; }

    string getNome() { return Nome; }
    string getCPF() { return CPF; }
    int getCodigo() { return Codigo; }
};

class Funcionario {
private:
    string Nome;
    string CPF;
    int Codigo;
public:
    void setNome(string nome) { Nome = nome; }
    void setCPF(string cpf) { CPF = cpf; }
    void setCodigo(int codigo) { Codigo = codigo; }

    string getNome() { return Nome; }
    string getCPF() { return CPF; }
    int getCodigo() { return Codigo; }
};

class Quarto {
private:
    int Numero;
    string Tipo;
    bool Disponivel;
public:
    void setNumero(int numero) { Numero = numero; }
    void setTipo(string tipo) { Tipo = tipo; }
    void setDisponivel(bool disponivel) { Disponivel = disponivel; }

    int getNumero() { return Numero; }
    string getTipo() { return Tipo; }
    bool getDisponivel() { return Disponivel; }
};

class Estadia {
private:
    Cliente* CodigoCliente;
    Quarto* NumeroQuarto;
    int QuantidadeDiarias;
    bool Ativa;
public:
    void setCodigoCliente(Cliente* codigoCliente) { CodigoCliente = codigoCliente; }
    void setNumeroQuarto(Quarto* numeroQuarto) { NumeroQuarto = numeroQuarto; }
    void setQuantidadeDiarias(int quantidadeDiarias) { QuantidadeDiarias = quantidadeDiarias; }
    void setAtiva(bool ativa) { Ativa = ativa; }

    Cliente* getCodigoCliente() { return CodigoCliente; }
    Quarto* getNumeroQuarto() { return NumeroQuarto; }
    int getQuantidadeDiarias() { return QuantidadeDiarias; }
    bool getAtiva() { return Ativa; }
};

void CadastrarClientes(Cliente ClientesDoHotel[Max_Clientes]) {
    if (ContadorClientes >= Max_Clientes) {
        cout << "Número máximo de clientes cadastrados atingido." << endl;
        return;
    }

    string nome, cpf;
    cout << "Digite o nome do cliente: ";
    cin >> nome;
    cout << "Digite o CPF do cliente: ";
    cin >> cpf;

    Cliente novoCliente;
    novoCliente.setNome(nome);
    novoCliente.setCPF(cpf);
    novoCliente.setCodigo(ContadorClientes + 1);

    ClientesDoHotel[ContadorClientes] = novoCliente;
    ContadorClientes++;

    cout << "Cliente cadastrado com sucesso!" << endl;
}

void listarClientesCadastrados(Cliente ClientesDoHotel[Max_Clientes]) {
    cout << "Clientes cadastrados:" << endl;
    for (int i = 0; i < ContadorClientes; i++) {
        cout << "Codigo: " << ClientesDoHotel[i].getCodigo() << ", Nome: " << ClientesDoHotel[i].getNome() << ", CPF: " << ClientesDoHotel[i].getCPF() << endl;
    }
}

void CadastrarFuncionarios(Funcionario listaFuncionarios[Max_Funcionarios]) {
    if (ContadorFuncionarios >= Max_Funcionarios) {
        cout << "Número máximo de funcionários cadastrados atingido." << endl;
        return;
    }

    string nome, cpf;
    cout << "Digite o nome do funcionario: ";
    cin >> nome;
    cout << "Digite o CPF do funcionario: ";
    cin >> cpf;

    Funcionario novoFuncionario;
    novoFuncionario.setNome(nome);
    novoFuncionario.setCPF(cpf);
    novoFuncionario.setCodigo(ContadorFuncionarios + 1);

    listaFuncionarios[ContadorFuncionarios] = novoFuncionario;
    ContadorFuncionarios++;

    cout << "Funcionario cadastrado com sucesso!" << endl;
}

void ListarFuncionariosCadastrados(Funcionario listaFuncionarios[Max_Funcionarios]) {
    cout << "Funcionarios cadastrados:" << endl;
    for (int i = 0; i < ContadorFuncionarios; i++) {
        cout << "Codigo: " << listaFuncionarios[i].getCodigo() << ", Nome: " << listaFuncionarios[i].getNome() << ", CPF: " << listaFuncionarios[i].getCPF() << endl;
    }
}

void CadastrarEstadia(Estadia listaEstadias[Max_estadias], Cliente ClientesDoHotel[Max_Clientes], Quarto listaQuartos[Max_Quartos]) {
    if (ContadorEstadias >= Max_estadias) {
        cout << "Número máximo de estadias cadastradas atingido." << endl;
        return;
    }

    int codigoCliente, numeroQuarto, quantidadeDiarias;
    cout << "Digite o código do cliente: ";
    cin >> codigoCliente;
    cout << "Digite o número do quarto: ";
    cin >> numeroQuarto;
    cout << "Digite a quantidade de diárias: ";
    cin >> quantidadeDiarias;

    Cliente* cliente = nullptr;
    for (int i = 0; i < ContadorClientes; i++) {
        if (ClientesDoHotel[i].getCodigo() == codigoCliente) {
            cliente = &ClientesDoHotel[i];
            break;
        }
    }

    if (cliente == nullptr) {
        cout << "Cliente não encontrado!" << endl;
        return;
    }

    Quarto* quarto = nullptr;
    for (int i = 0; i < ContadorQuartos; i++) {
        if (listaQuartos[i].getNumero() == numeroQuarto && listaQuartos[i].getDisponivel()) {
            quarto = &listaQuartos[i];
            break;
        }
    }

    if (quarto == nullptr) {
        cout << "Quarto não encontrado ou indisponível!" << endl;
        return;
    }

    Estadia novaEstadia;
    novaEstadia.setCodigoCliente(cliente);
    novaEstadia.setNumeroQuarto(quarto);
    novaEstadia.setQuantidadeDiarias(quantidadeDiarias);
    novaEstadia.setAtiva(true);

    listaEstadias[ContadorEstadias] = novaEstadia;
    ContadorEstadias++;

    quarto->setDisponivel(false);

    cout << "Estadia cadastrada com sucesso!" << endl;
}

void ListarEstadias(Estadia listaEstadias[Max_estadias]) {
    cout << "Estadias cadastradas:" << endl;
    for (int i = 0; i < ContadorEstadias; i++) {
        cout << "Cliente: " << listaEstadias[i].getCodigoCliente()->getNome() << ", Quarto: " << listaEstadias[i].getNumeroQuarto()->getNumero() << ", Diárias: " << listaEstadias[i].getQuantidadeDiarias() << ", Ativa: " << (listaEstadias[i].getAtiva() ? "Sim" : "Não") << endl;
    }
}

void cadastrarQuarto(Quarto listaQuartos[Max_Quartos]) {
    if (ContadorQuartos >= Max_Quartos) {
        cout << "Número máximo de quartos cadastrados atingido." << endl;
        return;
    }

    int numero;
    string tipo;
    cout << "Digite o número do quarto: ";
    cin >> numero;
    cout << "Digite o tipo do quarto: ";
    cin >> tipo;

    Quarto novoQuarto;
    novoQuarto.setNumero(numero);
    novoQuarto.setTipo(tipo);
    novoQuarto.setDisponivel(true);

    listaQuartos[ContadorQuartos] = novoQuarto;
    ContadorQuartos++;

    cout << "Quarto cadastrado com sucesso!" << endl;
}

void listarQuartos(Quarto listaQuartos[Max_Quartos]) {
    cout << "Quartos cadastrados:" << endl;
    for (int i = 0; i < ContadorQuartos; i++) {
        cout << "Numero: " << listaQuartos[i].getNumero() << ", Tipo: " << listaQuartos[i].getTipo() << ", Disponível: " << (listaQuartos[i].getDisponivel() ? "Sim" : "Não") << endl;
    }
}

void DarBaixaEstadia(Estadia listaEstadias[Max_estadias]) {
    int codigoCliente;
    cout << "Digite o código do cliente: ";
    cin >> codigoCliente;

    for (int i = 0; i < ContadorEstadias; i++) {
        if (listaEstadias[i].getCodigoCliente()->getCodigo() == codigoCliente && listaEstadias[i].getAtiva()) {
            listaEstadias[i].setAtiva(false);
            listaEstadias[i].getNumeroQuarto()->setDisponivel(true);
            cout << "Estadia encerrada com sucesso!" << endl;
            return;
        }
    }

    cout << "Estadia não encontrada ou já encerrada!" << endl;
}

void MostrarEstadiasCliente(Estadia listaEstadias[Max_estadias], Cliente ClientesDoHotel[Max_Clientes]) {
    int codigoCliente;
    cout << "Digite o código do cliente: ";
    cin >> codigoCliente;

    Cliente* cliente = nullptr;
    for (int i = 0; i < ContadorClientes; i++) {
        if (ClientesDoHotel[i].getCodigo() == codigoCliente) {
            cliente = &ClientesDoHotel[i];
            break;
        }
    }

    if (cliente == nullptr) {
        cout << "Cliente não encontrado!" << endl;
        return;
    }

    cout << "Estadias do cliente " << cliente->getNome() << ":" << endl;
    bool encontrouEstadia = false;
    for (int i = 0; i < ContadorEstadias; i++) {
        if (listaEstadias[i].getCodigoCliente()->getCodigo() == codigoCliente) {
            cout << "Quarto: " << listaEstadias[i].getNumeroQuarto()->getNumero() << ", Diárias: " << listaEstadias[i].getQuantidadeDiarias() << ", Ativa: " << (listaEstadias[i].getAtiva() ? "Sim" : "Não") << endl;
            encontrouEstadia = true;
        }
    }

    if (!encontrouEstadia) {
        cout << "Este cliente não possui estadias cadastradas." << endl;
    }
}

void CalcularPontosFidelidade(Estadia listaEstadias[Max_estadias], Cliente ClientesDoHotel[Max_Clientes]) {
    int codigoCliente;
    cout << "Digite o código do cliente: ";
    cin >> codigoCliente;

    Cliente* cliente = nullptr;
    for (int i = 0; i < ContadorClientes; i++) {
        if (ClientesDoHotel[i].getCodigo() == codigoCliente) {
            cliente = &ClientesDoHotel[i];
            break;
        }
    }

    if (cliente == nullptr) {
        cout << "Cliente não encontrado!" << endl;
        return;
    }

    int totalDiarias = 0;
    for (int i = 0; i < ContadorEstadias; i++) {
        if (listaEstadias[i].getCodigoCliente()->getCodigo() == codigoCliente && !listaEstadias[i].getAtiva()) {
            totalDiarias += listaEstadias[i].getQuantidadeDiarias();
        }
    }

    cout << "Pontos de fidelidade do cliente " << cliente->getNome() << ": " << totalDiarias << endl;
}

void SalvarDados(Cliente ClientesDoHotel[Max_Clientes], Funcionario listaFuncionarios[Max_Funcionarios], Estadia listaEstadias[Max_estadias], Quarto listaQuartos[Max_Quartos]) {
    ofstream fileClientes("clientes.dat", ios::binary);
    if (fileClientes.is_open()) {
        fileClientes.write(reinterpret_cast<char*>(ClientesDoHotel), Max_Clientes * sizeof(Cliente));
        fileClientes.close();
        cout << "Dados de clientes salvos com sucesso!" << endl;
    } else {
        cout << "Não foi possível abrir o arquivo de clientes para salvar." << endl;
    }

    ofstream fileFuncionarios("funcionarios.dat", ios::binary);
    if (fileFuncionarios.is_open()) {
        fileFuncionarios.write(reinterpret_cast<char*>(listaFuncionarios), Max_Funcionarios * sizeof(Funcionario));
        fileFuncionarios.close();
        cout << "Dados de funcionarios salvos com sucesso!" << endl;
    } else {
        cout << "Não foi possível abrir o arquivo de funcionarios para salvar." << endl;
    }

    ofstream fileEstadias("estadias.dat", ios::binary);
    if (fileEstadias.is_open()) {
        fileEstadias.write(reinterpret_cast<char*>(listaEstadias), Max_estadias * sizeof(Estadia));
        fileEstadias.close();
        cout << "Dados de estadias salvos com sucesso!" << endl;
    } else {
        cout << "Não foi possível abrir o arquivo de estadias para salvar." << endl;
    }

    ofstream fileQuartos("quartos.dat", ios::binary);
    if (fileQuartos.is_open()) {
        fileQuartos.write(reinterpret_cast<char*>(listaQuartos), Max_Quartos * sizeof(Quarto));
        fileQuartos.close();
        cout << "Dados de quartos salvos com sucesso!" << endl;
    } else {
        cout << "Não foi possível abrir o arquivo de quartos para salvar." << endl;
    }
}

void CarregarDados(Cliente ClientesDoHotel[Max_Clientes], Funcionario listaFuncionarios[Max_Funcionarios], Estadia listaEstadias[Max_estadias], Quarto listaQuartos[Max_Quartos]) {
    ifstream fileClientes("clientes.dat", ios::binary);
    if (fileClientes.is_open()) {
        fileClientes.read(reinterpret_cast<char*>(ClientesDoHotel), Max_Clientes * sizeof(Cliente));
        fileClientes.close();
        cout << "Dados de clientes carregados com sucesso!" << endl;
    } else {
        cout << "Não foi possível abrir o arquivo de clientes para carregar." << endl;
    }

    ifstream fileFuncionarios("funcionarios.dat", ios::binary);
    if (fileFuncionarios.is_open()) {
        fileFuncionarios.read(reinterpret_cast<char*>(listaFuncionarios), Max_Funcionarios *sizeof(Funcionario));
        fileFuncionarios.close();
        cout << "Dados de funcionarios carregados com sucesso!" << endl;
    } else {
        cout << "Não foi possível abrir o arquivo de funcionarios para carregar." << endl;
    }

    ifstream fileEstadias("estadias.dat", ios::binary);
    if (fileEstadias.is_open()) {
        fileEstadias.read(reinterpret_cast<char*>(listaEstadias), Max_estadias * sizeof(Estadia));
        fileEstadias.close();
        cout << "Dados de estadias carregados com sucesso!" << endl;
    } else {
        cout << "Não foi possível abrir o arquivo de estadias para carregar." << endl;
    }

    ifstream fileQuartos("quartos.dat", ios::binary);
    if (fileQuartos.is_open()) {
        fileQuartos.read(reinterpret_cast<char*>(listaQuartos), Max_Quartos * sizeof(Quarto));
        fileQuartos.close();
        cout << "Dados de quartos carregados com sucesso!" << endl;
    } else {
        cout << "Não foi possível abrir o arquivo de quartos para carregar." << endl;
    }
}

int main() {
    Cliente ClientesDoHotel[Max_Clientes];
    Funcionario listaFuncionarios[Max_Funcionarios];
    Estadia listaEstadias[Max_estadias];
    Quarto listaQuartos[Max_Quartos];

    int opcao;
    do {
        cout << "===== Menu Principal =====" << endl;
        cout << "1 - Cadastrar cliente" << endl;
        cout << "2 - Listar clientes cadastrados" << endl;
        cout << "3 - Cadastrar funcionario" << endl;
        cout << "4 - Listar funcionarios cadastrados" << endl;
        cout << "5 - Cadastrar estadia" << endl;
        cout << "6 - Listar estadias cadastradas" << endl;
        cout << "7 - Cadastrar quarto" << endl;
        cout << "8 - Listar quartos cadastrados" << endl;
        cout << "9 - Dar baixa em estadia" << endl;
        cout << "10 - Mostrar estadias de um cliente" << endl;
        cout << "11 - Calcular pontos de fidelidade de um cliente" << endl;
        cout << "12 - Salvar dados" << endl;
        cout << "13 - Carregar dados" << endl;
        cout << "0 - Sair" << endl;
        cout << "Digite sua opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                CadastrarClientes(ClientesDoHotel);
                break;
            case 2:
                listarClientesCadastrados(ClientesDoHotel);
                break;
            case 3:
                CadastrarFuncionarios(listaFuncionarios);
                break;
            case 4:
                ListarFuncionariosCadastrados(listaFuncionarios);
                break;
            case 5:
                CadastrarEstadia(listaEstadias, ClientesDoHotel, listaQuartos);
                break;
            case 6:
                ListarEstadias(listaEstadias);
                break;
            case 7:
                cadastrarQuarto(listaQuartos);
                break;
            case 8:
                listarQuartos(listaQuartos);
                break;
            case 9:
                DarBaixaEstadia(listaEstadias);
                break;
            case 10:
                MostrarEstadiasCliente(listaEstadias, ClientesDoHotel);
                break;
            case 11:
                CalcularPontosFidelidade(listaEstadias, ClientesDoHotel);
                break;
            case 12:
                SalvarDados(ClientesDoHotel, listaFuncionarios, listaEstadias, listaQuartos);
                break;
            case 13:
                CarregarDados(ClientesDoHotel, listaFuncionarios, listaEstadias,listaQuartos);
                break;
            case 0:
                cout << "Encerrando o programa..." << endl;
                break;
            default:
                cout << "Opção inválida! Digite novamente." << endl;
                break;
        }
    } while (opcao != 0);

    return 0;
}
