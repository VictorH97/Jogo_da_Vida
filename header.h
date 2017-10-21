#define TAM 100
#define VIVO 2
#define MORTO 0
#define LIMPA -1

int lerDados(int ind[][TAM], int *gera);
void nasceCelula(int ind[][TAM], int nasc[][TAM], int tam);
void morreCelula(int ind[][TAM], int mor[][TAM], int tam);
void exibirMundo(int ind[][TAM], int mor[][TAM], int nasc[][TAM], int tamundo);
void salvarDados(int ind[][TAM], int tamundo);
int carregarDados(int ind[][TAM], int tamundo);
void clear(int nasc[][TAM], int mor[][TAM], int tamundo);
