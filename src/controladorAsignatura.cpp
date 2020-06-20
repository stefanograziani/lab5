#include "../include/controladorAsignatura.h"
#include "../include/dtAsignatura.h"
#include "../include/dtDocente.h"
#include "../include/clase.h"

using namespace std;

ControladorAsignatura* ControladorAsignatura::instancia = NULL;

ControladorAsignatura::ControladorAsignatura(){};

ControladorAsignatura* ControladorAsignatura::getInstancia() {
  if (instancia == NULL)
    instancia = new ControladorAsignatura();
  return instancia;
};

void ControladorAsignatura::setEmailDocente(string e){  this->emailDocente = e;};
string ControladorAsignatura::getEmailDocente(){  return emailDocente;};

void ControladorAsignatura::setNombreAsig(string n){  this->nombreAsig = n;};
string ControladorAsignatura::getNombreAsig(){ return nombreAsig;};

void ControladorAsignatura::setCodigoAsig(int c){  this->codigoAsig = c;};
int ControladorAsignatura::getCodigoAsig(){ return codigoAsig;};

void ControladorAsignatura::setAceptaTeo(bool b){  this->aceptaTeo = b;};
bool ControladorAsignatura::getAceptaTeo(){ return aceptaTeo;};

void ControladorAsignatura::setAceptaPra(bool b){  this->aceptaPra = b;};
bool ControladorAsignatura::getAceptaPra(){ return aceptaPra;};

void ControladorAsignatura::setAceptaMon(bool b){  this->aceptaMon = b;};
bool ControladorAsignatura::getAceptaMon(){ return aceptaMon;};

void ControladorAsignatura::setRolDoc(tipoClase r){ this->rolDoc = r;};
tipoClase ControladorAsignatura::getRolDoc(){return rolDoc;};

void ControladorAsignatura::setAsigAEliminar(int a){ this->asigAEliminar = a;};
int ControladorAsignatura::getAsigAEliminar(){ return asigAEliminar;};

void ControladorAsignatura::setColAsig(map<int,Asignatura*>* c){ this->coleccionGlobalAsignaturas = c;};
void ControladorAsignatura::setColDoc(map<string,Docente*>* c){ this->coleccionGlobalDocentes = c;};
void ControladorAsignatura::setColCla(map<int,Clase*>* c){this->coleccionGlobalClases=c;};

void ControladorAsignatura::agregarAsignatura(string n, int c, bool t, bool p, bool m){
  this->setNombreAsig(n);
  this->setCodigoAsig(c);
  this->setAceptaTeo(t);
  this->setAceptaPra(p);
  this->setAceptaMon(m);
};

void ControladorAsignatura::confirmarAlta(){
  Asignatura *nueva = new Asignatura();
  nueva->setNombre(getNombreAsig());
  nueva->setCodigo(getCodigoAsig());
  nueva->setTeorico(getAceptaTeo());
  nueva->setPractico(getAceptaPra());
  nueva->setMonitoreo(getAceptaMon());
  this->coleccionGlobalAsignaturas->insert(pair<int,Asignatura*>(nueva->getCodigo(),nueva));
};

void ControladorAsignatura::cancelarAlta(){

};

set<dtAsignatura> ControladorAsignatura::consultarAsignaturas(){
  set<dtAsignatura> nuevo;
  map<int,Asignatura*> :: iterator it;
  for (it=coleccionGlobalAsignaturas->begin(); it!=coleccionGlobalAsignaturas->end() ;++it){
    Asignatura* a = it->second;
    dtAsignatura* agregar = new dtAsignatura();
    agregar->setCodigo(a->getCodigo());
    agregar->setNombre(a->getNombre());
    agregar->setMonitoreo(a->getMonitoreo());
    agregar->setPractico(a->getPractico());
    agregar->setTeorico(a->getTeorico());
    nuevo.insert(*agregar);
  };
  return nuevo;
};

map<string,dtDocente> ControladorAsignatura::consultarDocentesLibres(int codigo){
  map<string,dtDocente> nuevo;
  map<string,Docente*> :: iterator it;
  for (it=coleccionGlobalDocentes->begin(); it!=coleccionGlobalDocentes->end() ;++it){
    Docente* d = it->second;
    if(!(d->esDocenteDe(codigo))){
      dtDocente* agregar = new dtDocente();
      agregar->setNombre(d->getNombre());
      agregar->setEmail(d->getEmail());
      agregar->setPassword(d->getPassword());
      agregar->setImagen(d->getImagen());
      agregar->setInstituto(d->getInstituto());
      //agregar->setModoSus(d->getModoSus());
      nuevo.insert(pair<string, dtDocente>(d->getEmail(), *agregar));
    }
  };
  return nuevo;
};
bool ControladorAsignatura::asignarDocente(string e, int c, tipoClase r){
  bool res;
  auto asig = coleccionGlobalAsignaturas->find(c)->second;
  if( (asig->getTeorico() && r==teorico)||(asig->getPractico() && r==practico)||(asig->getMonitoreo() && r==monitoreo) ){
    this->setEmailDocente(e);
    this->setCodigoAsig(c);
    this->setRolDoc(r);
    res = true;
  }
  else{
    cout << "\n\tLa asignatura no admite clases del rol elegido"<<endl;
    res = false;
  }
  return res;
};
void ControladorAsignatura::confirmarAsignacion(){
  auto doc = coleccionGlobalDocentes->find(emailDocente);
  auto asig = coleccionGlobalAsignaturas->find(codigoAsig);
  Rol* nuevo = doc->second->nuevoRol(asig->second,this->rolDoc);
  asig->second->agregarRol(nuevo);
};
void ControladorAsignatura::cancelarAsignacion(){

};

set<DtDictado> ControladorAsignatura::tiempoDictado(){
  set<DtDictado> nuevo;
  map<int,Asignatura*> :: iterator it;
  for (it=coleccionGlobalAsignaturas->begin(); it!=coleccionGlobalAsignaturas->end() ;++it){
      int tiempo=0;
      for (auto itclases=it->second->getClases()->begin(); itclases!=it->second->getClases()->end() ;++itclases){
          tiempo+=(itclases->second->getFechaFin() - itclases->second->getFechaInicio());
        };
      DtDictado *dictado = new DtDictado(it->second->getCodigo(),tiempo);
      nuevo.insert(*dictado);
  };
  return nuevo;
};

void ControladorAsignatura::eliminarAsignatura(int codigo){
  setAsigAEliminar(codigo);
};
void ControladorAsignatura::confirmarElim(){
  auto asig = coleccionGlobalAsignaturas->find(asigAEliminar);
    for(auto it = asig->second->getClases()->begin();it != asig->second->getClases()->end();it++){
      int aux = it->second->getCodigo();
      for(auto itDoc = asig->second->getDocentes()->begin();itDoc != asig->second->getDocentes()->end();itDoc++)//borro la clase del mapa del docente
        itDoc->second->getDoc()->getClases()->erase(aux);//si no esta en el map no hace nada
      delete it->second;
      coleccionGlobalClases->erase(aux);
    }
    delete asig->second;
    coleccionGlobalAsignaturas->erase(asigAEliminar);
};

void ControladorAsignatura::cancelarElim(){

};

ControladorAsignatura::~ControladorAsignatura(){

};
