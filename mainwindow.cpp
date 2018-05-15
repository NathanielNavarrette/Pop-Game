#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imageView.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->layout()->addWidget(new ImageView(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resetGame(bool pressed)
{
    qDebug() << "Reset Game button Pressed";
    emit resettingGame(pressed);
}

void MainWindow::startGame(bool pressed)
{
    qDebug() << "Start Game button Pressed";
    emit startingGame(pressed);
}

void MainWindow::pauseGame(bool pressed)
{
    qDebug() << "Pause Game button Pressed";
    emit pausingGame(pressed);
}
