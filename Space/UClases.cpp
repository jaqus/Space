
#include "stdafx.h"
#include "iostream"

using namespace System;
using namespace std;

/////////////////////ctanque

CTanque::CTanque()
{
  x=55;
  y=45;
  dx=1;
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
 Console::BackgroundColor = ConsoleColor::DarkBlue;   	  
 Console::ForegroundColor = ConsoleColor::Gray;
 Console::SetCursorPosition(x+6,y); cout<<"___"; 
 Console::SetCursorPosition(x,y+1); cout<<("_____/_o_\\_____");
 Console::SetCursorPosition(x-2,y+2); cout<<(" (==(/_______\\)==) "); 
 Console::SetCursorPosition(x+1,y+3); cout<<(" \\==\\/ \\/==/ ");
}
void CTanque::Borrar()
{
 Console::BackgroundColor = ConsoleColor::DarkBlue;   	  
 Console::ForegroundColor = ConsoleColor::DarkBlue;
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
			 Console::BackgroundColor = ConsoleColor::DarkBlue;   	  
             
			 Console::SetCursorPosition(x+1,y); cout<<(",--."); 
			 Console::SetCursorPosition(x,y+1); cout<<("| oo |");
			 Console::SetCursorPosition(x,y+2); cout<<("| ~~ |"); 
			 Console::SetCursorPosition(x,y+3); cout<<("|/\\/\\|");
 

}
void CEnemigo::Borrar()
{
	Console::BackgroundColor = ConsoleColor::DarkBlue;   	  
	Console::ForegroundColor = ConsoleColor::DarkBlue;
	Console::SetCursorPosition(x+1,y); cout<<(",--."); 
	Console::SetCursorPosition(x,y+1); cout<<("| oo |");
	Console::SetCursorPosition(x,y+2); cout<<("| ~~ |"); 
	Console::SetCursorPosition(x,y+3); cout<<("|/\\/\\|");



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

	
      Console::BackgroundColor = ConsoleColor::DarkBlue;   	  
   	  Console::ForegroundColor = ConsoleColor::Green;
	  Console::SetCursorPosition(x,y);   cout<<char(24) ;   
	
}
void CBala::Borrar()
{
	char bla=24;

	 Console::BackgroundColor = ConsoleColor::DarkBlue;   	  
	 Console::ForegroundColor = ConsoleColor::DarkBlue;
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
///////////////////////////////////////////
/////////////////////CPac
CPac::CPac()
{
 x = 114;
 y = 40;
 dx = -1;
 dy = -4;
 tipo = 1;
 
 ///Actpac
 System::Random ^r = gcnew System::Random(System::DateTime::Now.Ticks);
 py=8;
 px=r->Next(15,100);
 pdy=1;
 pdx=1;
 velocidad=r->Next(50,65);
}
CPac::~CPac()
{
}
void CPac::Dibujar()
{
	
	Console::BackgroundColor = ConsoleColor::DarkBlue;   	  
	Console::ForegroundColor = ConsoleColor::White;

        switch(tipo)
	    {
				case 1:
					  { 
						Console::SetCursorPosition(x,y);     cout<<("  .---. ");
						Console::SetCursorPosition(x,y+1);   cout<<(" '-._* \\"); 
						Console::SetCursorPosition(x,y+2);   cout<<("  _.-' /");
						Console::SetCursorPosition(x,y+3);   cout<<(" '----' ");
						break;
					  }
				case 2:
					  {
						Console::SetCursorPosition(x,y);     cout<<("  .---. ");
						Console::SetCursorPosition(x,y+1);   cout<<(" '___* \\"); 
						Console::SetCursorPosition(x,y+2);   cout<<(" :     /");
						Console::SetCursorPosition(x,y+3);   cout<<(" '----' ");
						break;
					  }
				case 3:
					  {
						Console::SetCursorPosition(x,y);     cout<<(" .---. ");
						Console::SetCursorPosition(x,y+1);   cout<<("/ *_.-'"); 
						Console::SetCursorPosition(x,y+2);   cout<<("\\ '-._");
						Console::SetCursorPosition(x,y+3);   cout<<(" '----'");
						break;
					  }
				case 4:
					  {
						Console::SetCursorPosition(x,y);     cout<<(" .---. ");
						Console::SetCursorPosition(x,y+1);   cout<<("/ *___'"); 
						Console::SetCursorPosition(x,y+2);   cout<<("\\     ;");
						Console::SetCursorPosition(x,y+3);   cout<<(" '----'");
						break;
					  }

		}


}
void CPac::Borrar()
{

	Console::BackgroundColor = ConsoleColor::DarkBlue;   	  
	Console::ForegroundColor = ConsoleColor::DarkBlue;
	
		switch(tipo)
	    {
				case 1:
					  { 
						Console::SetCursorPosition(x,y);     cout<<("  .---. ");
						Console::SetCursorPosition(x,y+1);   cout<<(" '-._* \\"); 
						Console::SetCursorPosition(x,y+2);   cout<<("  _.-' /");
						Console::SetCursorPosition(x,y+3);   cout<<(" '----' ");
						break;
					  }
				case 2:
					  {
						Console::SetCursorPosition(x,y);     cout<<("  .---. ");
						Console::SetCursorPosition(x,y+1);   cout<<(" '___* \\"); 
						Console::SetCursorPosition(x,y+2);   cout<<(" :     /");
						Console::SetCursorPosition(x,y+3);   cout<<(" '----' ");
						break;
					  }
				case 3:
					  {
						Console::SetCursorPosition(x,y);     cout<<(" .---. ");
						Console::SetCursorPosition(x,y+1);   cout<<("/ *_.-'"); 
						Console::SetCursorPosition(x,y+2);   cout<<("\\ '-._");
						Console::SetCursorPosition(x,y+3);   cout<<(" '----'");
						break;
					  }
				case 4:
					  {
						Console::SetCursorPosition(x,y);     cout<<(" .---. ");
						Console::SetCursorPosition(x,y+1);   cout<<("/ *___'"); 
						Console::SetCursorPosition(x,y+2);   cout<<("\\     ;");
						Console::SetCursorPosition(x,y+3);   cout<<(" '----'");
						break;
					  }

		}


}
void CPac::Mover()
{
   
  Borrar();

     
     if(x+dx+6<LARGO && x+dx>0)
	   {
		  x+=dx;
		  if(dx < 0)
		     tipo=1;
		  else
			 tipo=3;
	   }
     if((x+dx+6 ==LARGO || x+dx==0) && y+dy>7)
       {
	    y+=dy;
	    dx*=-1;

	    if(x+dx == 2)
	       tipo=3;
	    else
	    if(x+dx+6 == 128)
	       tipo=1; 
      }

  Dibujar();


}
void CPac::Come()
{
  if(dx < 0)
     tipo = 2;
  if(dx > 0)
     tipo = 4;

  cout<< char(7);
     
     Dibujar();
	 Sleep(55);

}
void CPac::Dibujar_Actpac()
{
	
	Console::BackgroundColor = ConsoleColor::DarkBlue;   	  
	Console::ForegroundColor = ConsoleColor::Black;
	Console::SetCursorPosition(px,py); cout<< char(2);
}
void CPac::Borrar_Actpac()
{
	Console::BackgroundColor = ConsoleColor::DarkBlue;   	  
	Console::ForegroundColor = ConsoleColor::DarkBlue;
	Console::SetCursorPosition(px,py); cout<< char(2);
}
void CPac::Mover_Actpac()
{
   
	    Borrar_Actpac();
    
		if(pdy != 0)
		{
			if(py+pdy < ALTO-1)
			  {		
				py+=pdy;
			    Sleep(velocidad);  
    		    Dibujar_Actpac();
		      }
			else
			{
			  pdy=50;
			  py=0;
			  px=0; 
			  Borrar_Actpac();
			}


		}

	    

}
int CPac::get_x()
{
  return x;
}
int CPac::get_y()
{
  return y;
}
int CPac::get_px()
{
  return px;
}
int CPac::get_py()
{
  return py;
}



///////////////////////////////////////////
//////////////////// CJuego

CJuego::CJuego()
{
  Tanque	= new CTanque();
  Enemigo	= new CEnemigos();
  Pacman	= new CPac();  
 
  nivel=1;
  puntos=fin=p=con=act=z=0;
  d=150;

  premio=0;
  Tablero(LARGO,ALTO);
}
CJuego::~CJuego()
{
	delete Tanque;
	delete Enemigo;
	delete Pacman;
 
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
			Console::BackgroundColor = ConsoleColor::DarkBlue;   	  
		cout<<(" ");
	  }	
     }

 Datos();
 Tanque->Dibujar();	      

    
}


void CJuego::Datos()
{
	Console::ForegroundColor = ConsoleColor::White;
   	Console::SetCursorPosition(2,2); cout<<" Nivel: "<< nivel;
	Console::SetCursorPosition(2,3); cout<<" Puntos: "<< puntos; 
	
	if(premio)
	{Console::SetCursorPosition(118,3); cout<< char(2); }
	else
	{Console::SetCursorPosition(118,3); cout<<(" "); }


	int cont;
	for(int i=0;i<Enemigo->get_n();i++)
	
	 
	if(con == 5)
	{Pacman->Dibujar_Actpac(); act=1; con++;}

	

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
		 
		if(premio)
		{  
			if(tecla == 'P' || tecla == 'p')
		    {		
              Pacman->Dibujar(); 			
		      p++;
		    }
		}
		if(tecla == -32)
		  {
		   tecla = getch();
		   if(tecla == FD)  
			  Tanque->Derecha();
		   if(tecla == FI)
			  Tanque->Izquierda();
		  }



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


	  if(d<=*cont)
	    {
			Enemigo->Insertar_Enemigos(r);
		    if(*s>5)
			   *s-=5;
    	        *cont=0;
		}
}
void CJuego::Mover_Todo(int *s)
{
	Datos();
    Colision(s);
	if (nivel > 10)
		You_Win(LARGO,ALTO); 
	if(!fin)
	{
	 if(Enemigo->get_n())
 	    Enemigo->Mover_Enemigos();
	 if(Tanque->get_n())
  	    Tanque->Mover_Balas();
	}
	if(act)
	  if(Pacman->get_py() !=0 )
		  Pacman->Mover_Actpac();
	  else
	     act=0;
	  
	if(p)
	{
	   Pacman->Mover();
	   if(Pacman->get_x() == 1 && Pacman->get_y() == 8)
	     {
		  Pacman->Borrar();
		  delete Pacman;
		  p=premio=0;
	     }
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
			  if( (xe+6>=xb && xe<=xb+6 ) && (ye+4>=yb && ye<=yb+4) )
				return true;
			  else
				return false;
			  break;
			 }
	   case 3:
			 {
			  if( (xe+17>=xb && xe<=xb ) && (ye+4>=yb && ye<=yb) )
				return true;
			  else
				return false;
			  break;
			 }

	}


}
void CJuego::Colision(int *s)
{
	if(Enemigo->get_n()> 0)
	{  for(int i=0;i<Enemigo->get_n();i++)
       {  
		  if (Enemigo->get_vy(i)+8 > 45)
		      Game_Over(LARGO,ALTO,i);

          
		  if(act)
		  {  
			  if ( Siente_ElChoque( Tanque->get_x() ,Tanque->get_y () ,Pacman->get_px(), Pacman->get_py() ,3 ) )
		         {
				   premio=1;
				   act=0;
				   Pacman->Borrar_Actpac();
				   Tanque->Dibujar();
				 }
		  
		  }		
		  
		  if(p && premio)
		  {  
			  if ( Siente_ElChoque( Enemigo->get_vx(i),Enemigo->get_vy(i),Pacman->get_x(),Pacman->get_y(),2 ) )
		         {
				   Actualizar_datos(i);
			       Enemigo->Eliminar_Enemigos(i);
				   Pacman->Come();
		           if(*s<100)
				   *s+=5;
		         }
		  
		  }
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
		      } 
		  }


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


  strcpy(go[0],"            _____ _   _ _   _  ___ ______ ___________  _____             ");  
  strcpy(go[1],"           |_   _| \\ | | | | |/ _ \\|  _  \\  ___| ___ \\/  ___|        ");   
  strcpy(go[2],"             | | |  \\| | | | / /_\\ \\ | | | |__ | |_/ /\\ `--.         ");  
  strcpy(go[3],"             | | | . ` | | | |  _  | | | |  __||    /  `--. \\           ");  
  strcpy(go[4],"            _| |_| |\\  \\ \\_/ / | | | |/ /| |___| |\\ \\ /\\__/ /      ");  
  strcpy(go[5],"            \\___/\\_| \\_/\\___/\\_| |_/___/ \\____/\\_| \_|\\____/     ");  
  for (int i=6;i<17;i++)
  strcpy(go[i],"                                                                       ");

 
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
  getch();
  
  fin=1;
  i=Enemigo->get_n();
}
void CJuego::You_Win(int largo,int alto)
{
  Console::Clear();
  Console::ForegroundColor = ConsoleColor::White;
  Console::SetCursorPosition ((largo/2 - 6),alto/2);cout<<(" YOU WIN ");
  getch();

  fin=1;

}
int CJuego::get_fin()
{
 return fin;
}

	     
	

 