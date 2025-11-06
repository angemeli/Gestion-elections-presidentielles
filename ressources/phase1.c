#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ressources.h"

// Fonction pour compter le nombre de lignes dans le fichier .csv
int compterLignes(const char *nomFichier) {
    FILE *f = fopen(nomFichier, "r");
    if (f == NULL) {
        // Si le fichier n'existe pas encore, on considère qu'il y a 0 lignes
        return 0;
    }

    int count = 0;
    char ligne[500];
    while (fgets(ligne, sizeof(ligne), f)) {
        // Ignore les lignes vides
        if (ligne[0] != '\n' && ligne[0] != '\0')
            count++;
    }

    fclose(f);
    return count;
}

// Fonction générique pour vérifier si un candidat ou un électeur existe déjà
int existeDeja(const char *nomFichier, const char *nom, const char *autreChamp) {
    FILE *f = fopen(nomFichier, "r");
    if (f == NULL) {
        // Si le fichier n'existe pas encore, personne n'est enregistré
        return 0;
    }

    char ligne[500];
    char nomLu[100], champLu[100];
    int id, age;
    int valSupp; // pour lire un champ supplémentaire (caution ou autre)

    while (fgets(ligne, sizeof(ligne), f)) {
        // Si c’est le fichier des candidats (5 champs)
        if (strstr(nomFichier, "candidat") != NULL) {
            if (sscanf(ligne, "%d,%99[^,],%d,%99[^,],%d", &id, nomLu, &age, champLu, &valSupp) == 5) {
                if (strcmp(nomLu, nom) == 0 && strcmp(champLu, autreChamp) == 0) {
                    fclose(f);
                    return 1; // doublon trouvé
                }
            }
        }
        // Si c’est le fichier des électeurs (4 champs)
        else if (strstr(nomFichier, "electeurs") != NULL) {
            if (sscanf(ligne, "%d,%99[^,],%d,%99[^,]", &id, nomLu, &age, champLu) == 4) {
                if (strcmp(nomLu, nom) == 0 && strcmp(champLu, autreChamp) == 0) {
                    fclose(f);
                    return 1; // doublon trouvé
                }
            }
        }
    }

    fclose(f);
    return 0; // aucun doublon trouvé
}

void enregCandidat(Candidat c) {
    FILE *f = fopen("candidats.csv", "a"); // nom du fichier corrigé
    if (f == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    printf("Entrez le nom, l'age, le parti et le montant de la caution payee par le candidat :\n");
    scanf("%s %d %s %lf", c.nom, &c.age, c.parti, &c.caution);

    // Vérifie si ce candidat existe déjà (même nom et même parti)
    if (existeDeja("candidats.csv", c.nom, c.parti)) {
        printf("\n⚠️  Ce candidat est déjà enregistré.\n");
        fclose(f);
        return;
    }

    // Compter le nombre de candidats déjà enregistrés dans candidat.csv
    int id_c = compterLignes("candidats.csv") + 1;
    c.id = id_c;

    // Ajout du candidat dans la liste en mémoire
    liste_candidats[nb_candidats] = c;
    nb_candidats += 1;

    // Écriture dans le fichier CSV
    fprintf(f, "%d,%s,%d,%s,%lf\n", c.id, c.nom, c.age, c.parti, c.caution);
    fclose(f);

    printf("\nLe candidat a ete enregistre avec succes ! (ID : %d)\n", c.id);
}

// Fonction pour enregistrer un électeur
void enregElecteur(Electeur e) {
    FILE *f = fopen("electeurs.csv", "a"); // "a" = append (ajoute à la fin du fichier)
    if (f == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    printf("Entrez le nom, l'age et le quartier de l'electeur :\n");
    scanf("%s %d %s", e.nom, &e.age, e.quartier);

    if (e.age >= 21) {
        // Vérifie si l’électeur existe déjà (même nom et même quartier)
        if (existeDeja("electeurs.csv", e.nom, e.quartier)) {
            printf("\n⚠️  Cet électeur est déjà enregistré.\n");
            fclose(f);
            return;
        }
        // Calcul de l'ID selon le nombre de lignes déjà enregistrées
        int id_e = compterLignes("electeurs.csv") + 1;
        e.id = id_e;

        // Ajout de l'électeur à la liste en mémoire
        liste_electeurs[nb_electeurs] = e;
        nb_electeurs++;

        // Écriture dans le fichier CSV
        fprintf(f, "%d,%s,%d,%s\n", e.id, e.nom, e.age, e.quartier);
        fclose(f);

        printf("\nL'electeur a ete enregistre avec succes ! (ID : %d)\n", e.id);
    } else {
        printf("\nL'electeur n'est pas en age de voter !\n");
        fclose(f);
    }
}
