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
#include <QDebug>

//enum Operation {noop,ellipse,rectangle,line};

class ImageView : public QGraphicsView
{
    Q_OBJECT
public:
    // http://en.cppreference.com/w/cpp/language/explicit
    explicit ImageView(QWidget *parent = 0);

signals:

public slots:
    void mousePressEvent(QMouseEvent * e);
    void startingGame(bool triggered);
    void pausingGame(bool triggered);
    void resettingGame(bool triggered);

private:
    QGraphicsScene * scene;
    QPointF original_position;
    QPointF last_position;

    //void startingGame(bool triggered);
    QPointF get_rand_pos();
};
#endif // IMAGEVIEW_H
