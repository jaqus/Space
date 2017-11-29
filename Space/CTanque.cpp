#include "UClases.h"

/////////////////////ctanque

CTanque::CTanque()
{
  x=55;
  y=45;
  dx=1;
  dy=1;
  n=0;
  V=NULL;
}
CTanque::~CTanque()
{
	if(n=0) return;
	for(int i=0;i<n;i++)
		 delete V[i];
	delete []V;
}
void CTanque::Dibujar()
{
 Console::BackgroundColor = ConsoleColor::Black;   	  
 Console::ForegroundColor = ConsoleColor::Gray;
 Console::SetCursorPosition(x+6,y); cout<<"___"; 
 Console::SetCursorPosition(x,y+1); cout<<("_____/_o_\\_____");
 Console::SetCursorPosition(x-2,y+2); cout<<(" (==(/_______\\)==) "); 
 Console::SetCursorPosition(x+1,y+3); cout<<(" \\==\\/ \\/==/ ");
}
void CTanque::Borrar()
{
 Console::BackgroundColor = ConsoleColor::Black;   	  
 Console::ForegroundColor = ConsoleColor::Black;
 Console::SetCursorPosition(x+6,y); cout<<("___"); 
 Console::SetCursorPosition(x,y+1); cout<<("_____/_o_\\_____");
 Console::SetCursorPosition(x-2,y+2); cout<<(" (==(/_______\\)==) "); 
 Console::SetCursorPosition(x+1,y+3); cout<<(" \\==\\/ \\/==/ ");

}
void CTanque::Derecha()
{
  Borrar();

  if(x+dx+17<LARGO)
     x=x+dx;
  
  Dibujar();
}
void CTanque::Izquierda()
{
  Borrar();
  
  if(x-dx>1)
     x=x-dx;

  Dibujar();
}
void CTanque::Arriba()
{
  Borrar();

  if(y-dy>8)
     y=y-dy;
  
  Dibujar();
}
void CTanque::Abajo()
{
  Borrar();
  
  if(y+dy+4<ALTO)
     y=y+dy;

  Dibujar();
}
void CTanque::Insertar_Balas()
{ 
	CUniversal **aux;
    int x,y;


    aux=new CUniversal*[n+1];
   
    if(V!=NULL) 
	{
     for(int i=0;i<n;i++)
	     aux[i] = V[i]; 
	 x=(this->x+7);
	 y=(this->y-1);
	 aux[n]= new CBala(x,y);
     n++;
     if(V!=NULL)
	    delete []V;

	}
	V=aux;

   

}
void CTanque::Eliminar_Balas(int pos)
{
   CUniversal **aux= new CUniversal*[n-1];
   int i=0;
   if(V==NULL) return;

   
   	                             
   while(i<=n)
   {   	   
	   if( i == pos )
	     {   
		  V[i]->Borrar();
		  n--;
		  i++;
		 }
	   else
	     { 
		   if(i < pos)
	          V[i] = V[i];         
	       if(i > pos)
	         {
	          V[i-1] = V[i];
	          V[i]->Borrar();
			 }
		   
		   i++;
	    }
   
   }

   for(int j=0;j<n;j++)
       aux[j]=V[j];

   delete []V;

   V = aux;
    


   
}
void CTanque::Mover_Balas()
{
  for(int i=0;i<n;i++)
	  if(V[i]->get_dy() == 0)
         Eliminar_Balas(i);
	  else 
	     V[i]->Mover(); 
}
int CTanque::get_vx(int i)
{
    return V[i]->get_x();
 
}
int CTanque::get_vy(int i)
{
 	return V[i]->get_y();
}
int CTanque::get_n()
{
    return n;
}
int CTanque::get_x()
{
  return x;
}
int CTanque::get_y()
{
  return y;
}