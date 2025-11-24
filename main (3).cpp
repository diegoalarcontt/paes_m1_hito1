\
    #include <QApplication>
    #include <cstring>

    #include "MainWindow.h"
    #include "Cuestionario.h"

    int main(int argc, char *argv[])
    {
        // Modo de prueba por consola
        for (int i = 1; i < argc; ++i) {
            if (std::strcmp(argv[i], "--test") == 0) {
                Cuestionario quiz;
                return quiz.modoTest();
            }
        }

        QApplication app(argc, argv);

        MainWindow w;
        w.show();

        return app.exec();
    }
