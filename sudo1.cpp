#include "math2.h"
#include <iostream>
using namespace std;
int sudo1[81] = {
	0,0,0,0,0,0,0,8,0,
	6,8,0,4,7,0,0,2,0,
	0,1,9,5,0,8,6,4,7,
	0,6,0,9,0,0,0,0,4,
	3,4,2,6,8,0,0,0,0,
	1,9,0,0,5,0,8,3,0,
	0,0,0,7,2,0,4,0,3,
	0,0,6,0,0,5,0,1,0,
	0,0,3,8,9,1,5,0,0
};
int sudo2[81] = {
	0,0,0,0,0,0,0,0,2,
	0,1,0,5,0,6,8,0,0,
	0,7,3,0,0,0,1,6,0,
	0,0,9,4,0,0,0,0,8,
	0,0,0,0,0,5,3,2,0,
	7,0,0,8,0,0,0,5,1,
	0,0,1,7,2,0,0,0,0,
	5,8,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,4
};
int* sudo = sudo2;
int get(int x,int y){
	return sudo[(y-1)*9+x-1];
}
void change(int x,int y,int n){
	sudo[(y-1)*9+x-1] = n;
}
void printGrid(){
	cout << endl << endl;
	for(int y=1;y<=9;++y){
		cout << "|";
		for(int x=1;x<=9;++x){
			int n = get(x,y);
			if(n!=0){
				cout << get(x,y);
			}else{
				cout << " ";
			}
			cout << "|";
		}
		cout << endl;
	}
	cout << endl << endl;
}
void getNumbers(){
	cout << endl << "This is the grid currrently: " << endl;
	printGrid();
	int x, y, n;
	cout << "type in the x and y cordinate of the grid you want to change: (0 for blank)" << endl;
	cout << "the x-number: ";
	cin >> x;
	cout << "the y-number: ";
	cin >> y;
	int dn = false;
	while(!dn){
		cout << "the number that it will be: ";
		if(!(cin >> n)){
			cout << "Type a number :(" << endl;
			cin.clear();
      		cin.ignore(10000,'\n');
		}else if(n<0){
			cout << "Type a positve number" << endl;
			dn = false;
		}else{
			dn = true;
		}
	}
	change(x,y,n);
	printGrid();
	cout << "all done" << endl;
}
int checkErrors(){
	int hit = 0;
	for(int x=1;x<=9;++x){
		int h1[9] = {0,0,0,0,0,0,0,0,0};
		for(int y=1;y<=9;++y){
			int n = get(x,y);
			if(n!=0){
				if(h1[n-1]!=0){
					cout << endl << "ERROR FOUND" << endl;
					cout << "On column " << x << ", the number " << n << " was repeated" << endl << endl;
					++hit;
				}
				h1[n-1] = n;
			}
		}
	}
	for(int y=1;y<=9;++y){
		int h1[9] = {0,0,0,0,0,0,0,0,0};
		for(int x=1;x<=9;++x){
			int n = get(x,y);
			if(n!=0){
				if(h1[n-1]!=0){
					cout << "ERROR FOUND" << endl;
					cout << "On row " << y << ", the number " << n << " was repeated" << endl << endl;
					++hit;
				}
				h1[n-1] = n;
			}
		}
	}
	for(int nb=1;nb<=9;++nb){
		int h1[9] = {0,0,0,0,0,0,0,0,0};
		int nx = (nb-1)%3+1, ny = floor((nb-1)/3)+1;
		for(int x=1;x<=3;++x){
			for(int y=1;y<=3;++y){
				int n = get((nx-1)*3+x,(ny-1)*3+y);
				if(n!=0){
					if(h1[n-1]!=0){
						cout << "ERROR FOUND" << endl;
						cout << "On box " << nb << ", the number " << n << " was repeated" << endl << endl;
						++hit;
					}
					h1[n-1] = n;
				}
			}
		}
	}
	return hit;
}
int done(){
	for(int x=1;x<=9;++x){
		for(int y=1;y<=9;++y){
			if(get(x,y)==0){
				return false;
			}
		}
	}
	return true;
}
void solve(){
	for(int x=1;x<=9;++x){
		int h1[9] = {0,0,0,0,0,0,0,0,0};
		for(int sy=1;sy<=9;++sy){
			h1[get(x,sy)-1] = get(x,sy);
		}
		for(int i=0;i<sizeof(h1);++i){
			if(h1[i]!=0){continue;}
			int h2[9] = {0,0,0,0,0,0,0,0,0};
			int total = 0;
			int cy;
			for (int y=1;y<=9;++y){
				if(get(x,y)!=0){continue;}
				int n = i+1;
				if(n>9) continue;
				// detection of x-axis
				int hitx = 0;
				for(int x2=1;x2<=9;++x2){
					if(get(x2,y)==n){
						++hitx;
					}
				}
				// detection for the box
				int hitb = 0;
				int bx = floor((x-1)/3)+1, by = floor((y-1)/3)+1;
				for(int dx=1;dx<=3;++dx){
					for(int dy=1;dy<=3;++dy){
						int n2 = get(bx*3+dx-3,by*3+dy-3);
						if(n2==n){
							++hitb;
						}
					}
				}
				// last bit
				if(hitx<=0 && hitb<=0){
					cy = y;
					++total;
				}
			}
			if(total == 1){
				change(x,cy,i+1);
			}
		}
	}
	for(int y=1;y<=9;++y){
		int h1[9] = {0,0,0,0,0,0,0,0,0};
		for(int sx=1;sx<=9;++sx){
			h1[get(sx,y)-1] = get(sx,y);
		}
		for(int i=0;i<sizeof(h1);++i){
			if(h1[i]!=0){continue;}
			int h2[9] = {0,0,0,0,0,0,0,0,0};
			int total = 0;
			int cx;
			for (int x=1;x<=9;++x){
				if(get(x,y)!=0){continue;}
				int n = i+1;
				if(n>9) continue;
				// detection of y-axis
				int hity = 0;
				for(int y2=1;y2<=9;++y2){
					if(get(x,y2)==n){
						++hity;
					}
				}
				// detection for the box
				int hitb = 0;
				int bx = floor((x-1)/3)+1, by = floor((y-1)/3)+1;
				for(int dx=1;dx<=3;++dx){
					for(int dy=1;dy<=3;++dy){
						int n2 = get(bx*3+dx-3,by*3+dy-3);
						if(n2==n){
							++hitb;
						}
					}
				}
				// last bit
				if(hity<=0 && hitb<=0){
					cx = x;
					++total;
				}
			}
			if(total == 1){
				change(cx,y,i+1);
			}
		}
	}
	for(int nb=1;nb<=9;++nb){
		int nx = (nb-1)%3+1, ny = floor((nb-1)/3)+1;
		int h1[9] = {0,0,0,0,0,0,0,0,0};
		for(int x=1;x<=3;++x){
			for(int y=1;y<=3;++y){
				int n = get((nx-1)*3+x,(ny-1)*3+y);
				h1[n-1] = n;
			}
		}
		for(int i=0;i<sizeof(h1);++i){
			if(h1[i]!=0){continue;}
			int h2[9] = {0,0,0,0,0,0,0,0,0};
			int total = 0;
			int cx, cy;
			for(int px=1;px<=3;++px){
				for(int py=1;py<=3;++py){
					int x = (nx-1)*3+px;
					int y = (ny-1)*3+py;
					if(get(x,y)!=0){continue;}
					int n = i+1;
					int hit = 0;
					if(n>9) continue;
					for(int x2=1;x2<=9;++x2){
						if(get(x2,y)==n){
							++hit;
						}
					}
					for(int y2=1;y2<=9;++y2){
						if(get(x,y2)==n){
							++hit;
						}
					}
					if(hit<=0){
						++total;
						cx = x;
						cy = y;
					}
				}
			}
			if(total == 1){
				change(cx,cy,i+1);
			}
		}
	}
}
int main(void){
	cout << endl << "This is the grid" << endl;
	printGrid();
	int t1 = true;
	do
	{
		cout << "Want any more changes? ";
		cin >> t1;
		if(t1){
			getNumbers();
		}
	} while (t1);
	while(checkErrors()>0){
		cout << "You will have to change the grid" << endl;
		getNumbers();
	}
	for(int i=0;i<81*9;++i){solve();}
	if(!done()){
		cout << "There is an error..." << endl;
	}
	printGrid();
	return 0;
}
