#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>
#include "rennen.h"
#include "racelist.h"
#include "racelane.h"
#include "usb_wrapper.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Usb_wrapper* usb_obj = Usb_wrapper::getInstance();
    QQmlContext* root = new QQmlContext(engine.rootContext());


    qRegisterMetaType<RaceLane>();
    int retval = qmlRegisterType<Rennen>("de.hrv.types",1,0,"Rennen");
    qmlRegisterType<RaceList>("de.hrv.types",1,0,"RaceList");
    if (retval == -1){
        qInfo()<< "Error integrating" << endl;
    }
    root->setContextProperty("USB",usb_obj);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));


    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
