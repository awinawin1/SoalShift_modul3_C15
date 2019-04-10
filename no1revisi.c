#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

unsigned long long hasil[50];

void* factorial(void* arg)//fungsi faktorial
{
    int* nump = (int*) arg; //mengcasting mnjdi integer
    int num = *nump;//nilai num
    int i;
    unsigned long long facto = 1;
    for( i=num; i>0; i--){//faktorisasi
        facto = facto*i;
    }
    hasil[num] = facto;//hasil faktorial dimasukkan ke array hasil
}
void swap(int *a, int *b)//template swap
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[], int size)//templtae SelectionSort
{
    int i, j;
    for (i = 0 ;  i < size;i++)
    {
        for (j = i ; j < size; j++)
        {
            if (arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
        }
    }
}

int main(int argc, char *argv[])
{//argc: menghitung jumlah input, //argv: menyimpan input 
    int n;
    n = argc-1; //inputan
    pthread_t tid[n];//membuat thread sesuai inputan
    int i;
    int ar[n];
    for(i=0;i<n;i++){
       ar[i] = atoi(argv[i+1]);//mengambil inputan tanpa ./blabla, atau asci to integer
    }
    for(i=0;i<n;i++){
        pthread_create(&tid[i],NULL,&factorial,&ar[i]);
    }
    for(i=0;i<n;i++){
        pthread_join(tid[i],NULL);
    }
    selectionSort(ar,n);//memanggil fungsi selectionsort
    for(i=0;i<n;i++){
        printf("%d! = %llu\n",ar[i],hasil[ar[i]]);
    }//mengoutputkan nilai faktorial pada setiap thread
    
}
