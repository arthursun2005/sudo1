#include <math.h>
#define π atan(1)*4
#define g1 (1+sqrt(5))/2
#define g2 (1-sqrt(5))/2
int isInt(double n){
	if(round(n)!=n){return false;}
	else{return true;}
}
int isPrime(double n){
	int hit = 0;
	if(!isInt(n)||n<2){return false;}
	for(int i=2;i<=sqrt(n);++i){
		if(isInt(n/i)){++hit;}
	}
	if(hit<=0){return true;}else{return false;}
}
double cc(double a, double b, bool c){
	if(c){return a*b+a+b;}
	else{return a*b-a-b;}
}
double calculateDistance(double v, double a, double g){
	return (2*v*v*cos(a)*sin(a))/g;
}
int isPerfect(double n){
	int fac = 0;
	if(!isInt(n)||n<=0){return false;}
	for(int i=1;i<=n/2;++i){
		if(isInt(n/i)){
			fac+=i;
		}
	}
	if((fac-1) == n){return true;}
	else{return false;}
}
double two(double n){
	return pow(2,n);
}
double dist(double x1, double y1, double x2, double y2){
	double d = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	return d;
}
double mag(double x, double y){
	return sqrt(pow(x,2)+pow(y,2));
}
double constrain(double x, double a, double b){
	if(x<a) return a;
	else if(x>b) return b;
	else return x;
}