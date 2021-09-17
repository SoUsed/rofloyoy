#include <QApplication>
#include <QQmlApplicationEngine>
#include "mainrofl.h"
#include <QObject>
#include <QQmlComponent>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQuickWindow>
#include <QSurfaceFormat>

QApplication *app=0;

int main(int argc, char *argv[])
{
    QApplication appA(argc, argv);
    app = &appA;
    qDebug()<<"MAIN.CPP | Started running";
    qmlRegisterType<mainrofl>("com.ics.rofl",0,8,"mainrofl");
    //testclass::getscr_geometry(testclass::wdth1,testclass::hght1);
    qDebug()<<"MAIN.CPP | Yay!register";
    mainrofl myClass;
    int x = 0;
    int y = 0;
    qDebug()<<"MAIN.CPP | Yay!myClass";
    {
        myClass.getscr_geometry(x,y);
        qDebug() << x <<" XXX "<<y;
    }
    qDebug()<<"MAIN.CPP | Yay!getscr";
    QQmlApplicationEngine engine;
    qDebug()<<"MAIN.CPP | Yay!Engine";
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    qDebug()<<"MAIN.CPP | Yay!near setContextProperty!";
    QQmlContext *rc = engine.rootContext();
    if(rc)
    {
        qDebug()<< "MAIN.CPP | SET CLASS";
        rc->setContextProperty("myClass",&myClass);
    }
    else
        qDebug()<< "MAIN.CPP | NO ROOT";
    //QObject* root = engine.rootObjects()[0];

    //engine.rootContext()->setContextProperty("testclass", &myClass);
    qDebug()<<"MAIN.CPP | Yay!finish!";
    myClass.readOptions();
    return appA.exec();
}
