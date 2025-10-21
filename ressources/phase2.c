#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ressources.h"



void verifierCandidatures(Candidat candidat[], int n){
    for(int i = 0; i < n; i++){
        if(candidats[i].age >= 35 && candidats[i].cautionPayee == 1 && candidats[i].dossierComplet == 1){
            candidats[i].estValide = 1;
        }else{
            candidats[i].estValide = 0;
        }
    }
}

void afficherResultats(candidat candidats[], int n){
    printf("\n Résultats de la vérification des candidatures :\n");
    printf("id\tnom\tparti\tStatut\n");
    for(int i = 0; i < n; i++){
        printf("%d\t%-10s\t%-10s\t%s\n", candidats[i].id, candidats[i].nom, candidats[i].parti, candidats[i].estValide ? "Acceptée" : "Rejetée");
    }
}
