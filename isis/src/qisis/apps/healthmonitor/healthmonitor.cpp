
#include "ControlNet.h"
#include "IString.h"
#include "Progress.h"

#include "ControlNet.h"
#include "ControlNetVitals.h"

#include <QApplication>

#include "ControlHealthMonitor.h"
using namespace Isis;
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    // Create a widget
    ControlNet *net = new ControlNet();
    net->ReadControl("simplenet.net");
    ControlNetVitals *vitals = new ControlNetVitals(net);
    ControlHealthMonitor *w = new ControlHealthMonitor(vitals);
    w->show();

    // Event loop
    return app.exec();
}
