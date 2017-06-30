#define FD 77
#define FI 75
#define ESP 32 
#define LARGO 120
#define ALTO 50

class CUniversal{

 public:
	    CUniversal() {}
		virtual void Dibujar()=0;
		virtual void Borrar()=0;
		virtual void Mover()= 0;
		virtual int get_x()=0;
		virtual int get_y()=0;
		virtual int get_dy()=0;
		virtual int get_tipo()=0;
};

class CBala:public CUniversal
{
 private:
         int x,y,dy; 
 public:
        CBala(int x,int y);
		~CBala();
		void Dibujar();
		void Borrar();
		void Mover();
		int get_x();
	    int get_y();
		int get_dy();
		int get_tipo(){return 1;}
};

class CTanque
{
 private:
        int x,y,dx,n;
		CUniversal **V;
			
 public:
	   CTanque();
	   ~CTanque();
	   void Dibujar();
	   void Borrar();
	   void Derecha();
	   void Izquierda();
	   void Insertar_Balas();
   	   void Eliminar_Balas(int pos);
	   void Mover_Balas();
	   int  get_vx(int i);
	   int  get_vy(int i);
	   int  get_n();
	   int  get_x();
	   int  get_y();

	   


};



class CEnemigo:public CUniversal
{
 private:
        int tipo,x,y,dx,dy;
 public:
       CEnemigo(int x = 0,int y=0,int tipo=0);
	   ~CEnemigo();
	   void Dibujar();
	   void Borrar();
	   void Mover();
	   int  get_x();
	   int  get_y();
	   int  get_dy() { return 1; }
	   int  get_tipo();
	   
};

class CEnemigos
{
 private:
        CUniversal **V;
		int n;

 public:
        CEnemigos();
		~CEnemigos();
		void Insertar_Enemigos(System::Random ^r);
		void Eliminar_Enemigos(int pos);
		void Mover_Enemigos();
		int get_vx(int i);
		int get_vy(int i);
		int get_tipo(int i);
	    int get_n();
	



};

class CPac
{
 private:
         int x,y,dx,dy,tipo;
		 int px,py,pdx,pdy,velocidad;
 public:
	     CPac();
	    ~CPac();
		void Dibujar();
		void Borrar();
        void Mover();
		int get_x();
		int get_y();
		void Come();
		void Dibujar_Actpac();
		void Borrar_Actpac();
		void Mover_Actpac();
		int get_py();
		int get_px();



};

class CJuego
{
 private:
	    CTanque *Tanque;
        CEnemigos *Enemigo;
		CPac  *Pacman;
		int nivel,puntos,fin,d,z;
		int p,premio,con,act;

 public:
       CJuego();
	   ~CJuego();
	   void Tablero(int largo , int alto);
       void Datos();
	   void Actualizar_datos(int i);
	   void Teclado(int *s);
	   void Insertar_Elementos(System::Random ^r,int *cont,int *s);
	   void Mover_Todo(int *s);
	   bool Siente_ElChoque(int xe,int ye, int xb, int yb,int caso);
	   void Colision(int *s);
	   void Presentacion();
       void impdiag(int posx,int posy,int x,int y,char go[ ][70],int color);
	   void intro(int x,int y);
	   void Game_Over(int largo, int alto, int &i);
	   void You_Win(int largo, int alto);
	   int get_fin();
};
