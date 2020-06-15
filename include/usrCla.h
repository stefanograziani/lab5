#ifndef ESTCLA_H
#define ESTCLA_H
#include <string>
#include <list>
#include "dtFecha.h"
//#include "visualizacion.h"
//#include "estudiante.h"
//#include "clase.h"

using namespace std;

class Clase;
class Estudiante;
class Visualizacion;

class UsrCla{
  private:
    list<Visualizacion*> vis;
    Estudiante *est;
    Clase *clase;
  public:
    UsrCla();
    void setVisualizacion(Visualizacion*); //hacer coleccion de visualizacion
    void setEstudiante(Estudiante*);
    void setClase(Clase*);
    //list<Visualizacion*> getVis();
    Estudiante* getEst();
    Clase* getClase();

    //int getCodigoClase();
    //string getEmailUser();
    void marcarFin(dtFecha);
    //void iniciarVis();
    ~UsrCla();

};

#endif