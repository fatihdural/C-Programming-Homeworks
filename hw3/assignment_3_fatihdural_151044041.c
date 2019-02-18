#include <stdio.h>
int find(char a[100][250], char desired[], int size); /* i�eri�i doldurulacak fonksiyon tan�mlan�r. */
int main(){
	FILE *fp;
	fp = fopen("input.txt","r"); /* input.txt dosyas� okunmak i�in a��l�r. */
	char desired1[] = "Xanthos"; /* dosya i�inde aranacak kelimeler ilk ba�ta tan�mlan�r. */
	char desired2[] = "Patara";
	char desired3[] = "Myra";
	char desired4[] = "Arycanda";
	char desired5[] = "Phaselis";
	char a[100][250]; int i; /* dosyadan okunacak her sat�r� almak �zere 2 boyutlu char array'i olu�turulur ve kullan�lmak �zere i de�i�keni tan�mlan�r. */
	while(fscanf(fp, "%s", a[i]) != EOF){ /* dosyan�n sonuna kadar her sat�r string olarak okunur. */
		i++;
	}
	find(a, desired1, 7); /* a�a��da i�eri�i tan�ml� fonksiyon 5 kez �a��r�l�r. */
	find(a, desired2, 6); /* fonksiyona t�m sat�rlar� bar�nd�ran a[][] stringi, aranacak kelime ve kelimenin uzunlu�u parametre olarak verilir. */
	find(a, desired3, 4);
	find(a, desired4, 8);
	find(a, desired5, 8);
	fclose(fp); 			/* fopen fonksiyonuyla a��lan dosya i�lemler sonunda kapan�r. */
	return 0;
}
int find(char a[100][250], char desired[], int size){
	int i, j, k, x, count; /* �e�itli ama�larda kullan�lan de�i�kenler tan�mlan�r. */
	i = 0; j = 0; k = 0; count = 0; /* ilk de�erleri 0 olarak atan�r. */
	while(1){ 			   /* d�ng� i�inde kendi kendine k�ralana kadar d�ner. Bu d�ng�n�n amac� kelimeyi soldan sa�a aramakt�r. */
		if(a[k][i] == '\0'){ /* sat�r sonuna gelindi�inde �e�itli i�lemler uygulan�r. */
			k++; /* dosyadan okunan sat�rlar�n numaras�n� k ifade eder. Sat�r sonuna gelindi�inde k art�r�l�r. */
			i = 0; /* s�tunu ifade eden i s�f�rlan�r. */
			count = 0; /* saya� s�f�rlan�r. */
			j = 0; /* e�er o sat�rda bulunamazsa j de s�f�rlan�r. j kelimenin harf numaralar�n� ifade eder. */
		}  
		if(a[k][i] == desired[j]){ /* e�er sat�rdaki herhangi bir eleman kelimenin harfine e�itse gir. */
			j++; /* di�er harfe bakmak i�in j yi art�r. */
			count++; /* sayac� art�r. */
			if(count == size){ /* e�er saya� boyuta e�itse yani o sat�rda sa�dan sola do�ru kelime mevcutsa. */
				printf("%s (%d,%d) Horizontal\n", desired, k + 1, i - size + 2); /*  formatta belirtildi�i �zere kelimenin nerde bulundu�unu yazd�r.*/
				return 0; /* fonksiyondan ��k. */
			}
		}
		i++; /* sat�rdaki bir sonraki harfe yani bir sonraki s�tuna bakmak i�in i yi art�r. */
		if(k > 100){ /* sat�r say�s� max. miktardan fazlaysa d�ng�den ��k. */
			break; 
		}
	}
	i = 0; j = 0; k = 0; count = 0; /* de�i�kenleri tekrar kullanmak �zere de�i�kenleri s�f�rla. */
	while(1){					   /* d�ng� i�inde kendi kendine k�ralana kadar d�ner. Bu d�ng�n�n amac� kelimeyi yukar�dan a�a�� aramakt�r. */
		if(a[k][i] == '\0'){		/* sat�r sonuna gelindi�inde �e�itli i�lemler uygulan�r. */
			k++;	/* dosyadan okunan sat�rlar�n numaras�n� k ifade eder. Sat�r sonuna gelindi�inde k art�r�l�r. */
			i = 0;	/* s�tunu ifade eden i s�f�rlan�r. */
			count = 0;  /* saya� s�f�rlan�r. */
			j = 0; /* e�er o sat�rda bulunamazsa j de s�f�rlan�r. j kelimenin harf numaralar�n� ifade eder. */
		}  
		if(a[k][i] == desired[j]){ /* e�er sat�rdaki herhangi bir eleman kelimenin harfine e�itse gir. */
			count++; /* sayac� art�r. */
			x = k; /* k'n�n ilk de�erini kaybetmemek i�in de�eri x'e assign edip i�lemlere x ile devam edilir. */
			while(1){
				x++; /* kelimeyi yukar�dan a�a�� aramak i�in x art�l�r yani alt sat�ra bak�l�r. */
				j++; /* kelimenin di�er harfine bak�lmak �zere j art�rl�r. */
				if(a[x][i] == desired[j]){ /* e�er harf bulunursa gir. */
					count++; /* sayac� art�r. */
				}
				if(count == size){ /* e�er saya� boyuta e�itse yani o s�tunda yukar�dan a�a��ya do�ru kelime mevcutsa. */
					printf("%s (%d,%d) Vertical\n", desired, x-size+2, i+1); /* formatta belirtildi�i �zere kelimenin nerde bulundu�unu yazd�r.*/
					return 0; /* fonksiyondan ��k. */
				}
				if (x > 100 || a[x][i] == '\0'){ /* sat�r say�s� max. miktardan fazlaysa veya sat�r sonuna gelindiyse d�ng�den ��k. */
					j = 0;
					break;
				}
			}
		}
		i++;
		if(k > 100){ 	 /* sat�r say�s� max. miktardan fazlaysa d�ng�den ��k. */
			return 0; /* fonksiyondan ��k. */
		}
	}
}
