# CMATH — Hito 3  
Entrenador matemático interactivo con Qt y C++

Resumen del proyecto  
   CMATH es una aplicación interactiva diseñada para practicar contenidos matemáticos tipo PAES.  
   El usuario responde preguntas de selección múltiple, recibe retroalimentación inmediata y ve su avance en tiempo real.  

   En este hito migramos el sistema de consola del Hito 2 a una **interfaz gráfica Qt**, manteniendo la lógica previa pero mejorando completamente la experiencia del usuario.

---

Interfaz gráfica desarrollada

   * Objetivo de la interfaz  
      - Presentar preguntas matemáticas de forma clara.  
      - Permitir seleccionar una alternativa mediante radio buttons.  
      - Entregar retroalimentación inmediata.  
      - Mostrar el avance del usuario de manera simple y directa.

   * Elementos principales (widgets)  
      - `QLabel` → título, eje, enunciado, feedback  
      - `QRadioButton` → alternativas  
      - `QPushButton` → Responder / Siguiente  
      - `QMessageBox` → mensaje final  
      - `QVBoxLayout`, `QHBoxLayout` → distribución de la interfaz  

   * Comportamiento esperado  
      1. El usuario ve una pregunta y sus alternativas.  
      2. Selecciona una respuesta y presiona **Responder**.  
      3. La interfaz muestra si la respuesta es correcta o incorrecta.  
      4. Con el botón **Siguiente**, avanza a la próxima pregunta.  
      5. Al finalizar, se muestra el puntaje total del usuario.



Clases y estructura del programa

   * Clase `Pregunta`
      Representa una pregunta del cuestionario e incluye:  
      - Enunciado  
      - Eje temático  
      - Alternativas  
      - Índice de la respuesta correcta  
      - Explicación  
      - Método `validar()` para revisar la respuesta del usuario  

   * Clase `Cuestionario`
      Administra el conjunto de preguntas:  
      - Avanza entre preguntas  
      - Valida respuestas con `responder()`  
      - Cuenta aciertos  
      - Calcula porcentaje final  
      - Tiene `modoTest()` para ejecución sin GUI  

---

Signals y Slots en Qt

   * Señales utilizadas
      - `clicked()` en boton **Responder**  
      - `clicked()` en boton **Siguiente**

   * Slots asociados
      - `onResponderClicked()`  
      - `onSiguienteClicked()`

   * Relación con la lógica
      Los slots llaman funciones del `Cuestionario`, actualizan la GUI y controlan el flujo del programa.

---

Principales desafíos del Hito 3
- Integrar Qt con la lógica creada en el Hito 2.  
- Sincronizar el estado interno del cuestionario con la interfaz.  
- Actualizar widgets dinámicamente.  
- Deshabilitar opciones después de responder.  
- Mantener el modo `--test` operativo.  

---

* Registro de herramientas de IA utilizadas
   Se utilizaron herramientas de IA generativa para:  
   - Proponer estructura de la interfaz Qt.  
   - Generar y revisar código de clases.  
   - Elaborar documentación como README y AI_USAGE.md.  
   - Crear mockups representativos de la interfaz.  
   - Generar descripciones y guiones para la presentación.

* Limitaciones observadas:  
   - Algunas correcciones manuales fueron necesarias para compilar.  
   - Los estilos visuales sugeridos no siempre coinciden con Qt real.

--- 

* Modo Test (`--test`)

Modo de ejecución sin GUI:

Resultados:  
   - `0` → configuración correcta  
   - `1` → error detectado  

---

Este repositorio incluye:  
   - Milestone **Hito 3**  
   - Issues asociadas  
   - Project Board con To-Do / Doing / Done  
   - Archivo `AI_USAGE.md` actualizado  

---
  
Diego Alarcón / Martin Lopez / Agustín Lucero  
Proyecto académico — Ingeniería Civil Química  
Hito 3 — Programación + Qt
