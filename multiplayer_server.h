#ifndef MULTIPLAYER_SERVER_H
#define MULTIPLAYER_SERVER_H
#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>
#include <QObject>

QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
QT_FORWARD_DECLARE_CLASS(QWebSocket)

class multiplayer_server : public QObject
{
    Q_OBJECT
public:
    explicit multiplayer_server(quint16 port,int max_users, QObject *parent = 0);
    virtual ~multiplayer_server();

    bool can_we_start();

    int maxusers;
signals:

public slots:




private Q_SLOTS:
    void onNewConnection();
    void processMessage(QString message);
    void socketDisconnected();

private:
    QWebSocketServer *m_pWebSocketServer;
    QList<QWebSocket *> m_clients;
};

#endif // MULTIPLAYER_SERVER_H
