#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QList>
#include <QObject>

#include <cmath>

#include "style.h"
#include "generation.h"

#define DEFAULT_HISTOGRAM_SIZE 10

struct idfit
{
    int id;
    float fit;
};

bool fitnessLessThan(const idfit &a, const idfit &b);

class Histogram: public QGraphicsScene
{
    Q_OBJECT

    public:
        Histogram(qreal x, qreal y, qreal width, qreal height, QWidget *parent);
        void setSize(int size);
        void setData(Generation *gen);
        void draw();
        QList<int> getLastClicked();
    private:
        int size;
        Generation *data;
        QList<int> lastClicked;
    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    signals:
        void clickedBar(QList<int> ids);
};

class HistogramBar: public QGraphicsRectItem
{
    public:
        HistogramBar(qreal x, qreal y, qreal width, qreal height, QList<int> nids);
        QList<int> getIds();
    private:
        QList<int> ids;
    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);

};
