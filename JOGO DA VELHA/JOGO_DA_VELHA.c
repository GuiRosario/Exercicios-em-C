#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char jdv[3][3];

//IMPRIME TABULEIRO
void imprimir_tabuleiro(){
	system("clear");
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

//RETORNA COORDENADA ONDE A IA DESEJA JOGAR
void IA(int coordenadas[2]){
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
}

// CONTROLA A JOGADA DO COMPUTADOR
void PC(){
system("clear");
int posicao_PC;
int coordenadas[2];
IA(coordenadas);
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
	printf("-ESPAÇO PARA CONTINUAR PARA O TURNO DO PLAYER %c-",*current_player);
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

//MODO DE COMPUTADOR VS JOGADOR
void P1VSCPU(){
	int continuar = 1;
	char player;
	int Posi;
	char qcomeca; 

	printf("VOCE E O JOGADOR X\n");
	printf("VOCE QUER COMECAR JOGANDO?(S OU N)\n");
	scanf("%c",&qcomeca);
	limparbuffer();

	if(qcomeca == 'S'){
		player = 'X';
	}else{
		player = 'O';
	}

	imprimir_tabuleiro();

	if(player == 'X'){
		jogar(player);		
	}else{
		PC();
	}

	imprimir_tabuleiro();

	while(continuar){
		trocar_turno(&player);
		imprimir_tabuleiro();
		if(player == 'X'){
			jogar(player);		
		}else{
			PC();
		}
		imprimir_tabuleiro();
		if(player_winn('X')){
			system("clear");
			imprimir_tabuleiro();
			printf("\nVOCE VENCEU!\n-ENTER PARA FINALZAR-");
			getchar();
			continuar = 0;
		}else if(player_winn('O')){
			system("clear");
			imprimir_tabuleiro();
			printf("\nVOCE PERDEU!\n-ENTER PARA FINALZAR-");
			getchar();		
			continuar = 0;	
		}else if(verificar_velha()){
			system("clear");
			imprimir_tabuleiro();
			printf("\nDEU VELHA!\n-ENTER PARA FINALZAR-");
			getchar();		
			continuar = 0;	
		}			
	}


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
		printf("|                       |JOGO DA VELHA|                     |\n");
		printf("|                                                           |\n");
		printf("|Escolha uma das opcoes:                                    |\n");
		printf("|(1) P1 VS CPU.                                             |\n");
		printf("|(2) P1 vs P2.                                              |\n");
		printf("|(3) Pontuacao.                                             |\n");
		printf("|(4) Sair do Jogo.                                          |\n");
		printf("|-----------------------------------------------------------|\n");


		scanf("%i",&selec);
		limparbuffer();
		system("clear");

		switch(selec){
			case 1:
				P1VSCPU();
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				exit(0);
				break;												
		}

	}
}

//MAIN
void main(void){
	/*
	**TESTE DE LIMPEZA DO BUFFER
	scanf("%c");
	limparbuffer();
	scanf("%i");
	limparbuffer();
	getchar();
	scanf("%c");
	limparbuffer();
	getchar();
	*/
	menu_principal();
	return;
}

