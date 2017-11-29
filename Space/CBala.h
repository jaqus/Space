#include "UClases.h"

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