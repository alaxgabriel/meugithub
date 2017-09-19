#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//consegui?
//função de comparação que é necessário para implementação da função qsort();
int comparar(const void *a, const void *b){
    //caso os parâmetros a e b sejam iguais, a função retorna 0;
    if (*(float*)a == *(float*)b)
        return 0;
    //caso o a seja maior que o b, a função retorna 1;
    //do contrário, retorna -1;
    else
        if(*(float*)a > *(float*)b)
            return 1;
        else
            return -1;
}

//função para imprimir os arrays;
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

    //nesse momento, ocorre uma alocação na memória; em que um bloco de memória de dados do tipo float será
    //criado, com tamanho equivalente ao tamanho do seu tipo em bytes.
    //o endereço do primeiro conteúdo do bloco de memória é armaxenado em x.
	x = (float*) malloc(n*sizeof(float));

	for(i=0; i<n; i++){
        x[i] = rand() % n + 1;
    }

    //laço que preenche o bloco de memória alocado
	/*for(i=0; i<n; i++){
        printf("Digite o %i: ", i);
        scanf("%f", &x[i]);
        printf("\n");
	}*/

    //chamada da funçaõ que colocará os dados do bloco de meória em ordem.
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

	//chamada da função que exibirá os dados do bloco de memória alocado, já com os conteúdos na forma ordenada
	//printar(x, n);



	//função que apaga o bloco de memória que havia sido alocado
	free(x);
	//ser�?

	return 0;

}

