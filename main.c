#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

const int MAX_SIZE = 1000;

int sort_by_length(char tab[]){
    if (tab == NULL)
        return 1;

    int n = strlen(tab);

    if (n == 0)
        return 1;

    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (strcmp(tab + i, tab + j) < 0){
                char tmp[MAX_SIZE];
                strcpy(tmp, tab + i);
                strcpy(tab + i, tab + j);
                strcpy(tab + j, tmp);
            }
        }
    }

    return 0;
}

int main(){
    char tab[MAX_SIZE];

    printf("Podaj tekst:\n");

    if (fgets(tab, MAX_SIZE, stdin) == NULL){
        printf("Incorrect input data\n");
        return 2;
    }

    if (sort_by_length(tab) != 0){
        printf("Incorrect input data\n");
        return 2;
    }

    printf("%s\n", tab);

    return 0;
}