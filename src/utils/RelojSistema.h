#pragma once

#include <string>

class RelojSistema {
private:
    static RelojSistema* instancia;

    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;

    RelojSistema();

    bool fechaValida(int dia, int mes, int anio, int hora, int minuto) const;
    std::string dosDigitos(int valor) const;

public:
    static RelojSistema* getInstancia();

    void modificarFecha(int dia, int mes, int anio, int hora, int minuto);
    std::string consultarFecha() const;
};
