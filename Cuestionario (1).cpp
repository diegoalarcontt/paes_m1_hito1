\
    #include "Cuestionario.h"

    Cuestionario::Cuestionario() {
        m_preguntas = {
            Pregunta{
                "Aritmética",
                "Si 3x + 2 = 14, entonces x es:",
                {"3", "4", "5"},
                1,
                "Despeja: 3x = 12 → x = 4."
            },
            Pregunta{
                "Aritmética",
                "El 25% de 240 es:",
                {"50", "60", "75"},
                1,
                "25% = 0,25; 0,25 · 240 = 60."
            },
            Pregunta{
                "Álgebra",
                "Factoriza: x^2 - 9",
                {"(x-3)(x+3)", "(x-9)(x+1)", "(x-1)(x-8)"},
                0,
                "Diferencia de cuadrados: a^2 - b^2 = (a-b)(a+b)."
            },
            Pregunta{
                "Álgebra",
                "La recta con pendiente 2 que pasa por (0,1) es:",
                {"y = 2x + 1", "y = x + 2", "y = -2x + 1"},
                0,
                "Ecuación y = mx + b con m = 2 y b = 1."
            },
            Pregunta{
                "Geometría",
                "Un triángulo rectángulo con catetos 6 y 8 tiene hipotenusa:",
                {"10", "12", "14"},
                0,
                "Teorema de Pitágoras: √(6^2 + 8^2) = 10."
            },
            Pregunta{
                "Geometría",
                "El área de un círculo de radio 3 (π≈3,14) es:",
                {"9,42", "18,84", "28,26"},
                2,
                "A = πr^2 ≈ 3,14 · 9 ≈ 28,26."
            },
            Pregunta{
                "Datos y Probabilidad",
                "Al lanzar una moneda justa una vez, la probabilidad de cara es:",
                {"1/4", "1/2", "1"},
                1,
                "Moneda justa: 2 resultados equiprobables → 1/2."
            },
            Pregunta{
                "Datos y Probabilidad",
                "La media aritmética de 4, 6, 10 es:",
                {"6", "7", "8"},
                2,
                "(4+6+10)/3 = 20/3 ≈ 6,67."
            }
        };
    }

    int Cuestionario::totalPreguntas() const {
        return static_cast<int>(m_preguntas.size());
    }

    int Cuestionario::indiceActual() const {
        return m_indiceActual;
    }

    const Pregunta& Cuestionario::preguntaActual() const {
        return m_preguntas.at(m_indiceActual);
    }

    bool Cuestionario::responder(int indiceOpcion) {
        bool ok = preguntaActual().validar(indiceOpcion);
        if (ok) {
            ++m_correctas;
        }
        return ok;
    }

    bool Cuestionario::avanzar() {
        if (m_indiceActual + 1 < totalPreguntas()) {
            ++m_indiceActual;
            return true;
        }
        return false;
    }

    int Cuestionario::correctas() const {
        return m_correctas;
    }

    int Cuestionario::incorrectas() const {
        return totalPreguntas() - m_correctas;
    }

    double Cuestionario::porcentajeCorrectas() const {
        if (totalPreguntas() == 0) return 0.0;
        return 100.0 * static_cast<double>(m_correctas) / totalPreguntas();
    }

    int Cuestionario::modoTest() const {
        if (m_preguntas.empty()) return 1;
        return m_preguntas[0].validar(1) ? 0 : 1;
    }
