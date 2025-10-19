#include <stdio.h>
#include <stdlib.h>

#include "ressources/ressources.h"

// Fonction principale
int main(int argc, char const *argv[]) {
    int choice = 1;
    int phase = 1;

    while (choice != 0) {
        switch (phase) {
        // Phase 1 : Enregistrement des candidats et des electeurs
        case 1 :
            printf("\n----------------------------------------------------------------\n");
            printf("\nPHASE 1 : ENREGISTREMENT DES CANDIDATS ET DES ELECTEURS\n");
            printf("\nChoisissez une action dans la liste suivante :\n");
            printf(
                "\n1. Enregistrer un nouveau candidat"
                "\n2. Enregistrer un nouvel electeur"
                "\n3. Passer a la phase 2 (evaluation des candidatures)"
                "\n0. Quitter le programme"
                "\n\nVotre choix : "
            );
            scanf("%d", &choice);

            // Choisir une action pour la phase 1
            switch (choice) {
            case 1 :
                system("cls");
                enregCandidat();
                break;
            case 2 :
                system("cls");
                enregElecteur();
                break;
            case 3 :
                char entry;
                printf("\nContinuer vers la phase 2 (evaluation des candidatures) ? (o/n) Cette action est irreversible : ");
                scanf(" %c", &entry);
                if (entry == 'o' || entry == 'O') {
                    phase = 2;        
                }
                system("cls");
                break;
            case 0 :
                printf("\nMerci et a la prochaine !\n");
                return 0;
            default :
                system("cls");
                printf("\nEntree invalide\n");
                break;
            }

            break;

        // Phase 2 : Evaluation des candidatures
        case 2 :
            printf("\n----------------------------------------------------------------\n");
            printf("\nPHASE 2 : EVALUATION DES CANDIDATURES\n");
            printf("\nChoisissez une action dans la liste suivante :\n");
            printf(
                "\n1. Evaluer la validite des candidatures"
                "\n2. Afficher la liste des candidatures acceptees et celles rejetees"
                "\n3. Passer a la phase 3 (vote et comptabilisation)"
                "\n0. Quitter le programme"
                "\n\nVotre choix : "
            );
            scanf("%d", &choice);

            // Choisir une action pour la phase 2
            switch (choice) {
            case 1 :
                system("cls");
                // Fonction 1 de la phase 2
                break;
            case 2 :
                system("cls");
                // Fonction 2 de la phase 2
                break;
            case 3 :
                char entry;
                printf("\nContinuer vers la phase 3 (vote et comptabilisation) ? (o/n) Cette action est irreversible : ");
                scanf(" %c", &entry);
                if (entry == 'o' || entry == 'O') {
                    phase = 3;        
                }
                system("cls");
                break;
            case 0 :
                printf("\nMerci et a la prochaine !\n");
                return 0;
            default :
                system("cls");
                printf("\nEntree invalide\n");
                break;
            }

            break;
        
        // Phase 3 : Vote et comptabilisation
        case 3 :
            printf("\n----------------------------------------------------------------\n");
            printf("\nPHASE 3 : VOTE ET COMPTABILISATION\n");
            printf("\nChoisissez une action dans la liste suivante :\n");
            printf(
                "\n1. Trouver pour un electeur s'il a vote ou pas"
                "\n2. Comptabiliser les votes pour chaque candidat"
                "\n3. Passer a la phase 4 (affichage des resultats)"
                "\n0. Quitter le programme"
                "\n\nVotre choix : "
            );
            scanf("%d", &choice);

            // Choisir une action pour la phase 3
            switch (choice) {
            case 1 :
                system("cls");
                // Fonction 1 de la phase 3
                break;
            case 2 :
                system("cls");
                count_votes();
                break;
            case 3 :
                char entry;
                printf("\nContinuer vers la phase 4 (affichage des resultats) ? (o/n) Cette action est irreversible : ");
                scanf(" %c", &entry);
                if (entry == 'o' || entry == 'O') {
                    phase = 4;        
                }
                system("cls");
                break;
            case 0 :
                printf("\nMerci et a la prochaine !\n");
                return 0;
            default :
                system("cls");
                printf("\nEntree invalide\n");
                break;
            }

            break;

        // Phase 4 : Affichage des résultats
        case 4 :
            printf("\n----------------------------------------------------------------\n");
            printf("\nPHASE 4 : AFFICHAGE DES RESULTATS\n");
            printf("\nChoisissez une action dans la liste suivante :\n");
            printf(
                "\n1. Afficher les resultats de l'election"
                "\n2. Afficher les candidats dont la caution doit etre remboursee"
                "\n0. Quitter le programme"
                "\n\nVotre choix : "
            );
            scanf("%d", &choice);

            // Choisir une action pour la phase 4
            switch (choice) {
            case 1 :
                system("cls");
                // Fonction 1 de la phase 4
                break;
            case 2 :
                system("cls");
                // Fonction 2 de la phase 4
                break;
            case 0 :
                printf("\nMerci et a la prochaine !\n");
                return 0;
            default :
                system("cls");
                printf("\nEntree invalide\n");
                break;
            }

            break;
        
        default :
            break;
        }
    }

    return 0;
}
