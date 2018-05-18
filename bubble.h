#ifndef BUBBLE_H
#define BUBBLE_H

#include <QObject>
#include <QWidget>
#include <QPoint>
#include <QLabel>
#include <QPixmap>

class Bubble : public QWidget
{
    Q_OBJECT
public:
    explicit Bubble(QWidget *parent = nullptr);

private:
    QLabel *bubble_img = new QLabel;
    QPixmap *bubble_file = new QPixmap("bubble.png");
    QPointF *current_pos = new QPointF;

signals:

public slots:
};

#endif // BUBBLE_H
