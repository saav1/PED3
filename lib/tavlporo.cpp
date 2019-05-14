//STALYN ALEJANDRO ALCOCER VALENCIA, DNI:20947870E
#include "tavlporo.h"


/*.................................TNODOAVL...........................................*/
//Constructor TNodo
TNodoAVL::TNodoAVL(){
	this->item = TPoro();
	this->iz = TAVLPoro();
	this->de = TAVLPoro();
	this->fe = 0;
}

//Constructor de copia
TNodoAVL::TNodoAVL(const TNodoAVL &nodo){
	if(this != &nodo){ //Si es diferente llamo al destructor.
		(*this).~TNodoAVL();
		this->item = TPoro(nodo.item);
		this->iz = nodo.iz;
		this->de = nodo.de;
	}	
	
}

//Destructor
TNodoAVL::~TNodoAVL(){
	this->item = TPoro();
	this->iz = TAVLPoro();
	this->de = TAVLPoro();
	this->fe = 0;
}

//Sobrecarga del operador asignación
TNodoAVL & TNodoAVL::operator = (const TNodoAVL &nodo){
	if(this != &nodo){
		(*this).~TNodoAVL();
		this->item = TPoro(nodo.item);
		this->iz = nodo.iz;
		this->de = nodo.de;
	}
	return *this;
}


/*.................................TAVLPORO...........................................*/

//Constructor por defecto
TAVLPoro::TAVLPoro(){
	this->raiz = NULL;
}

//Constructor de copia 
TAVLPoro::TAVLPoro(const TAVLPoro &avl){
	if(this != &avl){
		(*this).~TAVLPoro();
		this->raiz = new TNodoAVL(*avl.raiz);
	}
}

//Destructor 
TAVLPoro::~TAVLPoro(){
	if(this->raiz != NULL){
		delete raiz;
		this->raiz = NULL;
	}
	this->raiz = NULL;
}

//Sobrecarga del operador de asignación
TAVLPoro & TAVLPoro::operator = (const TAVLPoro &avl){
	if(this != &avl){
		(*this).~TAVLPoro();
		this->raiz = new TNodoAVL(*avl.raiz);
	}
	return *this;
}

//Sobrecarga del operador igualdad
bool TAVLPoro::operator == (const TAVLPoro &avl)const{
	bool iguales = ((*this).Nodos() == avl.Nodos()) ? true : false;
	if(iguales){
		TVectorPoro v1, v2;
		v1 = avl.Inorden();
		v2 = (*this).Inorden();
		for(int i = 0; i <= v1.Longitud() && iguales; i++){
			iguales = false;
			for(int j = 1; j <= v2.Longitud(); j++){
				iguales = true;
			}
		}
	}
	return iguales;
}

//Sobrecarga del operador desigualdad
bool TAVLPoro::operator != (const  TAVLPoro &avl)const{
	return !(*this == avl);
}

//Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
bool TAVLPoro::EsVacio()const{
	if(this->raiz == NULL)return true;
	return false;
}

//Inserta el elemento TPoro en el árbol
bool TAVLPoro::Insertar(const TPoro &poro){
	return 1;
}

//Devuelve TRUE si el elemento TPoro está en el árbol
bool TAVLPoro::Buscar(const TPoro &poro)const{
	if(this->raiz == NULL) return false;
	if((*this).Raiz() == poro) return true;

	if(poro.Volumen() < (*this).raiz->item.Volumen()) return (*this).raiz->iz.Buscar(poro);
	else return (*this).raiz->de.Buscar(poro);

}

//Borra un elemento TPoro del árbol AVL
bool TAVLPoro::Borrar(const TPoro &poro){
	return 1;
}

//Devuelve la altura del árbol. La altura de un árbol vacío es 0.
int TAVLPoro::Altura()const{
	int i = 0;
	if(!(*this).EsVacio()){
		i = 1;
		if((*this).raiz->iz.Altura() > (*this).raiz->de.Altura()){
			i += (*this).raiz->iz.Altura();
		}else{
			i += (*this).raiz->de.Altura();
		}
	}
	return i;
}

//Devuelve el elemento TPoro raíz del árbol AVL.
TPoro TAVLPoro::Raiz() const{
	TPoro poro;
	if(!(*this).EsVacio()) poro = raiz->item;
	return poro;
}

//Devuelve el número de nodos del árbol. Un árbol vacío son 0 nodos. 
int TAVLPoro::Nodos()const{
	int i = 0;
	if(!(*this).EsVacio()){
		i++;
		if((*this).raiz->iz.EsVacio() && (*this).raiz->de.EsVacio())return i;
		else{
			i += (*this).raiz->iz.Nodos() + (*this).raiz->de.Nodos();
			return i;
		}
	}
	return i;
}

//Devuelve el número de nodos hoja en el árbol. La raíz puede ser hoja. 
int TAVLPoro::NodosHoja()const{
	int i = 0;
	if(!(*this).EsVacio()){
		if((*this).raiz->iz.EsVacio() && (*this).raiz->de.EsVacio())return i;
		else return ((*this).raiz->iz.NodosHoja() + (*this).raiz->de.NodosHoja());
	}
	return i;
}

//Devuelve el recorrido en Inorden
TVectorPoro TAVLPoro::Inorden()const{
	int pos = 1;
	TVectorPoro v((*this).Nodos());
	InordenAux(v, pos);
	return v;
}

void TAVLPoro::InordenAux(TVectorPoro &v, int &pos)const{
	if(!(*this).EsVacio()){
		(*this).raiz->iz.InordenAux(v, pos);
		v[pos++] = (*this).Raiz();
		(*this).raiz->de.InordenAux(v, pos);
	}
}



//Devuelve el recorrido en Preorden
TVectorPoro TAVLPoro::Preorden()const{
	int pos = 1;
	TVectorPoro v((*this).Nodos());
	InordenAux(v, pos);
	return v;
}

void TAVLPoro::PreordenAux(TVectorPoro &v, int &pos)const{
	if(!(*this).EsVacio()){
		v[pos++] = (*this).Raiz();
		(*this).raiz->iz.PreordenAux(v, pos);
		(*this).raiz->de.PreordenAux(v, pos);
	}
}

//Devuelve el recorrido en Postorden
TVectorPoro TAVLPoro::Postorden()const{
	int pos = 1;
	TVectorPoro v((*this).Nodos());
	InordenAux(v, pos);
	return v;
}


void TAVLPoro::PostordenAux(TVectorPoro &v, int &pos)const{
	if(!(*this).EsVacio()){
		(*this).raiz->iz.PostordenAux(v, pos);
		(*this).raiz->de.PostordenAux(v, pos);
		v[pos++] = (*this).Raiz();
	}
}

