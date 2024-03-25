#include <stdio.h>
#include <stdlib.h>
#include <TIME.H>

#include "Padaria.c"
#include "Limpeza.c"
#include "Alimentos.c"
#include "Pagamento.c"


float faturamentoDiario = 0.0;
float faturamentoPadaria = 0.0;
float faturamentoLimpeza = 0.0;
float faturamentoAlimentos = 0.0;
int vendas = 0;

static float gastosTotais = 0.0;

float gastoPadaria = 0.0;
float gastoLimpeza = 0.0;
float gastoAlimentos = 0.0;

int main(void)
{
    mostrarAPagar();
    criarMenuPrincipal();

    return 0;
}

// cria o menu principal
void criarMenuPrincipal()
{
    printf("-- MENU PRINCIPAL --");
    printf("\n");
    printf("1. material de Limpeza");
    printf("\n");
    printf("2. Venda de Alimentos");
    printf("\n");
    printf("3. Padaria");
    printf("\n");
    printf("4. Pagamento");
    printf("\n");
    printf("5. Terminar faturacao do dia");
    printf("\n");
    printf("-- FIM MENU PRINCIPAL --");
    printf("\n");

    redirecionarUsuario();
}

// redireciona o usuario a funcao correspondente a sua escolha
void redirecionarUsuario()
{
    int entrada = 0;
    scanf("%d", &entrada);

    switch(entrada)
    {
        case 1:
            //chama material de limpeza
            chamarLimpeza();

            break;
        case 2:
            //chama Venda de alimentos
            chamarAlimentos();
            break;
        case 3:
            //chama Padaria
            chamarPadaria();
            break;
        case 4:
            //chama pagamento
            chamarPagamento();
            break;
        case 5:
            //chama pagamento
            terminarFaturamento();
            break;
        default:
            //avisa que isso n�o � eficaz, e chama de volta o menu
            printf("Escreva um valor correto.");
            criarMenuPrincipal();
            break;
    }
}

// chama a Padaria, salva os valores selecionados e volta ao Menu principal se o Usuario decidir
void chamarPadaria()
{
    float gastoNovo;

    mostrarAPagar();
    gastoNovo = criarMenuPadaria();

    if(gastoNovo < 1)
    {
        mostrarAPagar();
        criarMenuPrincipal();
    }
    else
    {
        gastoPadaria += gastoNovo;
        gastosTotais += gastoNovo;
        mostrarAPagar();
        chamarPadaria();
    }
}

// chama a Limpeza, salva os valores selecionados e volta ao Menu principal se o Usuario decidir
void chamarLimpeza()
{
    float gastoNovo;

    mostrarAPagar();
    gastoNovo = criarMenuLimpeza();

    if(gastoNovo < 1)
    {
        mostrarAPagar();
        criarMenuPrincipal();
    }
    else
    {
        gastoLimpeza += gastoNovo;
        gastosTotais += gastoNovo;
        mostrarAPagar();
        chamarLimpeza();
    }
}

// chama a Alimentos, salva os valores selecionados e volta ao Menu principal se o Usuario decidir
void chamarAlimentos()
{
    float gastoNovo;

    mostrarAPagar();
    gastoNovo = criarMenuAlimentos();

    if(gastoNovo < 1)
    {
        mostrarAPagar();
        criarMenuPrincipal();
    }
    else
    {
        gastoAlimentos += gastoNovo;
        gastosTotais += gastoNovo;
        mostrarAPagar();
        chamarAlimentos();
    }
}

// chama o pagamento, reinicia o sistema depois de terminado.
void chamarPagamento()
{
    int tipoPago = 0;
    int maquina = 0;

    tipoPago = tipoPagamento();

    if(tipoPago == 1) {
        tratarCartao();

        maquina = maquinaDeCartao();
        if(maquina == 2)
        {
            mostrarAPagar();
            chamarPagamento();
        }
        else
        {
            tratarCartao();
        }
    }
    else
    {
        tratarDinheiro();
    }
    printf("\n Pagamento realizado!");

    faturamentoDiario += gastosTotais;
    faturamentoAlimentos += gastoAlimentos;
    faturamentoLimpeza += gastoLimpeza;
    faturamentoPadaria += gastoPadaria;
    vendas++;

    sleep(5);
    gastoAlimentos = 0.0;
    gastoPadaria = 0.0;
    gastoLimpeza = 0.0;
    gastosTotais = 0.0;
    main();
}

// termina o faturamento, mostrando as vendas do dia.
void terminarFaturamento()
{
    system("cls");
    printf("--/--/--/--/--/--/");
    printf("\n");
    printf("Faturamento de limpeza: %.2f", faturamentoLimpeza);
    printf("\n");
    printf("Faturamento de Alimentos: %.2f", faturamentoAlimentos);
    printf("\n");
    printf("Faturamento da Padaria: %.2f", faturamentoPadaria);
    printf("\n");
    printf("Faturamento total do dia: %.2f", faturamentoDiario);
    printf("\n");
    printf("Quantidade total de vendas hoje: %d", vendas);
    printf("\n");
    printf("--/--/--/--/--/--/");
    printf("\n \n \n");

}
// mostra os valores que tem que pagar
void mostrarAPagar()
{
    system("cls");
    printf("--/--/--/--/--/--/");
    printf("\n");
    printf("Valor da Limpeza a pagar: %.2f", gastoLimpeza);
    printf("\n");
    printf("Valor de Alimentos a pagar: %.2f", gastoAlimentos);
    printf("\n");
    printf("Valor da Padaria a pagar: %.2f", gastoPadaria);
    printf("\n");
    printf("Valor a pagar: %.2f", gastosTotais);
    printf("\n");
    printf("--/--/--/--/--/--/");
    printf("\n \n");
}
