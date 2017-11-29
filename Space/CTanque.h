#include "UClases.h"

class CTanque
{
 private:
        int x,y,dx,dy,n;
		CUniversal **V;
			
 public:
	   CTanque();
	   ~CTanque();
	   void Dibujar();
	   void Borrar();
	   void Derecha();
	   void Izquierda();
	   void Arriba();
	   void Abajo();
	   void Insertar_Balas();
   	   void Eliminar_Balas(int pos);
	   void Mover_Balas();
	   int  get_vx(int i);
	   int  get_vy(int i);
	   int  get_n();
	   int  get_x();
	   int  get_y();

	   


};