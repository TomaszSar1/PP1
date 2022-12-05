#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#include "Czesio.c"
int is_prime(int a){
    int pom = 0;
    for (int i = 1; i <= a;i++) {
        if(a%i == 0) {
            pom++;
            if(pom == 2 && i == a){
                return 1;
            }
        }
    }
    return 0;
}
int tab[5][5] = {0};
int pom[5][5] = {0};
int wyn[50][2] = {0};
int main(){
    czesc("czesio");
    printf("Podaj liczby\n");
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if(scanf("%d",&tab[i][j])!=1){
                printf("Incorrect input\n");
                return 1;
            }
        }
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            pom[i][j] = is_prime(tab[i][j]);
        }
    }
    int ile_sasiadow = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int x = 0;
            if(is_prime(tab[i][j])) {
                if (pom[i - 1][j - 1] == 1) x++;
                if (pom[i - 1][j] == 1) x++;
                if (pom[i - 1][j + 1] == 1) x++;
                if (pom[i][j - 1] == 1) x++;
                if (pom[i][j + 1] == 1) x++;
                if (pom[i + 1][j - 1] == 1) x++;
                if (pom[i + 1][j] == 1) x++;
                if (pom[i + 1][j + 1] == 1) x++;
                ile_sasiadow += x;
            }
        }
    }
    int wyniki = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if(is_prime(tab[i][j])==1){
                wyn[wyniki][0] = i;
                wyn[wyniki][1] = j;
                wyniki++;
            }
        }
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("%d ",pom[i][j]);
        }
        printf("\n");
    }
    printf("%d\n",ile_sasiadow/2);
    for (int i = 0; i < wyniki; ++i) {
        printf("%d %d ",wyn[i][0],wyn[i][1]);
        if(i%2==1) printf("\n");
    }
    return 0;
}