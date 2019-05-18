#ifndef _TAVLPORO_
#define _TAVLPORO_

#include <iostream>
#include <cstdlib>
#include <queue>
#include "tporo.h"
#include "tvectorporo.h"
using namespace std;

class TNodoAVL;
class TAVLPoro;

class TAVLPoro{
friend class TNodoAVL;
//Sobrecarga del operador de salida
friend ostream & operator <<(ostream &, const TAVLPoro &);

private:
	//Puntero al nodo raiz
	TNodoAVL *raiz;
	//AUXILIAR: Devuelve el recorrido en inorden 
	void InordenAux(TVectorPoro &, int &)const;
	//AUXILIAR: Devuelve el recorrido en preorden
	void PreordenAux(TVectorPoro &, int &)const;
	//AUXILIAR: Devuelve el recorrido en postorden
	void PostordenAux(TVectorPoro &, int &)const;
	//AUXILIAR: Equilibrar el árbol AVL
	bool InsertarAux(const TPoro &, bool &);
	//AUXILIAR: EquilibrarIzquierda
	void EquilibrarIzquierda();
	//AUXILIAR: EquilibrarDerecha
	void EquilibrarDerecha();
	//AUXILIAR: Imprimir
	void Imprimir(ostream &os)const;


public:	
	//Constructor por defecto
	TAVLPoro();
	//Constructor de copia
	TAVLPoro(const TAVLPoro &);
	//Destructor
	~TAVLPoro();
	//Sobrecarga del operador asignación
	TAVLPoro & operator = (const TAVLPoro &);

	//Métodos
	//Sobrecarga del operador igualdad
	bool operator == (const TAVLPoro &)const;
	//Sobrecarga del operador desigualdad
	bool operator != (const TAVLPoro &)const;
	//Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
	bool EsVacio()const;
	//Inserta el elemento TPoro en el árbol
	bool Insertar(const TPoro &);
	//Devuelve TRUE si el elemento TPoro está en el árbol
	bool Buscar(const TPoro &)const;
	//Borra un elemento TPoro del árbol AVL
	bool Borrar(const TPoro &);
	//Devuelve la altura del árbol. La altura de un árbol vacío es 0.
	int Altura()const;
	//Devuelve el elemento TPoro raíz del árbol AVL.
	TPoro Raiz()const;
	//Devuelve el número de nodos del árbol. Un árbol vacío son 0 nodos.
	int Nodos()const;
	//Devuelve el número de nodos hoja en el árbol. La raíz puede ser hoja. 
	int NodosHoja()const;

	//Devuelve el recorrido en Inorden sobre un vector 
	TVectorPoro Inorden()const;
	//Devuelve el recorrido en Preorden sobre un vector 
	TVectorPoro Preorden()const;
	//Devuelve el recorrido en Postorden sobre un vecor
	TVectorPoro Postorden()const;
};

class TNodoAVL{
friend class TAVLPoro;
private:
	//El elemento del nodo
	TPoro item;
	//Subárbol izquierdo y derecho
	TAVLPoro iz, de;
	//Factor de equilibrio
	int fe;

public:
	//Contructor por defecto
	TNodoAVL();
	//Constructor copia
	TNodoAVL(const TNodoAVL &);
	//Destructor
	~TNodoAVL();
	//Sobrecarga del operador asignación
	TNodoAVL & operator = (const TNodoAVL &);

};

#endif

/*
........................ACLARACIONES TAVLPoro...........................

1. Se permite amistad entre las clases.

2.TVectorPoro TAVLPoro::Inorden()
       {
             int posicion = 1;
       // Vector del tamaño adecuado para almacenar todos los nodos
             TVectorPoro v(Nodos());
             InordenAux(v, posicion);
             return v;
}
De este modo, se reduce el coste de crear múltiples objetos de tipo 
TVectorPoro, ya que sólo se emplea uno durante todo el cálculo del 
recorrido.	

3. El criterio de ordenación para los elementos TPoro sigue siendo el 
mismo. 

4. Para simplificar los algoritmos, el árbol NO puede contener elementos
con vólumenes repetidos. 

5. El CONSTRUCTOR DE COPIA tiene que realizar una copia exacta 
duplicando todos los nodos del árbol. 

6. El DESTRUCTOR tiene que liberar toda la memoria que ocupe el árbol.

7. Si se asigna un árbol a un árbol no vacío, se destruye el árbol incial.
La ASIGNACIÓN tiene que realizar una copia exacta duplicando todos los
nodos del árbol. 

8. En el operador '==', dos árboles son iguales si poseen los mismos
elementos independientemente de la estructura interna del árbol. 
NO se exige que la estructura de ambos sea la misma. 

9. INSERTAR devuelve TRUE si el elemento se puede insertar y FALSE en 
caso contrario. Por ejemplo, por que el árbol ya existe. 

10. BORRAR devuelve TRUE si el elemento se puede borrar y FALSE en caso
contrario. 
EL CRITERIO DE BORRADO ES SUSTITUIR POR EL MAYOR DE LA IZQUIERDA. 

11. RAIZ devuelve el TPoro raíz del árbol. Si el árbol está vacío, devuelve
un TPoro vacío.

12. El operador de SALIDA muestra recorrido por Inorden del AVL, con el 
formato pedido en el CUARDENILLO 1 para la clase TVectorPoro. 

13. Los tres recorridos devuelven un vector (TVectorPoro) en la que todas
las posiciones están ocupadas por los elementos del árbol. No pueden quedar
posiciones sin asignar. Si el árbol está vacío, se devuelve un vector vacío
-vector dimension 0-
*/
