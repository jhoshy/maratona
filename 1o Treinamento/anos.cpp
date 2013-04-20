#include <iostream>
using namespace std;

inline bool compara(int num[], int n_casas)
{
	if(n_casas == 1) return true;
	
	for(int i = 3; i > 4 - (n_casas); i--)
		for(int j = (i - 1); j >= (4 - n_casas); j--)
			if(num[i] == num[j])
				return false;
	return true;
}

int main(void)
{
	int n_iteracoes;
	cin >> n_iteracoes;
	
	while(n_iteracoes > 0)
	{
		int A, B, n_years = 0;
		
		cin >> A >> B;
		
		for(int i = A; i <= B; i++)
		{
			int T[4], n_casas = 4;
			T[0] = (i / 1000);
			T[1] = ((int)(i - (T[0] * 1000)) / 100);
			T[2] = ((int)(i - ((T[0] * 1000) + (T[1] * 100))) / 10);
			T[3] = ((int)(i - ((T[0] * 1000) + (T[1] * 100) + (T[2] * 10))));
			
			for(int i = 0; i < 3; i++)
				if(T[i] == 0) n_casas--;
				else break;
			
			if(compara(T, n_casas)) n_years++;
		}
		
		cout << n_years << endl;
		
		n_iteracoes--;
	}
	
	return 0;
}
