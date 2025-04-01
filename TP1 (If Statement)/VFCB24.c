#include <stdio.h> //bagian header (library)

int main(){
	/*membuat variabel untuk menampung nilai 
	l = gol yang didapatkan lewandowski
	r = gol yang didapatkan raphinha
	y = gol yang didapatkan yamal
	n = lama hari barcelona latihan
	hari = sisa hari latihan
	bulan = sisa bulan latihan
	tahun = sisa tahun latihan
	performa = performa yang dimiliki tim barca
	pl = performa lewandowski
	pr = performa raphinha
	py = performa yamal
	homeAway = posisi tim bermain home/away*/
	
    int l, r, y, tahun, bulan, hari, n, performa;
    char pl, pr, py;
	char homeAway;
	
	/*meminta input dari user*/
    scanf("%d %d %d\n", &l, &r, &y);
    scanf("%c\n", &homeAway);
    scanf("%d", &n);

	/*membuat kondisi jumlah gol yang didapatkan
	Lewandowski dan menentukan performa pemain*/
    if(l >= 2){
        pl = 'S';
    } else if(l == 1){
        pl = 'A';
    } else if(l == 0){
        pl = 'B';
    } 

	/*membuat kondisi jumlah gol yang didapatkan
	Raphinha dan menentukan performa pemain*/
    if(r >= 2){
        pr = 'S';
    } else if(r == 1){
        pr = 'A';
    } else if(r == 0){
        pr = 'B';
    }  

	/*membuat kondisi jumlah gol yang didapatkan
	Yamal dan menentukan performa pemain*/
    if(y >= 2){
        py = 'S';
    } else if(y == 1){
        py = 'A';
    } else if(y == 0){
        py = 'B';
    } 

	/*membuat kondisi jika ada pemain dengan
	performa S, maka akan menambah performa tim*/	
    if(pl == 'S') {
		performa += 20;
	}
    if(pr == 'S') {
		performa += 20;
	}
    if(py == 'S') {
		performa += 20;
	}

    /*membuat kondisi kemungkinan home atau away*/
    if(homeAway == 'H'){
        performa += 26;//kemungkinan jika home
    } else if(homeAway == 'A'){
        performa += 10;//kemungkinan jika away
    }

    /*membuat kondisi jika bermain home
	dan total gol lebih dari 5*/
    if(homeAway == 'H' && l + r + y > 5){
        performa -=7;
    }

    /*membuat kondisi jika lewandowski bermain
	away maka ia akan bertambah semangat*/
    if(homeAway == 'A' && l >= 1){
        performa += 10;
    }

    /*membuat kondisi jika ada 2 penyerang yang mencetak gol*/
    if((l == 2 && r == 2) || (l == 2 && y == 2) || (r == 2 && y == 2)){
        performa +=17;//jika 2 penyerang mencetak 2 gol
    } else if((l == 0 && r == 0) || (l == 0 && y == 0) || (r == 0 && y == 0)){
        performa -=17;//jika 2 penyerang tidak mencetak gol sama sekali
    }

	/*membuat hasil sisa waktu dalam tahun, bulan, dan hari*/
    tahun = n/365;
    n = n%365;
    bulan = n/30;
    hari = n%30;

	/*membuat kondisi untuk memenuhi ketentuan menang*/
    if(((pl=='S')||(pr=='S')||(py=='S')) && ((l >= 1) || (r >= 1) || (y >= 1)) && (performa >=40)){
        printf("Total Performa Tim %d! Visca Barca y Visca catalunya~\nBarca perlu latihan lagi selama :\n%d Tahun %d Bulan %d Hari\n", performa, tahun, bulan, hari);
    } else{
        printf("Total Performa %d! coba lagi BarCa awal musim\nBarca perlu latihan lagi selama :\n%d Tahun %d Bulan %d Hari\n", performa, tahun, bulan, hari);
    }

    return 0;
}

/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan tugas praktikum 1 dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/