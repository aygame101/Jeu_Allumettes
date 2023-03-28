#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int allumettes = 0, choix = 0, tour = 1;
    char* jun = "";
    char* jdeux = "";
    // srand(time(NULL)); // initialisation du générateur de nombres aléatoires

    printf("Pseudo du 1er joueur ?\n");
    scanf("%s", &jun);
    printf("Pseudo du 2eme joueur ?\n");
    scanf("%s", &jdeux);
    printf("Bienvenue au jeu des allumettes !\n");
    do {
        printf("Combien d'allumettes voulez-vous pour commencer ? (nombre impair)\n");
        scanf("%d", &allumettes);
    } while (allumettes % 2 == 0); // on s'assure que le nombre d'allumettes est impair

    while (allumettes > 0) {
        printf("Tour %d - il reste %d allumette(s)\n", tour, allumettes);
        if (tour % 2 == 1) {
            // tour du joueur 1
            do {
                printf("%s - Combien d'allumette(s) voulez-vous retirer ? (1, 2 ou 3)\n", &jun);
                scanf("%d", &choix);
            } while (choix < 1 || choix > 3 || choix > allumettes);
            allumettes -= choix;
            printf("%s a retiré %d allumettes.\n", &jun, choix);
        } else {
            // tour du joueur 2
            do {
                printf("%s - Combien d'allumette(s) voulez-vous retirer ? (1, 2 ou 3)\n", &jdeux);
                scanf("%d", &choix);
            } while (choix < 1 || choix > 3 || choix > allumettes);
            allumettes -= choix;
            printf("%s a retiré %d allumette(s).\n", &jdeux, choix);
        }
        tour++;
    }

    if (tour % 2 == 0) {
        printf("%s a gagné !\n", &jdeux);
    } else {
        printf("%s a gagné !\n", &jun);
    }

    return 0;
}
