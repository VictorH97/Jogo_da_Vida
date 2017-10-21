#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "header.h"
#include "funcaocelula.c"

int main(){

	int individuo[TAM][TAM];
	int nascidos[TAM][TAM];
	int mortos[TAM][TAM];
	int geracoes, mundo, k = 0, i, j;
	char opcao;

	printf("JOGO DA VIDA\n");
	printf("\nO que deseja fazer:\n");
	printf("1 -- Iniciar novo jogo\n");
	printf("2 -- Carregar jogo\n");
	opcao = getch();

	if(opcao == '1'){               //novo jogo
		mundo = lerDados(individuo, &geracoes);

		printf("\t");
		for(i=0; i < mundo; i++)
		{
			printf("%d\t", i);
		}
		printf("\n");

		for(i=0;i < mundo;i++){
			printf("%d\t", i);
			for(j=0;j < mundo; j++){
				if(individuo[i][j] == VIVO)
					printf("%c\t", 'O');
						else printf("%c\t", ' ');
			}
		printf("\n");
		printf("\n");
		}

		for(k=1;k < geracoes;k++){
			//system("cls");
			nasceCelula(individuo, nascidos, mundo);
		//	printf("NASCEU");
			morreCelula(individuo, mortos, mundo);
	//		printf("MORREU");
			exibirMundo(individuo, mortos, nascidos, mundo);
	//		printf("EXIBIU");
			clear(nascidos, mortos, mundo);
	//		printf("DEU CLEAR");
			printf("\n");
			printf("\n");
		}

		printf("Deseja salvar o mundo?(s/n)");
		opcao = getch();
		if((opcao == 's') || (opcao == 'S')) salvarDados(individuo, mundo);

	}

		else if(opcao == '2'){        //carregando dados
			mundo = carregarDados(individuo, mundo);
			printf("Digite o n%cmero de gera%c%ces a serem simuladas: ", 163, 135, 228);
			scanf("%d", &geracoes);

			printf("\t");
		for(i=0; i < mundo; i++)
		{
			printf("%d\t", i);
		}
		printf("\n");

			for(i=0;i < mundo;i++){
				printf("%d\t", i);
				for(j=0;j < mundo; j++){
					if(individuo[i][j] == VIVO)
						printf("%c\t", 'O');
							else printf("%c\t", ' ');
			}
		printf("\n");
		printf("\n");
		}

		for(k=1;k < geracoes;k++){
			system("cls");
			nasceCelula(individuo, nascidos, mundo);
			morreCelula(individuo, mortos, mundo);
			exibirMundo(individuo, mortos, nascidos, mundo);
			clear(nascidos, mortos, mundo);
		}

		printf("Deseja salvar o mundo?(s/n)");
		opcao = getch();
		if((opcao == 's') || (opcao == 'S')) salvarDados(individuo, mundo);

		}
}

