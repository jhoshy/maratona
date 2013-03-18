// http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3972
#include <iostream>
#include <stdlib.h>

using namespace std;

bool check(char buff[5]) {
	int i = -1;
	while(buff[++i]) {
		int j = i;
		while(buff[++j]) if (buff[j] == buff[i]) return false;
	}

	return true;
}


int main(int argc, char const *argv[])
{
	int n, m, c = 0;
	cin >> n >> m;
	--n;

	char buff[5];

	while(++n <= m) {
		itoa(n, buff, 10);
		c += check(buff);
	}

	cout << c;
	return 0;
}
