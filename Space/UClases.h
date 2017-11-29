#define FD 77
#define FI 75
#define FA 72 
#define FAB 80
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


class CJuego
{
 private:
	    CTanque *Tanque;
        CEnemigos *Enemigo;
		int nivel,puntos,con,fin,d,z;


 public:
       CJuego();
	   ~CJuego();
	   void Tablero(int largo , int alto);
       void Datos();
	   void Actualizar_datos(int i);
	   void Teclado(int *s);
	   void Clonar(System::Random ^r,int *cont, int *s);
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
