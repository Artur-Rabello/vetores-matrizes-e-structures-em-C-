/*Exercício: Sistema de Gestão de Contas Bancárias
O programa deverá realizar as seguintes funcionalidades:

Definir uma Struct chamada ContaBancaria com os campos: 
numero (int), 
titular (string)
saldo (double).

Criar um Vetor desta struct para armazenar até 10 contas.

O numero da conta será gerado automaticamente pelo sistema 
com base no índice do vetor no momento do cadastro.
A primeira conta cadastrada (índice 0) receberá o Número 1.
A segunda conta (índice 1) receberá o Número 2, e assim 
sucessivamente.

Implementar um Menu com as seguintes opções:
============================================

1.Cadastrar Conta: Solicita o nome do titular e gera um 
número automático. O saldo inicial deve ser R$ 0.00.

2.Depositar: Localiza a conta pelo número e adiciona um 
valor ao saldo.

3.Sacar: Localiza a conta pelo número e subtrai um valor 
(verificando se há saldo suficiente).

4.Consultar Saldos: Exibe os dados de todas as contas 
cadastradas.

5.Sair: Encerra a aplicação.
*/

#include <iostream>
#include <iomanip>

using namespace std;

struct ContaBancaria{
	int numero;
	string titular;
	double saldo;	
};

int main(){
	
	const int tam = 5;
	ContaBancaria listaContas[tam];
	int qtdContas = 0; 
	int op;
	int buscar = 0;
	
	
	while(true){	

		cout << "\n=== Menu ===" << endl;
		cout << "1.Cadastrar conta" << endl;
		cout << "2.Depositar" << endl;
		cout << "3.Sacar" << endl;
		cout << "4.Consultar saldos" << endl;
		cout << "5. Sair" << endl;
		cout << " digigte a opcao desejada : ";
		cin >> op;
		
		if (op == 5){
			system("cls");
			break;
		}
		
		switch (op){
			
			case 1:	{
				if(qtdContas < tam){
					
					cout << "Digite o nome do titular da conta : ";
					cin.ignore();
					getline(cin, listaContas[qtdContas].titular);
					listaContas[qtdContas].numero = qtdContas + 1;
					listaContas[qtdContas].saldo = 0.0;
				
					cout << "conta " << listaContas[qtdContas].numero 
					<< " de nome " << listaContas[qtdContas].titular << " foi criada com sucesso" << endl;
					
					qtdContas ++;
				} else{
					cout << "Limite de contas atingido\n";
					break;
				}
				break;
			}
																								
			case 2: {
			
				int numContaDep;
				double valorDep;
				bool encontrouDep = false;
				
				cout << "Em qual conta deseja depositar o dinheiro : ";
				cin >> numContaDep;
				
				for(int i = 0; i < qtdContas; i++){
						if(listaContas[i].numero == numContaDep){
							
							cout << "Qual valor vai depositar : ";
							cin >> valorDep;
							
							listaContas[i].saldo += valorDep;
							encontrouDep = true;
							
							cout << "A conta : " << listaContas[i].numero << " foi depositado um saldo de : " << valorDep 
							<< " e esta com um total de : " << listaContas[i].saldo << endl;
							
							break;
						}
				}
				
				if(!encontrouDep){
					cout << "conta nao encontrada !!!";
				}
							
				break;
			}
				
			case 3: {
				int numContaSac;
				double valorSac;
				bool encontrouSac = false;
				
				cout << "Em qual conta deseja sacar o dinheiro : ";
				cin >> numContaSac;
				
				for(int i = 0; i < qtdContas; i++){
						if(listaContas[i].numero == numContaSac){
							
							cout << "Qual valor vai sacar : ";
							cin >> valorSac;
							
							if(valorSac <= listaContas[i].saldo){
								listaContas[i].saldo -= valorSac;
								encontrouSac = true;
								
								cout << "A conta : " << listaContas[i].numero << " foi sacado um saldo de : " << valorSac 
								<< " e esta com um total de : " << listaContas[i].saldo << endl;
								
								break;
							}
						}
				}
				
				if(!encontrouSac){
					cout << "valor exede o saldo da conta !!!";
				}
							
				break; 
			}
			
			case 4: {
				cout << " ==== Contas ====";
				for(int i = 0; i < qtdContas; i++){
					cout << "\nConta: " << listaContas[i].numero;
            		cout << "\nTitular: " << listaContas[i].titular;
            		cout << "\nSaldo: R$ " << fixed << setprecision(2)
                	<< listaContas[i].saldo << endl;
				}
				
			}			
		}
	}
}