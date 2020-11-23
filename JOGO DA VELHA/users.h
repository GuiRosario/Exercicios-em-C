#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct user{
	char nome[100];
	int vitorias;
	int derrotas;
	struct user *proximo;
} Usuario;

//SETA AS INFORMAÇÔES DO USUARIO (PRIVADA)
Usuario* set_usuario(char name[100],int vitorias,int derrotas){
	Usuario *lista;
	lista = malloc(sizeof(Usuario));
	strcpy(lista->nome, name);
	lista->vitorias = vitorias;
	lista->derrotas = derrotas;
	lista->proximo = NULL;
	return lista;
}

//RETORNA O PROXIMO USUARIO DA LISTA (PRIVADA)
Usuario* get_proximo(Usuario *usuario){return usuario->proximo;}

//PRINTA UM USUARIO ESPECIFICO
void imprimir_usuario(Usuario *usuario,int cont){
	printf("|(%3i) nome: %10s",cont,usuario->nome);
	printf("        vitorias: %4i",usuario->vitorias);
	printf("        derrotas: %4i|\n",usuario->derrotas);
	if(usuario->proximo == NULL){
		//printf("%s\n", "NULL");
	}else{
		//printf("próximo: %x\n",usuario->proximo);
	}
	return;
}

//IMPRIME A LISTA DE USUARIOS
int imprimir_lista(Usuario **usuario){
	Usuario *referencia;
	referencia = *usuario;
	int cont = 0;
	if((*usuario)->nome == NULL){
		return 0;
	}
	for(int i=0; i < 10; i++){
		cont++;
		imprimir_usuario(referencia,cont);
		referencia = get_proximo(referencia);
		if(referencia == NULL){
			break;
		}	
	}
	return cont;
}

//RETORNA O NUMERO DE USUARIOS ADICIONADOS
int tamanho_lista(Usuario *usuario){
	Usuario *referencia = usuario;
	int num = 0;
	do{
		referencia = get_proximo(referencia);
		num++;
	}while(referencia != NULL);
	return num;
}

Usuario** start_lista(){
	Usuario **lista = malloc(sizeof(Usuario));
	*lista = NULL;
	return lista;
}
//ADICIONA UM NOVO USUARIO
void add_usuario(Usuario **lista,char nome[100],int vitorias,int derrotas){
	//Achar último usuário da lista;
	//Adicionar novo usuario ao proximo do último item da LISTA

	if(*lista == NULL){
		*lista = set_usuario(nome,vitorias,derrotas);
		return;
	}

	Usuario *referencia = *lista;

	while(referencia->proximo != NULL){
		referencia = get_proximo(referencia);
	}

	referencia->proximo = set_usuario(nome,vitorias,derrotas);
}

//FUNÇÂO QUE PESQUISA UM USARIO NA LISAT APARTIR DE UM NOME PASSADO E RETORNA AQUELE USUARIO
Usuario* pesquisar_usuario(Usuario **lista,char nome[100]){
	int diferentes;	
	Usuario *item;
	item = *lista;
	while(item != NULL){
		diferentes = strcmp(nome,item->nome);		
		if(diferentes == 0){
			return item;
		}
		item = get_proximo(item);
	}
	return NULL;
}

//FUNÇÃO QUE DELETA UM USUARIO DA LISTA APARTIR DE UM NOME PASSADO E RETORNA SE FOI APAGADO OU N
int deletar_usuario(Usuario **lista,char nome[100]){

	Usuario *delete_item;
	int diferentes;
	Usuario *anterior;
	if(*lista == NULL){
		return 0;
	}else if(strcmp(nome,(*lista)->nome) == 0){
		delete_item = *lista;
		*lista = (*lista)->proximo;
		free(delete_item);
		return 1;
	}
	anterior = *lista;
	while(anterior->proximo != NULL){
		diferentes = strcmp(nome,anterior->proximo->nome);		
		if(diferentes == 0){
			delete_item = anterior->proximo;
			anterior->proximo = anterior->proximo->proximo;
			free(delete_item);
			return 1;
		}
		anterior = get_proximo(anterior);
	}

	return 0;
}

//FUNÇÂO QUE EDITA AS INFORMAÇÕES DE UM USUARIO DA LISTA
int editar_usuario(Usuario *usuario,char nome[100],int vitorias,int derrotas){
	if(usuario == NULL){
		return 0;
	}else{
		strcpy(usuario->nome,nome);
		usuario->vitorias += vitorias;
		usuario->derrotas += derrotas;
	}
}

//FUNÇÃO ONDE DADOS DE UM ARQUIVO SAO ADICIONADOS A UMA LISTA
Usuario** ler_arquivo(char nome_arquivo[100]){
	char frase[200];
	char nome[100];
	char fim;
	int vitorias;
	int derrotas;
	Usuario **lista = start_lista();
	FILE *arquivo;
	arquivo = fopen(nome_arquivo,"r");

	while(getc(arquivo) != EOF){
		fscanf(arquivo,"%s %i %i",nome,&vitorias,&derrotas);
		add_usuario(lista,nome,vitorias,derrotas);
		getc(arquivo);
	}

	fclose(arquivo);
	return lista;
}

//FUNÇÂO QUE IMPRIME AS INFORMAÇÕES DA LISTA E AS SALVA EM UM ARQUIVO
void imprimir_arquivo(Usuario **lista,char nome_arquivo[100]){	
	FILE *arquivo;
	arquivo = fopen(nome_arquivo,"w");	
	Usuario *item;
	item = *lista;

	while(item != NULL){
		fprintf(arquivo," %s %i %i\n",item->nome,item->vitorias,item->derrotas);
		item = (get_proximo(item));		
	}

	fclose(arquivo);

}

//FUNÇÃO QUE RETORNA UM USUARIO APARTIR DA SUA POSIÇÃO NA LISTA
Usuario* contar_usuario(Usuario **lista,int n){
	Usuario *item;
	item = *lista;
	int contador = 0;
	while(item != NULL){		
		contador++;
		if(n == contador){
			return item;
		}
		item = get_proximo(item);
		}
	return NULL;
}