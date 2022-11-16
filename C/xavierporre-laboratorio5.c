#include <stdio.h>

void hablaGato(){
    printf("Miau \n");
}
void hablaPerro(){
    printf("Guau \n");
}
void hablaHumano(){
    printf("Hola \n");
}
void hablaRobot(){
    printf("486f6c61 \n");
}
int comprobacion(int i,int j){
    switch(j){
        case 0://gato
        if(i<2){
            return 0;
        }else{
            return 1;
        }
        break;

        case 1://perro
        if(i<4){
            return 0;
        }else{
            return 1;
        }
        break;

        case 2:
        if(i<6){
            return 0;
        }else{
            return 1;
        }
        break;


    }

}
int main()
{
    int opcion,i1,i2,i3,i4,n;
    void (*apf[])(int*)={hablaGato, hablaPerro, hablaHumano, hablaRobot};

    while(opcion!=5){
        printf("\n Opciones");
        printf("\n1) gato");
        printf("\n2) perro");
        printf("\n3) persona");
        printf("\n4) robot");
        printf("\n5) terminar");
        printf("\n");
        scanf("%i",&opcion);

        switch(opcion){
            case 1:
            if (comprobacion(i1,0)==0)
            {
                apf[0](&n);
                i1+=1;
            }else{
                printf("\n no puedo hablar");
            }
            break;

            case 2:
            if (comprobacion(i2,1)==0){
                apf[1](&n);
                i2+=1;
            }else{
                printf("\n no puedo hablar");

            }
            break;

            case 3:
            if (comprobacion(i3,2)==0){
                apf[2](&n);
                i3+=1;
            }else{
                printf("\n no puedo hablar");
            }
            break;

            case 4:
            apf[3](&n);
            i4+=1;
            break;

            case 5:
            printf("\ngato hablo %i veces ",i1);
            printf("\nperro hablo %i veces ",i2);
            printf("\npersona hablo %i veces ",i3);
            printf("\nrobot hablo %i veces",i4);


        }
    }
    return 0;
}



