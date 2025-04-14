/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Kuis 2 soal 1 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include "fresh24.h"//menggunakan library "fresh24.h"

int main(){
    /*mendeklarasikan variabel untuk menampung nilai
    i = counting untuk loop for
    n1 = jumlah isi barang dalam array1
    n2 = jumlah isi barang dalam array2
    n3 = jumlah isi barang dalam array3*/
    int i;
    int n1, n2, n3;

/*meminta masukan dari user*/
    //meminta masukan untuk mode urutannya
    scanf("%s", mode_urut);

    //meminta masukan untuk array 1
    scanf("%d", &n1);
    fresh arr1[n1];
    for(i = 0; i < n1; i++){
        scanf("%s %s %d %d %d", arr1[i].nama, arr1[i].pend, &arr1[i].durkul, &arr1[i].tskill, &arr1[i].atti);
    }

    //meminta masukan untuk array 2
    scanf("%d", &n2);
    fresh arr2[n2];
    for(i = 0; i < n2; i++){
        scanf("%s %s %d %d %d", arr2[i].nama, arr2[i].pend, &arr2[i].durkul, &arr2[i].tskill, &arr2[i].atti);
    }

    //meminta masukan untuk array 3
    scanf("%d", &n3);
    fresh arr3[n3];
    for(i = 0; i < n3; i++){
        scanf("%s %s %d %d %d", arr3[i].nama, arr3[i].pend, &arr3[i].durkul, &arr3[i].tskill, &arr3[i].atti);
    }

/*membuat program*/
    //mencari nilai value
    value(n1, arr1);
    value(n2, arr2);
    value(n3, arr3);

    //memanggil merge table (sorting dilakukan didalam prosedur merge table)
    //menyimpan tabel 1 dan 2
    fresh arrnew1[n1+n2];
    merge_sort(n1, arr1, n2, arr2, arrnew1, mode_urut);
    
    //menyimpan tabel 1, 2, dan 3
    fresh arrnew2[n1+n2+n3];
    merge_sort(n1+n2, arrnew1, n3, arr3, arrnew2, mode_urut);

/*menampilkan output sesuai input yang telah diproses*/
    print_arr(n1+n2+n3, arrnew2);

    return 0;
}