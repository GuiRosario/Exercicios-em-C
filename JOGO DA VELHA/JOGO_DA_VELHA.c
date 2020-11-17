#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "users.h"


char jdv[3][3];

//IMPRIME TABULEIRO
void imprimir_tabuleiro(int pX,int pO){
	system("clear");
	printf("---------------------------PLACAR--------------------------------\n");
	printf("Player X: %3i\n",pX);
	printf("Player O: %3i\n",pO);
	printf("-----------------------------------------------------------------\n");
	printf("%c|%c|%c\n",jdv[0][0],jdv[0][1],jdv[0][2]);
	printf("-----\n");
	printf("%c|%c|%c\n",jdv[1][0],jdv[1][1],jdv[1][2]);
	printf("-----\n");
	printf("%c|%c|%c\n",jdv[2][0],jdv[2][1],jdv[2][2]);
}

//LIMPA O BUFFER DO TECLADINHO 2000 OBS: MAS SO TIRA OS CARACTERES A MAIS E O PRIMEIRO ENTER
void limparbuffer(void){
	char b;
	do{
		b = getchar();
		//printf("'tirei %c do buffer'\n",b);
	}while(b != '\n' && b != EOF);
}

//VERIFICAR SE EXISTE VELHA NAS LINHAS
int verificar_velha_linha(int linha){
	int X = 0;
	int O = 0;

	for(int pos = 0;pos < 3;pos++){
		if(jdv[linha][pos] == 'X'){
			X++;
		}else if(jdv[linha][pos] == 'O'){
			O++;
		}
	}

	if(X >= 1 && O >= 1){
		return 1;
	}else{
		return 0;
	}
}

//VERIFICAR SE EXISTE VELHA NAS COLUNAS
int verificar_velha_coluna(int coluna){
	int X = 0;
	int O = 0;

	for(int pos = 0;pos < 3;pos++){
		if(jdv[pos][coluna] == 'X'){
			X++;
		}else if(jdv[pos][coluna] == 'O'){
			O++;
		}
	}

	if(X >= 1 && O >= 1){
		return 1;
	}else{
		return 0;
	}
}

//VERIFICAR SE EXISTE VELHA NAS DIAGONAIS 
int verificar_velha_diagonal(int diagonal){
	int X = 0;
	int O = 0;

	if(diagonal == 0){
		for(int pos = 0;pos < 3;pos++){	
			if(jdv[pos][pos] == 'X'){
				X++;
			}else if(jdv[pos][pos] == 'O'){
				O++;
			}
		}			
	}else{
		for(int pos = 0;pos < 3;pos++){			
			if(jdv[pos][2-pos] == 'X'){
				X++;
			}else if(jdv[pos][2-pos] == 'O'){
				O++;
			}
		}				
	}

	if(X >= 1 && O >= 1){
		return 1;
	}else{
		return 0;
	}
}

//VERIFICA SE O JOGO DEU VELHA
int verificar_velha(){
	for(int pos=0; pos<3 ; pos++){
		if(verificar_velha_linha(pos) == 0){
			return 0;
		}
		if(verificar_velha_coluna(pos) == 0){
			return 0;
		}
		if(pos < 2){
			if(verificar_velha_diagonal(pos) == 0){
				return 0;
			}
		}
	}

	return 1;
}

//RETORNA O NUMERO DE JOGADAS DO PLAYER NAQUELA LINHA
int verificacao_linha(int linha, char player){
	int num = 0;
	for (int column=0; column<3; column++){
		if(jdv[linha][column] == player){
			num++;
		}
	}
	return num;
}

//RETORNA O NUMERO DE JOGADAS DO PLAYER NAQUELA COLUNA
int verificacao_coluna(int coluna, char player){
	int num = 0;
	for (int line=0; line<3; line++){
		if(jdv[line][coluna] == player){
			num++;
		}
	}
	return num;
}

//RETORNA O NUMERO DE JOGADAS DO PLAYER NAQUELA DIAGONAL
int verificacao_diagonal(int diagonal, char player){
	int num = 0;
	if(diagonal == 0){
		for (int pos=0; pos<3; pos++){
			if(jdv[pos][pos] == player){
				num++;
			}
		}
	}else{
		int finallineposition = 3-1; //Marca a última de uma posição de uma linha do tabuleiro [x|x|0] => posição 2 
		for (int pos=0; pos<3; pos++){
			if(jdv[pos][finallineposition-pos] == player){
				num++;
			}
		}
	}
	return num;
}

//VERIFICA SE O PLAYER JA GANHOU NAQUELA LINHA
int winn_linha(int linha, char player){
	if(verificacao_linha(linha, player) > 2){
		return 1;
	}else{
		return 0;
	}
}

//VERIFICA SE O PLAYER JA GANHOU NAQUELA COLUNA
int winn_coluna(int coluna, char player){
	if(verificacao_coluna(coluna, player) > 2){
		return 1;
	}else{
		return 0;
	}
}

//VERIFICA SE O PLAYER JA GANHOU NAQUELA DIAGONAL
int winn_diagonal(int diagonal, char player){
	if(verificacao_diagonal(diagonal, player) > 2){
		return 1;
	}else{
		return 0;
	}
}

//VERIFICA SE O PLAYER VENCEU
int player_winn(char player){
	for(int pos=0; pos<3 ; pos++){
		if(winn_linha(pos, player)){
			return 1;
		}
		if(winn_coluna(pos, player)){
			return 1;
		}
		if(pos < 2){
			if(winn_diagonal(pos, player)){
				return 1;
			}
		}
	}
	return 0;
}

//RETORNA A COLUNA BASEADO NA POSIÇÂO
int get_coluna(int Posi){
	int linha;
	int coluna;

	linha = Posi/3;

	coluna = Posi - ((linha - 1) * 3);   

	return coluna - 1; 
}

//RETORNA A LINHA BASEADO NA POSIÇÂO
int get_linha(int Posi){
	int linha;

	linha = Posi/3;

	return linha - 1;	
}

//ATUALIZA O TABULEIRO COM A NOVA JOGADA
void atualizar_tabuleiro(int Posi,char player){ jdv[get_linha(Posi)][get_coluna(Posi)] = player; }

//VERIFICASE OS VETORES DO TABULEIRO POSSUEM 2 X's OU 2 O's E RETORNA A COORDADENADA PARA PREENCHER VETOR
int IA_verificacao_principal(char player, int coordenadas[2]){
	for(int L = 0; L < 3; L++){
		if(verificacao_linha(L,player) == 2){
			for(int C = 0;C < 3;C++){
				if(jdv[L][C] == ' '){
					coordenadas[0] = L;
					coordenadas[1] = C;
					return 1;
				}
			}
		}
		if(verificacao_coluna(L,player) == 2){
			for(int C = 0;C < 3;C++){
				if(jdv[C][L] == ' '){
					coordenadas[0] = C;
					coordenadas[1] = L;
					return 1;
				}
			}	
		}
		if(L < 2){
			if(verificacao_diagonal(L,player) == 2){
				if(L == 0){
					for(int C = 0;C < 3;C++){
						if(jdv[C][C] == ' '){
							coordenadas[0] = C;
							coordenadas[1] = C;
							return 1;
						}
					}
				}else{
					for(int C = 0;C < 3;C++){
						if(jdv[C][2-C] == ' '){
							coordenadas[0] = C;
							coordenadas[1] = 2-C;
							return 1;
						}
					}
				}
			}	
		}
	}

	return 0;
}

//VERIFICA QUAL VETOR DO TABULEIRO POSSUEM O e NAO X E RETORNA COORDENADA PARA PREENCHER
int IA_verificacao_secundaria(int coordenadas[2]){
	for(int L = 0; L < 3; L++){
		if(verificacao_linha(L,'O') == 1 && verificacao_linha(L,'X') == 0){
			for(int C = 0;C < 3;C++){
				if(jdv[L][C] == ' '){
					coordenadas[0] = L;
					coordenadas[1] = C;
					return 1;
				}
			}
		}
		if(verificacao_coluna(L,'O') == 1 && verificacao_coluna(L,'X') == 0){
			for(int C = 0;C < 3;C++){
				if(jdv[C][L] == ' '){
					coordenadas[0] = C;
					coordenadas[1] = L;
					return 1;
				}
			}	
		}
		if(L < 2){
			if(verificacao_diagonal(L,'O') == 1 && verificacao_diagonal(L,'X') == 0){
				if(L == 0){
					for(int C = 0;C < 3;C++){
						if(jdv[C][C] == ' '){
							coordenadas[0] = C;
							coordenadas[1] = C;
							return 1;
						}
					}
				}else{
					for(int C = 0;C < 3;C++){
						if(jdv[C][2-C] == ' '){
							coordenadas[0] = C;
							coordenadas[1] = 2-C;
							return 1;
						}
					}
				}
			}	
		}
	}
	return 0;
}	
int IA_verificacao_cantos(int coordenadas[2]){
	if(jdv[0][0] != ' ' || jdv[0][2] != ' ' || jdv[2][0] != ' ' || jdv[2][2] != ' '){
		return 1;
	}else{
		return 0;
	}
}
int IA_verificacao_meio(int coordenadas[2]){
	if(jdv[1][1] != ' '){
		return 1;
	}else{
		return 0;
	}
}
int IA_verificacao_jogada_unica(int coordenadas[2]){
	if(jdv[0][0] == 'X' && jdv[1][1] == 'O' && jdv[2][2] == 'X'){
		return 1;
	}else if(jdv[0][2] == 'X' && jdv[1][1] == 'O' && jdv[2][0] == 'X'){
		return 1;
	}else{
		return 0;
	}
}
//RETORNA COORDENADA ONDE A IA DESEJA JOGAR
void IA(int coordenadas[2],int dificuldade,char qcomeca,int rodada){
	if(dificuldade == 1){
		for(int L = 0;L<3;L++){
			for(int C = 0;C<3;C++){
				if(jdv[L][C] == ' '){
					coordenadas[0] = L;
					coordenadas[1] = C;
					return;				
				}
			}
		}		
	}else if(dificuldade == 2){
		//PRIMEIRO PASSO
		if(IA_verificacao_principal('O', coordenadas)){
			return;
		}
		//SEGUNDO PASSO
		if(IA_verificacao_principal('X', coordenadas)){
			return;
		}
		//TERCEIRO PASSO
		if(IA_verificacao_secundaria(coordenadas)){
			return;
		}
		//QUARTO PASSO
		for(int L = 0;L<3;L++){
			for(int C = 0;C<3;C++){
				if(jdv[L][C] == ' '){
					coordenadas[0] = L;
					coordenadas[1] = C;
					return;				
				}
			}
		}
	}else{
		if(IA_verificacao_principal('O', coordenadas)){
			return;
		}
		//SEGUNDO PASSO
		if(IA_verificacao_principal('X', coordenadas)){
			return;
		}
		//TERCEIRO PASSO
				if(qcomeca == 'S'){
			if(rodada == 1){
				if(IA_verificacao_cantos(coordenadas) == 1){
					coordenadas[0] = 1;
					coordenadas[1] = 1;
					return;
				}
	
				if(IA_verificacao_meio(coordenadas) == 1){
					coordenadas[0] = 0;
					coordenadas[1] = 0;
					return;
				}	
			}
			else if(rodada == 3){
				if(IA_verificacao_jogada_unica(coordenadas) == 1){
					coordenadas[0] = 1;
					coordenadas[1] = 0;
					return;
				}
			}
		}else{
			if(rodada == 0){
				coordenadas[0] = 0;
				coordenadas[1] = 0;
			}
			if(rodada == 2){
				
			}
		}

		//QUARTO PASSO
		if(IA_verificacao_secundaria(coordenadas)){
			return;
		}
		//QUINTO PASSO
		for(int L = 0;L<3;L++){
			for(int C = 0;C<3;C++){
				if(jdv[L][C] == ' '){
					coordenadas[0] = L;
					coordenadas[1] = C;
					return;				
				}
			}
		}				
	}
}

// CONTROLA A JOGADA DO COMPUTADOR
void PC(int dificuldade,char qcomeca,int rodada){
	system("clear");
	int posicao_PC;
	int coordenadas[2];
	IA(coordenadas, dificuldade,qcomeca,rodada);
	jdv[coordenadas[0]][coordenadas[1]] = 'O';
	posicao_PC = (coordenadas[0])*3 + (coordenadas[1]+1);
	printf("O COMPUTADOR JOGOU NA POSICAO %i\n",posicao_PC);
	printf("-ENTER PARA CONTINUAR-");
	getchar();
	return;
}

//FUNÇÂO PARA TROCAR DE TRUNO ENTRE JOGADORES
void trocar_turno(char* current_player){
	if(*current_player == 'X'){
		*current_player = 'O';
	}else{
		*current_player = 'X';
	}
	printf("-ENTER PARA CONTINUAR PARA O TURNO DO PLAYER %c-",*current_player);
	getchar();
}

//FUNÇÂO QUE PEGA A JOGADA DO JOGADOR
void jogar(char player){
	int Posi;
	int entrada_invalida;
	do{
		printf("Jogador %c - Digite a Posição: ",player);
		scanf("%i",&Posi);
		limparbuffer();
		entrada_invalida = 0;
		if(jdv[get_linha(Posi)][get_coluna(Posi)] != ' '){
			printf("Posicao Invalida!\n");
			entrada_invalida = 1;
		}
	}while(entrada_invalida);
	atualizar_tabuleiro(Posi, player);
}

void adicionar_historico(int vitorias,int derrotas){
	char name[100];	
	int corad;
	int contador;
	int tamanho = 0;
	Usuario **perfil = start_lista();

	perfil = ler_arquivo("nomes.txt");

	contador = (imprimir_lista(perfil)+1);

	do{
		system("clear");
		if(corad > contador){
			printf("OPCAO INVALIDA!DIGITE NOVAMENTE!\n");
			getchar();
		}
		system("clear");		
		printf("Selecione Um dos Perfis: \n");
		imprimir_lista(perfil);
		printf("|(%3i) Criar um Novo Perfil                                        |\n",contador);
		scanf("%i",&corad);

		limparbuffer();		
	}while(corad > contador);

	if(corad == contador){
		system("clear");
		do{
			system("clear");
			if(tamanho > 10){
				printf("DIGITE NOVAMENTE!O NOME POSSUI MAIS DE 10 CARACTERES!\n");
				getchar();
			}
			printf("Digite o nome do perfil que deseja criar: (MAXIMO DE 10 CARACTERES)\n");
			scanf("%s",name);
			limparbuffer();
			tamanho = strlen(name);			
		}while(tamanho >= 10);
		add_usuario(perfil,name,vitorias,derrotas);
		imprimir_lista(perfil);
		imprimir_arquivo(perfil,"nomes.txt");
	}else{
		Usuario *pesquisa;
		pesquisa = contar_usuario(perfil,corad);
		editar_usuario(pesquisa,pesquisa->nome,vitorias,derrotas);
		imprimir_arquivo(perfil,"nomes.txt");
		imprimir_usuario(pesquisa,0);
		getchar();
	}
}
void continuar_jogando(int *continuar,int vitoria,int derrota){
	char soun;
	system("clear");
	printf("Gostaria de Continuar Jogando?(S ou N)\n");
	scanf(" %c",&soun);
	limparbuffer();
	if(soun == 'S'){
	}else{
		adicionar_historico(vitoria,derrota);
		*continuar = 0;
	}
}

//MODO DE COMPUTADOR VS JOGADOR
void P1VSCPU(int dificuldade){
	int *pont;
	int partida = 1;
	int continuar = 1;
	char player;
	int Posi;
	char qcomeca; 
	int vitoria = 0;
	int derrota = 0;
	int rodada = 0;
	pont = &partida;

	while(partida){
	rodada = 0;
	for(int L = 0;L<3;L++){
		for(int C = 0;C<3;C++){
			jdv[L][C] = ' ';
		}
	}	
		system("clear");
		printf("VOCE E O JOGADOR X\n");
		printf("VOCE QUER COMECAR JOGANDO?(S OU N)\n");
		scanf("%c",&qcomeca);
		limparbuffer();

		if(qcomeca == 'S'){
			player = 'X';
		}else{
			player = 'O';
		}

		imprimir_tabuleiro(vitoria,derrota);

		if(player == 'X'){
			jogar(player);		
		}else{
			PC(dificuldade,qcomeca,rodada);
		}

		imprimir_tabuleiro(vitoria,derrota);

		while(continuar){
		rodada++;
			trocar_turno(&player);
			imprimir_tabuleiro(vitoria,derrota);
			if(player == 'X'){
				jogar(player);		
			}else{
				PC(dificuldade,qcomeca,rodada);
			}
			imprimir_tabuleiro(vitoria,derrota);
			if(player_winn('X')){
				vitoria++;
				system("clear");
				imprimir_tabuleiro(vitoria,derrota);
				printf("\nVOCE VENCEU!\n");
				getchar();
				continuar_jogando(pont,vitoria,derrota);
				break;
			}else if(player_winn('O')){
				derrota++;
				system("clear");
				imprimir_tabuleiro(vitoria,derrota);
				printf("\nVOCE PERDEU!\n");
				getchar();
				continuar_jogando(pont,vitoria,derrota);
				break;			
			}else if(verificar_velha()){
				system("clear");
				imprimir_tabuleiro(vitoria,derrota);
				printf("\nDEU VELHA!\n-");
				getchar();
				continuar_jogando(pont,vitoria,derrota);
				break;						
			}
		}	
	}
}

void multiplayer(){
	char soun;
	int vitoria = 0;
	int derrota = 0;
	int continuar = 1;
	char player;
	int Posi;
	char qcomeca; 
	int rodada = 1;
	while(rodada){
	continuar = 1;
		for(int L = 0;L<3;L++){
			for(int C = 0;C<3;C++){
				jdv[L][C] = ' ';
			}
		}		
		system("clear");
		printf("QUEM JOGA PRIMEIRO?(X OU O)\n");
		scanf("%c",&qcomeca);
		limparbuffer();

		if(qcomeca == 'X'){
			player = 'X';
		}else{
			player = 'O';
		}

		imprimir_tabuleiro(vitoria,derrota);

		jogar(player);		

		imprimir_tabuleiro(vitoria,derrota);

		while(continuar){
			trocar_turno(&player);
			imprimir_tabuleiro(vitoria,derrota);

			jogar(player);		
		
			imprimir_tabuleiro(vitoria,derrota);
			if(player_winn('X')){
				vitoria++;
				system("clear");
				imprimir_tabuleiro(vitoria,derrota);
				printf("\nJOGADOR X VENCEU!!\n");
				getchar();
				printf("Quer Continuar Jogando?");
				scanf(" %c",&soun);
				limparbuffer();
				if(soun == 'S'){
					continuar = 0;		
				}else{
					continuar = 0;
					rodada = 0;
				}
			}else if(player_winn('O')){
				derrota++;
				system("clear");
				imprimir_tabuleiro(vitoria,derrota);
				printf("\nJOGADOR O VENCEU!!\n");
				getchar();		
				printf("Quer Continuar Jogando?");
				scanf(" %c",&soun);
				limparbuffer();
				if(soun == 'S'){
					continuar = 0;		
				}else{
					continuar = 0;
					rodada = 0;
				}				
			}else if(verificar_velha()){
				system("clear");
				imprimir_tabuleiro(vitoria,derrota);
				printf("\nDEU VELHA!\n-");
				getchar();
				printf("Quer Continuar Jogando?");
				scanf(" %c",&soun);
				limparbuffer();
				if(soun == 'S'){
					continuar = 0;		
				}else{
					continuar = 0;
					rodada = 0;
				}		
			}			
		}	
	}
}

void Historico(){
	char nome[100];
	int contador;
	int selec;
	Usuario *pesquisar;
	Usuario **Historico = start_lista();

	Historico = ler_arquivo("nomes.txt");	

	contador = imprimir_lista(Historico)+1;
	system("clear");
	printf("----------------------------HISTORICO-------------------------------\n");
	imprimir_lista(Historico);
	printf("|(%3i) Deletar Perfil                                              |\n",contador);
	printf("|(%3i) Editar Perfil                                               |\n",contador+1);
	printf("|(%3i) Voltar Para o Menu                                          |\n",contador+2);	
	scanf("%i",&selec);
	limparbuffer();
	if(selec == contador){
		system("clear");
		imprimir_lista(Historico);
		printf("Selecione um Perfil para Deletar\n");
		scanf("%i",&selec);
		limparbuffer();
		pesquisar = contar_usuario(Historico,selec);
		deletar_usuario(Historico,pesquisar->nome);
		system("clear");
		imprimir_lista(Historico);
		imprimir_arquivo(Historico,"nomes.txt");
		getchar();
	}else if(selec == contador + 1){
		system("clear");
		imprimir_lista(Historico);
		printf("Selecione um Perfil para Editar\n");
		scanf("%i",&selec);
		limparbuffer();
		pesquisar = contar_usuario(Historico,selec);
		printf("Digite o Novo Nome que deseja: ");
		scanf("%s",nome);
		limparbuffer();
		editar_usuario(pesquisar,nome,0,0);		
		imprimir_lista(Historico);
		imprimir_arquivo(Historico,"nomes.txt");
	}else if(selec == contador + 2){
		return;
	}
	getchar();
}

//MENU PRINCIPAL
void menu_principal(void){
	int selec;
	while(1){
		for(int L = 0;L<3;L++){
			for(int C = 0;C<3;C++){
				jdv[L][C] = ' ';
			}
		}

		system("clear");
		printf(" ___________________________________________________________\n");
		printf("|                     |JOGO DA VELHA|                       |\n");
		printf("|                                                           |\n");
		printf("|Escolha uma das opcoes:                                    |\n");
		printf("|(1) P1 VS CPU.                                             |\n");
		printf("|(2) P1 vs P2.                                              |\n");
		printf("|(3) Historico.                                             |\n");
		printf("|(4) Sair do Jogo.                                          |\n");
		printf("|-----------------------------------------------------------|\n");
		scanf("%i",&selec);
		limparbuffer();
		system("clear");
		switch(selec){
			case 1:
				system("clear");
				printf(" ___________________________________________________________\n");
				printf("|                     |JOGO DA VELHA|                       |\n");
				printf("|                                                           |\n");
				printf("|Escolha uma Dificuldade:                                   |\n");
				printf("|(1) Facil.                                                 |\n");
				printf("|(2) Medio.                                                 |\n");
				printf("|(3) Dificil.                                               |\n");
				printf("|-----------------------------------------------------------|\n");
				scanf("%i",&selec);			
				limparbuffer();	
				P1VSCPU(selec);
				break;
			case 2:
				multiplayer();
				break;
			case 3:
				Historico();
				break;
			case 4:
				exit(0);
				break;												
		}
	}
}

//MAIN
void main(void){
	menu_principal();
}

