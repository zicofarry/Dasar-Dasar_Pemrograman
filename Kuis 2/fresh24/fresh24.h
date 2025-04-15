/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Kuis 2 soal 1 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include <stdio.h>//menggunakan library stdio.h
#include <string.h>//menggunakan library string.h

typedef struct{//mendeklarasikan bungkusan yang menapung beberapa variabel
    /*mendeklarasikan variabel untuk menampung nilai
    nama = nama orangnya
    pend = pendidikannya (S1/D4/D3)
    durkul = durasi lamanya menjalani kuliah
    tskill = nilai tes skill
    atti = nilai attitude psikologi
    value = nilai value dari orang tersebut*/
    char nama[101];
    char pend[101];
    int durkul;
    int tskill;
    int atti;
    int value;
}fresh;
char mode_urut[101];//mendeklarasikan variabel untuk menampung string jenis sortnya (bubble/quick)

void value(int n, fresh *arr);//mendeklarasikan prosedur untuk menyimpan nilai value dari setiap fresh graduate
int ave_value(int n, fresh *arr);//mendeklarasikan fungsi untuk menyimpan nilai rata rata value dari keseluruhan fresh graduate
void swap(fresh *a, fresh *b);//mendeklarasikan prosedur untuk menukar nilai pada suatu indeks
void bubble_sort(int n, fresh *arr);//mendeklarasikan prosedur untuk melakukan pengurutan dengan algoritma bubble sort
int partition(fresh arr[], int low, int high);//mendeklarasikan fungsi untuk melakukan partisi yang fungsinya akan digunakan pada algoritma quick sort
void quick_sort(fresh arr[], int low, int high);//mendeklarasikan prosedur untuk melakukan pengurutan dengan algoritma quick sort
void merge_sort(int n1, fresh arr1[], int n2, fresh arr2[], fresh arr3[], char mode_urut[]);//mendeklarasikan prosedur untuk melakukan merging table secara terurut (sorting dilakukan di dalam prosedur)
void print_arr(int n, fresh *arr);//mendeklarasikan prosedur untuk melakukan print output sesuai output yang diinginkan soal