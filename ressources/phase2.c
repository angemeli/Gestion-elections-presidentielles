#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ressources.h"

int partiUnique(Candidat candidat[], int index, int total) {
    for (int i = 0; i < total; i++) {
        if (i != index && strcmp(candidat[i].parti, candidat[index].parti) == 0) {
            return 0;
        }
    }
    return 1;
}



void verifierCandidatures(Candidat candidat[], int n){
    for(int i = 0; i < n; i++){
        if(candidat[i].age >= 35 && candidat[i].caution == 30000000 && partiUnique(candidat, i, n)){
            candidat[i].estValide = 1;
        }else{
            candidat[i].estValide = 0;
        }
    }
}

void afficherResultats(Candidat candidat[], int n) {
    printf("\nRésultats de la vérification des candidatures :\n");
    printf("ID\tNom\t\tParti\t\tStatut\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%-10s\t%-10s\t%s\n", candidat[i].id, candidat[i].nom, candidat[i].parti,
               candidat[i].estValide ? "Acceptée" : "Rejetée");
    }
}
