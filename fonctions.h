#ifndef _ce_mot_est_unique_dans_tout_le_programme_
#define  _ce_mot_est_unique_dans_tout_le_programme_

typedef struct{
    int id;
    char nom[500];
    int age;
    char parti[20];
} Candidat ;

typedef struct{
    int id;
    char nom[500];
    int age;
    char quartier[20];
}Electeur ;

void enregCandidat(Candidat c);
void enregElecteur(Electeur e);
void Menu(void);
void BoucleDuProgramme(void);

#endif