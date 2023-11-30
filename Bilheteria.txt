#include <stdio.h>
#include <ctype.h>

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

    // Abre o arquivo para escrita
    FILE *arquivoCSV = fopen("relatoriovendas.csv", "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivoCSV == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1; // Saída com código de erro
    }

    // Adiciona cabeçalhos ao arquivo CSV
    fprintf(arquivoCSV, "Recibo,Horario,Quantidade,Inteira,Meia,Isencao,Total Arrecadado\n");

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
        horario = obterNumeroInteiro("Escolha o Horario", 1, 3);

        if (horario == 0) {
            break; // Sair do loop se o cliente desejar
        }

        // Solicitar ao cliente que insira a quantidade de ingressos
        printf("\n");
        printf("----------------------------------------------------\n");
        quantidade = obterNumeroInteiro("Quantos ingressos deseja comprar", 1, 100);

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
            tipoIngresso = obterNumeroInteiro("Escolha o tipo de ingresso", 1, 3);

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

        // Escrever no arquivo CSV
        fprintf(arquivoCSV, "Recibo%d,%d,%d,%d,%d,%d,%.2f\n", numeroRecibo++, horario, quantidade, ingressosInteira, ingressosMeia, ingressosIsencao, totalArrecadado);

        // Imprimir o comprovante de compra (recibo)
        printf("\n");
        printf("----------------------------------------------------\n");
        printf("\t==========================================\n");
        printf("\t===== Comprovante de Compra (Recibo) =====\n");
        printf("\t===Numero do Recibo: %d====================\n", numeroRecibo - 1);
        printf("\t===Horario: %s==========================\n", (horario == 1) ? horario1 : (horario == 2) ? horario2 : horario3);
        printf("\t===Quantidade de Ingressos: %d=============\n", quantidade);
        printf("\t===Valor Total: R$%.2f===================\n", valor);
        printf("\t==========================================\n");
        printf("\t======== Obrigado por sua compra! ========\n");
        printf("\t==========================================\n");

        // Pausa para o usuário visualizar o recibo
        printf("\nDigite 0 para sair ou qualquer outro numero para continuar: ");
        int opcaoSair;
        scanf("%d", &opcaoSair);
        if (opcaoSair == 0) {
            break; // Sair do loop se o usuário digitar 0
        }
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

    // Fechar o arquivo CSV
    fclose(arquivoCSV);

    // Imprimir mensagem indicando onde o relatório foi gravado
    printf("\nRelatorio de vendas do dia gravado em 'relatorio.csv'.\n");

    return 0;
}
