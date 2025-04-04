/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan UAS soal 1 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include "digstr24.h"//menggunakan library digstr24.h

int main(){
    /*mendeklarasikan variabel untuk menampung nilai
    bungkus = bungkusan yang berisi (angka, string, dan space)
    n = jumlah bungkusan yang ingin dibuat
    spacex = jumlah spasi yang selalu bertambah mengikuti aturan string sebelumnya*/
    x bungkus[51];
    int n;
    int spacex = 0;

/*Meminta input dari user*/
    //meminta input untuk jumlah bungkusan bungkus yang ingin dibuat
    scanf("%d", &n);
    
/*Menghasilkan output sesuai input yang telah diproses dalam prosedur*/
    //memanggil prosedur hasil
    hasil(n, bungkus);//memanggil prosedur hasil
    
    return 0;
}
//done