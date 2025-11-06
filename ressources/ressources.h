#ifndef _ce_mot_est_unique_dans_tout_le_programme_
#define  _ce_mot_est_unique_dans_tout_le_programme_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures globales
typedef struct{
    int id;
    char nom[500];
    int age;
    char parti[20];
    int nb_votes;
    int caution;
    int estValide;
    double pourcentage;
    char motifRejet[500];
} Candidat;

typedef struct{
    int id;
    char nom[500];
    int age;
    char quartier[20];
    int vote;
    int estAbstenu;
} Electeur;

// Variables globales
int nb_candidats = 0;
int nb_candidats_valides = 0;
int nb_electeurs = 0;
int nb_bulletins_nuls = 0;
int nb_votants = 0;
int nb_abstenus = 0;
Candidat liste_candidats[500];
Candidat *liste_candidats_valides[500];
Electeur liste_electeurs[1000];

// Fonctions accessoires
int get_int(char *message, int *variable) { // Fonction qui facilite la saisie des entiers avec gestion d'erreurs
    char input[500];
    printf("%s", message);
    fgets(input, sizeof(input), stdin);

    while (sscanf(input, "%d", variable) != 1) {
        printf("Entree invalide. Reessayez : ");
        fgets(input, sizeof(input), stdin);
    }
}

void get_string(char *message, char *variabe, int taille) { // Foction qui facilite la saisie des chaines de caractères
    printf("%s", message);
    fgets(variabe, taille, stdin);
    strtok(variabe, "\n");
}

// Fonctions de la phase 1
void load_data();
void enregCandidat(Candidat c);
void enregElecteur(Electeur e);

// Fonctions de la phase 2
void verifierCandidatures(Candidat candidat[], int n);
void retourner_liste_valide();

// Fonctions de la phase 3
void vote(Candidat *liste_candidats);
void check_elector_vote();
void count_votes(Candidat *liste_candidats);

// Fonctions de la phase 4
void trierCroissant(Candidat *liste_candidats);
void caution(Candidat *liste_candidats);

// Importation des fichiers
#include "phase1.c"
#include "phase2.c"
#include "phase3.c"
#include "phase4.c"

#endif

