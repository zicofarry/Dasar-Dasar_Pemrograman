/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan UAS soal 2 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include "mkbk24.h" //includekan file header

int main() {
    /*deklarasi variabel untuk menampung nilai
    kw = keyword masukan yang akan dibandingkan
    pita = pita masukan yang berisi beberapa kata
    n = jumlah pasangan yang memenuhi ketentuan*/
    char kw;
    char pita[501];
    int n = 0;

/*Meminta masukan dari user*/
    //meminta masukan untuk keyword
    scanf(" %c", &kw);

    //meminta masukan untuk pita
    scanf(" %500[^\n]s", &pita);


/*Membuat program dengan memanggil prosedur kemudian diproses*/
    hasil(kw, pita, &n);

/*Menampilkan output sesuai dengan input yang telah diproses*/
    if(n==0){ // jika n = 0
        printf("tidak ada\n"); // maka print "tidak ada"
        printf("%d\n", n); // dan tampilkan jumlah n nya
    }else{ // jika bukan 0
        printf("%d\n", n); // tampilkan jumlah n nya
    }

    return 0;
}
//done