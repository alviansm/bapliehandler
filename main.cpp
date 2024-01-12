#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QWindow>
#include <QQmlContext>
#include "TableModelSummary.h"
#include "TableBaplieContent.h"
#include "HandleBaplie.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Expose C++ Class to QML
    qmlRegisterType<TableModelSummary>("TableModelSummary", 0, 1, "TableModelSummary");
    qmlRegisterType<TableBaplieContent>("TableBaplieContent", 0, 1, "TableBaplieContent");

    QQmlApplicationEngine engine;

    // Expose C++ object to QML
    HandleBaplie *handleBaplie = new HandleBaplie(&app);
    engine.rootContext()->setContextProperty("handleBaplie", handleBaplie);

    const QUrl url(u"qrc:/BaplieVw/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);    

    return app.exec();
}
