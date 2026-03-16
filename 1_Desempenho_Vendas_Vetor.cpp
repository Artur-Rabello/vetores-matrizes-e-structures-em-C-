/*
======================================================
 Exercício2 - Vetores - Desempenho de vendas semanal 
======================================================
O programa deve executar as seguintes ações:

1.Entrada de Vendas Diárias: 
Solicita ao usuário que insira os valores de vendas 
para seis dias consecutivos da semana (segunda,terça,
quarta, quinta, sexta e sábado). Utilizar um vetor
para armazenar os valores e outro para armazenar os
dias da semana.
dia_semana[]={"segunda","terça  ","quarta ","quinta ","sexta  ","sábado "}

Dia [segunda] = R$ ?
Dia [terça  ] = R$ ?
Dia [quarta ] = R$ ?
Dia [quinta ] = R$ ?
Dia [sexta  ] = R$ ?
Dia [sábado ] = R$ ?

2.Definir uma Meta de Vendas: O usuário deve inserir 
uma meta de vendas específica para a semana.

Meta de vendas   R$ 0000.00

3.Exibição das Vendas: Após a entrada de todos os dados, 
o programa exibe o valor de venda registrado para cada 
um dos seis dias.

==== Vendas da semana/dia =====

Dia [segunda] = R$ 0000.00
Dia [terça  ] = R$ 0000.00
Dia [quarta ] = R$ 0000.00
Dia [quinta ] = R$ 0000.00
Dia [sexta  ] = R$ 0000.00
Dia [sábado ] = R$ 0000.00

4.Cálculo do Total de Vendas: Ele soma todas as vendas 
diárias e exibe o total de vendas da semana.

Total das vendas R$ 0000.00

5.Cáculo da média de vendas da semana

Média de vendas da semana R$ 0000.00

6.Verificação da Meta: O programa compara o total de vendas 
da semana com a meta estabelecida pelo usuário e informa se 
a meta foi atingida ou não.

Meta de vendas atingida com sucesso !!

7.Identificação do maior volume de vendas: 
Ele encontra o dia com o maior volume de vendas e mostra o 
dia e o valor correspondente.

Dia que mais vendeu => quinta  => R$ 0000.00

8.O programa deve perguntar ao usuário se ele deseja executar 
a análise novamente. 
===========================================================*/


#include <iostream>
#include <clocale>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".UTF8");

    const int tam = 6;
    string dias[tam] = {"segunda","terca","quarta","quinta","sexta","sabado"};

    while(true)
    {
        double vendas[tam];
        float meta;
        float soma = 0;
        float media;
        float maior;
        string maior_dia;
        char op;

        system("cls");

        cout << "=====================================\n";
        cout << "   ANALISE DE VENDAS DA SEMANA\n";
        cout << "=====================================\n\n";

        cout << "Digite as vendas diarias:\n\n";

        for (int i = 0; i < tam; i++)
        {
            cout << "Dia [" << dias[i] << "] = R$: ";
            cin >> vendas[i];
        }

        cout << "\nMeta de vendas da semana: R$ ";
        cin >> meta;

        system("cls");

        cout << "=====================================\n";
        cout << "      RELATORIO DE VENDAS\n";
        cout << "=====================================\n\n";

        cout << fixed << setprecision(2);

        for (int i = 0; i < tam; i++)
        {
            cout << "Dia [" << dias[i] << "] = R$ " << vendas[i] << endl;
        }

        cout << "\n-------------------------------------\n";

        for (int i = 0; i < tam; i++)
        {
            soma += vendas[i];
        }

        media = soma / tam;

        cout << "Total da semana : R$ " << soma << endl;
        cout << "Media da semana : R$ " << media << endl;

        cout << "\n-------------------------------------\n";

        if(soma >= meta)
        {
        	cout << "Meta R$ : " << meta << endl;
            cout << "Meta de vendas atingida com sucesso!\n";
        }
        else
        {
        	cout << "Meta R$ : " << meta << endl;
            cout << "A meta de vendas nao foi atingida.\n";
        }

        cout << "\n-------------------------------------\n";

        maior = vendas[0];
        maior_dia = dias[0];

        for(int i = 1; i < tam; i++)
        {
            if (vendas[i] > maior)
            {
                maior = vendas[i];
                maior_dia = dias[i];
            }
        }

        cout << "Maior venda da semana:\n";
        cout << maior_dia << " => R$ " << maior << endl;

        cout << "\n=====================================\n";
        cout << "Deseja analisar outra semana? (s/n): ";
        cin >> op;

        if(op == 'n' || op == 'N')
        {
            break;
        }
    }

    return 0;
}