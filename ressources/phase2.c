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
        if (c.estValide == 0) {
            printf(" (%s)", c.motifRejet);
        }
        
    }
    printf("\n");
}

void verifierCandidatures(Candidat candidat[], int n) {
    for(int i = 0; i < n; i++) {
        candidat[i].estValide = 0;

        if (candidat[i].age < 35) {
            candidat[i].estValide = 0;
            strcpy(candidat[i].motifRejet, "Age inferieur a l'age minimum requis");
        }
        else if (candidat[i].caution != 30000000) {
            candidat[i].estValide = 0;
            strcpy(candidat[i].motifRejet, "Montant de la caution non respecte");
        }
        else if (partiUnique(candidat, i, n) == 0) {
            candidat[i].estValide = 0;
            strcpy(candidat[i].motifRejet, "Pluralite de candudatures pour le meme parti");
        }

        else {
            candidat[i].estValide = 1;
        }
        
    }
    afficherResultats(candidat, n);
}

void retourner_liste_valide() {
    Candidat liste[500]; 
    int j = 0;
    for (int i = 0; i < nb_candidats; i++) {
        Candidat c = liste_candidats[i];
        if (c.estValide == 1) {
            c.id = j+1;
            liste[j] = c;
            j += 1;
        }
    }
    
    *liste_candidats_valides = liste;
    nb_candidats_valides = j;
} 
