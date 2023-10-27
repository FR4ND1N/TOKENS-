#include <stdio.h>

int main() {
    // Variáveis
    int totalVisitantes = 0;
    int totalGostaram = 0;
    int totalNaoGostaram = 0;
    int totalRecomendaria = 0;
    int totalProbabilidadeRevisita = 0;
    int totalEnvolvimento = 0;
    
    //titulo 
    	
	
	printf("\t===============================================\n");
		
		printf("\t===============================================\n");
		
		printf("\t======Evolucao da Tecnologia contemporanea=====\n");
	
		printf("\t===============================================\n");
		
		printf("\t===============================================\n\n");
		
		printf("\t-----------------------------------------------\n");
		
		printf("\t----------------------------------------------\n");


    // Loop para coletar respostas de vários visitantes
    while (1) {
        printf("===== Respostas do Visitante %d =====\n", totalVisitantes + 1);

        // Pergunta 1
         	printf("---------------------------------------------------\n");
        printf("voce gostou da Exposicao? (1: SIM, 2: NAO):   \n");
        int gostouExposicao;
        scanf("%d", &gostouExposicao);

        // Verificar se o visitante gostou da exposição
        if (gostouExposicao == 1) {
            totalGostaram++;
        } else if (gostouExposicao == 2) {
            totalNaoGostaram++;
        }

        // Pergunta 2
         	printf("---------------------------------------------------\n");
        printf("voce planeja recomendar esta Exposicao a amigos ou familiares? (1: SIM, 2: NAO): \n");
        int recomendariaExposicao;
        scanf("%d", &recomendariaExposicao);

        // Verificar se o visitante recomendaria a exposição
        if (recomendariaExposicao == 1) {
            totalRecomendaria++;
        }

        // Pergunta 3
         	printf("---------------------------------------------------\n");
        printf("Em uma escala de 0 a 5, quao envolvente voce considera a Exposicao? (0 a 5): \n");
        int envolvimentoExposicao;
        scanf("%d", &envolvimentoExposicao);

        // Pergunta 4
         	printf("---------------------------------------------------\n");
        printf("Em uma escala de 0 a 5, quao provavel voce esta de visitar novamente este museu para ver outras exposicoes? (0 a 5): \n");
        int probabilidadeRevisita;
        scanf("%d", &probabilidadeRevisita);

        totalVisitantes++;

        // Somar as respostas para envolvimento e probabilidade de revisita
        totalEnvolvimento += envolvimentoExposicao;
        totalProbabilidadeRevisita += probabilidadeRevisita;

        // Mensagem de agradecimento para o visitante 
		printf("\t===================================================\n");
		printf("\t===================================================\n");
        printf("\t--------Obrigado pela visita, volte sempre---------\n");
        printf("\t===================================================\n");
        printf("\t===================================================\n");
        printf("\n");

        // Pergunta de encerramento
    printf("===================================================\n");
    printf("--Deseja coletar mais respostas? (1: SIM, 2: NAO)--\n");
    printf("===================================================\n");
        printf("\n");
        int continuar;
        scanf("%d", &continuar);
        if (continuar != 1) {
            break;
        }
    }

    // Gerar relatório
    printf("\t\t===== Relatorio Final =====\n");
      printf("=============================================================\n");
    printf("Total de Visitantes: %d\n", totalVisitantes);
      printf("=============================================================\n");
    printf("Total de Visitantes que Gostaram da Exposicao: %d\n", totalGostaram);
      printf("=============================================================\n");
    printf("Total de Visitantes que Nao Gostaram da Exposicao: %d\n", totalNaoGostaram);
      printf("=============================================================\n");
    printf("Total de Visitantes que Recomendariam a Exposicao: %d\n", totalRecomendaria);
      printf("=============================================================\n");

    return 0;
}