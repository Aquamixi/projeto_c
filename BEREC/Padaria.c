#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

static float pegarValorItemPadaria(int codigoItem)
{
    float valor = 0.0;

    switch(codigoItem)
    {
        case 31:
            valor = 9.5f;
            break;
        case 32:
            valor = 12.5f;
            break;
        case 33:
            valor = 1.9f;
            break;
        case 34:
            valor = 8.5f;
            break;
        default:
            valor = 0;
            break;
    }
    return valor;
}


 static float criarMenuPadaria()
 {

    float valor = 0.0;
    int codigo = 0;

    printf("\n");

    printf("Item (codigo) - Nome do Item - Valor (Unidade)");
    printf("\n");
    printf("     31       - Pao de Forma -  R$ 9,50");
    printf("\n");
    printf("     32       - Pao Integral -  R$ 12,50");
    printf("\n");
    printf("     33    - Pao Frances(Unid) -  R$ 1,90");
    printf("\n");
    printf("     34       -  Sonho  -    R$ 8,50");
    printf("\n");


    printf("15. Voltar ao Menu Principal");
    printf("\n");

    scanf("%d", &codigo);
    valor = pegarValorItemPadaria(codigo);

    return valor;
}
