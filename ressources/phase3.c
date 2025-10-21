#include <stdio.h>
#include <stdlib.h>

#include "ressources.h"

void vote() {
    system("cls");
    printf("----- CONSIGNES POUR LES ELECTIONS -----\n"
        "\nChaque electeur ne peut voter qu'une seule fois. Pour chaque electeur, vous devez entrer l'id correspondant au candidat choisi"
        "\nPour soumettre un bulettin nul, entrez 0"
        "\nPour s'abstenir du vote, appuyez sur entree\n"
        "\nAppuyez sur la touche entree pour continuer "
    );
    scanf("");

    for (int i = 0; i < nb_electeurs; i++) {
        Electeur electeur = liste_electeurs[i];

        system("cls");

        printf("\nListe des candidats :\n");
        for (int j = 0; j < nb_candidats; j++) {
            Candidat candidat = liste_candidats[j];
            printf("\n%d. %s (%s)", candidat.id, candidat.nom, candidat.parti);
        }

        printf("Electeur %d :"
            "\nNom : %s"
            "\nAge : %d"
            "\nQuartier : %s\n"
            "\nChoix de l'electeur : ",
            electeur.id, electeur.nom, electeur.age, electeur.quartier
        );
        scanf("%d", &electeur.vote);
    }

    printf("\n\nLes votes sont termines. Appuyez sur entree pour continuer ");
    system("cls");
}

void check_elector_vote() {
    int id;
    printf("\nEntrez l'id de l'electeur a verifier : ");
    scanf("%d", &id);

    for (int i = 0; i < nb_electeurs; i++) {
        Electeur electeur = liste_electeurs[i];
        if (electeur.id == id) {
            printf("\nStatut de l'electeur de id %d, nomme %s : ", id, electeur.nom);
            char statut;
            if (electeur.vote != 0) {
                statut = 'V';
            }
            else {
                statut = 'A';
            }
            
            printf("%s", statut);
        }
    }

    printf("\n\nAppuyez sur entree pour continuer ");
    scanf("");
}

void count_votes() {
    for (int i = 0; i < nb_candidats; i++) {
        Candidat candidat = liste_candidats[i];
        candidat.nb_votes = 0;
        for (int j = 0; j < nb_electeurs; j++) {
            Electeur electeur = liste_electeurs[j];
            if (candidat.id == electeur.vote) {
                candidat.nb_votes += 1;
            }
        }
        
        liste_candidats[i] = candidat;   
    }

    printf("Le decompte des votes s'est acheve avec succes. Appuyez sur entree pour continuer ");
    scanf("");
}
