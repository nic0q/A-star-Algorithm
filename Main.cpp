#include "maze.h"
#include <time.h>
#include <cmath>
int main(){
	int n;
  unsigned t0,t1;
	double time;
	int dif_t;
	double tp = 0;
	Maze *m = new Maze(1000,90);
	cout << "Cantidad de pruebas ";
	cin >> n;
  for(int i = 0; i < n; i++){
		m->generate();
		t0 = clock();
		string p = m -> solve();
		t1 = clock();
		time = double(t1-t0) / CLOCKS_PER_SEC;
		tp = double(time + tp);
    cout << i + 1 << ".- " << time <<"[s]"<< endl;
  }
	cout <<"Promedio: "<< tp / n << "[s]" << endl;
}