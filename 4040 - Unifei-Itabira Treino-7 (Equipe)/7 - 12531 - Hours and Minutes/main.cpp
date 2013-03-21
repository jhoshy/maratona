// http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3976
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	
	int a;
	int i = -1, m, h, s;

	while (cin >> a){

		while(++i < 720) {
			m = i % 60; 
			h = i / 12;
			s = m - h;
			if (s < 0) s *= -1;
			if (s * 6 == a) {
				cout << "Y\n";
				break;
			} 
		}
		if (i == 720) cout << "N\n";
		
	}


	return 0;
}
