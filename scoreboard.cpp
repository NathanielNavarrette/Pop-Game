#include "scoreboard.h"

ScoreBoard::ScoreBoard(QWidget *parent) : QLCDNumber(parent)
{
    connect(this->parent()->parent(), SIGNAL(mousepressing(int)), this, SLOT(addScore(int)));
    connect(this->parent()->parent(), SIGNAL(resettingGame(bool)), this, SLOT(resetScore(bool)));

    setSegmentStyle(Filled);

    showScore();

    setWindowTitle(tr("Score Board:"));
    resize(150, 60);
}

void ScoreBoard::showScore()
{
    QString text = QString::number(m_current_score);
    display(text);
}

void ScoreBoard::addScore(int added_score)
{
    m_current_score += added_score;
    QString text = QString::number(m_current_score);
    display(text);
    //qDebug() << "Added score" << added_score;
}

void ScoreBoard::resetScore(bool check)
{
    //qDebug() << "Reset score, scoreboard";
    if(!check)
    {
        //qDebug() << "reset if inside";
        this->m_current_score = 0;
    }
    QString text = QString::number(m_current_score);
    display(text);
}
