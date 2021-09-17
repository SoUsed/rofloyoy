#ifndef MULTIPLAYER_CLIENT_H
#define MULTIPLAYER_CLIENT_H

#include <QObject>
#include <QtCore/QObject>
#include <QtWebSockets/QWebSocket>
#include <QDebug>
//#include "mainrofl.h"

class mainrofl;

class multiplayer_client : public QObject
{
    Q_OBJECT

public:
    explicit multiplayer_client(const QUrl &url,QObject *parent = Q_NULLPTR);
    virtual ~multiplayer_client()
    {qDebug()<<"MPC | destruction!";}
    int numofplayers;
    int mynum;
    int cur_players();
    int sendMess(QString mess);
Q_SIGNALS:
    void closed();
private Q_SLOTS:
    void onConnected();
    void onTextMessageReceived(QString message);
private:
    QWebSocket m_webSocket;
    QUrl m_url;
};

#endif // MULTIPLAYER_CLIENT_H
