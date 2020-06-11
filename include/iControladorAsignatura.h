#ifndef I_CONTROLADOR_ASIGNATURA_H
#define I_CONTROLADOR_ASIGNATURA_H
#include "dtDocente.h"
#include "dtAsignatura.h"
#include <string>
#include <set>

using namespace std;

class IControladorAsignatura{
	public:
		virtual Set<dtAsignatura> consultarAsignaturas() = 0;
		virtual Set<dtDocente> consultarDocentesLibres(string) = 0;
		virtual void asignarDocente(string,string,tipoClase) = 0;
		virtual void confirmarAsignacion() = 0;
		virtual void cancelarAsignacion() = 0;
		virtual void eliminarAsignatura(string) = 0;
		virtual void confirmarElim() = 0;
		virtual void cancelarElim() = 0;

		~IControladorAsignatura(){};
};
#endif