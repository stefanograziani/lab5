#include "../include/headers/clase.h"
#include "../include/"

void Clase::setNombre(string nombre){
  this->nombre = nombre;
};
void Clase::setCodigo(string codigo){
  this->codigo = codigo;
};
void Clase::setUrl(string url){
  this->url = url;
};
void Clase::setFechaInicio(DtFecha fecha){
  this->fechaInicio = fecha;
};
void Clase::setFechaFin(DtFecha){
  this->fechaFin = fecha;
};
tipoClase Clase::getTipo(){
  return tipo;
};
string Clase::getNombre(){
  return nombre;
};
string Clase::getCodigo(){
  return codigo;
};
string Clase::getUrl(){
  return url;
};
DtFecha Clase::getFechaInicio(){
  return fechaInicio;
};
DtFecha Clase::getFechaFin(){
  return fechaFin;
};
void Clase::visualizar(Estudiante){//sacado del diagrama de comunicacion de confirmarAsistencia()
  //puse las funciones member find y add como si existieran, no vi nada de la implementacion de coleccion que nos dieron
  bool existe = estParticipantes.member(email);
  if existe
    Estudiante *repro = find(email);
  else
    EstCla *repro = new EstCla();
    estParticipantes.add(repro);
};
