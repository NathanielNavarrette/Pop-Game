#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//Includes for widgets
#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include <QLCDNumber>
#include <QTextEdit>
#include <QLayout>

enum SizeConstraint { SetDefaultConstraint, SetFixedSize, SetMinimumSize, SetMaximumSize, SetMinAndMaxSize, SetNoConstraint };

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
    void mousePressEvent(QMouseEvent * e);

};

#endif // MAINWINDOW_H
