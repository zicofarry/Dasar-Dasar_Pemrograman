/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tugas praktikum 8 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include "header.h"

int main(){
    char y;

    panduan();
    printf("Mau ngasih perintah gak? (y/n) :\n");
    scanf(" %c", &y);

    while(y != 'n'){
        program(&y);
    }

    if(y == 'n'){
        printf("Program Telah Selesaiii\nlalalala yeyeyeye~\n");
    }


    return 0;
}
//done