#include <stdio.h>
#include <stdlib.h>

#include "ressources.h"

//foction pour enregistrer un candidat
void enregCandidat() {
    Candidat c;
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
void enregElecteur() {
    Electeur e;
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
