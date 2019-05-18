#include <iostream>
#include "tavlporo.h"
using namespace std;



int main(void)
{

  TPoro p6(1, 2, 6, "6");
  TPoro p5(1, 2, 5, "5");
  TPoro p4(1, 2, 4, "4");
  TPoro p3(1, 2, 3, "3");
  TPoro p2(1, 2, 2, "2");
  TPoro p1(1, 2, 1, "1");
  TAVLPoro avl;
  TAVLPoro avl2;

  avl.Insertar(p1);
  avl.Insertar(p2);  
  avl.Insertar(p3);
  avl.Insertar(p4);
  avl.Insertar(p5);
  avl.Insertar(p6);
  
  cout << "Raiz: " << avl.Raiz() << endl;
  cout << "Altura: " << avl.Altura() << endl;  
  cout << "Nodos: " << avl.Nodos() << endl;
  cout << "Nodos Hoja: " << avl.NodosHoja() << endl;
  cout << "Inorden: " << avl.Inorden() << endl;
  cout << "-----------------------------------" << endl;

return 0;
}
