#pragma once

class Lector;
class Material;

class Puntaje {
private:
    int valor;
    Lector* lector;
    Material* material;

public:
    Puntaje(int valor, Lector* lector, Material* material);
    ~Puntaje();

    int getValor() const;
    Lector* getLector() const;
    Material* getMaterial() const;
};
