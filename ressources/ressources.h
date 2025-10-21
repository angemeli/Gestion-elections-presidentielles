#ifndef _ce_mot_est_unique_dans_tout_le_programme_
#define  _ce_mot_est_unique_dans_tout_le_programme_

// Structures globales
typedef struct{
    int id;
    char nom[500];
    int age;
    char parti[20];
    int nb_votes;
} Candidat;

typedef struct{
    int id;
    char nom[500];
    int age;
    char quartier[20];
    int vote;
} Electeur;

// Variables globales
int nb_candidats = 0;
int nb_electeurs = 0;
Candidat liste_candidats[100];
Electeur liste_electeurs[500];

// Fonctions de la phase 1
void load_data();
void enregCandidat();
void enregElecteur();

// Fonctions de la phase 2

// Fonctions de la phase 3
void vote();
void count_votes();

// Fonctions de la phase 4


// Importation des fichiers
#include "phase1.c"
#include "phase2.c"
#include "phase3.c"
#include "phase4.c"

#endif
