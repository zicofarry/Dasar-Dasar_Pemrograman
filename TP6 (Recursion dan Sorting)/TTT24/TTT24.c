/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tugas praktikum 6 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include "TTT24.h"//menggunakan library TTT24.h

void win(player pow, player finn, int t, int n, player *lolos){//mendeklarasikan prosuder untuk menentukan pemenang dan mengetahui setiap serangan yang dilakukan
    //base case:
    if(t < 1 || pow.hp < 1 || finn.hp < 1){//jika t, hp pow, dan hp finnnya masih belum 0
        if(pow.hp > finn.hp){//jika hp pow lebih besar dari hp finn
            printf("[ Pow-Pow menang ]\n");//maka print Pow-Pow sebagai pemenang
            strcpy(pow.nama, "Pow-Pow");//maka isi pow.nama dengan "Pow-Pow"
            lolos[n] = pow;//pow masuk ke array pemain yang lolos ke leaderboard
            lolos[n+1].hp = -1;//marking -1 untuk menandakan ujung array
        }else if(pow.hp < finn.hp){//jika hp pow lebih kecil dari hp finn 
            printf("[ Finn menang ]\n");//maka print Finn sebagai pemenang
            strcpy(finn.nama, "Finn");//maka isi finn.nama dengan "Finn"
            lolos[n] = finn;//finn masuk ke array pemain yang lolos ke leaderboard
            lolos[n+1].hp = -1;//marking -1 untuk menandakan ujung array
        }else{//jika hp pow sama dengan hp finn
            printf("[ Pertandingan seri ]\n");//maka print Pertandingan Seri
            strcpy(finn.nama, "Finn");//maka isi finn.nama dengan "Finn"
            strcpy(pow.nama, "Pow-Pow");//maka isi pow.nama dengan "Pow-Pow"
            lolos[n] = pow;//pow masuk ke array pemain yang lolos ke leaderboard
            lolos[n+1] = finn;//finn masuk ke array pemain yang lolos ke leaderboard
            lolos[n+2].hp = -1;//marking -1 untuk menandakan ujung array
        }
        return;//maka rekursif berhenti
    }

    //melakukan serangan pertama
    finn.dmgx = (pow.hp + finn.hp) % 3;//menghitung bonus damage
    pow.hp -= finn.dmg + finn.dmgx;//mengurangi hp lawan
    if(pow.hp < 0) pow.hp = 0;//jika hp nya kurang dari 0, maka buat jadi 0
    printf("F->P | DMG: %d (+ %d) | HP: P = %d F = %d\n", finn.dmg, finn.dmgx, pow.hp, finn.hp);//print record serangan
    t--;//1 kali serangan sudah digunakan maka t dikurangi 1

    //gunakan base case kembali untuk mengecek proses karena sudah melakukan 1 kali serangan
    if(t < 1 || pow.hp < 1 || finn.hp < 1){//jika t, hp pow, dan hp finnnya masih belum 0
        if(pow.hp > finn.hp){//jika hp pow lebih besar dari hp finn
            printf("[ Pow-Pow menang ]\n");//maka print Pow-Pow sebagai pemenang
            strcpy(pow.nama, "Pow-Pow");//maka isi pow.nama dengan "Pow-Pow"
            lolos[n] = pow;//pow masuk ke array pemain yang lolos ke leaderboard
            lolos[n+1].hp = -1;//marking -1 untuk menandakan ujung array
        }else if(pow.hp < finn.hp){//jika hp pow lebih kecil dari hp finn 
            printf("[ Finn menang ]\n");//maka print Finn sebagai pemenang
            strcpy(finn.nama, "Finn");//maka isi finn.nama dengan "Finn"
            lolos[n] = finn;//finn masuk ke array pemain yang lolos ke leaderboard
            lolos[n+1].hp = -1;//marking -1 untuk menandakan ujung array
        }else{//jika hp pow sama dengan hp finn
            printf("[ Pertandingan seri ]\n");//maka print Pertandingan Seri
            strcpy(finn.nama, "Finn");//maka isi finn.nama dengan "Finn"
            strcpy(pow.nama, "Pow-Pow");//maka isi pow.nama dengan "Pow-Pow"
            lolos[n] = pow;//pow masuk ke array pemain yang lolos ke leaderboard
            lolos[n+1] = finn;//finn masuk ke array pemain yang lolos ke leaderboard
            lolos[n+2].hp = -1;//marking -1 untuk menandakan ujung array
        }
        return;//maka rekursif berhenti
    }
    
    //melakukan serangan lanjutan
    pow.dmgx = (pow.hp + finn.hp) % 3;//menghitung bonus damage
    finn.hp -= pow.dmg + pow.dmgx;//mengurangi hp lawan
    if(finn.hp < 0) finn.hp = 0;//jika hp nya kurang dari 0, maka buat jadi 0
    printf("P->F | DMG: %d (+ %d) | HP: P = %d F = %d\n", pow.dmg, pow.dmgx, pow.hp, finn.hp);//print record serangan
    t--;//1 kali serangan sudah digunakan maka t dikurangi 1

    //memanggil rekursif
    win(pow, finn, t, n, lolos);

}

void swap(player *a, player *b){//membuat prosedur swap
    player temp = *a;//mengisi variabel temporary dengan a
    *a = *b;//mengisi nilai a dengan nilai b
    *b = temp;//mengisi kembali nilai b dengan nilai temporary yang tadi sudah disimpan
}

void bubble_sort(int n, player *lolos){//membuat prosedur bubble sort
    int switched = 1;//mendeklarasikan dan marking nilai switched dengan 1 yang artinya true
    
    while(switched == 1){//selama switchednya masih 1 maka loop while akan terus diulang
        switched = 0;//marking switched dengan nilai 0 agar jika tidak masuk if dibawah loop akan berhenti
        for(int i = 0; i < n-1; i++){//loop untuk mengakses dan mensorting dengan algoritma bubble sort
            if(lolos[i].hp < lolos[i+1].hp){//jika hp indeks i lebih kecil dari indeks i+1
                swap(&lolos[i], &lolos[i+1]);//menukar bungkusan indeks i dengan indeks i+1
                switched = 1;//update nilai switched menjadi 1 lagi yang artinya masih terjadi penukaran dan while akan terus berlanjut
            }else if(lolos[i].hp == lolos[i+1].hp){//jika hp indeks i sama dengan hp indeks i+1
                if(lolos[i].dmg < lolos[i+1].dmg){//jika damage indeks i lebih kecil dari indeks i+1
                    swap(&lolos[i], &lolos[i+1]);//menukar bungkusan indeks i dengan indeks i+1
                    switched = 1;//update nilai switched menjadi 1 lagi yang artinya masih terjadi penukaran dan while akan terus berlanjut
                }else if(lolos[i].dmg == lolos[i+1].dmg){//jika damage indeks i sama dengan damage indeks i+1
                    if(strcmp(lolos[i].nama, lolos[i+1].nama) > 0){//jika nama indeks i lebih kecil dari indeks i+1
                        swap(&lolos[i], &lolos[i+1]);//menukar bungkusan indeks i dengan indeks i+1
                        switched = 1;//update nilai switched menjadi 1 lagi yang artinya masih terjadi penukaran dan while akan terus berlanjut
                    }
                }
            }          
        }
    }
}


int partition(player lolos[], int low, int high){//membuat fungsi partition yang berfungsi untuk membagi indeks yang akan digunakan pada algortima quick sort
    player pivot;//mendeklarasikan bungkusan pivot
    pivot = lolos[high];//mengisi nilai pivot kanan
    int i = low - 1;//mengisi i dimulai dari -1
    for(int j = low; j < high; j++){//membuat perulangan dari indeks low sampai high
        if(lolos[j].hp > pivot.hp){//jika hp indeks j lebih besar dari pivotnya
            i++;//maka indeks i bertambah
            swap(&lolos[i], &lolos[j]);//maka bungkusan lolos indeks i ditukar dengan indeks j
        }else if(lolos[j].hp == pivot.hp){//jika damage indeks j sama dengan pivotnya
            if(lolos[j].dmg > pivot.dmg){//jika damage indeks j lebih besar dari pivotnya
                i++;//maka indeks i bertambah
                swap(&lolos[i], &lolos[j]);//maka bungkusan lolos indeks i ditukar dengan indeks j
            }else if(lolos[j].dmg == pivot.dmg){//jika damage indeks j sama dengan pivotnya
                if(strcmp(lolos[j].nama, pivot.nama) < 0){//jika nama indeks j lebih besar dari pivotnya
                    i++;//maka indeks i bertambah
                    swap(&lolos[i], &lolos[j]);//maka bungkusan lolos indeks i ditukar dengan indeks j
                }
            }
        }     
    }
    swap(&lolos[i+1], &lolos[high]);//menukar sisa array bungkusan
    return i + 1;//mengembalikan nilai partisi
}

void quick_sort(player lolos[], int low, int high){//membuat prosedur quick sort
    if(low < high){//jika masih memenuhi maka;
        int belah_idx = partition(lolos, low, high);//mengisi indeks belahnya dengan memanggil fungsi partisi
        quick_sort(lolos, low, belah_idx - 1);//memanggil kembali prosedur quick sort
        quick_sort(lolos, belah_idx + 1, high);//memanggil kembali prosedur quick sort
    }
}

int digit(int n){//membuat fungsi untuk menghitung jumlah digit
    int count = 0;//count dimulai dari 0
    if(n == 0){//jika angka nya 0 
        count = 1;//maka dihitung sebanyak 1 digit
    }else{//jika lebih dari 0
        while (n != 0){//loop while selama angkanya tidak 0
            n /= 10;//angka dibagi 10
            count++;//setiap dibagi 10, count bertambah 1
        }
    }

    return count;//mengembalikan nilai count
}

void leaderboard(int n, player *lolos){//mendeklarasikan prosedur untuk memprint leaderboard sesuai data yang telah diproses
    /*mendeklarasikan variabel untuk menampung nilai
    i = counting untuk loop for
    j = counting untuk loop for di dalam loop for
    count = counting untuk mengecek jumlah dari array bungkusan (cek sampai ketemu marking -1)*/
    int i, j;
    int count = 0;

    //memprint leaderboard
    printf("\n<<< Leaderboard >>>\n");
    
    //memprint baris atas
    printf("+----+-");
    int max = 0;//membuat variabel untuk menampung panjang maksimal dari string nama yang ada dalam bungkusan
    int space = 0;//membuat variabel untuk menampung jumlah spasi
    
    for(i = 0; i < n; i++){
        if(max < strlen(lolos[i].nama)){//jika ada strlen nama yang lebih panjang
            max = strlen(lolos[i].nama);//maka update nilai max nya
        }
    }

    if(max > 12){//jika maksimalnya lebih dari 12
        for(i = 0; i < max; i++){//maka print '-' sebanyak panjang maksimalnya
            printf("-");
        }
        
    }else{//jika kurang atau sama dengan 12
        for(i = 0; i < 12; i++){
            printf("-");//maka print '-' sebanyak 12 kali
        }
    }
    printf("-+---------------+");
    printf("--------+\n");

    //memprint baris judul
    printf("| No | Nama Peserta ");
    space = max - 12;//spasi didapatkan dari panjang maksimal dikurang 12
    if(space < 1) space = 0;//jika spasinya negatif, maka spasinya 0
    for(i = 0; i < space; i++){
        printf(" ");//print ' ' sebanyak jumlah spasi
    }
    printf("| Health Points | Damage |\n");

    //memprint baris dibawah judul
    printf("+----+-");

    for(i = 0; i < n; i++){
        if(max < strlen(lolos[i].nama)){//jika ada strlen nama yang lebih panjang
            max = strlen(lolos[i].nama);//maka update nilai max nya
        }
    }

    if(max > 12){
        for(i = 0; i < max; i++){
            printf("-");//maka print '-' sebanyak panjang maksimalnya
        }
        
    }else{
        for(i = 0; i < 12; i++){
            printf("-");//maka print '-' sebanyak 12 kali
        }
    }
    printf("-+---------------+");
    printf("--------+\n");
    
    //memprint isi leadearboard
    for(i = 0; i < n; i++){//melakukan loop sebanyak jumlah array nya
        //memprint no rank leaderboard
        if(i > 8){//jika no nya lebih dari 1 digit
            printf("| %d | ", i + 1);//maka print tanpa spasi setelahnya
        }else{//jika hanya 1 digit
            printf("| %d  | ", i + 1);//maka print dengan spasi setelahnya agar rata
        }

        //memprint nama player
        printf("%s", lolos[i].nama);
        if(max > 12){//jika panjang maksimal stringnya lebih dari 12, maka;
            space = max - strlen(lolos[i].nama);//spasi didapatkan dari max string dikurangi string indeks i
            if(space < 1) space = 0;//jika spasinya negatif maka spasinya 0
            for(j = 0; j < space; j++){
                printf(" ");//print ' ' sebanyak jumlah spasi
            }
        }else{//jika panjang maksimal stringnya kurang / sama dengan 12, maka;
            space = 12 - strlen(lolos[i].nama);//spasi didapatkan dari 12 dikurang panjang string indeks i
            if(space < 1) space = 0;//jika spasinya negatif maka spasinya 0
            for(j = 0; j < space; j++){
                printf(" ");//print ' ' sebanyak jumlah spasi
            }
        }

        //memprint hp player
        printf(" | %d", lolos[i].hp);
        //menghitung spasi didapatkan dari 13 dikurang jumlah digit hp
        space = 13 - digit(lolos[i].hp);
        for(j = 0; j < space; j++){
            printf(" ");//print ' ' sebanyak jumlah spasi
        }

        //memprint damage player
        printf(" | %d", lolos[i].dmg);
        //menghitung spasi didapatkan dari 6 dikurang jumlah digit damage
        space = 6 - digit(lolos[i].dmg);
        for(j = 0; j < space; j++){
            printf(" ");//print ' ' sebanyak jumlah spasi
        }
        printf(" |\n");
    }

    //memprint baris di bawah leaderboard
    printf("+----+-");

    for(i = 0; i < n; i++){
        if(max < strlen(lolos[i].nama)){//jika ada strlen nama yang lebih panjang
            max = strlen(lolos[i].nama);//maka update nilai max nya
        }
    }

    if(max > 12){
        for(i = 0; i < max; i++){
            printf("-");//maka print '-' sebanyak panjang maksimalnya
        }
        
    }else{
        for(i = 0; i < 12; i++){
            printf("-");//maka print '-' sebanyak 12 kali
        }
    }
    printf("-+---------------+");
    printf("--------+\n");
}