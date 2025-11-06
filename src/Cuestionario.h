#pragma once
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
