#include <stdio.h>
#include <string.h>
void row_copy( int a[], int b[], int n ); /* a arrayini b arrayine kopyalayan fonksiyon. */
int turn( int n, int cub[6][n][n],  int face_id, int rowcolumn_id, char way[5] ); /* kupu dosyadaki talimatlara gore degistiren fonksiyon. */
int main(){
	FILE *fp = fopen("commands.txt","r"); /* dosya okumak amaciyla acilir. */
	FILE *fp2 = fopen("result.txt", "w"); /* dosya yazmak amaciyla acilir. */
	int n = 0, face_id = 0, rowcolumn_id = 0, i, j, k; /* gerekli degiskenler tanimlanir ve iniatilize edilir. */
	char rowcolumn[10], way[5], temp[10]; 
	fscanf(fp, "%d", &n); 
	int cub[6][n][n];
	for( k = 0; k < 6; k++ ){ /* 3 boyutlu array olusturur. */
		for( i = 0; i < n; i++){
			for( j = 0; j < n; j++){
				cub[k][i][j] = k;
			}
		}
	}
	while( fscanf(fp, "%s %d %s %d %s", temp, &face_id, rowcolumn, &rowcolumn_id, way) != EOF ){ /* dosya sonuna kadar dosyayi oku degiskenlere ata. */
			turn( n, cub, face_id, rowcolumn_id, way ); /* fonksiyonu her satir sonunda cagir. */
	}
	for( k = 0; k < 6; k++ ){  /* cesitli talimatlara degisen kup en son haliyle dosyaya yazdirilir. */
		for( i = 0; i < n; i++){
			for( j = 0; j < n; j++){
				fprintf(fp2, "%d", cub[k][i][j]);
				if( j != n - 1 ){
					fprintf(fp2, " ");
				}
			}
			if( k == 5 && i == n - 1 ){
				fprintf(fp2,"");
			}
			else{
				fprintf(fp2,"\n");
			}
		}
		if( k < 5 ){
			fprintf(fp2, "\n");	
		}
	}	
	return 0;
}
void row_copy( int a[], int b[], int n ){ /*  a arrayini b arrayine kopyalar. */
	int i;
	for( i = 0; i < n; i++ ){ /* size kadar don her defasinda a[i] elemanini b[i] elemanina ata. */
		b[i] = a[i];
	}
}

int turn( int n, int cub[6][n][n],  int face_id, int rowcolumn_id, char way[5] ){
	int temp1[n], temp2[n], temp3[n], temp4[n], i = 0, j = 0, k = 0; /* degiskenler tanimlanir ve iniatilize edilir. */
	if( strcmp(way, "right") == 0 ){ /* eger right komutu girilirse bunlarý uygula. */
		if( face_id < 4){ /* 0, 1, 2, 3 icin uygula. */
			row_copy( cub[1][rowcolumn_id], temp1, n); /* face 1'i islem sonunda kaybetmemek icin temp1'e ata. */
			row_copy( cub[0][rowcolumn_id], cub[1][rowcolumn_id], n); /* face 0'i face 1 e ata. */ 
			row_copy( cub[2][rowcolumn_id], temp2, n); /* face 2'i temp2 e ata. */
			row_copy( temp1, cub[2][rowcolumn_id], n); /* temp1 i face 2 e ata. */
			row_copy( cub[3][rowcolumn_id], temp1, n); /* face 3 u temp1 e ata. */
			row_copy( temp2, cub[3][rowcolumn_id], n); /* temp2 i face 3 e ata. */
			row_copy( temp1, cub[0][rowcolumn_id], n); /* temp1 i face 0 a ata. */
		}
		/* asagidada komuta ve face_id e gore atamalar yapilir. */
		else if( face_id == 4 ){ 
			for( i = 0; i < n; i++){ 
				temp1[i] = cub[4][rowcolumn_id][i]; 
			}
			for( i = 0; i < n; i++){
				temp2[i] = cub[1][i][n-rowcolumn_id-1];
			}
			for( i = 0; i < n; i++){
				temp3[i] = cub[5][n-rowcolumn_id-1][i];
			}
			for( i = 0; i < n; i++){
				temp4[i] = cub[3][i][rowcolumn_id];
			}
			for( i = 0; i < n; i++){
				cub[1][i][n-rowcolumn_id-1] = temp1[i];
			}
			for( i = 0; i < n; i++){
				cub[5][n-rowcolumn_id-1][i] = temp2[n-i-1];
			}
			for( i = 0; i < n; i++){
				cub[3][i][rowcolumn_id] = temp3[i];
			}
			for( i = 0; i < n; i++){
				cub[4][rowcolumn_id][i] = temp4[n-i-1];
			}						
		}
		else if( face_id == 5 ){ 
			for( i = 0; i < n; i++){ 
				temp1[i] = cub[5][rowcolumn_id][i];
			}
			for( i = 0; i < n; i++){
				temp2[i] = cub[1][i][rowcolumn_id];
			}
			for( i = 0; i < n; i++){
				temp3[i] = cub[4][n-rowcolumn_id-1][i];
			}
			for( i = 0; i < n; i++){
				temp4[i] = cub[3][i][n-rowcolumn_id-1];
			}
			
			for( i = 0; i < n; i++){
				cub[1][i][rowcolumn_id] = temp1[n-i-1];
			}
			for( i = 0; i < n; i++){
				cub[4][n-rowcolumn_id-1][i] = temp2[i];
			}
			for( i = 0; i < n; i++){
				cub[3][i][n-rowcolumn_id-1] = temp3[n-i-1];
			}
			for( i = 0; i < n; i++){
				cub[5][rowcolumn_id][i] = temp4[i];
			}	
		}
	}
	else if( strcmp(way, "left") == 0 ){
		if( face_id < 4 ){
			row_copy( cub[3][rowcolumn_id], temp1, n);
			row_copy( cub[0][rowcolumn_id], cub[3][rowcolumn_id], n);
			row_copy( cub[2][rowcolumn_id], temp2, n);
			row_copy( temp1, cub[2][rowcolumn_id], n);
			row_copy( cub[1][rowcolumn_id], temp1, n);
			row_copy( temp2, cub[1][rowcolumn_id], n);
			row_copy( temp1, cub[0][rowcolumn_id], n);
		}
		else if( face_id == 4 ){
			for( i = 0; i < n; i++){
				temp1[i] = cub[4][rowcolumn_id][i];
			}
			for( i = 0; i < n; i++){
				temp2[i] = cub[3][i][rowcolumn_id];
			}
			for( i = 0; i < n; i++){
				temp3[i] = cub[5][n-rowcolumn_id-1][i];
			}
			for( i = 0; i < n; i++){
				temp4[i] = cub[1][i][n-rowcolumn_id-1];
			}
			
			for( i = 0; i < n; i++){
				cub[3][i][rowcolumn_id] = temp1[n-i-1];
			}
			for( i = 0; i < n; i++){
				cub[5][n-rowcolumn_id-1][i] = temp2[i];
			}
			for( i = 0; i < n; i++){
				cub[1][i][n-rowcolumn_id-1] = temp3[n-i-1];
			}
			for( i = 0; i < n; i++){
				cub[4][rowcolumn_id][i] = temp4[i];
			}						
		}
		else if( face_id == 5 ){
			for( i = 0; i < n; i++){
				temp1[i] = cub[5][rowcolumn_id][i];
			}
			for( i = 0; i < n; i++){
				temp2[i] = cub[3][i][n-rowcolumn_id-1];
			}
			for( i = 0; i < n; i++){
				temp3[i] = cub[4][n-rowcolumn_id-1][i];
			}
			for( i = 0; i < n; i++){
				temp4[i] = cub[1][i][rowcolumn_id];
			}
			
			for( i = 0; i < n; i++){
				cub[3][i][n-rowcolumn_id-1] = temp1[i];
			}
			for( i = 0; i < n; i++){
				cub[4][n-rowcolumn_id-1][i] = temp2[n-i-1];
			}
			for( i = 0; i < n; i++){
				cub[1][i][rowcolumn_id] = temp3[i];
			}
			for( i = 0; i < n; i++){
				cub[5][rowcolumn_id][i] = temp4[n-i-1];
			}		
		}
	}
	if( strcmp(way, "up") == 0 ){
		if( face_id == 0 || face_id == 4 || face_id == 5 ){
			for( i = 0; i < n; i++){
				temp1[i] = cub[0][i][rowcolumn_id];
			}
			for( i = 0; i < n; i++){
				temp2[i] = cub[4][i][rowcolumn_id];
			}
			for( i = 0; i < n; i++){
				temp3[i] = cub[2][i][n-rowcolumn_id-1];
			}
			for( i = 0; i < n; i++){
				temp4[i] = cub[5][i][rowcolumn_id];
			}
			
			for( i = 0; i < n; i++){
				cub[4][i][rowcolumn_id] = temp1[i];
			}
			for( i = 0; i < n; i++){
				cub[2][i][n-rowcolumn_id-1] = temp2[n-i-1];
			}
			for( i = 0; i < n; i++){
				cub[5][i][rowcolumn_id] = temp3[n-i-1];
			}
			for( i = 0; i < n; i++){
				cub[0][i][rowcolumn_id] = temp4[i];
			}
		}
		else if( face_id == 1 ){
			for( i = 0; i < n; i++){
				temp1[i] = cub[1][i][rowcolumn_id];
			}
			for( i = 0; i < n; i++){
				temp2[i] = cub[4][n-rowcolumn_id-1][i];
			}
			for( i = 0; i < n; i++){
				temp3[i] = cub[3][i][n-rowcolumn_id-1];
			}
			for( i = 0; i < n; i++){
				temp4[i] = cub[5][rowcolumn_id][i];
			}
			
			for( i = 0; i < n; i++){
				cub[4][n-rowcolumn_id-1][i] = temp1[i];
			}
			for( i = 0; i < n; i++){
				cub[3][i][n-rowcolumn_id-1] = temp2[n-i-1];
			}
			for( i = 0; i < n; i++){
				cub[5][rowcolumn_id][i] = temp3[i];
			}
			for( i = 0; i < n; i++){
				cub[1][i][rowcolumn_id] = temp4[n-i-1];
			}			
		}
		else if( face_id == 2 ){
			for( i = 0; i < n; i++){
				temp1[i] = cub[2][i][rowcolumn_id];
			}
			for( i = 0; i < n; i++){
				temp2[i] = cub[4][i][n-rowcolumn_id-1];
			}
			for( i = 0; i < n; i++){
				temp3[i] = cub[0][i][n-rowcolumn_id-1];
			}
			for( i = 0; i < n; i++){
				temp4[i] = cub[5][i][n-rowcolumn_id-1];
			}
			
			for( i = 0; i < n; i++){
				cub[4][i][n-rowcolumn_id-1] = temp1[n-i-1];
			}
			for( i = 0; i < n; i++){
				cub[0][i][n-rowcolumn_id-1] = temp2[i];
			}
			for( i = 0; i < n; i++){
				cub[5][i][n-rowcolumn_id-1] = temp3[i];
			}
			for( i = 0; i < n; i++){
				cub[2][i][rowcolumn_id] = temp4[n-i-1];
			}			
		}
		else if( face_id == 3 ){
			for( i = 0; i < n; i++){
				temp1[i] = cub[3][i][rowcolumn_id];
			}
			for( i = 0; i < n; i++){
				temp2[i] = cub[4][rowcolumn_id][i];
			}
			for( i = 0; i < n; i++){
				temp3[i] = cub[1][i][n-rowcolumn_id-1];
			}
			for( i = 0; i < n; i++){
				temp4[i] = cub[5][n-rowcolumn_id-1][i];
			}
			
			for( i = 0; i < n; i++){
				cub[4][rowcolumn_id][i] = temp1[n-i-1];
			}
			for( i = 0; i < n; i++){
				cub[1][i][n-rowcolumn_id-1] = temp2[i];
			}
			for( i = 0; i < n; i++){
				cub[5][n-rowcolumn_id-1][i] = temp3[n-i-1];
			}
			for( i = 0; i < n; i++){
				cub[3][i][rowcolumn_id] = temp4[i];
			}			
		}		
	} 
	else if( strcmp(way, "down") == 0 ){
		if( face_id == 0 || face_id == 4 || face_id == 5 ){
			for( i = 0; i < n; i++){
				temp1[i] = cub[0][i][rowcolumn_id];
			}
			for( i = 0; i < n; i++){
				temp2[i] = cub[5][i][rowcolumn_id];
			}
			for( i = 0; i < n; i++){
				temp3[i] = cub[2][i][n-rowcolumn_id-1];
			}
			for( i = 0; i < n; i++){
				temp4[i] = cub[4][i][rowcolumn_id];
			}
			
			for( i = 0; i < n; i++){
				cub[5][i][rowcolumn_id] = temp1[i];
			}
			for( i = 0; i < n; i++){
				cub[2][i][n-rowcolumn_id-1] = temp2[n-i-1];
			}
			for( i = 0; i < n; i++){
				cub[4][i][rowcolumn_id] = temp3[n-i-1];
			}
			for( i = 0; i < n; i++){
				cub[0][i][rowcolumn_id] = temp4[i];
			}
		}
		else if( face_id == 1 ){
			for( i = 0; i < n; i++){
				temp1[i] = cub[1][i][rowcolumn_id];
			}
			for( i = 0; i < n; i++){
				temp2[i] = cub[5][rowcolumn_id][i];
			}
			for( i = 0; i < n; i++){
				temp3[i] = cub[3][i][n-rowcolumn_id-1];
			}
			for( i = 0; i < n; i++){
				temp4[i] = cub[4][n-rowcolumn_id-1][i];
			}
			
			for( i = 0; i < n; i++){
				cub[5][rowcolumn_id][i] = temp1[n-i-1];
			}
			for( i = 0; i < n; i++){
				cub[3][i][n-rowcolumn_id-1] = temp2[i];
			}
			for( i = 0; i < n; i++){
				cub[4][n-rowcolumn_id-1][i] = temp3[n-i-1];
			}
			for( i = 0; i < n; i++){
				cub[1][i][rowcolumn_id] = temp4[i];
			}			
		}
		else if( face_id == 2 ){
			for( i = 0; i < n; i++){
				temp1[i] = cub[2][i][rowcolumn_id];
			}
			for( i = 0; i < n; i++){
				temp2[i] = cub[5][i][n-rowcolumn_id-1];
			}
			for( i = 0; i < n; i++){
				temp3[i] = cub[0][i][n-rowcolumn_id-1];
			}
			for( i = 0; i < n; i++){
				temp4[i] = cub[4][i][n-rowcolumn_id-1];
			}
			
			for( i = 0; i < n; i++){
				cub[5][i][n-rowcolumn_id-1] = temp1[n-i-1];
			}
			for( i = 0; i < n; i++){
				cub[0][i][n-rowcolumn_id-1] = temp2[i];
			}
			for( i = 0; i < n; i++){
				cub[4][i][n-rowcolumn_id-1] = temp3[i];
			}
			for( i = 0; i < n; i++){
				cub[2][i][rowcolumn_id] = temp4[n-i-1];
			}			
			
		}
		else if( face_id == 3 ){
			for( i = 0; i < n; i++){
				temp1[i] = cub[3][i][rowcolumn_id];
			}
			for( i = 0; i < n; i++){
				temp2[i] = cub[5][n-rowcolumn_id-1][i];
			}
			for( i = 0; i < n; i++){
				temp3[i] = cub[1][i][n-rowcolumn_id-1];
			}
			for( i = 0; i < n; i++){
				temp4[i] = cub[4][rowcolumn_id][i];
			}
			
			for( i = 0; i < n; i++){
				cub[5][n-rowcolumn_id-1][i] = temp1[i];
			}
			for( i = 0; i < n; i++){
				cub[1][i][n-rowcolumn_id-1] = temp2[n-i-1];
			}
			for( i = 0; i < n; i++){
				cub[4][rowcolumn_id][i] = temp3[i];
			}
			for( i = 0; i < n; i++){
				cub[3][i][rowcolumn_id] = temp4[n-i-1];
			}			
		}	
	return 0;
	}
}








