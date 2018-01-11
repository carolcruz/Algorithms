#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define char_to_index(c) ((int)c - (int)'a')

typedef struct container{
	char code[13];
	char cnpj[19];
	int weight;
}Container;

typedef struct per{
	char codigo[13];
	int prct;
	int dif;
}percentual;

Container *containers=NULL, *aux = NULL;
Container *amostra=NULL;
percentual *array=NULL, *auxiliar=NULL, *fim=NULL;
int total=0, value=0, len=0;

//Functions:

int binarySearch(Container c, int low, int high);
float calculaPercent(int a, int b);
void mergeWeightKey(int low, int mid, int high);
void mergeSortCodeKey( int low, int high);
void mergeSortWeightKey( int low, int high);
int arredondamento1(float num);
void mergePercentKey(int low, int mid, int high);
void mergeSortPercentKey( int low, int high);



void getData(FILE *input){

	char n[10];
	fgets(n, 10, input);
	int tam = strlen(n);
	total = atoi(n);
	containers = (Container*)malloc(total*sizeof(Container));
	printf("%d\n", total);
	fseek(input, tam*sizeof(char), 0);

	int i=0;
	for(i=0; i<total; i++){
		char peso[8];
		fgets(containers[i].code, 13, input);
		fgets(containers[i].cnpj, 19, input);
		fgets(peso, 8, input);
		int pesinhokkk = atoi(peso);
		containers[i].weight = pesinhokkk;
	}

	char m[10];
	fgets(m, 10, input);
	//int tamanho = strlen(m);
	value = atoi(m);
	amostra = (Container*)malloc(value*sizeof(Container));
	array = (percentual*)malloc(value*sizeof(percentual));
	auxiliar = (percentual*)malloc(value*sizeof(percentual));
	aux = malloc(value*sizeof(Container));
	printf("%d\n", value);
	for(i=0; i<value; i++){
		char pesoo[8];
		fgets(amostra[i].code, 13, input);
		fgets(amostra[i].cnpj, 19, input);
		fgets(pesoo, 8, input);
		int pesinhookkk = atoi(pesoo);
		amostra[i].weight = pesinhookkk;
	}

}

void removeSpace(){
	int i=0, j=0;
	
	while(i<total){
		for(j=strlen(containers[i].code); j>0; j--){
        	if(containers[i].code[j]==' '){
            	containers[i].code[j]='\0';
            	break;
        	}   
    	}
    	i++;
	}
	i=0;
	while(i<value){
		for(j=strlen(amostra[i].code); j>0; j--){
        	if(amostra[i].code[j]==' '){
            	amostra[i].code[j]='\0';
            	break;
        	}   
    	}
    	i++;
	}
}

void putData(FILE *output){
	
	int i, a, j;
	int peso1, peso2, difereca, p, count=0;
	float porct;
	mergeSortCodeKey(0, value-1);
	for (i=0; i<total; i++){
		a = binarySearch(containers[i], 0, value-1);
		if(a!= -1 && strcmp(containers[i].cnpj, amostra[a].cnpj) !=0){
			fprintf(output, "%s: ", containers[i].code);
			fprintf(output, "%s<->%s\n", containers[i].cnpj, amostra[a].cnpj);
			count++;
		} 
	}
	printf("%d\n", count);
	count=0;


	j=0;
	for (i=0; i<total; i++){
		a = binarySearch(containers[i], 0, value-1);
		peso1=containers[i].weight;
		peso2=amostra[a].weight;
		difereca=abs(peso2-peso1);
		porct = calculaPercent(peso1, peso2); 
		p = arredondamento1(porct);
		if(a!=-1 && containers[i].weight != amostra[a].weight && p>10 
		   && strcmp(containers[i].cnpj, amostra[a].cnpj)==0){
			strcpy(array[j].codigo, amostra[a].code);
			array[j].prct = p;
			array[j].dif = difereca;
			//fprintf(output, "%s: ", containers[i].code);
			//fprintf(output, "%dkg (%d%%)\n", difereca, p);
			count++;
			fim = &array[j];
			j++;
		}
	}
	printf("%d\n", count);	
}

void putData2(FILE *output){
	
	mergeSortPercentKey(0, len-1);
	//printf("ta okay ate aqui\n");
	int i=0;
	for(i=0; i<len; i++){
		//fprintf(output, "", );
		fprintf(output, "%s: %dkg (%d%%)\n", array[i].codigo, array[i].dif, array[i].prct);
	}
	//printf("ta okay ate aqui\n");
}

void copy(Container *to, Container *from, int size) {
	int i;
	for(i=0; i<size; i++) {
		to[i] = from[i];
	}
}

void copyy(percentual *to, percentual *from, int size) {
	int i;
	for(i=0; i<size; i++) {
		to[i] = from[i];
	}
}

int binarySearch(Container c, int low, int high){
	if(high>=low){
		int mid = low+(high-low)/2;
		if(strcmp(c.code, amostra[mid].code) == 0) return mid;
		else if(strcmp(c.code, amostra[mid].code) < 0) return binarySearch(c, low, mid-1);
		else if(strcmp(c.code, amostra[mid].code) > 0) return binarySearch(c, mid + 1, high);
	}
	return -1;
}

void mergeCodeKey(int low, int mid, int high){

	int i=low, j=mid+1, k=low;

	while(i<=mid && j<=high){
		if(strcmp(amostra[i].code, amostra[j].code) <= 0){
			aux[k] = amostra[i];
			k++;
			i++;
		}
		else{
			aux[k] = amostra[j];
			k++;
			j++;
		}
	}

	if(i > mid){
		copy(&aux[k],&amostra[j],high - j + 1);
	} else {
		copy(&aux[k],&amostra[i],mid - i + 1);
	}

	copy(&amostra[low], &aux[low], high-low+1);

}


void elementosArray(){
	
	int count=-1;
	do{
		count++;
	}while(&array[count]!=fim);

	len = count+1;
	printf("%d\n", len);

}

void mergePercentKey(int low, int mid, int high){

	int i=low, j=mid+1, k=low;

	while(i<=mid && j<=high){
		if(array[i].prct >= array[j].prct){
			auxiliar[k] = array[i];
			k++;
			i++;
		}
		else{
			auxiliar[k] = array[j];
			k++;
			j++;
		}
	}
	//printf("ta okay ate aqui\n");

	if(i > mid){
		copyy(&auxiliar[k],&array[j],high - j + 1);
	} else {
		copyy(&auxiliar[k],&array[i],mid - i + 1);
	}

	copyy(&array[low], &auxiliar[low], high-low+1);

}

void mergeSortPercentKey(int low, int high){

	if(high > low){
		int mid = low+(high-low)/2;
		mergeSortPercentKey(low, mid);
		mergeSortPercentKey(mid+1, high);
		mergePercentKey(low, mid, high);
	}
}

void mergeSortCodeKey( int low, int high){

	if(high > low){
		int mid = low+(high-low)/2;
		mergeSortCodeKey(low, mid);
		mergeSortCodeKey(mid+1, high);
		mergeCodeKey(low, mid, high);
	}
}

float calculaPercent(int a, int b){
	float c = abs(b-a);
	float percent=0;
	percent = (100*c)/a;
	return percent;
}

int arredondamento1(float num){
    int num_int = num;
    if( (num - num_int) >= 0.5) return (num_int+1);
    else return num_int;
}

int main(int argc, char *argv[])
{
	printf("#ARGS = %i\n", argc);
	printf("PROGRAMA = %s\n", argv[0]);
	printf("ARG1 = %s, ARG2 = %s\n", argv[1], argv[2]);
    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");
	getData(input);
	removeSpace();
	printf("%d\n", value);
	putData(output);
	elementosArray();
	putData2(output);
	free(containers);
	free(amostra);
	free(aux);
	free(array);
	free(auxiliar);
	fclose(input);
	fclose(output);
	
    return 0;
}
