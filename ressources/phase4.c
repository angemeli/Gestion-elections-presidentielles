#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ressources.h"




void afficherliste_candidats(){
    void pourcentage();
    int i;
    printf("\nTableau des résultats :\n");
    printf("ID\tNom\t\tParti\tVoix\tPourcentage\n");
    for (int i = 0; i < nb_candidats; i++) {
        printf("%d\t%-10s\t%-5d\t%-10s\t%d\t%.2f%%\n", liste_candidats[i].id, liste_candidats[i].nom, liste_candidats[i].age, liste_candidats[i].parti, liste_candidats[i].nb_votes, liste_candidats[i].pourcentage);
    }
 
}

void trierCroissant(){
    int i, j, Tmp;
    for(i = 0; i < 10; i++){
        for(j = i + 1; j < 10; j++){
            if(liste_candidats[i].voix > liste_candidats[j].voix){
                Tmp = liste_candidats[i].voix;
                liste_candidats[i].voix = liste_candidats[j].voix;
                liste_candidats[j].voix = Tmp;}
        }
    }

    printf("\n les résultats par ordre croissant de vote sont :\n");
    afficherliste_candidats();
}

void pourcentage(){

    int i;
    float pourcentage;

    for(i = 0; i < 10; i++){
        pourcentage += liste_candidats[i].voix;
    }
    nb_electeurs = (int)pourcentage;
    for(i = 0; i < sizeof(liste_candidats); i++){
        liste_candidats[i].pourcentage = (liste_candidats[i].voix*100.0)/pourcentage;
    }
}

void caution(){
    printf("\n Voici les candidants dont la caution sera  rembourséé \n");
    int i;
    for(i = 0; i < nb_candidats; i++){
        if(liste_candidats[i].pourcentage >= 12.0){
            printf("- %s (%d%%)\n", liste_candidats[i].nom, liste_candidats[i].pourcentage);
        }
    }

}

