#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Example of a Hash Table struct 
typedef struct {
    struct pair {
    	char status[10];
        int value;
        int cont;
    } *tbl;
} HT;
// prints the hash on terminal
void imprime (HT *h, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf ("Valor: %d \tContagem: %d \tStatus: %s \n",h->tbl[i].value, h->tbl[i].cont, h->tbl[i].status);
    }
}
// inicializes hash
void inicializar (HT *h, int size) {
	int i;
    h->tbl = calloc (size, sizeof (struct pair));
	for (i = 0; i < size; i++) {
		strcpy (h->tbl[i].status, "EMPTY"); 
		h->tbl[i].value = -99;
		h->tbl[i].cont = 0;
	}
}
// adds a value to the hash
void add (HT *h, int size, int val) {
    int r;
    r = val % size;
    
    while (strcmp (h->tbl[r].status,"EMPTY") != 0){
        if (h->tbl[r].value == val && (strcmp (h->tbl[r].status,"USED") == 0)){
            break;
        }
        r = (r+1) % size;
    }
    
    h->tbl[r].value = val;
    h->tbl[r].cont++,
    strcpy (h->tbl[r].status, "USED");
}
// Adds all the elements of v to an Hash, counting repetitions
// Also prints the hash obtained at the end on the terminal
int repetidos (int v[], int N) {
    int i, r, size = 3*N;
    HT *h;
    inicializar(h, size);
    
    for (i = 0; i < N;i++) {
        add (h,size,v[i]);
    }
    imprime (h, size);
    return 0;
}
// Example of the given problem
int main () {
    int a[5] = {11,25,33,47,11}, r;
    r = repetidos (a,5);
    return 0;
}
