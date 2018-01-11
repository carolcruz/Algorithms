#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX (512)

typedef struct s{
	char dado[2];
}aux;

typedef struct d{
	int number;
	int size;
	char *info;
}data;

data *packages=NULL, *fim=NULL;
int freq=0, packs=0;


void heapify(data *V, int i, int n) {
	int P = i;
	int E = 2*i+1;
	int D = 2*i+2;
	data aux;
	if(E < n && V[E].number > V[P].number) P = E;
	if(D < n && V[D].number > V[P].number) P = D;
	if(P != i) {
		aux = V[P];
		V[P] = V[i];
		V[i] = aux;
		heapify(V, P, n);
	}
}

void constroiHeap(data *V, int n){
	int pivo = (n-1)/2;
	int i;
	for(i=pivo; i>=0; i--){
		heapify(V, i, n);
	}
}

void heapsort(data *V, int n) {
	constroiHeap(V, n);
	int i;
	data aux;
	for(i = n-1; i > 0; i--) {
		aux = V[0];
		V[0] = V[i];
		V[i] = aux;
		heapify(V, 0, i);
	}
}

void printa(data *pointer, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%s ", pointer[i].info);
	}
	printf("\n");
}

data *copy(data *array, data *aux, int ini, int n){
	int i=0;
	for(i=ini; i<n; i++){
		aux[i] = array[i];
	}
	return aux;
}

void getData(FILE *input, FILE *output){

	int i=0, tam=0, j=0, k=0;

	fscanf(input, "%d %d", &packs, &freq);
	printf("%d %d\n", packs, freq);

	packages = (data*)malloc(packs*sizeof(data));
	printf("ok\n");

	int lidos=0;

	for(i=0; i<packs; i++){

// ================ ENTRADA ====================

		fscanf(input, "%d %d\n", &packages[i].number, &packages[i].size);
		tam = (3*packages[i].size);
		int len = packages[i].size;
		packages[i].info = (char*)malloc(tam+1*sizeof(char));
		fgets(packages[i].info, tam, input);

// ================ SAIDA ====================
		lidos++;
		
		if(lidos == freq || i+1==packs){
			heapsort(packages, i+1);
			lidos=0;
			if(packages[j].number == j){
				fprintf(output,"%d: ", k);
				while(packages[j].number == j){
					fprintf(output,"%s ", packages[j].info);
	 				j++;
			 	}
			 	fprintf(output,"\n");
			 k++;
			}
		}
	}
}

int main(int argc, char *argv[]){

	printf("#ARGS = %i\n", argc);
	printf("PROGRAMA = %s\n", argv[0]);
	printf("ARG1 = %s, ARG2 = %s\n", argv[1], argv[2]);
    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");
    getData(input, output);

    return 0;

 }