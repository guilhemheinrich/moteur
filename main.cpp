#include <QCoreApplication>
#include <myclass.h>
#include <QtDebug>
#include <iostream>
#include <QtGui/QVector3D>
#include <QVector>
#include <QtGui/QGuiApplication>
#include <QtGui/QMatrix4x4>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QScreen>
#include <QtGui/QImage>
#include <QtCore/qmath.h>
#include <arraytools.h>


//QVector<QVector3D> generateTerrain()
//{
//    GLfloat y1;
//    QVector<QVector3D> _map;
//    QImage image;
//    if (QFile::exists(":/heightmap-2.png")) {
//        if(!image.load(":/heightmap-2.png"))
//        {
//            std::cout << "image non chargé ";
//            exit(0);
//        }
//    }

//    for(int x = 0; x < image.width() - 1; x++)
//    {
//        unsigned char* line = image.scanLine(x);

//        for(int z = 0; z < image.height() - 1; z++)
//        {
//            y1 = pow(1.f - 1.f/(GLfloat)line[z*4], 2);
//            QVector3D vec((qreal) x, (qreal) y1, (qreal) z);
//            _map.push_back( vec );
//        }
//    }
//    return _map;
//}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);






    ArrayTools arr(6,5,1);
    qDebug()<< "size of points :" <<arr.getPoints().size();


    arr.setTriangleMotif(triangle);
    arr.makeIndex();
    arr.buildVertices();
    arr.randomMesh(10);



    for (int i =0; i<arr.getPoints().size();i++)
    {
       qDebug()<< "points"<<i<< " : " <<  arr.getPoints()[i].x()<<","<< arr.getPoints()[i].y()<<","<< arr.getPoints()[i].z();
    }
    qDebug()<<"index";
    for (int i =0; i<(arr.getIndex().size())/3;i++)
    {
        qDebug()<< "triangle"<<i<< " : "<<arr.getIndex()[i*3]<<","<< arr.getIndex()[i*3+1]<<","<<arr.getIndex()[i*3+2];
    }
    qDebug()<<"vertices";
    for (int i =0; i<arr.getVertices().size();i++)
    {
       qDebug()<< "vertice"<<i<< " : " <<  arr.getVertices()[i]->x()<<","<< arr.getVertices()[i]->y()<<","<< arr.getVertices()[i]->z();
    }


    return a.exec();
}
