#include "myclass.h"

Myclass::Myclass(QObject *parent) :
    QObject(parent)
{
}

void Myclass::go()
{
    QTimer *timer = new QTimer(this);

    timer->connect(timer, SIGNAL(timeout()),this, SLOT(firstTry()));
    timer->start(1000);
}


void Myclass::firstTry()
{
    qDebug() << "lol";
}

