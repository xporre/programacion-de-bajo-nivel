#include<stdio.h>

int main(){
    int opcion,optionp,cuenta,cuentad;
    float saldo,monto;

    printf("\nIngrese el numero de su cuenta:");
    scanf("%i",&cuenta);
    printf("\nIngrese el monto que desea en su cuenta:");
    scanf("%f",&saldo);


    printf("\nSu numero de cuenta es : %i",cuenta);
    printf("\nSu saldo es: %f",saldo);
    while(opcion!=6){
        printf("\nmenu");
        printf("\n1) mostra el saldo");
        printf("\n2) hacer una transferencia");
        printf("\n3) hacer un deposito");
        printf("\n4) hacer un retiro");
        printf("\n5) pedri un credito");
        printf("\n6) salir");
        printf("\n");
        scanf("%i",&opcion);

        switch(opcion){
            case 1: printf("\nSu numero de cuenta es : %i",cuenta);
                    printf("\nSu saldo es: %f",saldo);
            break;

            case 2: printf("ingrese el monto de transferencia:");
                    scanf("%f",&monto);
                    if (monto>saldo){
                        printf("\n no es posible hacer la transferencia");
                    }
                    else {
                        printf("\ningrese la cuenta destino:");
                        scanf("%i",&cuentad);
                        saldo -= monto;
                    }
            break;

            case 3: printf("\n que monto desea depositar");
                    scanf("%f",&monto);
                    saldo += monto;

            break;

            case 4: printf("cuanto de retirar");
                    scanf("%f",&monto);
                    if(saldo-monto<0){
                        printf("no cuenta con fondos suficientes para esta accion");

                    }else{
                        saldo -= monto;
                    }
                    

            break;

            case 5: printf("\n escoja un monto de prestamo");
                    printf("1) 100.000 2) 250.000 \n 3) 500.000 4)1.000.000");
                    scanf("%i",&optionp);
                    switch(optionp){
                        case 1: saldo += 100000; break;
                        case 2: saldo += 250000; break;
                        case 3: saldo += 500000; break;
                        case 4: saldo += 1000000; break;
                    }


            break;

        };
    }





    return 0;
}