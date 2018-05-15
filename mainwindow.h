#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void resetGame(bool pressed);
    void startGame(bool pressed);
    void pauseGame(bool pressed);

signals:
    void startingGame(bool);
    void pausingGame(bool);
    void resettingGame(bool);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
