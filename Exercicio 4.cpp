//Fiz um algoritmo que recebe uma dimensão N de uma matriz Anxn, seguido dos respectivos valores da matriz 
//(preenchendo a matriz de cima para baixo, da esquerda para a direta), 
//Ele ira verificar se A é um quadrado mágico (escrevendo “quadrado magico” caso seja e “quadrado nao magico” caso não seja).

#include<iostream>
#include <conio.h>

using namespace std;

int main(void) {
	int n, i, j;
	cin>>n;
	
	int mat[n][n];
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin>>mat[i][j];
		}
	}
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout<<mat[i][j];
		}
		cout<<"\n\n";
	}

	int somaDP = 0, somaDS = 0;
	
	//soma diagonal principal
	for (i = 0; i < n; i++) {
		somaDP += mat[i][i];
	}
	
	//soma diagonal secundária
	for (i = 0; i < n; i++) {
		somaDS += mat[i][n-i-1];
	}
	
	//soma linhas
	cout<<"\nSoma das linhas: ";
	int vetL[n];
	for (i = 0; i < n; i++) {
		vetL[i] = 0;
		for (j = 0; j < n; j++) {
			vetL[i] += mat[i][j];
		}
	}
	for (i = 0; i < n; i++) {
		cout<<vetL[i];
	}

	//soma colunas
	cout<<"\nSoma das colunas: ";
	int vetC[n];
	for (j = 0; j < n; j++) {
		vetC[j] = 0;
		for (i = 0; i < n; i++) {
			vetC[j] += mat[i][j];
		}
	}
	for (i = 0; i < n; i++) {
		cout<<vetC[i];
	}
	
	cout<<"\nSoma diagonal principal e secundária \n", somaDP, somaDS;

	int testaL = 1, testaC = 1;
	for (i = 1; i <  n; i++) {
		if (vetL[i] != vetL[i-1]) {
			testaL = 0;
			break;
		} else if (vetC[i] != vetC[i-1]) {
			testaC = 0;
			break;
		}
	}
	
	if (testaL && testaC && somaDP == somaDS && somaDP == vetL[0]) {
		cout<<"Quadrado magico";
	} else {
		cout<<"Quadrado nao magico";
	}

	return 0;
}
