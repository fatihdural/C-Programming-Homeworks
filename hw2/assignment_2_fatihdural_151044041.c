#include <stdio.h>
double avarege_calculater(double a[100][1000], int i, int j){ /* bu fonksiyon girilen a[][] dizisinin istenilen chunkýnýn ortalamasýný döndürür. */
	int k;
	double num = 0;
	for(k=0; k<=j; k++){      /* j, chunkýn eleman sayýsýný ifade eder. Elemanlar toplanýp eleman sayýsýna bölünerek ortalama hesaplanýr. */
		num = num + a[i][k];
	}
	return num / (j + 1);
}

int swap(double a[100][1000], int i, int b, int c, int d){ /* bu fonksiyon a[][] dizisinin istenilen 2 chunkýný yer deðiþtirir, swap eder. */
	double temp[1000]; int x, max_num;
	if(b>d)	
		max_num = b;						/* büyük elemaný bulmak amacýyla max_num tanýmlanýr. */
	else 
		max_num = d;
	for(x = 0; x<=max_num; x++){	/* elemanlarý tek tek yer deðiþtirir. */
		temp[x] = a[i][x];
		a[i][x] = a[c][x];
		a[c][x] = temp[x];
	}	
}

int main(){
	FILE *fp, *fp2; /* dosyayý okumak amacýyla fp, dosyaya yazmak amacýyla fp2 pointerlarý oluþturulur. */
	double a[100][1000]; int b[1000]; /* dosyadan okuduðumuz deðerleri tutmak amacýyla a[][] dizisi ve chunklarýn sizelarýný tutmak amacýyla b[] dizisi oluþturulur. */
	int i, j, k, zero_count, total, tempp; /* kullanacaðýmýz deðiþkenler tanýmlanýr. */
	i = 0; j = 0; k = 0; zero_count = 0; total = 0; tempp = 0; /* deðiþkenlerin ilk deðerleri atanýr. */ 
	fp = fopen("input.txt","r"); /* okumak amacýyla input.txt dosyasý açýlýr. */
	fp2 = fopen("output.txt","w"); /* yazmak amacýyla output.txt dosyasý açýlýr. */
	while(!feof(fp)) /* dosyanýn sonuna kadar devam et! */
	{
		fscanf(fp,"%lf",&a[k][i]); /* fscanf fonksiyonu ile dosyadan okunur. Hangi chunk olduðunu anlamak için k deðiþkeni kullanýlmýþtýr. a[0] ilk chunký ifade eder gibi. */
		if( a[k][i] == 0 ){
			i--;
			zero_count++; /* sýfýr okunduðunda counter artýlýr, 3 kez sýfýr okunduðunda chunk oluþmuþtur. */
			if(zero_count == 3){
				b[j] = i; /* chunklarýn boyutunu ifade etmek amacýyla kullanýlýr. */
				total = total + i+1; /* total deðiþkeni toplam eleman sayýsýný bulmak amacýyla kulllanýlmýþtýr. */
				j++;
				i = -1;  /* i yi birazdan 1 artýracaðýmýzdan -1 e assign ediyoruz. Counterý sýfýrlýyoruz. */
				zero_count = 0;
				k++; /* k chunk numarasýný ifade ediyordu. Yeni chunka geçeceðimizden k' yý artýrýyoruz. */
			}
		}
		i++;
	}
	b[j] = i - 1;
	total = total + b[j];
	for(k=0; k<j; k++){
		for(i=k; i<j; i++){
			if( avarege_calculater(a, k, b[k]) > avarege_calculater(a, i+1, b[i+1]) ){/* her chunkýn ortalamasýný avarege_calculater fonksiyonu ile bulup kýyaslýyoruz ve sýralýyoruz.*/
				swap( a, k, b[k], i+1, b[i+1] );  /* kýyaslanan chunk daha küçükse swap fonksiyonunu kullanarak chunklarý yer deðiþtiriyoruz. */
				tempp = b[k];  /* sizelarýda swap iþleminden sonra yer deðiþtiriyoruz ki karýþmasýn. */
				b[k] = b[i+1]; 
				b[i+1] = tempp;
			}
		}
	}
	for(i=0; i<=j; i++){
		for(k=0; k<=b[i]; k++){
			fprintf(fp2,"%5.3lf ", a[i][k]); /* a dizisindeki elemanlarý istenilen þekilde output.txt dosyasýna yazdýyoruz. */
		}
		fprintf(fp2,"\n");
	}
	fclose(fp); /* dosyalar kapanýr. */
	fclose(fp2);
	return 0;
}
