#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <QtGlobal>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QDialogButtonBox>
#include <QInputDialog>
#include <QFormLayout>
#include <QMessageBox>
#include <QLabel>
#include <QColorDialog>
#include <vector>
#include <QTime>
#include <QTimer>
#include <QDebug>

//enum Operation {noop,ellipse,rectangle,line};

class ImageView : public QGraphicsView
{
    Q_OBJECT
public:
    // http://en.cppreference.com/w/cpp/language/explicit
    explicit ImageView(QWidget *parent = 0);

signals:
    void addingScore(int);
    //void addingScore(QString);

public slots:
    void mousePressEvent(QMouseEvent * e);
    void startingGame(bool triggered);
    void pausingGame(bool triggered);
    void resettingGame(bool triggered);

private:
    QGraphicsScene *scene = new QGraphicsScene;
    QPointF original_position;
    QPointF last_position;

    //void startingGame(bool triggered);
    qreal get_rand_height();
    qreal get_rand_width();
};
#endif // IMAGEVIEW_H
