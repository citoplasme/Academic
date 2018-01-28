#include <stdio.h>

#define NV 100

struct edge {
    int destino;
    int weight;
    struct edge *next;
};

typedef struct edge *Grafo[NV];

// Devolve o numero de vertices que vão dar a s
int indegree (Grafo g, int s) {
	struct edge *p;
	int i, r = 0;

	for (i = 0; i < NV; i++) {
		for (p = g[i]; p; p = p -> next) {
			if (p -> destino == s) r++;
		}
	}
	return r;
}
// se encontrar um vértice ja visto, é pq existe mais que um caminho para lá
int bf (Grafo g, int s, int color[]) {
	struct edge *p;
	int r = 1;
	color [s] = 1;

	for (p = g[s]; p ; p = p -> next) {
		if (color[p -> destino] == -1) r = bf(g, p->destino, color);
		if (color[p -> destino] == 1) return -1;
	}
	return r;
}

int isTree (Grafo g) {
	int color[NV] = {-1};
	int i, zeros = 0, r, r2;
	int graus[NV] = {-1};

	for (i = 0; i < NV; i++) {
		graus[i] = indegree(g, i);
		if (graus[i] == 0) zeros++; r = i;
	}
	if (zeros != 1) return -1;

	r2 = bf(g, r, color);
	// existencia de mais do q um caminho
	if (r2 == -1) return -1;
	else {
		for (i = 0; i < NV; i++) {
			// nao existir caminho
			if (color[i] == -1) return -1;
		}
	}
	return r;
}
