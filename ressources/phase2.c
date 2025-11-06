#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ressources.h"

int verifeirFichier(const char *nomFichier) {
    FILE *f = fopen(nomFichier, "r");
    if (f == NULL) {
        // Si le fichier n'existe pas encore, on considère qu'il y a 0 lignes
        return 0;
    }
    Candidat liste[100];
    while (fscanf(f, "%s %d %s %lf", 
              liste_candidats -> nom, 
              &liste_candidats -> age,
              liste_candidats -> parti,
              &liste_candidats -> caution) == 3) {
    nb_candidats++;
    }
    fclose(f);
}
    


// Vérifie si le parti est unique parmi les autres candidats
int partiUnique(int index) {
    for (int i = 0; i < nb_candidats; i++) {
        if (i != index && strcmp(liste_candidats[i].parti, liste_candidats[index].parti) == 0) {
            return 0;
        }
    }
    return 1;
}



void verifierCandidatures(){
    for(int i = 0; i < nb_candidats; i++){
        if(liste_candidats[i].age >= 35 && liste_candidats[i].caution == 30000000 && partiUnique(i)){
            liste_candidats[i].estValide = 1;
        }else if(liste_candidats[i].caution != 30000000){
            liste_candidats[i].estValide = 0;
            strcpy(liste_candidats[i].motifRejet, "Caution différente de 30000000");
        } else if(liste_candidats[i].age < 35){
            liste_candidats[i].estValide = 0;
            strcpy(liste_candidats[i].motifRejet, "Âge inférieur à 35 ans");
        }
    }
    printf("Evaluation términée.");
}

void afficherResultats() {
    int n;
    printf("\nRésultats de la vérification des candidatures :\n");
    printf("ID\tNom\t\tParti\t\tStatut\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%-10s\t%-10s\t%s\n", liste_candidats[i].id, liste_candidats[i].nom, liste_candidats[i].parti,
               liste_candidats[i].estValide ? "Acceptée" : "Rejetée");
    }
}
