#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ressources.h"


void remplirliste_candidats(){
    int i;
    printf("\nEntrer les valeurs du tableaux: \n");
    for(i = 0; i < 10; i++){
        printf("liste_candidats[%d] = ", i + 1);
        scanf("%f", &liste_candidats[i]);
    }
}

void afficherliste_candidats(){
    void pourcentage();
    int i;
    printf("\nTableau des résultats :\n");
    printf("ID\tNom\t\tParti\tVoix\tPourcentage\n");
    for (int i = 0; i < nb_candidats; i++) {
        printf("%d\t%-10s\t%-5s\t%.0f\t%.2f%%\n", candidats[i].id, candidats[i].nom, candidats[i].age, candidats[i].parti, candidats[i].nb_votes, candidats[i].pourcentage);
    }
 
}

void trierCroissant(){
    int i, j;
    float Tmp;
    for(i = 0; i < 10; i++){
        for(j = i + 1; j < 10; j++){
            if(liste_candidats[i] > liste_candidats[j]){
                Tmp = liste_candidats[i];
                liste_candidats[i] = liste_candidats[j];
                liste_candidats[j] = Tmp;}
        }
    }

    printf("\n les résultats par ordre croissant de vote sont :\n");
    afficherliste_candidats();
}

void pourcentage(){

    int i;
    float pourcentage;

    for(i = 0; i < 10; i++){
        pourcentage += liste_candidat[i].voix;
    }
    nb_votants = (int)pourcentage;
    for(i = 0; i < liste_candidat; i++){
        liste_candidats[i].pourcentage = (liste_candidats[i].voix*100.0)/pourecntage;
    }
}

void caution(){
    printf("\n Voici les candidants dont la caution sera  rembourséé \n");
    int i;
    for(i = 0; i < liste_candidats; i++){
        if(liste_candidats[i].pourcentage >= 12.0){
            printf("- %s (%.2f%%)\n", candidats[i].nom, liste_candidats[i].pourcentage);
        }
    }

}



