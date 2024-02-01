#include <stdio.h>
#include <stdlib.h>

int arr[6][6] = {{0,1,1,0,0,0},
				 {1,0,0,1,1,0},
				 {1,0,0,0,1,0},
				 {0,1,0,0,1,1},
				 {0,1,1,1,0,1},
				 {0,0,0,1,1,0}};

int visited[6] = {0,0,0,0,0,0};

void DFT (void) {
	int node ;
	for (node = 0; node < 6; node++) {
		if (visited[node] == 0) {
		TraversGraph(node);
		}
	}
}

void TraversGraph (int node) {
	int i;
	visited[node] = 1;
	printf("%d ", node);
	for (i = 0; i < 6; i++) {
		if (arr[node][i] == 1 && visited[i] == 0) {
			TraversGraph(i);
		}
	}
}

int main (void) {
	DFT();
	return 0;
}
