/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan UAS soal 1 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include "digstr24.h"//menggunakan library digstr24.h

int digit(int n){//membuat fungsi untuk menghitung jumlah digit
    int count = 0;//count dimulai dari 0
    if(n == 0){//jika angka nya 0 
        count = 1;//maka dihitung sebanyak 1 digit
    }else{//jika lebih dari 0
        while (n != 0){//loop while selama angkanya tidak 0
            n /= 10;//angka dibagi 10
            count++;//setiap dibagi 10, count bertambah 1
        }
    }

    return count;//mengembalikan nilai count
}

void hasil(int n, x bungkus[]){//membuat prosedur hasil untuk menghasilkan pola
    int spacex = 0;
    for(int i = 0; i < n; i++){
        bungkus[i].space = 0;//marking 0 untuk mengisi jumlah spasi awal
        bungkus[i].space += spacex;//mengupdate setiap array baru dan mengisinya dengan jumlah spacex
        scanf("%d %s", &bungkus[i].angka, bungkus[i].string);//meminta input untuk bungkusan yang berisi angka dan string
        //membuat kondisi jika angka 1 digit, 2 digit, atau 3 digit
        if(digit(bungkus[i].angka)  == 1){//jika 1 digit
            spacex += 1;//spacex akan diisi dengan 1 spasi
        }else if(digit(bungkus[i].angka) == 2 || digit(bungkus[i].angka) == 3){//jika 2 atau 3 digit
            spacex += strlen(bungkus[i].string);//spacex akan diisi sesuai jumlah string pada bungkusan
        }
        
    }
    
    for(int i = 0; i < n; i++){
    /*membuat program untuk menghasilkan pola*/
        //membuat kondisi jika angka 1 digit, 2 digit, atau 3 digit
        if(digit(bungkus[i].angka) == 1){ // jika 1 digit
            for(int j = 0; j < strlen(bungkus[i].string); j++){
                for(int k = 0; k < bungkus[i].space; k++){
                    printf(" ");//memprint spasi sesuai jumlah spasi sebelumnya
                }
                printf("%c\n", bungkus[i].string[j]);//memprint setiap char pada string
            }
        }else if(digit(bungkus[i].angka) == 2){ // jika 2 digit
            for(int j = 0; j < bungkus[i].space; j++){
                printf(" ");//memprint spasi sesuai jumlah spasi sebelumnya
            }
            for(int j = strlen(bungkus[i].string) - 1; j >= 0; j--){
                printf("%c", bungkus[i].string[j]);//memprint setiap char (terbalik) pada string
            }
            printf("\n");
        }else if(digit(bungkus[i].angka) == 3){ // jika 3 digit
            for(int j = 0; j < strlen(bungkus[i].string); j++){
                for(int k = 0; k < bungkus[i].space; k++){
                    printf(" ");//memprint spasi sesuai jumlah spasi sebelumnya
                }
                for(int k = 0; k < j; k++){
                    printf(" ");//memprint spasi sesuai jumlah string (loop segitiga)
                }
                printf("%c\n", bungkus[i].string[j]);//memprint setiap char pada string
            }
        }
    }
}