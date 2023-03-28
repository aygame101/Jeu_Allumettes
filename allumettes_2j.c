#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int allumettes = 0, choix = 0, tour = 1;
    // srand(time(NULL)); // initialisation du générateur de nombres aléatoires

    printf("Bienvenue au jeu des allumettes !\n");
    do {
        printf("Combien d'allumettes voulez-vous pour commencer ? (nombre impair)\n");
        scanf("%d", &allumettes);
    } while (allumettes % 2 == 0); // on s'assure que le nombre d'allumettes est impair

    while (allumettes > 0) {
        printf("Tour %d - il reste %d allumettes\n", tour, allumettes);
        if (tour % 2 == 1) {
            // tour du joueur 1
            do {
                printf("J1 - Combien d'allumettes voulez-vous retirer ? (1, 2 ou 3)\n");
                scanf("%d", &choix);
            } while (choix < 1 || choix > 3 || choix > allumettes);
            allumettes -= choix;
            printf("J1 a retiré %d allumettes.\n", choix);
        } else {
            // tour du joueur 2
            do {
                printf("J2 - Combien d'allumettes voulez-vous retirer ? (1, 2 ou 3)\n");
                scanf("%d", &choix);
            } while (choix < 1 || choix > 3 || choix > allumettes);
            allumettes -= choix;
            printf("J2 a retiré %d allumettes.\n", choix);
        }
        tour++;
    }

    if (tour % 2 == 0) {
        printf("J2 a gagné !\n");
    } else {
        printf("J1 a gagné !\n");
    }

    return 0;
}
