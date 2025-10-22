#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ressources.h"

// Vérifie si le parti est unique parmi les autres candidats
int partiUnique(Candidat candidats[], int index, int total) {
    for (int i = 0; i < total; i++) {
        if (i != index && strcmp(candidats[i].parti, candidats[index].parti) == 0) {
            return 0;
        }
    }
    return 1;
}



void verifierCandidatures(Candidat candidat[], int n){
    for(int i = 0; i < n; i++){
        if(candidats[i].age >= 35 && candidats[i].cautionPayee == 30000000 && partiUnique(candidats, i, n)){
            candidats[i].estValide = 1;
        }else{
            candidats[i].estValide = 0;
        }
    }
}

void afficherResultats(Candidat candidats[], int n) {
    printf("\nRésultats de la vérification des candidatures :\n");
    printf("ID\tNom\t\tParti\t\tStatut\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%-10s\t%-10s\t%s\n", candidats[i].id, candidats[i].nom, candidats[i].parti,
               candidats[i].estValide ? "Acceptée" : "Rejetée");
    }
}
