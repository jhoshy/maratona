// http://br.spoj.com/problems/VOLEI/
#include <iostream>

using namespace std;

bool **m, // matrix do input
	***juiz;
int N;

bool qualquer(bool *piso) {
	return piso[0] || piso[1] || piso[2] || piso[3];
}

bool verificar(int *xl, int *yl, int d) {
	if (xl < 0 || yl < 0) return true;
	if (!qualquer(m[*(yl)]/*[*(xl)]*/ )) return false;

	if (*(yl) == 0 || !m[*(yl)-1][*(xl)] ) // passa linha por cima
		if (!juiz[2][*(yl)][3] && !juiz[3][*(yl)][2] ) return false;
	if (*(yl) == N-1 || !m[*(yl)+1][*(xl)] ) // baixo
		if (!juiz[2][*(yl)+1][3] && !juiz[3][*(yl)+1][2] ) return false;
	if (*(xl) == 0 || !m[*(yl)][*(xl)-1] ) // esquerda
		if (!juiz[0][*(xl)][1] && !juiz[1][*(xl)][0] ) return false;
	if (*(xl) == N-1 || !m[*(yl)][*(xl)+1] ) // direita
		if (!juiz[0][*(xl)+1][1] && !juiz[1][*(xl)+1][0] ) return false;
}
								
int main() {

	while(1) {
		cin >> N;
		if (N == 0) return 0;

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
				while(N3--) m[N][N3] = false;
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
						
						if (y == 0 || !m[y-1][x]) { // passa linha por cima
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
				// finge que retirou cada juiz, e ve se a matrix continua 'válida'.
				int posicao = 4, indice, direcao;
				int *direcao_old = new int[4];
				bool cb; // juizes ficam em cima ou em baixo; senao, ficam na esquerda ou direita;
				while(posicao--) {
					cb = posicao < 2;
					int indice = cb ? largura : altura;
					while(indice--) {
						int direcao = 4;
						bool juiz_old[4]; 
						juiz_old[0] = juiz[posicao][indice][0];
						juiz_old[1] = juiz[posicao][indice][1];
						juiz_old[2] = juiz[posicao][indice][2];
						juiz_old[3] = juiz[posicao][indice][3];

						while(direcao--) {
							// salva o estado atual
							direcao_old[direcao] = juiz[posicao][indice][direcao];
							
							// verifica se juiz esta olhando pra esta direcao
							if (juiz[posicao][indice][direcao] == 0) continue;

							// deleta esse juiz, nesta direcao
							juiz[posicao][indice][direcao] = 0;

							// verifica validez do estado, nesta direcao
							int xl = indice, 
								yl = indice,
								*i = cb ? &yl : &xl,
								*j = cb ? &xl : &yl;

							*i = -1;
							int t = cb ? largura : altura;
							while(++(*i) < t) {
								// para cada ponto, no encontro de linhas, verificar as 2 casas ao redor.
								--(*j);
								if (!verificar(i, j, direcao) || !verificar(i, j, direcao)) break;
							}
							if (*i != t ) break;
						}

						if (direcao != -1) {
							// voltar ao o que era antes, este juíz nao pode ser removido.
							juiz[posicao][indice][0] = juiz_old[0];
							juiz[posicao][indice][1] = juiz_old[1];
							juiz[posicao][indice][2] = juiz_old[2];
							juiz[posicao][indice][3] = juiz_old[3];
							break;
						}
					}
				}
			}
		}
	}
	return 0;
}
