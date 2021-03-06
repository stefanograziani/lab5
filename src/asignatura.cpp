#include "../include/asignatura.h"
#include "../include/estudiante.h"
#include "../include/dtFecha.h"

const dtFecha fechaNula(0,0,0,0,0,0);

Asignatura::Asignatura(){//inicializo las colecciones vacias
  map<string,Estudiante*>* a = new map<string,Estudiante*>;
  this->inscriptos = a;
  map<string,Clase*>* b = new map<string,Clase*>;
  this->clases = b;
  map<string,Rol*>* c = new map<string,Rol*>;
  this->docentes = c;
};

void Asignatura::setCodigo(string c){ this->codigo = c;};
string Asignatura::getCodigo() const{ return codigo;};

void Asignatura::setNombre(string n){ this->nombre = n;};
string Asignatura::getNombre()const{ return nombre;};

void Asignatura::setTeorico(bool t){  this->teorico = t;};
bool Asignatura::getTeorico() const{ return teorico;};

void Asignatura::setPractico(bool p){ this->practico = p;};
bool Asignatura::getPractico() const{ return practico;};

void Asignatura::setMonitoreo(bool m){ this->monitoreo = m;};
bool Asignatura::getMonitoreo() const{  return monitoreo;};



void Asignatura::agregarRol(Rol* rol){
  this->docentes->insert(pair<string,Rol*>(rol->getDoc()->getEmail(),rol));
};

map<string,Estudiante*>* Asignatura::getInscriptos(){
  return inscriptos;
};
map<string,Clase*>* Asignatura::getClases(){
  return clases;
};

set<dtClase> Asignatura::clasesEnVivo(){
  set<dtClase> nuevo;
  for(auto it = this->clases->begin(); it!=clases->end(); ++it){
    if(it->second->getFechaFin() == fechaNula){
      dtClase* dt = new dtClase();
      dt->setNombre(it->second->getNombre());
      dt->setCodigo(it->second->getCodigo());
      dt->setFechaInicio(it->second->getFechaInicio());
      dt->setFechaFin(fechaNula);
      dt->setTipo(it->second->getTipo());
      dt->setUrl(it->second->getUrl());
      dt->setCreador(it->second->getEmailCreador());
      dt->setAsig(it->second->getCodigoAsig());
      nuevo.insert(*dt);
    }
  }
  return nuevo;
};
map<string,Rol*>* Asignatura::getDocentes(){
  return docentes;
};

void Asignatura::agregarInscripto(Estudiante* est){
  inscriptos->insert(pair<string,Estudiante*> (est->getEmail(),est));
};

void Asignatura::agregarClaseNueva(Clase* c){
  clases->insert(pair<string,Clase*> (c->getCodigo(),c));
};

/*set<dtClase> Asignatura::getClasesDiferido(){
  set<dtClase> nuevo;
  for(auto itCla = clases->begin(); itCla!=clases->end();++itCla){
    if(itCla->second->getFechaFin() != fechaNula){
      dtClase *d = new dtClase();
      d->setCodigo(itAsig->second->getCodigo());
      d->setNombre(itAsig->second->getNombre());
      d->setUrl(itAsig->second->getUrl());
      d->setFechaInicio(itAsig->second->getFechaInicio());
      d->setFechaFin(itAsig->second->getFechaFin());
      //d->setCreador(itAsig->second->);
      d->setCodigoAsig(this->getCodigo());
      d->setTipo(itAsig->second->getTipo());
      nuevo.insert(*d);
    }
  }
  return nuevo;
};*/
Asignatura::~Asignatura(){
  int i = 0;
  int size = this->clases->size();
  while(i<size){
    auto itclases = this->clases->begin();
    delete itclases->second;
    this->clases->erase(itclases->first);
    i++;
  }
  /*
  for(auto itclases = this->clases->begin(); itclases!=clases->end(); ++itclases){
    delete itclases->second;
    this->clases->erase(itclases->first);
  }*/
  i = 0;
  size = this->inscriptos->size();
  while(i<size){
    auto itest = this->inscriptos->begin();
    itest->second->desinscribir(this->codigo);
    this->inscriptos->erase(itest->first);
    ++i;
  }
  /*for(auto itest = this->inscriptos->begin();itest!=this->inscriptos->end() ; ++itest){
    itest->second->desinscribir(this->codigo);
    this->inscriptos->erase(itest->first);
  }*/
  i = 0;
  size = this->docentes->size();
  while(i<size){
    auto itrol = this->docentes->begin();
    delete itrol->second;
    this->docentes->erase(itrol->first);
    ++i;
  }/*
  for(auto itrol = this->docentes->begin(); itrol!=this->docentes->end(); ++itrol){
    delete itrol->second;
    this->docentes->erase(itrol->first);
  }*/
};
