#include "RelojSistema.h"
#include <stdexcept>

RelojSistema* RelojSistema::instancia = nullptr;

RelojSistema::RelojSistema()
    : dia(1), mes(1), anio(2026), hora(0), minuto(0) {}

RelojSistema* RelojSistema::getInstancia() {
    if (instancia == nullptr) {
        instancia = new RelojSistema();
    }

    return instancia;
}

bool RelojSistema::fechaValida(int dia, int mes, int anio, int hora, int minuto) const {
    return dia >= 1 && dia <= 31 &&
           mes >= 1 && mes <= 12 &&
           anio > 0 &&
           hora >= 0 && hora <= 23 &&
           minuto >= 0 && minuto <= 59;
}

std::string RelojSistema::dosDigitos(int valor) const {
    if (valor < 10) {
        return "0" + std::to_string(valor);
    }

    return std::to_string(valor);
}

void RelojSistema::modificarFecha(int dia, int mes, int anio, int hora, int minuto) {
    if (!fechaValida(dia, mes, anio, hora, minuto)) {
        throw std::runtime_error("Fecha u hora invalida.");
    }

    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->minuto = minuto;
}

std::string RelojSistema::consultarFecha() const {
    return dosDigitos(dia) + "/" +
           dosDigitos(mes) + "/" +
           std::to_string(anio) + " " +
           dosDigitos(hora) + ":" +
           dosDigitos(minuto);
}
