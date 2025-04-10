/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Kuis 3 soal 1 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include "mkkd24.h" // include kan file header


// fungsi untuk memeriksa akhir dari proses (End of Process)
int eopc(){
    if(cc == '$'){ // jika cc saat ini '$'
        return 1; // kembalikan nilai 1 (marking eop true)
    }else{ // jika tidak
        return 0; // kembalikan nilai 0
    }
}

// prosedur untuk memulai mesin karakter
void startc(char pita[]){
    // memulai pembacaan mesin karakter
    indeks = 0; // index pasti dimulai dari 0
    cc = pita[indeks]; // cc adalah pita inputan ke idx = 0
}

// prosedur untuk memajukan karakter pada pita
void incc(char pita[]){
    // menambah nilai indeks dan mengatur karakter yang dibaca
    indeks++;
    cc = pita[indeks];
}

// prosedur untuk memundurkan karakter pada pita
void decc(char pita[]){
    // mwngurangi nilai indeks dan mengatur karakter yang dibaca
    indeks--;
    cc = pita[indeks];
}

// prosedur untuk memajukan karakter hingga melewati spasi
void advc(char pita[]){
    // menambah nilai indeks dan mengatur karakter yang dibaca
    indeks++;
    cc = pita[indeks];

    // proses looping jika karakter saat ini masih berupa spasi
    while((cc == ' ') && (eopc() == 0)){
        indeks++;
        cc = pita[indeks];
    }
}

// fungsi untuk menghitung jumlah karakter
int countc(char pita[]){
    int n = 0;
    startc(pita);
    while(eopc() == 0){
        n++;
        advc(pita);
    }

    return n;
}

// fungsi untuk mendapatkan karakter pita saat ini
int getcc(){
    return cc;
}