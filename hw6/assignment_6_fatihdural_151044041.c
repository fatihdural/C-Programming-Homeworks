#include <stdio.h>
int recursive(int brackets, int i, char input[100]); /* recursive fonksiyon tanimlanir. */
int control(int i, char input[100]); /* dosyada daha fazla karakter olup olmadigini kontrol eden fonksiyon tanimlanir. */
int main(){
	FILE *fp; /* pointer tanimlanir. */
	fp = fopen("input.txt","r"); /* dosya okumak amaciyla acilir. */
	char input[100]; /* dosyadan okunan tum karakterler bu stringe atanir. */
	fscanf(fp, "%s", &input); /* fscanf fonksiyonu ile dosyadaki tum karakterler okunur. */
	recursive(0, 0, input); /* recursive fonksiyon cagirilir. */
	fclose(fp); /* okunmak amacýyla acilan dosya kapatilir. */
	return 1; 
}

int recursive(int brackets, int i, char input[100]){ 
	int j;
	if(input[i] == '\0'){ /* stringin sonuna gelindiginde recursive fonksiyon biter. */
		return 1;
	}
	if( input[i] != '(' && input[i] != ')' && input[i] != ',' ){ /* eger karakter parantez ac kapat ve virgul degilse gir. */
		for( j = 0; j < brackets; j++){ /* parantez sayisi kadar don. */
			printf("-"); /* ekrana tire(-) bas. */
		}
		printf("%c", input[i]); /* ekrana karakteri bas. */
		if( control( i+1, input) == 1 ){ /* control fonksiyonun geri donus degeri 1 ise alt satýra gec. */
			printf("\n");
		} 
		return recursive(brackets, i+1, input); /* recursive fonksiyonu bidaha cagir. i dosyanýn diger karakterini ifade eder o yuzden i+1 ile dondurulur. */
	}
	if( input[i] == '(' ){ /* karakter -ac parantez- ise gir. */
		brackets++; /* parantez sayisini 1 arttir. */
		return recursive(brackets, i+1, input);	/* fonksiyonu tekrar cagir. */
	}
	else if( input[i] == ')' ){ /* eger karakter -kapa parantez- ise gir. */
		brackets--; /* parantez sayisini azalt. */
		return recursive(brackets, i+1, input); /* fonksiyonu tekrar cagir. */	
	}
	else if( input[i] == ',' ){ /* eger karakter -virgul- ise gir. */
		return recursive(brackets, i+1, input);	/* fonksiyonu tekrar cagir. */
	}
}
int control(int i, char input[100]){ 
	if( input[i] != '(' && input[i] != ')' && input[i] != ',' && input[i] != '\0') { /* karakter basilmasi gereken kosul saglanirsa gir. */
		return 1; /* kosul saglanirsa 1 return(dondur) et. Yani karakter varsa. */
	}
	if( input[i] == '\0' ){ /* dosya sonuna gelinmisse gir. */
		return 0; /* karakter bulunamamýssa 0 dondur. */
	}
	return control(i+1, input); /* recursive fonksiyonu i yi 1 artýrarak(bir sonraki eleman) tekrar cagir. */
}



