#ifndef MONITOREO_H
#define MONITOREO_H
#include "clase.h"

class Estudiante;

class Monitoreo : public Clase{
  private:
    int cantHabilitados;
    Estudiante* habilitados[15];
  public://faltan funciones de manejo de relaciones
    void auxiliar();

    Monitoreo();

    void agregarHabilitado(Estudiante*);

    ~Monitoreo();
};
#endif
