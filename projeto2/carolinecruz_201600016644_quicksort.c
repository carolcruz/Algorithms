#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct whatever{
	
	int size;
	int *array;

}vectors;

typedef struct whateverr{
	
	int size;
	char name[3];

}vector;

int n=0;

vector counts[6];

vectors *set=NULL;

int particionar(int V[], int inicio, int fim);
void quickPadrao(int V[], int inicio, int fim);
int hoare(int V[], int inicio, int fim);
void quickHoarePadrao(int V[], int inicio, int fim);
void printa(int tam, FILE *output, int i);
void getData(FILE* input);
int particionar2(int V[], int inicio, int fim);
int randomico(int V[], int inicio, int fim);
void quickRandomico(int V[], int inicio, int fim);
int hoare(int V[], int inicio, int fim);
int hoare(int V[], int inicio, int fim);
void quickHoarePadrao(int V[], int inicio, int fim);
int hoare2(int V[], int inicio, int fim);
int hoareRandomico(int V[], int inicio, int fim);
void quickHoareRandomico(int V[], int inicio, int fim);
int particionar3(int V[], int inicio, int fim);
int med(int V[], int inicio, int fim);
void quickMediana(int V[], int inicio, int fim);
int hoare3(int V[], int inicio, int fim);
int medh(int V[], int inicio, int fim);
void quickHoareMediana(int V[], int inicio, int fim);
int *copy(int *array, int *aux, int n);
void bubble_sort(vector vetor[], int n);
void putData(FILE* output);
void printa(int tam, FILE *output, int i);

// ======================================

int main(int argc, char *argv[])
{
	printf("#ARGS = %i\n", argc);
	printf("PROGRAMA = %s\n", argv[0]);
	printf("ARG1 = %s, ARG2 = %s\n", argv[1], argv[2]);
    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");
    getData(input);
    putData(output);
    fclose(input);
    fclose(output);
    free(set);

    return 0;

 }

void getData(FILE* input){

	fscanf(input, "%d\n", &n);
	set = (vectors*)malloc(n*sizeof(vectors));

	int i=0, j=0, len=0, aux=0;
	for(i=0; i<n; i++){
		fscanf(input, "%d", &len);
		set[i].size = len;
		set[i].array = (int*)malloc(len*sizeof(int));
		for(j=0; j<len; j++){
			fscanf(input, "%d", &aux);
			set[i].array[j] = aux;
		}
	}
}

// -------PARTICIONAR PADRÃO--------------

int particionar(int V[], int inicio, int fim) {
	int pivo = V[fim];
	int aux = 0;
	int i = inicio - 1, j;
	for(j = inicio; j < fim; j++){
		if(V[j] <= pivo) {
			i++;
			aux = V[i];
			V[i] = V[j];
			V[j] = aux;
			counts[0].size++;
		}
	}
	aux = V[i+1];
	V[i+1] = V[fim];
	V[fim] = aux;
	counts[0].size++;
	return i+1;
}

void quickPadrao(int V[], int inicio, int fim) {
	counts[0].size++;
	if(inicio < fim) {
		int pivo = particionar(V, inicio, fim);
		quickPadrao(V, inicio, pivo-1);
		quickPadrao(V, pivo+1, fim);
	}
}

// ---------PARTICIONAMENTO ALEATORIO--------------

int particionar2(int V[], int inicio, int fim){
	int pivo = V[fim];
	int aux = 0;
	int i = inicio - 1, j;
	for(j = inicio; j < fim; j++){
		if(V[j] <= pivo) {
			i++;
			aux = V[i];
			V[i] = V[j];
			V[j] = aux;
			counts[2].size++;
		}
	}
	aux = V[i+1];
	V[i+1] = V[fim];
	V[fim] = aux;
	counts[2].size++;
	return i+1;
}

int randomico(int V[], int inicio, int fim){
	counts[2].size++;
	int i = inicio+(abs(V[inicio])%(fim-inicio+1));
	int aux=0;
	aux = V[fim];
	V[fim] = V[i];
	V[i] = aux;
	return particionar2(V, inicio, fim);
}

void quickRandomico(int V[], int inicio, int fim){
	counts[2].size++;
	if(inicio < fim) {
		int pivo = randomico(V, inicio, fim);
		quickRandomico(V, inicio, pivo-1);
		quickRandomico(V, pivo+1, fim);
	}
}

// ----------PARTICIONAMENTO HOARE---------------

int hoare(int V[], int inicio, int fim){
	int pivo = V[inicio], aux=0;
	int i = inicio;
	int j = fim;
	while(i < j) {
		while(j > i && V[j] >= pivo) j--;
		while(i < j && V[i] < pivo) i++;
		if(i < j){
			aux = V[i];
			V[i] = V[j];
			V[j] = aux;
			counts[3].size++;
		}
	}
	return j;
}

void quickHoarePadrao(int V[], int inicio, int fim){
	counts[3].size++;
	if(inicio < fim) {
		int pivo = hoare(V, inicio, fim);
		quickHoarePadrao(V, inicio, pivo);
		quickHoarePadrao(V, pivo + 1, fim);
	}
}

// -----------HOARE RANDOMICO----------------

int hoare2(int V[], int inicio, int fim){
	int pivo = V[inicio], aux=0;
	int i = inicio;
	int j = fim;
	while(i < j) {
		while(j > i && V[j] >= pivo) j--;
		while(i < j && V[i] < pivo) i++;
		if(i < j){
			aux = V[i];
			V[i] = V[j];
			V[j] = aux;
			counts[5].size++;
		}
	}
	return j;
}

int hoareRandomico(int V[], int inicio, int fim){
	int i = inicio+(abs(V[inicio])%(fim-inicio+1));
	int aux=0;
	aux = V[inicio];
	V[inicio] = V[i];
	V[i] = aux;
	counts[5].size++;
	return hoare2(V, inicio, fim);
}

void quickHoareRandomico(int V[], int inicio, int fim){
	counts[5].size++;
	if(inicio < fim) {
		int pivo = hoareRandomico(V, inicio, fim);
		quickHoareRandomico(V, inicio, pivo);
		quickHoareRandomico(V, pivo+1, fim);
	}
}

// -------PARTICIONAR MEDIANA DE 3--------------

int particionar3(int V[], int inicio, int fim){
	int pivo = V[fim];
	int aux = 0;
	int i = inicio - 1, j;
	for(j = inicio; j < fim; j++){
		if(V[j] <= pivo) {
			i++;
			aux = V[i];
			V[i] = V[j];
			V[j] = aux;
			counts[1].size++;
		}
	}
	aux = V[i+1];
	V[i+1] = V[fim];
	V[fim] = aux;
	counts[1].size++;
	return i+1;
}

int med(int V[], int inicio, int fim){
	int a = V[inicio+((fim-inicio+1)/4)], b = V[inicio+((fim-inicio+1)/2)], 
		c = V[inicio+(3*(fim-inicio+1)/4)];
	int array[] = {a, b, c};
	int i=0, aux=0, j=0;
	for(i = 1; i < 3; i = i+1){
		for(j = i; j > 0 && array[j-1] > array[j]; j--){
			aux = array[j];
			array[j] = array[j-1];
			array[j-1] = aux;
		}
	}
	int var=0;
	if(array[1] == a) var = inicio+((fim-inicio+1)/4);
	else if (array[1] == b) var = inicio+((fim-inicio+1)/2);
	else var = inicio+(3*(fim-inicio+1)/4);

	aux = V[fim];
	V[fim] = V[var];
	V[var] = aux;
	counts[1].size++;

	return particionar3(V, inicio, fim);

}

void quickMediana(int V[], int inicio, int fim){
	counts[1].size++;
	if(inicio < fim) {
		int pivo = med(V, inicio, fim);
		quickMediana(V, inicio, pivo-1);
		quickMediana(V, pivo+1, fim);
	}
}

// -----------HOARE MEDIANA DE 3----------------

int hoare3(int V[], int inicio, int fim){
	int pivo = V[inicio], aux=0;
	int i = inicio;
	int j = fim;
	while(i < j) {
		while(j > i && V[j] >= pivo) j--;
		while(i < j && V[i] < pivo) i++;
		if(i < j){
			aux = V[i];
			V[i] = V[j];
			V[j] = aux;
			counts[4].size++;
		}
	}
	return j;
}

int medh(int V[], int inicio, int fim){
	int a = V[inicio+((fim-inicio+1)/4)], b = V[inicio+((fim-inicio+1)/2)], c = V[inicio+(3*(fim-inicio+1)/4)];
	int array[] = {a, b, c};
	int i=0, aux=0, j=0;
	for(i = 1; i < 3; i = i+1){
		for(j = i; j > 0 && array[j-1] > array[j]; j--){
			aux = array[j];
			array[j] = array[j-1];
			array[j-1] = aux;
		}
	}
	int var=0;
	if(array[1] == a) var = inicio+((fim-inicio+1)/4);
	else if (array[1] == b) var = inicio+((fim-inicio+1)/2);
	else var = inicio+(3*(fim-inicio+1)/4);

	aux = V[inicio];
	V[inicio] = V[var];
	V[var] = aux;
	counts[4].size++;

	return hoare3(V, inicio, fim);
}

void quickHoareMediana(int V[], int inicio, int fim){
	counts[4].size++;
	if(inicio < fim) {
		int pivo = medh(V, inicio, fim);
		quickHoareMediana(V, inicio, pivo);
		quickHoareMediana(V, pivo+1, fim);
	}
}

// --------------------------------------------

int *copy(int *array, int *aux, int n){
	int i=0;
	for(i=0; i<n; i++){
		aux[i] = array[i];
	}

	return aux;
}

void sort(vector vetor[], int n){
    int k, j, aux;
    char str[5];
    for (k=1; k < n; k++) {
        for (j=k; j>0 && vetor[j-1].size>vetor[j].size; j--) {
            	strcpy(str, vetor[j].name);
                aux = vetor[j].size;
                strcpy(vetor[j].name, vetor[j-1].name);
                vetor[j].size = vetor[j-1].size;
                strcpy(vetor[j-1].name, str);
                vetor[j-1].size = aux;
        }
    }
}

void putData(FILE* output){

	int i=0, j=0;
	int *aux=NULL, *aux2=NULL, *aux3=NULL, *aux4=NULL, *aux5=NULL, *aux6=NULL;

	for(i=0; i<n; i++){
		counts[0].size = 0; counts[1].size = 0; counts[2].size = 0; 
		counts[3].size = 0; counts[4].size = 0; counts[5].size = 0;

		strcpy(counts[0].name,"PP");
		strcpy(counts[1].name,"PM");
		strcpy(counts[2].name,"PA");
		strcpy(counts[3].name,"HP");
		strcpy(counts[4].name,"HM");	
		strcpy(counts[5].name,"HA");

		int tam=set[i].size;
		
		aux = (int*)malloc(tam*sizeof(int));
		aux = copy(set[i].array, aux, tam);
		quickPadrao(aux, 0, tam-1);
		
		aux2 = (int*)malloc(tam*sizeof(int));
		aux2 = copy(set[i].array, aux2, tam);
		quickRandomico(aux2, 0, tam-1);
		
		aux3 = (int*)malloc(tam*sizeof(int));
		aux3 = copy(set[i].array, aux3, tam);
		quickHoarePadrao(aux3, 0, tam-1);
		
		aux4 = (int*)malloc(tam*sizeof(int));
		aux4 = copy(set[i].array, aux4, tam);
		quickHoareRandomico(aux4, 0, tam-1);
		
		aux5 = (int*)malloc(tam*sizeof(int));
		aux5 = copy(set[i].array, aux5, tam);
		quickMediana(aux5, 0, tam-1);
		
		aux6 = (int*)malloc(tam*sizeof(int));
		aux6 = copy(set[i].array, aux6, tam);
		quickHoareMediana(aux6, 0, tam-1);
		
		sort(counts, 6);
		fprintf(output, "%d: N(%d) %s(%d) %s(%d) %s(%d) %s(%d) %s(%d) %s(%d)\n", 
			i, tam, counts[0].name, counts[0].size, counts[1].name, counts[1].size,
			counts[2].name, counts[2].size, counts[3].name, counts[3].size, counts[4].name, 
			counts[4].size, counts[5].name, counts[5].size);

		free(aux);
		free(aux2);
		free(aux3);
		free(aux4);
		free(aux5);
		free(aux6);
	}
}