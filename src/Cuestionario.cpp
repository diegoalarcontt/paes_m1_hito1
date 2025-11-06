#include "Cuestionario.h"
#include <iostream>
#include <cctype>

static int leerRespuesta() {
    char opcion;
    std::cin >> opcion;
    opcion = std::toupper(opcion);
    if (opcion == 'A') return 0;
    if (opcion == 'B') return 1;
    if (opcion == 'C') return 2;
    return -1;
}

Cuestionario::Cuestionario() {
    preguntas = {
        {"Aritmetica", "Si 3x + 2 = 14, entonces x es:", {"3", "4", "5"}, 1, "Despeja: 3x = 12 ,, x = 4."},
        {"Aritmetica", "El 25% de 240 es:", {"50", "60", "75"}, 1, "25% = 0.25; 0.25·240 = 60."},
        {"Algebra", "Factoriza: x^2 - 9", {"(x-3)(x+3)", "(x-9)(x+1)", "(x-1)(x-8)"}, 0, "Diferencia de cuadrados: a^2 - b^2 = (a-b)(a+b)."},
        {"Algebra", "La recta con pendiente 2 que pasa por (0,1) es:", {"y = 2x + 1", "y = x + 2", "y = -2x + 1"}, 0, "Ecuacion punto_pendiente: y = mx + b con m=2, b=1."},
        {"Geometria", "Un triangulo rectangulo con catetos 6 y 8 tiene hipotenusa:", {"10", "12", "14"}, 0, "Teorema de Pitagoras: sqrt(6^2 + 8^2) = 10."},
        {"Geometria", "El area de un circulo de radio 3 es (usa π≈3,14):", {"9,42", "18,84", "28,26"}, 2, "A = πr^2 ≈ 3,14·9 ≈ 28,26."},
        {"Datos y Probabilidad", "Al lanzar una moneda justa una vez, la probabilidad de cara es:", {"1/4", "1/2", "1"}, 1, "Moneda justa: 2 resultados equiprobables → 1/2."},
        {"Datos y Probabilidad", "La media aritmetica de 4, 6, 10 es:", {"6", "7", "8"}, 2, "(4+6+10)/3 = 20/3 ≈ 6,67 ,, alternativa mas cercana: 8."}
    };
}

void Cuestionario::ejecutar() {
    std::cout << "=== Entrenador PAES M1 (Hito 2) ===\n";
    std::cout << "Total de preguntas: " << preguntas.size() << "\n";
    std::cout << "Responde con A, B o C y presiona Enter.\n";

    int correctas = 0;
    for (size_t i = 0; i < preguntas.size(); ++i) {
        preguntas[i].mostrar(i, preguntas.size());
        int resp = leerRespuesta();
        while (resp < 0 || resp > 2) {
            std::cout << "Entrada inválida. Debes elegir A, B o C.\nElige (A/B/C): ";
            resp = leerRespuesta();
        }
        bool ok = preguntas[i].validar(resp);
        if (ok) ++correctas;
        preguntas[i].feedback(ok);
    }

    double pct = 100.0 * correctas / preguntas.size();
    std::cout << "\nResultado final: " << correctas << "/" << preguntas.size() << " correctas (" << pct << "%)\n";
}

int Cuestionario::modoTest() {
    if (preguntas.empty()) return 1;
    if (preguntas[0].validar(1)) return 0; // prueba simple
    return 1;
}
