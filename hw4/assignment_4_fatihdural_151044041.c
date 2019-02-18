#include <stdio.h> /* gerekli kutuphaneler tanimlanir. */
#include <math.h>
int main(){
	double val[100], sonuc[500], a[500], temp[100], evaluation; /* gerekli degiþkenler tanimlanir. val arrayi values.txt deki sayilari tutar. */        			  
	char poly[1000], c[1000];						/* poly arrayi polynomial.txt deki polinomu tutar. */
	int i = 0, j = 0, k = 0, size = 0, count = 0;	/* sonuc arrayi polynomun parçalarinin sonuclarini tutar. */
	FILE *fpval = fopen("values.txt","r"); /* dosyalar okunmak veya yazilmak icin acilir. */
	FILE *fppoly = fopen("polynomial.txt","r");
	FILE *fpeval = fopen("evaluations.txt","w");

	while( fscanf(fpval,"%lf", &val[i]) != EOF ){ /* dosyanin sonuna kadar sayilari alir. */
		i++;													
	}
	size = i; 				/* kac sayi oldugu size degiskeninde tutulur. */
	fgets(c,1000,fppoly); 	/* polynom gecici olarak c stringinde tutulur. */
	for(i=0; i<1000; i++){ 	/* c stringi bosluklardan poly stringine atilarak arindirilir. */
		if(c[i] != ' '){
			poly[j] = c[i];
			j++;
		}
	}
	i=0; j=0; /* degiskenler bir daha kullanilmak uzere sifirlanir. */
	sscanf(&poly[i], "%lf", &a[j]); /* ilk parca okunur ve a arrayine atilir, a arrayi kat sayilari tutar. */
	if(a[j] > 0){ /* ilk katsayinin durumuna gore islemler yapilir. */
		i++;
		j++;
	}
	else if(a[j] < 0){
		a[j] = -1;
		i++;
		j++;
	}
	else{
		a[j] = 1;
		i++;
		j++;
	}
	while(1){ /* stringte x veya ^ varsa a arrayinin o indisine sifir atanir. */
		if( poly[i] == 'x' ){
			a[j] = 0;
			if(poly[i+1] == '^'){
				a[j+1] = 0;
				sscanf(&poly[i+2], "%lf", &a[j+2]);
				j += 3;
			}
			else{
				sscanf(&poly[i+2], "%lf", &a[j+1]);	
				if( poly[i+2] == '-' ){
					a[j+1] *= -1;
				}
				j += 2;
			}
			
		}
		if ( poly[i] == '\0'){ /* polynomin sonuna kadar doner. */
			break;}
		i++;
	}
	i = 0; j= 0; /* degiskenler bir daha kullanilmak uzere sifirlanir. */
	for(k=0; k<size; k++){ /* sayi miktari kadar kere evaluation bulunur. */
		if( a[i] == 0 ){  
			sonuc[j] = val[k];
			i++; 
			j++;
		}
		while(1){
			if( a[i] != 0 ){
				if( a[i] != -1 && a[i+2]!=0){
					sonuc[j] = a[i] * val[k];
					count++;
					j++;
				}
				if((a[i] != -1) && (a[i+2] == 0)){
					sonuc[j] = (a[i]) * (pow(val[k], a[i+3]));
					temp[i] = a[i+3];
					a[i+3] = 0;
					count++;
					j++;
				}
				if(a[i] == -1.0){
					sonuc[j] = (-1.0) * pow(val[k], a[i+2]);
					count++;
					j++;
				}    			
			}
			i++;
			if(i > 10 * size)
				break;
		}
		for(i=0; i< 10 * size; i++){ /* yukaridaki dongude sifirlanan elemanlar tekrar geri koyulur, eski elemanlar tempte tutulmustur. */
			if(temp[i] != 0)
				a[i+3] = temp[i];
		}
		evaluation = 0;	
		for(i = 0; i<count; i++){ /* sonuc arrayinin parcalari birlestirilerek evaluation bulunur. */
			evaluation += sonuc[i];
		}
		i = 0; j = 0; 							/* degiskenler bir daha kullanilmak uzere sifirlanir. */
		fprintf(fpeval, "%.2lf\n", evaluation); /* her evaluation degeri dosyaya yazilir. */
		}
		fclose(fpval); /* dosyalar kapanir. */
		fclose(fppoly);
		fclose(fpeval);
return 1;
}

