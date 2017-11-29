#include "UClases.h"

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
