#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//Includes for widgets
#include "imageView.h"
#include <QWidget>
#include <QDebug>
#include <QTimer>
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
    void addingScore(int add_score);

signals:
    void startingGame(bool);
    void pausingGame(bool);
    void resettingGame(bool);

private:
    Ui::MainWindow *ui;
    void mousePressEvent(QMouseEvent * e);

    QWidget * imgView = new ImageView(this);
    QHBoxLayout * imgSpace = new QHBoxLayout(imgView);
    QWidget *topWidget = new QWidget;
    QLCDNumber *lcdScore = new QLCDNumber(10, topWidget);
    QWidget *scoreText = new QTextEdit("Score:", topWidget);
    QVBoxLayout * m_layout = new QVBoxLayout(this);
    QHBoxLayout *topWidgetLayout = new QHBoxLayout(topWidget);
    QWidget *startButton = new QPushButton("Start Game", topWidget);
    QWidget *pauseButton = new QPushButton("Pause Game", topWidget);
    QWidget *resetButton = new QPushButton("Reset Game", topWidget);


};

#endif // MAINWINDOW_H
