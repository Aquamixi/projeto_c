
// transforma o código no preco, e reenvia para o Main.c para lá ser adicionado
static float pegarValorItemLimpeza(int codigoItem)
{
    float valor = 0.0;

    switch(codigoItem)
    {
        case 11:
            valor = 1.99f;
            break;
        case 12:
            valor = 8.99f;
            break;
        case 13:
            valor = 1.50f;
            break;
        case 14:
            valor = 15.00f;
            break;
        default:
            valor = 0;
            break;
    }
    return valor;
}


// cria o menu da Limpeza
static float criarMenuLimpeza()
 {

    float valor = 0.0;
    int codigo = 0;

    printf("\n");

    printf("Item (codigo) - Nome do Item - Valor (Unidade)  ");
    printf("\n");
    printf("     11       -  Detergente -  R$ 1,99");
    printf("\n");
    printf("     12       -  Sabao em Po (1kg) -  R$ 8,99");
    printf("\n");
    printf("     13       -  Esponja  -  R$ 1,50");
    printf("\n");
    printf("     14       -  Amaciante (1Lt)  -    R$ 15,00");
    printf("\n");


   printf("15. Voltar ao Menu Principal");
    printf("\n");

    scanf("%d", &codigo);

    valor = pegarValorItemLimpeza(codigo);

    return valor;
 }
