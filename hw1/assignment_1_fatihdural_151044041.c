#include <stdio.h>
int main(){
	double x, y, a, b, marked_x, marked_y, kesis_x, kesis_y, detect_x, detect_y; /* deðiþkenler tanýmlanýr. */
	int attempts = 5; /*  attempts remaining 5 olarak tanýmlandý, deðiþtirilebilir. */
	a = kesis_x; b = kesis_y;
	marked_x = 10; marked_y = 10; detect_x = 6; detect_y = 6; kesis_x = 4; kesis_y = 4;
	/* marked_x ve marked_y marked region'ýn merkez noktasýnýn koordinatlarý. */
	/* kesis_x ve kesis_y marked region'ýn x ve y deki uzunluklarý. (Þu haliyle [4 x 4] büyüklüðünde bir marked region.) */
	/* detect_x ve detect_y dedektörün x ve y deki uzunluklarý. (Þu haliyle [6 x 6] büyüklüðünde bir dedektör.) */
	printf("Board = [20 x 20], marked region = [%1.0lf x %1.0lf], Detector = [%1.0lf x %1.0lf] \n", marked_x, marked_y, detect_x, detect_y);
	while(1){
		printf("Enter the x coordinate of the move: "); /* dedektörün merkez noktasýnýn x koordinatýný gir. */
		scanf("%lf", &x); 
		printf("Enter the y coordinate of the move: "); /* dedektörün merkez noktasýnýn y koordinatýný gir. */
		scanf("%lf", &y);
		if(x > 20 || y > 20 ){
			printf("Error, move is not valid. Try again. Attempts remaining: %d\n", attempts); /* dedektör alanýn dýþýna çýkarsa hata verir ancak attempts remaining azalmaz. */
			continue;
		}
		else
		{	/* dedektörün marked regionýn hangi tarafýnda kaldýðýyla alakalý bir algoritma tasarlandý. */
		if( x < marked_x ){	/* a ve b yeni marked regionýn x ve y deki uzunluklarý. */
			a = (x + (detect_x/2)) - (marked_x - (a/2)); /* eski deðeri kaybetmemek için a ve b deðiþmeden deðerlerini kesis_x ve kesis_y ye atýlýr. */
			if(a > 0){	/* vurulan bölgeye göre yeni marked region oluþturulur. */
			marked_x = (marked_x - (kesis_x/2 - ((x + (detect_x/2)) - (marked_x - kesis_x/2)) / 2 ));
			}
		}
		if( y < marked_y ){
			b = (y + (detect_y/2)) - (marked_y - (b/2));
			if(b > 0){
				marked_y = (marked_y - (kesis_y/2 - ((y + (detect_y/2)) - (marked_y - kesis_y/2)) / 2 ));
			}
		}																			
		if( x > marked_x ){
			a = (marked_x + (a/2)) - (x - (detect_x/2));
			if(a > 0 ){
			marked_x = (marked_x + (kesis_x/2 - ((marked_x + kesis_x/2) - (x - (detect_x/2))) / 2 ));
			}
		}
		if( y > marked_y ){
			b = (marked_y + (b/2)) - (y - (detect_y/2));
			if(b > 0){	
			marked_y = (marked_y + (kesis_y/2 - ((marked_y + kesis_y/2) - (y - (detect_y/2))) / 2 ));
			}
		}
		if( a >= kesis_x && b >= kesis_y){
			printf("Bravo! You hit the target.");	/* eðer hedefin tamamý vurulduysa oyun sonlanýr. */
			break;
		}
		if (a < 0 || b < 0){
			attempts--;	
			printf("You missed the target, attempts remaining: %d \n", attempts); /* hiçbir alan vurulamazsa can düþer ve yeni koordinatlar istenir. */
			a = kesis_x; b = kesis_y;
			continue;
		}
		kesis_x = a; kesis_y = b;
		}
		attempts--;
		if(attempts <1) break; /* attempts remaining(can) kalmadýðýnda oyun sonlanýr. */
		printf("Partial hit! marked region was shirked to [%2.2lf x %2.2lf], detector was shirked to [%2.2lf x %2.2lf] attempts remaining: %d \n", a, b, detect_x/2, detect_y/2, attempts);
		printf("And the x coordinate of center of marked region is '%2.2lf'. The y coordinate of center of marked region is '%2.2lf'. \n", marked_x,marked_y);
		detect_x = detect_x / 2; detect_y = detect_y / 2; /* hedef her vurulduðunda dedektörün boyutu yarýya iner. */ 
	}
	return 0;
}
