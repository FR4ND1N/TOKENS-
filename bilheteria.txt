#include <stdio.h>

int main() {
    // Horários disponíveis para sessões
    char horario1[] = "9:00";
    char horario2[] = "12:00";
    char horario3[] = "15:00";

    // Inicialização das variáveis para acompanhamento das vendas
    int totalIngressosVendidos1 = 0;
    int totalIngressosVendidos2 = 0;
    int totalIngressosVendidos3 = 0;
    int totalInteira1 = 0;
    int totalMeia1 = 0;
    int totalIsencao1 = 0;
    int totalInteira2 = 0;
    int totalMeia2 = 0;
    int totalIsencao2 = 0;
    int totalInteira3 = 0;
    int totalMeia3 = 0;
    int totalIsencao3 = 0;
    float totalArrecadado = 0.0;
	printf("\t===============================================\n");
	printf("\t===============================================\n");
	printf("\t===============================================\n");
    printf("\t=========Bem-vindo ao museu Bom Ponto!=========\n");
	printf("\t===============================================\n");
	printf("\t===============================================\n");
	printf("\t===============================================\n");
			
			
			
    // Variável para gerar números de recibo únicos
    int numeroRecibo = 1;

    // Loop principal para atender clientes
    while (1) {
        int horario, quantidade;
        float valor = 0.0;

        // Solicitar ao cliente que selecione o horário
        printf("\nHorarios disponiveis:\n");
        	printf("---------------------------------------------------\n");
        printf(" 1. %s\n2. %s\n3. %s\n", horario1, horario2, horario3);
        printf(" Escolha o Horario (1/2/3) ou digite '0' para sair: \n");
        printf("\n");
        
        
        scanf("%d", &horario);
      

        if (horario == 0) {
            break; // Sair do loop se o cliente desejar
        }

        // Verificar se o horário é válido
        if (horario != 1 && horario != 2 && horario != 3) {
            printf("Horario invalido. Tente novamente.\n");
            continue;
        }

        // Solicitar ao cliente que insira a quantidade de ingressos
        	printf("\n");
        	printf("----------------------------------------------------\n");
        printf("Quantos ingressos deseja comprar? \n");
        printf("\n");
        
        scanf("%d", &quantidade);

        // Verificar se a quantidade é válida
        if (quantidade <= 0) {
            printf("Quantidade invalida. Tente novamente.\n");
            continue;
        }

        // Inicializar variáveis para acompanhar os tipos de ingressos
        int ingressosInteira = 0;
        int ingressosMeia = 0;
        int ingressosIsencao = 0;

        // Solicitar ao cliente que selecione o tipo de ingresso para cada ingresso
        for (int i = 1; i <= quantidade; i++) {
            int tipoIngresso;
	printf("\n");
	printf("----------------------------------------------------\n");
            printf("Escolha o tipo de ingresso para o ingresso %d/%d:\n", i, quantidade);
            printf("1. Inteira (R$10)\n2. Meia (R$5)\n3. Isencao (gratuidade)\n");
            printf("Escolha o tipo de ingresso (1/2/3): \n");
            	printf("\n");

            scanf("%d", &tipoIngresso);

            // Verificar se o tipo de ingresso é válido
            if (tipoIngresso < 1 || tipoIngresso > 3) {
            		printf("\n");
                printf("Tipo de ingresso invalido. Tente novamente.\n");
                	printf("\n");
                i--; // Volta para a iteração anterior
                continue;
            }

            // Atualizar os contadores de tipos de ingressos
            if (tipoIngresso == 1) {
                ingressosInteira++;
                valor += 10.0;
            } else if (tipoIngresso == 2) {
                ingressosMeia++;
                valor += 5.0;
            } else {
                ingressosIsencao++;
            }
        }

        // Atualizar as estatísticas de vendas
        switch (horario) {
            case 1:
                totalIngressosVendidos1 += quantidade;
                totalInteira1 += ingressosInteira;
                totalMeia1 += ingressosMeia;
                totalIsencao1 += ingressosIsencao;
                break;
            case 2:
                totalIngressosVendidos2 += quantidade;
                totalInteira2 += ingressosInteira;
                totalMeia2 += ingressosMeia;
                totalIsencao2 += ingressosIsencao;
                break;
            case 3:
                totalIngressosVendidos3 += quantidade;
                totalInteira3 += ingressosInteira;
                totalMeia3 += ingressosMeia;
                totalIsencao3 += ingressosIsencao;
                break;
        }

        totalArrecadado += valor;

        // Imprimir o comprovante de compra (recibo)
        printf("\n");
      printf("----------------------------------------------------\n");
      	printf("\t==========================================\n");
        printf("\t===== Comprovante de Compra (Recibo) =====\n");
        printf("\t===Numero do Recibo: %d====================\n", numeroRecibo++);
        printf("\t===Horario: %s==========================\n", (horario == 1) ? horario1 : (horario == 2) ? horario2 : horario3);
        printf("\t===Quantidade de Ingressos: %d=============\n", quantidade);
      printf("\t===Valor Total: R$%.2f===================\n", valor);
      	printf("\t==========================================\n");
        printf("\t======== Obrigado por sua compra! ========\n");
      	printf("\t==========================================\n");
    }

    // Imprimir relatório de vendas do dia
    printf("\nRelatorio de vendas do dia:\n");
    printf("\nHorario %s - %d ingressos vendidos\n", horario1, totalIngressosVendidos1);
    printf("Ingressos Inteira: %d\n", totalInteira1);
    printf("Ingressos Meia: %d\n", totalMeia1);
    printf("Ingressos Isencao: %d\n", totalIsencao1);
    printf("\nHorario %s - %d ingressos vendidos\n", horario2, totalIngressosVendidos2);
    printf("Ingressos Inteira: %d\n", totalInteira2);
    printf("Ingressos Meia: %d\n", totalMeia2);
    printf("Ingressos Isencao: %d\n", totalIsencao2);
    printf("\nHorario %s - %d ingressos vendidos\n", horario3, totalIngressosVendidos3);
    printf("Ingressos Inteira: %d\n", totalInteira3);
    printf("Ingressos Meia: %d\n", totalMeia3);
    printf("Ingressos Isencao: %d\n", totalIsencao3);
    printf("\nTotal arrecadado: R$%.2f\n", totalArrecadado);

    return 0;
}