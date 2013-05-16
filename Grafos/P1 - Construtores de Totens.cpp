#include <iostream>
using namespace std;
 
int main(int argc, char const *argv[])
{
	int k = 0;

	while(!cin.eof()) {
		int n, m;
		cin >> n >> m;

		if (cin.eof()) return 0;

		bool 
			*t = new bool[n * n], // toten
			*s = new bool[m * m]; // signature
		
		// monta toten
		int i = -1;
		while(++i < n * n) {
			char c;
			cin >> c;
			t[i] = c == '|'; // _ = 0; | = 1;
		} 

		// monta assinatura
		i = -1;
		while(++i < m * m) {
			char c;
			cin >> c;
			s[i] = c == '|'; // _ = 0; | = 1;
		}

		cout << "Instancia " << ++k << "\n";

		int j = i = -1;
		while(++i < n) { // i é pra coluna
			j = -1;
			while(++j < n) { // j pra linha
				int a = -1;
				while(t[j * n + i + ++a / m + (a % m) * n] == s[a / m + (a % m) * m]);
				if(a == m * m) cout << j << " " << i << "\n";
					
			}
		}


		delete [] t;
		delete [] s; 
	}


	return 0;
}