#ifndef I_CONTROLADOR_CLASE_H
#define I_CONTROLADOR_CLASE_H

#include "dtClase.h"
#include "dtAsignatura.h"
#include "dtInfoClase.h"
#include "dtEstudiante.h"
#include "dtMensaje.h"
#include "dtFecha.h"
#include "estudiante.h"
#include "docente.h"
#include "asignatura.h"
#include "clase.h"
#include "mensaje.h"
#include "handlerMensajes.h"
#include "DtTiempoDeClase.h"

#include <string>
#include <set>
#include <map>

using namespace std;

class Reloj;

class IControladorClase{
	public:

		virtual void setColEst(map<string,Estudiante*>*) = 0;
		virtual void setColDoc(map<string,Docente*>*) = 0;
		virtual void setColAsig(map<string,Asignatura*>*) = 0;
		virtual void setColCla(map<string,Clase*>*) = 0;
		virtual void setColMens(map<int,Mensaje*>*) = 0;
		virtual void setHandler(HandlerMensajes*) = 0;
		virtual void setReloj(Reloj*) = 0;

		virtual void iniciarSesion(string,string) = 0;
		virtual set<dtAsignatura> consultarAsignaturasDocente() = 0;
		virtual tipoClase rolDocente(string) = 0;
		virtual void iniciarClase(string,string,tipoClase,dtFecha) = 0;
		virtual map<string,dtEstudiante*> consultarInscriptos() = 0;
		virtual void agregarHabilitado(string) = 0;
		virtual dtInfoClase desplegarInfoClase() = 0;
		virtual void confirmarInicio() = 0;
		virtual void cancelarInicio() = 0;
		virtual dtFecha generarFecha() = 0;
		virtual set<dtClase> consultarClasesEnVivo() = 0;
		virtual set<dtClase> consultarClasesEnVivoDeAsig(string codigoAsig) = 0;
		virtual void finalizarClase(string) = 0;
		virtual void confirmarFin() = 0;
		virtual void cancelarFin() = 0;
		virtual set<dtClase> consultarClasesParticipando() = 0;
		virtual set<dtMensaje> consultarMensajes(string) = 0;
		virtual void enviarMensaje(string) = 0;
		virtual void enviarRespuesta(int,string) = 0;
		virtual void confirmarEnvio() = 0;
		virtual void cancelarEnvio() = 0;
		virtual set<dtAsignatura> consultarAsigIns() = 0;
		virtual set<dtClase> consultarClasesVivo(string a) = 0;
		virtual dtClase asistirClaseVivo(string) = 0;
		virtual void confirmarAsistenciaVivo() = 0;
		virtual void cancelarAsistencia() = 0;
		virtual set<dtClase*>  consultarClasesParticipandoVivo() = 0;
		virtual void finalizarAsistencia(string) = 0;
		virtual void confirmarSalida() = 0;
		virtual void cancelarSalida() = 0;
		virtual set<DtTiempoDeClase> consultarTiempoClaseDocente(string ) = 0;
		~IControladorClase(){};
};
#endif
