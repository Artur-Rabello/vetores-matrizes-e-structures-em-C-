/*
========================================================
     Exercício3:  Controle de Estoque de uma Loja
========================================================
Uma loja vende 4 produtos diferentes (1,2,3 e 4) e possui 
3 filiais (1,2 e 3). O gerente da loja deseja controlar o 
estoque de cada produto em cada filial. Para isso, ele 
utiliza uma matriz 3x4, onde as linhas representam as 
filiais e as colunas representam os produtos.

O programa deverá realizar as seguintes funcionalidades:

1.Declarar uma matriz 3x4 de inteiros para representar o 
 estoque da loja.
 
2.Solicitar ao usuário que digite a quantidade de cada 
 produto em cada filial.
 
3.Exibir o estoque da loja no formato de matriz, mostrando 
 a quantidade de cada produto em cada filial.
 
4.Calcular e exibir o total de cada produto em todas as filiais.

5.Calcular e exibir o total de produtos em cada filial.
*/

/*
========================================================
     Exercício3:  Controle de Estoque de uma Loja
========================================================
*/

#include <iostream>
#include <iomanip> 
#include <Windows.h>

using namespace std;

int main() 
{
    SetConsoleOutputCP(CP_UTF8);

    const int linha = 3;
    const int coluna = 4;

    int matriz[linha][coluna];

    cout << "=== DIGITE O ESTOQUE DA LOJA ===\n\n";

    // 1 e 2 - entrada de dados
    for (int i = 0; i < linha; i++) 
    {
        for (int j = 0; j < coluna; j++) 
        {
            cout << "Filial[" << i+1 << "] Produto[" << j+1 << "]: ";
            cin >> matriz[i][j];
        }
    }

    cout << "\n\n=== ESTOQUE DA LOJA ===\n\n";
	
	// Cabeçalho (Produtos)
	cout << setw(12) << " ";
	for (int j = 0; j < coluna; j++) 
	{
	    cout << setw(5) << "P[" << j+1 << "]";
	}
	cout << endl;
	
    // 3 - mostrar matriz
    for (int i = 0; i < linha; i++) 
    {
        cout << "Filial " << i+1 << " : ";

        for (int j = 0; j < coluna; j++) 
        {
            cout << setw(6) << matriz[i][j];
        }

        cout << endl;
    }

    cout << "\n=== TOTAL DE CADA PRODUTO ===\n";

    // 4 - total por produto
    for (int j = 0; j < coluna; j++) 
    {
        int soma = 0;

        for (int i = 0; i < linha; i++) 
        {
            soma += matriz[i][j];
        }

        cout << "Produto " << j+1 << " = " << soma << endl;
    }

    cout << "\n=== TOTAL POR FILIAL ===\n";

    // 5 - total por filial
    for (int i = 0; i < linha; i++) 
    {
        int soma = 0;

        for (int j = 0; j < coluna; j++) 
        {
            soma += matriz[i][j];
        }

        cout << "Filial " << i+1 << " = " << soma << endl;
    }

    return 0;
}