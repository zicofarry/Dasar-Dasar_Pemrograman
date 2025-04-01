/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tugas praktikum 2 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include <stdio.h>//bagian header (library)

/*menyimpan nilai tinggi, jumlah ruas, dan ketebalan
di dalam bungkusan ikan*/
typedef struct {
    int tinggi;
    int ruas;
    int tebal;
} ikan;

int main() {
    /*membuat variabel untuk menampung nilai 
	ikan boba = ikan milik si boba
	ikan kentang = ikan milik si kentang
	ikan ucul = ikan milik si ucul
	jenis = jenis ikan yang dimiliki boba
	huruf = bagian kepala ikan menggunakan alphabet
    b = jumlah baris 
    k = jumlah kolom*/
    ikan boba, kentang, ucul;
    char jenis;
    char huruf = 'a';
    int b, k;

    //meminta input dari user
    scanf("%d %c\n", &boba.tinggi, &jenis);//meminta input untuk tinggi dan jenis ikan yang dimiliki boba
	scanf("%d %d %d\n", &kentang.tinggi, &kentang.ruas, &kentang.tebal);//meminta input untuk tinggi, jumlah ruas, dan ketebalan ikan yang dimiliki kentang
	scanf("%d %d %d", &ucul.tinggi, &ucul.ruas, &ucul.tebal);//meminta input untuk tinggi, jumlah ruas, dan ketebalan ikan yang dimiliki ucul

    //membuat pilihan untuk jenis-jenis ikan yang dimiliki boba
    switch (jenis) {
        case 'L': //jenis ikan lele
            boba.ruas = 8;
            boba.tebal = 3;
            break;
        case 'M': //jenis ikan mas
            boba.ruas = 3;
            boba.tebal = 5;
            break;
        case 'N': //jenis ikan nila
            boba.ruas = 5;
            boba.tebal = 1;
            break;
        default:
            printf("jenis ikan tidak dikenali.\n");//ketika input jenis ikan selain L, N, dan M.
            break;
    }


    //membuat ikan milik boba bagian atas
    for(b=1;b<=boba.tinggi/2;b++){
        for(k=2;k<=b;k++){
            printf(" ");//membuat jarak sebelum ekor
        }
        for(k=1;k<=b;k++){
            printf("*");//membuat ekor ikan bagian atas
        }

        for(int o = 0; o <= boba.ruas-1;o++){//membuat sirip ikan bagian atas
            for(int p = 0; p <= boba.tinggi - 2; p++){
                printf(" ");
            }
            for(int q = 0; q <= boba.tebal-1; q++){
                printf("*");
            }
        }
        for(k=boba.tinggi/2-b;k>=0;k--){
            printf("  ");//membuat jarak sebelum kepala
        }
        for(k=3;k<=b*2+1;k++){
            if(huruf > 'z'){
            huruf = 'a';
        }
        printf("%c", huruf++);//membuat kepala dengan alphabet
        }

        printf("\n");
    }

    //membuat bagian tulang (tengah) ikan milik boba
    for(int a = 1;a<=boba.tinggi/2;a++){
            printf(" ");//membuat jarak sebelum tulang ekor
        }
    for(int a = 1;a<=(boba.tinggi+1)/2;a++){
            printf(">");//membuat tulang bagian ekor tengah
        }
    for(int o = 0; o <= boba.ruas-1;o++){//membuat tulang ikan
            for(int p = 0; p <= boba.tinggi - 2; p++){
                printf("*");
            }
            for(int q = 0; q <= boba.tebal-1; q++){
                printf(">");
            }
        }
    for(b=1;b<=boba.tinggi;b++){

        if(huruf > 'z'){
            huruf = 'a';
        }
        printf("%c", huruf++);//membuat kepala ikan bagian tengah menggunakan alphabet
    }
    printf("\n");

    //membuat ikan milik boba bagian bawah
    for(b=1;b<=boba.tinggi/2;b++){
        for(k=boba.tinggi/2-b;k>=1;k--){
            printf(" ");//membuat jarak sebelum ekor bagian bawah 
        }
        for(k=boba.tinggi/2-b+1;k>=1;k--){
            printf("*");//membuat ekor bagian bawah
        }

        for(int o = 0; o <= boba.ruas-1;o++){//membuat sirip ikan bagian bawah
            for(int p = 0; p <= boba.tinggi - 2; p++){
                printf(" ");
            }
            for(int q = 0; q <= boba.tebal-1; q++){
                printf("*");
            }
        }
         for(k=1;k<=b;k++){
            printf("  ");//membuat jarak sebelum kepala bagian bawah
        }
    for(k=boba.tinggi-b*2;k>=1;k--){
            if(huruf > 'z'){
            huruf = 'a';
        } 
        printf("%c", huruf++);//membuat kepala ikan bagian bawah menggunakan alphabet
        }
        printf("\n");
    }

    /*membuat print untuk menampilkan hasil output sesuai dengan yang
    diingankan, yaitu tinggi, jumlah ruas, dan ketebalan ikan milik boba*/
    printf("\n");
    printf("Informasi Ikan Boba:\n");
    printf("> Tinggi Ikan: %d cm\n", boba.tinggi);
    printf("> Banyak Ruas Tulang: %d\n", boba.ruas);
    printf("> Ketebalan Tulang: %d cm\n", boba.tebal);
    printf("\n");

    //membuat kondisi jika ikan boba lebih berkualitas dari ikan kentang
    if((boba.tinggi > kentang.tinggi) && (boba.ruas > kentang.ruas) && (boba.tebal < kentang.tebal)){
        printf("Ikan Boba lebih berkualitas dari ikan Kentang!\n");
    }else{
        printf("Ikan Boba tidak lebih berkualitas dari ikan Kentang.\n");
    }
    
    //membuat kondisi jika ikan boba lebih berkualitas dari ikan ucul
    if((boba.tinggi > ucul.tinggi) && (boba.ruas > ucul.ruas) && (boba.tebal < ucul.tebal)){
        printf("Ikan Boba lebih berkualitas dari ikan Ucul!\n");
    }else{
        printf("Ikan Boba tidak lebih berkualitas dari ikan Ucul.\n");
    }

    return 0;

}