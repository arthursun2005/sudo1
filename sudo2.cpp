#include <iostream>
#include "sudos.h"
#include "Sudoku.h"
using namespace std;
void print(Sudoku s){
	cout << endl << endl;
	for(int y=0;y<9;++y){
		cout << "|";
		for(int x=0;x<9;++x){
			int n = s.get(x,y);
			if(n!=0){
				cout << s.get(x,y);
			}else{
				cout << " ";
			}
			cout << "|";
		}
		cout << endl;
	}
	cout << endl << endl;
}
int main(int argc, char const *argv[])
{
	Sudoku s1(sudo1);
	print(s1);
	if(!s1.check()){
		cout << "Error in the Sudoku" << endl;
		return 0;
	}
	if(!s1.done()) s1.solve();
	print(s1);
	return 0;
}