#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//Includes for widgets
#include "imageView.h"
#include "scoreboard.h"
#include <QWidget>
#include <QDebug>
#include <QTimer>
#include <QPushButton>
#include <QLCDNumber>
#include <QTextEdit>
#include <QRadioButton>
#include <QLayout>
#include <QThread>

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

    void startGame();

    void mousePressed(int score_add);
    void autoChecked(bool checked);


signals:
    void startingGame(bool);
    void pausingGame(bool);
    void resettingGame(bool);

    void mousepressing(int);

private:
    Ui::MainWindow *ui;
    void mousePressEvent(QMouseEvent * e);

    QTimer *autoTimer = new QTimer;

    QWidget *topWidget = new QWidget(this);
    QVBoxLayout * m_layout = new QVBoxLayout(this);
    QHBoxLayout *topWidgetLayout = new QHBoxLayout(topWidget);
    QWidget *startButton = new QPushButton("Start Game", topWidget);
    QWidget *pauseButton = new QPushButton("Pause Game", topWidget);
    QWidget *resetButton = new QPushButton("Reset Game", topWidget);
    QRadioButton *autoRunBtn = new QRadioButton("Auto Run", topWidget);

    QLCDNumber *lcdScore = new ScoreBoard(topWidget);
    QWidget *scoreText = new QLabel("Score:", topWidget);

    QWidget * imgView = new ImageView(this);
    QHBoxLayout * imgSpace = new QHBoxLayout(imgView);

};

#endif // MAINWINDOW_H
