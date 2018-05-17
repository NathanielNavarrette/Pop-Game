#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QLCDNumber>
#include <QDebug>

class ScoreBoard : public QLCDNumber
{
    Q_OBJECT
public:
    ScoreBoard(QWidget *parent = nullptr);

private:
    int m_current_score = 0;

signals:

private slots:
    void showScore();

public slots:
    void addScore(int added_score);
    void resetScore(bool check);
};

#endif // SCOREBOARD_H
