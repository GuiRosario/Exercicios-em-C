#include <stdio.h>
#include <math.h>


int main(){

	float distancia(float x1,float y1,float x2,float y2);

	float x1;
	float y1;
	float x2;
	float y2;
	float res;

	scanf("%f",&x1);
	scanf("%f",&y1);
	scanf("%f",&x2);
	scanf("%f",&y2);

	res = distancia(x1,y1,x2,y2);

	printf("%f",res);

	return 0;
}

float distancia(float x1,float y1,float x2,float y2){

	float dis;
	float dx;
	float dy;

	dx = x1 - x2;
	dy = y1 - y2;	

	dis = sqrt((dx*dx) + (dy*dy));

	return dis;
}