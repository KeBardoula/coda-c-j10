#include <stdlib.h>
#include <stdio.h>

int main(){
    FILE *fp = fopen("exercice2.txt", "w");
    char * content = "Frêre Jacques, frêre Jacques\n"
                      "Dormez-vous, dormez-vous ?";
    
    if (fp == NULL){
        printf("Le fichier exercice2.txt n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }
    
    fprintf(fp, "%s", content);
    
    fclose(fp);
    return 0;
}
