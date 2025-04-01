/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tugas praktikum 7 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include <stdio.h>
#include <string.h>

typedef struct{
    char judul[101];
    float durasi;
}lagu;

void swap(lagu *a, lagu *b){//membuat prosedur swap
    lagu temp = *a;//mengisi variabel temporary dengan a
    *a = *b;//mengisi nilai a dengan nilai b
    *b = temp;//mengisi kembali nilai b dengan nilai temporary yang tadi sudah disimpan
}


int partition(lagu arr[], int low, int high){//membuat fungsi partition yang berfungsi untuk membagi indeks yang akan digunakan pada algortima quick sort
    lagu pivot = arr[high];//mengisi nilai pivot kanan
    int i = low - 1;//mengisi i dimulai dari -1
    for(int j = low; j < high; j++){//membuat perulangan dari indeks low sampai high
        if(arr[j].durasi > pivot.durasi){//jika ukuran indeks j lebih kecil dari pivotnya
            i++;//indeks i bertambah
            swap(&arr[i], &arr[j]);//array bungkusannya ditukar
        }
    }
    swap(&arr[i+1], &arr[high]);//menukar sisa array bungkusan
    return i + 1;//mengembalikan nilai partisi
    
}

void quick_sort(lagu arr[], int low, int high){//membuat prosedur quick sort
    if(low < high){//jika masih memenuhi maka;
        int belah_idx = partition(arr, low, high);//mengisi indeks belahnya dengan memanggil fungsi partisi
        quick_sort(arr, low, belah_idx - 1);//memanggil kembali prosedur quick sort
        quick_sort(arr, belah_idx + 1, high);//memanggil kembali prosedur quick sort
    }
}

void merge_sort(int n1, lagu arr1[], int n2, lagu arr2[], lagu arr3[]){
    //sorting terlebih dahulu sebelum merging
    quick_sort(arr1, 0, n1 - 1);
    quick_sort(arr2, 0, n2 - 1);
    //deklarasi dan inisialisasi index untuk ketiga array
    int idx1 = 0, idx2 = 0, idx3 = 0;
    //loop sampai arr1 atau arr2 habis (salah satunya dulu)
    while(idx1 < n1 && idx2 < n2){
        //jika elemen arr1 lebih kecil dari arr2
        if(arr1[idx1].durasi > arr2[idx2].durasi){
            //masukan elemen tersebut ke arr3
            arr3[idx3++] = arr1[idx1++];
        }else if(arr1[idx1].durasi < arr2[idx2].durasi){
            //masukan elemen tersebut ke arr3
            arr3[idx3++] = arr2[idx2++];
        }else{
            //masukan elemen tersebut ke arr3
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

void print_arr(int n, lagu *arr){
    printf("----------------------------------------\n");
    printf(" Playlist setelah digabungkan :\n");
    printf("----------------------------------------\n");
    for(int i = 0; i < n; i++){
        printf("%s - %.2f\n", arr[i].judul, arr[i].durasi);
    }
}

void belahkata(char *judul, char kata[][100], int *jumlah_kata) {
    int k = 0, j = 0;
    for (int i = 0; judul[i] != '\0'; i++) {
        if (judul[i] == '_') {
            kata[k][j] = '\0';  // Menyelesaikan kata saat menemukan '_'
            k++;
            j = 0;
        } else {
            kata[k][j++] = judul[i];
        }
    }
    kata[k][j] = '\0';  // Menambahkan kata terakhir
    *jumlah_kata = k + 1;  // Mengatur jumlah kata
}

int compare(char a, char b) {
    // Jika a dan b adalah huruf kapital, ubah ke huruf kecil untuk perbandingan
    if (a >= 'A' && a <= 'Z') {
        a = a + 32;  // Ubah ke huruf kecil
    }
    if (b >= 'A' && b <= 'Z') {
        b = b + 32;  // Ubah ke huruf kecil
    }
    return a == b;  // Perbandingan karakter setelah diubah
}

int carikata(char *kata, char *cari) {
    int lenKata = strlen(kata);
    int lenCari = strlen(cari);

    // Periksa setiap kemungkinan posisi dalam 'kata' untuk mencocokkan 'cari'
    for (int i = 0; i <= lenKata - lenCari; i++) {
        int j = 0;
        // Bandingkan substring mulai dari posisi i
        while (j < lenCari && compare(kata[i + j], cari[j])) {
            j++;
        }
        // Jika semua karakter cocok, maka ditemukan substring
        if (j == lenCari) {
            return 1; // Substring ditemukan
        }
    }
    return 0; // Substring tidak ditemukan
}

// Prosedur untuk mencari lagu yang mengandung kata yang dicari
void sequentialSearch(int n, lagu *arr, char cari[], lagu *arrx) {
    int found = 0;  // Flag untuk menandakan apakah ditemukan atau tidak
    int idx = 0;    // Indeks untuk menambahkan lagu yang ditemukan
    char kata[100][100]; // Array untuk menyimpan kata-kata dari judul
    // if(cari[0] >= 'a' && cari[0] <= 'z'){
    //     cari[0] -= 32; 
    // }

    // Loop untuk mengecek setiap lagu dalam array
    for (int i = 0; i < n; i++) {
        int jumlah_kata = 0;
        belahkata(arr[i].judul, kata, &jumlah_kata);  // Pisahkan judul lagu menjadi kata-kata

        // Loop untuk mencari kata yang cocok dengan kata yang dicari
        for (int j = 0; j < jumlah_kata; j++) {
            if (carikata(kata[j], cari)) {  // Jika kata ditemukan sebagai substring
                arrx[idx++] = arr[i];  // Tambahkan lagu ke hasil pencarian
                found = 1;
                break;  // Tidak perlu lanjutkan pencarian kata lain dalam lagu ini
            }
        }
    }
    arrx[idx].durasi = -1;

    // Tampilkan hasil pencarian
    printf("\n----------------------------------------\n");
    printf(" Playlist yang memiliki kata kunci :\n");
    printf("----------------------------------------\n");

    if (found) {
        for (int i = 0; i < idx; i++) {
            printf("%s - %.2f\n", arrx[i].judul, arrx[i].durasi);
        }
    } else {
        printf("Tidak ada lagu yang sesuai\n");
    }
}


//ini belum bener
void binarySearch(int n, lagu arr[], float mindur){
    //deklarasi found, left, right
    int found = 0;      //buat flag (asumsi belum ketemu)
    int left = 0;       //index kiri
    int right = n - 1;  //index kanan
    int idx= 0;  

    // if(arr[right].durasi > mindur){
    //     idx = right;
    //     found = 1;
    // }else{
        //loop sampai ketemu atau tidak ada elemen lagi
    while (left <= right) {
        int mid = (left + right) / 2;  // Menentukan indeks tengah

        // Jika durasi lagu di tengah lebih besar atau sama dengan durasi minimal
        if (arr[mid].durasi >= mindur) {
            found = 1;
            idx = mid;
            // Mulai menyalin semua lagu yang memenuhi durasi minimal
            for (int i = mid; i < n; i++) {
                if (arr[i].durasi >= mindur) {
                    //arrx[idx] = arr[i];  // Menambahkan lagu yang memenuhi syarat
                    idx++;
                } else {
                    break;  // Hentikan jika sudah tidak ada lagu yang memenuhi syarat
                }
            }
            break;  // Keluar dari loop karena pencarian selesai
        } else {
            right = mid - 1;  // Jika durasi lagu di tengah lebih kecil, pindah ke kanan
        }
    }
    //printf("%d\n", idx);
    
    printf("\n----------------------------------------\n");
    printf(" Playlist yang memenuhi minimal durasi:\n");
    printf("----------------------------------------\n");
    if(found == 1){
        for(int i = 0; i < idx; i++){
            printf("%s - %.2f\n", arr[i].judul, arr[i].durasi);
        }
    }else{
        printf("Tidak ada lagu yang sesuai\n");
    }
}


int main(){
    /*mendeklarasikan variabel untuk menampung nilai
    i = untuk counting loop for
    n1 = jumlah bungkusan array 1
    n2 = jumlah bungkusan array 2
    n3 = jumlah bungkusan array 3
    cari = string yang akan dicari*/
    int i;
    int n1, n2, n3;
    char cari[51];
    float mindur;

/*meminta masukan dari user*/
    //masukan untuk jumlah bungkusan pada array 1
    scanf("%d", &n1);

    //masukan isi dari setiap bungkusan
    lagu arr1[n1];
    for(i = 0; i < n1; i++){
        scanf("%s %f", arr1[i].judul, &arr1[i].durasi);
    }
    
    //masukan untuk jumlah bungkusan pada array 2
    scanf("%d", &n2);

    //masukan isi dari setiap bungkusan
    lagu arr2[n2];
    for(i = 0; i < n2; i++){
        scanf("%s %f", arr2[i].judul, &arr2[i].durasi);
    }

    //masukan untuk jumlah bungkusan pada array 3
    scanf("%d", &n3);

    //masukan isi dari setiap bungkusan
    lagu arr3[n3];
    for(i = 0; i < n3; i++){
        scanf("%s %f", arr3[i].judul, &arr3[i].durasi);
    }
    

    //masukan untuk kata kunci yang akan dicari
    scanf("%s", cari);

    //masukan untuk jumlah minimal halaman
    scanf("%f", &mindur);
    mindur = (int) (mindur/60) + ((mindur - (int)(mindur / 60) * 60) / 100);
    // printf("%.2f\n", mindur);

/*membuat program*/

    //merging table
    //menyimpan array 1 dan 2 
    lagu arrnew1[n1+n2];
    merge_sort(n1, arr1, n2, arr2, arrnew1);


    //menyimpan array 1, 2 dan 3 
    lagu arrnew2[n1+n2+n3];
    merge_sort(n1+n2, arrnew1, n3, arr3, arrnew2);

/*menampilkan output sesuai input yang telah diproses*/
    print_arr(n1+n2+n3, arrnew2);

    // for(i = 0; i < n1+n2+n3; i++){
    //     belahkata(&arrnew2[i]);
    // }
    lagu arrnew3[101];
    sequentialSearch(n1+n2+n3, arrnew2, cari, arrnew3);
    int count = 0;
    while(arrnew3[count].durasi != -1){
        count++;
    }

// printf("%d\n", count);
    binarySearch(count, arrnew3, mindur);

    return 0;
}