// http://br.spoj.com/problems/VOLEI/
#include <iostream>

int main() {

	while(1) {
		int N;
		cin >> N;
		if (N == 0) return 0;

		bool **m; // matrix do input
		int largura = 0, altura = 0; // juizes

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
			while(N--) {
				int y = list[N][1] + Yo, x = list[N][0] + Xo;
				m[y][x] = true;
				if (y > altura) altura = y;
				if (x > largura) largura = x;
			}
			++largura;
			++altura;
		}



		{
			bool ***juiz;

			// constroi a matrix de juizes
			// [posicao][indice][direcao] , 
			// 	posicao (linha de cima, linha de baixo, coluna da esquerda, coluna da direita)
			// 	indice (da esquerda pra direita ou de cima pra baixo).
			// 	direcao (pra cima, pra baixo, pra esquerda, pra direita)

			{
				juiz = new bool**[4]; // ficam em cima, baixo, esquerda, direita
				int N2 = N, i = 4;
				while(i--) {
					int tamanho = i < 2 ? largura : altura;
					juiz[i] = new bool*[tamanho];
					int N3 = N2;
					while(tamanho--)  {
						juiz[i][tamanho] = new bool[4];
						int j = -1; 
						while(++j < 4) juiz[i][tamanho][j] = 0; // virados pra nenhum lado
					}
				}
			}
			
			// adiciona juízes
			{
				int y = -1, x;
				while(++y < N) {
					x = -1;
					while(++x < N) { // cada bloco na matrix pode gerar até 8 juízes
						
						if (y == 0 || !m[y-1][x]) { // cima
							juiz[2][y][3] = true;
							juiz[3][y][2] = true;
						}
						if (y == N-1 || !m[y+1][x]) { // baixo
							juiz[2][y+1][3] = true;
							juiz[3][y+1][2] = true;
						}
						if (x == 0 || !m[y][x-1]) { // esquerda
							juiz[0][x][1] = true;
							juiz[1][x][0] = true;
						}
						if (x == N-1 || !m[y][x+1]) { // direita
							juiz[0][x+1][1] = true;
							juiz[1][x+1][0] = true;
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
