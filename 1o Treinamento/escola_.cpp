#include <iostream>
#include <cmath>
using namespace std;

inline int abs(int n) { return (n > 0 ? n : -n); }

int main(void)
{
	int w, h, a;
	
	do
	{
		cin >> w >> h >> a;
		
		if(w && h && a)
		{
			int p[a * 2], sx = 0, sy = 0;
			for(int i = 0; i < a; i++)
			{
				cin >> p[2 * i] >> p[2 * i + 1];
				sx += p[2 * i]; sy += p[2 * i + 1];
			}
			
			sx = (int)round((float)sx / (float)a);
			sy = (int)round((float)sy / (float)a);
			
			int ax = 0, ay = 0;
		
			for(int i = 0; i < a; i++)
			{
				ax += abs(p[2 * i] - sx);
				ay += abs(p[2 * i + 1] - sy);
			}
		
			cout << ax + ay << endl;
		}
		
	}
	while(w && h && a);
	
	return 0;
}
