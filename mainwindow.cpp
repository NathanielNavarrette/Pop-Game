#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imageView.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVBoxLayout * m_layout = new QVBoxLayout(this);

    QWidget *topWidget = new QWidget;
    QHBoxLayout *topWidgetLayout = new QHBoxLayout(topWidget);

    QWidget *startButton = new QPushButton("Start Game", topWidget);
    QWidget *pauseButton = new QPushButton("Pause Game", topWidget);
    QWidget *resetButton = new QPushButton("Reset Game", topWidget);
    topWidgetLayout->addWidget(startButton);
    topWidgetLayout->addWidget(pauseButton);
    topWidgetLayout->addWidget(resetButton);

    topWidgetLayout->addStretch(1);
    QWidget *scoreText = new QTextEdit("Score:", topWidget);
    scoreText->setMaximumWidth(100);
    topWidgetLayout->addWidget(scoreText);
    topWidgetLayout->addWidget(new QLCDNumber(10, topWidget) );
    topWidget->setFixedHeight(50);



    QWidget * imgView = new QWidget;
    QHBoxLayout * imgSpace = new QHBoxLayout(imgView);

    imgSpace->addWidget(new ImageView(this) );

    connect(startButton, SIGNAL(clicked(bool)), this, SLOT(startGame(bool)));
    connect(pauseButton, SIGNAL(clicked(bool)), this, SLOT(pauseGame(bool)));
    connect(resetButton, SIGNAL(clicked(bool)), this, SLOT(resetGame(bool)));

    m_layout->addWidget(topWidget);
    m_layout->addWidget(imgView);



    ui->centralWidget->setLayout(m_layout);
    //ui->centralWidget->layout()->addWidget(new ImageView(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent * e)
{
    //auto pos = mapToScene(e->pos());
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
