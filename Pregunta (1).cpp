\
    #include "Pregunta.h"

    Pregunta::Pregunta(const std::string& eje,
                       const std::string& enunciado,
                       const std::vector<std::string>& opciones,
                       int indiceCorrecta,
                       const std::string& explicacion)
        : m_eje(eje),
          m_enunciado(enunciado),
          m_opciones(opciones),
          m_indiceCorrecta(indiceCorrecta),
          m_explicacion(explicacion)
    {
    }

    const std::string& Pregunta::getEje() const {
        return m_eje;
    }

    const std::string& Pregunta::getEnunciado() const {
        return m_enunciado;
    }

    const std::vector<std::string>& Pregunta::getOpciones() const {
        return m_opciones;
    }

    int Pregunta::getIndiceCorrecta() const {
        return m_indiceCorrecta;
    }

    const std::string& Pregunta::getExplicacion() const {
        return m_explicacion;
    }

    bool Pregunta::validar(int indiceOpcion) const {
        return indiceOpcion == m_indiceCorrecta;
    }
