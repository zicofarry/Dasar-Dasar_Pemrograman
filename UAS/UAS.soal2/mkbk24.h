/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan UAS soal 2 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include <stdio.h> // deklarasi library yang akan digunakan
#include <string.h> // deklarasi library yang akan digunakan

// deklarasi variabel global
int idx; // index dari karakter terakhir pada kata
int wlen; // panjang kata (word length)
char cw[51]; // kata saat ini (current word)

// bagian untuk mengakhiri, mereset, dan memulai mesin kata
int eop(char pita[]);
void start(char pita[]);
void reset();

// bagian memajukan dan  mesin kata
void inc(char pita[]);
// void dec(char pita[]);

// bagian mendapatkan variabel global/atribut mesin kata
char* getcw();
int getlen();

// mendeklarasikan prosedur untuk memproses hasil
void hasil(char kw, char pita[], int *n);
