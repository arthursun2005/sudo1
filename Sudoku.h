#include "math2.h"
class Sudoku
{
public:
	Sudoku(int c[]);
	~Sudoku();
	int cells[81];
	int get(int x, int y);
	void change(int x, int y, int n);
	int done();
	int check();
	void solve();
private:
};
Sudoku::Sudoku(int c[]){for(int i=0;i<81;++i){cells[i] = c[i];}}
Sudoku::~Sudoku(){}
int Sudoku::get(int x, int y){return cells[x+y*9];}
void Sudoku::change(int x, int y, int n){cells[x+y*9] = n;}
int Sudoku::check(){
	for(int x=0;x<9;++x){
		int h1[9] = {0,0,0,0,0,0,0,0,0};
		for(int y=0;y<9;++y){
			int n = get(x,y);
			if(n==0) continue;
			if(h1[n-1]!=0){return false;}
			h1[n-1] = n;
		}
	}
	for(int y=0;y<9;++y){
		int h1[9] = {0,0,0,0,0,0,0,0,0};
		for(int x=0;x<9;++x){
			int n = get(x,y);
			if(n==0) continue;
			if(h1[n-1]!=0){return false;}
			if(n!=0){h1[n-1] = n;}
		}
	}
	for(int nb=1;nb<=9;++nb){
		int h1[9] = {0,0,0,0,0,0,0,0,0};
		int nx = (nb-1)%3+1, ny = floor((nb-1)/3)+1;
		for(int x=1;x<=3;++x){
			for(int y=1;y<=3;++y){
				int n = get((nx-1)*3+x,(ny-1)*3+y);
				if(n==0) continue;
				if(h1[n-1]!=0){return false;}
				h1[n-1] = n;
			}
		}
	}
	return true;
}
int Sudoku::done(){
	check();
	for(int x=0;x<9;++x){
		for(int y=0;y<9;++y){
			if(get(x,y) == 0){return false;}
		}
	}
	return true;
}
void Sudoku::solve(){
	for(int x=1)
}