#include <stdio.h>
#include "isort.h"


void shift_element(int* arr1, int i){
    int temp1; int temp2; int flag; int j; 
    temp1 = 0; temp2 =0; flag = 1;
    for(j=0; j<i; j++){
        if (j==0){
            temp1 =*(arr1+1);
            *(arr1+1) = *(arr1);}
        else {
            if (flag){
                temp2 = *(arr1+j+1);
                *(arr1+j+1) = temp1;
                flag = 0;}
        else{
                temp1 = *(arr1+j+1);
                *(arr1+j+1) = temp2;
                flag=1;}
            }
        }
    }

void insertion_sort(int* arr , int len){
    int i; int j; int counter; int temp;
    i = 1; j=2; counter=1; 
    while(i<len){
        if (*(arr+i)<*(arr+i-1)){
            temp = *(arr+i);
            while (i-j>=0){
                if (temp<*(arr+i-j)){
                    j++;
                    counter++;}
                else break;}
            shift_element(arr+(i-counter), counter);
            *(arr+i-counter)=temp; }
        i++;
        j=2; counter=1; }
    }


int main() {
    int arr[arr_size] = {0};
    int i; 
    for (i=0; i<arr_size; i++){
        scanf(" %d",(arr+i));}
    insertion_sort(arr,arr_size);
    for (i = 0; i < arr_size-1; i++){
        printf("%d,",*(arr+i));}
    printf("%d\n",*(arr+arr_size-1));   

    return 0;
}








    

