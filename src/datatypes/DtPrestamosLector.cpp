#include "DtPrestamosLector.h"

DtPrestamosLector::DtPrestamosLector()
    : idLector(""), nombreLector(""), prestamos() {}

DtPrestamosLector::DtPrestamosLector(std::string idLector, std::string nombreLector, std::vector<DtPrestamo> prestamos)
    : idLector(idLector), nombreLector(nombreLector), prestamos(prestamos) {}
