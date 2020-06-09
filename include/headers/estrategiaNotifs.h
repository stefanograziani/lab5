#ifndef ESTRATEGIA_NOTIFS_H
#define ESTRATEGIA_NOTIFS_H
//#include"../headers/usuario.h" incluir en .cpp
class Usuario;

class EstrategiaNotifs{
  private:
    Usuario* user;
  public:
    virtual bool aplicaNotificacion() = 0;

    virtual ~EstrategiaNotifs(){};
};
#endif
