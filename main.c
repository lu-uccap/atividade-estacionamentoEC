/*
 * Sistema de Gerenciamento de Estacionamento Rotativo
 * Disciplina: Laboratório de Programação – UFMA
 * Prof. Rondineli Seba Salomão
 * Aluno: Pedro Lucca Dantas
 */

#include <stdio.h>
#include <string.h>   /* comparar textos */
#include <stdlib.h>   /* converter texto em numero */

int main() {

    /* ======================================================
     * DECLARACAO DAS VARIAVEIS
     * ====================================================== */
    char  placa[10];         /* Placa do veiculo */
    char  tipoVeiculo[20];   /* O que o usuario digitou (texto livre) */
    int   tipoNum;           /* Tipo convertido para numero (1, 2, 3) */
    float horas;             /* Tempo de permanencia */

    float tarifaPorHora;     /* Tarifa base de acordo com o tipo */
    float valorBase;         /* Valor antes de descontos/multas */
    float desconto;          /* Valor do desconto (se aplicavel) */
    float multa;             /* Valor da multa  (se aplicavel) */
    float valorFinal;        /* Valor total a ser cobrado */

    char  tipoTexto[20];     /* Nome do tipo de veiculo para o recibo */

    /* ======================================================
     * ENTRADA DE DADOS
     * ====================================================== */
    printf("============================================\n");
    printf("   SISTEMA DE ESTACIONAMENTO ROTATIVO\n");
    printf("============================================\n\n");

    printf("Digite a placa do veiculo: ");
    scanf("%s", placa);

    printf("\nSelecione o tipo do veiculo:\n");
    printf("  1- Carro        (R$ 5,00/h)\n");
    printf("  2- moto         (R$ 3,00/h)\n");
    printf("  3- Caminhonete  (R$ 8,00/h)\n");
    printf("Opcao: ");
    scanf("%s", tipoVeiculo);

    printf("Tempo de permanencia: ");
    scanf("%f", &horas);

    /* ======================================================
     * CONVERSÃO DA ENTRADA – TEXTO PARA NUMERO (atoi/strcmp/if/else)
     * para que o switch-case funcione normalmente logo abaixo.
     * ====================================================== */

    tipoNum = atoi(tipoVeiculo);

    /* Se atoi retornou 0, o usuario digitou por extenso      */
    if (tipoNum == 0) {
        if (strcmp(tipoVeiculo, "carro")       == 0 ||
            strcmp(tipoVeiculo, "Carro")       == 0 ||
            strcmp(tipoVeiculo, "CARRO")       == 0) {
            tipoNum = 1;

        } else if (strcmp(tipoVeiculo, "moto")  == 0 ||
                   strcmp(tipoVeiculo, "Moto")  == 0 ||
                   strcmp(tipoVeiculo, "MOTO")  == 0) {
            tipoNum = 2;

        } else if (strcmp(tipoVeiculo, "caminhonete") == 0 ||
                   strcmp(tipoVeiculo, "Caminhonete") == 0 ||
                   strcmp(tipoVeiculo, "CAMINHONETE") == 0) {
            tipoNum = 3;

        } else {
            printf("\nTipo de veiculo invalido! Encerrando...\n");
            return 1;
        }
    }

    /* ======================================================
     * PROCESSAMENTO – TIPO DE VEICULO (switch-case)
     * ====================================================== */
    switch (tipoNum) {
        case 1:
            tarifaPorHora = 5.0;
            sprintf(tipoTexto, "Carro");
            break;
        case 2:
            tarifaPorHora = 3.0;
            sprintf(tipoTexto, "Moto");
            break;
        case 3:
            tarifaPorHora = 8.0;
            sprintf(tipoTexto, "Caminhonete");
            break;
        default:
            printf("\nTipo de veiculo invalido! Encerrando...\n");
            return 1;
    }

    /* ======================================================
     * PROCESSAMENTO – CALCULO DO VALOR BASE
     * ====================================================== */
    if (horas < 1.0) {
        valorBase = tarifaPorHora;
    } else {
        valorBase = tarifaPorHora * horas;
    }

    /* ======================================================
     * PROCESSAMENTO – DESCONTO E MULTA (if/else)
     * Acima de 5h  -> desconto de 10%
     * Acima de 10h -> multa de R$ 20,00
     * ====================================================== */
    desconto = 0.0;
    multa    = 0.0;

if (horas > 10.0) {
    multa    = 20.0;               /* multa adicional */
} else if (horas > 5.0) {
    desconto = valorBase * 0.10;   /* apenas desconto de 10% */
}

valorFinal = valorBase - desconto + multa;

    valorFinal = valorBase - desconto + multa;

    /* ======================================================
     * SAIDA – RECIBO
     * ====================================================== */
    printf("\n============================================\n");
    printf("               RECIBO\n");
    printf("============================================\n");
    printf("Placa            : %s\n",     placa);
    printf("Tipo de veiculo  : %s\n",     tipoTexto);
    printf("Tempo            : %.2f \n", horas);
    printf("--------------------------------------------\n");
    printf("Valor base       : R$ %.2f\n", valorBase);

    if (desconto > 0.0) {
        printf("Desconto (10%%)   : R$ -%.2f\n", desconto);
    } else {
        printf("Desconto         : R$ 0.00\n");
    }

    if (multa > 0.0) {
        printf("Multa (>10h)     : R$ +%.2f\n", multa);
    } else {
        printf("Multa            : R$ 0.00\n");
    }

    printf("--------------------------------------------\n");
    printf("VALOR FINAL      : R$ %.2f\n", valorFinal);
    printf("============================================\n");

    return 0;
}