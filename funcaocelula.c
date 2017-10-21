int lerDados(int ind[][TAM], int *gera){
	
	int mundo;
	int i = 0, j = 0;
	int temp;
	
	printf("\nDigite o tamanho do mundo a ser criado(Max. 10): ");
	scanf("%d", &mundo);
	printf("Digite o n%cmero de gera%c%ces a serem simuladas: ", 163, 135, 228);
	scanf("%d", gera);
	printf("Entre com os indiv%cduos da primeira gera%c%co\n ", 161, 135, 198);
	printf("Linha: ");
	scanf("%d", &i);	
	if((i > (mundo-1)) || (i < 0 && i != -999)){
			printf("Digite um valor v%clido!\n", 160);
			printf("Linha: ");
			scanf("%d", &i);
		}
	
	temp = i;
	
	while(temp != -999){
		printf("Coluna: ");
		scanf("%d", &j);
		if((j > (mundo-1)) || (j < 0 && i != -999)){
			printf("Digite um valor v%clido!\n", 160);
			printf("Coluna: ");
			scanf("%d", &j);
		}
		ind[i][j] = VIVO;
		printf("Linha: ");
		scanf("%d", &i);
		if((i > (mundo-1)) || (i < 0 && i != -999)){
			printf("Digite um valor v%clido!\n", 160);
			printf("Linha: ");
			scanf("%d", &i);
		}
		temp = i;
	}
	
	return(mundo);
}

void nasceCelula(int ind[][TAM], int nasc[][TAM], int tam)

{
	
	int i, j;
	int cont = 0;
	int m, n;
	
	for(i=0;i < tam;i++){
		for(j=0;j < tam; j++){
			cont = 0;
			if(ind[i][j] != VIVO){
				//printf("\n NASCE CELULA Célula sendo escaneada %d/%d \n", i, j);
				//cont = 0;
				for(m = i-1; m < i+2; m++){
					for(n = j-1; n < j+2; n++){
						
						if(!(m < 0 || m > tam - 1 || n < 0 || n > tam -1)){
							
							if(ind[m][n] == VIVO)
							{						
							cont++;
							//printf("Achou %dº célula vizinha na posicao %d/%d\n", cont, m, n);
							}						
						
							//else printf("Achou %dº LUGAR VAZIO na posicao %d/%d\n", cont, m, n);
						}
					
					}
				}
				
				if(cont == 3) nasc[i][j] = VIVO; 
			}
		}
	}
}


void morreCelula(int ind[][TAM], int mor[][TAM], int tam){
	
	int i, j, cont, m, n;
	
	for(i=0;i < tam;i++){
		for(j=0;j < tam; j++){
			cont = 0;
			if(ind[i][j] == VIVO){
				//printf("\nMORRE CELULA Célula sendo escaneada %d/%d \n", i, j);
				//cont = 0;
				for(m = i-1; m < i+2; m++){
					for(n = j-1; n < j+2; n++){
						
						if(!(m < 0 || m > tam - 1 || n < 0 || n > tam -1)){
							
							if(ind[m][n] == VIVO)
							{	
							if(!(m == i && n == j))	
							{				
							cont++;
							//printf("Achou %dº célula vizinha na posicao %d/%d\n", cont, m, n);
							}
							//else
							//{
							//	printf("Posissaum central da cehlula\n");
							//}
							}						
						
							//else printf("Achou %dº LUGAR VAZIO na posicao %d/%d\n", cont, m, n);*/
						}
					
					}
				}
				
				
				if(cont >= 4) mor[i][j] = MORTO;
					else if((cont == 0) || (cont == 1)) mor[i][j] = MORTO;
						else if((cont == 2) || (cont == 3)) mor[i][j] = VIVO;////////////////////ISSO FOI O SEGREDO
			}
		}
	}
}

void exibirMundo(int ind[][TAM], int mor[][TAM], int nasc[][TAM], int tamundo){
	
	int i, j;
	
	for(i=0;i < tamundo;i++){
		for(j=0;j < tamundo;j++){
			if(ind[i][j] == VIVO){
				if(mor[i][j] == MORTO) ind[i][j] = MORTO;
					else if(mor[i][j] == VIVO) ind[i][j] = VIVO;/////////////////ISSO FOI A COMPLEMENTAÇÃO DO SEGREDO
			}
		}
	}
	
	for(i=0;i < tamundo;i++){
		for(j=0;j < tamundo;j++){
			if(ind[i][j] != VIVO){
				if(nasc[i][j] == VIVO) ind[i][j] = VIVO;	
			}
		}
	}
		printf("\t");
		for(i=0; i < tamundo; i++)
		{
			printf("%d\t", i);
		}
		printf("\n");
		
	for(i=0;i < tamundo;i++){
		printf("%d\t", i);
		for(j=0;j < tamundo; j++){			
			if(ind[i][j] == VIVO){
				printf("%c\t", 'O');
			}
					else printf("%c\t", ' ');
		}
		printf("\n");
		printf("\n");
	}
}
	
void salvarDados(int ind[][TAM], int tamundo){
	
	FILE *arq;
	int i, j;
	
	arq = fopen("celula.dta", "wb");
	
	fwrite(&tamundo, sizeof(int), 1, arq); ////////////////////duvida quanto ao fwrite estar depois do for	
	
	for(i=0;i < tamundo;i++){
		for(j=0;j < tamundo;j++){
			fwrite(&ind[i][j], sizeof(int), 1, arq);
		}
	}
	
	printf("\nSalvamento completo!\n");
	
	fclose(arq);
	
}

int carregarDados(int ind[][TAM], int tamundo){
	
	int i, j;
	FILE *arq;
	
	arq = fopen("celula.dta", "rb");
	
	if(arq == NULL){
		printf("Arquivo n%co encontrado\n", 198);
		exit(1);
		}
	
		else {
			
			fread(&tamundo, sizeof(int), 1, arq);
			printf("%d\n", tamundo);
			for(i=0;i < tamundo;i++){
				for(j=0;j < tamundo;j++){
					if(!feof(arq)){
						fread(&ind[i][j], sizeof(int), 1, arq);
					}
				}
			}		
		printf("Carregamento completo!\n");
		}
		
		printf("\t");
		for(i=0; i < tamundo; i++)
		{
			printf("%d\t", i);
		}
		printf("\n");
		
		for(i=0;i < tamundo;i++){
			printf("%d\t", i);
			for(j=0;j < tamundo; j++){
				if(ind[i][j] == VIVO)
					printf("%c\t", 'O');
						else printf("%c\t", ' ');
					}
			printf("\n");
			printf("\n");
		}
	
	fclose(arq);
	
	return(tamundo);
	
}

void clear(int nasc[][TAM], int mor[][TAM], int tamundo){
	
	int i, j;
	
	for(i=0;i < tamundo;i++){
		for(j=0;j < tamundo;j++){
			nasc[i][j] = LIMPA;
		}
	}

	for(i=0;i < tamundo;i++){
		for(j=0;j < tamundo;j++){
			mor[i][j] = LIMPA;
		}
	}
}

