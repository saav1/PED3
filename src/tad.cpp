#include <iostream>
#include "tavlporo.h"
using namespace std;



int
main(void)
{
  TPoro p5(5, 5, 5, "5");
  TPoro p4(1, 2, 4, "4");
  TPoro p3(1, 2, 3, "3");

  cout << "---" << endl;

  TAVLPoro avl;
  avl.Insertar(p5);
  avl.Insertar(p4);
  avl.Insertar(p3);

}
