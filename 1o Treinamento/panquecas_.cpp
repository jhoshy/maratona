#include <iostream>
using namespace std;

int main(void)
{
	int n_pedidos;
	do
	{
		cin >> n_pedidos;
		
		if(n_pedidos)
		{
			int tempo = 0;

			for(int i = 0; i < n_pedidos; i++)
			{
				int pedidoatual;
				cin >> pedidoatual;
				tempo += ((int)(pedidoatual / 2) * 2);
				if(pedidoatual % 2 == 1)
					tempo += 2;
			}

			cout << tempo << endl;
		}
	}
	while(n_pedidos);
	
	return 0;
}
