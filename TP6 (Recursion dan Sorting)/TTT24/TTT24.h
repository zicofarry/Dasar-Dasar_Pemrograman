/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tugas praktikum 6 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include <stdio.h>//menggunakan library stdio.h
#include <string.h>//menggunakan library string.h

typedef struct{//mendeklarasikan bungkusan untuk menampung beberapa variabel
    /*mendeklarasikan variabel untuk menampung nilai
    nama = nama pemain
    hp = health point yang dimiliki pemain
    dmg = damage yang dimiliki pemain
    dmgx = bonus damage yang dimiliki pemain setiap serangan*/
    char nama[101];
    int hp;
    int dmg;
    int dmgx;
}player;

void win(player pow, player finn, int t, int n, player *lolos);//mendeklarasikan prosuder untuk menentukan pemenang dan mengetahui setiap serangan yang dilakukan
void swap(player *a, player *b);//mendeklarasikan prosedur untuk menukarkan bungkusan di sustu indeks
void bubble_sort(int n, player *lolos);//mendeklarasikan prosedur untuk melakukan pengurutan dengan algoritma bubble sort
int partition(player lolos[], int low, int high);//mendeklarasikan fungsi untuk melakukan partisi yang akan digunakan untuk melakukan quick sort
void quick_sort(player lolos[], int low, int high);//mendeklarasikan prosedur untuk melakukan pengurutan dengan algoritma quick sort
int digit(int n);//mendeklarasikan fungsi untuk menghitung jumlah digit
void leaderboard(int n, player *lolos);//mendeklarasikan prosedur untuk memprint leaderboard sesuai data yang telah diproses