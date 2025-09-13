# AI_USAGE.md

## Herramientas utilizadas
- ChatGPT (GPT-5, OpenAI)

## Para qué se utilizó
- Generar la primera versión del código en C para la consola.
- Sugerir la estructura de funciones (mostrar preguntas, leer respuesta, validar, feedback, pruebas básicas).
- Crear un archivo readme vacío para añadir el Estado del proyecto.
- Apoyo en la organización del repositorio (issues, milestone, project board).

## Prompts representativos
- “Hazme un código esqueleto que pide en el hito uno a base de la primera idea que te mandé, para yo agregarle las distintas preguntas/ejercicios.”
- “Hazme un README vacío para el proyecto para descargar.”

## Observaciones / Limitaciones
- El banco de preguntas inicial fue generado como ejemplo. El grupo debe revisar y validar pedagógicamente cada ejercicio.
- No se usaron librerías externas; el código funciona en consola, pero aún no contempla entrada masiva de datos ni archivos.
- La IA puede proponer formatos o estilos de redacción, pero el equipo debe ajustar el tono y el contenido final para que represente su trabajo.
- Se recomienda no depender al 100% de la IA: el código fue probado en modo `--test`, pero se deben realizar pruebas adicionales.

## Buenas prácticas aplicadas
- Código organizado en `src/` con compilación clara en consola.
- Funciones separadas para cada funcionalidad clave.
- Retroalimentación documentada (correcto/incorrecto con explicación).
- Documentación del uso de IA en este archivo, cumpliendo con la rúbrica.
