#include "UClases.h"

///////////////////////////////////////

/////////////////////cbala

CBala::CBala(int x,int y)
{
  this->x = x;
  this->y = y;
  dy=-1;
} 
CBala::~CBala()
{

}
void CBala::Dibujar()
{	

	
      Console::BackgroundColor = ConsoleColor::Black;   	  
   	  Console::ForegroundColor = ConsoleColor::Green;
	  Console::SetCursorPosition(x,y);   cout<<char(24) ;   
	
}
void CBala::Borrar()
{
	char bla=24;

	 Console::BackgroundColor = ConsoleColor::Black;   	  
	 Console::ForegroundColor = ConsoleColor::Black;
     Console::SetCursorPosition(x,y);   cout<<char(24) ;   
	
}
void CBala::Mover()
{
	    Borrar();
    
	    if(y+dy < 7)
          dy=0;

	    y+=dy;
       
    	Dibujar();
	   
}
int CBala::get_x()
{
    return (x);
}
int CBala::get_y()
{
    return (y);
}
int CBala::get_dy()
{
    return (dy);
}