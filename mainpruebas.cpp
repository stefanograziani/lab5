#include <iostream>
#include <map>
#include "include/headers/asignatura.h"
#include "include/headers/clase.h"
#include "include/headers/controladorAsignatura.h"
#include "include/headers/controladorClase.h"
#include "include/headers/controladorUsuario.h"
#include "include/headers/docente.h"
#include "include/headers/estcla.h"
#include "include/headers/estrategiaModoSus1.h"
#include "include/headers/estrategiaModoSus2.h"
#include "include/headers/estrategiaModoSus3.h"
#include "include/headers/estrategiaNotifs.h"
#include "include/headers/estudiante.h"
#include "include/headers/factory.h"
#include "include/headers/handlerMensajes.h"
#include "include/headers/iControladorAsignatura.h"
#include "include/headers/iControladorClase.h"
#include "include/headers/iControladorUsuario.h"
#include "include/headers/mensaje.h"
#include "include/headers/monitoreo.h"
#include "include/headers/practico.h"
#include "include/headers/rol.h"
#include "include/headers/teorico.h"
#include "include/headers/usuario.h"
#include "include/headers/visualizacion.h"
#include "include/dts/dtAsignatura.h"
#include "include/dts/dtClase.h"
#include "include/dts/dtDocente.h"
#include "include/dts/dtEstudiante.h"
#include "include/dts/dtFecha.h"
#include "include/dts/dtMensaje.h"
#include "include/dts/dtMonitoreo.h"
#include "include/dts/dtNotificacion.h"
#include "include/dts/dtPractico.h"
#include "include/dts/dtRol.h"
#include "include/dts/dtTeorico.h"
#include "include/dts/dtUsuario.h"
#include "include/dts/dtVisualizacion.h"

using namespace std;

  //coleccion de est
  map<string,Estudiante*> coleccionGlobalEstudiantes;
  map<string,Docente*> coleccionGlobalDocentes;

int main(){

  ControladorUsuario* Cu = new ControladorUsuario;
  Cu->agregarEstudiante(c,a,email,a,s);
  Cu->confirmarAlta();

  auto it = coleccionGlobalEstudiantes.find(email);

  cout << "Iterator points to " << it->first <<
     " = " << it->second->getNombre() << endl;

  return 0;
}