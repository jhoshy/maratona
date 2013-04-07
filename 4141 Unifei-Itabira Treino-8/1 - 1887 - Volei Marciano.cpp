// http://br.spoj.com/problems/VOLEI/
#include <iostream>

int main() {

	while(1) {
		int N;
		cin >> N;
		if (N == 0) return 0;

		// monta estrutura da matrix
		bool **m;

		// matrix do input
		{
			int N2 = N, // N original
				Xo = 0, Yo = 0, // offset 
				**list = new int*[N];

			// joga input numa lista
			while(N--){ 
				int X, Y;
				cin >> X >> Y;
				if (X < Xo) Xo = X;
				if (Y < Yo) Yo = Y;
				list[N] = new int[2];
				list[N][0] = X;
				list[N][1] = Y;
			}

			N = N2;
			// monta estrutura da matrix
			m = new bool*[N];
			while(N--) {
				m[N] = new bool[N];
				int N3 = N2;
				while(N3--) m[N][M] = false;
			}

			N = N2;
			// monta matrix, tudo positivo
			while(N--) m[list[N][1] + Yo][list[N][0] + Xo] = true;
		}



		{
			bool ***juiz; // na verdade só precisava do perimetro, nao da area. ja era. =(

			// constroi a matrix de juizes
			// [linha][coluna][direcao] , direcao (pra cima, pra baixo, pra esquerda, pra direita)
			{
				juiz = new bool**[N];
				int N2 = N;
				while(N--) {
					juiz[N] = new bool*[N];
					int N3 = N2;
					while(N3--)  {
						juiz[N][N3] = new bool[4];
						int i = -1; while(++i < 4) juiz[N][N3][i] = 0;
					}
				}
			}
			
			// adiciona juízes
			{
				int y = -1, x;
				while(++y < N) {
					x = -1;
					while(++x < N) {
						bool cima, baixo, esquerda, direita;
						cima = baixo = esquerda = direita = false;
						
						// cada bloco na matrix pode gerar até 8 juízes:
						if (y == 0 || !m[y-1][x]) cima = true;
						if (y == N-1 || !m[y+1][x]) baixo = true;
						if (x == 0 || !m[y][x-1]) esquerda = true;
						if (x == N-1 || !m[y][x+1]) direita = true;
						
						if(cima) {
							juiz[y][0][3] = true;
							juiz[y][N-1][2] = true;
						}
						if(baixo) {
							juiz[y+1][0][3] = true;
							juiz[y+1][N-1][2] = true;
						}
						if(esquerda) {
							juiz[0][x][1] = true;
							juiz[N-1][x][0] = true;
						}
						if(direita) {
							juiz[0][x+1][1] = true;
							juiz[N-1][x+1][0] = true;
						}
					}
				}
			}

			// simplifica juizes
			{

			}

		}




	}

	return 0;
}
