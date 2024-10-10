#include <stdlib.h>
#include <stdio.h>

int main(){
    FILE *file;
    char *content;
    long file_size;
    
    //ouvrir le fichier en mode lecture
    file = fopen("exercice1.txt", "r");
    
    //vérification si le fichier a bien été ouvert
    if (file == NULL){
        printf("Erreur : impossible d'ouvrir le fichier .\n");
        return 1;
    }
    
    // Se déplacer à la fin du fichier pour connaître sa taille
    fseek(file, 0, SEEK_END); // modifie la position du fichier pour la mettre à un nouvel emplacement
    file_size = ftell(file); // Récupérer la taille du fichier
    rewind(file); // Revenir au début du fichier
    
    // Allouer de la mémoire pour le contenu du fichier
    content = (char *)malloc(sizeof(char) * (file_size + 1));// +1 pour le '\0'
    
    // Vérification de l'allocation mémoire
    if (content == NULL) {
        printf("Erreur : mémoire insuffisante.\n");
        fclose(file);
        return 1;
    }
    
    // Lire le fichier et stocker son contenu dans le buffer 'content'
    fread(content, sizeof(char), file_size, file);
    content[file_size] = '\0'; // S'assurer que la chaîne de caractères est terminée
    
    // Afficher le contenu du fichier
    printf("Contenu du fichier :\n%s\n", content);
    
    // Fermer le fichier et libérer la mémoire
    fclose(file);
    free(content);
    
    return 0;
}
