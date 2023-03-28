#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int allumettes = 0, choix = 0, tour = 1;
    srand(time(NULL)); // initialisation du générateur de nombres aléatoires

    printf("Bienvenue au jeu des allumettes !\n");
    do {
        printf("Combien d'allumettes voulez-vous pour commencer ? (nombre impair)\n");
        scanf("%d", &allumettes);
    } while (allumettes % 2 == 0); // on s'assure que le nombre d'allumettes est impair

    while (allumettes > 0) {
        printf("Tour %d - il reste %d allumettes\n", tour, allumettes);
        if (tour % 2 == 1) {
            // tour du joueur
            do {
                printf("Combien d'allumettes voulez-vous retirer ? (1, 2 ou 3)\n");
                scanf("%d", &choix);
            } while (choix < 1 || choix > 3 || choix > allumettes);
            allumettes -= choix;
            printf("Vous avez retiré %d allumettes.\n", choix);
        } else {
            // tour de l'ordinateur
            choix = rand() % 3 + 1; // choix aléatoire entre 1 et 3
            if (choix > allumettes) choix = allumettes;
            allumettes -= choix;
            printf("L'ordinateur a retiré %d allumettes.\n", choix);
        }
        tour++;
    }

    if (tour % 2 == 0) {
        printf("Vous avez perdu !\n");
    } else {
        printf("Vous avez gagné !\n");
    }

    return 0;
}
