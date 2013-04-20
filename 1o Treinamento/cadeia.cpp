#include <iostream>
#include <cstring>
using namespace std;


bool igual(char * a, char * b)
{

	int i = -1;
	int j = 0;
	char c = '\0';
	while(c = a[++i]){
		if (!b[i]) return 0;
		if (b[i] != a[i]) ++j;
	 }
	cout << a << " e " << b << " "; if (((a[i] + b[i] == 0) && j==1) == 0)  cout << "diferentes\n"; else cout << "iguais\n";
	return (a[i] + b[i] == 0) && j==1;
}

int main(void)
{
	char **d;
	
	int n;
	
	
	cin >> n;
	d = new char *[n];
	for(int i = 0; i < n; i++)
	{
		d[i] = new char[10];
		cin >> d[i];
		
	}
	
	{ // sort
		int i = -1;
		while(++i < n) {
			int j = -1;
			while(++j < n-1) {
				if (strcmp(d[j], d[j+1]) > 0) {
					char *c = d[j];
					d[j] = d[j+1];
					d[j+1] = c;
				}
			}
		}
	}
	
	
	int m;
	
	cin >> m;
	for(int j = 0; j < m; j++)
	{
		char *c = new char[10];
		cin >> c;
		
		cout << c << ":";
		
		for(int l = 0; l < n; ++l)
		{
			if(igual(c, d[l]))
			{
				cout << " " << d[l];
			}
		}
		
		cout << endl;
		delete [] c;
	}
	
	delete [] d;
	return 0;
}
