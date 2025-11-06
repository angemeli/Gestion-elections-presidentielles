#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ressources.h"

void pourcentage(Candidat *liste_candidats){
    for (int i = 0; i < nb_candidats_valides; i++) {
        Candidat candidat = liste_candidats[i];
        candidat.pourcentage = (double)candidat.nb_votes * 100  / (double)(nb_votants + nb_candidats_valides);
        liste_candidats[i] = candidat;
    }
}

void affichage_resultats(Candidat *liste_candidats){
    pourcentage(liste_candidats);

    int nb_el = nb_electeurs + nb_candidats_valides;
    int nb_vot = nb_votants + nb_candidats_valides;
    nb_abstenus = nb_el - nb_vot;
    printf("\nNombre total d'electeurs inscrits : %d", nb_el);
    printf("\nNombre total d'electeurs ayant vote : %d", nb_vot);
    printf("\nTaux d'abstention : %.2f%%", (double)nb_abstenus*100 / (double)nb_el);
    printf("\nNombre total de bulletins nuls : %d\n", nb_bulletins_nuls);

    printf("\n----- RESULTATS PAR CANDIDAT ----- \n");
    int i;
    for (int i = 0; i < nb_candidats_valides; i++) {
        Candidat c = liste_candidats[i];
        printf("\n%d. %s (%s) : %.2f%% (%d voix)", i+1, c.nom, c.parti, c.pourcentage, c.nb_votes);
    }

    printf("\n\nLe vainqueur de l'election presidentielle est le candidat %s", liste_candidats[0].nom);
    printf("\n");
}

void trierCroissant(Candidat *liste_candidats){
    int i, j; 
    Candidat tmp;
    for(i = 0; i < nb_candidats_valides-1; i++){
        for(j = i + 1; j < nb_candidats_valides; j++){
            if(liste_candidats[i].nb_votes < liste_candidats[j].nb_votes){
                tmp = liste_candidats[i];
                liste_candidats[i] = liste_candidats[j];
                liste_candidats[j] = tmp;
            }
        }
    }

    printf("\n------- RESULTATS DE L'ELECTION PRESIDENTIELLE -------\n");
    affichage_resultats(liste_candidats);
}

void caution(Candidat *liste_candidats){
    printf("\nNote : La caution n'est remboursee que si le candidat a obtenu au moins 12%% des voix");
    printf("\nVoici les candidants dont la caution doit etre remboursee :\n");
    int i;
    for(i = 1; i < nb_candidats_valides; i++){
        if(liste_candidats[i].pourcentage >= 12.0){
            printf("\n- %s (%s) (%.2f%%)", liste_candidats[i].nom, liste_candidats[i].parti, liste_candidats[i].pourcentage);
        }
    }
    printf("\n");
}
