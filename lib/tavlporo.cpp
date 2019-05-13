//STALYN ALEJANDRO ALCOCER VALENCIA, DNI:20947870E
#include "tavlporo.h"

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