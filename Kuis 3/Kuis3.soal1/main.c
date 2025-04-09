/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Kuis 3 soal 1 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include "mkkd24.h" // include kan file header

int main(){
    /*Mendeklarasikan variabel untuk menampung nilai
    c = kata kunci yang akan diperiksa
    pita = string masukan
    tmp = array of string yang menyimpan string yang sudah difilter
    tmp1 = menyimpan huruf pertama
    tmp2 = menyimpan huruf kedua
    tmp3 = menyimpan huruf ketiga
    n = jumlah string yang memenuhi*/
    char c;
    char pita[1001];
    char tmp[101][51];
    char tmp1, tmp2, tmp3;
    int n = 0;

/*Meminta masukan dari user*/
    //masukan untuk kunci karakter
    scanf(" %c", &c);

    //masukan string pita
    scanf(" %1000[^\n]s", &pita);

/*Membuat program dengan memanggil fungsi kemudian diproses*/
    int i = 0;
    startc(pita); //memulai huruf
    while(eopc() == 0){
        tmp1 = getcc(); //menyimpan huruf pertama
        advc(pita); //maju 1 huruf hiraukan blank space
        if(eopc() == 0){
            tmp2 = getcc(); //menyimpan huruf kedua
            advc(pita); //maju 1 huruf hiraukan blank space
            if(eopc() == 0){
                tmp3 = getcc(); //menyimpan huruf ketiga
                advc(pita); //maju 1 huruf hiraukan blank space
                if(eopc() == 0){
                    //membuat kondisi jika huruf ke 2 sesuai dengan karakter kunci, dan yang lainnya tidak
                    if((tmp1 != c) && (tmp2 == c) && (tmp3 != c) && (getcc() != c)){ //jika memebuhi
                        //mengisi string tmp pada tiap indeksnya
                        tmp[i][0] = tmp1;
                        tmp[i][1] = tmp2;
                        tmp[i][2] = tmp3;
                        tmp[i][3] = getcc();
                        tmp[i][4] = '\0';
                        i++;
                        n++;
                    }
                    decc(pita); //memundurkan 1 huruf
                }
                decc(pita); //memundurkan 1 huruf
            }
        }
    }

/*Menampilkan output sesuai dengan input yang telah diproses*/
    //membuat kondisi print sesuai dengan ketentuan soal
    if(n==0){ //jika tidak ada string yang memenuhi
        printf("tidak ada\n"); //print tidak ada
        printf("%d\n", n);
    }else{//jika ada yang memenuhi
        for(int j = 0; j < i; j++){
            printf("%s\n", tmp[j]); //print setiap string yang memenuhi
        }
        printf("%d\n", n);  //print jumlah string yang memenuhi
    }

    return 0;
}