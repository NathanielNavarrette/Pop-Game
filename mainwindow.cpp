#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    topWidgetLayout->addWidget(startButton);
    topWidgetLayout->addWidget(pauseButton);
    topWidgetLayout->addWidget(resetButton);
    topWidgetLayout->addStretch(1);
    scoreText->setMaximumWidth(100);
    topWidgetLayout->addWidget(scoreText);
    topWidgetLayout->addWidget(lcdScore);
    topWidget->setFixedHeight(50);

    imgSpace->addWidget(new ImageView(this) );

    connect(startButton, SIGNAL(clicked(bool)), this, SLOT(startGame(bool)));
    connect(pauseButton, SIGNAL(clicked(bool)), this, SLOT(pauseGame(bool)));
    connect(resetButton, SIGNAL(clicked(bool)), this, SLOT(resetGame(bool)));
    connect(imgView, SIGNAL(addingScore(int)), lcdScore, SLOT(display(int)));
    connect(imgView, SIGNAL(addingScore(QString)), scoreText, SLOT(setText(QString)));

    QTimer *timer = new QTimer(this);
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), lcdScore, SLOT(tick()));

    m_layout->addWidget(topWidget);
    m_layout->addWidget(imgView);

    ui->centralWidget->setLayout(m_layout);
    this->setMinimumHeight(125);
    this->setMinimumWidth(465);
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

void MainWindow::addingScore(int add_score)
{
    lcdScore->show();
}
