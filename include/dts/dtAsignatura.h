#ifndef DT_ASIGNATURA_H
#define DT_ASIGNATURA_H

class dtAsignatura{
  private:
    int codigo;
    string nombre;
    bool teorico;
    bool monitoreo;
    bool practico;
  public:
    dtAsignatura();
    void setCodigo(int);
    void setNombre(string);
    void setTeorico(bool);
    void setPractico(bool);
    void setMonitoreo(bool);
    int getCodigo();
    string getNombre();
    bool getTeorico();
    bool getPractico();
    bool getMonitoreo();
    ~dtAsignatura();
    //bool operator<(const Asignatura &right); //si colecciones se implementan con set esto es necesario
};

#endif
