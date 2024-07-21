#include <stdio.h>

int main()
{
    int length;
    
    /* Guardar o cumprimento do array */
    printf("What is the length of the array? ");
    scanf("%d", &length);
    printf("\n"); // break line
    
    int array[length];
    int icont;
    
    /* Inicializar todas as posições do array com zero */
    for (icont = 0; icont < length; icont++){
        array[icont] = 0;
    }
    
    int positiveLife_total = 0;
    int negativeLife_total = 0;
    int finalLife_total = 0;
    
    /* Armazenar o número de vidas em cada porta */
    printf("Enter the %d value of the array", length);
    printf("\n"); // break line
    for (icont = 0; icont < length; icont++){
        printf("door n° %d: ", icont);
        scanf("%d", &array[icont]);
        
        /* Cálcular a quantidade de vidas considerados todas as portas */
        if (array[icont] < 0){
            negativeLife_total -= array[icont];
        } else {
            positiveLife_total += array[icont];
        }
    }
    
    finalLife_total = (positiveLife_total - negativeLife_total);
    
    int firstDoor;
    int lastdoor;
    
    printf("\n"); // break line
    /* Porta de entrada */
    printf("What is the entry port number? ");
    scanf("%d", &firstDoor);
    
    /* Porta de saída */
    printf("What is the output port number? ");
    scanf("%d", &lastdoor);
    
    /* Conferir se a porta de entrada é menor do que a porta de saída 
     e se a porta de saída é maior do que o array */
    if ((firstDoor < lastdoor) && (lastdoor < length)){
        
        int positiveLife = 0;
        int negativeLife = 0;
        int finalLife = 0;
        
        /* Cálculo do máximo de vidas possíveis entre as portas escolhidas */
        for (icont = firstDoor; icont <= lastdoor; icont++){
            if (array[icont] < 0){
                negativeLife -= array[icont];
            } else {
                positiveLife += array[icont];
            }
        }
        
        finalLife = (positiveLife - negativeLife);
        
        printf("\nThe maximum number of lives possible between doors at the chosen doors is %d\n", finalLife);
        printf("The maximum number of possible lives considering all at the gates is %d", finalLife_total);
    } else if (lastdoor >= length) {
        printf("\nthis door does not exist");
    } else if (firstDoor > lastdoor) {
        printf("\nThe input port needs to be smaller than the output port");
    }
}