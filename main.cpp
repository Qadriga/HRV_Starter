#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "rennen.h"
#include "racelist.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    int retval = qmlRegisterType<Rennen>("de.hrv.types",1,0,"Rennen");
    qmlRegisterType<RaceList>("de.hrv.types",1,0,"RaceList");
    if (retval == -1){
        qInfo()<< "Error integrating" << endl;
    }
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));


    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
