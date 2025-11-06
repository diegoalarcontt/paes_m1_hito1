#include "Pregunta.h"
#include <iostream>

Pregunta::Pregunta(std::string eje, std::string enunciado,
                   std::vector<std::string> opciones,
                   int correcta, std::string explicacion)
    : eje(eje), enunciado(enunciado),
      opciones(opciones), correcta(correcta),
      explicacion(explicacion) {}

void Pregunta::mostrar(int idx, int total) const {
    std::cout << "\n[" << idx + 1 << "/" << total << "] Eje: " << eje << "\n";
    std::cout << enunciado << "\n";
    std::cout << "  A) " << opciones[0] << "\n";
    std::cout << "  B) " << opciones[1] << "\n";
    std::cout << "  C) " << opciones[2] << "\n";
    std::cout << "Elige (A/B/C): ";
}

bool Pregunta::validar(int respuesta) const {
    return respuesta == correcta;
}

void Pregunta::feedback(bool correcto) const {
    if (correcto)
        std::cout << " Correcto!\n";
    else
        std::cout << " Incorrecto. Explicacion: " << explicacion << "\n";
}

Copiar código
// src/Cuestionario.h
#include "Pregunta.h"
#include <vector>

class Cuestionario {
private:
    std::vector<Pregunta> preguntas;

public:
    Cuestionario(); // Constructor que carga las preguntas
    void ejecutar();
    int modoTest(); // Modo --test
};
