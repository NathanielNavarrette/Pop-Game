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
    connect(parent,SIGNAL(startingGame(bool)),this,SLOT(startingGame(bool)));
    connect(parent,SIGNAL(pausingGame(bool)),this,SLOT(pausingGame(bool)));
    connect(parent,SIGNAL(resettingGame(bool)),this,SLOT(resettingGame(bool)));

}

QPointF ImageView::get_rand_pos()
{
    QPointF rand_pos;
    rand_pos.setX(qreal(qrand() % this->size().height()-10 )+10 );
    rand_pos.setY(qreal(qrand() % this->size().width()-10 )+10 );
}


void ImageView::startingGame(bool triggered)
{

    auto pos = get_rand_pos();

    /*
    for(int i=0;i<15;i++)
    {
        scene->addEllipse(pos.x(),pos.y(),		//x,y position of the upper left hand corner
                          qrand()%50 + 50, qrand()%50 + 50,				// width and height of the rectangle
                          QPen(Qt::blue),		// the pen used for the outline
                          QBrush(Qt::blue)); 	// the brush used for the inside of the ellipse

    }
    */

    last_position = pos;
}

void ImageView::pausingGame(bool triggered)
{

}

void ImageView::resettingGame(bool triggered)
{

}
