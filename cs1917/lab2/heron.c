#include <stdio.h>
#include <math.h>
int main(int argc, char * argv[]) {

	double a = 0;
	double b = 0;
	double c = 0;
	printf("Enter sidelengths of a triangle:\n");
	scanf("%lf %lf %lf", &a, &b, &c);
	if(a + b >= c){
		double s = (a + b + c)/2;
		double  area = sqrt(s * (s - a) * (s - b) * (s - c));
		printf("Area =  %.2lf\n", area);
	} else {
		printf("the numbes are invaild\n");
	}
	return 0;



}
