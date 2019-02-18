#include <stdio.h>
int find(char a[100][250], char desired[], int size); /* içeriði doldurulacak fonksiyon tanýmlanýr. */
int main(){
	FILE *fp;
	fp = fopen("input.txt","r"); /* input.txt dosyasý okunmak için açýlýr. */
	char desired1[] = "Xanthos"; /* dosya içinde aranacak kelimeler ilk baþta tanýmlanýr. */
	char desired2[] = "Patara";
	char desired3[] = "Myra";
	char desired4[] = "Arycanda";
	char desired5[] = "Phaselis";
	char a[100][250]; int i; /* dosyadan okunacak her satýrý almak üzere 2 boyutlu char array'i oluþturulur ve kullanýlmak üzere i deðiþkeni tanýmlanýr. */
	while(fscanf(fp, "%s", a[i]) != EOF){ /* dosyanýn sonuna kadar her satýr string olarak okunur. */
		i++;
	}
	find(a, desired1, 7); /* aþaðýda içeriði tanýmlý fonksiyon 5 kez çaðýrýlýr. */
	find(a, desired2, 6); /* fonksiyona tüm satýrlarý barýndýran a[][] stringi, aranacak kelime ve kelimenin uzunluðu parametre olarak verilir. */
	find(a, desired3, 4);
	find(a, desired4, 8);
	find(a, desired5, 8);
	fclose(fp); 			/* fopen fonksiyonuyla açýlan dosya iþlemler sonunda kapanýr. */
	return 0;
}
int find(char a[100][250], char desired[], int size){
	int i, j, k, x, count; /* çeþitli amaçlarda kullanýlan deðiþkenler tanýmlanýr. */
	i = 0; j = 0; k = 0; count = 0; /* ilk deðerleri 0 olarak atanýr. */
	while(1){ 			   /* döngü içinde kendi kendine kýralana kadar döner. Bu döngünün amacý kelimeyi soldan saða aramaktýr. */
		if(a[k][i] == '\0'){ /* satýr sonuna gelindiðinde çeþitli iþlemler uygulanýr. */
			k++; /* dosyadan okunan satýrlarýn numarasýný k ifade eder. Satýr sonuna gelindiðinde k artýrýlýr. */
			i = 0; /* sütunu ifade eden i sýfýrlanýr. */
			count = 0; /* sayaç sýfýrlanýr. */
			j = 0; /* eðer o satýrda bulunamazsa j de sýfýrlanýr. j kelimenin harf numaralarýný ifade eder. */
		}  
		if(a[k][i] == desired[j]){ /* eðer satýrdaki herhangi bir eleman kelimenin harfine eþitse gir. */
			j++; /* diðer harfe bakmak için j yi artýr. */
			count++; /* sayacý artýr. */
			if(count == size){ /* eðer sayaç boyuta eþitse yani o satýrda saðdan sola doðru kelime mevcutsa. */
				printf("%s (%d,%d) Horizontal\n", desired, k + 1, i - size + 2); /*  formatta belirtildiði üzere kelimenin nerde bulunduðunu yazdýr.*/
				return 0; /* fonksiyondan çýk. */
			}
		}
		i++; /* satýrdaki bir sonraki harfe yani bir sonraki sütuna bakmak için i yi artýr. */
		if(k > 100){ /* satýr sayýsý max. miktardan fazlaysa döngüden çýk. */
			break; 
		}
	}
	i = 0; j = 0; k = 0; count = 0; /* deðiþkenleri tekrar kullanmak üzere deðiþkenleri sýfýrla. */
	while(1){					   /* döngü içinde kendi kendine kýralana kadar döner. Bu döngünün amacý kelimeyi yukarýdan aþaðý aramaktýr. */
		if(a[k][i] == '\0'){		/* satýr sonuna gelindiðinde çeþitli iþlemler uygulanýr. */
			k++;	/* dosyadan okunan satýrlarýn numarasýný k ifade eder. Satýr sonuna gelindiðinde k artýrýlýr. */
			i = 0;	/* sütunu ifade eden i sýfýrlanýr. */
			count = 0;  /* sayaç sýfýrlanýr. */
			j = 0; /* eðer o satýrda bulunamazsa j de sýfýrlanýr. j kelimenin harf numaralarýný ifade eder. */
		}  
		if(a[k][i] == desired[j]){ /* eðer satýrdaki herhangi bir eleman kelimenin harfine eþitse gir. */
			count++; /* sayacý artýr. */
			x = k; /* k'nýn ilk deðerini kaybetmemek için deðeri x'e assign edip iþlemlere x ile devam edilir. */
			while(1){
				x++; /* kelimeyi yukarýdan aþaðý aramak için x artýlýr yani alt satýra bakýlýr. */
				j++; /* kelimenin diðer harfine bakýlmak üzere j artýrlýr. */
				if(a[x][i] == desired[j]){ /* eðer harf bulunursa gir. */
					count++; /* sayacý artýr. */
				}
				if(count == size){ /* eðer sayaç boyuta eþitse yani o sütunda yukarýdan aþaðýya doðru kelime mevcutsa. */
					printf("%s (%d,%d) Vertical\n", desired, x-size+2, i+1); /* formatta belirtildiði üzere kelimenin nerde bulunduðunu yazdýr.*/
					return 0; /* fonksiyondan çýk. */
				}
				if (x > 100 || a[x][i] == '\0'){ /* satýr sayýsý max. miktardan fazlaysa veya satýr sonuna gelindiyse döngüden çýk. */
					j = 0;
					break;
				}
			}
		}
		i++;
		if(k > 100){ 	 /* satýr sayýsý max. miktardan fazlaysa döngüden çýk. */
			return 0; /* fonksiyondan çýk. */
		}
	}
}
