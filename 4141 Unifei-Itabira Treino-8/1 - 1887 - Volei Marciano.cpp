// http://br.spoj.com/problems/VOLEI/

int main() {

	while(1) {
		int N;
		cin >> N;
		if (N == 0) return 0;

		// monta estrutura da matrix
		bool **matrix;

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
			matrix = new bool*[N];
			while(N--) {
				matrix[N] = new bool[N];
				int M = N2;
				while(M--) matrix[N][M] = false;
			}

			N = N2;
			// monta matrix, tudo positivo
			while(N--) matrix[list[N][1] + Yo][list[N][0] + Xo] = true;
		}




	}

	return 0;
}
