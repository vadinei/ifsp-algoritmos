#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

// Definição de Constantes
#define QUANTIDADE_PORTA 5

#define NIVEL_DIFICIL 1
#define NIVEL_INTERMEDIARIO 2
#define NIVEL_FACIL 3

#define TENTATIVAS_NIVEL_DIFICIL 1
#define TENTATIVAS_NIVEL_INTERMEDIARIO 3
#define TENTATIVAS_NIVEL_FACIL 5

#define SIM 1
#define NAO 0
#define CHAR_FLUSH_SCANF '\n'

// Referências:
// https://pt.wikipedia.org/wiki/S%C3%A9rgio_Mallandro
// https://noticiasdatv.uol.com.br/noticia/filmes-na-tv/diretor-abre-a-porta-dos-desesperados-para-contar-historia-de-sergio-mallandro-111888
// https://www.youtube.com/watch?v=zotSjxA0r0s
int main(void)
{
	// Declaração das Variáveis
	int nivel;
	int continuar;
	int portaPremio;
	int portaTentativa;
	int tentativas;
	
	do {
		// Limpa a tela do Console/Prompt do Windows
		system("cls");

		// Inicializando as variaveis
		nivel = -1;
		continuar = -1;
		portaPremio = -1;
		portaTentativa = -1;
		tentativas = -1;		

    	printf("=============================================================\n");
    	printf("::: PORTA DOS DESESPERADOS - Homenagem ao Sergio Malandro :::\n");
    	printf("=============================================================\n");

    	printf("\n");
    	printf("-------------------------------------------------------------\n");
    	printf("Diferente da versao original, que ha apenas 3 Portas... \n");
    	printf("Encontre a Porta do Premio, entre as %d Portas existentes\n", QUANTIDADE_PORTA);
    	printf("-------------------------------------------------------------\n");
	    printf("%d > Nivel Dificil (%d Tentativa);\n", NIVEL_DIFICIL, TENTATIVAS_NIVEL_DIFICIL);
	    printf("%d > Nivel Intermediario (%d Tentativas);\n", NIVEL_INTERMEDIARIO, TENTATIVAS_NIVEL_INTERMEDIARIO);
	    printf("%d > Nivel Facil (%d Tentativas).\n", NIVEL_FACIL, TENTATIVAS_NIVEL_FACIL);
    	printf("-------------------------------------------------------------\n");

		// Ontem o nivel de dificuldade
		do {
		    printf(">>> Informe o nivel de dificuldade (%d, %d ou %d): ", NIVEL_DIFICIL, NIVEL_INTERMEDIARIO, NIVEL_FACIL);
		    scanf("%d", &nivel);
			
			// Valida a entrada
			if (nivel != NIVEL_DIFICIL && nivel != NIVEL_INTERMEDIARIO && nivel != NIVEL_FACIL) {
				printf("*** Opcao invalida! Digite uma opcao valida.\n\n");
				// Limpa o buffer de entrada
				while (getchar() != CHAR_FLUSH_SCANF);
			}
		} while (nivel != NIVEL_DIFICIL && nivel != NIVEL_INTERMEDIARIO && nivel != NIVEL_FACIL);
		
		// Definindo o numero de tentativas
		switch(nivel){
			case NIVEL_DIFICIL:
				tentativas = TENTATIVAS_NIVEL_DIFICIL;
				break;
			case NIVEL_INTERMEDIARIO:
				tentativas = TENTATIVAS_NIVEL_INTERMEDIARIO;
				break;
			case NIVEL_FACIL:
				tentativas = TENTATIVAS_NIVEL_FACIL;
				break;
		}
		
		// Obtem, de maneira randomica, a Porta do Premio
		portaPremio = (rand()% QUANTIDADE_PORTA + 1);
		
		// Realiza a(s) tentantiva(s)
		for(int i = 1; i <= tentativas; i++) {
			
			// Ontem a porta para a tentativa
			do {
				printf("\n");
			    printf(">>> [Tentativa %d de %d]: Escolha uma das portas [1 a %d]: ", i, tentativas, QUANTIDADE_PORTA);
			    scanf("%d", &portaTentativa);
				
				// Valida a entrada
				if (portaTentativa < 1 || portaTentativa > QUANTIDADE_PORTA) {
					printf("*** Opcao invalida! Digite uma opcao valida.\n");
					// Limpa o buffer de entrada
					while (getchar() != CHAR_FLUSH_SCANF);
				}
			} while (portaTentativa < 1 || portaTentativa > QUANTIDADE_PORTA);
			
			// Verifica se o numero da porta da tentativa eh igual ao da porta do premio
			if (portaTentativa == portaPremio) {
				printf("\n");
				printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");				
				printf("$$$ 'GLU GLU IE IE': Parabens! Voce acertou a porta do premio\n");				
				printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
				break;
			} else {
				// Verifica se o numero da tentativa eh menor que o total de tentativas
				if (i < tentativas) {
					// Verifica se o numero da porta da tentativa e menor ou maior que o da porta do premio
					if (portaTentativa < portaPremio) {
						printf("*** [Dica do Malandro]: 'eu vejo uma porta maior...'\n");				
					} else {
						printf("*** [Dica do Malandro]: 'eu vejo uma porta menor...'\n");				
					}
				} else {
					printf("*** 'RAAAAA': tentativa(s) se esgotou(ram). Tente novamente!\n");									
				}
			}				
		}
		
		// Verifica se o usuário deseja continuar jogando
		do {
			printf("\n");
	    	printf("Deseja continuar jogando? %d (Sim) ou %d (Nao): ", SIM, NAO);
	    	scanf("%d", &continuar);
			// Valida a entrada
			if (continuar != SIM && continuar != NAO) {
				printf("*** Opcao invalida! Digite uma opcao valida.\n");
				// Limpa o buffer de entrada
				while (getchar() != CHAR_FLUSH_SCANF);
			}
		} while (continuar != SIM && continuar != NAO);
    	
	} while (continuar == SIM);

	// Mensagem de agradecimento e finaliza o programa/jogo.
	printf("\n");
   	printf("=============================================================\n");
	printf("::: Muito obrigado! Espero que voce tenha gostado do jogo :::\n");
   	printf("=============================================================\n");

    return(0);
}