/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tugas praktikum 6 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include "TTT24.h"//menggunakan library TTT24.h

int main(){
    /*mendeklarasikan variabel untuk menampung nilai
    pow = bungkusan pow yang berisi (nama, hp, damage, dan bonus damage)
    finn = bungkusan finn yang berisi (nama, hp, damage, dan bonus damage)
    i = counting untuk loop for
    t = jumlah maksimal banyaknya serangan
    n = jumlah pemain yang sudah lolos leaderboard
    count = counting untuk menghitung banyaknya isi dalam suatu array
    algo_urut = algoritma untuk melakukan sorting (bubble/quick)*/
    player pow, finn;
    int i, t;
    int n, count = 0;
    char algo_urut[51];

/*meminta masukan dari user*/
    //masukan hp dan damage dari pow-pow
    scanf("%d %d", &pow.hp, &pow.dmg);

    //masukan hp dan damage dari bun-bun
    scanf("%d %d", &finn.hp, &finn.dmg);

    scanf("%d", &t);//masukan jumlah maksimal banyaknya serangan
    scanf("%d", &n);//masukan banyaknya pemain yang sudah masuk leaderboard

    player lolos[100];//mendeklarasikan bungkusan array dari pemain yang sudah pasti masuk leaderboard
    for(i = 0; i < n; i++){
        scanf("%s %d %d", lolos[i].nama, &lolos[i].hp, &lolos[i].dmg);//masukan nama, hp, dan damage dari setiap pemainnya
    }

    //masukan untuk algoritma sortingnya (bubble/ quick)
    scanf("%s", algo_urut);


/*membuat program dengan memanggil fungsi/ prosedur*/
    //memanggil prosedur untuk bertanding dan menentukan pemenang
    win(pow, finn, t, n, lolos);

    //counting untuk menghitung jumlah array yang masuk leaderboard
    while(lolos[count].hp != -1){
        count++;
    }

    //mengurutkan dengan algoritma dengan bubble atau quick
    if(strcmp(algo_urut, "bubble") == 0){//jika algoritma sortingnya adalah bubble sort
        bubble_sort(count, lolos);//memanggil prosedur bubble sort
    }else if(strcmp(algo_urut, "quick") == 0){//jika algoritma sortingnya adalah quick sort
        quick_sort(lolos, 0, count - 1);//memanggil prosedur quick sort
    }

/*menampilkan output sesuai dengan input yang telah diproses*/
    //memanggil prosedur leaderboard
    leaderboard(count, lolos);

    return 0;
}