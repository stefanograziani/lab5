#ifndef CLASE_H
#define CLASE_H

#include "iControladorUsuario.h"
#include "docente.h"
#include "mensaje.h"
#include <string>
#include <set>
#include <map>
#include <list>

using namespace std;

class UsrCla;
class Mensaje;
class Asignatura;
class Estudiante;

using namespace std;
class Clase{
  private:
    string nombre;
    string codigo;
    string url;
    dtFecha fechaInicio;
    dtFecha fechaFin;
    Docente* creador;
    set<UsrCla*> participantes;
    set<Mensaje*> mensajes;
    Asignatura *asig;
    tipoClase tipo;

  public://faltan funciones de manejo de relaciones
    Clase();
    virtual bool estaHabilitado(string);
    void setNombre(string);
    void setCodigo(string);
    void setUrl(string);
    void setFechaInicio(dtFecha);
    void setFechaFin(dtFecha);
    void setCreador(Docente*);
    void setAsig(Asignatura*);
    void setTipo(tipoClase);
    tipoClase getTipo();
    string getNombre();
    string getCodigo();
    string getUrl();
    dtFecha getFechaInicio();
    dtFecha getFechaFin();
    set<UsrCla*> getParticipantes();
    set<Mensaje*> getMensajes();
    string getEmailCreador();
    string getCodigoAsig();

    void nuevaVis(UsrCla*);
    void agregarMensaje(Mensaje*);

    //set<Visualizacion*> getVis();

    void visualizar(Estudiante*);

    ~Clase();
};
#endif
