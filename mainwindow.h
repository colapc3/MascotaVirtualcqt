#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "Mascota.h"
#include "Inventario.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Inventario* getInventario() const;

private slots:
    void usarItem();
    void actualizarSimulacion();

private:
    Ui::MainWindow *ui;
    Mascota *mascota;
    Inventario *inventario;
    QTimer *timer;
    double tiempoTranscurrido; // Declarar tiempoTranscurrido

    void actualizarInterfaz();
    void crearLayoutsInventario();
    void crearBotonesInventario();
};

#endif // MAINWINDOW_H
