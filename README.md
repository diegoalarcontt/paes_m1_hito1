# PAES M1 Trainer — Hito 2

## Descripción del proyecto
Este proyecto corresponde al **Hito 2** del curso **TEL-102: Seminario de Programación**.  
Consiste en la **migración completa del código del Hito 1**, desarrollado en lenguaje C, hacia una versión implementada en **C++** aplicando los principios de **Programación Orientada a Objetos (POO)**.

El propósito del sistema sigue siendo el mismo: ofrecer un **entrenador en consola** para que estudiantes practiquen preguntas tipo **PAES M1 de Matemáticas**, con retroalimentación inmediata para cada respuesta.

---

## Objetivo general
Migrar el programa del Hito 1 desde C a C++, manteniendo la funcionalidad base pero adoptando una estructura modular, jerárquica y orientada a objetos.

## Objetivos específicos
- Reestructurar el código utilizando **clases y métodos**.
- Implementar **encapsulamiento** y **composición** entre las clases del sistema.
- Sustituir arreglos de C por estructuras de la biblioteca estándar de C++ (`std::vector`, `std::string`).
- Separar el código en archivos de encabezado (`.h`) e implementación (`.cpp`).
- Mantener la claridad del flujo de ejecución y la retroalimentación al usuario.
- Documentar adecuadamente el proceso de migración y el uso de herramientas de IA.

---

## Funcionalidades implementadas
- Carga automática de un conjunto de ocho preguntas tipo PAES.
- Presentación del enunciado y tres alternativas de respuesta.
- Lectura de la alternativa ingresada por el usuario (A, B o C).
- Validación de la respuesta y entrega de retroalimentación inmediata.
- Cálculo y visualización del porcentaje de aciertos al final de la sesión.
- Modo de prueba (`--test`) para verificar la consistencia del sistema.

---

## Estructura del repositorio

paes_m1_hito1/
├─ src/
│ ├─ main.cpp
│ ├─ Pregunta.h
│ ├─ Pregunta.cpp
│ ├─ Cuestionario.h
│ └─ Cuestionario.cpp
├─ README hito2.md
└─ AI_USAGE.md

---

## Clases principales

### Clase `Pregunta`
Representa una pregunta individual del cuestionario.  
Atributos principales: eje, enunciado, opciones, índice de respuesta correcta y explicación.  
Métodos: `mostrar()`, `validar()`, `feedback()`.

### Clase `Cuestionario`
Administra el conjunto de preguntas y controla el flujo general del programa.  
Atributos principales: `std::vector<Pregunta> preguntas`.  
Métodos: `ejecutar()`, `modoTest()`.

---

## Compilación y ejecución

### En Linux o macOS
```bash
g++ -std=c++17 -Wall -Wextra src/*.cpp -o paes
./paes          # ejecución normal
./paes --test   # modo de prueba
