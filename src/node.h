#ifndef NODE_H 
#define NODE_H

#include "edge.h"

#include <cmath>
#include <climits>

#include <QBrush>
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QHash>
#include <QList>
#include <QMap>
#include <QObject>
#include <QPen>
#include <QPointF>
#include <QSet>
#include <QString>

#define CONSENSUS_ID INT_MIN
enum NodeType {OP, TERM, ROOT};

class Edge;
class Node
{

    public:
        Node(NodeType type, QString info);
        ~Node();

        void addSon(Node *son);
        void addEdge(Node *son, QPen style);
        void draw(QGraphicsScene *canvas, QPointF coord);
        void updateEdges(QGraphicsScene *canvas);
        int recursiveDraw(QGraphicsScene *canvas,
                          QPointF origin, QPointF coord,
                          int step, int level,
                          float areaAngle, float refAngle);

        void update(QPointF coord);

        static QList<Node*> recursiveDrawMany(QGraphicsScene *canvas, QList<Node*> nodes,
                                              QPointF origin, QPointF coord,
                                              int step, int level,
                                              float areaAngle, float refAngle, QHash<int, QPen> style);
        static QList<Node*> recursiveJoinMany(QList<Node*> nodes);

        QList<Node*> getSons();
        NodeType getType();
        QString getInfo();
        QPointF getCoord();
        QSet<int> getTreeId();

        void setSons(QList<Node*> node_sons);
        void setCoord(QPointF node_coord);
        void setTreeId(QSet<int> id);
        void addTreeId(QSet<int> ids);

        inline bool operator==(const Node &other) const
        {
            return (other.type == type) && (other.info == info);
        }

        inline bool operator<(const Node &other) const
        {
            if (other.type == type)
            {
                if (other.info == info)
                {
                    if (other.pos.x() == pos.x())
                        return other.pos.y() < pos.y();
                    else
                        return other.pos.x() < pos.x();
                }
                else
                    return other.info < info;
            }
            return other.type < type;
        }

    private:
        QSet<int> tree_id;
        NodeType type;
        QString info;
        QList<Node*> sons;
        QMap< Node, QList<Edge*> > edges;
        QPointF pos;
        QGraphicsItem *text;
        QGraphicsItem *bound;
};

#endif
