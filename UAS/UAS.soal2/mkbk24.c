/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan UAS soal 2 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include "mkbk24.h" //includekan file header

// cek eop
int eop(char pita[]){
    if(pita[idx] == '@'){ // jika '@' return 1
        return 1;
    }
    else{
        return 0; // jika bukan '@' kembalikan 0
    }
}

// nyalakan mesin
void start(char pita[]){
    // set index dan panjang kata menjadi 0
    idx = 0;
    wlen = 0;


    while (pita[idx] == ' '){ // ignore blank
        idx++;
    }


    // ambil kata masukkan dalam current word
    while ((pita[idx] != ' ') && (eop(pita) == 0)){
        cw[wlen] = pita[idx];
        wlen++;
        idx++;
    }
    cw[wlen] = '\0'; // akhiri dengan null terminator
}

// reset current word
void reset(){
    wlen = 0; // kembalikan panjang kata menjadi 0
    cw[wlen] = '\0'; // set current word menjadi null (siap diisi)
}


// pindah next kata
void inc(char pita[]){
    wlen = 0; // set panjang kata jadi 0 (memastikan)


    while (pita[idx] == ' '){ // ignore blank
        idx++;
    }


    // masukkan kata baru
    while ((pita[idx] != ' ') && (eop(pita) == 0)){
        cw[wlen] = pita[idx];
        wlen++;
        idx++;
    }
    cw[wlen] = '\0'; // akhiri lagi
}

// void dec(char pita[]) {
//     int wlen = getlen(pita);  // Ambil panjang kata dari pita
//     int idx = wlen - 1;       // Mulai dari indeks terakhir kata
//     char cw[100];             // Pastikan cw cukup besar untuk menampung kata yang dibalik

//     // Abaikan spasi di akhir kata
//     while (idx >= 0 && pita[idx] == ' ') {
//         idx--;
//     }

//     // Masukkan kata baru ke dalam cw (dibalik)
//     int cw_idx = 0;
//     while (idx >= 0 && pita[idx] != ' ' && wlen > 0) {
//         cw[wlen] = pita[idx];
//         cw_idx++;
//         wlen--;
//         idx--;
//     }

//     // Akhiri string dengan null character
//     cw[cw_idx] = '\0';
// }



// mengembalikan current word
char* getcw(){
    return cw;
}


// mengembalikan panjang current word
int getlen(){
    return wlen;
}

// membuat prosedur untuk memproses hasil
void hasil(char kw, char pita[], int *n){
    start(pita); // memulai kata
    char tmp[101]; // mendeklarasikan string untuk menampung string sementara
    while(eop(pita) == 0){
        strcpy(tmp, getcw()); // menyimpan kata saat ini di tmp
        int j1 = 0; // mendeklarasikan jumlah huruf yang memenuhi syarat pada 1 kata
        for(int i = 0; i < getlen(); i++){ // looping sepanjang kata
            if (getcw()[i] == kw) { // looping sepanjang kata
                j1++; // maka j1 bertambah
            }

        }

        inc(pita); // maju ke kata selanjutnya
        int j2 = 0; // mendeklarasikan jumlah huruf yang memenuhi syarat pada 1 kata
        for(int i = 0; i < getlen(); i++){ // looping sepanjang kata
            if (getcw()[i] == kw) { // looping sepanjang kata
                j2++; // maka j2 bertambah
            }

        }

        if(j1 >= 2 && j2 >= 2){ // jika j1 >= 2 dan j2 >= 2
            printf("%s %s\n", tmp, getcw()); // maka print pasangan string yang memenuhi
            (*n)++; // nilai n (pasangan string yang memenuhi) bertambah
            inc(pita); // dan lanjut ke kata selanjutnya
        }
    }
}