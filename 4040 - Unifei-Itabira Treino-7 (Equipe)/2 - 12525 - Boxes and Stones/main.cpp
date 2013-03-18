// http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3970
#include <iostream>
#include <math.h>

//#include <cstdlib>
using namespace std;


void deb(int i, int s, int b, int n, int *p, int *m) {
	
	cout << "\nn: " << n << "\n";

	cout << "pedras:\n";
	i = -1; while(++i < b) cout << p[i] << " ";
	cout << "\n";
	i = -1; while(++i < b) cout << m[i] << " ";
	cout << "\n";
}

int main(int argc, char const *argv[])
{

	// input
	int s, b; // inputs
	cin >> s >> b;

	// init
	int n,
		*p, // pedras
		*m; // quantas pedras foram movidas.
	{
		n = 0;
		p = new int[b]; // ultima posicao comeca com todas as pedras.
		m = new int[b];
		int i = -1; while(++i < b) p[i] = m[i] = 0;
		p[b-1] = s;
	}

	{
		int i = b - 1; bool flag = true;
		while(i < b) {

			//cout << "\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
			//deb(i, s, b, n, p, m);

			int j = -1, k = 0;
			while(++j < b) {

				int l = pow(2, j - k < 0 ? 0 : j - k);
				int o = floor(p[j] / 2);

				//cout << "\nk: " << k << ", l: " << l << ", p[j]" << p[j];

				if (p[j] >= l ) break;
				else if (p[j] == l - 1 && p[j] > 0) k += o > 0 ? o : 1;
				else --k;
				k = k < 0 ? 0 : k;

				//cout << "\tk: " << k << ", l: " << l << ", p[j]" << p[j];
			}
			if(j != b) flag = false;


			if (p[i] >= pow(2, i)) {
				//cout << "\nBUM! entrou na volta.\n";
				while( (p[i+1] += p[i]) <= m[i+1]) p[i] = m[i++] = 0;
				p[i] = m[i++] = 0;
				
				flag = false;

				//deb(i, s, b, n, p, m);


				continue;
			}

			if (flag) {
				++n; 
				deb(i, s, b, n, p, m);
			} else flag = true;


			p[i] -= ++m[i];
			p[--i] += m[i + 1];

			//cout << "\nfinal.\n";
			//deb(i, s, b, n, p, m);
			//system("pause");
			//cout << "\n" << n;
		}
		cout << "\nsaiu do loop\n\n";
	}

	cout << n;
	return 0;
}
