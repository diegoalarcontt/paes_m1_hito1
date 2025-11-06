#pragma once
#include <string>
#include <vector>

class Pregunta {
private:
    std::string eje;
    std::string enunciado;
    std::vector<std::string> opciones;
    int correcta;
    std::string explicacion;

public:
    // Constructor
    Pregunta(std::string eje, std::string enunciado,
             std::vector<std::string> opciones,
             int correcta, std::string explicacion);

    // Métodos principales
    void mostrar(int idx, int total) const;
    bool validar(int respuesta) const;
    void feedback(bool correcto) const;

    // Getters (por si los necesitas)
    std::string getEje() const { return eje; }
    std::string getEnunciado() const { return enunciado; }
};
