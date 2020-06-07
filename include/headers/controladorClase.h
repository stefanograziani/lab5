#ifndef CONTROLADOR_CLASE_H
#define CONTROLADOR_CLASE_H

class ControladorClase{
	private:
		string contraseniaUserActual;
		string emailUserActual;
		DtInfoClase infoParaCreacionClase;
		string claseAFinalizar;
	public:
		ControladorClase();
		void setContraseniaUserActual(string);
		void setEmailUserActual(string);
		void setInfoParaCreacionClase(DtInfoClase);
		void setClaseAFinalizar(string);
		string getContraseniaUserActual();
		string getEmailUserActual();
		DtInfoClase getInfoParaCreacionClase();
		string getClaseAFinalizar();

		void iniciarSesion(string,string);
		set(DtAsignatura) consultarAsignaturasDocente();
		DtInfoClase infoDocente(string);
		void iniciarClase(string,string,DtFecha);
		string generarCodigo();
		string generarUrl(clase);
		DtFecha generarFecha();
		set(DtEstudiantes) consultarInscriptos();
		void agregarHabilitado(string);
		DtInfoClase desplegarInfoClase();
		void confirmarInicio();
		void cancelarInicio();
		set(DtClase) consultarClasesEnVivo();
		DtClase finalizarClase(string);
		void confirmarFin();
		void cancelarFin();
		set(DtAsignatura) consultarAsigIns();
		set(DtClase) consultarClasesDiferido(string);
		DtClase AsistirClaseDiferido(string);
		set(DtMensaje) confirmarAsistencia();
		void cancelarAsistencia();
		set(DtInfoClase) desplegarInfoClases(string);
		void confirmarEnvio();

		~ControladorClase()
}
#endif
