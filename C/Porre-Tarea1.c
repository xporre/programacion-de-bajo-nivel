#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

    char 
    input_s[1024],
    input_p[1024],
    delimiter[]=" ",
    *token,
    *token2;
    int i=0;
     
    printf("-s");
    fgets(input_s, sizeof(input_s), stdin);

    printf("-p");
    fgets(input_p, sizeof(input_p), stdin);

    token = malloc(strlen(input_s));
    token = strtok(input_s,delimiter);

    
    printf("sopa de letras\n"); 

    if(token != NULL){
        while(token != NULL){
            printf("\n %s \n", token); 
            token = strtok(NULL, delimiter);
        }
    }
    
    printf("Palabras\n %s",input_p);



return 0;
}
