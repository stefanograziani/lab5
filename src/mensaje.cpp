#include "../include/mensaje.h"

Mensaje::Mensaje(){

};
void Mensaje::setId(int id){
  this->id = id;
};
void Mensaje::setContenido(string cont){
  this->contenido = cont;
};
void Mensaje::setFecha(dtFecha fecha){
  this->fecha = fecha;
};
void Mensaje::setEnRespuestaA(Mensaje *ms){
  this->enRespuestaA = ms;
};
void Mensaje::setClase(Clase* c){
  this->clase = c;
};
Clase* Mensaje::getClase(){
  return clase;
};
int Mensaje::getId() const {
  return id;
};
string Mensaje::getContenido(){
  return contenido;
};
dtFecha Mensaje::getFecha(){
  return fecha;
};
Mensaje* Mensaje::getEnRespuestaA(){
  return enRespuestaA;
};
Mensaje::~Mensaje(){

};
bool Mensaje::operator<(const Mensaje &right){
  return id < right.getId();
}; //si colecciones se implementan con set esto es necesario
