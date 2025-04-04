/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan UAS soal 1 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include <stdio.h>//menggunakan library stdio.h
#include <string.h>//menggunakan library string.h

typedef struct{//membuat bungkusan yang berisi angka, string, dan space
    /*mendeklarasikan variabel untuk menampung nilai
    angka = angka masukan
    string = string masukan 
    space = spasi untuk membuat pola*/
    int angka;
    char string[51];
    int space;
}x;

//mendeklarasikan fungsi untuk menghitung digit pada integer
int digit(int n);

//mendeklarasikan prosedur untuk menampilkan hasil yang telah diprosoes sesuai input
void hasil(int n, x bungkus[]);