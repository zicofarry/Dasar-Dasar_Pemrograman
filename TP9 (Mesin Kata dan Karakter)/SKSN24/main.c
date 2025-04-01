/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tugas praktikum 9 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include "sksn24.h"

int main(){
    char pita1[201];
    char pita2[301];

    scanf(" %200[^\n]s", &pita1);
    scanf(" %300[^\n]s", &pita2);

    //print untuk pita pertama
    pisah_kata(pita1);

    //print untuk pita kedua
    kena_sensor(pita2);


    return 0;
}
