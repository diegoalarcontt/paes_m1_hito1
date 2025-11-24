\
    #include "MainWindow.h"

    #include <QWidget>
    #include <QVBoxLayout>
    #include <QHBoxLayout>
    #include <QLabel>
    #include <QRadioButton>
    #include <QPushButton>
    #include <QMessageBox>
    #include <QFont>
    #include <QString>

    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
    {
        construirInterfaz();
        mostrarPreguntaActual();
        actualizarProgreso();
    }

    void MainWindow::construirInterfaz()
    {
        QWidget* central = new QWidget(this);
        QVBoxLayout* layout = new QVBoxLayout(central);

        m_lblTitulo = new QLabel("Entrenador PAES M1 (Hito 3 - Qt)", this);
        m_lblTitulo->setAlignment(Qt::AlignCenter);
        QFont f = m_lblTitulo->font();
        f.setPointSize(f.pointSize() + 4);
        f.setBold(true);
        m_lblTitulo->setFont(f);

        m_lblEje = new QLabel(this);
        m_lblEnunciado = new QLabel(this);
        m_lblEnunciado->setWordWrap(true);

        m_rbA = new QRadioButton(this);
        m_rbB = new QRadioButton(this);
        m_rbC = new QRadioButton(this);

        m_btnResponder = new QPushButton("Responder", this);
        m_btnSiguiente = new QPushButton("Siguiente", this);
        m_btnSiguiente->setEnabled(false);

        m_lblFeedback = new QLabel(this);
        m_lblProgreso = new QLabel(this);

        QVBoxLayout* layoutOpciones = new QVBoxLayout;
        layoutOpciones->addWidget(m_rbA);
        layoutOpciones->addWidget(m_rbB);
        layoutOpciones->addWidget(m_rbC);

        QHBoxLayout* layoutBotones = new QHBoxLayout;
        layoutBotones->addWidget(m_btnResponder);
        layoutBotones->addWidget(m_btnSiguiente);

        layout->addWidget(m_lblTitulo);
        layout->addSpacing(10);
        layout->addWidget(m_lblEje);
        layout->addWidget(m_lblEnunciado);
        layout->addSpacing(10);
        layout->addLayout(layoutOpciones);
        layout->addSpacing(10);
        layout->addLayout(layoutBotones);
        layout->addSpacing(10);
        layout->addWidget(m_lblFeedback);
        layout->addWidget(m_lblProgreso);

        setCentralWidget(central);

        connect(m_btnResponder, &QPushButton::clicked,
                this, &MainWindow::onResponderClicked);
        connect(m_btnSiguiente, &QPushButton::clicked,
                this, &MainWindow::onSiguienteClicked);

        setWindowTitle("PAES M1 Trainer - Hito 3");
        resize(600, 400);
    }

    void MainWindow::mostrarPreguntaActual()
    {
        const Pregunta& p = m_quiz.preguntaActual();

        m_lblEje->setText(QString::fromStdString("Eje: " + p.getEje()));
        m_lblEnunciado->setText(QString::fromStdString(p.getEnunciado()));

        const auto& opts = p.getOpciones();
        if (opts.size() >= 3) {
            m_rbA->setText(QString("A) %1").arg(QString::fromStdString(opts[0])));
            m_rbB->setText(QString("B) %1").arg(QString::fromStdString(opts[1])));
            m_rbC->setText(QString("C) %1").arg(QString::fromStdString(opts[2])));
        }

        m_rbA->setChecked(false);
        m_rbB->setChecked(false);
        m_rbC->setChecked(false);
        m_lblFeedback->clear();

        m_btnResponder->setEnabled(true);
        m_btnSiguiente->setEnabled(false);
        bloquearOpciones(false);
    }

    int MainWindow::indiceSeleccionado() const
    {
        if (m_rbA->isChecked()) return 0;
        if (m_rbB->isChecked()) return 1;
        if (m_rbC->isChecked()) return 2;
        return -1;
    }

    void MainWindow::actualizarProgreso()
    {
        int actual = m_quiz.indiceActual() + 1;
        int total = m_quiz.totalPreguntas();
        double pct = m_quiz.porcentajeCorrectas();

        m_lblProgreso->setText(
            QString("Pregunta %1 de %2 | Correctas: %3 | Puntaje: %4 %")
                .arg(actual)
                .arg(total)
                .arg(m_quiz.correctas())
                .arg(pct, 0, 'f', 1)
        );
    }

    void MainWindow::bloquearOpciones(bool bloqueado)
    {
        m_rbA->setEnabled(!bloqueado);
        m_rbB->setEnabled(!bloqueado);
        m_rbC->setEnabled(!bloqueado);
    }

    void MainWindow::onResponderClicked()
    {
        int indice = indiceSeleccionado();
        if (indice == -1) {
            QMessageBox::warning(this, "Sin respuesta",
                                 "Debes seleccionar una alternativa (A, B o C).");
            return;
        }

        bool ok = m_quiz.responder(indice);
        const Pregunta& p = m_quiz.preguntaActual();

        if (ok) {
            m_lblFeedback->setText(
                QString("✅ Correcto.\n%1")
                    .arg(QString::fromStdString(p.getExplicacion())));
        } else {
            m_lblFeedback->setText(
                QString("❌ Incorrecto.\n%1")
                    .arg(QString::fromStdString(p.getExplicacion())));
        }

        bloquearOpciones(true);
        m_btnResponder->setEnabled(false);
        m_btnSiguiente->setEnabled(true);
        actualizarProgreso();
    }

    void MainWindow::onSiguienteClicked()
    {
        if (!m_quiz.avanzar()) {
            double pct = m_quiz.porcentajeCorrectas();
            QString msg = QString("Has terminado el cuestionario.\n\n"
                                  "Correctas: %1 de %2\nPuntaje: %3 %")
                              .arg(m_quiz.correctas())
                              .arg(m_quiz.totalPreguntas())
                              .arg(pct, 0, 'f', 1);

            QMessageBox::information(this, "Resultado final", msg);
            m_btnSiguiente->setEnabled(false);
            bloquearOpciones(true);
            return;
        }

        mostrarPreguntaActual();
        actualizarProgreso();
    }
