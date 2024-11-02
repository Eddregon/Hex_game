//
// Created by Edgar on 31/05/2023.
//

#include "MyFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



//fonction qui demande a l'utilisateur parmi demarrer une partie, en reprendre une ou quitter et retourne la reponse: (D,R ou Q)
char menu(){
    char rep;

    //acquisition avec erreur de la variable rep
    printf ("\nQue voulez vous faire?\n   Demarrer une partie(D)\n   Reprendre une partie(R)\n   Quitter(Q)\n");
    scanf ("%c", &rep);
    getchar(); //evite au while suivant de se repeter une 2eme fois a cause du \n
    while (rep!='D' && rep!='R' && rep!='Q' && rep!='d' && rep!='r' && rep!='q'){
        printf ("\nVotre reponse ne fais pas partie des options\n");
        printf ("Que voulez vous faire?\n   Demarrer une partie(D)\n   Reprendre une partie(R)\n   Quitter(Q)\n");
        scanf ("%c", &rep);
    }

    printf ("votre reponse est %c \n", rep);

    return rep;
}



//on demande a l'utilisateur la taille du plateau entre 9 et 14 de cote
int taille_plateau(){
    int taille;

    printf ("\nChoisir une taille de plateau entre 9 et 14 de cote \n");
    scanf ("%d", &taille);
    while(taille<9 || taille>14){
        printf ("\nla taille choisi n'est valide \n");
        printf ("Choisir une taille de plateau entre 9 et 14 de cote \n");
        scanf ("%d", &taille);
    }

    printf ("votre plateau est de taille %dx%d\n", taille, taille);

    return taille;
}



//on initialise le plateau a '-'
void initialisation_plateau(char plateau[14][14], int taille){
    int ligne,colonne;

    for (ligne=0; ligne<taille; ligne++){
        for (colonne=0; colonne<taille; colonne++){
            plateau[ligne][colonne] = '-';
        }
    }
}



//fonction qui demande a l'utilisateur quelle type de jeu il veut jouer
char mode_jeu(){
    char mode;

    getchar();
    printf ("\nA quel mode de jeu voulez vous jouer?\n   Standard(S)\n   aleatoire(A)\n   Special(Z)\n");
    scanf ("%c", &mode);
    while (mode!= 'S' && mode!= 'A' && mode!= 'Z' && mode!= 's' && mode!= 'a' && mode!= 'z'){
        getchar();
        printf ("\nVotre reponse ne fais pas partie des options\n");
        printf ("A quel mode de jeu voulez vous jouer?\n   Standard(S)\n   aleatoire(A)\n   Special(Z)\n");
        scanf ("%c", &mode);
    }
    printf ("le mode choisi est %c\n", mode);

    return mode;
}



//fonction qui donne aleatoirement la couleur noir et blanche aux 2 joueurs
int tirage_aleatoire_couleur(char nom_1[100], char nom_2[100]){
    int couleur, len_nom;

    printf("\nvous allez donner les prenoms des 2 joueurs afin que chaque joueur puisse etre donne une couleur aleatoirement, sachant que les blancs commencent\n");
    getchar();

    //on demande le prenom 1
    printf ("donnez le prenom du 1er joueur:\n");
    fgets (nom_1,100,stdin);
    //on enleve le '\n' qui reste apres le prenom et on le remplace par '\0'
    len_nom = strlen (nom_1);
    nom_1[(len_nom - 1)] = '\0';

    //on demande le prenom 2
    printf ("donnez le prenom du 2eme joueur:\n");
    fgets (nom_2,100,stdin);
    //on enleve le '\n' qui reste apres le prenom et on le remplace '\0'
    len_nom = strlen (nom_2);
    nom_2[(len_nom - 1)] = '\0';

    //on choisi aleatoirement la valeur de couleur entre 1 et 2 afin de donner aleatoirement les 2 couleurs aux joueurs
    srand(time(0));
    couleur = rand()%2;

    if (couleur==0){
        printf("\n%s prend les pions noirs\n", nom_1);
        printf("%s prend les pions blancs\n", nom_2);
    }
    if (couleur==1){
        printf("\n%s prend les pions blancs\n", nom_1);
        printf("%s prend les pions noirs\n", nom_2);
    }
    return couleur;
}



//fonction qui place N pions de chaque couleur aleatoirement sur le plateau
void mode_aleatoire (char plateau[14][14], int taille){
    int N, i, ligne, colonne;

    N=(taille-1)/2;

    for (i=0; i<N; i++){
        ligne = rand()%taille;
        colonne = rand()%taille;
        while(plateau[ligne][colonne]!='-'){
            ligne = rand()%taille;
            colonne = rand()%taille;
        }
        plateau[ligne][colonne]='B';
    }

    for (i=0; i<N; i++){
        ligne = rand()%taille;
        colonne = rand()%taille;
        while(plateau[ligne][colonne]!='-'){
            ligne = rand()%taille;
            colonne = rand()%taille;
        }
        plateau[ligne][colonne]='N';
    }
}



//fonction qui determine a qui est le tour en fonction du nombre de pions sur le plateau
char a_qui_est_le_tour (char plateau[14][14], int taille){
    int nb_blanc=0, nb_noir=0, ligne, colonne;
    char tour;

    for (ligne=0; ligne<taille; ligne++){
        for (colonne=0; colonne<taille; colonne++){
            if (plateau[ligne][colonne]=='B'){
                nb_blanc++;
            }
        }
    }

    for (ligne=0; ligne<taille; ligne++){
        for (colonne=0; colonne<taille; colonne++){
            if (plateau[ligne][colonne]=='N'){
                nb_noir++;
            }
        }
    }

    printf("\n");
    if(nb_blanc<=nb_noir){
        printf("c'est au tour du blanc\n");
        tour = 'B';
    }
    if(nb_blanc>nb_noir){
        printf("c'est au tour du noir\n");
        tour = 'N';
    }

    return tour;
}



char choix_tour(char plateau[14][14], int taille, char tour, char nom_1[100], char nom_2[100], int couleur, char mode){
    char reponse;

    if(mode!='Z' && mode!='z'){
        printf ("que voulez vous faire?\n   Jouer(J)\n   Sauvegarder(S)\n   Quitter(X)\n");
        scanf ("%c", &reponse);
        getchar();
        while(reponse!='J' && reponse!='S' && reponse!='X' && reponse!='j' && reponse!='s' && reponse!='x') {
            printf("\nVotre reponse ne fais pas partie des options\n");
            printf("que voulez vous faire?\n   Jouer(J)\n   Sauvegarder(S)\n   Quitter(X)\n");
            scanf("%c", &reponse);
            getchar();
        }
    }

    if(mode=='Z' || mode=='z'){
        printf ("que voulez vous faire?\n   Jouer(J)\n   Sauvegarder(S)\n   Quitter(X)\n   Coup special(C)\n");
        scanf ("%c", &reponse);
        getchar();
        while(reponse!='J' && reponse!='S' && reponse!='X' && reponse!='j' && reponse!='s' && reponse!='x' && reponse!='C' && reponse!='c'){
            printf ("\nVotre reponse ne fais pas partie des options\n");
            printf ("que voulez vous faire?\n   Jouer(J)\n   Sauvegarder(S)\n   Quitter(X)\n   Coup special(C)\n");
            scanf ("%c", &reponse);
            getchar();
        }
    }

    if(reponse=='J' || reponse=='j'){
        choix_case (plateau, taille, tour);
    }

    if(reponse=='S' || reponse=='s'){
        printf ("appel de la fonction sauvegarde\n");
        sauvegarde (plateau, taille, nom_1, nom_2, couleur, mode);
    }

    if(reponse=='X' || reponse=='x'){
        printf ("fin de la partie\n");
    }
    if(mode=='Z' || mode=='z'){
        if(reponse=='C' || reponse=='c'){
            printf("appel de la fonction coup_special\n");
            coup_special(plateau, taille, tour);
        }
    }



    return reponse;
}



void choix_case(char plateau[14][14], int taille, char tour){
    int ligne, colonne;
    char lettre_colonne;

    printf ("quel case voulez vous jouer?\n");

    //on demande et acqueris, avec message d'erreur, la ligne de la case que l'utilisateur veut jouer
    printf ("numero de la ligne:\n");
    scanf ("%d", &ligne);
    ligne--; // ligne-- car la ligne x du plateau correspond a la ligne x-1 du tableau
    getchar();
    while (ligne<0 || ligne>taille){
        printf ("votre choix est incorrect\n");
        printf ("numero de la ligne:\n");
        scanf ("%d", &ligne);
        ligne--; // ligne-- car la ligne x du plateau correspond a la ligne x-1 du tableau
        getchar();
    }

    //on demande et acqueris, avec message d'erreur, la ligne de la case que l'utilisateur veut jouer
    printf ("lettre de la colonne:\n");
    scanf ("%c", &lettre_colonne);
    colonne = lettre_colonne-'a';
    getchar();
    while (colonne<0 || colonne>taille){
        printf ("votre choix est en dehors d\n");
        printf ("lettre de la colonne:\n");
        scanf ("%c", &lettre_colonne);
        colonne = lettre_colonne-'a';
        getchar();
    }

    verification_case(plateau, taille, tour, ligne, colonne);

}



//fonction qui verifie que la case chosi par le joueur n'est pas deja prise
void verification_case (char plateau[14][14], int taille, char tour, int ligne, int colonne){

    if (plateau[ligne][colonne]=='-'){
        plateau[ligne][colonne] = tour;
        affichage_plateau (plateau, taille);
    } else {
        printf ("\ncette case est deja prise, veuillez en prendre une autre\n");
        choix_case (plateau, taille, tour);
    }
}



//fonction dont la tache est d'afficher le plateau de jeu
void affichage_plateau (char plateau[14][14], int taille){
    int x, ligne, colonne, nb_espaces;

    tour_de_case_inutilisable(plateau, taille, 1);

    //on imprime la ligne avec les lettres pour chaque colonne du plateau
    printf("\n     ");
    for (x=0; x<taille; x++) {
        printf ("%c   ", 'a' + x);

    }
    printf("\n");
    for (ligne=0; ligne<taille; ligne++){

        //on affiche un espace de plus a chaque ligne pour donner l'effet du plateau hexagonal
        for (nb_espaces=0; nb_espaces<ligne; nb_espaces++){
            printf ("  ");
        }

        //on affiche un espace en plus quand il y a seulement 1 chiffre pour que les chiffres a gauche reste aligne
        if (ligne<9){
            printf (" ");
        }
        printf ("%d  ", ligne+1);

        for (colonne=0; colonne<taille; colonne++){

            printf (" %c  ", plateau[ligne][colonne]);
        }
        printf ("\n");
    }
}



// fonction de sauvegarde des paramètres dans un fixier txt
void sauvegarde (char plateau[14][14], int taille, char nom_1[100],char nom_2[100], int couleur, char mode) {

    FILE *fichier;
    fichier = fopen("sauvegarde.txt", "w");

    //on ecris la mode de jeu dans le fichier
    fprintf(fichier, "%c", mode);

    //on ecris la couleur dans le fichier
    fprintf (fichier, "%d", couleur);

    //on ecris le 1er prenom dans le fichier
    fprintf (fichier, "%s ", nom_1);

    //on ecris le 2eme prenom dans le fichier
    fprintf (fichier, "%s ", nom_2);

    //on ecris la taille du plateau dans le fichier
    fprintf (fichier, "%d", taille);

    //on ecris toutes les cases du plateau
    for (int ligne = 0; ligne < taille; ligne++) {
        for (int colonne = 0; colonne < taille; colonne++) {
            fprintf (fichier, "%c", plateau[ligne][colonne]);
        }
    }
    //fprintf (fichier, "\n%s%s",nom_1, nom_2);
    fclose (fichier);
    printf ("sauvegarde termine\n");
}



int reprendre_partie (char plateau[14][14], char *mode){
    int ligne, colonne, taille=0, couleur;
    char temporaire;
    FILE *fichier;

    fichier = fopen("sauvegarde.txt", "r");

    if (fichier != NULL){

    //on lit le mode
        fscanf(fichier, "%c", mode);

    //on lit la couleur
        fscanf(fichier,"%d",&couleur);

    //on lit le 1er prenom
        do {
            fscanf(fichier,"%c", &temporaire);
            printf("%c", temporaire);
        } while (temporaire!=' ');
        if(couleur==0){
            printf("prend les noirs\n");
        }
        if(couleur==1){
            printf("prend les blancs\n");
        }

    //on lit le 2eme prenom
        do {
            fscanf(fichier,"%c", &temporaire);
            printf("%c", temporaire);
        } while (temporaire!=' ');
        if(couleur==0){
            printf("prend les blancs\n");
        }
        if(couleur==1){
            printf("prend les noirs\n");
        }

    //on lit la taille du plateau
        fscanf(fichier,"%d", &taille);

    //on lit les emplacements du plateau
        for (ligne=0; ligne<taille; ligne++){
            for (colonne=0; colonne<taille; colonne++){
                fscanf(fichier,"%c", &temporaire);
                plateau[ligne][colonne] = temporaire;
            }
        }
    } else {
        //on est dans le cas ou le fichier est vide
        printf("Le fichier est vide\n");
    }
    return taille;
}








//fonction qui affiche un menu permettant de choisir un coup sepcial dans le cas d'un mode de jeu special
void coup_special(char plateau[14][14], int taille, char tour){
    char reponse;

    printf("\nQuel coup special voulez vous jouer?\n   Retirer(R)\n   Placer(P)\n   en Savoir plus(S)\n");
    scanf("%c", &reponse);
    getchar();
    while(reponse!='R' && reponse!='P' && reponse!='S' && reponse!='r' && reponse!='p' && reponse!='s'){
        printf ("\nVotre reponse ne fais pas partie des options\n");
        printf("Quel coup special voulez vous jouer?\n   Retirer (R)\n   Placer(P)\n   en Savoir plus(S)\n");
        scanf("%c", &reponse);
        getchar();
    }

    if(reponse=='R' || reponse=='r'){
        printf("on appele la fonction retirer_pion\n");
        retirer_pion(plateau, taille, tour);
    }

    if(reponse=='P' || reponse=='p'){
        printf("on appelle la fonction placer_2_pions\n");
        placer_2_pions(plateau, taille, tour);
    }

    if(reponse=='S' || reponse=='s'){
        printf("Le coup special 'Retirer' permet de retirer le pion adverse d'un case mais cette case devient inutilisable pour 3 tours\n");
        printf("Le coup special 'Placer' permet de placer 2 pions de suite mais ils ne doivent pas etre adjacents et votre prochain tour sera saute\n");
        coup_special(plateau, taille, tour);
    }
}


//fonction qui demande a l'utilisateur la case du pion a enlever
//avec verification de la ligne et de la colonne choisi pour eviter de sortir du plateau
void retirer_pion(char plateau[14][14], int taille, char tour){
    int ligne, colonne;
    char lettre_colonne;

    printf ("\nQuel pion voulez vous retirer?\n");

    //on demande et acqueris, avec message d'erreur, la ligne de la case que l'utilisateur veut jouer
    printf ("numero de la ligne:\n");
    scanf ("%d", &ligne);
    ligne--; // ligne-- car la ligne x du plateau correspond a la ligne x-1 du tableau
    getchar();
    while (ligne<0 || ligne>taille){
        printf ("Votre choix est en dehors du tableau\n");
        printf ("numero de la ligne:\n");
        scanf ("%d", &ligne);
        ligne--; // ligne-- car la ligne x du plateau correspond a la ligne x-1 du tableau
        getchar();
    }

    //on demande et acqueris, avec message d'erreur, la ligne de la case que l'utilisateur veut jouer
    printf ("lettre de la colonne:\n");
    scanf ("%c", &lettre_colonne);
    colonne = lettre_colonne-'a';
    getchar();
    while (colonne<0 || colonne>taille){
        printf ("Votre choix est en dehors du tableau\n");
        printf ("lettre de la colonne:\n");
        scanf ("%c", &lettre_colonne);
        colonne = lettre_colonne-'a';
        getchar();
    }

    verification_retirer_pion(plateau, taille, tour, ligne, colonne);
}


//cette fonction permet de verifier qu'il y a bien un pion adverse sur la case choisi, alors on initialise la case
void verification_retirer_pion (char plateau[14][14], int taille, char tour, int ligne, int colonne) {
    char pion_a_retirer;

    //si c'est le tour du joueur blanc, le pion a retirer sera noir
    // on va regarder si la case contient un pion du jouer noir
    if (tour == 'B') {
        pion_a_retirer='N';
    }
    //si c'est le tour du joueur noir, le pion a retirer sera blanc
    // on va regarder si la case contient un pion du jouer blanc
    if (tour == 'N'){
        pion_a_retirer='B';
    }

    //si la case contient un pion adverse
    //alors on initialise la case
    //sinon on redemande le case a l'utilisateur (en appelant retirer_pion)
    if (plateau[ligne][colonne] == pion_a_retirer) {
        plateau[ligne][colonne] = '4';
        affichage_plateau(plateau, taille);
    } else {
        printf("\ncette case ne contient pas de pion adverse, veuillez en prendre une autre\n");
        retirer_pion(plateau, taille, tour);
    }
}



void placer_2_pions(char plateau[14][14], int taille, char tour){
    int ligne_1, colonne_1, ligne_2, colonne_2, case_1=0, case_2=0, cases_adjacentes=1;
    char lettre_colonne_1, lettre_colonne_2;

    printf("\nAttention, les deux pions que vous allez poser ne peuvent pas etre adjacentes et votre prochain tour sera saute\n");

    while(cases_adjacentes==1){
        cases_adjacentes=0;

        //on demande pour la 1ere case
        while(case_1!=1){

            printf ("quel case voulez vous jouer en premier?\n");

            //on demande et acqueris, avec message d'erreur, la ligne de la case que l'utilisateur veut jouer
            printf ("numero de la ligne:\n");
            scanf ("%d", &ligne_1);
            ligne_1--; // ligne-- car la ligne x du plateau correspond a la ligne x-1 du tableau
            getchar();
            while (ligne_1<0 || ligne_1>taille){
                printf ("votre choix est en dehors du plateau\n");
                printf ("numero de la ligne:\n");
                scanf ("%d", &ligne_1);
                ligne_1--; // ligne-- car la ligne x du plateau correspond a la ligne x-1 du tableau
                getchar();
            }

            //on demande et acqueris, avec message d'erreur, la ligne de la case que l'utilisateur veut jouer
            printf ("lettre de la colonne:\n");
            scanf ("%c", &lettre_colonne_1);
            colonne_1 = lettre_colonne_1-'a';
            getchar();
            while (colonne_1<0 || colonne_1>taille){
                printf ("votre choix est en dehors du plateau\n");
                printf ("lettre de la colonne:\n");
                scanf ("%c", &lettre_colonne_1);
                colonne_1 = lettre_colonne_1-'a';
                getchar();
            }

            //on verifie que la case n'est pas prise
            if (plateau[ligne_1][colonne_1]=='-'){
                case_1=1; //pour noter que la case est libre
            } else {
                printf ("\ncette case est deja prise, veuillez en prendre une autre\n");
            }
        }
        printf("la case 1 est ligne %d, colonne %d\n", ligne_1, colonne_1);

        //on demande pour la 2nd case
        while(case_2!=1){

            printf ("quel case voulez vous jouer en deuxieme?\n");

            //on demande et acqueris, avec message d'erreur, la ligne de la case que l'utilisateur veut jouer
            printf ("numero de la ligne:\n");
            scanf ("%d", &ligne_2);
            ligne_2--; // ligne-- car la ligne x du plateau correspond a la ligne x-1 du tableau
            getchar();
            while (ligne_2<0 || ligne_2>taille){
                printf ("votre choix est en dehors du plateau\n");
                printf ("numero de la ligne:\n");
                scanf ("%d", &ligne_2);
                ligne_2--; // ligne-- car la ligne x du plateau correspond a la ligne x-1 du tableau
                getchar();
            }

            //on demande et acqueris, avec message d'erreur, la ligne de la case que l'utilisateur veut jouer
            printf ("lettre de la colonne:\n");
            scanf ("%c", &lettre_colonne_2);
            colonne_2 = lettre_colonne_2-'a';
            getchar();
            while (colonne_2<0 || colonne_2>taille){
                printf ("votre choix est en dehors du plateau\n");
                printf ("lettre de la colonne:\n");
                scanf ("%c", &lettre_colonne_1);
                colonne_2 = lettre_colonne_2-'a';
                getchar();
            }

            //on verifie que la case n'est pas prise
            if (plateau[ligne_2][colonne_2]=='-'){
                case_2=1; //pour noter que la case est libre
            } else {
                printf ("\ncette case est deja prise, veuillez en prendre une autre\n");
            }
        }
        printf("la case 2 est ligne %d, colonne %d\n", ligne_2, colonne_2);

        //on va maintenant verifier que les 2 cases ne sont pas adjacentes
        //si cases_adjacentes=1 alors les 2 cases sont adjacentes

        //plateau: case a gauche
        if(ligne_2 == ligne_1){
            if(colonne_2 == colonne_1-1){
                cases_adjacentes=1;
            }
        }

        //plateau: case a droite
        if(ligne_2 == ligne_1){
            if(colonne_2 == colonne_1+1){
                cases_adjacentes=1;
            }
        }

        //plateau: case en haut a droite
        if(ligne_2 == ligne_1-1){
            if(colonne_2 == colonne_1+1){
                cases_adjacentes=1;
            }
        }

        //plateau: case en haut a gauche
        if(ligne_2 == ligne_1-1){
            if(colonne_2 == colonne_1){
                cases_adjacentes=1;
            }
        }

        //plateau: case en bas a gauche
        if(ligne_2 == ligne_1+1){
            if(colonne_2 == colonne_1-1){
                cases_adjacentes=1;
            }
        }

        //plateau: case en bas a droite
        if(ligne_2 == ligne_1+1){
            if(colonne_2 == colonne_1){
                cases_adjacentes=1;
            }
        }

        if(cases_adjacentes==1){
            printf("vos deux cases sont adjacentes, recommencez a choisir vos deux case\n");
        }
    }

    //une fois que l'utilisateur a bien choisi deux cases non adjacentes
    plateau[ligne_1][colonne_1]=tour;
    plateau[ligne_2][colonne_2]=tour;

    affichage_plateau(plateau, taille);

    test_gagner(plateau, taille, tour);
}

void tour_de_case_inutilisable (char plateau[14][14], int taille, int valeur){
    int ligne, colonne;

    for (ligne=0; ligne<taille; ligne++){
        for(colonne=0; colonne<taille; colonne++){
            if(plateau[ligne][colonne] != '-' && plateau[ligne][colonne] != 'B' && plateau[ligne][colonne] != 'N'){
                if(plateau[ligne][colonne] == '1') {
                    printf("le caractere devient - normalement");
                    plateau[ligne][colonne] = '-';
                } else {
                    printf("on enleve 1 au caractere");
                    plateau[ligne][colonne] = plateau[ligne][colonne]-valeur;
                }

            }
        }
    }

}







/*
(B/N): Blanc puis noir, dans le cas ou il faut le faire une meme suite d'instructions mais legerement differente pour chaque couleur
Pour plus de clarte:
    - 5 lignes entre chaque partie
    - 3 lignes entre la partie blanche et la partie noire de chaque partie)
 *
Cette fonction a comme tache de tester si un des 2 joueurs a gagne (basee sur l'algorithme donne dans le sujet)
Cette fonction est reparti comme suit:
    - initialisation du nouveau tableau
    - 1ere PARTIE: Test de la 1ere colonne/ligne (B/N)
    - 2eme PARTIE: Test de chaque colonne/ligne avec verification de cases numerote autour (B/N)
    - 3eme PARTIE: Conclusion (B/N)
 *
On peux faire remarquer que le seul point faible de la fonction est dans le cas ou on revient sur nos pas,
En bref, si on fais une ligne en serpent
Alors la fonction ne dira pas au joueur qu'il a gagne meme si en realite la ligne rejoint le 2 cotes
*/
int test_gagner(char plateau[14][14], int taille, char tour){
    //j'ai mis les variables sur differentes lignes afin que ca soit plus lisible
    int ligne, colonne, win, minimum=100;
    int numerote_au_moins_1_case_B=0, numerote_au_moins_1_case_N=0;
    int case_numerote_derniere_colonne=0, case_numerote_derniere_ligne=0;
    int tableau_test[taille][taille];





//Initialisation a 0 de ce nouveau tableau
    for (ligne=0; ligne<taille; ligne++){
        for (colonne=0; colonne<taille; colonne++){
            tableau_test[ligne][colonne] = 0;
        }
    }





//1ere PARTIE: Test de la 1ere colonne/ligne (B/N)
    if (tour == 'B'){
        //on regarde si dans la 1ere colonne il y a des pions de la couleur Blanc
        //si oui on le note pour le demarrage de la 2eme PARTIE
        for (ligne=0; ligne<taille; ligne++){
            if(plateau[ligne][0] == 'B'){
                tableau_test[ligne][0] = 1;
                numerote_au_moins_1_case_B = 1;
            }
        }
    }



    if (tour == 'N'){
        //on regarde si dans la 1ere ligne il y a des pions de la couleur Noir
        //si oui on le note pour le demarrage de la 2eme PARTIE
        for (colonne=0; colonne<taille; colonne++){
            if (plateau[0][colonne] == 'N'){
                tableau_test[0][colonne] = 1;
                numerote_au_moins_1_case_N = 1;
            }
        }
    }





//2eme PARTIE: Test de chaque colonne/ligne avec verification de cases numerote autour (B/N)
    if (tour=='B'){
        //On regarde maintenant dans le plateau, chaque colonne et chaque ligne de chaque colonne pour tester si la case a la lettre B, si oui:
        //on cherche dans le tableau test les 6 cases autour si il y a une case numerote, et si oui on note le minimum
        //la case sera alors numerotee minimum+1
        if (numerote_au_moins_1_case_B == 1){
            for (colonne=1; colonne<taille; colonne++){
                //on fais une premiere fois, de haut en bas puis on fera une deuxieme fois, de bas en haut
                //cela permet de detecter les lignes qui vont de haut en bas mais aussi de bas en haut
                for (ligne=0; ligne<taille; ligne++){
                    if (plateau[ligne][colonne] == 'B'){
                        minimum = 100;

                        //maintenant on va tester si on a noté une ou plusieurs des 6 cases autour et en garder le minimum
                        //si aucun case autour n'as ete note on a min=100

                        //On teste si la case a gauche a ete numerote
                        if (tableau_test[ligne][colonne-1] != 0){
                            if (tableau_test[ligne][colonne-1] < minimum){
                                minimum = tableau_test[ligne][colonne-1];
                            }
                        }

                        //on teste si la case a droite a ete numerote
                        //boucle if pour eviter de prendre une valeur a droite du tableau
                        if (colonne!=taille-1) {
                            if (tableau_test[ligne][colonne+1] != 0) {
                                if (tableau_test[ligne][colonne+1] < minimum) {
                                    minimum = tableau_test[ligne][colonne+1];
                                }
                            }
                        }

                        //on teste si la case en haut a droite a ete numerote
                        //boucle if pour eviter de prendre une valeur a droite du tableau
                        if (colonne != taille-1){
                            //boucle if pour eviter de prendre une valeur au dessus du tableau
                            if (ligne != 0) {
                                if (tableau_test[ligne - 1][colonne + 1] != 0) {
                                    if (tableau_test[ligne - 1][colonne + 1] < minimum) {
                                        minimum = tableau_test[ligne - 1][colonne + 1];
                                    }
                                }
                            }
                        }

                        //boucle if pour eviter de prendre une valeur au dessus du tableau
                        if (ligne!=0){
                            //tableau: up, plateau: UP-LEFT
                            if (tableau_test[ligne-1][colonne] != 0){
                                if (tableau_test[ligne-1][colonne] < minimum) {
                                    minimum = tableau_test[ligne - 1][colonne];
                                }
                            }
                        }

                        //boucle if pour eviter de prendre une valeur en dessous du tableau
                        if (ligne!=taille) {
                            //tableau: bottom left, plateau: DOWN-LEFT
                            if (tableau_test[ligne + 1][colonne - 1] != 0) {
                                if (tableau_test[ligne + 1][colonne - 1] < minimum) {
                                    minimum = tableau_test[ligne + 1][colonne - 1];
                                }
                            }
                        }

                        //boucle if pour eviter de prendre une valeur en dessous du tableau
                        if (ligne!=taille) {
                            //tableau: down, plateau: DOWN-RIGHT
                            if (tableau_test[ligne+1][colonne]!=0){
                                if (tableau_test[ligne+1][colonne]<minimum){
                                    minimum = tableau_test[ligne+1][colonne];
                                }
                            }
                        }

                        //maintenant qu'on a determine le minimum, ou si il n'y a pas de case aux alentours min est egale a 100
                        //c'est pour ca qu'on teste si on a bien detecter une case avec le if suivant:
                        if (minimum!=100){
                            tableau_test[ligne][colonne] = minimum+1;
                            //on test si la case detecte fait partie de la derniere colonne
                            if (colonne==taille-1){
                                case_numerote_derniere_colonne = 1;
                            }
                        }
                    }
                }

                //on fais une deuxieme fois, de bas en haut
                for (ligne=taille-1; ligne>0; ligne--) {
                    if (plateau[ligne][colonne] == tour) {
                        minimum = 100;

                        //maintenant on va tester si on a noté une ou plusieurs des 6 cases autour et en garder le minimum
                        //si aucun case autour n'as ete note on a min=100

                        //tableau: left, plateau: LEFT
                        if (tableau_test[ligne][colonne - 1] != 0) {
                            if (tableau_test[ligne][colonne - 1] < minimum) {
                                minimum = tableau_test[ligne][colonne - 1];
                            }
                        }

                        //tableau: right, plateau: RIGHT
                        //boucle if pour eviter de prendre une valeur a droite du tableau
                        if (colonne != taille - 1) {
                            if (tableau_test[ligne][colonne + 1] != 0) {
                                if (tableau_test[ligne][colonne + 1] < minimum) {
                                    minimum = tableau_test[ligne][colonne + 1];
                                }
                            }
                        }

                        //tableau: top right, plateau: UP-RIGHT
                        //boucle if pour eviter de prendre une valeur a droite du tableau
                        if (colonne != taille - 1) {
                            //boucle if pour eviter de prendre une valeur au dessus du tableau
                            if (ligne != 0) {
                                if (tableau_test[ligne - 1][colonne + 1] != 0) {
                                    if (tableau_test[ligne - 1][colonne + 1] < minimum) {
                                        minimum = tableau_test[ligne - 1][colonne + 1];
                                    }
                                }
                            }
                        }

                        //boucle if pour eviter de prendre une valeur au dessus du tableau
                        if (ligne != 0) {
                            //tableau: up, plateau: UP-LEFT
                            if (tableau_test[ligne - 1][colonne] != 0) {
                                if (tableau_test[ligne - 1][colonne] < minimum) {
                                    minimum = tableau_test[ligne - 1][colonne];
                                }
                            }
                        }

                        //boucle if pour eviter de prendre une valeur en dessous du tableau
                        if (ligne != taille) {
                            //tableau: bottom left, plateau: DOWN-LEFT
                            if (tableau_test[ligne + 1][colonne - 1] != 0) {
                                if (tableau_test[ligne + 1][colonne - 1] < minimum) {
                                    minimum = tableau_test[ligne + 1][colonne - 1];
                                }
                            }
                        }

                        //boucle if pour eviter de prendre une valeur en dessous du tableau
                        if (ligne != taille) {
                            //tableau: down, plateau: DOWN-RIGHT
                            if (tableau_test[ligne + 1][colonne] != 0) {
                                if (tableau_test[ligne + 1][colonne] < minimum) {
                                    minimum = tableau_test[ligne + 1][colonne];
                                }
                            }
                        }

                        //maintenant qu'on a determine le minimum, ou si il n'y a pas de case aux alentours min est egale a 100
                        //c'est pour ca qu'on teste si on a bien detecter une case avec le if suivant:
                        if (minimum != 100) {
                            tableau_test[ligne][colonne] = minimum + 1;
                            //on test si la case detecte fait partie de la derniere colonne
                            if (colonne == taille - 1) {
                                case_numerote_derniere_colonne = 1;
                            }
                        }
                    }
                }
            }
        }
        //on peux placer ici une boucle pour afficher le tableau test si on veux
    }



    if (tour == 'N') {
        //On regarde maintenant dans le plateau, chaque ligne et chaque colonne de chaque ligne pour tester si la case a la lettre N, si oui:
        //on cherche dans le tableau test les 6 cases autour si il y a une case numerote, et si oui on note le minimum
        //la case sera alors numerotee minimum+1
        if (numerote_au_moins_1_case_N == 1) {

            //on fais une deuxieme fois avec ligne=1 et colonne=0 et continue tant que ligne<taille et colonne<taille
            //bref on parcours de haut en bas et de droite a gauche
            for (ligne = 1; ligne < taille; ligne++) {
                //on fais une premiere fois, de gauche a droite puis on fera une deuxieme fois, de droite a gauche
                for (colonne = 0; colonne < taille; colonne++) {
                    if (plateau[ligne][colonne] == 'N') {
                        minimum = 100;

                        //maintenant on va tester si on a noté une ou plusieurs des 6 cases autour et en garder le minimum
                        //si aucun case autour n'as ete note on a min=100

                        //tableau: left, plateau: LEFT
                        if (tableau_test[ligne][colonne-1] != 0) {
                            if (tableau_test[ligne][colonne-1] < minimum) {
                                minimum = tableau_test[ligne][colonne-1];
                            }
                        }

                        //tableau: right, plateau: RIGHT
                        //boucle if pour eviter de prendre une valeur a droite du tableau
                        if (colonne != taille - 1) {
                            if (tableau_test[ligne][colonne+1] != 0) {
                                if (tableau_test[ligne][colonne+1] < minimum) {
                                    minimum = tableau_test[ligne][colonne+1];
                                }
                            }
                        }

                        //tableau: top right, plateau: UP-RIGHT
                        //boucle if pour eviter de prendre une valeur a droite du tableau
                        if (colonne != taille-1) {
                            //boucle if pour eviter de prendre une valeur au dessus du tableau
                            if (ligne != 0) {
                                if (tableau_test[ligne-1][colonne+1] != 0) {
                                    if (tableau_test[ligne-1][colonne+1] < minimum) {

                                        minimum = tableau_test[ligne-1][colonne+1];
                                    }
                                }
                            }
                        }

                        //boucle if pour eviter de prendre une valeur au dessus du tableau
                        if (ligne != 0) {
                            //tableau: up, plateau: UP-LEFT
                            if (tableau_test[ligne-1][colonne] != 0) {
                                if (tableau_test[ligne-1][colonne] < minimum) {
                                    minimum = tableau_test[ligne-1][colonne];
                                }
                            }
                        }

                        //boucle if pour eviter de prendre une valeur en dessous du tableau
                        if (ligne != taille) {
                            //tableau: bottom left, plateau: DOWN-LEFT
                            if (tableau_test[ligne+1][colonne-1] != 0) {
                                if (tableau_test[ligne+1][colonne-1] < minimum) {
                                    minimum = tableau_test[ligne+1][colonne-1];
                                }
                            }
                        }

                        //boucle if pour eviter de prendre une valeur en dessous du tableau
                        if (ligne != taille) {
                            //tableau: down, plateau: DOWN-RIGHT
                            if (tableau_test[ligne+1][colonne] != 0) {
                                if (tableau_test[ligne+1][colonne] < minimum) {
                                    minimum = tableau_test[ligne+1][colonne];
                                }
                            }
                        }

                        //maintenant qu'on a determine le minimum, ou si il n'y a pas de case aux alentours min est egale a 100
                        //c'est pour ca qu'on teste si on a bien detecter une case avec le if suivant:
                        if (minimum != 100) {
                            tableau_test[ligne][colonne] = minimum + 1;
                            //on test si la case detecte fait partie de la derniere colonne
                            if (ligne == taille - 1) {
                                case_numerote_derniere_ligne = 1;
                            }
                        }
                    }
                }

                //on fais une deuxieme fois, de droite a gauche
                for (colonne = taille-1; colonne > 0; colonne--) {
                    if (plateau[ligne][colonne] == tour) {
                        minimum = 100;


                        //maintenant on va tester si on a noté une ou plusieurs des 6 cases autour et en garder le minimum
                        //si aucun case autour n'as ete note on a min=100

                        //tableau: left, plateau: LEFT
                        if (tableau_test[ligne][colonne-1] != 0) {
                            if (tableau_test[ligne][colonne-1] < minimum) {
                                minimum = tableau_test[ligne][colonne-1];
                            }
                        }

                        //tableau: right, plateau: RIGHT
                        //boucle if pour eviter de prendre une valeur a droite du tableau
                        if (colonne != taille-1) {
                            if (tableau_test[ligne][colonne+1] != 0) {
                                if (tableau_test[ligne][colonne+1] < minimum) {
                                    minimum = tableau_test[ligne][colonne+1];
                                }
                            }
                        }

                        //tableau: top right, plateau: UP-RIGHT
                        //boucle if pour eviter de prendre une valeur a droite du tableau
                        if (colonne != taille-1) {
                            //boucle if pour eviter de prendre une valeur au dessus du tableau
                            if (ligne != 0) {
                                if (tableau_test[ligne-1][colonne+1] != 0) {
                                    if (tableau_test[ligne-1][colonne+1] < minimum) {

                                        minimum = tableau_test[ligne-1][colonne+1];
                                    }
                                }
                            }
                        }

                        //boucle if pour eviter de prendre une valeur au dessus du tableau
                        if (ligne != 0) {
                            //tableau: up, plateau: UP-LEFT
                            if (tableau_test[ligne - 1][colonne] != 0) {
                                if (tableau_test[ligne - 1][colonne] < minimum) {
                                    minimum = tableau_test[ligne - 1][colonne];
                                }
                            }
                        }

                        //boucle if pour eviter de prendre une valeur en dessous du tableau
                        if (ligne != taille) {
                            //tableau: bottom left, plateau: DOWN-LEFT
                            if (tableau_test[ligne + 1][colonne - 1] != 0) {
                                if (tableau_test[ligne + 1][colonne - 1] < minimum) {
                                    minimum = tableau_test[ligne + 1][colonne - 1];
                                }
                            }
                        }

                        //boucle if pour eviter de prendre une valeur en dessous du tableau
                        if (ligne != taille) {
                            //tableau: down, plateau: DOWN-RIGHT
                            if (tableau_test[ligne+1][colonne] != 0) {
                                if (tableau_test[ligne+1][colonne] < minimum) {
                                    minimum = tableau_test[ligne+1][colonne];
                                }
                            }
                        }

                        //maintenant qu'on a determine le minimum, ou si il n'y a pas de case aux alentours min est egale a 100
                        //c'est pour ca qu'on teste si on a bien detecter une case avec le if suivant:
                        if (minimum != 100) {
                            tableau_test[ligne][colonne] = minimum+1;
                            //on test si la case detecte fait partie de la derniere colonne
                            if (ligne == taille-1) {
                                case_numerote_derniere_ligne = 1;
                            }
                        }
                    }
                }
            }
        }
        //on peux placer ici une boucle pour afficher le tableau test si on veux
    }





//3eme PARTIE: Conclusion (B/N)
    if (case_numerote_derniere_colonne == 1){
        win = 1;
        printf ("Le joueur Blanc a gagne\n");
    }

    if (case_numerote_derniere_ligne == 1){
        win = 1;
        printf ("Le joueur Noir a gagne\n");
    }

    if (case_numerote_derniere_colonne != 1 && case_numerote_derniere_ligne != 1){
        win = 0;
        printf ("le joueur n'a pas gagne\n");
    }

    return win;
}