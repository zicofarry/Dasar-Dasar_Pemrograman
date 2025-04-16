/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Kuis 2 soal 1 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include "fresh24.h"//menggunakan library fresh24.h

void value(int n, fresh *arr){//mendeklarasikan prosedur untuk menyimpan nilai value dari setiap fresh graduate
    int temp[n];//mendeklarasikan nilai hasil sementara sebelum dijumlahkan dengan nilai pendidikannya
    for(int i = 0; i < n; i++){//melakukan loop for untuk mengisi hasil dari setiap indeksnya
        temp[i] = arr[i].tskill + arr[i].atti - arr[i].durkul;
        if(strcmp(arr[i].pend, "S1") == 0 || strcmp(arr[i].pend, "D4") == 0){//membuat kondisi jika pendidikannya S1/ D4
            arr[i].value = temp[i] + 20;//maka nilai valuenya ditambah 20
        }else if(strcmp(arr[i].pend, "D3") == 0){//membuat kondisi jika pendidikannya D3
            arr[i].value = temp[i] + 10;//maka nilai valuenya ditambah 10
        }
    }
}

int ave_value(int n, fresh *arr){//mendeklarasikan fungsi untuk menyimpan nilai rata rata value dari keseluruhan fresh graduate
    int ave = 0;//mendeklarasikan variabel untuk menampung nilai rata rata value
    for(int i = 0; i < n; i++){//melakukan looping for untuk mengisi nilai ave dengan menjumlahkan value pada setiap indeks
        ave += arr[i].value;//menjumlahkan ave dengan value pada setiap indeks
    }
    ave = ave / n;//membagi seluruh nilai value dengan jumlah orang yang memiliki value
    return ave;//mengembalikan nilai value
}

void swap(fresh *a, fresh *b){//membuat prosedur swap
    fresh temp = *a;//mengisi variabel temporary dengan a
    *a = *b;//mengisi nilai a dengan nilai b
    *b = temp;//mengisi kembali nilai b dengan nilai temporary yang tadi sudah disimpan
}

void bubble_sort(int n, fresh *arr){//membuat prosedur bubble sort
    int switched = 1;//mendeklarasikan dan marking nilai switched dengan 1 yang artinya true
    
    while(switched == 1){//selama switchednya masih 1 maka loop while akan terus diulang
        switched = 0;//marking switched dengan nilai 0 agar jika tidak masuk if dibawah loop akan berhenti
        for(int i = 0; i < n-1; i++){//loop untuk mengakses dan mensorting dengan algoritma bubble sort
            //membuat kondisi jika mode urutnya ascending atau descending
            if(arr[i].value < arr[i + 1].value){//jika nilai value indeks i lebih kecil dari indeks i+1 maka akan ditukar
                swap(&arr[i], &arr[i+1]);//menukar bungkusan
                switched = 1;//update nilai switched menjadi 1 lagi yang artinya masih terjadi penukaran dan while akan terus berlanjut
            }
        }
    }
}

int partition(fresh arr[], int low, int high){//membuat fungsi partition yang berfungsi untuk membagi indeks yang akan digunakan pada algortima quick sort
    fresh pivot = arr[high];//mengisi nilai pivot kanan
    int i = low - 1;//mengisi i dimulai dari -1
    for(int j = low; j < high; j++){//membuat perulangan dari indeks low sampai high
        if(arr[j].value > pivot.value){//jika nilai value indeks j lebih besar dari pivotnya
            i++;//indeks i bertambah
            swap(&arr[i], &arr[j]);//array bungkusannya ditukar
        }
    }
    swap(&arr[i+1], &arr[high]);//menukar sisa array bungkusan
    return i + 1;//mengembalikan nilai partisi
}

void quick_sort(fresh arr[], int low, int high){//membuat prosedur quick sort
    if(low < high){//jika masih memenuhi maka;
        int belah_idx = partition(arr, low, high);//mengisi indeks belahnya dengan memanggil fungsi partisi
        quick_sort(arr, low, belah_idx - 1);//memanggil kembali prosedur quick sort
        quick_sort(arr, belah_idx + 1, high);//memanggil kembali prosedur quick sort
    }
}

void merge_sort(int n1, fresh arr1[], int n2, fresh arr2[], fresh arr3[], char mode_urut[]){//mendeklarasikan prosedur untuk melakukan merging table secara terurut (sorting dilakukan di dalam prosedur)
    if(strcmp(mode_urut, "bubble") == 0){//jika mode urutannya bubble
        //melakukan sorting terlebih dahulu sebelum memulai merge table
        bubble_sort(n1, arr1);//memanggil prosedur bubble_sort untuk melakukan sorting terlebih dahulu
        bubble_sort(n2, arr2);//memanggil prosedur bubble_sort untuk melakukan sorting terlebih dahulu

        //deklarasi dan inisialisasi index untuk ketiga array
        int idx1 = 0, idx2 = 0, idx3 = 0;
        //loop sampai arr1 atau arr2 habis (salah satunya dulu)
        while(idx1 < n1 && idx2 < n2){
            //jika elemen arr1 lebih besar dari arr2
            if(arr1[idx1].value > arr2[idx2].value){
                //masukan elemen tersebut ke arr3
                arr3[idx3++] = arr1[idx1++];
            //jika elemen arr1 lebih kecil dari arr2
            }else if(arr1[idx1].value < arr2[idx2].value){
                //masukan elemen tersebut ke arr3
                arr3[idx3++] = arr2[idx2++];
            //jika elemen arr1 sama dengan arr2
            }else{
                //masukan kedua elemen tersebut ke arr3
                arr3[idx3++] = arr1[idx1++];
                arr3[idx3++] = arr2[idx2++];
            }
        }

        //jika ada sisa di arr1, maka masukan ke arr3
        while(idx1 < n1){
            arr3[idx3++] = arr1[idx1++];
        }
        
        //jika ada sisa di arr2, maka masukan ke arr3
        while(idx2 < n2){
            arr3[idx3++] = arr2[idx2++];
        }
    }else if(strcmp(mode_urut, "quick") == 0){
        //melakukan sorting terlebih dahulu sebelum memulai merge table
        quick_sort(arr1, 0, n1 - 1);//memanggil prosedur quick_sort untuk melakukan sorting terlebih dahulu
        quick_sort(arr2, 0, n2 - 1);//memanggil prosedur quick_sort untuk melakukan sorting terlebih dahulu

        //deklarasi dan inisialisasi index untuk ketiga array
        int idx1 = 0, idx2 = 0, idx3 = 0;
        //loop sampai arr1 atau arr2 habis (salah satunya dulu)
        while(idx1 < n1 && idx2 < n2){
            //jika elemen arr1 lebih besar dari arr2
            if(arr1[idx1].value > arr2[idx2].value){
                //masukan elemen tersebut ke arr3
                arr3[idx3++] = arr1[idx1++];
            //jika elemen arr1 lebih kecil dari arr2
            }else if(arr1[idx1].value < arr2[idx2].value){
                //masukan elemen tersebut ke arr3
                arr3[idx3++] = arr2[idx2++];
            //jika elemen arr1 sama dengan arr2
            }else{
                //masukan kedua elemen tersebut ke arr3
                arr3[idx3++] = arr1[idx1++];
                arr3[idx3++] = arr2[idx2++];
            }
        }

        //jika ada sisa di arr1, maka masukan ke arr3
        while(idx1 < n1){
            arr3[idx3++] = arr1[idx1++];
        }
        
        //jika ada sisa di arr2, maka masukan ke arr3
        while(idx2 < n2){
            arr3[idx3++] = arr2[idx2++];
        }
    }
}

void print_arr(int n, fresh *arr){//mendeklarasikan prosedur untuk melakukan print output sesuai output yang diinginkan soal
    for(int i = 0; i < n; i++){//melakukan looping for untuk memprint sesuai format pada setiap indeksnya
        printf("%s %s %d %d %d Value: %d\n", arr[i].nama, arr[i].pend, arr[i].durkul, arr[i].tskill, arr[i].atti, arr[i].value);
    }

    printf("\nValue Rata-rata: %d\n", ave_value(n, arr));//memprint rata rata nilai value pada seluruh fresh graduate
}