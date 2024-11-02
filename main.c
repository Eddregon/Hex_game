#include <stdio.h>
#include "MyFunctions.h"

int main() {
    //definition des variables
    int taille, couleur, win=0;
    char reponse_menu, mode, tour, choix, nom_1[100], nom_2[100], rejouer='O';


    //boucle qui permet de rejouer a la fin de la partie
    while(rejouer=='O') {

        //menu initial avec 3 reponses possibles
        reponse_menu = menu();





        //REPONSE 1 au menu
        if (reponse_menu == 'Q' || reponse_menu == 'q') {
            printf("A bientot\n");
        }





        //REPONSE 2 au menu
        if (reponse_menu == 'D' || reponse_menu == 'd') {
            //fonction pour determiner la taille du plateau
            taille = taille_plateau();

            //on cree le tableau a 2 dimensions du plateau en fonction de la taille
            char Plateau[taille][taille];

            //on initialise le plateau a '-'
            initialisation_plateau(Plateau, taille);

            //fonction mode de jeu
            mode = mode_jeu();

            //affichage des regles
            printf("\nLe but du jeu est de creer une ligne avec ses pions sur le plateau de jeu, en posant tour a tour ses pions\n");
            printf("   - de gauche a droite pour le blanc\n   - de haut en bas pour le noir\n");
            printf("vous serez averti si un des joueurs a gagne\n");

            if (mode == 'Z' || mode == 'z') {
                printf("Avec ce mode vous pouvez effectuer 2 coups speciaux, vous pouvez en apprendre plus dans le menu des coups \n");
            }

            //fonction qui donne la couleur aleatoirement pour les 2 joueurs dans le cas du mode standard.
            couleur = tirage_aleatoire_couleur(nom_1, nom_2);

            //fonction mode_aleatoire pour poser N pions de chaque couleur dans le cas du mode Aleatoire
            if (mode == 'A' || mode == 'a') {
                mode_aleatoire(Plateau, taille);
            }

            //fonction qui affiche le plateau de jeu
            affichage_plateau(Plateau, taille);

            //boucle permettant de jouer tout simplement
            while (win != 1 && choix != 'X' && choix != 'x') {
                tour = a_qui_est_le_tour(Plateau, taille);

                choix = choix_tour(Plateau, taille, tour, nom_1, nom_2, couleur, mode);

                while (choix == 'S' || choix == 's') {
                    choix = choix_tour(Plateau, taille, tour, nom_1, nom_2, couleur, mode);
                }

                if (choix != 'X' && choix != 'x') {
                    win = test_gagner(Plateau, taille, tour);
                }
            }
        }





        //REPONSE 3 au menu

        if (reponse_menu == 'R' || reponse_menu == 'r') {

            char Plateau[14][14];

            taille = reprendre_partie(Plateau, &mode);

            printf("le mode est %c\n", mode);

            //Si on est dans le cas du mode special le coup retirer a peut etre ete utilise
            //Le probleme est que quand on affiche on enleve un tour aux cases inutilisable sans qu'un reel tour de jeu soit passe
            //Il faut donc monter de 1 les valeurs des cases inutilisables,
            //pour que quand le plateau soit affiche juste apres, que ca soit bien la valeur qui a ete sauvegarde
            if(mode=='z' || mode=='Z'){
                //on va appeler tour_de_case_inutilisable mais on va ajouter 1 au lieu d'enlever 1
                tour_de_case_inutilisable(Plateau, taille, -1);
            }

            affichage_plateau(Plateau, taille);

            //boucle permettant de jouer tout simplement
            while (win != 1 && choix != 'X' && choix != 'x') {
                tour = a_qui_est_le_tour(Plateau, taille);

                choix = choix_tour(Plateau, taille, tour, nom_1, nom_2, couleur, mode);

                while (choix == 'S' || choix == 's') {
                    choix = choix_tour(Plateau, taille, tour, nom_1, nom_2, couleur, mode);
                }

                if (choix != 'X' && choix != 'x') {
                    win = test_gagner(Plateau, taille, tour);
                }
            }
        }

        //acquisition avec erreur de la variable rejouer afin de determiner si l'utilisateur veux faire une partie
        printf("Voulez vous refaire une partie? (O/N)\n");
        scanf("%c", &rejouer);
        getchar();
        while (rejouer != 'O' && rejouer != 'o' && rejouer != 'N' && rejouer != 'n') {
            printf("Votre reponse est incorrecte\n");
            printf("Voulez vous refaire une partie? (O/N)\n");
            scanf("%c", &rejouer);
            getchar();
        }
    }

    return 0;
}