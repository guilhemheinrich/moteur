#ifndef ARRAYTOOLS_H
#define ARRAYTOOLS_H
#include <QtGui/QVector3D>
#include <QVector>
#include <QtDebug>

enum  motif {triangle};

class ArrayTools
{
public:
    ArrayTools();
    ArrayTools(int nr,int nc, int squareEdge);

    void randomMesh(int var);

    //void setTriangleMotif(QVector<int> motif);
    void setTriangleMotif(motif  motif);
    void makeIndex();
    void buildVertices();


    QVector<QVector3D> getPoints();
    QVector<int> getIndex();
    QVector<QVector3D *> getVertices();


private:
    int nRow,nCol;
    QVector<int> triangleMotif;

    QVector<int> index;

    QVector<QVector3D> points;
    QVector<QVector3D *> vertices;

};

#endif // ARRAYTOOLS_H
