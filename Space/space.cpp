// space.cpp : main project file.

#include "stdafx.h"

using namespace System;

int main(array<System::String ^> ^args)
{
  CJuego *Juego= new CJuego();
  System::Random ^r = gcnew System::Random((int)System::DateTime::Now.Ticks);
  int cont=0,s=60;


  while(!Juego->get_fin())
	{

    Juego->Insertar_Elementos(r,&cont,&s);


       if(kbhit())
		   Juego->Teclado(&s);

  	   Juego->Mover_Todo(&s);
 	   cont++;
       Sleep(s);
	}

	delete Juego;
    
	return 0;

}
