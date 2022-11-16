#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE * txt_quijote;
    txt_quijote = fopen("/Users/xavierporre/Desktop/Progrmacion de bajo nivel/C/el_quijote.txt", "r\n");
    
    if(txt_quijote == NULL){

        perror("error");
    }else{
        printf("se esta leyendo el texto\n");
    }
    char quijote[100], text[50];
    int i = 0,l=0,s=0;

    while(fgets(quijote, sizeof(quijote), txt_quijote)){
        //printf("%s",quijote);
        if(strcmp(quijote,"\n")){
            s+=1;
        }
        i+=1;

    }
    printf("\n%i caracteres",i);
    printf("\n%i lineas",s);
    fclose(txt_quijote);


    return 0;
}