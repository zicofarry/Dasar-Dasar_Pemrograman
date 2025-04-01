/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tugas praktikum 4 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include <stdio.h>//menggunakan library stdio.h
#include <string.h>//menggunakan library string.h

typedef struct{//membuat bungkusan dengan isi nama, zona, waktu, jam waktu, dan menit waktu
    char nama[51];
    int zona;
    int waktu, wakhour, wakminu;
}misi;

int main(){
    /*mendeklarasikan variabel untuk menampung nilai
    arr = bungkusan misi dengan isi nama, zona, dan waktu
    danger = bungkusan misi berbahaya isi nama, zona, dan waktu
    save = bungkusan misi aman dengan isi nama, zona, dan waktu
    n = jumlah pesan rahasia
    i = counting untuk looping for
    j = counting untuk looping for
    k = counting untuk looping for
    jam = jam sekarang
    menit = menit sekarang
    durasi = jumlah waktu perjalanan ke rumania (menit)
    count = jumlah misi
    cdanger = jumlah misi berbahaya
    csave = jumlah misi aman
    countcc = jumlah huruf konsonan
    huruf = jumlah huruf
    secmes = pesan rahasia
    dep = waktu berangkat
    arv = waktu kedatangan
    depjam = jam berangkat
    depmin = menit berangkat
    arvjam = jam kedatangan
    arvmin = menit kedatangan*/
    misi arr[51], danger[51], save[51];
    int n, i, j, k, jam, menit, durasi;
    int count = 0, cdanger = 0, csave = 0, countcc = 0;
    char secmes[51][101];
    int huruf = 0, dep = 0, arv = 0;
    int depjam, depmin, arvjam, arvmin;

/*Meminta input dari user*/
    i = 0;
    int c = 1;//marking untuk true pada loop while
    while(c == 1){
        scanf("%s", arr[i].nama);
        if(strcmp(arr[i].nama, "end") == 0) {//membuat kondisi jika stringnya "end" maka false dan loop berhenti
            c = 0;
        }else{
        scanf("%d %d", &arr[i].zona, &arr[i].waktu);//jika masih true maka meminta masukan untuk zona dan waktu
        i++;//counting untuk isi array nya
        count++;//counting untuk jumlah misi
        }
    }
    i--;//memundurkan isi array

    //meminta input untuk jumlah pesan rahasia
    scanf("%d", &n);

    //meminta input untuk pesan rahasia
    for(i = 0; i < n; i++){
        scanf("%s", secmes[i]);
    }

    //meminta input untuk jam dan menit sekarang
    scanf("%d %d", &jam, &menit);

    //meminta input untuk jumlah waktu perjalanan ke rumania dalam menit
    scanf("%d", &durasi);

/*Membuat program*/
    //membuat program untuk aktivitas berbahaya
    for(i = 0; i < count; i++){
        //membuat kondisi jika berada pada zona 3 atau 4
        if(arr[i].zona == 3 || arr[i].zona == 4){
            strcpy(danger[cdanger].nama, arr[i].nama);//memindahkan string misi ke string danger
            if(arr[i].waktu >= 60){//jika waktu lebih dari atau sama dengan 60
                danger[cdanger].wakhour= arr[i].waktu / 60;//untuk jam
                danger[cdanger].wakminu = arr[i].waktu % 60;//untuk menit
            }else{//jika kurang dari 60
                danger[cdanger].wakhour = 0;//untuk jam
                danger[cdanger].wakminu = arr[i].waktu;//untuk menit
            }
            cdanger++;//count up untuk danger
        }else if(arr[i].zona == 1 || arr[i].zona == 2){//membuat kondisi jika berada pada zona 1 atau 2
            strcpy(save[csave].nama, arr[i].nama);//memindahkan string misi ke string save
            if(arr[i].waktu >= 60){//jika waktu lebih dari atau sama dengan 60
                save[csave].wakhour = arr[i].waktu / 60;//untuk jam
                save[csave].wakminu = arr[i].waktu % 60;//untuk menit
            }else{//jika kurang dari 60
                save[csave].wakhour = 0;//untuk jam
                save[csave].wakminu = arr[i].waktu;//untuk menit
            }
            csave++;//count up untuk save
        }
    }


    //menghitung jumlah geser enkripsi caesar cipher
    for(i = 0; i < n; i++){
        for(j = 0; j < strlen(secmes[i]); j++){
            //membuat kondisi untuk menghitung jumlah huruf konsonan
            if(secmes[i][j] != 'a' && secmes[i][j] != 'i' &&
                secmes[i][j] != 'u' && secmes[i][j] != 'e' &&
                secmes[i][j] != 'o' && secmes[i][j] != '_'){
                    countcc++;
            }
            //membuat kondisi untuk menghitung jumlah huruf
            if(secmes[i][j] != '_'){
                huruf++;
            }
        }
    }

    //membuat program dengan enkripsi caesar cipher
    for(i = 0; i < n; i++){
        for (j = 0; j < strlen(secmes[i]); j++){
            //membuat enkripsi bergeser sesuai jumlah huruf vocal untuk enkripsi caesar cipher
            for(k = 0; k < countcc; k++){
                //membuat kondisi jika char ada pada range alphabet
                if((secmes[i][j] >= 'a') && (secmes[i][j] <= 'z')){
                    secmes[i][j]++;
                    if(secmes[i][j] > 'z'){
                        secmes[i][j] = 'a';//mengembalikan ke huruf a jika char sudah melampaui batas huruf z
                    }
                }
            }
            //jika char merupakan '_' maka tetap
            if(secmes[i][j] == '_'){
                secmes[i][j] = '_';
            }
        }
        secmes[i][j] = '\0';//mengisi null term pada setiap akhir string
    }

    //membuat program untuk mengkapitalkan berdasarkan ganjil genap
    for(i = 0; i < n; i++){
        for(j = 0; j < strlen(secmes[i]); j++){
            //membuat kondisi untuk setiap alphabet
            if(secmes[i][j] != '_'){
                //membuat kondisi jika indeks char nya ganjil
                if(j % 2 == 1){
                    secmes[i][j] -= 32;//maka diupdate menjadi uppercase
                }
            }
        }
    }

    //membuat perhitungan jam berangkat
    dep = jam*60 + menit + huruf*2;//mengisi menit berangkat dengan jam sekarang + menit sekarang + 2 menit setiap huruf yang dienkripsi
    for(i = 0; i < count; i++){
        dep += arr[i].waktu;//menambahkan menit berangkat dengan waktu pada setiap misi
    }


    depjam = (dep / 60) % 24;
    depmin = dep % 60;

    //membuat perhitungan jam kedatangan
    arv = dep + durasi;
    arvjam = (arv / 60) % 24;
    arvmin = arv % 60;


/*Menghasilkan output sesuai program*/
    //memprint zona berbahaya
    printf("Get Collapse-Radiationed lol\n");
    for(i = 0; i < cdanger; i++){//looping untuk setiap misi pada zona berbahaya
        printf("%d. %s: %d hour(s) %d minute(s)\n", i+1, danger[i].nama, danger[i].wakhour, danger[i].wakminu);
    }

    //memprint zona aman
    printf("\nFinally, some reasonable requests\n");
    for(i = 0; i < csave; i++){//looping untuk setiap misi pada zona aman
        printf("%d. %s: %d hour(s) %d minute(s)\n", i+1, save[i].nama, save[i].wakhour, save[i].wakminu);
    }

    //memprint space
    printf("\n----------------------------------------\n");

    //memprint hasil enkripsi
    printf("Glory to the NUSSR, death to the Rossies:\n");
    for(i = 0; i < n; i++){//looping untuk setiap pesan rahasia yang telah dienkripsi
        printf("%s\n", secmes[i]);
    }

    //memprint space
    printf("----------------------------------------\n\n");

    //memprint jam berangkat
    if(depjam > 9 && depmin > 9){//membuat kondisi penulisan jam dan menit sesuai digit (harus selalu 2 digit)
        printf("Speeding through Romania at %d:%d\n", depjam, depmin);//jika jam 2 digit dan menit 2 digit
    }else if(depjam > 9 && depmin <=9){
        printf("Speeding through Romania at %d:0%d\n", depjam, depmin);//jika jam 2 digit dan menit 1 digit
    }else if(depjam <= 9 && depmin > 9){
        printf("Speeding through Romania at 0%d:%d\n", depjam, depmin);//jika jam 1 digit dan menit 2 digit
    }else if(depjam <= 9 && depmin <=9){
        printf("Speeding through Romania at 0%d:0%d\n", depjam, depmin);//jika jam 1 digit dan menit 1 digit
    }

    //memprint jam kedatangan
    if(arvjam > 9 && arvmin > 9){//membuat kondisi penulisan jam dan menit sesuai digit (harus selalu 2 digit)
        printf("Arrived at SO-9 at %d:%d\n", arvjam, arvmin);//jika jam 2 digit dan menit 2 digit
    }else if(arvjam > 9 && arvmin <= 9){
        printf("Arrived at SO-9 at %d:0%d\n", arvjam, arvmin);//jika jam 2 digit dan menit 1 digit
    }else if(arvjam <= 9 && arvmin > 9){
        printf("Arrived at SO-9 at 0%d:%d\n", arvjam, arvmin);//jika jam 1 digit dan menit 2 digit
    }else if(arvjam <= 9 && arvmin <= 9){
        printf("Arrived at SO-9 at 0%d:0%d\n", arvjam, arvmin);//jika jam 1 digit dan menit 1 digit
    }

    //memprint space
    printf("\n----------------------------------------\n\n");

    //memprint pesan
    if(arvjam >= 0 && arvjam < 6){//jika sebelum jam 6 (waktu tidur)
        printf("A mimir\n");
    }else if(arvjam >= 6 && arvjam <= 12){//jika jam 6 - 12 (waktu santuy)
        printf("Alrighty, its pretty chill right now, lets see, FROM THE SCREEN TO THE RING TO THE PEN TO THE KING!!!!\n");
    }else if(arvjam > 12 && arvjam <= 23){//jika setelah jam 12 (rush hour)
        printf("Time to become the Shining Edge in this brave new world, oh look whos he- GET OUT\n");
    }

    return 0;
}