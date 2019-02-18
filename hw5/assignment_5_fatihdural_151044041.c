#include <stdio.h>
int initializer(int k[728]){ /* bu fonksiyon parametre olarak gonderilen int arrayin elemanlarini initialize eder( her elemana sifir atar). */
	int a; /* dongu kurmak amaciyla degisken tanimlanir. */
	for( a = 0; a < 728; a++ ){ /* dongu 728 defa doner. */
		k[a] = 0; /* her elemana sifir atanir. */
	}
	return 1; 
}
double find_bigrams(FILE *fp, int bigram[728]){ /* bu fonksiyon kendisine gonderilen filepointer icin dosyayi tarar, ikililerinin adetini bigram arrayine yerlestirir. */
	char x, y, temp; /* degiskenler tanimlanir. */												/* ornek: dosyada 'aa' ikilisi 5 defa varsa bigram[0] = 5 olacaktir. */
	int count = 0; /* count bigram sayisini tutar. */
	x = fgetc(fp); /* fgetc() fonksiyonu ile dosyadan bir karakter okunur ve x degiskenine assign edilir. */
	while( !feof(fp) ){ /* dosya sonuna kadar doner. */
		y = fgetc(fp); /* fgetc() fonksiyonu ile bir karakter daha okunur. */
		if( y != EOF ){ /* ikinci okunan karakterin dosya sonuna gelip gelmedigini kontrol eder. */
			temp = y; /* y degerinin degisme ihtimali icin degeri temp degiskenine atanir. */
			if( y == '\n' ){ /* eger karakter '\n' ise */
				y == ' '; /* y' ye ' ' yani space karakteri atanir. */
				temp = y; /* degeri tempe atanir. */
			} 
			if( x < 97 && y < 97 ){ /* x ve y yani bigramin iki karakterininde ascii karsýlýgý 97 den kucukse dongunun basina tekrar cik.  */
				continue;			/* 97 yazilmasinin sebebi ascii karsiligi yani karakterlerin (int) degerlerinin 97'den buyuk olmasidir. */
			}
			if( y < 97 ){	/* y kosula uygunsa gir. */
				y = 'a' + 26; /* y' ye 'a' + 26 yi ata. */
			}
			if( x < 97 ){	/* x kosula uygunsa gir. */
				x = 'a' + 26; /* x' e 'a' + 26 yi ata. */
			}
			bigram[ (x - 'a') * 27  + (y - 'a')] += 1; /* bu formule gore o ikilinin bulundugu indis 1 arttirilir. */
			x = temp; /* x'e tempi yani y degerini ata(ikililer birer birer kayarak gittigi icin bir onceki y degeri x'e atanir ). */
			count++; /* count degiskenini bir arttir. count tum ikili sayisinin adetini tutar. */
		}
	}
	return count; /* fonksiyonun geri donus degeri olarak count dondurur. */
}
double print_dissimilarity( int bigram1[728], int bigram2[728], double count1, double count2 ){ /* bu fonksiyon kendisine gonderilen bigram ve counterlarina gore verilen */
	double dissimilarity = 0, dissimilarity_temp = 0;											/* frekans formulunu kullanarak ekrana dissimilarityleri basar. */
	int i;	/* degiskenler tanimlanir ve initialize edilir. */
	for(i = 0; i < 728; i++){ /* dongu 728 defa tekrar eder. */
		dissimilarity_temp = ( (double) bigram1[i] / count1 ) - ( (double) bigram2[i] / count2 ); /* formule gore frekanslari cikartir ve degeri dissimilarity_tempe atar. */
		if( dissimilarity_temp < 0 ){ /* dissimilarity sýfýrdan kucukse(negatifse) -1 ile carparak pozitif yapar. */
			dissimilarity_temp *= -1;
		}
		dissimilarity += dissimilarity_temp; /* dissimilarity' e dissimilarity_temp eklenir. */
	}
	printf("%lf\n", dissimilarity); /* dissimilarity ekrana basilir. */
	return dissimilarity;
}
int main(){ 
	FILE *fp = fopen("language_x.txt","r"); /* okunmak amacýyla dosyalar acilir. */
	FILE *fp1 = fopen("language_1.txt","r");
	FILE *fp2 = fopen("language_2.txt","r");
	FILE *fp3 = fopen("language_3.txt","r");
	FILE *fp4 = fopen("language_4.txt","r");
	FILE *fp5 = fopen("language_5.txt","r");
	int bigram1[728], bigram2[728]; /* iki int array tutulur bunlar ikililerin dosyada kac kez bulundugunu ifade etmek amaciyla fonksiyona gonderilecektir. */
	double count1 = 0, count2 = 0; /* degiskenler tanimlanir, bu degiskenler tum ikili sayisini ifade eder. */
	
	initializer(bigram1); /* arraylar initializer fonksiyonu ile initialize edilir ve tum elemanlarina sifir atanir. */
	initializer(bigram2);
	count1 = find_bigrams(fp, bigram1); /* find_bigrams fonksiyonu cagirilir, geri donus degeri countlara atanir ve bigramlar doldurulmus olur. */
	count2 = find_bigrams(fp1, bigram2); 
	print_dissimilarity( bigram1, bigram2, count1, count2); /* ekrana iki dosya arasindaki dissimilarity degeri bastirilir. */ 
	
	initializer(bigram2); 					/* her zaman language_x.txt dosyasi ile kiyaslama yapildigi icin ona daha islem */
	count2 = find_bigrams(fp2, bigram2); 	/* yapilmaz diger dosyalara ayni islemler yapilir ve ekrana dissimilarityler basilir. */
	print_dissimilarity( bigram1, bigram2, count1, count2);
		
	initializer(bigram2);
	count2 = find_bigrams(fp3, bigram2); 
	print_dissimilarity( bigram1, bigram2, count1, count2);	
	
	initializer(bigram2);
	count2 = find_bigrams(fp4, bigram2); 
	print_dissimilarity( bigram1, bigram2, count1, count2);	
	
	initializer(bigram2);
	count2 = find_bigrams(fp5, bigram2); 
	print_dissimilarity( bigram1, bigram2, count1, count2);

	fclose(fp); /* dosyalar kapanir. */
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	fclose(fp5);
	return 1;
}


















