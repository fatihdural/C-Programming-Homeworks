#include <stdio.h>
int main(){
	double a[2][2];
	double *temp;
	
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;
	a[1][1] = 4;
	temp = &a[0][0]; 
	printf("%lf", temp[2]);
	
	return 0;
}
