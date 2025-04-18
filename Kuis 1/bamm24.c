/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Kuis 1 "bamm24" dalam mata kuliah
dasar pemrograman untuk keberkahan-Nya, maka saya
tidak akan melakukan kecurangan seperti yang telah
di spesifikasikan Aamiin.*/
#include <stdio.h>//bagian header(library)

typedef struct{
	int panjang;
	int lebar;
	int tinggi;
	int luaspermukaan;
	int volume;
}balok;

/*membuat variabel untuk menampung nilai
	*/
int main(){
	balok a;
	
	scanf("%d %d %d\n", &a.panjang, &a.lebar, &a.tinggi);
	
	a.luaspermukaan = 2 * ((a.panjang * a.lebar) + (a.panjang * a.tinggi) + (a.tinggi * a.lebar));
	a.volume = a.panjang * a.lebar * a.tinggi;
	
	balok b;
	
	scanf("%d %d %d\n", &b.panjang, &b.lebar, &b.tinggi);
	
	b.luaspermukaan = 2 * ((b.panjang * b.lebar) + (b.panjang * b.tinggi) + (b.tinggi * b.lebar));
	b.volume = b.panjang * b.lebar * b.tinggi;
	
	balok c;
	
	scanf("%d %d %d", &c.panjang, &c.lebar, &c.tinggi);
	
	c.luaspermukaan = 2 * ((c.panjang * c.lebar) + (c.panjang * c.tinggi) + (c.tinggi * c.lebar));
	c.volume = c.panjang * c.lebar * c.tinggi;
	
	if((a.volume > b.volume) && (a.volume > c.volume)){
		//jika volume a paling besar
		if(b.volume > c.volume){
			printf("%d %d %d %d %d\n", a.volume, a.luaspermukaan, a.panjang, a.lebar, a.tinggi);
			printf("%d %d %d %d %d\n", c.volume, c.luaspermukaan, c.panjang, c.lebar, c.tinggi);
			printf("%d %d %d %d %d\n", b.volume, b.luaspermukaan, b.panjang, b.lebar, b.tinggi);
		}else{
			printf("%d %d %d %d %d\n", a.volume, a.luaspermukaan, a.panjang, a.lebar, a.tinggi);
			printf("%d %d %d %d %d\n", b.volume, b.luaspermukaan, b.panjang, b.lebar, b.tinggi);
			printf("%d %d %d %d %d\n", c.volume, c.luaspermukaan, c.panjang, c.lebar, c.tinggi);
		}
	}

	if((b.volume > a.volume) && (b.volume > c.volume)){
		//jika volume b paling besar
		if(a.volume > c.volume){
			printf("%d %d %d %d %d\n", b.volume, b.luaspermukaan, b.panjang, b.lebar, b.tinggi);
			printf("%d %d %d %d %d\n", c.volume, c.luaspermukaan, c.panjang, c.lebar, c.tinggi);
			printf("%d %d %d %d %d\n", a.volume, a.luaspermukaan, a.panjang, a.lebar, a.tinggi);
		}else{
			printf("%d %d %d %d %d\n", b.volume, b.luaspermukaan, b.panjang, b.lebar, b.tinggi);
			printf("%d %d %d %d %d\n", a.volume, a.luaspermukaan, a.panjang, a.lebar, a.tinggi);
			printf("%d %d %d %d %d\n", c.volume, c.luaspermukaan, c.panjang, c.lebar, c.tinggi);
		}
	}
	
	if((c.volume > b.volume) && (c.volume > a.volume)){
		//jika volume c paling besar
		if(a.volume > b.volume){
			printf("%d %d %d %d %d\n", c.volume, c.luaspermukaan, c.panjang, c.lebar, c.tinggi);
			printf("%d %d %d %d %d\n", b.volume, b.luaspermukaan, b.panjang, b.lebar, b.tinggi);
			printf("%d %d %d %d %d\n", a.volume, a.luaspermukaan, a.panjang, a.lebar, a.tinggi);
		}else{
			printf("%d %d %d %d %d\n", c.volume, c.luaspermukaan, c.panjang, c.lebar, c.tinggi);
			printf("%d %d %d %d %d\n", a.volume, a.luaspermukaan, a.panjang, a.lebar, a.tinggi);
			printf("%d %d %d %d %d\n", b.volume, b.luaspermukaan, b.panjang, b.lebar, b.tinggi);
		}
	}
	
	return 0;
}