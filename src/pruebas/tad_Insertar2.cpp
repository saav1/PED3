#include <iostream>
#include "tavlporo.h"
using namespace std;



int main(void)
{

  TPoro p5(1, 2, 5, "5");
  TPoro p4(1, 2, 4, "4");
  TPoro p3(1, 2, 3, "3");
  TPoro p2(1, 2, 2, "2");
  TPoro p1(1, 2, 1, "1");
  TAVLPoro avl;
  TAVLPoro avl2;

  avl.Insertar(p5);
  avl.Insertar(p3);  
  avl.Insertar(p4);

  
  cout << "Raiz: " << avl.Raiz() << endl;
  cout << "Altura: " << avl.Altura() << endl;  
  cout << "Nodos: " << avl.Nodos() << endl;
  cout << "Nodos Hoja: " << avl.NodosHoja() << endl;
  cout << "Inorden: " << avl.Inorden() << endl;

  cout << "-----------------------------------" << endl;

  avl2.Insertar(p3);
  avl2.Insertar(p5);
  avl2.Insertar(p4);

  cout << "Raiz: " << avl2.Raiz() << endl;
  cout << "Altura: " << avl2.Altura() << endl;  
  cout << "Nodos: " << avl2.Nodos() << endl;
  cout << "Nodos Hoja: " << avl2.NodosHoja() << endl;
  cout << "Inorden: " << avl2.Inorden() << endl;





return 0;
}
