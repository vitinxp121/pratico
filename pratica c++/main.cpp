#include <iostream>
#include <string>

using namespace std;

int main() {

    // Variáveis das contas
    int numeroConta[5];
    string nomeCliente[5];
    string cpf[5];
    int tipoConta[5];
    double saldo[5];
    bool contaAtiva[5];

    int quantidadeContas = 0;
    int opcao;
    int contaEscolhida;

    do {

        cout << "\n************************************" << endl;
        cout << "**       BANCO NACIONAL            **" << endl;
        cout << "************************************" << endl;

        cout << "1 - Cadastrar conta" << endl;
        cout << "2 - Consultar conta" << endl;
        cout << "3 - Verificar saldo" << endl;
        cout << "4 - Alterar tipo da conta" << endl;
        cout << "5 - Ativar/Desativar conta" << endl;
        cout << "6 - Sair" << endl;

        cout << "\nEscolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

        case 1:

            // Verifica se ainda existe espaço para cadastrar
            if (quantidadeContas >= 5) {
                cout << "\nLimite de 5 contas atingido!" << endl;
                break;
            }

            cout << "\n===== CADASTRO DE CONTA =====" << endl;

            // Número da conta
            do {
                cout << "Numero da conta: ";
                cin >> numeroConta[quantidadeContas];

                if (numeroConta[quantidadeContas] <= 0) {
                    cout << "O numero da conta deve ser maior que zero!" << endl;
                }

            } while (numeroConta[quantidadeContas] <= 0);

            cin.ignore();

            // Nome do cliente
            cout << "Nome do cliente: ";
            getline(cin, nomeCliente[quantidadeContas]);

            // CPF
            cout << "CPF: ";
            getline(cin, cpf[quantidadeContas]);

            // Tipo da conta
            do {
                cout << "Tipo da conta (1 - Corrente / 2 - Poupanca): ";
                cin >> tipoConta[quantidadeContas];

                if (tipoConta[quantidadeContas] != 1 &&
                    tipoConta[quantidadeContas] != 2) {

                    cout << "Tipo de conta invalido!" << endl;
                }

            } while (tipoConta[quantidadeContas] != 1 &&
                     tipoConta[quantidadeContas] != 2);

            // Saldo inicial
            do {
                cout << "Saldo inicial: R$ ";
                cin >> saldo[quantidadeContas];

                if (saldo[quantidadeContas] < 0) {
                    cout << "O saldo nao pode ser negativo!" << endl;
                }

            } while (saldo[quantidadeContas] < 0);

            // Toda conta nova começa ativa
            contaAtiva[quantidadeContas] = true;

            quantidadeContas++;

            cout << "\nConta cadastrada com sucesso!" << endl;

            break;


        case 2:

            // Consultar conta
            if (quantidadeContas == 0) {
                cout << "\nNenhuma conta cadastrada!" << endl;
                break;
            }

            cout << "\nDigite o numero da conta: ";
            cin >> contaEscolhida;

            int encontrada;
            encontrada = -1;

            for (int i = 0; i < quantidadeContas; i++) {

                if (numeroConta[i] == contaEscolhida) {
                    encontrada = i;
                }
            }

            if (encontrada == -1) {
                cout << "\nConta nao encontrada!" << endl;
            }
            else {

                cout << "\n===== DADOS DA CONTA =====" << endl;
                cout << "Numero da conta: " << numeroConta[encontrada] << endl;
                cout << "Nome: " << nomeCliente[encontrada] << endl;
                cout << "CPF: " << cpf[encontrada] << endl;

                if (tipoConta[encontrada] == 1) {
                    cout << "Tipo: Conta Corrente" << endl;
                }
                else {
                    cout << "Tipo: Poupanca" << endl;
                }

                cout << "Saldo: R$ " << saldo[encontrada] << endl;

                if (contaAtiva[encontrada]) {
                    cout << "Status: Ativa" << endl;
                }
                else {
                    cout << "Status: Desativada" << endl;
                }
            }

            break;


        case 3:

            // Verificar saldo
            if (quantidadeContas == 0) {
                cout << "\nNenhuma conta cadastrada!" << endl;
                break;
            }

            cout << "\nDigite o numero da conta: ";
            cin >> contaEscolhida;

            encontrada = -1;

            for (int i = 0; i < quantidadeContas; i++) {

                if (numeroConta[i] == contaEscolhida) {
                    encontrada = i;
                }
            }

            if (encontrada == -1) {
                cout << "\nConta nao encontrada!" << endl;
            }
            else if (!contaAtiva[encontrada]) {
                cout << "\nA conta esta desativada!" << endl;
            }
            else {
                cout << "\nSaldo atual: R$ "
                     << saldo[encontrada] << endl;
            }

            break;


        case 4:

            // Alterar tipo da conta
            if (quantidadeContas == 0) {
                cout << "\nNenhuma conta cadastrada!" << endl;
                break;
            }

            cout << "\nDigite o numero da conta: ";
            cin >> contaEscolhida;

            encontrada = -1;

            for (int i = 0; i < quantidadeContas; i++) {

                if (numeroConta[i] == contaEscolhida) {
                    encontrada = i;
                }
            }

            if (encontrada == -1) {
                cout << "\nConta nao encontrada!" << endl;
            }
            else if (!contaAtiva[encontrada]) {
                cout << "\nA conta esta desativada!" << endl;
            }
            else {

                do {

                    cout << "\nNovo tipo da conta:" << endl;
                    cout << "1 - Corrente" << endl;
                    cout << "2 - Poupanca" << endl;
                    cout << "Escolha: ";
                    cin >> tipoConta[encontrada];

                    if (tipoConta[encontrada] != 1 &&
                        tipoConta[encontrada] != 2) {

                        cout << "Tipo invalido!" << endl;
                    }

                } while (tipoConta[encontrada] != 1 &&
                         tipoConta[encontrada] != 2);

                cout << "\nTipo da conta alterado com sucesso!" << endl;
            }

            break;


        case 5:

            // Ativar ou desativar conta
            if (quantidadeContas == 0) {
                cout << "\nNenhuma conta cadastrada!" << endl;
                break;
            }

            cout << "\nDigite o numero da conta: ";
            cin >> contaEscolhida;

            encontrada = -1;

            for (int i = 0; i < quantidadeContas; i++) {

                if (numeroConta[i] == contaEscolhida) {
                    encontrada = i;
                }
            }

            if (encontrada == -1) {
                cout << "\nConta nao encontrada!" << endl;
            }
            else {

                if (contaAtiva[encontrada]) {
                    contaAtiva[encontrada] = false;
                    cout << "\nConta desativada!" << endl;
                }
                else {
                    contaAtiva[encontrada] = true;
                    cout << "\nConta ativada!" << endl;
                }
            }

            break;


        case 6:

            cout << "\nSaindo do sistema..." << endl;
            break;


        default:

            cout << "\nOpcao invalida!" << endl;
        }

    } while (opcao != 6);

    return 0;
}