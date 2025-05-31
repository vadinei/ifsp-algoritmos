#include <stdio.h>

int main(void)
{
	int historicoFamiliarPressaoAlta = -1;
	int sobrePeso = -1;
	int sedentario = -1;
	int consumeAlcoolCigarro = -1; 
	int estresse = -1; 
    int idadeAvancada = -1; 
	int alimentacaoRuim = -1;
    int riscoTotal = 0;

	// Fonte: https://omronbrasil.com/fatores-de-risco-hipertensao
    printf("================================================================\n");
    printf("::: HyperRisk - Avaliador de Fatores de Risco de Hipertensao :::\n");
    printf("================================================================\n\n");
    
	printf(">> Responda com 1 (Sim) ou 0 (Nao) as 5 perguntas abaixo:\n\n");

    printf("1. Possui alguem na familia com historico de pressao alta? ");
    scanf("%d", &historicoFamiliarPressaoAlta);

    printf("2. Esta acima do peso ideal (sobrepeso)? ");
    scanf("%d", &sobrePeso);

    printf("3. Considera-se uma pessoa sedentária? ");
    scanf("%d", &sedentario);

    printf("4. Consome alcool e/ou cigarro? ");
    scanf("%d", &consumeAlcoolCigarro);

    printf("5. Possui uma rotina estressante em sua vida? ");
    scanf("%d", &estresse);
    
    printf("6. Possui idade avancada (mais de 55 anos)? ");
    scanf("%d", &idadeAvancada);

    printf("7. Costuma comer alimentos muito salgados ou frituras, por exemplo? ");
    scanf("%d", &alimentacaoRuim);

	if (historicoFamiliarPressaoAlta != 0 && historicoFamiliarPressaoAlta != 1) {
		printf("\nResposta invalida para pergunta: [1. Possui alguem na familia com historico de pressao alta?]\n");
		printf("Resposta informada: %d\n", historicoFamiliarPressaoAlta);
	} else if (sobrePeso != 0 && sobrePeso != 1) {
		printf("\nResposta invalida para pergunta: [2. Esta acima do peso ideal (sobrepeso)?]\n");
		printf("Resposta informada: %d\n", sobrePeso);
	} else if (sedentario != 0 && sedentario != 1) {
		printf("\nResposta invalida para pergunta: [3. Considera-se uma pessoa sedentária?]\n");
		printf("Resposta informada: %d\n", sedentario);
	} else if (consumeAlcoolCigarro != 0 && consumeAlcoolCigarro != 1) {
		printf("\nResposta invalida para pergunta: [4. Consome alcool e/ou cigarro?]\n");
		printf("Resposta informada: %d\n", consumeAlcoolCigarro);
	} else if (estresse != 0 && estresse != 1) {
		printf("\nResposta invalida para pergunta: [5. Possui uma rotina estressante em sua vida?]\n");
		printf("Resposta informada: %d\n", estresse);
	} else if (idadeAvancada != 0 && idadeAvancada != 1) {
		printf("\nResposta invalida para pergunta: [6. Possui idade avancada (mais de 55 anos)?]\n");
		printf("Resposta informada: %d\n", idadeAvancada);
	} else if (alimentacaoRuim != 0 && alimentacaoRuim != 1) {
		printf("\nResposta invalida para pergunta: [7. Costuma comer alimentos muito salgados ou frituras, por exemplo?]\n");
		printf("Resposta informada: %d\n", alimentacaoRuim);
	} else {
		
		riscoTotal = idadeAvancada + historicoFamiliarPressaoAlta + sobrePeso + sedentario + alimentacaoRuim;

	    printf("\n=================");
	    printf("\n::: RESULTADO :::");
	    printf("\n=================\n");
	
	    if (riscoTotal >= 4) {
	        printf("ALTO RISCO. Cuidado para nao desenvolver ou agravar a hipertensao!\n");
	        printf("Recomendacoes: procure uma unidade de saude, mude seus habitos e monitore sua pressao arterial.\n");
	    } else if (riscoTotal >= 2) {
	        printf("RISCO MODERADO. Atencao!\n");
	        printf("Recomendacoes: pratique exercicios, nao consuma bedidas e/ou cigarros, melhore sua rotina, alimentacao e faca avaliacao regularmente.\n");
	    } else {
	        printf("BAIXO RISCO. Parabens! Continue com bons habitos!\n");
	        printf("Recomendacoes: mantenha uma rotina saudavel e previna doencas.\n");
	    }
	    
	}

    return(0);
}