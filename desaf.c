
#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 50
#define NOME_TAM 60

int main(void) {
    
    char nomes[MAX_CLIENTES][NOME_TAM];
    float rendas[MAX_CLIENTES];
    float precos[MAX_CLIENTES];
    float parcelas[MAX_CLIENTES];
    int   status[MAX_CLIENTES];     

    int qtdClientes;
    int i;

    printf("=========================================\n");
    printf("   SISTEMA DE COMPRA DE CARROS\n");
    printf("=========================================\n\n");

     
    printf("Quantos clientes deseja cadastrar? ");
    scanf("%d", &qtdClientes);

    if (qtdClientes <= 0 || qtdClientes > MAX_CLIENTES) {
        printf("Quantidade invalida. Encerrando o programa.\n");
        return 1;
    }

    
    for (i = 0; i < qtdClientes; i++) {

        printf("\n--- Cadastro do cliente %d ---\n", i + 1);

       
        printf("Nome do cliente: ");
        scanf(" %[^\n]", nomes[i]);

        printf("Renda mensal do cliente (R$): ");
        scanf("%f", &rendas[i]);

        printf("Preco do carro desejado (R$): ");
        scanf("%f", &precos[i]);

        
        printf("\nDados lidos -> Nome: %s | Renda: R$ %.2f | Carro: R$ %.2f\n",
               nomes[i], rendas[i], precos[i]);

        
        parcelas[i] = precos[i] / 48.0f;

       
        if (parcelas[i] <= rendas[i] * 0.30f) {
            printf("Resultado inicial: renda SUFICIENTE para a parcela estimada.\n");
        } else {
            printf("Resultado inicial: renda INSUFICIENTE para a parcela estimada.\n");
        }

        
        {
            float percentual = (parcelas[i] / rendas[i]) * 100.0f;
            int faixa;

            if (percentual <= 20.0f) {
                faixa = 0; /* Aprovado        */
            } else if (percentual <= 30.0f) {
                faixa = 1; /* Em analise      */
            } else {
                faixa = 2; /* Reprovado       */
            }

            switch (faixa) {
                case 0:
                    printf("Classificacao: APROVADO (comprometimento de %.1f%% da renda)\n", percentual);
                    break;
                case 1:
                    printf("Classificacao: EM ANALISE (comprometimento de %.1f%% da renda)\n", percentual);
                    break;
                case 2:
                    printf("Classificacao: REPROVADO (comprometimento de %.1f%% da renda)\n", percentual);
                    break;
                default:
                    printf("Classificacao: INDEFINIDA\n");
                    break;
            }

            status[i] = faixa; 
        }
    }

   
    printf("\n=========================================\n");
    printf("        RELATORIO FINAL - TODOS OS CLIENTES\n");
    printf("=========================================\n");
    printf("%-3s %-20s %-12s %-12s %-12s %-15s\n",
           "Nº", "Nome", "Renda(R$)", "Carro(R$)", "Parcela(R$)", "Status");
    printf("---------------------------------------------------------------------------\n");

    for (i = 0; i < qtdClientes; i++) {
        const char *statusTexto;

        switch (status[i]) {
            case 0:  statusTexto = "APROVADO";     break;
            case 1:  statusTexto = "EM ANALISE";   break;
            case 2:  statusTexto = "REPROVADO";    break;
            default: statusTexto = "INDEFINIDO";   break;
        }

        printf("%-3d %-20s %-12.2f %-12.2f %-12.2f %-15s\n",
               i + 1, nomes[i], rendas[i], precos[i], parcelas[i], statusTexto);
    }

    printf("---------------------------------------------------------------------------\n");
    printf("Total de clientes processados: %d\n", qtdClientes);

    return 0;
}