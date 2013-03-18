// http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3974
#include <iostream>
using namespace std;

bool **barreiras;
int w, h;

int resultado = 2147483647; // max int

struct No {
	bool **girou, **passou;
	int x, y,
		contador,
		contador_giro;

	No() {}
	No(No* p, int X, int Y, bool &girar, int X2, int Y2) {

		contador_giro = p->contador_giro + girar;

		girou = new bool*[h];
		y = -1;
		while(++y < h) {
			girou[y] = new bool[w];
			x = -1; while(++x < w) girou[y][x] = p->girou[y][x];
		}
		if (girar) girou[Y2][X2] = 1;

		passou = new bool*[h + 1];
		y = -1;
		while(++y < h + 1) {
			passou[y] = new bool[2 * w + 1];
			x = -1; while(++x < 2 * w + 1) passou[y][x] = p->passou[y][x];
		}

		x = X;
		y = Y;
		contador = p->contador;
		girar = 0;
		andar();
	}

	void deb(int A, int B, bool dir, bool graca, int a, int b) {
		if (x == A && y == B) 
		{
			cout << "\n\nx: " << x << ", y: " << y << "\n";
			cout << "direcao: " << (dir ? "pode" : "nao pode") << "\n";
			cout << "pode: " << (!passou[y][x - 1] ? "sim" : "nao") << "\n";
			cout << "de graca: " << (graca ? "sim" : "nao") << "\n";
			cout << "barrado: " << (barreiras[b][a] ^ girou[b][a] ? "horizontal" : "vertical") << "\n";
			cout << "ainda nao girou: " << (!girou[b][a] ? "pode girar" : "nao pode girar") << "\n";
		}

	}

	void andar() {


		++contador;

		if (x == 0 && y == h && contador == (h + 1) * (2 * w + 1)) {
			if (resultado > contador_giro) resultado = contador_giro;
			//cout << "x";
			return;
		} else if (contador_giro >= resultado) {return;}

		passou[y][x] = 1;

		int i = !(x & 1 ^ y & 1), // se ambos são ímpares ou pares.
				X = x/2, X2 = (x - 1) / 2, 
				Y = y, Y2 = y - 1;
		bool girar = 0,
			esq = x > 0, 
			dir = x < 2 * w, 
			baixo = y < h, 
			cima = y > 0;
		No *filho;

		//cout << "\n" << "(" << x << ", " << y << "), " << contador_giro  << ", contador: " << contador;
	
		// andar pra direita
		int a = X, b = i ? Y : Y2;
		if (dir && !passou[y][x + 1] && ((i ? !baixo : !cima) || (barreiras[b][a] ^ girou[b][a] || (!girou[b][a] && (girar = 1))))  ) { 
			filho = new No(this, x + 1, y, girar, a, b);
		}

		// andar pra esquerda
		a = X2; b = !i ? Y : Y2;
		//deb(6, 1, esq, (!i ? !baixo : !cima), a, b);
		if(esq && !passou[y][x - 1] && ((!i ? !baixo : !cima) || (barreiras[b][a] ^ girou[b][a] || (!girou[b][a] && (girar = 1))))   ) { 
			filho = new No(this, x - 1, y, girar, a, b);
		} 

		// andar pra baixo
		a = i ? X : X2; b = Y;
		if (baixo && !passou[y + 1][x] && ((i ? !dir : !esq) || (barreiras[b][a] ^ girou[b][a] || (!girou[b][a] && (girar = 1))))) { 
			filho = new No(this, x, y + 1, girar, i ? X : X2, Y);
		}

		// andar pra cima
		a = i ? X : X2; b = Y2;
		if (cima && !passou[y - 1][x] && ((i ? !dir : !esq) || (barreiras[b][a] ^ girou[b][a] || (!girou[b][a] && (girar = 1))))) { 
			filho = new No(this, x, y - 1, girar, i ? X : X2, Y2);
		}
	}

};



int main(int argc, char const *argv[])
{


	// input
	cin >> w;
	h = w * 2 - 1;
	barreiras = new bool*[h];
	int y = -1;
	while(++y < h) {
		barreiras[y] = new bool[w];
		int x = -1;
		while(++x < w) {
			char giro;
			cin >> giro;
			barreiras[y][x] = giro == 'H';
		}
	}


	// iniciar
	No *inicio = new No();
	inicio->x = inicio->y = 0;
	inicio->contador = inicio->contador_giro = 0;
	inicio->girou = new bool*[h];
	y = -1;
	while(++y < h) {
		inicio->girou[y] = new bool[w];
		int x = -1; while(++x < w) inicio->girou[y][x] = 0;
	}

	inicio->passou = new bool*[h + 1];
	y = -1;
	while(++y < h + 1) {
		inicio->passou[y] = new bool[2 * w + 1];
		int x = -1; while(++x < 2 * w + 1) inicio->passou[y][x] = 0;
	}
	

	// executar
	inicio->andar();


	// output
	cout << /*"\n\n\nresultado: " <<*/ resultado;
	
	return 0;
}
