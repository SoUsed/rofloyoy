#include "multiplayer_client.h"
#include <QtCore/QDebug>
#include <string>
#include <stdio.h>
#include "mainrofl.h"
#include <QString>
//! [constructor]
multiplayer_client::multiplayer_client(const QUrl &url, QObject *parent) :
    QObject(parent),
    m_url(url)
{
    connect(&m_webSocket, &QWebSocket::connected, this, &multiplayer_client::onConnected);
    connect(&m_webSocket, &QWebSocket::disconnected, this, &multiplayer_client::closed);
    m_webSocket.open(QUrl(url));
}
//! [constructor]

//! [onConnected]
void multiplayer_client::onConnected()
{
    connect(&m_webSocket, &QWebSocket::textMessageReceived,
            this, &multiplayer_client::onTextMessageReceived);
    if(m_webSocket.sendTextMessage(QStringLiteral("test")))
    {
        qDebug() << "MPC | WebSocket connected";
    }
    else
    {
        qDebug() << "MPC | Fail!";
        delete this;
    }
}
//! [onConnected]

//! [onTextMessageReceived]
void multiplayer_client::onTextMessageReceived(QString message)
{
    qDebug() << "MPC | Message received:" << message;
    std::string msgstr = message.toLocal8Bit().constData();
    char stdpc = 'p';
    char stduc = 'u';
    char stdic = 'i';
    char stdmc = 'm';
    char stdsc = 's';
    char stdec = 'e';
    if(message.length()==0)
    {
        qDebug()<<"Recieved empty!";
    }
    if(msgstr[0]==stdpc)
    {
        qDebug()<<"MPC | Recieved numofplayers in lobby: "<<message<<". Num: "<<msgstr[1]<<
                  " 2*Num: "<< (int)msgstr[1]*2-96;
        numofplayers=(int)msgstr[1]-48;
        ((mainrofl*)QObject::parent())->sendNumOfPlayersToQMLf(numofplayers);
    }else
    if(msgstr[0]==stduc && ((mainrofl*)QObject::parent())->game_started)
    {
        qDebug()<<"MPC | Recieved my num in lobby: "<<message<<". Num: "<<msgstr[1]<<
                  " 2*Num: "<< (int)msgstr[1]*2-96;
        mynum=(int)msgstr[1]-48;
        ((mainrofl*)QObject::parent())->sendYourNumToQMLf(mynum);
    }else
    if(msgstr[0]==stdic)
    {
        qDebug()<<"MPC | Recieved main game info! "<<message;
        for(int i=2;i<msgstr.size();i++)
        {
            msgstr[i-2]=msgstr[i];
        }
        msgstr[msgstr.size()-1]=0;
        msgstr[msgstr.size()-2]=0;
        // size -> players -> provinces
        QStringList sl =  QString(msgstr.c_str()).split(" ");

        if(sl.size()>=3)
        {
            QString sz = sl[0];
            int ps = sl[1].toInt();
            QString pv = sl[2];
            qDebug()<< sz << " " << ps << " "<< pv;
            ((mainrofl*)QObject::parent())->sendMainInfoToQMLf(sz,ps,pv);
        }
        else
            qDebug() << "MPC | Errot sl.size() = " << sl.size();
    }else

    // MAP INFO!
    if(msgstr[0]==stdmc)
    {
        qDebug()<<"MPC | Recieved map!";
        for(int i=0;i<msgstr.size();i++)
        {
            msgstr[i-1]=msgstr[i];
        }
        msgstr[msgstr.size()-1]=0;
        QStringList lexemes =  QString(msgstr.c_str()).split(" ");
        ((mainrofl*)QObject::parent())->current_player=lexemes[1].toInt();
        ((mainrofl*)QObject::parent())->firstturn=(bool)lexemes[2].toInt();
        ((mainrofl*)QObject::parent())->sx=lexemes[3].toInt();
        ((mainrofl*)QObject::parent())->sy=lexemes[4].toInt();
        ((mainrofl*)QObject::parent())->intimap(((mainrofl*)QObject::parent())->maprel,
                    ((mainrofl*)QObject::parent())->sx,((mainrofl*)QObject::parent())->sy);

        if (((mainrofl*)QObject::parent())==0)
        {
            qDebug()<<"MPC | FATAL";
        }


        qDebug()<<"MPC | lexemes.size() = " << lexemes.size();
        int counter=5;

        int nx = lexemes[3].toInt();
        int ny = lexemes[4].toInt();
        qDebug()<<"MPC | Map " << nx << "X" << ny;

        if(lexemes.size()<counter)
        {
            qDebug()<<"MPC | YOY!";
        }
        for(int i=0;i<nx;i++)
        {
            for(int j=0;j<ny;j++)
            {
                ((mainrofl*)QObject::parent())->maprel[i][j].is_standable=(bool)lexemes[counter].toInt();
                counter++;
                if(lexemes.size()<counter)
                {
                    qDebug()<<"MPC | YOY!";
                }
                ((mainrofl*)QObject::parent())->maprel[i][j].player=lexemes[counter].toInt();
                counter++;
                if(lexemes.size()<counter)
                {
                    qDebug()<<"MPC | YOY!";
                }
                ((mainrofl*)QObject::parent())->maprel[i][j].is_capital=(bool)lexemes[counter].toInt();
                counter++;
                if(lexemes.size()<counter)
                {
                    qDebug()<<"MPC | YOY!";
                }
                ((mainrofl*)QObject::parent())->maprel[i][j].tree=lexemes[counter].toInt();
                counter++;
                if(lexemes.size()<counter)
                {
                    qDebug()<<"MPC | YOY!";
                }
                ((mainrofl*)QObject::parent())->maprel[i][j].hatchery=(bool)lexemes[counter].toInt();
                counter++;
                if(lexemes.size()<counter)
                {
                    qDebug()<<"MPC | YOY!";
                }
                ((mainrofl*)QObject::parent())->maprel[i][j].tower=lexemes[counter].toInt();
                counter++;
                if(lexemes.size()<counter)
                {
                    qDebug()<<"MPC | YOY!";
                }
                ((mainrofl*)QObject::parent())->maprel[i][j].roflochelik_lvl=lexemes[counter].toInt();
                counter++;
                if(lexemes.size()<counter)
                {
                    qDebug()<<"MPC | YOY!";
                }
                ((mainrofl*)QObject::parent())->maprel[i][j].roflochelik_active=(bool)lexemes[counter].toInt();
                counter++;
                if(lexemes.size()<counter)
                {
                    qDebug()<<"MPC | YOY!";
                }
                ((mainrofl*)QObject::parent())->maprel[i][j].xcoor=i;
                ((mainrofl*)QObject::parent())->maprel[i][j].ycoor=j;
            }
        }
        ((mainrofl*)QObject::parent())->allprov.clear();
        for(int i=0;i<lexemes[counter].toInt();i++)
        {
        ((mainrofl*)QObject::parent())->allprov.push_back(((mainrofl*)QObject::parent())->emptyprovince);
        }
        counter++;
        if(lexemes.size()<counter)
        {
            qDebug()<<"MPC | YOY!";
        }
        for(int i=0;i<((mainrofl*)QObject::parent())->allprov.size();i++)
        {
            ((mainrofl*)QObject::parent())->allprov[i].player=lexemes[counter].toInt();
            counter++;
            if(lexemes.size()<=counter)
            {
                qDebug()<<"MPC | YOY!";
            }
            ((mainrofl*)QObject::parent())->allprov[i].curincome=lexemes[counter].toInt();
            counter++;
            if(lexemes.size()<=counter)
            {
                qDebug()<<"MPC | YOY!";
            }
            ((mainrofl*)QObject::parent())->allprov[i].curmoney=lexemes[counter].toInt();
            counter++;
            if(lexemes.size()<=counter)
            {
                qDebug()<<"MPC | YOY!";
            }
            ((mainrofl*)QObject::parent())->allprov[i].hexes_x.clear();
            ((mainrofl*)QObject::parent())->allprov[i].hexes_y.clear();
            int nHexInProv = lexemes[counter].toInt();
            if(nHexInProv > 10)
            {
                qDebug()<<"MPC | nHexInProv="<<nHexInProv;
            }
            for(int ii=0;ii<nHexInProv;ii++)
            {
                if (((mainrofl*)QObject::parent())->allprov.size() > i)
                {
                    ((mainrofl*)QObject::parent())->allprov[i].hexes_x.push_back(0);
                    ((mainrofl*)QObject::parent())->allprov[i].hexes_y.push_back(0);
                }
                else
                    qDebug() << "MPC | out of vector allprov " << i << "size = " <<
                                ((mainrofl*)QObject::parent())->allprov.size();
            }
            counter++;
            if(lexemes.size()<=counter)
            {
                qDebug()<<"MPC | YOY!";
            }

            for(int q=0;q<((mainrofl*)QObject::parent())->allprov[i].hexes_x.size();q++)
            {
                ((mainrofl*)QObject::parent())->allprov[i].hexes_x[q]=lexemes[counter].toInt();
                counter++;
                if(lexemes.size()<counter)
                {
                    qDebug()<<"MPC | YOY!";
                }
                ((mainrofl*)QObject::parent())->allprov[i].hexes_y[q]=lexemes[counter].toInt();
                counter++;
                if(lexemes.size()<counter)
                {
                    qDebug()<<"MPC | YOY!";
                }
            }
        }
    qDebug()<<"MPC | Done";
    bool ismyturn;
    if(mynum==((mainrofl*)QObject::parent())->current_player)
    {
        ismyturn=true;
    }
    else
    {
        ismyturn=false;
    }
    ((mainrofl*)QObject::parent())->sendMapQMLf(ismyturn);
    }else

    if(msgstr[0]==stdsc)
    {
        qDebug()<<"MPC | Game started!";
        ((mainrofl*)QObject::parent())->startGameQMLf();
    }
    if(msgstr[0]==stdec)
    {
        qDebug()<<"MPC | Game ended!";
        ((mainrofl*)QObject::parent())->endgame(QString(msgstr.c_str()).split(" ")[1].toInt());
    }






    //m_webSocket.close();
}
//! [onTextMessageReceived]

// SEND MESSAGE!
int multiplayer_client::sendMess(QString mess)
{
    m_webSocket.sendTextMessage(mess);
}

int multiplayer_client::cur_players()
{
    return numofplayers;
}


