/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Kuis 3 soal 2 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include "mkpv24.h" //includekan file header

int main() {
    // deklarasi variabel untuk menampung nilai
    char pita[301];
    char tmp[51];
    char tmp1[101];
    char tmp2[101];
    char tmpvok1[51];
    char tmpvok2[51];
    char vok1[51][101];
    char vok2[51][101];
    int n = 0;


/*Meminta masukan dari user*/
    scanf("%300[^\n]s", &pita);


/*Membuat program dengan memanggil fungsi kemudian diproses*/
    int count = 0;
    int done = 0;
    start(pita);
    while(eop(pita) == 0){
        strcpy(tmp1, getcw());
        // printf("tmp = %s\n", tmp);
        // if(eop(pita) == 0){
            // printf("gc = %s\n", getcw());
            int vokal = 0;
            // printf("gcw1 = %s\n", getcw());
            int j1 = 0;
            for(int i = 0; i < strlen(tmp1); i++){
                if (tmp1[i] == 'a' || tmp1[i] == 'i' || tmp1[i] == 'u' || tmp1[i] == 'e' || tmp1[i] == 'o' || 
                    tmp1[i] == 'A' || tmp1[i] == 'I' || tmp1[i] == 'U' || tmp1[i] == 'E' || tmp1[i] == 'O') {
                    tmpvok1[j1++] = tmp1[i];
                }

            }
            tmpvok1[j1] = '\0';

        inc(pita);
        strcpy(tmp2, getcw());
            // inc(pita);
            // printf("gcw2 = %s\n", getcw());
            int j2 = 0;
            for(int i = 0; i < strlen(tmp2); i++){
                if (tmp2[i] == 'a' || tmp2[i] == 'i' || tmp2[i] == 'u' || tmp2[i] == 'e' || tmp2[i] == 'o' || 
                    tmp2[i] == 'A' || tmp2[i] == 'I' || tmp2[i] == 'U' || tmp2[i] == 'E' || tmp2[i] == 'O') {
                    tmpvok2[j2++] =  tmp2[i];
                }

            }
            tmpvok2[j2] = '\0';
            // printf("vok1 = |%s|\n", tmpvok1);
            // printf("vok2 = |%s|\n", tmpvok2);
            if(strcmp(tmpvok1, tmpvok2) == 0){
                strcpy(vok1[n], tmp1);
                strcpy(vok2[n], tmp2);
                n++;   
                inc(pita);

            }
    }

    
/*Menampilkan output sesuai dengan input yang telah diiproses*/
    if(n==0){
        printf("tidak ada\n");
        printf("%d\n", n);
    }else{
        for(int i = 0; i < n; i++){
            printf("%s %s\n", vok1[i], vok2[i]);
        }
        printf("%d\n", n);
    }


    return 0;
}


