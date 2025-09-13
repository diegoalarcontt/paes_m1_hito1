# PAES M1 Trainer — Hito 1

## Descripción del proyecto
Este proyecto corresponde al Hito 1 del curso TEL-102: Seminario de Programación.  
Consiste en una primera versión funcional de un entrenador en consola , desarrollado en C, para preparar a estudiantes en la prueba M1 de Matemáticas (PAES).  

El propósito no es solo resolver ejercicios puntuales, sino aprender la lógica detrás de los métodos que se repiten en la prueba, con retroalimentación inmediata explicando el ejercicio y un flujo de preguntas.

---

## Objetivo general
Desarrollar una primera versión en C que permita a los estudiantes practicar preguntas tipo PAES M1, de forma dinámica, rápida y con retroalimentación.

## Objetivos específicos
- Implementar un banco de preguntas de ejemplo (en esta versión: 8 preguntas demo distribuidas en las 4 areás de lo ejes Paes: Aritmética, Álgebra, Geometría y Datos/Probabilidad).
- Validar respuestas con 3 alternativas (A/B/C), indicando si son correctas o incorrectas.
- Entregar retroalimentación inmediata en caso de error.
- Implementar funciones clave para cada parte del programa (mostrar pregunta, leer respuesta, validar, feedback, ejecución).
- Incluir un modo de pruebas básicas (`--test`) que verifica consistencia del programa.

---

## Funcionalidades implementadas
- Render de pregunta: se muestran enunciado, eje PAES y 3 alternativas.
- Lectura de alternativa: entrada de usuario (A, B o C).
- Validación de respuesta: compara con la alternativa correcta.
- Feedback inmediato: 
  -  Correcto  
  -  Incorrecto (con explicación breve)  
- Ejecución de todas las preguntas del banco.
- Modo pruebas (`--test`)**: valida que el banco esté cargado, que "MAX_OPTIONS" sea 3, y que la función de validación responda correctamente.

---

## 📂 Estructura del repositorio
```
paes_m1_hito1/
├─ src/
│  └─ main.c
├─ README.md
└─ AI_USAGE.md
```

---

## 🖥️ Compilación y ejecución

### En Linux / MacOS
```bash
gcc -std=c11 -O2 -Wall -Wextra -o paes src/main.c
./paes          # ejecución normal
./paes --test   # pruebas básicas
```

### En Windows (MinGW)
```bash
gcc -std=c11 -O2 -Wall -Wextra -o paes.exe src\main.c
paes.exe
paes.exe --test
```

---

## 🧪 Casos de prueba (ejemplo)

**Caso correcto**  
```
[1/8] Eje: Aritmetica
Si 3x + 2 = 14, entonces x es:
  A) 3
  B) 4
  C) 5
Elige (A/B/C): B
 Correcto!
```

**Caso incorrecto**  
```
[2/8] Eje: Aritmetica
El 25% de 240 es:
  A) 50
  B) 60
  C) 75
Elige (A/B/C): A
 Incorrecto. Explicacion: 25% = 0.25; 0.25·240 = 60.
```

---

##  Roles del equipo
| Integrante | Rol | Responsabilidades |
|------------|-----|-------------------|
| DIEGO ALARCON  | Desarrollo | Implementación en C, funciones y pruebas |
| MARTIN LOPEZ | Contenido  | Banco de preguntas, validación pedagógica |
| AGUSTIN LUCERO  | GitHub/Docs | Issues, milestone, project board, README |
| MAXIMILIANO VEGA | QA/Video   | Pruebas de usuario, guion de presentación |


##  Avance y próximos pasos (Hito 2)  
  - Código ejecutable en consola con 8 preguntas.  
  - Funciones clave implementadas.  
  - Retroalimentación inmediata.  
  - Modo de pruebas básicas.  

## Próximos pasos: 
  - Ampliar banco de preguntas a 20 (5 por eje), solo hicimos 8 preguntas para saber si estaba bien implementado el codigo.  
  - Añadir métricas: porcentaje de aciertos, estadísticas por eje.  
  - Implementar carga de preguntas desde archivo externo (CSV/JSON).  
  - Mejorar feedback con explicaciones más detalladas y no solo la explicación basica .  
  - Continuar con milestones y issues para organizar avance.  

## 📚 Referencias
- Sintaxis Markdown: [https://markdown.es](https://markdown.es)  
- Material de referencia PAES Matemáticas.  
