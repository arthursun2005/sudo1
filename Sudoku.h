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
Sudoku::Sudoku(int c[]){
	for(int i=0;i<81;++i){
		cells[i] = c[i];
	}
}
Sudoku::~Sudoku(){
	//delete [] cells;
}
int Sudoku::get(int x, int y){
	return cells[x+y*9];
}
void Sudoku::change(int x, int y, int n){
	cells[x+y*9] = n;
}
int Sudoku::check(){
	int h1[9] = {0,0,0,0,0,0,0,0,0};
	for(int x=0;x<9;++x){
		for(int y=0;y<9;++y){
		}
	}
}
int Sudoku::done(){
	for(int x=0;x<9;++x){
		for(int y=0;y<9;++y){
			if(get(x,y) == 0){
				return false;
			}
		}
	}
	return true;
}