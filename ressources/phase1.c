// ressources/phase1.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ressources.h" // contient les typedefs Candidat, Electeur, et les listes externes

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

// Vide le buffer stdin jusqu'au prochain \n (utile après scanf)
void viderBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

// Lit une ligne depuis stdin dans dest (taille size) et enlève le \n final
void lireLigne(char *dest, size_t size) {
    if (fgets(dest, (int)size, stdin) == NULL) {
        // Si fgets échoue, on met une chaîne vide
        dest[0] = '\0';
        return;
    }
    // supprime le \n final s'il existe
    dest[strcspn(dest, "\n")] = '\0';
}

// Supprime \n, \r et espaces de fin d'une chaîne (utile pour nettoyer les données lues depuis le fichier)
void nettoyerChaine(char *s) {
    int i = (int)strlen(s) - 1;
    while (i >= 0 && (s[i] == '\n' || s[i] == '\r' || s[i] == ' ' || s[i] == '\t')) {
        s[i] = '\0';
        i--;
    }
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
    double valSupp; // pour lire un champ supplémentaire (caution ou autre) -- double pour caution

    while (fgets(ligne, sizeof(ligne), f)) {
        // Si c’est le fichier des candidats (5 champs : id,nom,age,parti,caution)
        if (strstr(nomFichier, "candidat") != NULL) {
            if (sscanf(ligne, "%d,%99[^,],%d,%99[^,],%lf", &id, nomLu, &age, champLu, &valSupp) == 5) {
                nettoyerChaine(nomLu);
                nettoyerChaine(champLu);
                // compare avec les valeurs passées (nom et autreChamp)
                if (strcmp(nomLu, nom) == 0 && strcmp(champLu, autreChamp) == 0) {
                    fclose(f);
                    return 1; // doublon trouvé
                }
            }
        }
        // Si c’est le fichier des électeurs (4 champs : id,nom,age,quartier)
        else if (strstr(nomFichier, "electeurs") != NULL) {
            if (sscanf(ligne, "%d,%99[^,],%d,%99[^,]", &id, nomLu, &age, champLu) == 4) {
                nettoyerChaine(nomLu);
                nettoyerChaine(champLu);
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
    FILE *f = fopen("candidats.csv", "a");
    if (f == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    printf("Entrez le nom du candidat :\n");
    // vider le buffer au cas où il resterait un \n après une lecture précédente
    viderBuffer();
    lireLigne(c.nom, sizeof(c.nom));

    printf("Entrez l'âge du candidat :\n");
    // lecture numérique : scanf puis vider le \n restant
    if (scanf("%d", &c.age) != 1) {
        printf("Valeur d'age invalide.\n");
        fclose(f);
        viderBuffer();
        return;
    }
    viderBuffer();

    printf("Entrez le parti du candidat :\n");
    lireLigne(c.parti, sizeof(c.parti));

    printf("Entrez le montant de la caution payée par le candidat :\n");
    if (scanf("%lf", &c.caution) != 1) {
        printf("Valeur de caution invalide.\n");
        fclose(f);
        viderBuffer();
        return;
    }
    viderBuffer();

    // Nettoyage des champs (au cas où)
    nettoyerChaine(c.nom);
    nettoyerChaine(c.parti);

    if (existeDeja("candidats.csv", c.nom, c.parti)) {
        printf("\n⚠️  Ce candidat est déjà enregistré.\n");
        fclose(f);
        return;
    }

    int id_c = compterLignes("candidats.csv") + 1;
    c.id = id_c;

    // Ajout en mémoire (liste_candidats et nb_candidats doivent être définis dans ressources.h)
    liste_candidats[nb_candidats] = c;
    nb_candidats++;

    // Écriture dans le fichier CSV
    fprintf(f, "%d,%s,%d,%s,%.2f\n", c.id, c.nom, c.age, c.parti, c.caution);
    fclose(f);

    printf("\nLe candidat a été enregistré avec succès ! (ID : %d)\n", c.id);
}


// Fonction pour enregistrer un électeur
void enregElecteur(Electeur e) {
    FILE *f = fopen("electeurs.csv", "a"); // "a" = append (ajoute à la fin du fichier)
    if (f == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    printf("Entrez le nom de l'électeur :\n");
    viderBuffer();
    lireLigne(e.nom, sizeof(e.nom));

    printf("Entrez l'âge de l'électeur :\n");
    if (scanf("%d", &e.age) != 1) {
        printf("Valeur d'age invalide.\n");
        fclose(f);
        viderBuffer();
        return;
    }
    viderBuffer();

    printf("Entrez le quartier de l'électeur :\n");
    lireLigne(e.quartier, sizeof(e.quartier));

    // Nettoyage des champs (au cas où)
    nettoyerChaine(e.nom);
    nettoyerChaine(e.quartier);

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

        printf("\nL'électeur a été enregistré avec succès ! (ID : %d)\n", e.id);
    } else {
        printf("\nL'électeur n'est pas en âge de voter !\n");
        fclose(f);
    }
}
