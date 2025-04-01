#include "CIMYC24.h"

int main(){
    char st[10][10];
    char tempat[51][101];
    int jarak[51];
    int i, j, k, n;
    float kecepatan;
    int totjarak = 0;
    int jlari, mlari;
    int jkargo, mkargo;
    int sama=0, tidaksama=0;
    int mtotsampekargo = 0;
    int mtotjadwalkargo = 0;
    int menitsampe;

/*meminta input dari user*/
    for(i = 0; i < 9; i++){
        scanf("%s", st[i]);
    }

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%s", tempat[i]);
    }
    for(i = 0; i < n; i++){
        scanf("%d", &jarak[i]);
    }

    scanf("%f", &kecepatan);
    scanf("%d %d", &jlari, &mlari);
    scanf("%d %d", &jkargo, &mkargo);
    
/*membuat program*/
    /*for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            for(k = 0; k < 9; k++){
                if(st[i][j] == st[k][j]){
                    sama++;
                }else{
                    tidaksama++;
                }
            }
        }
    }

    i = n;
    do{
        totjarak += jarak[i];
        i--;

    }while(i < n && strcmp(tempat[i], "abandoned_stasion") != 0);

    mtotsampekargo = jlari*60 + mlari + (float) (totjarak / (kecepatan * 60));
    mtotjadwalkargo = jkargo*60 + mkargo;


printf("tojar = %d\n", totjarak);
printf("sampe = %d\n", mtotsampekargo);
printf("jadkargo = %d\n", mtotjadwalkargo);
/*printf("%d\n", sama);
printf("%d\n", tidaksama);*/
    
/*menghasilkan output sesuai input yang telah diproses*/
    //memprint hasil game sudoku
    /*if(sama == 81 && tidaksama == 648){
        printf("Congrats, you made it out!\n");
        //memprint pembatas
        printf("\nooOooOooOooOooOooOooOooOooOoo\n");
        if(mtotsampekargo < mtotjadwalkargo){
            printf("\nGotcha. You cannot run from me.\n");
        }else{
            printf("\nThe cargo is gone. Time to find another way.\n");
    }
    }else{
        printf("Almost there, afterall, mysteries are there to be solved!\n");
    }*/

    //printf("kejar = %d\n", fKejarKargo(jlari, mlari, totjarak, kecepatan, n, jarak, tempat));
    //printf("jadkargo = %d\n", fJadwalKargo(jkargo, mkargo));
    sudoku(st, n, tempat, jarak, kecepatan, jlari, mlari, jkargo, mkargo);

    return 0;
}