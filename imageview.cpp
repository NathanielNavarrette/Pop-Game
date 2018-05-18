#include "imageView.h"

ImageView::ImageView(QWidget *parent) :
    QGraphicsView(parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(QRectF(-200,-200,400,400));
    this->setScene(scene);
    last_position.setX(0);
    last_position.setY(0);

    this->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    //connect(widgetA, SIGNAL(signal()), widgetB, SLOT(slot());
    connect(parent,SIGNAL(startingGame(bool)),this,SLOT(startingGame(bool)));
    connect(parent,SIGNAL(pausingGame(bool)),this,SLOT(pausingGame(bool)));
    connect(parent,SIGNAL(resettingGame(bool)),this,SLOT(resettingGame(bool)));

}

void ImageView::mousePressEvent(QMouseEvent * e)
{
    //auto pos = get_rand_pos();

    auto pos = mapToScene(e->pos());
    int width = qrand()%50 + 50;
    int height = qrand()%50 + 50;

    if(e->button() == Qt::LeftButton)
    {
        scene->addEllipse(pos.x()-(width/2),pos.y()-(height/2),		//x,y position of the upper left hand corner
                          width, height,				// width and height of the rectangle
                          QPen(Qt::blue),		// the pen used for the outline
                          QBrush(Qt::blue)); 	// the brush used for the inside of the ellipse

        emit addingScore(50);

        qDebug() << "Mouse click pos:" << "X:" << pos.x() << "  Y:" << pos.y();
    }else if(e->button() == Qt::RightButton){
        scene->clear();
    }
}

qreal ImageView::get_rand_height()
{
    int max_height = scene->height()-10;
    qsrand(QDateTime::currentMSecsSinceEpoch()%5000);
    int rand2 = qrand();
    if(rand2 % 4 == 0)
        rand2 *= -1;
    rand2 %= max_height;

    return rand2;
}

qreal ImageView::get_rand_width()
{
    int max_width = scene->width()-10;
    qsrand(QDateTime::currentMSecsSinceEpoch()%5000);
    int rand2 = qrand();
    if(rand2 % 4 == 0)
        rand2 *= -1;
    rand2 %= max_width;

    return rand2;
}


void ImageView::startingGame(bool triggered)
{
    qDebug() << "Starting Game ImageView";
    QPointF pos;
    pos.setX(get_rand_width());
    QTimer *waitFor = new QTimer;
    waitFor->setSingleShot(true);
    waitFor->start(400);
    for(int j=0;j<5959595;j++)
    {
        //do nothing
    }
    pos.setY(get_rand_height());

    qDebug() << "X:" << pos.x() << "  Y:" << pos.y();

    for(int i=0;i<1;i++)
    {
        scene->addEllipse(pos.x(),pos.y(),		//x,y position of the upper left hand corner
                          qrand()%50 + 50, qrand()%50 + 50,				// width and height of the rectangle
                          QPen(Qt::blue),		// the pen used for the outline
                          QBrush(Qt::blue)); 	// the brush used for the inside of the ellipse
    }
    last_position = pos;
}

void ImageView::pausingGame(bool triggered)
{
    qDebug() << "Pausing Game ImageView";
}

void ImageView::resettingGame(bool triggered)
{
    //qDebug() << "Resetting Game ImageView";
    scene->clear();
}
