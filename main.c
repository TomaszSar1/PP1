#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
int concat_begin(const int first[], int size, const int second[], int size2, int dest[], int size3) {
    if (size + size2 > size3) return -2;
    for (int i = 0; i < size2; i++) dest[i] = second[i];
    for (int i = 0; i < size; i++) dest[size2 + i] = first[i];
    return size + size2;
}
int concat_end(const int first[], int size, const int second[], int size2, int dest[], int size3) {
    if (size + size2 > size3) return -2;
    for (int i = 0; i < size; i++) dest[i] = first[i];
    for (int i = 0; i < size2; i++) dest[size + i] = second[i];
    return size + size2;
}

int concat_zip(const int first[], int size, const int second[], int size2, int dest[], int size3) {
    if (size + size2 > size3) return -2;
    for (int i = 0; i < size; i++) dest[i * 2] = first[i];
    for (int i = 0; i < size2; i++) dest[i * 2 + 1] = second[i];
    return size + size2;
}
int read_vector(int vec[], int size, int stop_value) {
    int count = 0;
    while (count < size) {
        int value;
        scanf("%d", &value);
        if (value == stop_value) break;
        vec[count++] = value;
    }
    return count;
}
void display_vector(const int vec[], int size){
    for(int i=0; i < size; i++){
        printf("%d ", vec[i]);
    }
}
