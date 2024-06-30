#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QCoreApplication>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLayoutItem>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), mascota(new Mascota("Garfield")), inventario(new Inventario), timer(new QTimer(this)), tiempoTranscurrido(0) {
    ui->setupUi(this);

    // Cargar el inventario desde el archivo CSV
    QDir dir(QCoreApplication::applicationDirPath());
    QString path = dir.filePath("config.csv");
    qDebug() << "Ruta del archivo CSV:" << path;
    inventario->cargarDesdeCSV(path.toStdString());

    connect(timer, &QTimer::timeout, this, &MainWindow::actualizarSimulacion);

    crearLayoutsInventario();
    crearBotonesInventario();
    actualizarInterfaz();

    // Configurar imagen de la mascota
    QPixmap pixmap(":/images/mascota.png");
    if (pixmap.isNull()) {
        qDebug() << "Error: No se pudo cargar la imagen de la mascota.";
    } else {
        ui->lblImagenMascota->setPixmap(pixmap);
        ui->lblImagenMascota->setScaledContents(true);
    }

    // Iniciar el temporizador automáticamente
    timer->start(500); // Iniciar el temporizador para actualizar cada 0.5 segundos
}

MainWindow::~MainWindow() {
    delete ui;
    delete mascota;
    delete inventario;
}

Inventario* MainWindow::getInventario() const {
    return inventario;
}

void MainWindow::usarItem() {
    qDebug() << "Slot usarItem() llamado";
    QObject* senderObj = sender();
    QPushButton* button = qobject_cast<QPushButton*>(senderObj);
    if (!button) return;

    int id = button->property("itemId").toInt();
    qDebug() << "ID del item: " << id;
    Item *inventarioItem = inventario->obtenerItem(id);
    if (inventarioItem) {
        if (dynamic_cast<Comida*>(inventarioItem)) {
            mascota->usarComida();
        } else if (dynamic_cast<Medicina*>(inventarioItem)) {
            mascota->usarMedicina();
        } else if (dynamic_cast<Juguete*>(inventarioItem)) {
            mascota->usarJuguete();
        }
        inventarioItem->usar();
        actualizarInterfaz();
    }
}

void MainWindow::actualizarSimulacion() {
    tiempoTranscurrido += 0.5;
    mascota->avanzarTiempo(0.5 * 86400.0); // Avanza 0.5 días en cada llamada
    actualizarInterfaz();

    if (mascota->getEstado() == Mascota::Muerto || tiempoTranscurrido >= 15.0) {
        QMessageBox::information(this, "Fin de la Simulación", "La mascota ha muerto.");
        QCoreApplication::quit(); // Cierra la aplicación
    }
}

void MainWindow::actualizarInterfaz() {
    qDebug() << "Actualizando interfaz";
    ui->lblNombreValor->setText(QString::fromStdString(mascota->getNombre()));
    ui->lblEdadValor->setText(QString::number(mascota->getEdad(), 'f', 2)); // Muestra la edad con dos decimales
    ui->progressSalud->setValue(mascota->getSalud());
    ui->progressEnergia->setValue(mascota->getEnergia());
    ui->progressFelicidad->setValue(mascota->getFelicidad());

    QString estadoStr;
    switch (mascota->getEstado()) {
    case Mascota::Feliz: estadoStr = "Feliz"; break;
    case Mascota::Triste: estadoStr = "Triste"; break;
    case Mascota::Hambriento: estadoStr = "Hambriento"; break;
    case Mascota::Enojado: estadoStr = "Enojado"; break;
    case Mascota::Cansado: estadoStr = "Cansado"; break;
    case Mascota::Muerto: estadoStr = "Muerto"; break;
    default: estadoStr = "Neutro"; break;
    }
    ui->lblEstado->setText(estadoStr);
}

void MainWindow::crearLayoutsInventario() {
    // Crear layouts verticales para cada pestaña
    QVBoxLayout *layoutAlimentos = new QVBoxLayout();
    ui->widgetAlimentos->setLayout(layoutAlimentos);

    QVBoxLayout *layoutMedicina = new QVBoxLayout();
    ui->widgetMedicina->setLayout(layoutMedicina);

    QVBoxLayout *layoutJuguetes = new QVBoxLayout();
    ui->widgetJuguetes->setLayout(layoutJuguetes);
}

void MainWindow::crearBotonesInventario() {
    // Limpiar los layouts existentes en las pestañas del inventario
    QLayoutItem* child;
    while ((child = ui->widgetAlimentos->layout()->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
    while ((child = ui->widgetMedicina->layout()->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
    while ((child = ui->widgetJuguetes->layout()->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    // Crear y añadir botones a las pestañas del inventario
    for (const auto& item : inventario->getItems()) {
        QPushButton *button = new QPushButton(QString::fromStdString(item->getNombre()));
        button->setProperty("itemId", item->getId());
        connect(button, &QPushButton::clicked, this, &MainWindow::usarItem);

        if (dynamic_cast<Comida*>(item)) {
            ui->widgetAlimentos->layout()->addWidget(button);
        } else if (dynamic_cast<Medicina*>(item)) {
            ui->widgetMedicina->layout()->addWidget(button);
        } else if (dynamic_cast<Juguete*>(item)) {
            ui->widgetJuguetes->layout()->addWidget(button);
        }
    }
}
