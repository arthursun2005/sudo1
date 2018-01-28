/*
This is all ways to calculate fibonacci numbers
*/
#include <iostream>
#include "math2.h"
using namespace std;
long long F1(int n){
	if(n == 1) return 1;
	if(n == 2) return 1;
	else return F1(n-1)+F1(n-2);
}
long long F2(int n){
	double t = sqrt(5);
	return (1/t)*(pow((1+t)/2,n)-pow((1-t)/2,n));
}
long long F3(int n){
	double t = (1+sqrt(5))/2;
	return round(pow(t,n)/sqrt(5));
}
int main(void)
{
	while(1){
		int d;
		cout << "Enter a number: ";
		cin >> d;
		long n = F2(d);
		cout << n << endl;
	}
	return 0;
}