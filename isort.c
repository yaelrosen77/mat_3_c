#include "isort.h"

//this is a function that shifts i numbers from address arr1 to the right
void shift_element(int* arr1, int i){
    int temp1; int temp2; int flag; int j; 
    temp1 = 0; temp2 =0; flag = 1;
    for(j=0; j<i; j++){
        if (j==0){				//first iteration use a store value of temp var
            temp1 =*(arr1+1);
            *(arr1+1) = *(arr1);}
        else {
            if (flag){			  //if flag equals 1, then temp2 is free for store
                temp2 = *(arr1+j+1);
                *(arr1+j+1) = temp1;
                flag = 0;}
        else{
                temp1 = *(arr1+j+1);		//if flag equals 0, then temp1 is free for store
                *(arr1+j+1) = temp2;
                flag=1;}
            }
        }
    }

//sorting a given array, using insertion sort
void insertion_sort(int* arr , int len){
    int i; int j; int counter; int temp;
    i = 1; j=2; counter=1; 
    while(i<len){
        if (*(arr+i)<*(arr+i-1)){			//each iteration checks if the number is smaller then the one before
            temp = *(arr+i);
            while (i-j>=0){				//if it is, then checking how many numbers are bigger then that one, and saving result to counter
                if (temp<*(arr+i-j)){
                    j++;
                    counter++;}
                else break;}
            shift_element(arr+(i-counter), counter);		//calling shift_element on the last number found, with all counter iterations
            *(arr+i-counter)=temp; }
        i++;
        j=2; counter=1; }
    }


int main() {
    int arr[arr_size] = {0};
    int i; 
    for (i=0; i<arr_size; i++){				//inserting the input numbers to the array
        scanf(" %d",(arr+i));}
    insertion_sort(arr,arr_size);
    for (i = 0; i < arr_size-1; i++){			//printing the values of each number in the sorted arr
        printf("%d,",*(arr+i));}
    printf("%d\n",*(arr+arr_size-1));   		//the last index is seperated with ','

    return 0;
}








    

