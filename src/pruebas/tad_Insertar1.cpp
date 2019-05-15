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

  avl.Insertar(p5);
  avl.Insertar(p4);  
  avl.Insertar(p3);
  avl.Insertar(p2);
  avl.Insertar(p1);
  
  cout << "Altura: " << avl.Altura() << endl;  
  cout << "Nodos: " << avl.Nodos() << endl;
  cout << "Nodos Hoja: " << avl.NodosHoja() << endl;




return 0;
}
