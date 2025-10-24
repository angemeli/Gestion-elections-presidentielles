# **Gestion elections presidentielles**
 Programme en C qui simule un système de gestion des élections présidentielles au Cameroun

## **Principe**
Un candidat est caractérisé par son id unique, son nom, son âge et son parti politique. Un électeur quant-à lui est caractérisé par son id, son nom, son âge et son quartier de résidence. On sait qu'un électeur ne peut voter que pour un et un seul candidat, et chaque candidat doit voter pour lui-même.

Les candidats sont enregistrés dans un fichier .csv, de même que les électeurs (afin d'éviter d'entrer les informations chaque fois qu'on lance le programme). Lorsqu'un nouveau candidat ou un nouvel électeur est enregistré, il est simplement ajouté dans le fichier correspondant.

Le programme parcourt chaque électeur, identifie son vote et l'attribue au candidat correspondant. Il comptabilise ensuite les votes de chaque candidat et range ceux-ci par ordre croissant de votes, puis détermine les candidats dont les cautions doivent être remboursées.

## **Fonctions du programme**

**Phase 1 : Enregistrement des candidats et des électeurs**
- Une fonction permettant d'enregistrer les candidats (Un candidat ne peut être enregistré qu'une seule fois)
- Une fonction permettant d'enregistrer les électeurs (Un électeur ne peut être enregistré qu'une seule fois)

**Phase 2 : Evaluation des candidatures**
- Une fonction qui évalue la validité de chaque candidature et affiche le résultat de l'évaluation

**Phase 3 : Vote et comptabilisation**
- Une fonction qui permet d'effectuer les votes
- Une fonction qui affiche pour un électeur s'il a voté ou pas
- Une fonction qui comptabilise les votes pour chaque candidat

**Phase 4 : Affichage des résultats**
- Une fonction qui range les candidats par ordre croissant de nombre de votes
- Une fonction qui affiche les candidats dont la caution doit être remboursée
