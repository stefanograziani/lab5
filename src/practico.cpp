#include "../include/practico.h"
bool Practico::estaHabilitado(string s){
  return true;
};
Practico::Practico(){
  this->setTipo(practico); //invariable, una clase de tipo practico tiene en el atributo "tipo" el valor "practico", se otroga este valor cuando se la crea, es correcto esto?
};
Practico::~Practico(){

};
