#include "Classes.cpp"
#include <iostream>

void ListarQuartosOcupados(){
    
}

void CadastrarClientes(Cliente listaClientes[Max_Clientes]){
    if(ContadorPessoas<Max_Clientes){
        char nomeCliente[80];
        cout << "Insira o nome do cliente: ";
        cin >> nomeCliente;
        fflush(stdin);
        listaClientes[ContadorPessoas].setNome(nomeCliente);

    }

}

/*
void cadastrarPessoa(Pessoa listaPessoas[MAX_PESSOAS],
                     Veiculo listaVeiculos[MAX_VEICULO]) {
  if (contP < MAX_PESSOAS) { // Se nao ultrapassou a capacidade do vetor
    char nome[50];
    cout << "Digite um nome de pessoa:";
    cin >> nome;
    fflush(stdin);
    listaPessoas[contP].setNome(nome);

    // 1ª Busca no vetor de veculos uma veículo existente e associa a pessoa
    // Lista os veículos exitentes
    listarVeiculos(listaVeiculos);
    // Busca pela placa
    char placa[10];
    cout << "Digite a placa do veiculo que eh seu:";
    cin >> placa;
    fflush(stdin);

    Veiculo *encontrado = buscarVeiculos(listaVeiculos, placa);
    if (encontrado != NULL) {                     // Encontrou o veículo
      listaPessoas[contP].setVeiculo(encontrado); // associa
      listaPessoas[contP].mostrar();
    } else
      cout << "Veiculo nao encontrado.\n";
  }
}
*/
