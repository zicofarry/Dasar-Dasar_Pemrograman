/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Kuis 3 soal 1 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include <stdio.h> // deklarasi library yang akan digunakan

// deklarasi variabel global
int indeks; // variabel global untuk indeks karakter
char cc; // variabel global untuk menampung current character

int eopc(); // fungsi untuk marking sudah berada di eop atau tidak
void startc(char pita[]); // prosedur untuk memulai mesin karakter
void incc(char pita[]); // prosedur memajukan satu karakter
void decc(char pita[]); // prosedur memundurkan satu karakter
void advc(char pita[]); // prosedur memajukan satu karakter (skip spasi)
int countc(char pita[]); // Fungsi untuk menghitung jumlah karakter
int getcc(); //fungsi untuk mendapatkan current karakter
