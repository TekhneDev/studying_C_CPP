// arquivo: figuras.h

class coordenada
{
	private:
		int  x;
		int  y;
	public:
	                 coordenada (void);   
    	virtual void nova_pos  (int nx, int ny);
    	virtual void obter_pos (int *vx, int *vy);
    	virtual void novo_nome (char nnome [15]) = 0;   // '=0' indica que classe é abstrata pois tem método abstrato
};
	
class ponto: protected coordenada // membros publicos do pai se tornam protegidos (protected) no filho
{
	private:
		char  c;	
		char nome[15];  
		    
	  	      void posiciona(void);	
	protected:
	  virtual void mostra (void);	
    public:
	                ponto     (void);
			        ponto     (int x, int y);	           
	           void novo_c    (char nc);
	           void novo_nome (char nnome [15]);	           
	   virtual void exibe     (void);
   	           void move_para (int  nx, int ny);
};
	
class circulo: public ponto // membros herdados conservam a visibilidade definida no pai
{
	private:
	      static char preenchimento;		  		
	      	     int raio;
	      virtual void mostra(void);	
    public:
		              circulo    (int x, int y, int r);
	             void novo_raio  (int  nr);	    
	             void exibe      (void);	    
         static  void novo_preenchimento (char p);
};
