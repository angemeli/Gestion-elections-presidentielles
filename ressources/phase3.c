#include <stdio.h>
#include <stdlib.h>

#include "ressources.h"

void check_electors_vote() {
     
}

void count_votes() {
    for (int i = 0; i < nb_candidates; i++) {
        Candidat candidat = liste_candidats_valides[i];
        for (int j = 0; j < liste_electeurs; j++) {
            Electeur electeur = liste_electeurs[j];
            if (candidat.id == electeur.vote) {
                candidat.nb_votes += 1;
            }
        }
        
        liste_candidats_valides[i] = candidat;   
    }
}