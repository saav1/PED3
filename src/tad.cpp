/************************************************************
	PRUEBA EXAMEN PED
*************************************************************/
#include <iostream>
#include "tavlporo.h"

using namespace std;

int
main()
{
  TAVLPoro arb1;
  TListaPoro lista;

  TPoro p1(1,2,1,(char *) "rojo");
  TPoro p3(1,2,3,(char *) "rojo");
  TPoro p5(1,2,5,(char *) "rojo");
  TPoro p6(1,2,6,(char *) "rojo");
  TPoro p7(1,2,7,(char *) "rojo");
  TPoro p8(1,2,8,(char *) "rojo");
  TPoro p10(1,2,10,(char *)"rojo"); 

  TPoro p25(1,2,25,(char *)"rojo");


  cout << "ListaInsertar: " << lista.Insertar(p1) << endl;
  cout << "ListaInsertar: " << lista.Insertar(p2) << endl;
  cout << "ListaInsertar: " << lista.Insertar(p3) << endl;
  cout << "ListaInsertar: " << lista.Insertar(p4) << endl;
  cout << "Lsta: " << lista << endl;

  cout << "Lista longitud: " << lista.Longitud() << endl;

 
  return 0;
}
