#include "multiplayer_server.h"
#include "QtWebSockets/QWebSocketServer"
#include "QtWebSockets/QWebSocket"
#include <QtCore/QDebug>
#include "mainrofl.h"
//constructor
multiplayer_server::multiplayer_server(quint16 port,int max_users, QObject *parent) :
    QObject(parent),
    m_pWebSocketServer(Q_NULLPTR),
    m_clients()
{
  m_pWebSocketServer = new QWebSocketServer(QStringLiteral("Multiplayer Server"),
                                            QWebSocketServer::NonSecureMode,
                                            this);
  maxusers=max_users;
  if (m_pWebSocketServer->listen(QHostAddress::Any, port))
  {
      qDebug() << "MPS | Multiplayer Server listening on port" << port << " w/ max amount of users: "<<maxusers;
      connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
              this, &multiplayer_server::onNewConnection);
  }
}
//destructor
multiplayer_server::~multiplayer_server()
{
    //send to all of clients message about numof players
    Q_FOREACH (QWebSocket *pClient, m_clients)
    {
            pClient->sendTextMessage(QString("p0"));
    }
    qDebug() << "MPS | Server goes down";
    m_pWebSocketServer->close();
    qDeleteAll(m_clients.begin(), m_clients.end());
}


//! [onNewConnection]
void multiplayer_server::onNewConnection()
{
    if(maxusers>m_clients.size())
    {
    QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();
    connect(pSocket, &QWebSocket::textMessageReceived, this, &multiplayer_server::processMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &multiplayer_server::socketDisconnected);
    m_clients << pSocket;
    pSocket->sendTextMessage(QString("u")+QString::number(m_clients.size()));
    qDebug() << "MPS | WOW!"<<m_clients.size();
    }
    else
    {
        qDebug() << "MPS | Connection Rejected!";
    }
    //send to all of clients message about numof players
    Q_FOREACH (QWebSocket *pClient, m_clients)
    {
            pClient->sendTextMessage(QString("p")+QString::number(m_clients.size()));
    }
}
//! [onNewConnection]


//! [processMessage]
void multiplayer_server::processMessage(QString message)
{
    QWebSocket *pSender = qobject_cast<QWebSocket *>(sender());
    Q_FOREACH (QWebSocket *pClient, m_clients)
    {
        if (pClient != pSender) //don't echo message back to sender
        {
            pClient->sendTextMessage(message);
        }
    }
}
//! [processMessage]

//! [socketDisconnected]
void multiplayer_server::socketDisconnected()
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient)
    {
        for(int i=0;i<m_clients.size();i++)
        {
            if(m_clients[i]==pClient)
            {
                 /*((mainrofl*)QObject::parent())->computer_players.push_back(i); // added 1104
                 qDebug()<<"MPS | -client/+computer: "<< i;*/
            }
        }
        m_clients.removeAll(pClient);
        pClient->deleteLater();
    }

    //send to all of clients message about numof players
    int i=1;
    Q_FOREACH (QWebSocket *pClient, m_clients)
    {
            pClient->sendTextMessage(QString("p")+QString::number(m_clients.size()));
            pClient->sendTextMessage(QString("u")+QString::number(i));
            i++;
    }

    qDebug()<<"MPS | -socket! Now it's"<<m_clients.size()<<" clients!";
}
//! [socketDisconnected]

bool multiplayer_server::can_we_start()
{
    return m_clients.size()==maxusers;
}


