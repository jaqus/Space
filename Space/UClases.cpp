
#include "stdafx.h"
#include "iostream"



using namespace System;
using namespace std;

///////////////////////////////////////////
//////////////////// CJuego

CJuego::CJuego()
{
  Tanque	= new CTanque();
  Enemigo	= new CEnemigos();

 
  nivel=1;
  puntos=fin=con=z=0;
  d=150;


  Tablero(LARGO,ALTO);
}
CJuego::~CJuego()
{
	delete Tanque;
	delete Enemigo;

 
}
void CJuego::Tablero(int largo, int alto)
{

    Console::SetWindowSize(largo,alto);
	Console::SetBufferSize(largo,alto);
	Console::CursorVisible = false;
  
	Presentacion();
	Console::Clear();


    Console::ForegroundColor = ConsoleColor::White;
    int x=LARGO/2-24;
	int y=ALTO/2 -6;
	Console::SetCursorPosition(x,y);     cout<<(" .d888888   888888ba   88888888b    dP    dP  .88888.  dP     dP ");
	Console::SetCursorPosition(x,y+1);   cout<<("d8'    88   88    `8b  88           Y8.  .8P d8'   `8b 88     88"); 
	Console::SetCursorPosition(x,y+2);   cout<<("88aaaaa88a a88aaaa8P' a88aaaa        Y8aa8P  88     88 88     88");
	Console::SetCursorPosition(x,y+3);   cout<<("88     88   88   `8b.  88              88    88     88 88     88");
    Console::SetCursorPosition(x,y+4);   cout<<("88     88   88     88  88              88    Y8.   .8P Y8.   .8P  ");
    Console::SetCursorPosition(x,y+5);   cout<<("88     88   dP     dP  88888888P       dP     `8888P'  `Y88888P'  ");

    Console::SetCursorPosition(x,y+8);     cout<<(" 888888ba   88888888b  .d888888  888888ba  dP    dP    .d8888ba   ");
    Console::SetCursorPosition(x,y+9);     cout<<(" 88    `8b  88        d8'    88  88    `8b Y8.  .8P    `8'   `8b  ");
    Console::SetCursorPosition(x,y+10);     cout<<("a88aaaa8P' a88aaaa    88aaaaa88a 88     88  Y8aa8P          .d8'  ");
    Console::SetCursorPosition(x,y+11);     cout<<(" 88   `8b.  88        88     88  88     88    88          d8P'   ");
    Console::SetCursorPosition(x,y+12);    cout<<(" 88     88  88        88     88  88    .8P    88          ""      ");
    Console::SetCursorPosition(x,y+13);    cout<<(" dP     dP  88888888P 88     88  8888888P     dP          oo      ");
    getch();
	Console::Clear();

  for(int i=0;i<largo;i++)
     {
	  for(int j=0;j<alto;j++)
	  { Console::SetCursorPosition(i,j);
	     if(j==7)
		{
			Console::ForegroundColor = ConsoleColor::Yellow;
	     cout<<char(219);
		}
		else
			Console::BackgroundColor = ConsoleColor::Black;   	  
		cout<<(" ");
	  }	
     }

 Datos();
 Tanque->Dibujar();	      

    
}


void CJuego::Datos()
{
	Console::ForegroundColor = ConsoleColor::White;
   	Console::SetCursorPosition(2,3); cout<<" Nivel: "<< nivel;
	Console::SetCursorPosition(2,4); cout<<" Puntos: "<< puntos; 
	


	

}
void CJuego::Actualizar_datos(int i)
{

    switch (Enemigo->get_tipo(i))
								{
 								 case 1: puntos+=30;break;
								 case 2: puntos+=10;break;
								 case 3: puntos+=20;break;
								}
							
 	if(puntos>0 && puntos%50 == 0)
	  {  
		nivel++;
		z++;
	  }
    if(Enemigo->get_vy(i) < 24)
		con++;

}

void CJuego::Teclado(int *s)
{char tecla;

        
 	    tecla = getch();
		
		if(tecla == ESP)
		  {
		   Tanque->Insertar_Balas();
		   if(*s>5)
		   *s-=5;
          }
		 
		
		if(tecla == -32)
		  {
		   tecla = getch();
		   if(tecla == FD)  
			  Tanque->Derecha();
		   if(tecla == FI)
			  Tanque->Izquierda();
		   if(tecla == FA)  
			  Tanque->Arriba();
		   if(tecla == FAB)
			  Tanque->Abajo();
		  }



}
void CJuego::Clonar(System::Random ^r,int *cont,int *s)
{
	
	Enemigo->Insertar_Enemigos(r);
		    if(*s>5)
			   *s-=5;
    	        *cont=0;

}
void CJuego::Insertar_Elementos(System::Random ^r,int *cont, int *s)
{


	  if(z && d>8)
	    { 
   		 d-=10;	
	     z=0;
	    }
	  if(d<8 )
		 d=8;


	  if(d<=*cont){
		  Clonar(r,cont,s);
			if(nivel>15)
				Clonar(r,cont,s);
			if (nivel>28)
			{
				Clonar(r,cont,s);
				Clonar(r,cont,s);
				Clonar(r,cont,s);
			}
	  }
}
void CJuego::Mover_Todo(int *s)
{
	Datos();
    Colision(s);
	if (nivel > 30)
		You_Win(LARGO,ALTO);


	if(!fin)
	{
	 if(Enemigo->get_n())
 	    Enemigo->Mover_Enemigos();
	 if(Tanque->get_n())
  	    Tanque->Mover_Balas();
	}
	
	  
	
}
bool CJuego::Siente_ElChoque(int xe,int ye, int xb, int yb,int caso)
{

	switch(caso)
    {
	   case 1:
			 {
			  if( (xe+6>=xb && xe<=xb ) && (ye+4>=yb && ye<=yb) )
				return true;
			  else
				return false;
			  break;
			 }
	   case 2:
			 {
			  if( (xe+8>=xb && xe<=xb+17 ) && (ye+4>=yb && ye<=yb+4) )
				return true;
			  else
				return false;
			  break;
			 }


	}


}
void CJuego::Colision(int *s)
{
	bool chq=false; 

	if(Enemigo->get_n()> 0)
	{  for(int i=0;i<Enemigo->get_n();i++)
       {  
		  if (Enemigo->get_vy(i)+8 > 45)
		      Game_Over(LARGO,ALTO,i);

          
		 		  
		  
		  for(int j=0;j<Tanque->get_n();j++)
	      {
  		   if ( Siente_ElChoque( Enemigo->get_vx(i),Enemigo->get_vy(i),Tanque->get_vx(j),Tanque->get_vy(j) ,1) )
		      {   
   				  Actualizar_datos(i);
				  Enemigo->Eliminar_Enemigos(i);
				  Tanque->Eliminar_Balas(j); 
	              if(*s<100)
				   *s+=5;
				  j=Tanque->get_n();
 				  chq=true;
		      } 
		  }

		  if(chq)
			  continue;

		  if ( Siente_ElChoque( Enemigo->get_vx(i),Enemigo->get_vy(i),Tanque->get_x(),Tanque->get_y() ,2) )
		       Game_Over(LARGO,ALTO,i);
		


	  }
	}

}
void CJuego::Presentacion()
{

 
  intro(LARGO/2-35,ALTO/2-4);

}
void CJuego::impdiag(int posx,int posy,int x,int y,char go[ ][70],int color)
{
	switch(color) 
	{case 1:System::Console::ForegroundColor=ConsoleColor::White;break;  
	case 2:System::Console::ForegroundColor=ConsoleColor::Gray;break;  
	case 3:System::Console::ForegroundColor=ConsoleColor::Blue;break;
		}
 
	 while(y>=0 && x<70)
	 {
		 if (go[y][x]!=' ')
		 {
			 Console::SetCursorPosition(posx+x,posy+y);
			 cout<< go[y][x];
		 }
		x++;
		y--;
	 }
}
void CJuego::intro(int x,int y)
{ char go[17][70];
  int color =1,color2,tmp=0,trama=10;
  System::Console::Clear();


  strcpy(go[0],"            _______..______      ___       ______  _______               ");  
  strcpy(go[1],"           /       ||   _  \\    /   \\     /      ||   ____|              ");   
  strcpy(go[2],"          |   (----`|  |_)  |  /  ^  \\   |  ,----'|  |__                 ");  
  strcpy(go[3],"           \\   \\    |   ___/  /  /_\\  \\  |  |     |   __|                ");  
  strcpy(go[4],"       .----)   |   |  |     /  _____  \\ |  `----.|  |____               ");  
  strcpy(go[5],"       |_______/    | _|    /__/     \\__\\ \\______||_______|              ");  
  for (int i=6;i<17;i++)  
  strcpy(go[i],"                                                                         ");

 
	while(!kbhit())
	{
	   for (int i=0;i<17;i++)
	   {
	     impdiag(x,y,0,i,go,color);
	     if(tmp%trama==0)
	     {color++;tmp=0;}
	     if(color==4)
	       color=1;
	     tmp++;
	  }

    for (int i=0;i<70;i++) 
    {
      impdiag(x,y,i,16,go,color);
      if(tmp%trama==0)
      {color++;tmp=0;}
       if(color==4)
          color=1;
       tmp++;
    }

Console::SetCursorPosition(79,24) ;
Sleep(70);
}
getch();
}



void CJuego::Game_Over(int largo, int alto, int &i)
{
  Console::Clear();
  Console::ForegroundColor = ConsoleColor::White;
  Console::SetCursorPosition ((largo/2 - 6),alto/2);cout<<(" GAME OVER ");
  Sleep(200);

  
  fin=1;
  i=Enemigo->get_n();
}
void CJuego::You_Win(int largo,int alto)
{
  Console::Clear();
  Console::ForegroundColor = ConsoleColor::White;
  Console::SetCursorPosition ((largo/2 - 6),alto/2);cout<<(" YOU WIN ");
  Sleep(200);


  fin=1;

}
int CJuego::get_fin()
{
 return fin;
}
