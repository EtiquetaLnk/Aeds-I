#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct use{
	
	char CPF[14];
	char RG[9];
	char NOME[50];
	
}TUsuario;

typedef struct celula{
	
	TUsuario item;
	struct celula *prox;
}TCelula;

typedef struct fila{
	
	TCelula *frente;
	TCelula *tras;
	int tamanho;
}TFila;

void FFVazia(TFila *fila){
	
	fila->frente->prox=(TCelula*)malloc(sizeof(TCelula));
	fila->tras=fila->frente;
	fila->frente->prox = NULL;
	
}

void Desenfileirar(TFila *fila, TUsuario *item){
	
	TCelula *aux;
	
	if(fila->frente == fila->tras){
		printf("FILA VAZIA!");
	}
	
	aux = fila->frente->prox;
	*item = aux->item;
	fila->frente->prox = aux->prox;
	free(aux);
	if(fila->frente->prox == NULL){
		fila->tras=fila->frente;
		fila->tamanho--;
	}
	fila->tamanho--;
}

void Imprimir(TFila fila){
	
	TUsuario item;
	TFila faux;
	FFVazia(&faux);
	
	while(!Vazia(fila)){
		Desenfileirar(&fila, &item);
		ImprimirUsuario(item);
		Enfileirar(&faux, &item);
	}
	while(!Vazia(faux)){
		Desenfileirar(&faux, &item);
		Enfileirar(&fila, &item);
	}
	free(faux.frente);;
}

void Enfileirar(TFila *fila, TUsuario item){
	
	fila->tras->prox=(TCelula*)malloc(sizeof(TCelula));
	fila->tras=fila->tras->prox;
	fila->tras->item=item;
	fila->tras->prox=NULL;
	
}

int Verifica_igualdade(TFila fila1, TFila fila2){
	
	int i=1;
	TUsuario item1, item2;
	
	
	if(fila1.tamanho != fila2.tamanho){
		return 0;
	}
	while(i<=fila1.tamanho){
		
		Desenfileirar(&fila1, &item1);
		Desenfileirar(&fila2, &item2);
		if(strcmp(item1.CPF, item2.CPF)!=0){
			return 0;
		}
		Enfileirar(&fila1, item1);
		Enfileirar(&fila2, item2);
	}
	return 1;
}

TFila* Intercala(TFila fila1, TFila fila2, TFila *fila3){
	
	
	TUsuario item1, item2;
	int L, i=0, n=0, e=0;
	
	if(fila1.tamanho >= fila2.tamanho){
		L = fila1.tamanho;
	}
	else{
		L = fila2.tamanho;
	}
	
	do{
		
		if(n<fila1.tamanho){
			Desenfileirar(&fila1, &item1);
			Enfileirar(&fila3, item1);
			Enfileirar(&fila1, item);
			n++;	
		}
		if(e<fila2.tamanho){
			Desenfileirar(&fila2, &item2);
			Enfileirar(&fila3, item2);
			Enfileirar(&fila2, item2);
			e++;	
		}
		
		i++;
	}while(i<L);
	
	return fila3;
	
}

void Inverte(TFila *fila){
	
	TFila faux;
	TUsuario item;
	FFVazia(&faux);
	int i;
	
	while(faux.tamanho!=fila->tamanho){
		for(i=1; i<=fila.tamanho-1; i++){
			Desenfileirar(fila, &item);
			Enfileirar(fila, item)	
		}
		Enfileirar(&faux, fila->frente->prox->item);
	}
	
	while(!Vazia(fila)){
		Desenfileirar(fila, &item);
	}
	while(!Vazia(faux)){
		Desenfileirar(&faux, &item);
		Enfileirar(fila, item)
	}
