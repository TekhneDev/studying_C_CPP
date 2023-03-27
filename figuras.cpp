// arquivo: figuras.cpp

#include <stdio.h>
#include <string.h>

#include "figuras.h"
 	
/***********************
*  Classe coordenada	
************************/

coordenada::coordenada (void) { 
	x = 0; 
  	y = 0; 
}

void coordenada::nova_pos (int nx, int ny) {
	x = nx;
    y = ny;
}

void coordenada::obter_pos (int *vx, int *vy){
	*vx = x;
    *vy = y;	
}

/***********************
*  Classe ponto	
************************/

ponto::ponto (void) {
	c = '*';
	novo_nome ("ponto");
}

ponto::ponto (int x, int y) {
	c = '@';
	nova_pos(x, y);
	novo_nome ("centro");
}
	
void ponto::novo_nome (char nnome [15]) {
	strcpy(nome, nnome);
}

void ponto::novo_c (char nc) {
	c = nc;
}
		
void ponto::move_para (int nx, int ny)  {
	nova_pos(nx, ny);	
	exibe();
}

void ponto::exibe (void) {
	printf("\n");
	
	posiciona();
	mostra();
	
	printf("\n");	
}

void ponto::mostra (void) {
	printf("%c", c);
	
}
	
void ponto::posiciona (void) {
	int coluna, linha;
	
	obter_pos (&coluna, &linha);
	
    for(int p = 0; p <= linha; p++) { 
		printf("\n");
    } 
    for(int q = 0; q <= coluna; q++) {
		printf(" ");
    }
}
	
/***********************
*  Classe circulo	
************************/	
	
char circulo::preenchimento = '.';	// se nao incializar assim, dá erro

void circulo::novo_preenchimento (char p)
{
	circulo::preenchimento = p;
}

circulo::circulo (int x, int y, int r): ponto(x, y) {
     raio = r;
}
	
void circulo::novo_raio (int nr) {
	raio = nr;
}

void circulo::exibe (void) {
    mostra();
}

void circulo::mostra(void) {
	int x, y, lin, col;
	int ab, ord; 
	int i, j; 
    int N = 2 * raio + 1;

	obter_pos (&col, &lin); 
	
	if (col == raio) 
    	ab = 0;
 	else 
		ab = col - raio;	 

	if (lin == raio)
    	ord = 0;
	else 
		ord = lin - raio;
      	
	for (i = 0; i < N + ord; i++) {
  
        for (j = 0; j < N + ab; j++) {
            x = i - raio - ord;
            y = j - raio - ab;
 
            if (x*x + y*y <= raio*raio+1 ) {
                if (i == (raio + ord)  && j == (raio + ab)) {
                	ponto::mostra();
                } else {
                    printf("%c", circulo::preenchimento);                
                }
            } else { // se fora do circulo, imprime espaco
                printf(" ");
            }
            printf(" ");
        }
        printf("\n");
    }
}
