/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tugas praktikum 3 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include <stdio.h>//menggunakan library stdio.h
#include <string.h>//menggunakan library string.h

int main(){
    /*mendeklarasikan variabel untuk menampung nilai
    n = banyak balapan dalam 1 musim
    pembalap1[50] = nama pembalap ke-1
    timbalap1[50] = tim untuk pembalap ke-1
    pembalap2[50] = nama pembalap ke-2
    timbalap2[50] = tim untuk pembalap ke-2
    timfree[50] = tim yang bebas dari denda
    pembalap1ex[50] = nama pembalap 1 setelah dienkripsi dijumlahkan ASCII nya sesuai jumlah poin
    pembalap2ex[50] = nama pembalap 2 setelah dienkripsi dijumlahkan ASCII nya sesuai jumlah poin
    char exbalik1 = nama pembalap 1 setelah dienkripsi ditukar setiap 2 digit
    char exbalik2 = nama pembalap 2 setelah dienkripsi ditukar setiap 2 digit
    poin1[n], banyak poin pembalap 1 dari setiap balapan dalam satu musim
    poin2[n], banyak poin pembalap 2 dari setiap balapan dalam satu musim
    jumpoin1 = jumlah poin dari pembalap 1
    jumpoin2 = jumlah poin dari pembalap 2
    jumwin1 = jumlah kemenangan pembalap 1 (25 poin menandakan kemenangan)
    jumwin2 = jumlah kemenangan pembalap 2 (25 poin menandakan kemenangan)
    sechalf1 = jumlah poin pembalap 1 yang diperoleh pada setengah kedua
    sechalf2 = jumlah poin pembalap 2 yang diperoleh pada setengah kedua
    pemenang = pembalap yang memenangkan pertandingan
    denda = sanksi yang harus dibayar tim pembalap*/
    int n, i;
    scanf("%d", &n);
    char pembalap1[50], timbalap1[50], pembalap2[50], timbalap2[50], timfree[50], pembalap1ex[50], pembalap2ex[50], exbalik1[50], exbalik2[50];
    int poin1[n], poin2[n], jumpoin1 = 0, jumpoin2 = 0, jumwin1 = 0, jumwin2 = 0, sechalf1 = 0, sechalf2 = 0, pemenang = 0, denda;

/*meminta input dari user*/
    //meminta masukan dari user untuk nama pembalap1 dan timnya
    scanf("%s", pembalap1);
    scanf("%s", timbalap1);

    //meminta masukan dari user untuk banyak poin dari setiap balapan
    for(i = 0;i < n;i++){
        scanf("%d", &poin1[i]);
        jumpoin1 += poin1[i];
    }

    //meminta masukan dari user untuk nama pembalap2 dan timnya
    scanf("%s", pembalap2);
    scanf("%s", timbalap2);

    //meminta masukan dari user untuk banyak poin dari setiap balapan
    for(i = 0;i < n;i++){
        scanf("%d", &poin2[i]);
        jumpoin2 += poin2[i];
    }

    //meminta masukan dari user untuk nama tim yang bebas dari benda
    scanf("%s", timfree);

/*membuat program untuk menentukan pemenang*/
    //membuat kondisi jika jumlah poin dari kedua tim sama
    if(jumpoin1>jumpoin2){
        pemenang = 1;
    }else if(jumpoin1<jumpoin2){
        pemenang = 2;
    }else if(jumpoin1==jumpoin2){
        for(i = 0;i < n;i++){
            if(poin1[i]==25){
                jumwin1++;
            }
            if(poin2[i]==25){
                jumwin2++;
            }
        }
        //membuat kondisi jika jumlah kemenangan dari kedua tim sama
        if(jumwin1>jumwin2){
            pemenang = 1;
        }else if(jumwin1<jumwin2){
            pemenang = 2;
        }else if(jumwin1==jumwin2){
            for(i = n/2;i < n;i++){
                sechalf1 += poin1[i];
            }
            for(i = n/2;i < n;i++){
                sechalf2 += poin2[i];
            }
            //membuat kondisi untuk membandingkan secondhalf
            if(sechalf1>sechalf2){
                pemenang = 1;
            }else if(sechalf1<sechalf2){
                pemenang = 2;
            }
        }
    }

/*membuat program untuk mengenkripsi nama pembalap yang menang*/
    //mengcopy string untuk di enkripsi
    strcpy(pembalap1ex,pembalap1);
    strcpy(pembalap2ex,pembalap2);

    //membuat enkripsi dengan cara menambahkan string nama pemenang dengan jumlah poin yang didapatkan
    if(pemenang==1){//membuat kondisi jika pemenangnya adalah pembalap 1
        int i;
        for (i = 0; i <= strlen(pembalap1ex); i++){
            int j = 0;
            for(j = 0; j < jumpoin1; j++){
                if((pembalap1ex[i] >= 'A') && (pembalap1ex[i] <= '[')){
                    if(pembalap1ex[i] == '['){
                        pembalap1ex[i] = 'A';//mengembalikan ke huruf A jika char sudah melampaui batas huruf Z
                }
                pembalap1ex[i]++;
                }
                if((pembalap1ex[i] >= 'a') && (pembalap1ex[i] <= '{')){
                    if(pembalap1ex[i] == '{'){
                        pembalap1ex[i] = 'a';//mengembalikan ke huruf z jika char sudah melampaui batas huruf z
                }
                pembalap1ex[i]++;
                }
            }
        }
        pembalap1ex[i] = '\0';//mendeklarasikan null term untuk mengakhiri string
    }else if(pemenang==2){//membuat kondisi jika pemenangnya adalah pembalap 2
        int i;
        for (i = 0; i <= strlen(pembalap2ex); i++){
            int j = 0;
            for(j = 0; j < jumpoin2; j++){
                if((pembalap2ex[i] >= 'A') && (pembalap2ex[i] <= '[')){
                    if(pembalap2ex[i] == '['){
                        pembalap2ex[i] = 'A';//mengembalikan ke huruf A jika char sudah melampaui batas huruf Z
                }
                pembalap2ex[i]++;
                }
                if((pembalap2ex[i] >= 'a') && (pembalap2ex[i] <= '{')){
                    if(pembalap2ex[i] == '{'){
                        pembalap2ex[i] = 'a';//mengembalikan ke huruf a jika char sudah melampaui batas huruf z
                }
                pembalap2ex[i]++;
                }
            }
        }
        pembalap2ex[i]='\0';//mendeklarasikan null term untuk mengakhiri string
    }
    
    //membuat enkripsi dengan pola terbalik
    if(pemenang==1){//membuat kondisi jika pemenangnya adalah pembalap 1
        int i;
        for (i = 0; i <= strlen(pembalap1); i++){
            if(i % 2 == 0){
                exbalik1[i] = pembalap1ex[i+1];
            }else if(i % 2 == 1){
                exbalik1[i] = pembalap1ex[i-1];
            }  
        }
        exbalik1[i]='\0';//mendeklarasikan null term untuk mengakhiri string
    }else if(pemenang==2){//membuat kondisi jika pemenangnya adalah pembalap 2
        int i;
        for (i = 0; i <= strlen(pembalap2); i++){
            if(i % 2 == 0){
                exbalik2[i] = pembalap2ex[i+1];
            }else if(i % 2 == 1){
                exbalik2[i] = pembalap2ex[i-1];
            }
        }
        exbalik2[i]='\0';//mendeklarasikan null term untuk mengakhiri string
    }

/*membuat program untuk menentukan jumlah denda/ sanksi yang didapat*/
    //membandingakan nilai ASCII dengan tim yang bebas sanksi
    if(pemenang==1){//membuat kondisi jika pemenangnya adalah pembalap 1
        if (strcmp(timbalap1,timfree) > 0){
            denda = 75;//jika ASCII tim pembalap 1 lebih besar dari tim yang bebas sanksi
        }else if(strcmp(timbalap1,timfree) < 0){
            denda = 125;//jika ASCII tim pembalap 1 lebih kecil dari tim yang bebas sanksi
        }else if(strcmp(timbalap1,timfree) == 0){
            denda = 0;//jika ASCII tim pembalap 1 sama dengan tim yang bebas sanksi
        }
    }else if(pemenang==2){//membuat kondisi jika pemenangnya adalah pembalap 2
        if (strcmp(timbalap2,timfree) > 0){
            denda = 75;//jika ASCII tim pembalap 2 lebih besar dari tim yang bebas sanksi
        }else if(strcmp(timbalap2,timfree) < 0){
            denda = 125;//jika ASCII tim pembalap 2 lebih kecil dari tim yang bebas sanksi
        }else if(strcmp(timbalap2,timfree) == 0){
            denda = 0;//jika ASCII tim pembalap 2 sama dengan tim yang bebas sanksi
        }
    } 

/*membuat output berdasarkan input yang telah diproses*/
    //membuat kondisi berdasarkan pemenang dan jumlah denda
    if(pemenang==1){//membuat kondisi jika pemenangnya adalah pembalap 1
        if(denda==0){//jika tidak ada denda
            printf("Pesan sebelum di enkripsi :\nLuAr biAsA!!! %s Juara Dunia dari musim Sengit ini!!\n%s bebas dari denda!\n\nPesan setelah di enkripsi :\nLuAr biAsA!!! %s Juara Dunia dari musim Sengit ini!!\n%s bebas dari denda!\n", pembalap1, pembalap1, exbalik1, exbalik1);
        }else if(denda==75){//jika dendanya 75000
            printf("Pesan sebelum di enkripsi :\nLuAr biAsA!!! %s Juara Dunia dari musim Sengit ini!!\n%s kena denda $75,000!\n\nPesan setelah di enkripsi :\nLuAr biAsA!!! %s Juara Dunia dari musim Sengit ini!!\n%s kena denda $75,000!\n", pembalap1, pembalap1, exbalik1, exbalik1);
        }else if(denda==125){//jika dendanya 125000
            printf("Pesan sebelum di enkripsi :\nLuAr biAsA!!! %s Juara Dunia dari musim Sengit ini!!\n%s kena denda $125,000!\n\nPesan setelah di enkripsi :\nLuAr biAsA!!! %s Juara Dunia dari musim Sengit ini!!\n%s kena denda $125,000!\n", pembalap1, pembalap1, exbalik1, exbalik1);
        }
    }else if(pemenang==2){//membuat kondisi jika pemenangnya adalah pembalap 2
        if(denda==0){//jika tidak ada denda
            printf("Pesan sebelum di enkripsi :\nLuAr biAsA!!! %s Juara Dunia dari musim Sengit ini!!\n%s bebas dari denda!\n\nPesan setelah di enkripsi :\nLuAr biAsA!!! %s Juara Dunia dari musim Sengit ini!!\n%s bebas dari denda!\n", pembalap2, pembalap2, exbalik2, exbalik2);
        }else if(denda==75){//jika dendanya 75000
            printf("Pesan sebelum di enkripsi :\nLuAr biAsA!!! %s Juara Dunia dari musim Sengit ini!!\n%s kena denda $75,000!\n\nPesan setelah di enkripsi :\nLuAr biAsA!!! %s Juara Dunia dari musim Sengit ini!!\n%s kena denda $75,000!\n", pembalap2, pembalap2, exbalik2, exbalik2);
        }else if(denda==125){//jika dendanya 125000
            printf("Pesan sebelum di enkripsi :\nLuAr biAsA!!! %s Juara Dunia dari musim Sengit ini!!\n%s kena denda $125,000!\n\nPesan setelah di enkripsi :\nLuAr biAsA!!! %s Juara Dunia dari musim Sengit ini!!\n%s kena denda $125,000!\n", pembalap2, pembalap2, exbalik2, exbalik2);
        }
    }
    return 0;
}
//done