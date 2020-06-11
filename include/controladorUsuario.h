#ifndef CONTROLADOR_USUARIO_H
#define CONTROLADOR_USUARIO_H

#include <iostream>

#include "dtNotificacion.h"
#include "iControladorUsuario.h"
#include "usrcla.h"
#include "estudiante.h"
#include "docente.h"

#include <map>
#include <set>
#include <string>

using namespace std;

class ControladorUsuario: public IControladorUsuario{
	private:
		bool userEsEst;
		string nombreUser;
		string contraseniaUser;
		string emailUser;
		string urlUser;
		string institutoDoc;
		string cedulaEst;
		string nombreUserActual;
		string emailUserActual;
		int nuevoModoSus;
		map<string,Estudiante*>* coleccionGlobalEstudiantes;
		map<string,Docente*>* coleccionGlobalDocentes;

	public:
		ControladorUsuario();
		bool getUserEsEst();
		string getNombreUser();
		string getPasswordUser();
		string getEmailUser();
		string getUrlUser();
		string getInstitutoDoc();
		string getCedulaEst();
		string getNombreUserActual();
		string getEmailUserActual();
		int getNuevoModoSus();
		void setUserEsEst(bool);
		void setNombreUser(string);
		void setPasswordUser(string);
		void setEmailUser(string);
		void setUrlUser(string);
		void setInstitutoDoc(string);
		void setCedulaEst(string);
		void setNombreUserActual(string);
		void setEmailUserActual(string);
		void setNuevoModoSus(int);
		//COLECCIONES
		void setColEst(map<string,Estudiante*>*);
		void setColDoc(map<string,Docente*>*);

		void iniciarSesion(string,string);

		//ALTA DE USUARIO
		void agregarEstudiante(string,string,string,string,string);
		void agregarDocente(string,string,string,string,string);
		void confirmarAlta();
		void cancelarAlta();

		set<dtNotificacion> consultarNotifs();
		void cambiarModoSus(int);
		void cancelarCambio();
		void confirmarCambio();
		void desuscribirse();

		~ControladorUsuario();
};
#endif
