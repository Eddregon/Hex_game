//
// Created by Edgar on 31/05/2023.
//

#ifndef BARRIOS_BELLEMERE_MYFUNCTIONS_H
#define BARRIOS_BELLEMERE_MYFUNCTIONS_H

char menu ();

int taille_plateau ();

void initialisation_plateau (char plateau[14][14], int taille);

char mode_jeu ();

int tirage_aleatoire_couleur (char nom_1[100], char nom_2[100]);

void mode_aleatoire (char plateau[14][14], int taille);



char a_qui_est_le_tour(char plateau[14][14], int taille);



char choix_tour (char plateau[14][14], int taille, char tour, char nom_1[100], char nom_2[100], int couleur, char mode);

void choix_case (char plateau[14][14], int taille, char tour);

void verification_case (char plateau[14][14], int taille, char tour, int ligne, int colonne);

void affichage_plateau (char[14][14], int taille);



void sauvegarde (char plateau[14][14], int taille, char nom_1[100], char nom_2[100], int couleur, char mode);

int reprendre_partie (char plateau[14][14], char *mode);



void coup_special (char plateau[14][14], int taille, char tour);

void retirer_pion (char plateau[14][14], int taille, char tour);

void verification_retirer_pion (char plateau[14][14], int taille, char tour, int ligne, int colonne);

void placer_2_pions(char plateau[14][14], int taille, char tour);

void tour_de_case_inutilisable(char plateau[14][14], int taille, int valeur);



int test_gagner (char plateau[14][14], int taille, char tour);

#endif //BARRIOS_BELLEMERE_MYFUNCTIONS_H