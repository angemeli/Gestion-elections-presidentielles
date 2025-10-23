#include <stdio.h>
#include <stdlib.h>

#include "ressources.h"

int id_c = 1;
int id_e = 1;



//foction pour enregistrer un candidat
void enregCandidat(Candidat c) {
    c.id = id_c;
    FILE *f = fopen("candidats.csv", "a"); // "a" = append (ajoute à la fin du fichier)
    if (f == NULL) {
        perror("Erreur d'ouverture du fichier");
        return;
    }
    printf("Entrez le nom, l'âge et le parti du candidat :\n");
    scanf("%s %d %s", c.nom, &c.age, c.parti);
    // écriture d'une ligne CSV
    fprintf(f, "%d,%s,%d,%s\n",c.id, c.nom, c.age, c.parti);
    fclose(f);
    id_c++;
}


//foction pour enregistrer un electeur
void enregElecteur(Electeur e) {
    e.id = id_e;
    FILE *f = fopen("electeurs.csv", "a"); // "a" = append (ajoute à la fin du fichier)
    if (f == NULL) {
        perror("Erreur d'ouverture du fichier");
        return;
    }
    printf("Entrez le nom, l'âge et le quartier de l'electeur :\n");
    scanf("%s %d %s", e.nom, &e.age, e.quartier);
    
    if (e.age >= 21){
        fprintf(f, "%d,%s,%d,%s\n",e.id, e.nom, e.age, e.quartier);// écriture d'une ligne CSV
        fclose(f);
        id_e++;
    }else{
        printf("Pas en age de voter!\n");
    }
}
