/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tugas praktikum 8 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include <stdio.h>
#include <string.h>

typedef struct{
    char idVehicle[51];
    char name[51];
    char manuf[51];
    char class[51];
    char nation[51];
    int weight;
}data;

typedef struct{
    char kode[51];
    char jenis[51];
}mcn;

typedef struct{
    int name;
    int manuf;
    int class;
    int nation;
    int weight;
}tabel;

void write_Vehicle(int n, data source[], char fileName[]);
void write_MCN(int n, mcn source[], char fileName[]);
void read_Vehicle(int *n, data source[], char fileName[]);
void read_MCN(int *n, mcn source[], char fileName[]);
void modify_MCN(char perintah[], char mode[], mcn baru, mcn *tmp, int *n, data vehicle[], int v);
void modify_data(char perintah[], char mode[], data baru_vehic, data *vehicle, int *v, mcn manuf[], int m, mcn class[], int c, mcn nation[], int n);
void trans(int v, data vehicle[], int m, mcn manuf[], int c, mcn class[], int n, mcn nation[]);
int digit(int n);
void tabel_MCN(char mode[], int n, mcn *str);
void tabel_vehicle(char mode[], int n, data *str);
void program(char *y);
void panduan();