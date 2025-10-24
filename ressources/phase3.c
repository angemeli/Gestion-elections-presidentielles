#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "ressources.h"

int hide_input() {
    char input[100];
    int i = 0;
    char ch;

    while (i < sizeof(input) - 1) {
        ch = _getch();
        
        if (ch == 13) {
            break;
        }
        else if (ch == 8) {
            if (i > 0) {
                i--;
                printf("\b\b"); //Effacer le dernier caractère affiché
            }
        }
        else {
            input[i++] = ch; //Ajouter le caractère à l'input
            printf("*");
        }
    }

    input[i] = '\0'; //Terminer la chaîne
    return atoi(input);
}

void vote() {
    for (int i = 0; i < nb_electeurs; i++) {
        Electeur electeur = liste_electeurs[i];

        system("cls");
        printf("----- CONSIGNES POUR LES ELECTIONS -----\n"
            "\nChaque electeur ne peut voter qu'une seule fois. Pour chaque electeur, vous devez entrer l'id correspondant au candidat choisi"
            "\nPour soumettre un bulettin nul, entrez 0"
            "\nPour s'abstenir du vote, appuyez sur entree\n"
        );

        printf("\n--- Liste des candidats ---");
        for (int j = 0; j < nb_candidats; j++) {
            Candidat candidat = liste_candidats[j];
            printf("\n%d. %s (%s)", candidat.id, candidat.nom, candidat.parti);
        }

        printf("\n\n--- Electeur %d ---"
            "\nNom : %s"
            "\nAge : %d"
            "\nQuartier : %s\n"
            "\nChoix de l'electeur : ",
            electeur.id, electeur.nom, electeur.age, electeur.quartier
        );
        electeur.vote = hide_input();
        liste_electeurs[i] = electeur;
    }

    printf("\n\nLes votes sont termines");
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
            
            printf("%c", statut);
        }
    }
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
        candidat.nb_votes += 1; // Compter le vote du candidat lui-même
        
        liste_candidats[i] = candidat; 
    }

    printf("\nLe decompte des votes est termine\n");
}
