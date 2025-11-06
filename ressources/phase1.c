// ressources/phase1.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ressources.h" // contient les typedefs Candidat, Electeur, et les listes externes

void load_data() { // Fonction pour charger les données depuis les fichiers
    // Fichier des candidats
    FILE *f = fopen("candidats.csv", "r");
    if (f == NULL) {
        perror("Erreur lors de l'ouverture du fichier des candidats pour le chargement des donnees");
        return;
    }

    Candidat c;
    while (fscanf(f, "%d,%49[^,],%d,%49[^,],%d\n", &c.id, c.nom, &c.age, c.parti, &c.caution) == 5) {
        liste_candidats[nb_candidats] = c;
        nb_candidats += 1;
    }
    fclose(f);
    
    // Fichier des électeurs
    f = fopen("electeurs.csv", "r");
    if (f == NULL) {
        perror("Erreur lors de l'ouverture du fichier des electeurs pour le chargement des donnees");
        return;
    }

    Electeur e;
    while (fscanf(f, "%d,%49[^,],%d,%49[^\n]\n", &e.id, e.nom, &e.age, e.quartier) == 4) {
        liste_electeurs[nb_electeurs] = e;
        nb_electeurs += 1;
    }
    fclose(f);
}

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
int existeDeja(const char *nomFichier, const char *nom, const int age, const char *autreChamp) {
    if (nomFichier == "candidats.csv") {
        for (int i = 0; i < nb_candidats; i++) {
            if (nom == liste_candidats[i].nom && age == liste_candidats[i].age && autreChamp == liste_candidats[i].parti) {
                return 1; // Doublon trouvé
            }
        }
    }

    else if (nomFichier == "electeurs.csv") {
        for (int i = 0; i < nb_electeurs; i++) {
            if (nom == liste_electeurs[i].nom && age == liste_electeurs[i].age && autreChamp == liste_electeurs[i].quartier) {
                return 1; // Doublon trouvé
            }
        }
    }
    
    return 0; // aucun doublon trouvé
}

void enregCandidat(Candidat c) {
    FILE *f = fopen("candidats.csv", "a");
    if (f == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    printf("Entrez les informations sur le nouveau candidat\n");
    get_string("\nNom : ", c.nom, sizeof(c.nom));
    get_int("Age : ", &c.age);
    get_string("Parti politique : ", c.parti, sizeof(c.parti));
    get_int("Montant de la caution : ", &c.caution);

    /* viderBuffer();

    // Nettoyage des champs (au cas où)
    nettoyerChaine(c.nom);
    nettoyerChaine(c.parti); */

    // Vérifie si ce candidat existe déjà (même nom, même âge et même parti)
    if (existeDeja("candidats.csv", c.nom, c.age, c.parti)) {
        printf("\n⚠️  Ce candidat est deja enregistre.\n");
        fclose(f);
        return;
    }

    // Attribution automatique d'un id au canddat
    c.id = nb_candidats + 1;

    // Ajout du candidat dans la liste en mémoire
    liste_candidats[nb_candidats] = c;
    nb_candidats += 1;

    // Écriture dans le fichier CSV
    fprintf(f, "%d,%s,%d,%s,%d\n", c.id, c.nom, c.age, c.parti, c.caution);
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

    printf("Entrez les informations sur le nouvel electeur\n");
    get_string("\nNom : ", e.nom, sizeof(e.nom));
    get_int("Age : ", &e.age);
    get_string("Quartier de residence : ", e.quartier, sizeof(e.quartier));
    
    /* viderBuffer();
    // Nettoyage des champs (au cas où)
    nettoyerChaine(e.nom);
    nettoyerChaine(e.quartier); */

    if (e.age >= 21) {
        // Vérifie si l’électeur existe déjà (même nom et même quartier)
        if (existeDeja("electeurs.csv", e.nom, e.age, e.quartier)) {
            printf("\n⚠️  Cet électeur est déjà enregistré.\n");
            fclose(f);
            return;
        }
        // Attribution automatique d'un id a l'electeur
        e.id = nb_electeurs + 1;

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
