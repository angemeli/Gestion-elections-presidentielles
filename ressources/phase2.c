#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ressources.h"

// Vérifie si le parti est unique parmi les autres candidats
int partiUnique() {
    int index, total;
    for (int i = 0; i < total; i++) {
        if (i != index && strcmp(liste_candidats[i].parti, liste_candidats[index].parti) == 0) {
            return 0;
        }
    }
    return 1;
}



void verifierCandidatures(){
    int n;
    for(int i = 0; i < n; i++){
        if(liste_candidats[i].age >= 35 && liste_candidats[i].caution == 30000000 && partiUnique()){
            liste_candidats[i].estValide = 1;
        }else{
            liste_candidats[i].estValide = 0;
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
