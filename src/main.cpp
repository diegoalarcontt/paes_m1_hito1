#include "Cuestionario.h"
#include <cstring>

int main(int argc, char** argv) {
    Cuestionario quiz;

    if (argc > 1 && std::strcmp(argv[1], "--test") == 0)
        return quiz.modoTest();

    quiz.ejecutar();
    return 0;
}
