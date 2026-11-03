
/******************************************************************************

INF101
Trabalho – Implementação de um Sistema de
Registro e Gestão de Contas Bancárias (ETAPA 2)

Aluno: João Pedro Ferraz Barreto
Matrícula: 29059

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int MAX_CONTAS = 100;
    const int MAX_MOVIMENTACOES = 500;

    // Arrays para armazenar os dados das contas
    int numeroConta[MAX_CONTAS];
    string nomeCliente[MAX_CONTAS];
    string cpf[MAX_CONTAS];
    int tipoConta[MAX_CONTAS];
    double saldo[MAX_CONTAS];

    int quantidadeContas = 0;

    // Arrays para armazenar o historico de movimentacoes
    int contaMovimentacao[MAX_MOVIMENTACOES];
    char tipoMovimentacao[MAX_MOVIMENTACOES];
    double valorMovimentacao[MAX_MOVIMENTACOES];

    int quantidadeMovimentacoes = 0;

    int numero, numeroPesquisa, numeroDestino;
    int indice, indiceOrigem, indiceDestino;
    double valor;

    do {

        cout << "\n********************************" << endl;
        cout << "********** ADS BANK ************" << endl;
        cout << "********************************" << endl;

        cout << "**********   MENU   ************" << endl;
        cout << "********************************" << endl;

        cout << "1 - Cadastrar conta" << endl;
        cout << "2 - Listar contas" << endl;
        cout << "3 - Consultar conta" << endl;
        cout << "4 - Realizar deposito" << endl;
        cout << "5 - Realizar saque" << endl;
        cout << "6 - Realizar transferencia" << endl;
        cout << "7 - Exibir extrato" << endl;
        cout << "8 - Sair" << endl;

        cout << "********************************" << endl;
        cout << "Digite o numero da opcao desejada: ";
        cin >> numero;

        switch (numero) {

            // 1 - CADASTRAR CONTA
            case 1: {

                cout << "\n--- CADASTRO DE CONTA ---\n";

                if (quantidadeContas >= MAX_CONTAS) {

                    cout << "Limite maximo de contas atingido.\n";

                } else {

                    do {
                        cout << "Numero da conta: ";
                        cin >> numeroConta[quantidadeContas];

                        if (numeroConta[quantidadeContas] <= 0) {
                            cout << "Erro: o numero deve ser maior que zero.\n";
                        }

                    } while (numeroConta[quantidadeContas] <= 0);

                    // Verifica se o numero da conta ja existe
                    indice = -1;

                    for (int i = 0; i < quantidadeContas; i++) {
                        if (numeroConta[i] == numeroConta[quantidadeContas]) {
                            indice = i;
                        }
                    }

                    if (indice != -1) {

                        cout << "Erro: ja existe uma conta com esse numero.\n";

                    } else {

                        cin.ignore();

                        cout << "Nome do titular: ";
                        getline(cin, nomeCliente[quantidadeContas]);

                        cout << "CPF do titular: ";
                        getline(cin, cpf[quantidadeContas]);

                        do {
                            cout << "Tipo da conta (1 - Corrente / 2 - Poupanca): ";
                            cin >> tipoConta[quantidadeContas];

                            if (tipoConta[quantidadeContas] != 1 &&
                                tipoConta[quantidadeContas] != 2) {
                                cout << "Erro: escolha 1 ou 2.\n";
                            }

                        } while (tipoConta[quantidadeContas] != 1 &&
                                 tipoConta[quantidadeContas] != 2);

                        do {
                            cout << "Saldo inicial: R$ ";
                            cin >> saldo[quantidadeContas];

                            if (saldo[quantidadeContas] < 0) {
                                cout << "Erro: o saldo nao pode ser negativo.\n";
                            }

                        } while (saldo[quantidadeContas] < 0);

                        quantidadeContas++;

                        cout << "\nConta cadastrada com sucesso!\n";
                    }
                }

                break;
            }

            // 2 - LISTAR CONTAS
            case 2: {

                cout << "\n--- LISTA DE CONTAS ---\n";

                if (quantidadeContas == 0) {

                    cout << "Nenhuma conta foi cadastrada.\n";

                } else {

                    for (int i = 0; i < quantidadeContas; i++) {

                        cout << "\n----------------------------\n";
                        cout << "Numero da conta: " << numeroConta[i] << endl;
                        cout << "Titular: " << nomeCliente[i] << endl;
                        cout << "CPF: " << cpf[i] << endl;

                        if (tipoConta[i] == 1) {
                            cout << "Tipo: Corrente\n";
                        } else {
                            cout << "Tipo: Poupanca\n";
                        }

                        cout << "Saldo: R$ " << saldo[i] << endl;
                    }
                }

                break;
            }

            // 3 - CONSULTAR CONTA
            case 3: {

                cout << "\n--- CONSULTA DE CONTA ---\n";

                cout << "Digite o numero da conta: ";
                cin >> numeroPesquisa;

                indice = -1;

                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numeroPesquisa) {
                        indice = i;
                    }
                }

                if (indice == -1) {

                    cout << "Conta nao encontrada.\n";

                } else {

                    cout << "\nNumero da conta: " << numeroConta[indice] << endl;
                    cout << "Nome do titular: " << nomeCliente[indice] << endl;
                    cout << "CPF: " << cpf[indice] << endl;

                    if (tipoConta[indice] == 1) {
                        cout << "Tipo: Corrente\n";
                    } else {
                        cout << "Tipo: Poupanca\n";
                    }

                    cout << "Saldo: R$ " << saldo[indice] << endl;
                }

                break;
            }

            // 4 - REALIZAR DEPOSITO
            case 4: {

                cout << "\n--- REALIZAR DEPOSITO ---\n";

                cout << "Numero da conta: ";
                cin >> numeroPesquisa;

                indice = -1;

                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numeroPesquisa) {
                        indice = i;
                    }
                }

                if (indice == -1) {

                    cout << "Conta nao encontrada.\n";

                } else if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {

                    cout << "Limite de movimentacoes atingido.\n";

                } else {

                    do {
                        cout << "Valor do deposito: R$ ";
                        cin >> valor;

                        if (valor <= 0) {
                            cout << "Erro: o valor deve ser maior que zero.\n";
                        }

                    } while (valor <= 0);

                    saldo[indice] = saldo[indice] + valor;

                    contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indice];
                    tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                    valorMovimentacao[quantidadeMovimentacoes] = valor;

                    quantidadeMovimentacoes++;

                    cout << "Deposito realizado com sucesso!\n";
                    cout << "Novo saldo: R$ " << saldo[indice] << endl;
                }

                break;
            }

            // 5 - REALIZAR SAQUE
            case 5: {

                cout << "\n--- REALIZAR SAQUE ---\n";

                cout << "Numero da conta: ";
                cin >> numeroPesquisa;

                indice = -1;

                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numeroPesquisa) {
                        indice = i;
                    }
                }

                if (indice == -1) {

                    cout << "Conta nao encontrada.\n";

                } else {

                    do {
                        cout << "Valor do saque: R$ ";
                        cin >> valor;

                        if (valor <= 0) {
                            cout << "Erro: o valor deve ser maior que zero.\n";
                        }

                    } while (valor <= 0);

                    if (valor > saldo[indice]) {

                        cout << "Saldo insuficiente para realizar o saque.\n";

                    } else if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {

                        cout << "Limite de movimentacoes atingido.\n";

                    } else {

                        saldo[indice] = saldo[indice] - valor;

                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indice];
                        tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                        valorMovimentacao[quantidadeMovimentacoes] = valor;

                        quantidadeMovimentacoes++;

                        cout << "Saque realizado com sucesso!\n";
                        cout << "Novo saldo: R$ " << saldo[indice] << endl;
                    }
                }

                break;
            }

            // 6 - REALIZAR TRANSFERENCIA
            case 6: {

                cout << "\n--- REALIZAR TRANSFERENCIA ---\n";

                cout << "Numero da conta de origem: ";
                cin >> numeroPesquisa;

                cout << "Numero da conta de destino: ";
                cin >> numeroDestino;

                indiceOrigem = -1;
                indiceDestino = -1;

                // Localiza as duas contas
                for (int i = 0; i < quantidadeContas; i++) {

                    if (numeroConta[i] == numeroPesquisa) {
                        indiceOrigem = i;
                    }

                    if (numeroConta[i] == numeroDestino) {
                        indiceDestino = i;
                    }
                }

                if (indiceOrigem == -1 || indiceDestino == -1) {

                    cout << "Uma ou ambas as contas nao foram encontradas.\n";

                } else if (indiceOrigem == indiceDestino) {

                    cout << "Nao e possivel transferir para a mesma conta.\n";

                } else if (quantidadeMovimentacoes > MAX_MOVIMENTACOES - 2) {

                    cout << "Espaco insuficiente no historico de movimentacoes.\n";

                } else {

                    do {
                        cout << "Valor da transferencia: R$ ";
                        cin >> valor;

                        if (valor <= 0) {
                            cout << "Erro: o valor deve ser maior que zero.\n";
                        }

                    } while (valor <= 0);

                    if (valor > saldo[indiceOrigem]) {

                        cout << "Saldo insuficiente para realizar a transferencia.\n";

                    } else {

                        // Atualiza os saldos das duas contas
                        saldo[indiceOrigem] = saldo[indiceOrigem] - valor;
                        saldo[indiceDestino] = saldo[indiceDestino] + valor;

                        // Registra a saida da conta de origem
                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceOrigem];
                        tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                        valorMovimentacao[quantidadeMovimentacoes] = valor;

                        quantidadeMovimentacoes++;

                        // Registra a entrada na conta de destino
                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceDestino];
                        tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                        valorMovimentacao[quantidadeMovimentacoes] = valor;

                        quantidadeMovimentacoes++;

                        cout << "Transferencia realizada com sucesso!\n";
                        cout << "Novo saldo da origem: R$ " << saldo[indiceOrigem] << endl;
                        cout << "Novo saldo do destino: R$ " << saldo[indiceDestino] << endl;
                    }
                }

                break;
            }

            // 7 - EXIBIR EXTRATO
            case 7: {

                cout << "\n--- EXTRATO DA CONTA ---\n";

                cout << "Numero da conta: ";
                cin >> numeroPesquisa;

                indice = -1;

                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numeroPesquisa) {
                        indice = i;
                    }
                }

                if (indice == -1) {

                    cout << "Conta nao encontrada.\n";

                } else {

                    cout << "\nTitular: " << nomeCliente[indice] << endl;
                    cout << "Numero da conta: " << numeroConta[indice] << endl;

                    cout << "\n--- MOVIMENTACOES ---\n";

                    bool encontrouMovimentacao = false;

                    for (int i = 0; i < quantidadeMovimentacoes; i++) {

                        if (contaMovimentacao[i] == numeroPesquisa) {

                            encontrouMovimentacao = true;

                            if (tipoMovimentacao[i] == 'D') {

                                cout << "Deposito/Transferencia recebida: R$ "
                                     << valorMovimentacao[i] << endl;

                            } else if (tipoMovimentacao[i] == 'S') {

                                cout << "Saque/Transferencia enviada: R$ "
                                     << valorMovimentacao[i] << endl;
                            }
                        }
                    }

                    if (!encontrouMovimentacao) {
                        cout << "Nenhuma movimentacao registrada.\n";
                    }

                    cout << "\nSaldo atual: R$ " << saldo[indice] << endl;
                }

                break;
            }

            // 8 - SAIR
            case 8:

                cout << "\nSistema encerrado. Obrigado por utilizar o ADS BANK!\n";
                break;

            default:

                cout << "\nOpcao invalida! Escolha uma opcao de 1 a 8.\n";
        }

    } while (numero != 8);

    return 0;
}
