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

void afficherResultats(Candidat candidat[], int n) {
    printf("\nResultats de la verification des candidatures :\n");
    for (int i = 0; i < n; i++) {
        Candidat c = candidat[i];
        printf("\n%d. %s (%s) : %s", c.id, c.nom, c.parti,
            c.estValide == 1 ? "Acceptee" : "Rejetee");
    }
    printf("\n");
}

void verifierCandidatures(Candidat candidat[], int n) {
    for(int i = 0; i < n; i++){
        if(candidat[i].age >= 35 && candidat[i].caution == 30000000 && partiUnique(candidat, i, n)){
            candidat[i].estValide = 1;
        } else{
            candidat[i].estValide = 0;
        }
    }

    afficherResultats(candidat, n);
}