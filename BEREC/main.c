#include <stdio.h>
#include <stdlib.h>

#include "Padaria.c"
#include "Limpeza.c"
#include "Alimentos.c"
#include "Pagamento.c"


float gastosTotais = 0.0;

float gastoPadaria = 0.0;
float gastoLimpeza = 0.0;
float gastoAlimentos = 0.0;

int main(void)
{
    mostrarAPagar();
    criarMenuPrincipal();

    return 0;
}
//cria o menu principal
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
    printf("-- FIM MENU PRINCIPAL --");
    printf("\n");

    redirecionarUsuario();
}

//redireciona o usu�rio � fun��o correspondente a sua escolha
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
            tipoPagamento();
            break;
        default:
            //avisa que isso n�o � eficaz, e chama de volta o menu
            printf("Enfia um valor gostoso por favor.");
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

void tipoPagamento()
{

    int formaPagamento;


    mostrarAPagar();

    printf("Escolha a forma de pagamento: \n");

    printf("1. cartao \n");
    printf("2. dinheiro \n");
    scanf("%d", &formaPagamento);

    
    tratarPagamento(formaPagamento);

}


// funçao de pagamento 

void tratarPagamento(int formaPagamento) {

    float porcentagem = 0.0;
    float desconto = 0;
    float valorComDesconto = 0;


    if(formaPagamento == 1) {
        porcentagem = 0.0;
    }

    else if(gastosTotais <= 0 && gastosTotais <= 50)
    {
        porcentagem = 0.05;

    } 
    else if(gastosTotais > 50 && gastosTotais <= 99)
    {   
        porcentagem = 0.10;

    } 
    else if(gastosTotais >= 100)
    {
        porcentagem = 0.18;
    }


    desconto = (porcentagem * gastosTotais);
    valorComDesconto = (gastosTotais - desconto);

    printf("Valor total: %.2f \n", gastosTotais);
    printf("Valor descontado: %.2f \n", desconto);
    printf("Valor final com desconto: %.2f \n", valorComDesconto);

}

// mostra os valores que tem que pagar
void mostrarAPagar()
{
    system("cls");
    printf("--/--/--/--/--/--/");
    printf("\n");
    printf("Valor da Limpeza � pagar: %.2f", gastoLimpeza);
    printf("\n");
    printf("Valor de Alimentos � pagar: %.2f", gastoAlimentos);
    printf("\n");
    printf("Valor da Padaria � pagar: %.2f", gastoPadaria);
    printf("\n");
    printf("Valor � pagar: %.2f", gastosTotais);
    printf("\n");
    printf("--/--/--/--/--/--/");
    printf("\n \n");
}
