# Entrenador PAES M1 – Hito 3 (Qt + C++)

Este proyecto corresponde al **Hito 3**, donde se migra el sistema del Hito 2 (consola) hacia una aplicación **gráfica** construida con **Qt Widgets**, reutilizando la lógica existente en C++ (clases `Pregunta` y `Cuestionario`).

## 🎯 Objetivos
- Implementar una interfaz gráfica en Qt.
- Integrar la lógica del Hito 2 (modelo Pregunta–Cuestionario).
- Usar señales y slots para la interacción.
- Mostrar preguntas, alternativas, retroalimentación y progreso.
- Mantener el modo de prueba `--test`.
- Publicar estructura ordenada para GitHub.

## 🧱 Arquitectura
```
/Hito3/
├── main.cpp
├── MainWindow.h
├── MainWindow.cpp
├── Pregunta.h
├── Pregunta.cpp
├── Cuestionario.h
├── Cuestionario.cpp
└── README.md
```

## 🚀 Cómo ejecutar (Qt Creator)
1. Abrir Qt Creator → Open Project.
2. Compilar (`Ctrl + B`).
3. Ejecutar → Se abre la interfaz gráfica.
4. Interactuar con:
   - Eje y enunciado.
   - Opciones con QRadioButton.
   - Botones Responder / Siguiente.
   - Feedback inmediato.
   - Barra de progreso.

## 🧪 Modo Test
Ejecutar:
```
./Hito3 --test
```

Devuelve:
- `0` si la lógica está correcta.
- `1` si existe un error.

## 💻 Dependencias
- Qt 6 o Qt 5.15  
- Qt Widgets  
- C++17+

## 🖼️ Capturas (puedes agregarlas)
```
imagenes/mainwindow.png
imagenes/feedback.png
```

## 🧑‍💻 Autor
**Diego Alarcón**  
Proyecto académico — Ingeniería Civil Química  
Hito 3 — Programación + Qt
