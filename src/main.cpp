#include "gpvis.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    GPVis window;

    window.setWindowTitle("GPVis");
    window.show();

    return app.exec();
}