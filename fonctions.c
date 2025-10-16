#include <stdio.h>
#include "fonctions.h"

//Fonction pour le menu d'accueil
void Menu(void){
    printf("_______________________________________________________________________\n");
    printf("|                                MENU                                  |\n");
    printf("|______________________________________________________________________|\n");
    printf("|1. Enregistrer un candidat                                            |\n");
    printf("|2. Enregistrer un electeur                                            |\n");
    printf("|3. Evaluer la validité d'un candidat                                  |\n");
    printf("|4. Voir les liste des candidatures acceptées et celle des rejetées    |\n");
    printf("|5. Verifier le vote d'un electeur                                     |\n");
    printf("|6. Voir le total de votes d'un candidat                               |\n");
    printf("|7. Classer les candidat par ordre croissant de nombre votes           |\n");
    printf("|8. Afficher les candidats dont la caution doit être rembourssée       |\n");
    printf("|0. Quiter le programme                                                |\n");
    printf("|______________________________________________________________________|\n");
}

//foction pour enregistrer un candidat
void enregCandidat(Candidat c) {
    FILE *f = fopen("candidats.csv", "a"); // "a" = append (ajoute à la fin du fichier)
    if (f == NULL) {
        perror("Erreur d'ouverture du fichier");
        return;
    }
    printf("Entrez l'ID, le nom, l'âge et le parti du candidat :\n");
        scanf("%d %s %d %s", &c.id, c.nom, &c.age, c.parti);
    // écriture d'une ligne CSV
    fprintf(f, "%d,%s,%d,%s\n", c.id, c.nom, c.age, c.parti);
    fclose(f);
}

//foction pour enregistrer un electeur
void enregElecteur(Electeur e) {
    FILE *f = fopen("electeurs.csv", "a"); // "a" = append (ajoute à la fin du fichier)
    if (f == NULL) {
        perror("Erreur d'ouverture du fichier");
        return;
    }
    printf("Entrez l'ID, le nom, l'âge et le quartier de l'electeur :\n");
    scanf("%d %s %d %s", &e.id, e.nom, &e.age, e.quartier);
    // écriture d'une ligne CSV
    fprintf(f, "%d,%s,%d,%s\n", e.id, e.nom, e.age, e.quartier);
    fclose(f);
}

void BoucleDuProgramme(void){
    int choix;
    do{
        Candidat c;
        Electeur e;
        //appel de la fonction qui gère le menu
        Menu();
        printf("Choisissez l'une des options ci-dessus : \n");
        scanf(" %d", &choix);
        while (choix < 0 && choix > 8){
            printf("Entrez une option valide : ");
            scanf(" %d", &choix);
        }
        
        switch (choix){
        case 1:
            enregCandidat(c); 
            break;
        case 2:
            enregElecteur(e);
            break;
        case 0:
            printf("Au revoir! \n");
            break;
        default:
            break;
        }
    } while (choix != 0);
    
}