#include "Libro.h"

Libro::Libro(std::string codigo, std::string titulo, int anioPublicacion, std::string autor, int cantPaginas)
    : Material(codigo, titulo, anioPublicacion), autor(autor), cantPaginas(cantPaginas) {}

Libro::~Libro() {}

std::string Libro::getAutor() const {
    return autor;
}

int Libro::getCantPaginas() const {
    return cantPaginas;
}

DtDatosEspecificos Libro::getDatosEspecificos() const {
    return DtDatosEspecificos(autor, std::to_string(cantPaginas));
}

std::string Libro::getTipoMaterial() const {
    return "Libro";
}
