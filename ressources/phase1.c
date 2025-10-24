#include <stdio.h>
#include <stdlib.h>

#include "ressources.h"

//foction pour enregistrer un candidat
void enregCandidat(Candidat c) {
    FILE *f = fopen("candidats.csv", "a"); // "a" = append (ajoute à la fin du fichier)
    if (f == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }
    printf("Entrez le nom, l'age, le parti et le montant de la caution payee par le candidat :\n");
    scanf("%s %d %s %d",c.nom, &c.age, c.parti, &c.caution);

    // Ajout du candidat à la liste des candidats du programme (la liste qui sera utilisée dans les autres fonctions du programme)
    c.id = nb_candidats + 1;
    liste_candidats[nb_candidats] = c;
    nb_candidats += 1;

    // écriture d'une ligne CSV
    fprintf(f, "%d,%s,%d,%s,%d\n", c.id, c.nom, c.age, c.parti, c.caution);
    fclose(f);

    printf("\nLe candidat a ete enregistre avec succes\n");
}

//foction pour enregistrer un electeur
void enregElecteur(Electeur e) {
    FILE *f = fopen("electeurs.csv", "a"); // "a" = append (ajoute à la fin du fichier)
    if (f == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }
    printf("Entrez le nom, l'age et le quartier de l'electeur :\n");
    scanf("%s %d %s", e.nom, &e.age, e.quartier);
    
    if (e.age >= 21){
        // Ajout de l'electeur à la liste des candidats du programme (la liste qui sera utilisée dans les autres fonctions du programme)
        e.id = nb_electeurs + 1;
        liste_electeurs[nb_electeurs] = e;
        nb_electeurs += 1;

        fprintf(f, "%d,%s,%d,%s\n",e.id, e.nom, e.age, e.quartier);// écriture d'une ligne CSV
        fclose(f);

        printf("\nL'electeur a ete enregistre avec succes\n");
    }else{
        printf("\nLe candidat n'est pas en age de voter !\n");
    }
}
