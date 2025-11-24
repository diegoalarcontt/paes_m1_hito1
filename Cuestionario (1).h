\
    #ifndef CUESTIONARIO_H
    #define CUESTIONARIO_H

    #include <vector>
    #include "Pregunta.h"

    class Cuestionario {
    public:
        Cuestionario();

        int totalPreguntas() const;
        int indiceActual() const;
        const Pregunta& preguntaActual() const;

        // Registra la respuesta del usuario a la pregunta actual.
        // Devuelve true si es correcta.
        bool responder(int indiceOpcion);

        // Avanza a la siguiente pregunta.
        // Devuelve false si ya no hay más preguntas.
        bool avanzar();

        int correctas() const;
        int incorrectas() const;
        double porcentajeCorrectas() const;

        // Mantiene un modo de prueba sencillo (para --test)
        int modoTest() const;

    private:
        std::vector<Pregunta> m_preguntas;
        int m_indiceActual = 0;
        int m_correctas = 0;
    };

    #endif // CUESTIONARIO_H
