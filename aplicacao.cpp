// arquivo: aplicacao.cpp


#include <stdlib.h>

#include "figuras.h"

int main(void) 
{
	
/***********************
*  Objeto coordenada	
************************/
	
//  coordenada c; 			  //[Error] cannot declare variable 'c' to be of abstract type 'coordenada'	
	
	
	
/***********************
*  Objeto ponto	
************************/	
	ponto pt;	

	pt.exibe();
	system("PAUSE");
	
//	pt.nova_pos (10, 1);  //[Error]'void coordenada::nova_pos(int, int)' is protected
	     
	pt.novo_c('#');
	pt.exibe();
	system("PAUSE");
	
	pt.move_para(20, 1);
	system("PAUSE");
	
	
/***********************
*  Objeto circulo	
************************/		

// Circulo: alocacao estática
	circulo circ(10, 10, 10);  
    circ.exibe();    
        
    system("PAUSE");
	system("CLS");
	
//	circ.nova_pos (40, 13); //[Error]'void coordenada::nova_pos(int, int)' is protected

    circ.exibe();

	circ.novo_raio(7);
    circ.exibe();	
	system("PAUSE");
	
	
// Circulo: alocacao  dinamica
    circulo* vet[10];
    vet[0] = new circulo (9, 9, 9);
    
    vet[0]->exibe(); 

	circulo::novo_preenchimento ('+');
	
	vet[0]->move_para (40, 13);
	system("PAUSE");
	
	delete vet[0];	

  return EXIT_SUCCESS;
}
