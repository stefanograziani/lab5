#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <set>
#include"../dts/dtNotificacion.h"
//#include "../headers/estrategiaNotifs.h"
using namespace std;
class EstrategiaNotifs{

};
class Usuario{
  private:
    string nombre;
    string email;
    string password;
    string imagen;
    set<DtNotificacion> notificaciones;
    // int modoSus //Necesario?
    EstrategiaNotifs aplica;
  public:
    Usuario();
    void setNombre(string);
    void setEmail(string);
    void setPassword(string);
    void setImagen(string);
    void setNotificaciones(); //crea el conjunto de notifiaciones vacio
    virtual void setAplica(EstrategiaNotifs)= 0;
    string getNombre();
    string getEmail();
    string getPassword();
    string getImagen();
    set<DtNotificacion> getNotificaciones();
    EstrategiaNotifs getAplica();

    void notificar(DtNotificacion);

    ~Usuario();
};
#endif
