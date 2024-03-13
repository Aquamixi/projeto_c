static float pegarValorItemAlimentos(int codigoItem)
{
    float valor = 0.0;

    switch(codigoItem)
    {
        case 21:
            valor = 19.99f;
            break;
        case 22:
            valor = 5.99f;
            break;
        case 23:
            valor = 4.50f;
            break;
        case 24:
            valor = 8.00f;
            break;
        case 25:
            valor = 5.00f;
            break;
        default:
            valor = 0;
            break;
    }
    return valor;
}

static float criarMenuAlimentos()
 {
     float valor = 0.0;
    int codigo = 0;

    printf("\n");

    printf("Item (codigo) - Nome do Item - Valor (Unidade)");
    printf("\n");
    printf("     21       -  Cafe -  R$ 19.99");
    printf("\n");
    printf("     22       -  Leite (cx) -  R$ 5.99");
    printf("\n");
    printf("     23       -  Arroz (1kg)  -  R$ 4.50");
    printf("\n");
    printf("     24       -  Feijao  -    R$ 8.00");
    printf("\n");
    printf("     25       -  Açucar (1kg)  -    R$ 5.00");
    printf("\n");

   printf("15. Voltar ao Menu Principal");
    printf("\n");


    scanf("%d", &codigo);

    valor = pegarValorItemAlimentos(codigo);

    return valor;
 }
