#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct a{
	int inp1;
	int inp2;
	int out;
	char input1[10];
	char input2[10];
	char output[10];
}AND;

typedef struct o{
	int inp1;
	int inp2;
	int out;
	char input1[10];
	char input2[10];
	char output[10];
}OR;

typedef struct n{
	char input1[10];
	char output[10];
	int inp1;
	int out;
}NOT;

typedef struct f{
	int inp1;
	int out;	
	char output[10];
	char input1[10];

}FLIPFLOP;

typedef struct i{
	int inp;	
	char input[10];
}INPUT;

typedef struct boolean{
	int INPUT;
	int AND;
	int OR;
	int NOT;
	int FLIPFLOP;
}identifier_c;
int count_identifier(int id_counter , identifier_c *x);
int count_input(int count);

int main(){
	int id_counter = 0, point = 0, count = 0, start = 0, finish, i = 0;
	int input_c = 0, and_c = 0 , or_c = 0 , not_c = 0 , flipflop_c = 0;
	char tempstr[10], tempc, temp[10];
	identifier_c x;
    count_identifier(id_counter , &x);
	
	FILE *fp2 = fopen("input.txt" , "r");
	AND *and1 = calloc(x.AND , sizeof(AND));
	OR *or1 = calloc(x.OR , sizeof(OR));
	NOT *not1 = calloc(x.NOT , sizeof(NOT));
	FLIPFLOP *flipflop1 = calloc(x.FLIPFLOP , sizeof(FLIPFLOP));
	INPUT *input1 = calloc(x.INPUT , sizeof(INPUT));

	while( point < x.FLIPFLOP ){
		flipflop1[point].out = 0;
		point++;
	}
	flipflop1[flipflop_c].out = 0;
	finish = count_input(count);

	while( start < finish ){
		i = 0;
		point = 0;
		and_c = 0;
		or_c = 0;
		not_c = 0;
		flipflop_c = 0;
		input_c = 0;
		FILE *fp1 = fopen("circuit.txt" , "r");
	
		while( x.INPUT > i ){
			fscanf(fp2,"%d", &input1[i].inp);
			i++;
		}
		i = 0;
		while(1){
			fscanf(fp1,"%s",tempstr);
			tempc = fgetc(fp1);
			if(tempc == EOF){
				break;
			}
			else{
				if( !strcmp(tempstr, "INPUT") ){
					while(i < x.INPUT ){
						fscanf(fp1, "%s", input1[i].input);
						tempc = fgetc(fp1);
						if(tempc == EOF){
							break;
						}
						i++;
					}
					i = 0;
				}
				else if( !strcmp(tempstr,"AND") ){
					fscanf(fp1,"%s",tempstr);
					strcpy(and1[and_c].output,tempstr);
					tempc = fgetc(fp1);
					fscanf(fp1,"%s",tempstr);
					strcpy(and1[and_c].input1,tempstr);
					point = 0;
					i = 0;
					while(i < x.INPUT){
						if( !strcmp(input1[i].input, tempstr ) ){
							and1[and_c].inp1 = input1[i].inp;
							point++;
						}
						i++;
					}				
					if( point == 0 ){
						i = 0;
						while( ( i < and_c ) && ( point == 0 ) ){
							if( !strcmp(and1[i].output, tempstr ) ){
								and1[and_c].inp1 = and1[i].out;
								point++;
							}
							i++;
						}
					}
					if( point == 0 ){
						i = 0;
						while( ( i < or_c ) && ( point == 0 ) ){
							if( !strcmp(or1[i].output, tempstr ) ){
								and1[and_c].inp1 = or1[i].out;
								point++;
							}
							i++;
						}
					}
					if( point == 0 ){
						i = 0;
						while( ( i < not_c ) && ( point == 0 ) ){
							if( !strcmp(not1[i].output, tempstr ) ){
								and1[and_c].inp1 = not1[i].out;
								point++;
							}
							i++;
						}
					}
					if( point == 0 ){
						i = 0;
						while( ( i < flipflop_c ) && ( point == 0 ) ){
							if( !strcmp(flipflop1[i].output, tempstr ) ){
								and1[and_c].inp1 = flipflop1[i].out;
								point++;
							}
							i++;
						}
					}
					tempc = fgetc(fp1);
					
					fscanf(fp1,"%s", tempstr);
					strcpy(and1[and_c].input2, tempstr);
					i = 0;
					point = 0;
					while(i < x.INPUT ){
						if( !strcmp(input1[i].input, tempstr ) ){
							and1[and_c].inp2 = input1[i].inp;
							point++;
						}
					i++;
					}				
					if( point == 0 ){
						i = 0;
						while( ( i < and_c ) && ( point == 0 ) ){
							if( !strcmp(and1[i].output, tempstr ) ){
								and1[and_c].inp2 = and1[i].out;
								point++;
							}
							i++;
						}
					}
					if( point == 0 ){
						i = 0;
						while( ( i < or_c ) && ( point == 0 ) ){
							if( !strcmp(or1[i].output, tempstr ) ){
								and1[and_c].inp2 = or1[i].out;
								point++;
							}
							i++;
						}
					}
					if(point == 0){
						i = 0;
						while( ( i < not_c ) && ( point == 0 ) ){
							if( !strcmp(not1[i].output,tempstr) ){
								and1[and_c].inp2 = not1[i].out;
								point++;
							}
							i++;
						}
					}
					if(point == 0){
						i = 0;
						while( ( i < flipflop_c ) && ( point == 0 ) ){
							if( !strcmp(flipflop1[i].output, tempstr ) ){
								and1[and_c].inp2 = flipflop1[i].out;
								point++;
							}
							i++;
						}
					}
					tempc = fgetc(fp1);
					and1[and_c].out = and1[and_c].inp1 * and1[and_c].inp2;
					and_c++;
					if(tempc == EOF){
						printf("%d\n",and1[and_c-1].out);
						break;
					}
				}	
				else if( !strcmp(tempstr, "OR" ) ){
					fscanf(fp1, "%s", tempstr);
					strcpy(or1[or_c].output, tempstr);
					tempc = fgetc(fp1);	
					fscanf(fp1,"%s", tempstr);
					strcpy(or1[or_c].input1, tempstr);
					point = 0;
					i = 0;
					while( i < x.INPUT ){
						if( !strcmp(input1[i].input, tempstr ) ){
							or1[or_c].inp1 = input1[i].inp;
							point++;
						}
						i++;
					}				
					if(point == 0){
						i = 0;
						while( ( i < and_c ) && ( point == 0 ) ){
							if( !strcmp(and1[i].output, tempstr ) ){
								or1[or_c].inp1 = and1[i].out;
								point++;
							}
							i++;
						}
					}
					if(point == 0){
						i = 0;
						while( ( i < or_c ) && ( point == 0 ) ){
							if( !strcmp(or1[i].output, tempstr ) ){
								or1[or_c].inp1 = or1[i].out;
								point++;
							}
							i++;
						}
					}
					if( point == 0 ){
						i = 0;
						while( ( i < not_c ) && ( point == 0 ) ){
							if( !strcmp(not1[i].output, tempstr ) ){
								or1[or_c].inp1 = not1[i].out;
								point++;
							}
							i++;
						}
					}
					if( point == 0 ){
						i = 0;
						while( ( i < flipflop_c ) && ( point == 0 ) ){
							if( !strcmp(flipflop1[i].output, tempstr ) ){
								or1[or_c].inp1 = flipflop1[i].out;
								point++;
							}
							i++;
						}
					}
					tempc = fgetc(fp1);
					fscanf(fp1, "%s", tempstr);
					strcpy(or1[or_c].input2, tempstr);
					i = 0;
					point = 0;
					while( i < x.INPUT ){
						if( !strcmp(input1[i].input,tempstr) ){
							or1[or_c].inp2 = input1[i].inp;
							point++;
						}
						i++;
					}				
					if( point == 0 ){
						i = 0;
						while( ( i < and_c ) && ( point == 0 ) ){
							if( !strcmp(and1[i].output, tempstr ) ){
								or1[or_c].inp2 = and1[i].out;
								point++;
							}
							i++;
						}
					}
					if( point == 0 ){
						i = 0;
						while( ( i < or_c ) && ( point == 0 ) ){
							if( !strcmp(or1[i].output, tempstr ) ){
								or1[or_c].inp2 = or1[i].out;
								point++;
							}
							i++;
						}
					}
					if( point == 0){
						i = 0;
						while( ( i < not_c ) && ( point == 0 ) ){
							if( !strcmp(not1[i].output, tempstr ) ){
								or1[or_c].inp2 = not1[i].out;
								point++;
							}
							i++;
						}
					}
					if( point == 0){
						i = 0;
						while( ( i < flipflop_c ) && ( point == 0 ) ){
							if( !strcmp(flipflop1[i].output, tempstr ) ){
								or1[or_c].inp2 = flipflop1[i].out;
								point++;
							}
							i++;
						}
					}
					tempc = fgetc(fp1);
					point = or1[or_c].inp1 + or1[or_c].inp2;
					if( point > 0 ){
						or1[or_c].out = 1;
					}
					else{
						or1[or_c].out = 0;
					}
					or_c++;
						if( tempc == EOF ){
						printf("%d\n", or1[or_c-1].out);
						break;
					}
				}
				else if( !strcmp(tempstr, "NOT") ){
					fscanf(fp1, "%s", tempstr);
					strcpy(not1[not_c].output, tempstr);
					tempc = fgetc(fp1);
					fscanf(fp1, "%s", tempstr);
					strcpy(not1[not_c].input1, tempstr);
					point = 0;
					i = 0;
					while( i < x.INPUT ){
						if( !strcmp(input1[i].input, tempstr) ){
							not1[not_c].inp1 = input1[i].inp;
							point++;
						}
						i++;
					}				
					if( point == 0 ){
						i = 0;
						while( ( i < and_c ) && ( point == 0 ) ){
							if( !strcmp(and1[i].output, tempstr) ){
								not1[not_c].inp1 = and1[i].out;
								point++;
							}
							i++;
						}
					}
					if( point == 0 ){
						i = 0;
						while( ( i < or_c ) && ( point == 0 ) ){
							if( !strcmp(or1[i].output,tempstr) ){
								not1[not_c].inp1 = or1[i].out;
								point++;
							}
							i++;
						}
					}
					if( point == 0 ){
						i = 0;
						while( ( i < not_c ) && ( point == 0 ) ){
							if( !strcmp(not1[i].output, tempstr) ){
								not1[not_c].inp1 = not1[i].out;
								point++;
							}
							i++;
						}
					}
					if( point == 0 ){
						i = 0;
						while( ( i < flipflop_c ) && ( point == 0 ) ){
							if( !strcmp(flipflop1[i].output,tempstr) ){
								not1[not_c].inp1 = flipflop1[i].out;
								point++;
							}
							i++;
						}
					}
					tempc = fgetc(fp1);
					if(not1[not_c].inp1 == 1){
						not1[not_c].out = 0;
					}
					else{
						not1[not_c].out = 1;
					}
					not_c++;
					if(tempc == EOF){
						printf("%d\n", not1[not_c-1].out);
						break;
					}
				}
			
				else if( !strcmp(tempstr, "FLIPFLOP") ){
					fscanf(fp1, "%s", tempstr);
					strcpy(flipflop1[flipflop_c].output, tempstr);
					tempc = fgetc(fp1);
					fscanf(fp1, "%s", tempstr);
					strcpy(flipflop1[flipflop_c].input1, tempstr);
					point = 0;
					i = 0;
					while( i < x.INPUT ){
						if( !strcmp(input1[i].input, tempstr) ){
							flipflop1[flipflop_c].inp1 = input1[i].inp;
							point++;
						}
						i++;
					}				
					if( point == 0 ){
						i = 0;
						while( ( i < and_c ) && ( point == 0)  ){
							if( !strcmp(and1[i].output, tempstr ) ){
								flipflop1[flipflop_c].inp1 = and1[i].out;
								point++;
							}
							i++;
						}
					}
					if( point == 0 ){
						i = 0;
						while( ( i < or_c ) && ( point == 0 ) ){
								if( !strcmp( or1[i].output, tempstr ) ){
									flipflop1[flipflop_c].inp1 = or1[i].out;
									point++;
								}
							i++;
						}
					}
					if( point == 0 ){
						i = 0;
						while((i < not_c) && (point == 0)){
							if(!strcmp(not1[i].output,tempstr)){
								flipflop1[flipflop_c].inp1 = not1[i].out;
								point++;
							}
							i++;
						}
					}
					if( point == 0 ){
						i = 0;
						while((i < flipflop_c) && (point == 0)){
							if(!strcmp(flipflop1[i].output,tempstr)){
								flipflop1[flipflop_c].inp1 = flipflop1[i].out;
								point++;
							}
							i++;
						}
					}
					tempc = fgetc(fp1);
					if(flipflop1[flipflop_c].inp1 == 0 && flipflop1[flipflop_c].out == 0)	{
						flipflop1[flipflop_c].out = 0;
					}
					else if( flipflop1[flipflop_c].inp1 == 1 && flipflop1[flipflop_c].out == 1 ){
						flipflop1[flipflop_c].out = 0;
					}
					else{
						flipflop1[flipflop_c].out = 1;
					}

					flipflop_c++;
					if(tempc == EOF){
						printf("%d\n", flipflop1[flipflop_c-1].out);
						break;
					}
				}
		}
	}
		fclose(fp1);
		start++;
	}
	fclose(fp2);
	free(and1); free(or1); free(flipflop1); free(not1); free(input1);
}
int count_input(int count){
	FILE *fp = fopen("input.txt", "r");
	char temp;
	while(1){
		temp = fgetc(fp);
		if(temp == '\n')	count++;
		else if( temp == EOF){
			count++;
			break;
		}
	}
	return count;
}
int count_identifier(int count,identifier_c *x){
	FILE *fp = fopen("circuit.txt", "r");
	char tempstr[10], tempc;
	x->INPUT = 0;
	x->AND = 0;
	x->FLIPFLOP = 0;
	x->NOT = 0;
	x->OR = 0;
	while(1){
		fscanf(fp, "%s", tempstr);
		if( !strcmp(tempstr, "INPUT") ){
			do{
				tempc = fgetc(fp);
				if(tempc == EOF){
					break;
				}
				else if(tempc == '\n'){
					break;

				}
				else if(tempc == ' '){
					count++;
					x->INPUT++;
				}
			}while(1);
			
		}
		else if( !strcmp(tempstr,"AND") ){
			count++;
			x->AND++;
			do{
				tempc = fgetc(fp);
				if(tempc == EOF){
					break;
				}	
				else if(tempc == '\n'){
					break;
				}	
			}while(1);	
		}
		else if( !strcmp(tempstr, "OR") ){
			count++;
			x->OR++;
			do{
				tempc = fgetc(fp);
				if(tempc == EOF){
					break;
				}	
				else if(tempc == '\n'){
					break;
				}	
			}while(1);
		}
		else if( !strcmp(tempstr,"NOT") ){
			count++;
			x->NOT++;
			do{
				tempc = fgetc(fp);
				if(tempc == EOF){
					break;
				}	
				else if(tempc == '\n'){
					break;
				}	
			}while(1);
		}
		else if( !strcmp(tempstr, "FLIPFLOP") ){
			count++;
			x->FLIPFLOP++;
			do{
				tempc = fgetc(fp);
				if(tempc == EOF){
					break;
				}	
				else if(tempc == '\n'){
						break;
				}
			}while(1);
		}
		if(tempc == EOF){
			break;
		}	
	}
	fclose(fp);
	return count;
}
