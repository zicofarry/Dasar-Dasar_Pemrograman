/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tugas praktikum 9 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include "sksn24.h"

//fungsi fungsi untuk karakter
int eopc(){
    if(cc == '.'){
        return 1;
    }else{
        return 0;
    }
}

void startc(char pita[]){
    indeks = 0;
    cc = pita[indeks];
}

void incc(char pita[]){
    indeks++;
    cc = pita[indeks];
}

void decc(char pita[]){
    indeks--;
    cc = pita[indeks];
}

void advc(char pita[]){
    indeks++;
    cc = pita[indeks];
    while((cc == ' ') && (eopc() == 0)){
        indeks++;
        cc = pita[indeks];
    }
}

int countc(char pita[]){
    int n = 0;
    startc(pita);
    while(eopc() == 0){
        n++;
        advc(pita);
    }

    return n;
}

int getcc(){
    return cc;
}

//fungsi fungsi untuk kata
int eopw(char pita[]){
    if(pita[indeks] == '.'){
        return 1;
    }else{
        return 0;
    }
}

void startw(char pita[]){
    indeks = 0;
    panjangkata = 0;
    while(pita[indeks] == ' '){
        indeks++;
    }
    while(pita[indeks] != ' ' && pita[indeks] != '.'){
        cword[panjangkata] = pita[indeks];
        indeks++;
        panjangkata++;
    }
    cword[panjangkata] = '\0';
}

void resetw(){
    panjangkata = 0;
    cword[panjangkata] = '\0';
}

void incw(char pita[]){
    panjangkata = 0;
    while(pita[indeks] == ' '){    
        indeks++;
    }
    while(pita[indeks] != ' ' && pita[indeks] != '.'){
        cword[panjangkata] = pita[indeks];
        indeks++;
        panjangkata++;
    }
    cword[panjangkata] = '\0';
}

char* getcw(){
    return cword;
}

int getlen(){
    return panjangkata;
}

// menghitung jumlah kata pada suatu string
int countw(char pita[]){
    int jkata = 0;
    startw(pita);// mulai kata
    while(eopw(pita) == 0){ // loop selama belum bertemu eop
        jkata++; // jumlah kata bertambah
        incw(pita); // maju ke kata selanjutnya
    }

    //menghitung sisa kata yang memiliki eop
    if(getlen() > 0){
        jkata++;
    }
    
    return jkata;
}

void pisah_kata(char pita1[]){
    char tmp[201];
    char tmp1[201];

    startc(pita1);
    int i = 0;
    int j = 0;
    while(eopc() == 0){
        tmp1[i] = getcc();
        incc(pita1);
        i++;
    }
    
    startc(pita1);
    i = 0;
    j = 0;
    while(eopc() == 0){
        tmp1[i] = getcc();
        if((tmp1[i] >= 'A' && tmp1[i] <= 'Z') && i != 0 &&
                (tmp1[i-1] >= 'A' && tmp1[i-1] <= 'Z') &&
                (tmp1[i+1] >= 'a' && tmp1[i+1] <= 'z')){
                tmp[j++] = ' ';
        }
        else if((tmp1[i] >= 'A' && tmp1[i] <= 'Z') && i != 0 &&
            (tmp1[i-1] >= 'a' && tmp1[i-1] <= 'z')){
            tmp[j++] = ' ';
        }

        tmp[j++] = tmp1[i];
        incc(pita1);
        i++;
    }
    tmp[j] = '\0';
    printf("%s\n", tmp);
}

void kena_sensor(char pita2[]){
    char sensor[51][151];
    int s = 0;

    startw(pita2);
    while(eopw(pita2) == 0){
        int huruf = 0;
        int ada = 0;
        for(int i = 0; i < getlen(); i++){
            if((getcw()[i] >= 'a' && getcw()[i] <= 'z') ||
                (getcw()[i] >= 'A' && getcw()[i] <= 'Z')){
                huruf++;
            }else if((getcw()[i] >= '0' && getcw()[i] <= '9') && getcw()[i] == getcw()[i+1]){
                ada = 1;
            }
            // printf("h = %d\n", huruf);
            // printf("ada = %d\n", ada);
        }
        
        if(ada == 1 && huruf >= 4){
            strcpy(sensor[s++], getcw());
        }
        incw(pita2);
    }
    int huruf = 0;
    int ada = 0;
    

    for(int i = 0; i < getlen(); i++){
        if((getcw()[i] >= 'a' && getcw()[i] <= 'z') ||
            (getcw()[i] >= 'A' && getcw()[i] <= 'Z')){
            huruf++;
        }else if((getcw()[i] >= '0' && getcw()[i] <= '9') && getcw()[i] == getcw()[i+1]){
            ada = 1;
        }
            // printf("h = %d\n", huruf);
            // printf("ada = %d\n", ada);
    }

    if(ada == 1 && huruf >= 4){
        strcpy(sensor[s++], getcw());
    }


    printf("\nKena 5ensor:\n");
    for(int i = 0; i < s; i++){
        printf("%s\n", sensor[i]);
    }

}