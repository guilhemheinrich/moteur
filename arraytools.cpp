#include "arraytools.h"

ArrayTools::ArrayTools()
{
}


ArrayTools::ArrayTools(int nr,int nc, int squareEdge)
{
    nRow=nr;
    nCol=nc;
    for (int i=0; i<nr;i++)
    {
        for (int j=0; j<nc;j++)
        {
            points.push_back(QVector3D(i,j,0));
        }
    }
}


void ArrayTools::randomMesh(int var)
{
for (int i=0;i<points.size();i++)
    {
    points[i][2]= rand() % var;
    }

}

QVector<QVector3D> ArrayTools::getPoints()
{
    return points;
}

QVector<int> ArrayTools::getIndex()
{
    return index;
}

QVector<QVector3D *> ArrayTools::getVertices()
{
    return vertices;
}

//void ArrayTools::setTriangleMotif(QVector<int> motif)
// {
//     triangleMotif=motif;
// }

void ArrayTools::setTriangleMotif(motif motif)
 {
      QVector<int>  shape;
    if (motif == triangle){
        shape.push_back(0);
        shape.push_back(1);
        shape.push_back(nRow);
        shape.push_back(1);
        shape.push_back(nRow);
        shape.push_back(nRow+1);
    }


    triangleMotif=shape;
 }

void ArrayTools::makeIndex()
{
    std::vector<float> line;
    //int lengthMotif = (sizeof(triangleMotif)/sizeof(*triangleMotif)); // taille du tableau

        // Duplication horizontal
        for (int i=0;i< (nCol-1);i++) {
            for (int k=0;k<triangleMotif.size();k++){
                // On agit moralement sur les coordonnées le long de l'axe x, le premier axe (sur deux)
                line.push_back(triangleMotif[k]+nRow*i);
            }
        }

        // Duplication vertical

           for (int i=0;i< (nRow-1);i++) {
            for (int k=0;k< (int) line.size();k++){
                // On agit moralement sur les coordonnées le long de l'axe y, le deuxième axe (sur deux)
                index.push_back(line.at(k)+i);
            }
        }
}

void ArrayTools::buildVertices()
{
    for (int i=0;i<index.size();i++){
        vertices.push_back(&points[index[i]]);
//        qDebug()<<"index :"<< index[i];
//        qDebug()<<points[index[i]].x()<<","<<points[index[i]].y()<<","<<points[index[i]].z();
    }
}

