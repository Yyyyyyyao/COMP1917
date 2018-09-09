#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
	int year = 0;
	int a, b, c, d, e, f, g, h, i, k, l, m, month, p, date;	
	printf("Enter Year: ");
	scanf("%d", &year);
	if(year > 1583){
		a = year%19;
		b = year/100;
		c = year%100;
		d = b/4;
		e = b%4;
		f = (b + 8)/25;
		g = (b-f+1)/3;
		h = (19*a+b-d-g+15);
		i = c/4;
		k = c%4;
		l = (32+2*e+2*i-h-k)%7;
		m = (a+11*h+22*l)/451;
		month = (h+l-7*m+114)/31;
		p =(h+l-7*m+114)%31;
		date =p+1;
		printf("Easter Month = %d\n", month);
		printf("Easter Date = %d\n", date);
	} else{
		printf("the year is invaild\n");
	}
	return 0;

}
