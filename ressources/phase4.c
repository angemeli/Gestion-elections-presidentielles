#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ressources.h"

void pourcentage(){
    for (int i = 0; i < nb_candidats; i++) {
        Candidat candidat = liste_candidats[i];
        candidat.pourcentage = (double)candidat.nb_votes * 100  / (double)(nb_electeurs + nb_candidats);
        liste_candidats[i] = candidat;
    }
}

void afficherliste_candidats(){
    pourcentage();
    int i;
    for (int i = 0; i < nb_candidats; i++) {
        Candidat c = liste_candidats[i];
        printf("\n%d. %s (%s) : %.2f%% (%d voix)", i+1, c.nom, c.parti, c.pourcentage, c.nb_votes);
    }
    printf("\n");
}

void trierCroissant(){
    int i, j; 
    Candidat tmp;
    for(i = 0; i < nb_candidats-1; i++){
        for(j = i + 1; j < nb_candidats; j++){
            if(liste_candidats[i].nb_votes < liste_candidats[j].nb_votes){
                tmp = liste_candidats[i];
                liste_candidats[i] = liste_candidats[j];
                liste_candidats[j] = tmp;
            }
        }
    }

    printf("\n------- RESULTATS DE L'ELECTION PRESIDENTIELLE -------\n");
    afficherliste_candidats();
}

void caution(){
    printf("\nVoici les candidants dont la caution sera  remboursee :");
    int i;
    for(i = 1; i < nb_candidats; i++){
        if(liste_candidats[i].pourcentage >= 12.0){
            printf("\n- %s (%s) (%.2f%%)", liste_candidats[i].nom, liste_candidats[i].parti, liste_candidats[i].pourcentage);
        }
    }
    printf("\n");
}
