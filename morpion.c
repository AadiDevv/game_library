#include <stdio.h>
#include <stdlib.h>
#include "morpion.h"


void morpion()
{
    printf("\t\n\n------ MORPION ------\n\n");

        char grille[3][3]=
    {
       {'.','.','.'},
       {'.','.','.'},
       {'.','.','.'}
    };

    int fin_partie=0;
    char joueur = 'X';
    int coord_x, coord_y;

    do
    {
        dessinerGrille(grille);
        saisieUtilisateur(grille, joueur, &coord_x, &coord_y);

        //test de la grille
        if(victoire(grille, joueur) == 1)
        {
            printf("\n\n-- VICTOIRE DU JOUEUR %c --\n\n", joueur);
            dessinerGrille(grille);
            fin_partie = 1;
        }
        else if(grillePleine(grille) == 1)
        {
            printf("\n\n-- MATCH NUL --\n\n");
            dessinerGrille(grille);
            fin_partie = 1;
        }
        else
        {
            if(joueur == 'X') joueur = 'O';
            else joueur = 'X';
        }

    }while(fin_partie != 1);
}



void dessinerGrille(char grille[][3])
{
    for(int x=0; x <3; x++)
    {
        printf("|%c|%c|%c|\n", grille[x][0], grille[x][1], grille[x][2]);
    }
}


void saisieUtilisateur(char grille[][3], char joueur, int* p_coord_x, int* p_coord_y)
{
    do
    {
        printf("\n< Joueur %c > Ou voullez-vous jouer?\n", joueur);

        fflush(stdin);
        printf("en x:");
        scanf("%d", p_coord_x);
        printf("en y:");
        scanf("%d", p_coord_y);
    }while(saisieValide(grille, *p_coord_x, *p_coord_y) == 0);
    grille[*p_coord_y-1][*p_coord_x-1] = joueur;
}


int saisieValide(char grille[][3], int coord_x, int coord_y )
{
    // test si les coordonnées sont comprise dans la taille du morpion
    if(coord_x <=0 || coord_x > 3 || coord_y <=0 || coord_y > 3)
    {
        printf("Coordonnees invalides!\n");
        return 0;
    }

    // test si case libre
    if(grille[coord_y-1][coord_x-1] != '.')
    {
        printf("Case deja occupee!\n");
        return 0;
    }

    return 1;
}

int victoire(char grille[][3], char joueur)
{
    // test des lignes
    for(int x=0; x<3; x++)
    {
        if(grille[x][0] == joueur && grille[x][1] == joueur && grille[x][2] == joueur)
            return 1;
    }

    // test des colonnes
    for(int y=0; y<3; y++)
    {
        if(grille[0][y] == joueur && grille[1][y] == joueur && grille[2][y] == joueur)
            return 1;
    }

    //test de la diagonale
    if(grille[0][0] == joueur && grille[1][1] == joueur && grille[2][2] == joueur)
        return 1;

    //test de la diagonale inverse
    if(grille[2][0] == joueur && grille[1][1] == joueur && grille[0][2] == joueur)
        return 1;


    return 0;
}

int grillePleine(char grille[][3])
{
    for(int x=0; x<3; x++)
    {
        for(int y=0; y<3; y++)
        {
            if(grille[x][y] == '.') return 0;
        }
    }

    return 1;
}

