/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tugas praktikum 8 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/

#include "header.h"

void write_Vehicle(int n, data source[], char fileName[]){
    FILE *fvehicle;
    fvehicle = fopen(fileName, "w");

    for(int i = 0; i < n; i++){
        fprintf(fvehicle, "%s %s %s %s %s %d\n", source[i].idVehicle, source[i].name, source[i].manuf, source[i].class, source[i].nation, source[i].weight);
    }
        fprintf(fvehicle, "%s %s %s %s %s %d\n", "####", "####", "####", "####", "####", -999);

        fclose(fvehicle);
}

void write_MCN(int n, mcn source[], char fileName[]){
    FILE *fmcn;
    fmcn = fopen(fileName, "w");

    for(int i = 0; i < n; i++){
        fprintf(fmcn, "%s %s\n", source[i].kode, source[i].jenis);
    }
        fprintf(fmcn, "%s %s\n", "####", "####");

        fclose(fmcn);
}

void read_Vehicle(int *n, data source[], char fileName[]){
    FILE *fvehicle;
    fvehicle = fopen(fileName, "r");//r untuk operator read file

    int returnVal = fscanf(fvehicle, "%s %s %s %s %s %d", source[*n].idVehicle, source[*n].name, source[*n].manuf, source[*n].class, source[*n].nation, &source[*n].weight);

    if(strcmp(source[*n].idVehicle, "####") == 0 || returnVal == EOF) printf("File Kosong\n");
    else{
        while(strcmp(source[*n].idVehicle, "####") != 0){
            *n = *n + 1;
            fscanf(fvehicle, "%s %s %s %s %s %d", source[*n].idVehicle, source[*n].name, source[*n].manuf, source[*n].class, source[*n].nation, &source[*n].weight);
        }
    }

    fclose(fvehicle);
}

void read_MCN(int *n, mcn source[], char fileName[]){
    FILE *fvehicle;
    fvehicle = fopen(fileName, "r");//r untuk operator read file

    int returnVal = fscanf(fvehicle, "%s %s", source[*n].kode, source[*n].jenis);

    if(strcmp(source[*n].kode, "####") == 0 || returnVal == EOF) printf("File Kosong\n");
    else{
        while(strcmp(source[*n].kode, "####") != 0){
            *n = *n + 1;
            fscanf(fvehicle, "%s %s", source[*n].kode, source[*n].jenis);
        }
    }

    fclose(fvehicle);
}

void modify_MCN(char perintah[], char mode[], mcn baru, mcn *tmp, int *n, data vehicle[], int v){
    if(strcmp(perintah, "INSERT") == 0 || strcmp(perintah, "UPDATE") == 0){

        printf("Masukan Kode Dan Jenis:\n");
        scanf("%s %s", baru.kode, baru.jenis);


        if(mode[0] == baru.kode[0] && 
            (baru.kode[1] >= '0' && baru.kode[1] <= '9') &&
            (baru.kode[2] >= '0' && baru.kode[2] <= '9') &&
            (baru.kode[3] >= '0' && baru.kode[3] <= '9')){
            if(strlen(baru.kode) == 4){
                if(strcmp(perintah, "INSERT") == 0){
                    int ada = 0;
                    for(int i = 0; i < *n; i++){//cek apakah primary key nya udah kepake atau belum
                        if(strcmp(tmp[i].kode, baru.kode) == 0){
                            ada = 1;
                        }
                    }

                    if(!ada){
                        //kondisi memasukan ke dalam array
                        if(strcmp(baru.kode, tmp[0].kode) < 0){//rekaman baru paling depan
                            //geser semua isi array belakang
                            int i;
                            for(i = *n-1; i >= 0; i--){
                                strcpy(tmp[i+1].kode, tmp[i].kode);
                                strcpy(tmp[i+1].jenis, tmp[i].jenis);
                            }
                            (*n)++;
                            strcpy(tmp[0].kode, baru.kode);
                            strcpy(tmp[0].jenis, baru.jenis);
                        }else if(strcmp(baru.kode, tmp[*n-1].kode) > 0){//rekaman baru di belakang
                            strcpy(tmp[*n].kode, baru.kode);
                            strcpy(tmp[*n].jenis, baru.jenis);
                            (*n)++;
                        }else{//rekaman baru memiliki posisi di tengah
                            int i = 0;
                            int stop = 0;
                            //cari posisi
                            while((i < *n) && (stop == 0)){
                                if(strcmp(tmp[i].kode, baru.kode) > 0){
                                    stop = 1;
                                }else{
                                    i++;
                                }
                            }

                            int j;
                            for(j = *n-1; j >= i; j--){
                                strcpy(tmp[j+1].kode, tmp[j].kode);
                                strcpy(tmp[j+1].jenis, tmp[j].jenis);
                            }
                            strcpy(tmp[i].kode, baru.kode);
                            strcpy(tmp[i].jenis, baru.jenis);
                            (*n)++;   
                        }
                        printf("INSERT berhasil, lalala yeyeyeye~\n");
                    }else{
                        printf("KODE PRIMARY SUDAH DIGUNAKAN!!\n");
                    }
                }else if(strcmp(perintah, "UPDATE") == 0){
                    int stop = 0;
                    for(int i = 0; i < *n; i++){
                        if(strcmp(tmp[i].kode, baru.kode) == 0){
                            strcpy(tmp[i].kode, baru.kode);
                            strcpy(tmp[i].jenis, baru.jenis);
                            stop = 1;
                        }
                    }

                    if(!stop){
                        printf("Tidak ada kode primary serupa yang bisa diupdate!!\n");
                    }else{
                        printf("UPDATE berhasil, lalala yeyeyeye~\n");
                    }
                }
            }else{
                printf("Kode Primary %s harus berisi 4 digit!!\n", mode);
            }
        }else{
            printf("Kode primary %s tidak sesuai format!!!\n", mode);
        }
    }else if(strcmp(perintah, "DELETE") == 0){
        printf("Masukan Kode:\n");
        scanf("%s", baru.kode);


        if(mode[0] == baru.kode[0]){
            if(strlen(baru.kode) == 4){
                int i = 0;
                int adav = 0;
                if(strcmp(mode, "Manufacturer") == 0){
                    //cari posisi
                    while((i < v) && (adav == 0)){
                        if(strcmp(vehicle[i].manuf, baru.kode) == 0){
                            adav = 1;
                        }else{
                            i++;
                        }
                    }
                }else if(strcmp(mode, "Class") == 0){
                    //cari posisi
                    while((i < v) && (adav == 0)){
                        if(strcmp(vehicle[i].class, baru.kode) == 0){
                            adav = 1;
                        }else{
                            i++;
                        }
                    }
                }else if(strcmp(mode, "Nationality") == 0){
                    //cari posisi
                    while((i < v) && (adav == 0)){
                        if(strcmp(vehicle[i].nation, baru.kode) == 0){
                            adav = 1;
                        }else{
                            i++;
                        }
                    }
                }

                if(!adav){
                    int i = 0;
                    int stop = 0;
                    //cari posisi
                    while((i < *n) && (stop == 0)){
                        if(strcmp(tmp[i].kode, baru.kode)== 0){
                            stop = 1;
                        }else{
                            i++;
                        }
                    }

                    if(stop){
                        int j;
                        for(j = i; j < *n; j++){
                            strcpy(tmp[j].kode, tmp[j+1].kode);
                            strcpy(tmp[j].jenis, tmp[j+1].jenis);
                        }
                        (*n)--;
                        printf("DELETE berhasil, lalala yeyeyeye~\n");
                    }else{
                        printf("Tidak ada kode primary serupa yang bisa dihapus!!\n");
                    } 
                }else{
                    printf("Primary key sedang digunakan dalam tabel Vehicle, TIDAK BISA DIHAPUS!!!\n");
                }
            }else{
                printf("Kode Primary %s harus berisi 4 digit!!\n", mode);
            }
        }else{
            printf("Kode Primary %s tidak sesuai format!!!\n", mode);
        }
    }else{
        printf("MASUKAN PERINTAH TIDAK SESUAI FORMAT!!!!!\n");
    }

    if(strcmp(mode, "Manufacturer") == 0){
        write_MCN(*n, tmp, "Manufacturer.txt");
    }else if(strcmp(mode, "Class") == 0){
        write_MCN(*n, tmp, "Class.txt");
    }else if(strcmp(mode, "Nationality") == 0){
        write_MCN(*n, tmp, "Nationality.txt");
    }
}

void modify_data(char perintah[], char mode[], data baru_vehic, data *vehicle, int *v, mcn manuf[], int m, mcn class[], int c, mcn nation[], int n){
    if(strcmp(mode, "Vehicle") == 0){
        if(strcmp(perintah, "INSERT") == 0 || strcmp(perintah, "UPDATE") == 0){

            printf("Masukan IdVehicle, Nama, IdManufacturer, IdClass, IdNationality, dan Weight:\n");
            scanf("%s %s %s %s %s %d", baru_vehic.idVehicle, baru_vehic.name, baru_vehic.manuf, baru_vehic.class, baru_vehic.nation, &baru_vehic.weight);

            if(mode[0] == baru_vehic.idVehicle[0] &&
                (baru_vehic.idVehicle[1] >= '0' && baru_vehic.idVehicle[1] <= '9') &&
                (baru_vehic.idVehicle[2] >= '0' && baru_vehic.idVehicle[2] <= '9') &&
                (baru_vehic.idVehicle[3] >= '0' && baru_vehic.idVehicle[3] <= '9')){
                if(strlen(baru_vehic.idVehicle) == 4){
                    int im = 0;
                    int adam = 0;
                    //cari posisi
                    while((im < m) && (adam == 0)){
                        if(strcmp(manuf[im].kode, baru_vehic.manuf) == 0){
                            adam = 1;
                        }else{
                            im++;
                        }
                    }
                    
                    int ic = 0;
                    int adac = 0;
                    //cari posisi
                    while((ic < c) && (adac == 0)){
                        if(strcmp(class[ic].kode, baru_vehic.class) == 0){
                            adac = 1;
                        }else{
                            ic++;
                        }
                    }
                    
                    int in = 0;
                    int adan = 0;
                    //cari posisi
                    while((in < n) && (adan == 0)){
                        if(strcmp(nation[in].kode, baru_vehic.nation) == 0){
                            adan = 1;
                        }else{
                            in++;
                        }
                    }



                    if((strcmp(perintah, "INSERT") || strcmp(perintah, "UPDATE")) && baru_vehic.idVehicle[0] == 'V' &&
                        baru_vehic.manuf[0] == 'M' && baru_vehic.class[0] == 'C' && baru_vehic.nation[0] == 'N'){
                        if(adam == 1 & adac == 1 && adan == 1){
                            // printf("masokk\n");
                            if(strcmp(perintah, "INSERT") == 0){
                                int ada = 0;
                                for(int i = 0; i < *v; i++){//cek apakah primary key nya udah kepake atau belum
                                    if(strcmp(vehicle[i].idVehicle, baru_vehic.idVehicle) == 0){
                                        ada = 1;
                                    }
                                }

                                if(!ada){
                                    //kondisi memasukan ke dalam array
                                    if(strcmp(baru_vehic.idVehicle, vehicle[0].idVehicle) < 0){//rekaman baru_vehic paling depan
                                        //geser semua isi array belakang
                                        int i;
                                        for(i = *v-1; i >= 0; i--){
                                            strcpy(vehicle[i+1].idVehicle, vehicle[i].idVehicle);
                                            strcpy(vehicle[i+1].name, vehicle[i].name);
                                            strcpy(vehicle[i+1].manuf, vehicle[i].manuf);
                                            strcpy(vehicle[i+1].class, vehicle[i].class);
                                            strcpy(vehicle[i+1].nation, vehicle[i].nation);
                                            vehicle[i+1].weight = vehicle[i].weight;
                                        }
                                        (*v)++;
                                        strcpy(vehicle[0].idVehicle, baru_vehic.idVehicle);
                                        strcpy(vehicle[0].name, baru_vehic.name);
                                        strcpy(vehicle[0].manuf, baru_vehic.manuf);
                                        strcpy(vehicle[0].class, baru_vehic.class);
                                        strcpy(vehicle[0].nation, baru_vehic.nation);
                                        vehicle[0].weight = baru_vehic.weight;
                                    }else if(strcmp(baru_vehic.idVehicle, vehicle[*v-1].idVehicle) > 0){//rekaman baru_vehic di belakang
                                        strcpy(vehicle[*v].idVehicle, baru_vehic.idVehicle);
                                        strcpy(vehicle[*v].name, baru_vehic.name);
                                        strcpy(vehicle[*v].manuf, baru_vehic.manuf);
                                        strcpy(vehicle[*v].class, baru_vehic.class);
                                        strcpy(vehicle[*v].nation, baru_vehic.nation);
                                        vehicle[*v].weight = baru_vehic.weight;
                                        (*v)++;
                                    }else{//rekaman baru memiliki posisi di tengah
                                        int i = 0;
                                        int stop = 0;
                                        //cari posisi
                                        while((i < *v) && (stop == 0)){
                                            if(strcmp(vehicle[i].idVehicle, baru_vehic.idVehicle) > 0){
                                                stop = 1;
                                            }else{
                                                i++;
                                            }
                                        }

                                        int j;
                                        for(j = *v-1; j >= i; j--){
                                            strcpy(vehicle[j+1].idVehicle, vehicle[j].idVehicle);
                                            strcpy(vehicle[j+1].name, vehicle[j].name);
                                            strcpy(vehicle[j+1].manuf, vehicle[j].manuf);
                                            strcpy(vehicle[j+1].class, vehicle[j].class);
                                            strcpy(vehicle[j+1].nation, vehicle[j].nation);
                                            vehicle[j+1].weight = vehicle[j].weight;
                                        }
                                        strcpy(vehicle[i].idVehicle, baru_vehic.idVehicle);
                                        strcpy(vehicle[i].name, baru_vehic.name);
                                        strcpy(vehicle[i].manuf, baru_vehic.manuf);
                                        strcpy(vehicle[i].class, baru_vehic.class);
                                        strcpy(vehicle[i].nation, baru_vehic.nation);
                                        vehicle[i].weight = baru_vehic.weight;
                                        (*v)++;   
                                    }
                                    printf("INSERT berhasil, lalala yeyeyeye~\n");
                                }else{
                                    printf("ID VEHICLE SUDAH DIGUNAKAN!!\n");
                                }
                            }else if(strcmp(perintah, "UPDATE") == 0){
                                int stop = 0;
                                for(int i = 0; i < *v; i++){
                                    if(strcmp(vehicle[i].idVehicle, baru_vehic.idVehicle) == 0){
                                        strcpy(vehicle[i].idVehicle, baru_vehic.idVehicle);
                                        strcpy(vehicle[i].name, baru_vehic.name);
                                        strcpy(vehicle[i].manuf, baru_vehic.manuf);
                                        strcpy(vehicle[i].class, baru_vehic.class);
                                        strcpy(vehicle[i].nation, baru_vehic.nation);
                                        vehicle[i].weight = baru_vehic.weight;
                                        stop = 1;
                                    }
                                }

                                if(!stop){
                                    printf("Tidak ada data serupa yang bisa diupdate!!\n");
                                }else{
                                    printf("UPDATE berhasil, lalala yeyeyeye~\n");
                                }
                            }
                        }else if(adam == 0 && adac == 1 && adan == 1){
                            printf("IdManufacturer tidak ada dalam tabel manufacturer!\n");
                        }else if(adam == 1 && adac == 0 && adan == 1){
                            printf("IdClass tidak ada dalam tabel class!\n");
                        }else if(adam == 1 && adac == 1 && adan == 0){
                            printf("IdNationality tidak ada dalam tabel nationality!\n");
                        }else if(adam == 1 && adac == 0 && adan == 0){
                            printf("IdClass dan IdNationality tidak ada dalam tabelnya!\n");
                        }else if(adam == 0 && adac == 1 && adan == 0){
                            printf("IdManufacturer dan Idnationality tidak ada dalam tabel!\n");
                        }else if(adam == 0 && adac == 0 && adan == 1){
                            printf("IdManufacturer dan IdClass tidak ada dalam tabelnya!\n");
                        }else if(adam == 0 && adac == 0 && adan == 0){
                            printf("IdManufacturer, IdClass, dan IdNationality tidak ada dalam tabelnya!\n");
                        }
                    }else{
                        printf("Kode primary (Manufacturer/ Class/ Nationality) ada yang tidak sesuai format!!!\n");
                    }
                }else{
                    printf("Kode Primary %s harus berisi 4 digit!!\n", mode);
                }
            }else{
                printf("Kode Primary %s tidak sesuai format!!!\n", mode);
            }
        }else if(strcmp(perintah, "DELETE") == 0){
            printf("Masukan IdVehicle:\n");
            scanf("%s", baru_vehic.idVehicle);

            if(mode[0] == baru_vehic.idVehicle[0]){
                if(strlen(baru_vehic.idVehicle) == 4){
                    int i = 0;
                    int stop = 0;
                    //cari posisi
                    while((i < *v) && (stop == 0)){
                        if(strcmp(vehicle[i].idVehicle, baru_vehic.idVehicle)== 0){
                            stop = 1;
                        }else{
                            i++;
                        }
                    }

                    if(stop){
                        int j;
                        for(j = i; j < *v; j++){
                            strcpy(vehicle[j].idVehicle, vehicle[j+1].idVehicle);
                            strcpy(vehicle[j].name, vehicle[j+1].name);
                            strcpy(vehicle[j].manuf, vehicle[j+1].manuf);
                            strcpy(vehicle[j].class, vehicle[j+1].class);
                            strcpy(vehicle[j].nation, vehicle[j+1].nation);
                            vehicle[j].weight = vehicle[j+1].weight;
                        }
                        (*v)--;
                        printf("DELETE berhasil, lalala yeyeyeye~\n");
                    }else{
                        printf("Tidak ada data serupa yang bisa dihapus!!\n");
                    }
                }else{
                    printf("Kode Primary %s harus berisi 4 digit!!\n", mode);
                }
            }else{
                printf("Kode Primary %s tidak sesuai format!!!\n", mode);
            }
        }else{
            printf("MASUKAN PERINTAH TIDAK SESUAI FORMAT!!!!!\n");
        }
        write_Vehicle(*v, vehicle, "Vehicle.txt");
    }else if(strcmp(mode, "VehicleComplete") == 0){
        printf("Tidak bisa melakukan INSERT/ UPDATE/ DELETE pada tabel VehicleComplete!!!\n");
    }
}

void trans(int v, data vehicle[], int m, mcn manuf[], int c, mcn class[], int n, mcn nation[]){
    for(int i = 0; i < v; i++){
        for(int j = 0; j < m; j++){
            if(strcmp(vehicle[i].manuf, manuf[j].kode) == 0){
                strcpy(vehicle[i].manuf, manuf[j].jenis);
            }
        }

        for(int j = 0; j < c; j++){
            if(strcmp(vehicle[i].class, class[j].kode) == 0){
                strcpy(vehicle[i].class, class[j].jenis);
            }
        }
        
        for(int j = 0; j < n; j++){
            if(strcmp(vehicle[i].nation, nation[j].kode) == 0){
                strcpy(vehicle[i].nation, nation[j].jenis);
            }
        }
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

void tabel_MCN(char mode[], int n, mcn *str){
    /*mendeklarasikan variabel untuk menampung nilai
    i = counting untuk loop for
    j = counting untuk loop for di dalam loop for
    count = counting untuk mengecek jumlah dari array bungkusan (cek sampai ketemu marking -1)*/
    int i, j;
    int count = 0;
    int max;
    int space;

    for(i = 0; i < strlen(mode); i++){
        if(mode[i] >= 'a' && mode[i] <= 'z'){
            mode[i] -= 32;
        }
    }
    printf("\n<<< TABEL %s >>>\n", mode);
    
    //memprint baris atas
    printf("+----+------+-");
    
    max = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
    space = 0;//membuat variabel untuk menampung jumlah spasi
    for(i = 0; i < n; i++){
        if(max < strlen(str[i].jenis)){//jika ada strlen jenis yang lebih panjang
            max = strlen(str[i].jenis);//maka update nilai max nya
        }
    }

    if(max > 5){//jika maksimalnya lebih dari 5
        for(i = 0; i < max; i++){//maka print '-' sebanyak panjang maksimalnya
            printf("-");
        }
        
    }else{//jika kurang atau sama dengan 5
        for(i = 0; i < 5; i++){
            printf("-");//maka print '-' sebanyak 5 kali
        }
    }
    printf("-+\n");
    
    //memprint bagian judul
    printf("| No | Kode | Jenis");
    space = max - 5;//spasi didapatkan dari panjang maksimal dikurang 12
    if(space < 1) space = 0;//jika spasinya negatif, maka spasinya 0
    for(i = 0; i < space; i++){
        printf(" ");//print ' ' sebanyak jumlah spasi
    }
    printf(" |\n");


    //memprint bagian bawah judul
    printf("+----+------+-");
    max = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
    space = 0;//membuat variabel untuk menampung jumlah spasi
    for(i = 0; i < n; i++){
        if(max < strlen(str[i].jenis)){//jika ada strlen jenis yang lebih panjang
            max = strlen(str[i].jenis);//maka update nilai max nya
        }
    }

    if(max > 5){//jika maksimalnya lebih dari 5
        for(i = 0; i < max; i++){//maka print '-' sebanyak panjang maksimalnya
            printf("-");
        }
        
    }else{//jika kurang atau sama dengan 5
        for(i = 0; i < 5; i++){
            printf("-");//maka print '-' sebanyak 5 kali
        }
    }
    printf("-+\n");

    //print isi tabel
    for(i = 0; i < n; i++){//melakukan loop sebanyak jumlah array nya
        //memprint no rank leaderboard
        if(i > 8){//jika no nya lebih dari 1 digit
            printf("| %d | ", i + 1);//maka print tanpa spasi setelahnya
        }else{//jika hanya 1 digit
            printf("| %d  | ", i + 1);//maka print dengan spasi setelahnya agar rata
        }
        printf("%s | %s", str[i].kode, str[i].jenis);


        if(max > 5){//jika panjang maksimal stringnya lebih dari 12, maka;
            space = max - strlen(str[i].jenis);//spasi didapatkan dari max string dikurangi string indeks i
            if(space < 1) space = 0;//jika spasinya negatif maka spasinya 0
            for(j = 0; j < space; j++){
                printf(" ");//print ' ' sebanyak jumlah spasi
            }
        }else{//jika panjang maksimal stringnya kurang / sama dengan 12, maka;
            space = 5 - strlen(str[i].jenis);//spasi didapatkan dari 12 dikurang panjang string indeks i
            if(space < 1) space = 0;//jika spasinya negatif maka spasinya 0
            for(j = 0; j < space; j++){
                printf(" ");//print ' ' sebanyak jumlah spasi
            }
        }

        printf(" |\n");
    }

    //memprint bagian bawah tabel
    printf("+----+------+-");
    max = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
    space = 0;//membuat variabel untuk menampung jumlah spasi
    for(i = 0; i < n; i++){
        if(max < strlen(str[i].jenis)){//jika ada strlen jenis yang lebih panjang
            max = strlen(str[i].jenis);//maka update nilai max nya
        }
    }

    if(max > 5){//jika maksimalnya lebih dari 5
        for(i = 0; i < max; i++){//maka print '-' sebanyak panjang maksimalnya
            printf("-");
        }
        
    }else{//jika kurang atau sama dengan 5
        for(i = 0; i < 5; i++){
            printf("-");//maka print '-' sebanyak 5 kali
        }
    }
    printf("-+\n");

}


void tabel_vehicle(char mode[], int n, data *str){
    /*mendeklarasikan variabel untuk menampung nilai
    i = counting untuk loop for
    j = counting untuk loop for di dalam loop for
    count = counting untuk mengecek jumlah dari array bungkusan (cek sampai ketemu marking -1)*/
    int i, j;
    int count = 0;
    tabel max;
    tabel space;
    char mode1[51];

     //memprint tabel
    j = 0;
    for(i = 0; i < strlen(mode); i++){
        if((mode[i] >= 'A' && mode[i] <= 'Z') && i != 0 && (mode[i-1] >= 'a' && mode[i-1] <= 'z')){
            mode1[j++] = ' ';
            // printf("masok\n");
        }
        mode1[j++] = mode[i];
    }
    mode1[j] = '\0';
    // strcpy(mode1, mode);

    for(i = 0; i < strlen(mode1); i++){
        if(mode1[i] >= 'a' && mode1[i] <= 'z'){
            mode1[i] -= 32;
        }
    }
    printf("\n<<< TABEL %s >>>\n", mode1);
    
    //memprint baris atas
    printf("+----+------+-");
    
    max.name = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
    space.name = 0;//membuat variabel untuk menampung jumlah spasi
    for(i = 0; i < n; i++){
        if(max.name < strlen(str[i].name)){//jika ada strlen jenis yang lebih panjang
            max.name = strlen(str[i].name);//maka update nilai max nya
        }
    }

    if(max.name > 4){//jika maksimalnya lebih dari 4
        for(i = 0; i < max.name; i++){//maka print '-' sebanyak panjang maksimalnya
            printf("-");
        }
        
    }else{//jika kurang atau sama dengan 4
        for(i = 0; i < 4; i++){
            printf("-");//maka print '-' sebanyak 4 kali
        }
    }
    printf("-+-");
    
    max.manuf = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
    space.manuf = 0;//membuat variabel untuk menampung jumlah spasi
    for(i = 0; i < n; i++){
        if(max.manuf < strlen(str[i].manuf)){//jika ada strlen jenis yang lebih panjang
            max.manuf = strlen(str[i].manuf);//maka update nilai max nya
        }
    }

    if(max.manuf > 12){//jika maksimalnya lebih dari 12
        for(i = 0; i < max.manuf; i++){//maka print '-' sebanyak panjang maksimalnya
            printf("-");
        }
        
    }else{//jika kurang atau sama dengan 12
        for(i = 0; i < 12; i++){
            printf("-");//maka print '-' sebanyak 12 kali
        }
    }
    printf("-+-");
    
    max.class = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
    space.class = 0;//membuat variabel untuk menampung jumlah spasi
    for(i = 0; i < n; i++){
        if(max.class < strlen(str[i].class)){//jika ada strlen jenis yang lebih panjang
            max.class = strlen(str[i].class);//maka update nilai max nya
        }
    }

    if(max.class > 5){//jika maksimalnya lebih dari 5
        for(i = 0; i < max.class; i++){//maka print '-' sebanyak panjang maksimalnya
            printf("-");
        }
        
    }else{//jika kurang atau sama dengan 5
        for(i = 0; i < 5; i++){
            printf("-");//maka print '-' sebanyak 5 kali
        }
    }
    printf("-+-");
    
    max.nation = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
    space.nation = 0;//membuat variabel untuk menampung jumlah spasi
    for(i = 0; i < n; i++){
        if(max.nation < strlen(str[i].nation)){//jika ada strlen jenis yang lebih panjang
            max.nation = strlen(str[i].nation);//maka update nilai max nya
        }
    }

    if(max.nation > 11){//jika maksimalnya lebih dari 11
        for(i = 0; i < max.nation; i++){//maka print '-' sebanyak panjang maksimalnya
            printf("-");
        }
        
    }else{//jika kurang atau sama dengan 11
        for(i = 0; i < 11; i++){
            printf("-");//maka print '-' sebanyak 11 kali
        }
    }
    printf("-+-");
    
    max.weight = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
    space.weight = 0;//membuat variabel untuk menampung jumlah spasi
    for(i = 0; i < n; i++){
        if(max.weight < digit(str[i].weight)){//jika ada strlen jenis yang lebih panjang
            max.weight = digit(str[i].weight);//maka update nilai max nya
        }
    }

    if(max.weight > 6){//jika maksimalnya lebih dari 6
        for(i = 0; i < max.weight; i++){//maka print '-' sebanyak panjang maksimalnya
            printf("-");
        }
        
    }else{//jika kurang atau sama dengan 6
        for(i = 0; i < 6; i++){
            printf("-");//maka print '-' sebanyak 6 kali
        }
    }
    printf("-+\n");
    
    //memprint bagian judul
    printf("| No | Kode | Nama");
    space.name = max.name - 4;//spasi didapatkan dari panjang maksimal dikurang 12
    if(space.name < 1) space.name = 0;//jika spasinya negatif, maka spasinya 0
    for(i = 0; i < space.name; i++){
        printf(" ");//print ' ' sebanyak jumlah spasi
    }
    printf(" | ");
    
    printf("Manufacturer");
    space.manuf = max.manuf - 12;//spasi didapatkan dari panjang maksimal dikurang 12
    if(space.manuf < 1) space.manuf = 0;//jika spasinya negatif, maka spasinya 0
    for(i = 0; i < space.manuf; i++){
        printf(" ");//print ' ' sebanyak jumlah spasi
    }
    printf(" | ");
    
    printf("Class");
    space.class = max.class - 5;//spasi didapatkan dari panjang maksimal dikurang 12
    if(space.class < 1) space.class = 0;//jika spasinya negatif, maka spasinya 0
    for(i = 0; i < space.class; i++){
        printf(" ");//print ' ' sebanyak jumlah spasi
    }
    printf(" | ");
    
    printf("Nationality");
    space.nation = max.nation - 11;//spasi didapatkan dari panjang maksimal dikurang 12
    if(space.nation < 1) space.nation = 0;//jika spasinya negatif, maka spasinya 0
    for(i = 0; i < space.nation; i++){
        printf(" ");//print ' ' sebanyak jumlah spasi
    }
    printf(" | ");
    
    printf("Weight");
    space.weight = max.weight - 6;//spasi didapatkan dari panjang maksimal dikurang 12
    if(space.weight < 1) space.weight = 0;//jika spasinya negatif, maka spasinya 0
    for(i = 0; i < space.weight; i++){
        printf(" ");//print ' ' sebanyak jumlah spasi
    }
    printf(" |\n");


    //memprint bagian bawah judul
    printf("+----+------+-");
    
    max.name = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
    space.name = 0;//membuat variabel untuk menampung jumlah spasi
    for(i = 0; i < n; i++){
        if(max.name < strlen(str[i].name)){//jika ada strlen jenis yang lebih panjang
            max.name = strlen(str[i].name);//maka update nilai max nya
        }
    }

    if(max.name > 4){//jika maksimalnya lebih dari 4
        for(i = 0; i < max.name; i++){//maka print '-' sebanyak panjang maksimalnya
            printf("-");
        }
        
    }else{//jika kurang atau sama dengan 4
        for(i = 0; i < 4; i++){
            printf("-");//maka print '-' sebanyak 4 kali
        }
    }
    printf("-+-");
    
    max.manuf = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
    space.manuf = 0;//membuat variabel untuk menampung jumlah spasi
    for(i = 0; i < n; i++){
        if(max.manuf < strlen(str[i].manuf)){//jika ada strlen jenis yang lebih panjang
            max.manuf = strlen(str[i].manuf);//maka update nilai max nya
        }
    }

    if(max.manuf > 12){//jika maksimalnya lebih dari 12
        for(i = 0; i < max.manuf; i++){//maka print '-' sebanyak panjang maksimalnya
            printf("-");
        }
        
    }else{//jika kurang atau sama dengan 12
        for(i = 0; i < 12; i++){
            printf("-");//maka print '-' sebanyak 12 kali
        }
    }
    printf("-+-");
    
    max.class = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
    space.class = 0;//membuat variabel untuk menampung jumlah spasi
    for(i = 0; i < n; i++){
        if(max.class < strlen(str[i].class)){//jika ada strlen jenis yang lebih panjang
            max.class = strlen(str[i].class);//maka update nilai max nya
        }
    }

    if(max.class > 5){//jika maksimalnya lebih dari 5
        for(i = 0; i < max.class; i++){//maka print '-' sebanyak panjang maksimalnya
            printf("-");
        }
        
    }else{//jika kurang atau sama dengan 5
        for(i = 0; i < 5; i++){
            printf("-");//maka print '-' sebanyak 5 kali
        }
    }
    printf("-+-");
    
    max.nation = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
    space.nation = 0;//membuat variabel untuk menampung jumlah spasi
    for(i = 0; i < n; i++){
        if(max.nation < strlen(str[i].nation)){//jika ada strlen jenis yang lebih panjang
            max.nation = strlen(str[i].nation);//maka update nilai max nya
        }
    }

    if(max.nation > 11){//jika maksimalnya lebih dari 11
        for(i = 0; i < max.nation; i++){//maka print '-' sebanyak panjang maksimalnya
            printf("-");
        }
        
    }else{//jika kurang atau sama dengan 11
        for(i = 0; i < 11; i++){
            printf("-");//maka print '-' sebanyak 11 kali
        }
    }
    printf("-+-");
    
    max.weight = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
    space.weight = 0;//membuat variabel untuk menampung jumlah spasi
    for(i = 0; i < n; i++){
        if(max.weight < digit(str[i].weight)){//jika ada strlen jenis yang lebih panjang
            max.weight = digit(str[i].weight);//maka update nilai max nya
        }
    }

    if(max.weight > 6){//jika maksimalnya lebih dari 6
        for(i = 0; i < max.weight; i++){//maka print '-' sebanyak panjang maksimalnya
            printf("-");
        }
        
    }else{//jika kurang atau sama dengan 6
        for(i = 0; i < 6; i++){
            printf("-");//maka print '-' sebanyak 6 kali
        }
    }
    printf("-+\n");

    //print isi tabel
    for(i = 0; i < n; i++){//melakukan loop sebanyak jumlah array nya
        //print no, primary, dan nama
        if(i > 8){//jika no nya lebih dari 1 digit
            printf("| %d | ", i + 1);//maka print tanpa spasi setelahnya
        }else{//jika hanya 1 digit
            printf("| %d  | ", i + 1);//maka print dengan spasi setelahnya agar rata
        }
        printf("%s | %s", str[i].idVehicle, str[i].name);
        if(max.name > 5){//jika panjang maksimal stringnya lebih dari 5, maka;
            space.name = max.name - strlen(str[i].name);//spasi didapatkan dari max string dikurangi string indeks i
            if(space.name < 1) space.name = 0;//jika spasinya negatif maka spasinya 0
            for(j = 0; j < space.name; j++){
                printf(" ");//print ' ' sebanyak jumlah spasi
            }
        }else{//jika panjang maksimal stringnya kurang / sama dengan 12, maka;
            space.name = 12 - strlen(str[i].name);//spasi didapatkan dari 12 dikurang panjang string indeks i
            if(space.name < 1) space.name = 0;//jika spasinya negatif maka spasinya 0
            for(j = 0; j < space.name; j++){
                printf(" ");//print ' ' sebanyak jumlah spasi
            }
        }

        //print manufacturer
        printf(" | %s", str[i].manuf);
        if(max.manuf > 12){//jika panjang maksimal stringnya lebih dari 12, maka;
            space.manuf = max.manuf - strlen(str[i].manuf);//spasi didapatkan dari max string dikurangi string indeks i
            if(space.manuf < 1) space.manuf = 0;//jika spasinya negatif maka spasinya 0
            for(j = 0; j < space.manuf; j++){
                printf(" ");//print ' ' sebanyak jumlah spasi
            }
        }else{//jika panjang maksimal stringnya kurang / sama dengan 12, maka;
            space.manuf = 12 - strlen(str[i].manuf);//spasi didapatkan dari 12 dikurang panjang string indeks i
            if(space.manuf < 1) space.manuf = 0;//jika spasinya negatif maka spasinya 0
            for(j = 0; j < space.manuf; j++){
                printf(" ");//print ' ' sebanyak jumlah spasi
            }
        }

        //print class
        printf(" | %s", str[i].class);
        if(max.class > 5){//jika panjang maksimal stringnya lebih dari 12, maka;
            space.class = max.class - strlen(str[i].class);//spasi didapatkan dari max string dikurangi string indeks i
            if(space.class < 1) space.class = 0;//jika spasinya negatif maka spasinya 0
            for(j = 0; j < space.class; j++){
                printf(" ");//print ' ' sebanyak jumlah spasi
            }
        }else{//jika panjang maksimal stringnya kurang / sama dengan 12, maka;
            space.class = 5 - strlen(str[i].class);//spasi didapatkan dari 12 dikurang panjang string indeks i
            if(space.class < 1) space.class = 0;//jika spasinya negatif maka spasinya 0
            for(j = 0; j < space.class; j++){
                printf(" ");//print ' ' sebanyak jumlah spasi
            }
        }

        //print nationality
        printf(" | %s", str[i].nation);
        if(max.nation > 11){//jika panjang maksimal stringnya lebih dari 11, maka;
            space.nation = max.nation - strlen(str[i].nation);//spasi didapatkan dari max string dikurangi string indeks i
            if(space.nation < 1) space.nation = 0;//jika spasinya negatif maka spasinya 0
            for(j = 0; j < space.nation; j++){
                printf(" ");//print ' ' sebanyak jumlah spasi
            }
        }else{//jika panjang maksimal stringnya kurang / sama dengan 11, maka;
            space.nation = 11 - strlen(str[i].nation);//spasi didapatkan dari 12 dikurang panjang string indeks i
            if(space.nation < 1) space.nation = 0;//jika spasinya negatif maka spasinya 0
            for(j = 0; j < space.nation; j++){
                printf(" ");//print ' ' sebanyak jumlah spasi
            }
        }
        
        //print weight
        printf(" | %d", str[i].weight);
        if(max.weight > 6){//jika panjang maksimal stringnya lebih dari 6, maka;
            // print("d= %d\n", digit(str[i].weight));
            space.weight = max.weight - digit(str[i].weight);//spasi didapatkan dari max string dikurangi string indeks i
            if(space.weight < 1) space.weight = 0;//jika spasinya negatif maka spasinya 0
            for(j = 0; j < space.weight; j++){
                printf(" ");//print ' ' sebanyak jumlah spasi
            }
        }else{//jika panjang maksimal stringnya kurang / sama dengan 12, maka;
            space.weight = 6 - digit(str[i].weight);//spasi didapatkan dari 12 dikurang panjang string indeks i
            if(space.weight < 1) space.weight = 0;//jika spasinya negatif maka spasinya 0
            for(j = 0; j < space.weight; j++){
                printf(" ");//print ' ' sebanyak jumlah spasi
            }
        }

        printf(" |\n");
    }

    //memprint bagian bawah tabel
    printf("+----+------+-");
    
    max.name = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
    space.name = 0;//membuat variabel untuk menampung jumlah spasi
    for(i = 0; i < n; i++){
        if(max.name < strlen(str[i].name)){//jika ada strlen jenis yang lebih panjang
            max.name = strlen(str[i].name);//maka update nilai max nya
        }
    }

    if(max.name > 4){//jika maksimalnya lebih dari 4
        for(i = 0; i < max.name; i++){//maka print '-' sebanyak panjang maksimalnya
            printf("-");
        }
        
    }else{//jika kurang atau sama dengan 4
        for(i = 0; i < 4; i++){
            printf("-");//maka print '-' sebanyak 4 kali
        }
    }
    printf("-+-");
    
    max.manuf = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
    space.manuf = 0;//membuat variabel untuk menampung jumlah spasi
    for(i = 0; i < n; i++){
        if(max.manuf < strlen(str[i].manuf)){//jika ada strlen jenis yang lebih panjang
            max.manuf = strlen(str[i].manuf);//maka update nilai max nya
        }
    }

    if(max.manuf > 12){//jika maksimalnya lebih dari 12
        for(i = 0; i < max.manuf; i++){//maka print '-' sebanyak panjang maksimalnya
            printf("-");
        }
        
    }else{//jika kurang atau sama dengan 12
        for(i = 0; i < 12; i++){
            printf("-");//maka print '-' sebanyak 12 kali
        }
    }
    printf("-+-");
    
    max.class = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
    space.class = 0;//membuat variabel untuk menampung jumlah spasi
    for(i = 0; i < n; i++){
        if(max.class < strlen(str[i].class)){//jika ada strlen jenis yang lebih panjang
            max.class = strlen(str[i].class);//maka update nilai max nya
        }
    }

    if(max.class > 5){//jika maksimalnya lebih dari 5
        for(i = 0; i < max.class; i++){//maka print '-' sebanyak panjang maksimalnya
            printf("-");
        }
        
    }else{//jika kurang atau sama dengan 5
        for(i = 0; i < 5; i++){
            printf("-");//maka print '-' sebanyak 5 kali
        }
    }
    printf("-+-");
    
    max.nation = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
    space.nation = 0;//membuat variabel untuk menampung jumlah spasi
    for(i = 0; i < n; i++){
        if(max.nation < strlen(str[i].nation)){//jika ada strlen jenis yang lebih panjang
            max.nation = strlen(str[i].nation);//maka update nilai max nya
        }
    }

    if(max.nation > 11){//jika maksimalnya lebih dari 11
        for(i = 0; i < max.nation; i++){//maka print '-' sebanyak panjang maksimalnya
            printf("-");
        }
        
    }else{//jika kurang atau sama dengan 11
        for(i = 0; i < 11; i++){
            printf("-");//maka print '-' sebanyak 11 kali
        }
    }
    printf("-+-");
    
    max.weight = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
    space.weight = 0;//membuat variabel untuk menampung jumlah spasi
    for(i = 0; i < n; i++){
        if(max.weight < digit(str[i].weight)){//jika ada strlen jenis yang lebih panjang
            max.weight = digit(str[i].weight);//maka update nilai max nya
        }
    }

    if(max.weight > 6){//jika maksimalnya lebih dari 6
        for(i = 0; i < max.weight; i++){//maka print '-' sebanyak panjang maksimalnya
            printf("-");
        }
        
    }else{//jika kurang atau sama dengan 6
        for(i = 0; i < 6; i++){
            printf("-");//maka print '-' sebanyak 6 kali
        }
    }
    printf("-+\n");

}

void program(char *y){
    char perintah[51];
    char mode[51];
    data baru_Vehic;
    mcn baru_MCN;

    if(*y != 'n' && *y != 'y'){
        printf("MASUKAN CUMAN BOLEH (y/n) SAJA!!!\n");
        printf("\nMau ngasih perintah lagi gak? (y/n) :\n");
        char tmp;
        scanf(" %c", &tmp);
        *y = tmp;
        program(&*y);
    }

    while(*y == 'y'){
        int v = 0;
        data vehicle[51];
        read_Vehicle(&v, vehicle, "Vehicle.txt");

        int m = 0;
        mcn manuf[51];
        read_MCN(&m, manuf, "Manufacturer.txt");
        
        int c = 0;
        mcn class[51];
        read_MCN(&c, class, "Class.txt");
        
        int n = 0;
        mcn nation[51];
        read_MCN(&n, nation, "Nationality.txt");


        printf("Masukan perintah:\n");
        scanf("%s %s", perintah, mode);
        if(strcmp(perintah, "INSERT") == 0 || strcmp(perintah, "UPDATE") == 0 || strcmp(perintah, "DELETE") == 0){
            if(strcmp(mode, "Vehicle") == 0){
                modify_data(perintah, mode, baru_Vehic, vehicle, &v, manuf, m, class, c, nation, n);
            }else if(strcmp(mode, "VehicleComplete") == 0){
                int v1 = 0;
                data vehicleCom[51];
                read_Vehicle(&v1, vehicleCom, "VehicleComplete.txt");
                modify_data(perintah, mode, baru_Vehic, vehicleCom, &v1, manuf, m, class, c, nation, n);
            }else if(strcmp(mode, "Manufacturer") == 0){
                modify_MCN(perintah, mode, baru_MCN, manuf, &m, vehicle, v);
            }else if(strcmp(mode, "Class") == 0){
                modify_MCN(perintah, mode, baru_MCN, class, &c, vehicle, v);
            }else if(strcmp(mode, "Nationality") == 0){
                modify_MCN(perintah, mode, baru_MCN, nation, &n, vehicle, v);
            }else{
                printf("KAMU MAU UBAH APASIH, GAK SESUAI FORMAT PENULISANNYA!!!!\n");
            }
        }else if(strcmp(perintah, "SHOW") == 0){
            if(strcmp(mode, "Vehicle") == 0){
                tabel_vehicle(mode, v, vehicle);
            }else if(strcmp(mode, "VehicleComplete") == 0){
                int v1 = 0;
                data vehicleCom[51];
                read_Vehicle(&v1, vehicleCom, "VehicleComplete.txt");
                tabel_vehicle(mode, v1, vehicleCom);
            }else if(strcmp(mode, "Manufacturer") == 0){
                tabel_MCN(mode, m, manuf);
            }else if(strcmp(mode, "Class") == 0){
                tabel_MCN(mode, c, class);
            }else if(strcmp(mode, "Nationality") == 0){
                tabel_MCN(mode, n, nation);
            }else{
                printf("KAMU MAU NGELIAT TABEL APASIH, GAK SESUAI FORMAT PENULISANNYA!!!!\n");
            }

        }else{
            printf("MASUKAN PERINTAH TIDAK SESUAI FORMAT!!!!!\n");
        }

        trans(v, vehicle, m, manuf, c, class, n, nation);
        write_Vehicle(v, vehicle, "VehicleComplete.txt");

        printf("\nMau ngasih perintah lagi gak? (y/n) :\n");
        char tmp;
        scanf(" %c", &tmp);
        *y = tmp;
    };
    
}

void panduan(){
    printf("============================================================================\n");
    printf("|+------------------------------------------------------------------------+|\n");
    printf("||                                                                        ||\n");
    printf("||     <<<<<<<<<<<<<  BUKU PANDUAN MENGGUNAKAN KODE  >>>>>>>>>>>>>        ||\n");
    printf("||                                                                        ||\n");
    printf("||     1. Pilih Mau Kasih Perintah Atau Enggak (y/n).                     ||\n");
    printf("||                                                                        ||\n");
    printf("||     2. Pilih Masukan Perintah Dengan Format [Perintah] [Data]          ||\n");
    printf("||        CASE SENSITIVE!!!!                                              ||\n");
    printf("||        Perhatikan Huruf Besar Kecilnya                                 ||\n");
    printf("||                 +----------+   +-------------------+                   ||\n");
    printf("||                 | PERINTAH |   |       DATA        |                   ||\n");
    printf("||                 +----------+   +-------------------+                   ||\n");
    printf("||                 |   SHOW   |   |    Manufacturer   |                   ||\n");
    printf("||                 |  INSERT  |   |       Class       |                   ||\n");
    printf("||                 |  UPDATE  |   |    Nationality    |                   ||\n");
    printf("||                 |  DELETE  |   |      Vehicle      |                   ||\n");
    printf("||                 +----------+   |  VehicleComplete  |                   ||\n");
    printf("||                                +-------------------+                   ||\n");
    printf("||                                                                        ||\n");
    printf("||     3. Jika Anda Memilih SHOW, Maka Anda Akan Dapat Melihat Data       ||\n");
    printf("||        Pada Tabel.                                                     ||\n");
    printf("||                                                                        ||\n");
    printf("||     4. Jika Anda Memilih INSERT/ UPDATE, Tulis ID dan Nama Jenisnya.   ||\n");
    printf("||         a. Jika Manufacturer/ Class/ Nationality                       ||\n");
    printf("||            [Kode Primary] [Jenis]                                      ||\n");
    printf("||         b. Jika Vehicle                                                ||\n");
    printf("||            [Kode Primary] [Nama] [IdManufactuer] [IdClass]             ||\n");
    printf("||            [IdNationality] [Weight]                                    ||\n");
    printf("||         c. Jika VehicleComplete                                        ||\n");
    printf("||            Anda Tidak Bisa Melakukan INSERT/ UPDATE Dalam              ||\n");
    printf("||            VehicleCompelete                                            ||\n");
    printf("||                                                                        ||\n");
    printf("||     5. Jika Anda Memilih DELETE, Tulis ID nya saja.                    ||\n");
    printf("||         a. Jika Vehicle/ Manufacturer/ Class/ Nationality              ||\n");
    printf("||            [Kode Primary]                                              ||\n");
    printf("||         b. Jika VehicleCompelete                                       ||\n");
    printf("||            Anda Tidak Bisa Melakukan DELETE Dalam VehicleCompelete     ||\n");
    printf("||                                                                        ||\n");
    printf("||                                                                        ||\n");
    printf("|+------------------------------------------------------------------------+|\n");
    printf("============================================================================\n");
}