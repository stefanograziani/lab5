#include "../include/usrCla.h"
#include "../include/dtFecha.h"
#include "../include/estudiante.h"
#include "../include/visualizacion.h"

const dtFecha fechaNula(0,0,0,0,0,0);

UsrCla::UsrCla(){};

void UsrCla::setEstudiante(Estudiante* e){ this->est = e;};
Estudiante* UsrCla::getEst(){ return est;};

void UsrCla::setClase(Clase* c){ this->clase = c;};
Clase* UsrCla::getClase(){ return clase;};

void UsrCla::setVisualizacion(Visualizacion* v){
  vis.insert(vis.end(),v);
};

//Visualizacion* UsrCla::getVis();

//int UsrCla::getCodigoClase(){};
//string UsrCla::getEmailUser(){};

void UsrCla::marcarFin(dtFecha fecha){//como es clase en vivo solo hay una visualizacion, solo marco el principio de la lista
  if((*vis.begin())->getFechaFinVis() == fechaNula)
    (*vis.begin())->setFechaFinVis(fecha);
  (*vis.begin())->setEnVivo(true);
};
//void UsrCla::iniciarVis(){};
//UsrCla::~UsrCla(){};