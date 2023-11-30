#include <stdio.h>
#include <ctype.h>

// Função para obter um número inteiro válido dentro de uma faixa
int obterNumeroInteiro(const char *mensagem, int min, int max) {
    int numero;
    char entrada[100];

    while (1) {
        printf("%s (%d-%d): ", mensagem, min, max);
        scanf("%s", entrada);

        // Verificar se a entrada contém apenas dígitos
        int valido = 1;
        for (int i = 0; entrada[i] != '\0'; i++) {
            if (!isdigit(entrada[i])) {
                valido = 0;
                break;
            }
        }

        if (!valido) {
            printf("Opcao invalida. Digite apenas numeros.\n");
            continue;
        }

        // Converter a entrada para um número inteiro
        sscanf(entrada, "%d", &numero);

        // Verificar se o número está dentro da faixa permitida
        if (numero < min || numero > max) {
            printf("Opcao invalida. Digite um numero entre %d e %d.\n", min, max);
        } else {
            break;
        }
    }

    return numero;
}

int main() {
    // Variáveis
    int totalVisitantes = 0;
    int totalGostaram = 0;
    int totalNaoGostaram = 0;
    int totalRecomendaria = 0;
    int totalProbabilidadeRevisita = 0;
    int totalEnvolvimento = 0;

    printf("\t\t\t\t\t================================================\n");
    printf("\t\t\t\t\t===============================================\n");
    printf("\t\t\t\t\t================= 150 Anos  ===================\n");
    printf("\t\t\t\t\t=====================De========================\n");
    printf("\t\t\t\t\t============== Santos Dumont =============\n");
    printf("\t\t\t\t\t===============================================\n");
    printf("\t\t\t\t\t===============================================\n\n");

    // Abre o arquivo para escrita
    FILE *arquivoCSV = fopen("relatorio_santosdumont.csv", "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivoCSV == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1; // Saída com código de erro
    }

    // Adiciona cabeçalhos ao arquivo CSV
    fprintf(arquivoCSV, "Visitante,Gostou,Recomendaria,Envolvimento,Probabilidade Revisita\n");

    // Loop principal para coletar respostas
    while (1) {
        printf("===== Respostas do Visitante %d =====\n", totalVisitantes + 1);

        // Pergunta 1
        printf("---------------------------------------------------\n");
        printf("Voce gostou da Exposicao? (1: SIM, 2: NAO): \n");
        int gostouExposicao = obterNumeroInteiro("", 1, 2);

        // Pergunta 2
        printf("---------------------------------------------------\n");
        printf("Voce planeja recomendar esta Exposicao a amigos ou familiares? (1: SIM, 2: NAO): \n");
        int recomendariaExposicao = obterNumeroInteiro("", 1, 2);

        // Pergunta 3
        printf("---------------------------------------------------\n");
        printf("Em uma escala de 0 a 5, quao envolvente voce considera a Exposicao? (0 a 5): \n");
        int envolvimentoExposicao = obterNumeroInteiro("", 0, 5);

        // Pergunta 4
        printf("---------------------------------------------------\n");
        printf("Em uma escala de 0 a 5, quao provavel voce esta de visitar novamente este museu para ver outras exposicoes? (0 a 5): \n");
        int probabilidadeRevisita = obterNumeroInteiro("", 0, 5);

        totalVisitantes++;

        // Salvar as respostas no arquivo CSV
        fprintf(arquivoCSV, "%d,%d,%d,%d,%d\n", totalVisitantes, gostouExposicao, recomendariaExposicao, envolvimentoExposicao, probabilidadeRevisita);

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
        int continuar = obterNumeroInteiro("", 1, 2);
        if (continuar != 1) {
            break;
        }
    }

    // Fechar o arquivo CSV
    fclose(arquivoCSV);

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

    // Imprimir mensagem indicando onde o relatório foi gravado
    printf("\nRelatorio de vendas do dia gravado em 'relatorio_santosdumont.csv'.\n");

    return 0;
}
