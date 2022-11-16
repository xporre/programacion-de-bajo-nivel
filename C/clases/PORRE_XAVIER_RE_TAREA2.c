#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int menu(int opcion){
    printf("\n menu \n1) Lista destinos de saliendo de aeropuerto \n2) Lista orígenes llegando a aeropuerto \n3) Lista aerolíneas que operan por aeropuerto \n4) Mostrar aerolínea con mas rutas \n5) Mostrar que aerolíneas cubren mas ruta entre dos aeropuertos \n6) Salir \n");
    scanf("%i",&opcion);
    return opcion;
}

typedef struct array_rutas
{
    char cod_aero[100];
    char aerolinea[100];
    char cod_origen[100];
    char origen[100];
    char cod_destino[100];
    char destino[100];

}array_rutas;   

    





int main(){

    int opcion=0;
    

    FILE *rutas_csv = fopen("/Users/xavierporre/Desktop/Progrmacion de bajo nivel/C/clases/rutas.csv", "r");
    if(rutas_csv==NULL){perror("Revisar ruta del archivo\n");}
    else{printf("se lee el archivo sin problema\n");}
   
    char buff[1024];
    int c_fila=0, i=0 , m=sizeof(rutas_csv);

    array_rutas *rutas_e0;
    rutas_e0 = malloc(m);

    char *campo;
    while(fgets(buff, sizeof(buff), rutas_csv))
    {
        //printf("%s\n", buff);

        c_fila++;
        if (c_fila<=1)
        {
            continue;
        }
        
        campo = strtok(buff, ";,\n");
        int c_campo=0;

        while(campo)
        {
            //hacer copia de los datos csv en array
            //printf("%s\n",campo);

            //printf("%i |%i\n",i,c_campo);
            
            if(c_campo==0){strcpy(rutas_e0[i].cod_aero, campo); }
            if(c_campo==1){strcpy(rutas_e0[i].aerolinea, campo); }
            if(c_campo==2){strcpy(rutas_e0[i].cod_origen, campo); }
            if(c_campo==3){strcpy(rutas_e0[i].origen, campo); }
            if(c_campo==4){strcpy(rutas_e0[i].cod_destino, campo); }
            if(c_campo==5){strcpy(rutas_e0[i].destino, campo); }
            campo = strtok(NULL, ";");
            c_campo++;

            
                
        }
        i++;// pasar a siguiente linea 

        
    }
    fclose(rutas_csv);
    // mostrar el array
/*
    for(int e=0; e<i; e++){
        printf("%s| %s| %s| %s| %s| %s\n",
        rutas_e0[e].cod_aero,
        rutas_e0[e].aerolinea,
        rutas_e0[e].cod_origen,
        rutas_e0[e].origen,
        rutas_e0[e].cod_destino,
        rutas_e0[e].destino);
    }
*/   


   
    // menu

    while(opcion != 6){
        int a=0,b=0,c=0,d=0,f=0,g=0;
        char *s;
        opcion = menu(opcion);
        switch(opcion) { 
            case 1:
            printf("ingrese siglas de aeropuerto:\n");
            break;
            case 2:
            printf("ingrese siglas de aeropuerto:\n");
            break;
            case 3:
            printf("ingrese siglas de aeropuerto:\n");
            break;
            case 4:
            for (int e = 0; e<i; e++){

                if(strcasecmp(rutas_e0[e].cod_aero, rutas_e0[e+1].cod_aero)){a++;c=b;}

                if(!strcasecmp(rutas_e0[e].cod_aero, rutas_e0[e+1].cod_aero)){
                    b++;
                    d=b-c;
                }
                g=d;
                if(c==b){
                    f=d;
                }

                if(d==f){printf("%s|%i\n", rutas_e0[e].aerolinea,f);}

                

                //printf("%i | %i | %i| %i |%i\n",a,b,c,d,f);
            }

            break;
            case 5:
            printf("ingrese siglas de origen:\n");
            printf("ingrese siglas de destino:\n");
            break;

        }
    

    }
    

   return 0;
}