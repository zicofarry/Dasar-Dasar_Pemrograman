// #include "CIMYC24.h"

    
// /*membuat program*/

// /*int fKejarKargo(int jlari, int mlari, int totjarak, int kecepatan, int n, int jarak[51], char tempat[51][101]){
//     int i, mtotKejarKargo;
//     i = n;
//     do{
//         totjarak += jarak[i];
//         i--;

//     }while(i < n && strcmp(tempat[i], "abandoned_stasion") != 0);

//     mtotKejarKargo = jlari*60 + mlari + (float) (totjarak / (kecepatan * 60));

//     return mtotKejarKargo;
// }
    
// int fJadwalKargo(int jkargo, int mkargo){
//     int mtotJadwalKargo;
//     mtotJadwalKargo = jkargo*60 + mkargo;

//     return mtotJadwalKargo;
// }*/


// // printf("tojar = %d\n", totjarak);
// // printf("sampe = %d\n", mtotsampekargo);
// // printf("jadkargo = %d\n", mtotjadwalkargo);
// // /*printf("%d\n", sama);
// // printf("%d\n", tidaksama);*/
    
// /*menghasilkan output sesuai input yang telah diproses*/
// void sudoku(char st[10][10], int jlari, int mlari, int totjarak, int kecepatan, int n, int jarak[], char tempat[51][101], int jkargo, int mkargo){
//     int i, j, k;
//     int sama= 0, tidaksama = 0;
//     for(i = 0; i < 9; i++){
//         for(j = 0; j < 9; j++){
//             for(k = 0; k < 9; k++){
//                 if(st[i][j] == st[k][j]){
//                     sama++;
//                 }else{
//                     tidaksama++;
//                 }
//             }
//         }
//     }

//     if(sama == 81 && tidaksama == 648){
//         printf("Congrats, you made it out!\n");
//         //memprint pembatas
//         printf("\nooOooOooOooOooOooOooOooOooOoo\n");
//         int mtotKejarKargo = jlari*60 + mlari + (float) (totjarak / (kecepatan * 60));
//         int mtotJadwalKargo = jkargo*60 + mkargo;
//         if(mtotKejarKargo < mtotJadwalKargo){
//             printf("\nGotcha. You cannot run from me.\n");
//         }else{
//             printf("\nThe cargo is gone. Time to find another way.\n");
//         }    
    
//     }else{
//         printf("Almost there, afterall, mysteries are there to be solved!\n");
//     }
// }
//     /*memprint hasil game sudoku
//     if(sama == 81 && tidaksama == 648){
//         printf("Congrats, you made it out!\n");
//         //memprint pembatas
//         printf("\nooOooOooOooOooOooOooOooOooOoo\n");
//         if(mtotsampekargo < mtotjadwalkargo){
//             printf("\nGotcha. You cannot run from me.\n");
//         }else{
//             printf("\nThe cargo is gone. Time to find another way.\n");
//     }
//     }else{
//         printf("Almost there, afterall, mysteries are there to be solved!\n");
//     }

//     return 0;
// }*/