#include <stdio.h>
double avarege_calculater(double a[100][1000], int i, int j){ /* bu fonksiyon girilen a[][] dizisinin istenilen chunk�n�n ortalamas�n� d�nd�r�r. */
	int k;
	double num = 0;
	for(k=0; k<=j; k++){      /* j, chunk�n eleman say�s�n� ifade eder. Elemanlar toplan�p eleman say�s�na b�l�nerek ortalama hesaplan�r. */
		num = num + a[i][k];
	}
	return num / (j + 1);
}

int swap(double a[100][1000], int i, int b, int c, int d){ /* bu fonksiyon a[][] dizisinin istenilen 2 chunk�n� yer de�i�tirir, swap eder. */
	double temp[1000]; int x, max_num;
	if(b>d)	
		max_num = b;						/* b�y�k eleman� bulmak amac�yla max_num tan�mlan�r. */
	else 
		max_num = d;
	for(x = 0; x<=max_num; x++){	/* elemanlar� tek tek yer de�i�tirir. */
		temp[x] = a[i][x];
		a[i][x] = a[c][x];
		a[c][x] = temp[x];
	}	
}

int main(){
	FILE *fp, *fp2; /* dosyay� okumak amac�yla fp, dosyaya yazmak amac�yla fp2 pointerlar� olu�turulur. */
	double a[100][1000]; int b[1000]; /* dosyadan okudu�umuz de�erleri tutmak amac�yla a[][] dizisi ve chunklar�n sizelar�n� tutmak amac�yla b[] dizisi olu�turulur. */
	int i, j, k, zero_count, total, tempp; /* kullanaca��m�z de�i�kenler tan�mlan�r. */
	i = 0; j = 0; k = 0; zero_count = 0; total = 0; tempp = 0; /* de�i�kenlerin ilk de�erleri atan�r. */ 
	fp = fopen("input.txt","r"); /* okumak amac�yla input.txt dosyas� a��l�r. */
	fp2 = fopen("output.txt","w"); /* yazmak amac�yla output.txt dosyas� a��l�r. */
	while(!feof(fp)) /* dosyan�n sonuna kadar devam et! */
	{
		fscanf(fp,"%lf",&a[k][i]); /* fscanf fonksiyonu ile dosyadan okunur. Hangi chunk oldu�unu anlamak i�in k de�i�keni kullan�lm��t�r. a[0] ilk chunk� ifade eder gibi. */
		if( a[k][i] == 0 ){
			i--;
			zero_count++; /* s�f�r okundu�unda counter art�l�r, 3 kez s�f�r okundu�unda chunk olu�mu�tur. */
			if(zero_count == 3){
				b[j] = i; /* chunklar�n boyutunu ifade etmek amac�yla kullan�l�r. */
				total = total + i+1; /* total de�i�keni toplam eleman say�s�n� bulmak amac�yla kulllan�lm��t�r. */
				j++;
				i = -1;  /* i yi birazdan 1 art�raca��m�zdan -1 e assign ediyoruz. Counter� s�f�rl�yoruz. */
				zero_count = 0;
				k++; /* k chunk numaras�n� ifade ediyordu. Yeni chunka ge�ece�imizden k' y� art�r�yoruz. */
			}
		}
		i++;
	}
	b[j] = i - 1;
	total = total + b[j];
	for(k=0; k<j; k++){
		for(i=k; i<j; i++){
			if( avarege_calculater(a, k, b[k]) > avarege_calculater(a, i+1, b[i+1]) ){/* her chunk�n ortalamas�n� avarege_calculater fonksiyonu ile bulup k�yasl�yoruz ve s�ral�yoruz.*/
				swap( a, k, b[k], i+1, b[i+1] );  /* k�yaslanan chunk daha k���kse swap fonksiyonunu kullanarak chunklar� yer de�i�tiriyoruz. */
				tempp = b[k];  /* sizelar�da swap i�leminden sonra yer de�i�tiriyoruz ki kar��mas�n. */
				b[k] = b[i+1]; 
				b[i+1] = tempp;
			}
		}
	}
	for(i=0; i<=j; i++){
		for(k=0; k<=b[i]; k++){
			fprintf(fp2,"%5.3lf ", a[i][k]); /* a dizisindeki elemanlar� istenilen �ekilde output.txt dosyas�na yazd�yoruz. */
		}
		fprintf(fp2,"\n");
	}
	fclose(fp); /* dosyalar kapan�r. */
	fclose(fp2);
	return 0;
}
