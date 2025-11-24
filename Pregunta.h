\
    #ifndef PREGUNTA_H
    #define PREGUNTA_H

    #include <string>
    #include <vector>

    class Pregunta {
    public:
        Pregunta() = default;

        Pregunta(const std::string& eje,
                 const std::string& enunciado,
                 const std::vector<std::string>& opciones,
                 int indiceCorrecta,
                 const std::string& explicacion);

        const std::string& getEje() const;
        const std::string& getEnunciado() const;
        const std::vector<std::string>& getOpciones() const;
        int getIndiceCorrecta() const;
        const std::string& getExplicacion() const;

        bool validar(int indiceOpcion) const;

    private:
        std::string m_eje;
        std::string m_enunciado;
        std::vector<std::string> m_opciones;
        int m_indiceCorrecta = 0;
        std::string m_explicacion;
    };

    #endif // PREGUNTA_H
