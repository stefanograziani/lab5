#include "../include/teorico.h"

Teorico::Teorico(){
  this->setTipo(teorico); //invariable, una clase de tipo teorico tiene en el atributo "tipo" el valor "teorico", se otroga este valor cuando se la crea, es correcto esto?
};
void Teorico::setAsistentes(int a){
  this->asistentes = a;
};
int Teorico::getAsistentes(){
  return asistentes;
};
int Teorico::calcularAsistentes(){

};
void Teorico::setNombre(string n){
  this->setNombre(n);
};
Teorico::~Teorico(){

};
