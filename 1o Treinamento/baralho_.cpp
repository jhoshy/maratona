#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{	
	int n;
	cin >> n;
	
	int *b = new int [13];
	char c;
	
	int j = -1;
	while(++j < n) {
		int k = -1;
		while(++k < 13) {
			cin >> c;
			b[k] = (c == 'J' ? 11 : c == 'Q' ? 12 : c == 'K' ? 13 : c == 'A' ? 1 : c - '1');
		}
		
		k = 0;
		while(b[0] != 1) {
			++k;
			int l = b[0] - 1;
			int a = -1;
			while(++a < l/2) {
				int z = b[a];
				b[a] = b[l-a];
				b[l-a] = z;
			}
		}
		cout << k << "\n";
	
	}	
	return 0;
}
