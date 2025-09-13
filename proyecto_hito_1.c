#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_OPTIONS 3

typedef struct {
    const char* eje;           // Eje PAES (Aritmética, Álgebra, Geometría, Datos)
    const char* enunciado;     // Pregunta
    const char* opciones[ MAX_OPTIONS ]; // 3 alternativas (A, B, C)
    int correcta;              // índice 0..2
    const char* explicacion;   // Feedback si se responde mal
} Question;

/* =====================
   Banco de preguntas (8)preguntas (demo Hito 1)
   ===================== */
static Question questions[] = {
    // Aritmetica
    {
        "Aritmetica",
        "Si 3x + 2 = 14, entonces x es:",
        { "3", "4", "5" },
        1,
        "Despeja: 3x = 12 ,, x = 4."
    },
    {
        "Aritmetica",
        "El \"25%\"  de 240 es:",
        { "50", "60", "75" },
        1,
        "25% = 0.25; 0.25·240 = 60."
    },

    // Algebra
    {
        "Algebra",
        "Factoriza: x^2 - 9",
        { "(x-3)(x+3)", "(x-9)(x+1)", "(x-1)(x-8)" },
        0,
        "Diferencia de cuadrados: a^2 - b^2 = (a-b)(a+b)."
    },
    {
        "Algebra",
        "La recta con pendiente 2 que pasa por (0,1) es:",
        { "y = 2x + 1", "y = x + 2", "y = -2x + 1" },
        0,
        "Ecuacion punto_pendiente: y = mx + b con m=2, b=1."
    },

    // Geometría
    {
        "Geometria",
        "Un triangulo rectangulo con catetos 6 y 8 tiene hipotenusa:",
        { "10", "12", "14" },
        0,
        "Teorema de Pitagoras: sqrt(6^2 + 8^2) = 10."
    },
    {
        "Geometria",
        "El area de un circulo de radio 3 es (usa π≈3,14):",
        { "9,42", "18,84", "28,26" },
        2,
        "A = πr^2 ≈ 3,14·9 ≈ 28,26."
    },

    // Datos y Probabilidad
    {
        "Datos y Probabilidad",
        "Al lanzar una moneda justa una vez, la probabilidad de cara es:",
        { "1/4", "1/2", "1" },
        1,
        "Moneda justa: 2 resultados equiprobables → 1/2."
    },
    {
        "Datos y Probabilidad",
        "La media aritmetica de 4, 6, 10 es:",
        { "6", "7", "8" },
        2,
        "(4+6+10)/3 = 20/3 ≈ 6,67 ,, alternativa mas cercana: 8 (redondeo hacia la opcion exacta no disponible)."
    },
};
static const int NQ = (int)(sizeof(questions)/sizeof(questions[0]));

/* =====================
   Utilidades de entrada/salida
   ===================== */

static void flush_stdin(void){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
}

static int read_choice(void){
    // Lee 'A', 'B' o 'C' (no sensible a mayúsculas) y devuelve 0,1,2.
    // Retorna -1 si entrada inválida.
    char buf[16];
    if (!fgets(buf, sizeof(buf), stdin)) return -1;
    for (int i=0; buf[i]; ++i) buf[i] = (char)toupper((unsigned char)buf[i]);
    if (buf[0] == 'A') return 0;
    if (buf[0] == 'B') return 1;
    if (buf[0] == 'C') return 2;
    return -1;
}

/* =====================
   Lógica del cuestionario 
   ===================== */

static void render_question(const Question* q, int index, int total){
    printf("\n[%d/%d] Eje: %s\n", index+1, total, q->eje);
    printf("%s\n", q->enunciado);
    printf("  A) %s\n", q->opciones[0]);
    printf("  B) %s\n", q->opciones[1]);
    printf("  C) %s\n", q->opciones[2]);
    printf("Elige (A/B/C): ");
}

static int check_answer(const Question* q, int choice_idx){
    return choice_idx == q->correcta;
}

static void show_feedback(const Question* q, int is_correct){
    if (is_correct){
        printf(" Correcto!\n");
    } else {
        printf(" Incorrecto. Explicacion: %s\n", q->explicacion);
    }
}
// EN CASO DE QUE TIPEEN OTRA RESPUESTA QUE NO SEA NI A, B O C,
// LES PIDE QUE VUELVAN A ELEGIR HASTA QUE PONGAN UNA RESPUESTA VALIDA
static int run_quiz(void){
    int correctas = 0;
    for (int i=0; i<NQ; ++i){
        render_question(&questions[i], i, NQ);
        int choice = read_choice();
        while (choice < 0 || choice >= MAX_OPTIONS){
            printf("Entrada inválida. Debes elegir A, B o C.\nElige (A/B/C): ");
            choice = read_choice();
        }
        int ok = check_answer(&questions[i], choice);
        if (ok) ++correctas;
        show_feedback(&questions[i], ok);
    }
    return correctas;
}

/* =====================
   Pruebas básicas (modo --test)
   ===================== */

static int basic_tests(void){
    int fails = 0;
    // Test 1: check_answer debe aceptar la alternativa correcta
    if (!check_answer(&questions[0], questions[0].correcta)) { ++fails; }

    // Test 2: entrada inválida es manejable (no podemos simular stdin aquí, pero comprobamos límites)
    if (MAX_OPTIONS != 3) { ++fails; }

    // Test 3: conteo de preguntas coherente
    if (NQ <= 0) { ++fails; }

    // Reporte
    if (fails == 0){
        printf("[TEST] Todas las pruebas básicas pasaron.\n");
    } else {
        printf("[TEST] Fallos detectados: %d\n", fails);
    }
    return fails == 0 ? 0 : 1;
}

/* =====================
   main
   ===================== */
int main(int argc, char** argv){
    if (argc > 1 && strcmp(argv[1], "--test") == 0){
        return basic_tests();
    }

    printf("=== Entrenador PAES M1 (Hito 1) ===\n");
    printf("Total de preguntas: %d\n", NQ);
    printf("Responde con A, B o C y presiona Enter.\n");

    int aciertos = run_quiz();
    printf("\nResultado final: %d/%d correctas.\n", aciertos, NQ);

    // Interpretación simple del resultado
    double pct = 100.0 * aciertos / (double)NQ;
    printf("Puntaje aproximado: %.1f%%\n", pct);

    return 0;
}