#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QtCore>
#include <iostream>

class Myclass : public QObject
{
    Q_OBJECT
public:
    explicit Myclass(QObject *parent = 0);
    void go();

signals:

public slots:
void firstTry();
};

#endif // MYCLASS_H
