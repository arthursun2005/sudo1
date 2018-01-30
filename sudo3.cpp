#include <iostream>
#include "Sudoku.h"
using namespace std;
int grid[81] = {};
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
	cout << endl << "We start from an empty grid" << endl;
	cout << "(enter -1 to break off)" << endl;
	for(int i=0;i<81;++i){
		int x = (i%9)+1, y = floor(i/9)+1;
		int n;
		cout << "Enter the number at coordinates " << x << "x and " << y << "y number: ";
		cin >> n;
		if(n == -1){
			break;
		}
		grid[i] = n;
	}
	Sudoku s1(grid);
	print(s1);
	if(!s1.check()){
		cout << "Error in the Sudoku" << endl;
		return 0;
	}
	int t = s1.solve();
	print(s1);
	if(t){
		cout << "DONE!" << endl;
	}else{
		cout << "FAIL!" << endl;
	}
	return 0;
}