#include <stdio.h>

void troca_1(int a, int b){
    int aux = a;
    a = b;
    b = aux;
}
void troca_2(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble_sort(int arr[], int len){
    for(int i = 0; i < len; i++){
        for(int j = len - 1; j >= i + 1; j--){
            if (arr[j] < arr[j - 1]){
                troca_2(&arr[j], &arr[j - 1]);
            }
        }
    }
}

void main(){
    int arr[] = {5,4,3,2,1};
    bubble_sort(arr, 5);

    for(int x = 0; x < 5; x++){
        printf("%d ", arr[x]);
    }
    printf("\n");
}