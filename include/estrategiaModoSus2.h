#ifndef ESTRATEGIA_MODO_SUS_2_H
#define ESTRATEGIA_MODO_SUS_2_H
#include "estrategiaNotifs.h"

class EstrategiaModoSus2 : public EstrategiaNotifs{
  public:
    EstrategiaModoSus2();

    bool aplicaNotificacion();

    ~EstrategiaModoSus2();
};
#endif