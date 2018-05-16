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
        emit addingScore(QString::number(50));
    }else if(e->button() == Qt::RightButton){
        scene->clear();
    }


}

QPointF ImageView::get_rand_pos()
{
    /*
    QPointF rand_pos;
    QTime time = time.currentTime();
    int rand_num_array[100];
    int r_num;
    for(int i-0;i<100;i++)
        rand_num_array[i] = time.msec(); //random number between 0 and 999

    r_num = rand_num_array[time.msec() % 100];

    qDebug() << "Random Number:" << r_num;

    int maxHeight = this->size().height()-10;
    int maxWidth  = this->size().width()-10;

    rand_pos.setX(qreal(r_num % maxHeight));
    rand_pos.setY(qreal(r_num % maxHeight));

    return rand_pos;
    */

    //rand_pos.setX(qreal(qrand() % this->size().height()-10 )+10 );
    //rand_pos.setY(qreal(qrand() % this->size().width()-10 )+10 );
}


void ImageView::startingGame(bool triggered)
{
    qDebug() << "Starting Game ImageView";
    QPointF pos = get_rand_pos();

    qDebug() << "X:" << pos.x() << "  Y:" << pos.y();

    for(int i=0;i<15;i++)
    {
        scene->addEllipse(pos.x(),pos.y(),		//x,y position of the upper left hand corner
                          qrand()%50 + 50, qrand()%50 + 50,				// width and height of the rectangle
                          QPen(Qt::blue),		// the pen used for the outline
                          QBrush(Qt::blue)); 	// the brush used for the inside of the ellipse
        for(int j=0;j<500000;j++)
        {
            //do nothing
        }
    }


    last_position = pos;
}

void ImageView::pausingGame(bool triggered)
{
    qDebug() << "Pausing Game ImageView";
}

void ImageView::resettingGame(bool triggered)
{
    qDebug() << "Resetting Game ImageView";
}
