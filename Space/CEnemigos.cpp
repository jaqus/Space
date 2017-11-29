#include "UClases.h"

///////////////////////////////////////

////////////////////////cenemigo
CEnemigo::CEnemigo(int x, int y, int tipo)
{
	
	this->tipo = tipo;  
	this->x = x;
    this->y = y;
	dx=1;
	dy=4;



}
CEnemigo::~CEnemigo()
{
}
void CEnemigo::Dibujar()
{
 
  switch(tipo)
  {
	 case 1:
		     Console::ForegroundColor = ConsoleColor::Cyan;break;
	 case 2:
		     Console::ForegroundColor = ConsoleColor::Red;break;
	 case 3:
		     Console::ForegroundColor = ConsoleColor::Yellow;break;
		   
  }
			 Console::BackgroundColor = ConsoleColor::Black;   	  
             
			 Console::SetCursorPosition(x+1,y); cout<<(",----."    ); 
			 Console::SetCursorPosition(x,y+1); cout<<("|      |"  );
			 Console::SetCursorPosition(x,y+2); cout<<(" \\    /"  ); 
			 Console::SetCursorPosition(x,y+3); cout<<("  wwww"    );
 

}
void CEnemigo::Borrar()
{
			 Console::BackgroundColor = ConsoleColor::Black;   	  
			 Console::ForegroundColor = ConsoleColor::Black;
			 Console::SetCursorPosition(x+1,y); cout<<(",----."   ); 
			 Console::SetCursorPosition(x,y+1); cout<<("|      |" );
			 Console::SetCursorPosition(x,y+2); cout<<(" \\    /" ); 
			 Console::SetCursorPosition(x,y+3); cout<<("  wwww"   );



}
void CEnemigo::Mover()
{
  Borrar();

  if(x+dx+6<LARGO && x+dx>0)
     x+=dx;
  if((x+dx+6==LARGO || x+dx==1) && y+dy+4<45)
    {
	 y+=dy;
	 dx*=-1;
    }

  Dibujar();

}

int CEnemigo::get_x()
{
  return x;
}
int CEnemigo::get_y()
{
  return y;
}
int CEnemigo::get_tipo()
{
  return tipo;
}

////////////////////////////////////////

////////////////////cenemigos

CEnemigos::CEnemigos()
{
   
   V=NULL;
   n=0;

}
CEnemigos::~CEnemigos()
{
	if(n=0) return;
	for(int i=0;i<n;i++)
		 delete V[i];
	delete []V;

}
void CEnemigos::Insertar_Enemigos(System::Random ^r)
{
   CUniversal **aux;
   int tipo,x,y;



   aux=new CUniversal*[n+1];
   
   if(V!=NULL) 
   {
     for(int i=0;i<n;i++)
	     aux[i] = V[i]; 
	 if(r->Next(0,120)>80)
		x=LARGO-9;
	 else if(r->Next(0,120)<80 && r->Next(0,120)>40 )
	    x=60;
	 else 
	    x=5;
	 
	 y=8;
     tipo = r->Next(1,4);
     aux[n]= new CEnemigo(x,y,tipo);
     n++;
     if(V!=NULL)
	    delete []V;
   }

   V = aux;

}
void CEnemigos::Eliminar_Enemigos(int pos)
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


void CEnemigos::Mover_Enemigos()
{
	for(int i=0;i<n;i++)
	  V[i]->Mover();


}
int CEnemigos::get_vx(int i)
{
       return V[i]->get_x();
 
}
int CEnemigos::get_vy(int i)
{
 	return V[i]->get_y();
}
int CEnemigos::get_tipo(int i)
{
	return V[i]->get_tipo();
}
int CEnemigos::get_n()
{
    return n;
}
