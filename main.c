#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//fun��o de compara��o que � necess�rio para implementa��o da fun��o qsort();
int comparar(const void *a, const void *b){
    //caso os par�metros a e b sejam iguais, a fun��o retorna 0;
    if (*(float*)a == *(float*)b)
        return 0;
    //caso o a seja maior que o b, a fun��o retorna 1;
    //do contr�rio, retorna -1;
    else
        if(*(float*)a > *(float*)b)
            return 1;
        else
            return -1;
}

//fun��o para imprimir os arrays;
void printar(float *x, int n){
    int i;
    for(i=0; i<n; i++){
        printf("\n%f\n", x[i]);
	}
	printf("\n");
}

int main(void){
	float *x;
	int i;
	long int n;
    //n = 100000;
    //srand(time(NULL));
    n = 100000;
    srand(time(NULL));

    //printf("\nDigite o n: ");
	//scanf("%i", &n);
    //printf("\n");

    //nesse momento, ocorre uma aloca��o na mem�ria; em que um bloco de mem�ria de dados do tipo float ser�
    //criado, com tamanho equivalente ao tamanho do seu tipo em bytes.
    //o endere�o do primeiro conte�do do bloco de mem�ria � armaxenado em x.
	x = (float*) malloc(n*sizeof(float));

	for(i=0; i<n; i++){
        x[i] = rand() % n + 1;
    }

    //la�o que preenche o bloco de mem�ria alocado
	/*for(i=0; i<n; i++){
        printf("Digite o %i: ", i);
        scanf("%f", &x[i]);
        printf("\n");
	}*/

    //chamada da fun�a� que colocar� os dados do bloco de me�ria em ordem.
	//qsort(x, n, sizeof(float), comparar);
//	qsort(x, n, sizeof(float), comparar);

    //clock_t time;
    //time = clock();
    clock_t time;
    time = clock();
    qsort(x, n, sizeof(float), comparar);
    time = clock() - time;
    //time = clock() - time;
    //printf("\nTempo: %f", ((float)time)/CLOCKS_PER_SEC);
    //printf(" segundos\n");

    printf("\nTempo: %f", ((float)time)/CLOCKS_PER_SEC);
    printf(" segundos\n");

	//chamada da fun��o que exibir� os dados do bloco de mem�ria alocado, j� com os conte�dos na forma ordenada
	//printar(x, n);



	//fun��o que apaga o bloco de mem�ria que havia sido alocado
	free(x);

	return 0;

}

