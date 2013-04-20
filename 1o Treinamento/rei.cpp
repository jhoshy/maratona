#include <iostream>
using namespace std;

int main(void)
{
	int n;
	do
	{
		cin >> n;
		if(n) cout << 8 * n * (n + 1) / 2 + (n > 1) << endl;
	}
	while(n);
	return 0;
}
