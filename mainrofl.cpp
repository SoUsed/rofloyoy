#include "mainrofl.h"
#include <QtCore/qdebug.h>
#include <QtGui/qguiapplication.h>
#include <QtGui/qscreen.h>
#include <QApplication>
#include <cstdlib>
#include <QDesktopWidget>
#include <QDebug>
#include <QDateTime>
#include <QPixmap>
#include <QPainter>
#include <QFile>
#include <QStandardPaths>
#include <math.h>
#include <queue>
#include "multiplayer_server.h"
#include "multiplayer_client.h"
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QNetworkInterface>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <fstream>


#include <signal.h>
mainrofl::mainrofl(QObject *parent) :
    QObject(parent),
    //_apppth(QApplication::applicationDirPath()),
    q_red_empty(":/resources/q_red_empty.png"),
    q_blue_empty(":/resources/q_blue_empty.png"),
    q_tan_empty(":/resources/q_tan_empty.png"),
    q_green_empty(":/resources/q_green_empty.png"),
    q_orange_empty(":/resources/q_orange_empty.png"),
    q_purple_empty(":/resources/q_purple_empty.png"),
    q_teal_empty(":/resources/q_teal_empty.png"),
    q_pink_empty(":/resources/q_pink_empty.png"),
    q_neutral_empty(":/resources/q_neutral_empty.png"),

    q_blue_palace(":/resources/q_blue_palace.png"),
    q_red_palace(":/resources/q_red_palace.png"),
    q_tan_palace(":/resources/q_tan_palace.png"),
    q_green_palace(":/resources/q_green_palace.png"),
    q_orange_palace(":/resources/q_orange_palace.png"),
    q_purple_palace(":/resources/q_purple_palace.png"),
    q_teal_palace(":/resources/q_teal_palace.png"),
    q_pink_palace(":/resources/q_pink_palace.png"),

    q_blue_1(":/resources/q_blue_unit1.png"),
    q_red_1(":/resources/q_red_unit1.png"),
    q_tan_1(":/resources/q_tan_unit1.png"),
    q_green_1(":/resources/q_green_unit1.png"),
    q_orange_1(":/resources/q_orange_unit1.png"),
    q_purple_1(":/resources/q_purple_unit1.png"),
    q_teal_1(":/resources/q_teal_unit1.png"),
    q_pink_1(":/resources/q_pink_unit1.png"),

    q_blue_2(":/resources/q_blue_unit2.png"),
    q_red_2(":/resources/q_red_unit2.png"),
    q_tan_2(":/resources/q_tan_unit2.png"),
    q_green_2(":/resources/q_green_unit2.png"),
    q_orange_2(":/resources/q_orange_unit2.png"),
    q_purple_2(":/resources/q_purple_unit2.png"),
    q_teal_2(":/resources/q_teal_unit2.png"),
    q_pink_2(":/resources/q_pink_unit2.png"),

    q_blue_3(":/resources/q_blue_unit3.png"),
    q_red_3(":/resources/q_red_unit3.png"),
    q_tan_3(":/resources/q_tan_unit3.png"),
    q_green_3(":/resources/q_green_unit3.png"),
    q_orange_3(":/resources/q_orange_unit3.png"),
    q_purple_3(":/resources/q_purple_unit3.png"),
    q_teal_3(":/resources/q_teal_unit3.png"),
    q_pink_3(":/resources/q_pink_unit3.png"),

    q_blue_4(":/resources/q_blue_unit4.png"),
    q_red_4(":/resources/q_red_unit4.png"),
    q_tan_4(":/resources/q_tan_unit4.png"),
    q_green_4(":/resources/q_green_unit4.png"),
    q_orange_4(":/resources/q_orange_unit4.png"),
    q_purple_4(":/resources/q_purple_unit4.png"),
    q_teal_4(":/resources/q_teal_unit4.png"),
    q_pink_4(":/resources/q_pink_unit4.png"),

    q_blue_t1(":/resources/q_blue_tower1.png"),
    q_red_t1(":/resources/q_red_tower1.png"),
    q_tan_t1(":/resources/q_tan_tower1.png"),
    q_green_t1(":/resources/q_green_tower1.png"),
    q_orange_t1(":/resources/q_orange_tower1.png"),
    q_purple_t1(":/resources/q_purple_tower1.png"),
    q_teal_t1(":/resources/q_teal_tower1.png"),
    q_pink_t1(":/resources/q_pink_tower1.png"),

    q_blue_t2(":/resources/q_blue_tower2.png"),
    q_red_t2(":/resources/q_red_tower2.png"),
    q_tan_t2(":/resources/q_tan_tower2.png"),
    q_green_t2(":/resources/q_green_tower2.png"),
    q_orange_t2(":/resources/q_orange_tower2.png"),
    q_purple_t2(":/resources/q_purple_tower2.png"),
    q_teal_t2(":/resources/q_teal_tower2.png"),
    q_pink_t2(":/resources/q_pink_tower2.png"),

    q_blue_h(":/resources/q_blue_hatchery.png"),
    q_red_h(":/resources/q_red_hatchery.png"),
    q_tan_h(":/resources/q_tan_hatchery.png"),
    q_green_h(":/resources/q_green_hatchery.png"),
    q_orange_h(":/resources/q_orange_hatchery.png"),
    q_purple_h(":/resources/q_purple_hatchery.png"),
    q_teal_h(":/resources/q_teal_hatchery.png"),
    q_pink_h(":/resources/q_pink_hatchery.png"),

    q_blue_tree(":/resources/q_blue_tree.png"),
    q_red_tree(":/resources/q_red_tree.png"),
    q_tan_tree(":/resources/q_tan_tree.png"),
    q_green_tree(":/resources/q_green_tree.png"),
    q_orange_tree(":/resources/q_orange_tree.png"),
    q_purple_tree(":/resources/q_purple_tree.png"),
    q_teal_tree(":/resources/q_teal_tree.png"),
    q_pink_tree(":/resources/q_pink_tree.png"),
    q_neutral_tree(":/resources/q_neutral_tree.png"),

    q_blue_palm(":/resources/q_blue_palm.png"),
    q_red_palm(":/resources/q_red_palm.png"),
    q_tan_palm(":/resources/q_tan_palm.png"),
    q_green_palm(":/resources/q_green_palm.png"),
    q_orange_palm(":/resources/q_orange_palm.png"),
    q_purple_palm(":/resources/q_purple_palm.png"),
    q_teal_palm(":/resources/q_teal_palm.png"),
    q_pink_palm(":/resources/q_pink_palm.png"),
    q_neutral_palm(":/resources/q_neutral_palm.png"),

    kvadrat_malevicha(":/resources/kvadrat_malevicha.png"),
    or_vodichka(":/resources/or_water.png"),
    background1(":/resources/bg_th.png")

{
    //options






    /*
    //MEDIA
    m_player = new QMediaPlayer(this);
    m_playlist = new QMediaPlaylist(m_player);
    m_player->setVolume(50);
    m_player->setPlaylist(m_playlist);
    m_playlist->addMedia(QUrl(":/resources/ryoy3.mp3"));
    m_playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    m_player->play();

    qDebug()<<m_player->isAudioAvailable()<<m_player->isAvailable()<<m_player->isSeekable();
    */



    qDebug()<<"Constr(mainrofl)!";
    NuServ=0;
    NuClient = 0;
//    maprel.clear();// = 0;
    for(int i=0;i<100;i++)
    {
        QVector<hex> t;
        hex nil;
        for(int j=0;j<100;j++)
            t.push_back(nil);
//        map[i]= new hex[sy];
        maprel.push_back(t);

    }

    oldSx = 0;

    center_x = _wdth1/2;
    center_y = _wdth1*2/3;
    //square_size=_wdth1/sx;



    clck = true;


    current_player=1;
    current_action=1;
    prevc_x=0;
    prevc_y=0;


    emptyprovince.player=-1;

    currentprovince=emptyprovince;
    roflochelik_status=0;
    buildings_status=0;

    // MP
    is_it_my_turn=true;

    qDebug()<<"Constr(mainrofl) ready!";

    /*
    //TBC define IP
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address())
        {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    */
}



void mainrofl::readOptions()
{
    std::ifstream optF;
    optF.open((apppth() + "/rofloptions.txt").toLocal8Bit().constData());
    char ttt[64];
    optF.getline(ttt,32);
    qDebug()<< "ReadOpt | " << (apppth() + "/rofloptions.txt").toLocal8Bit().constData();
    qDebug()<< "ReadOpt | " << ttt;
    if(ttt[0] ==  'o' && ttt[1] == 'r') // TBC!
    {
        qDebug()<< "ReadOpt | ORIGINAL!";
        q_red_1 = QPixmap(":/resources/or_red_unit_1.png");
        q_red_2 = QPixmap(":/resources/or_red_unit_2.png");
        q_red_3 = QPixmap(":/resources/or_red_unit_3.png");
        q_red_4 = QPixmap(":/resources/or_red_unit_4.png");
        q_blue_1 = QPixmap(":/resources/or_blue_unit_1.png");
        q_blue_2 = QPixmap(":/resources/or_blue_unit_2.png");
        q_blue_3 = QPixmap(":/resources/or_blue_unit_3.png");
        q_blue_4 = QPixmap(":/resources/or_blue_unit_4.png");
        q_tan_1 = QPixmap(":/resources/or_tan_unit_1.png");
        q_tan_2 = QPixmap(":/resources/or_tan_unit_2.png");
        q_tan_3 = QPixmap(":/resources/or_tan_unit_3.png");
        q_tan_4 = QPixmap(":/resources/or_tan_unit_4.png");
        q_green_1 = QPixmap(":/resources/or_green_unit_1.png");
        q_green_2 = QPixmap(":/resources/or_green_unit_2.png");
        q_green_3 = QPixmap(":/resources/or_green_unit_3.png");
        q_green_4 = QPixmap(":/resources/or_green_unit_4.png");
        q_orange_1 = QPixmap(":/resources/or_orange_unit_1.png");
        q_orange_2 = QPixmap(":/resources/or_orange_unit_2.png");
        q_orange_3 = QPixmap(":/resources/or_orange_unit_3.png");
        q_orange_4 = QPixmap(":/resources/or_orange_unit_4.png");
        q_purple_1 = QPixmap(":/resources/or_purple_unit_1.png");
        q_purple_2 = QPixmap(":/resources/or_purple_unit_2.png");
        q_purple_3 = QPixmap(":/resources/or_purple_unit_3.png");
        q_purple_4 = QPixmap(":/resources/or_purple_unit_4.png");
        q_teal_1 = QPixmap(":/resources/or_teal_unit_1.png");
        q_teal_2 = QPixmap(":/resources/or_teal_unit_2.png");
        q_teal_3 = QPixmap(":/resources/or_teal_unit_3.png");
        q_teal_4 = QPixmap(":/resources/or_teal_unit_4.png");
        q_pink_1 = QPixmap(":/resources/or_pink_unit_1.png");
        q_pink_2 = QPixmap(":/resources/or_pink_unit_2.png");
        q_pink_3 = QPixmap(":/resources/or_pink_unit_3.png");
        q_pink_4 = QPixmap(":/resources/or_pink_unit_4.png");

        textures = "or";
    }
    else
    {
        qDebug()<< "ReadOpt | Heroes";
        textures = "he";
    }

    optF.getline(ttt,5);
    qDebug()<< "ReadOpt | " << ttt;
    if(ttt[0] == 'n')
    {
        qDebug()<< "ReadOpt | No sound!";
        soundStat = false;
    }
    else
    {
        qDebug()<< "ReadOpt | W/ sound!";
        soundStat = true;
    }
    sendOptionsQMLf(textures,soundStat);
}

void mainrofl::getscr_geometry(int & w, int & h)
{
    _wdth1 = w = app->desktop()->screenGeometry().width();
    _hght1 = h = app->desktop()->screenGeometry().height();
    if(9*_wdth1==16*_hght1){
        _wdth1 = _hght1*9/16;
    }
    //_apppth = app->applicationDirPath();//.toLocal8Bit().constData();   // FOR PC BUILD!
    //_apppth ="storage/emulated/0/rofloyoy"; //FOR ANDROID BUILD, NON-WORKABLE
    _apppth = QStandardPaths::standardLocations(QStandardPaths::DownloadLocation)[0]; // UNIVERSAL
}

//QMutex mainrofl::mu1;

void mainrofl::createmap(QString size, int numofplayers, QString numofprovinces)
{
    //mu1.lock();
    game_started=true;
    QVector < QVector<hex> >  map = maprel;
    allprov.clear();
    if(size/*.toLocal8Bit().constData()*/=="small"){intimap(map,24,16);sx=16;sy=24;}
    if(size=="medium"){intimap(map,40,30);sx=30;sy=40;}
    if(size=="big"){intimap(map,60,45);sx=45;sy=60;}
    if(size=="huge"){intimap(map,80,60);sx=60;sy=80;}
    numofplayers_ = numofplayers;
    srand(QDateTime::currentDateTime().toMSecsSinceEpoch());

    int numofpro;
    if(numofprovinces=="default")
    {
        if(size=="small")
        {
            numofpro=1;
        }
        if(size=="medium")
        {
            numofpro=2;
        }
        if(size=="big")
        {
            numofpro=3;
        }
        if(size=="huge")
        {
            numofpro=4;
        }
    }
    else
    {
        numofpro=numofprovinces.toInt();
    }


    // RMG 1.0 -----------------------------------------------------------------
    /*for(int i=0;i<percentage*sx*sy/100;i++)
    {
        srand(QDateTime::currentDateTime().toMSecsSinceEpoch());
        map[curdtx][curdty].is_standable=1;
        int rnd=rand()%8;
        //int rnd = rand()%6;
        int crfnd=false;

        if(rnd==0)
        {
            if(curdty>0  && map[curdtx][curdty-1].is_standable!=1)
            {
                curdty--;
                crfnd=true;
            }
            else{rnd++;}
        }

        if((rnd==1 || rnd==6))
        {
            if(curdtx>0  && map[curdtx-1][curdty].is_standable!=1)
            {
                curdtx--;
                crfnd=true;
            }
            else{rnd++;}
        }

        if(rnd==2)
        {
            if(curdtx>0 && curdty<sy-1 && map[curdtx-1][curdty+1].is_standable!=1)
            {
                curdtx--;
                curdty++;
                crfnd=true;
            }
            else{rnd++;}
        }

        if(rnd==3)
        {
            if(curdtx < sx-1 && map[curdtx+1][curdty].is_standable!=1)
            {
                curdtx++;
                crfnd=true;
            }
            else{rnd++;}
        }

        if(rnd==4)
        {
            if(curdtx<sx-1 && curdty<sy-1 && map[curdtx+1][curdty+1].is_standable!=1)
            {
                curdty++;
                curdtx++;
                crfnd=true;
            }
            else{rnd++;}
        }

        if((rnd==5 || rnd==7))
        {
            if(curdtx < sx-1  && map[curdtx+1][curdty+1].is_standable!=1)
            {
                curdtx++;
                crfnd=true;
            }
            else{rnd=0;}
        }

        if(rnd==0 && !crfnd)
        {
            if(curdty>0 && map[curdtx][curdty-1].is_standable!=1)
            {
                curdty--;
                crfnd=true;
            }
            else{rnd++;}
        }

        if((rnd==1 || rnd==6) && !crfnd)
        {
            if(curdtx>0  && map[curdtx-1][curdty].is_standable!=1)
            {
                curdtx--;
                crfnd=true;
            }
            else{rnd++;}
        }

        if(rnd==2 && !crfnd)
        {
            if(curdtx>0 && curdty<sy-1 && map[curdtx-1][curdty+1].is_standable!=1)
            {
                curdtx--;
                curdty++;
                crfnd=true;
            }
            else{rnd++;}
        }

        if(rnd==3 && !crfnd)
        {
            if(curdtx< sx-1 && map[curdtx+1][curdty].is_standable!=1)
            {
                curdtx++;
                crfnd=true;
            }
            else{rnd++;}
        }

        if(rnd==4 && !crfnd)
        {
            if(curdtx<sx-1 && curdty<sy-1 && map[curdtx+1][curdty+1].is_standable!=1)
            {
                curdty++;
                curdtx++;
                crfnd=true;
            }


        }
    }//------------------------------------------------------------------------------------ */
    rmg(map);
    maprel=map;
    /*int CurSquare=0;
    CurSquare=0;
    for(int i=0;i<sx;i++)
    {
        for(int j=0;j<sy;j++)
        {
            CurSquare+=map[i][j].is_standable;
        }
    }*/
    /*if(CurSquare>=sx*sy*4/10  && CurSquare<=sx*sy*60/100){qDebug() << '\n';
    QString outpt;
    for(int i=0;i<sx;i++)
    {
        for(int j=0;j<sy;j++)
        {
            outpt+= QString::number(map[i][j].is_standable) + QString(" ");
        }
        qDebug() << outpt;
        outpt.clear();
    }}*/
    //static int counter=1;
    /*if(CurSquare<sx*sy*40/100 || CurSquare>sx*sy*60/100) // HERE CHANGE PERCENTAGE!!!
    {
        qDebug() << '\n' << "Re!( " << CurSquare << " of " << sx*sy << " , " << CurSquare*100/sx/sy << " % ) " << counter;
        counter++;
        createmap(size,numofplayers,numofplayers);
    }else*///{qDebug() << '\n' << "Ok!( " << CurSquare << " of " << sx*sy << " , " << CurSquare*100/sx/sy << " % ) " << counter;}
    /*if(CurSquare>=sx*sy*4/10  && CurSquare<=sx*sy*60/100)*/
    for(int i=1;i<numofplayers+1;i++)
    {
        for(int numofproves=0;numofproves<numofpro;numofproves++)
        {
            bool rdy=false;
        while(!rdy)
        {
            regenresp:
            int rndx= rand()%sx;
            int rndy= rand()%sy;

            if(neighbour_hexes(map,rndx,rndy).size()==6 && !map[rndx][rndy].is_capital && map[rndx][rndy].is_standable
                    && map[rndx][rndy].player==0)
            {
                std::vector<hex> neighbour_hexesc = neighbour_hexes(map,rndx,rndy);
                bool okrsp=true;
                for(int qf=0;qf<6;qf++)
                {
                    if(neighbour_hexesc[qf].player!=0){okrsp=false;}
                }
                /*starting province*/
                province bufprov;
                bufprov.curincome=0;
                bufprov.curmoney=10;
                bufprov.player=i;
                bufprov.hexes_x.clear();
                bufprov.hexes_y.clear();
                /*starting province*/
                if(okrsp){
                for(int q=0;q<6;q++)
                {
                    map[neighbour_hexesc[q].xcoor][neighbour_hexesc[q].ycoor].player=i;
                    bufprov.hexes_x.push_back(neighbour_hexesc[q].xcoor);
                    bufprov.hexes_y.push_back(neighbour_hexesc[q].ycoor);
                    //map[neighbour_hexesc[1].xcoor][neighbour_hexesc[1].ycoor].roflochelik_lvl=1;//TO BE DELETED!!!
                    //map[neighbour_hexesc[2].xcoor][neighbour_hexesc[2].ycoor].roflochelik_lvl=2;//TO BE DELETED!!!
                    //map[neighbour_hexesc[3].xcoor][neighbour_hexesc[3].ycoor].roflochelik_lvl=3;//TO BE DELETED!!!
                    //map[neighbour_hexesc[4].xcoor][neighbour_hexesc[4].ycoor].roflochelik_lvl=4;//TO BE DELETED!!!

                }
                bufprov.hexes_x.push_back(rndx);
                bufprov.hexes_y.push_back(rndy);
                bufprov = sortedprovince(bufprov);
                allprov.push_back(bufprov);
                map[rndx][rndy].player=i;
                map[rndx][rndy].is_capital=true;
                rdy=true;}else{goto regenresp;}
            }else{goto regenresp;}
        }
        }
    }
    /*if(CurSquare>=sx*sy*4/10   && CurSquare<=sx*sy*60/100)*/{
    QString outpt;
    outpt.clear();
    qDebug() << '\n';
    qDebug() << "Players: " << '\n';
        for(int i=0;i<sx;i++)
        {
            for(int j=0;j<sy;j++)
            {
                outpt+= QString::number(map[i][j].player) + QString(" ");
            }
            qDebug() << outpt;
            outpt.clear();
        }}
    maprel=map;
    setTrees(2);
    center_x = _wdth1/2;
    center_y = _wdth1*2/3;
    square_size = _wdth1/sx;
    current_player=1;
    firstturn=true;
    redrawimg();
    //mu1.unlock();

}

void mainrofl::intimap(QVector< QVector < hex > > & map, int sy, int sx)
{
    qDebug()<<"INTIMAP!!!!!!!!!!!!!!!!!!!!!!";
/*    if (map)
    {
        for(int i=0;i<oldSx;i++)
        {
            delete [] map[i];
        }
        delete [] map;
        map = 0;
    }
*/
    //mu1.lock();
    //map.clear();
    oldSx = sx;
//    map = new hex*[sx];
/*    for(int i=0;i<sx;i++)
    {
        QVector<hex> t;
        hex nil;
        for(int j=0;j<sy;j++)
            t.push_back(nil);
//        map[i]= new hex[sy];
        map.push_back(t);

    }*/
    for(int i=0;i<sx;i++) // sx->60
    {
        for(int j=0;j<sy;j++)// sy->80
        {
            map[i][j].hatchery=false;
            map[i][j].is_capital=false;
            map[i][j].is_standable=false;
            map[i][j].player=0;
            map[i][j].tower=0;
            map[i][j].tree=0;
            map[i][j].xcoor=i;
            map[i][j].ycoor=j;
            map[i][j].roflochelik_lvl=0;
            map[i][j].roflochelik_active=true;
        }
    }
    //mu1.unlock();
}

std::vector<mainrofl::hex> mainrofl::neighbour_hexes(QVector< QVector< mainrofl::hex > > & map, int curhexx, int curhexy)
{
    std::vector<hex> nbhx;
    if(map[curhexx][curhexy].is_standable)
    {
        if(curhexx % 2 == 1)
        {
        if(curhexy-1>0){if(map[curhexx][curhexy-1].is_standable){nbhx.push_back(map[curhexx][curhexy-1]);}}
        if(curhexx-1>0){if(map[curhexx-1][curhexy].is_standable){nbhx.push_back(map[curhexx-1][curhexy]);}}
        if(curhexy+1<sy && curhexx-1>0){if(map[curhexx-1][curhexy+1].is_standable){nbhx.push_back(map[curhexx-1][curhexy+1]);}}
        if(curhexy+1<sy){if(map[curhexx][curhexy+1].is_standable){nbhx.push_back(map[curhexx][curhexy+1]);}}
        if(curhexy+1<sy && curhexx+1<sx){if(map[curhexx+1][curhexy+1].is_standable){nbhx.push_back(map[curhexx+1][curhexy+1]);}}
        if(curhexx+1<sx){if(map[curhexx+1][curhexy].is_standable){nbhx.push_back(map[curhexx+1][curhexy]);}}
        }
        else
        {

            if(curhexy-1>0){if(map[curhexx][curhexy-1].is_standable){nbhx.push_back(map[curhexx][curhexy-1]);}}//prev
            if(curhexx-1>0){if(map[curhexx-1][curhexy].is_standable){nbhx.push_back(map[curhexx-1][curhexy]);}}//prev
            if(curhexy-1>0 && curhexx-1>0){if(map[curhexx-1][curhexy-1].is_standable){nbhx.push_back(map[curhexx-1][curhexy-1]);}}
            if(curhexy+1<sy){if(map[curhexx][curhexy+1].is_standable){nbhx.push_back(map[curhexx][curhexy+1]);}}//prev
            if(curhexy-1>0 && curhexx+1<sx){if(map[curhexx+1][curhexy-1].is_standable){nbhx.push_back(map[curhexx+1][curhexy-1]);}}
            if(curhexx+1<sx){if(map[curhexx+1][curhexy].is_standable){nbhx.push_back(map[curhexx+1][curhexy]);}}//prev


        }
    }
    return nbhx;
}

void mainrofl::test1(int x,int y)
{
    qDebug() << "In! ( " << x << " ; " << y << " )" << '\n';
    ctx=x;
    cty=y;
    qDebug() << "Infun! ( " << ctx << " ; " << cty << " )" << '\n';
    mouse_obrabotchik(1);
    clck=true;
}

void mainrofl::test2(int x,int y)
{
    qDebug() << "Atputi! ( " << x << " ; " << y << " )" << '\n';
    stx=x;
    sty=y;
    qDebug() << "Atputifun! ( " << stx << " ; " << sty << " )" << '\n';
    //mouse_obrabotchik();

}

void mainrofl::test3(int x,int y)
{
    if(!clck){
    qDebug() << "Atputil! ( " << x << " ; " << y << " )" << '\n';
    enx=x;
    eny=y;
    qDebug() << "Atputilfun! ( " << enx << " ; " << eny << " )" << '\n';
    mouse_obrabotchik(2);}
    else{clck=false;}

}

void mainrofl::nextplayer()
{
    //trees if first player;
    if(current_player==numofplayers_)
    {
        setTrees(1);
    }

    //HERE CHECK IF GAME IS ENDED!
    bool is_game_ended=true;
        for(int j=0;j<allprov.size();j++)
        {
            if(allprov[j].player!=current_player && allprov[j].player!=0)
            {
                is_game_ended=false;
            }
        }
        if(is_game_ended)
        {
            qDebug()<<"NEXTPLAYER | GAME ENDED!!!!!";
            if(NuClient)
            {
                NuClient->sendMess("e "+QString::number(current_player));
            }
            endgame(current_player);
            return;
        }



    if(current_player<numofplayers_)
    {
        current_player++;
    }
    else
    {
        current_player=1;
        firstturn=false;
    }
    /* IMPORTANT: here we checking if player have a single province. If no, this player is eliminated, so we call nextplayer();
     */
    bool is_singleprov=false;
    for(int i=0;i<allprov.size();i++)
    {
        if(allprov[i].player==current_player)
        {
            is_singleprov=true;
        }
    }
    if(!is_singleprov)
    {
        qDebug() << "NEXTPLAYER | Err w/ giving " << currentplayer() << " turn. This player is eliminated!";
        nextplayer(); // this player is eliminated so we giving turn to next player
        return;
    }
    // provinces
    reformprovinces(current_player);
    // economics (if it isn't first turn)
    if(!firstturn)
    {
        for(int i=0;i<allprov.size();i++)
        {
            if(allprov[i].player==current_player)
            {
                allprov[i].curmoney+=allprov[i].curincome;
                if(allprov[i].curmoney<0) // if money in province ends
                {
                    //eliminate this roflocheliks!
                    for(int q=0;q<allprov[i].hexes_x.size();q++)
                    {
                        if(maprel[allprov[i].hexes_x[q]][allprov[i].hexes_y[q]].roflochelik_lvl>0)
                        {
                            maprel[allprov[i].hexes_x[q]][allprov[i].hexes_y[q]].tree==1+(75+rand()%60)/100;
                            // 25/60 probability for tree
                            // 35/60 probability for palm
                        }
                        maprel[allprov[i].hexes_x[q]][allprov[i].hexes_y[q]].roflochelik_lvl=0;
                        allprov[i].curmoney=0;
                    }
                }
            }
        }
    }
    // provinces (recount income)
    reformprovinces(current_player);
    //
    for(int i=0;i<sx;i++)
    {
        for(int j=0;j<sy;j++)
        {
            if(maprel[i][j].player==current_player && maprel[i][j].roflochelik_lvl>0 )
            {
                maprel[i][j].roflochelik_active=true;
            }
            else
            {
                maprel[i][j].roflochelik_active=false;
            }
        }
    }current_action=1;currentprovince=emptyprovince;buildings_status=0;roflochelik_status=0;redrawimg();//reset main parameters & redraw
    /*for(int i=0;i<computer_players.size();i++)
    {
        if(current_player==computer_players[i])
        {
            doComputerTurn();
        }
    }*/
    if(NuClient)
    {
        sendMap();
        is_it_my_turn=false;
    }

}

QString mainrofl::currentplayer()
{
    if(current_player==1)
    {
        return "Red";
    }
    if(current_player==2)
    {
        return "Blue";
    }
    if(current_player==3)
    {
        return "Tan";
    }
    if(current_player==4)
    {
        return "Green";
    }
    if(current_player==5)
    {
        return "Orange";
    }
    if(current_player==6)
    {
        return "Purple";
    }
    if(current_player==7)
    {
        return "Teal";
    }
    if(current_player==8)
    {
        return "Pink";
    }
}

bool mainrofl::hexcanbeattacked(int code)//IMP!!! code 1 means roflochelik already stands on map , code 2 means that roflochelik isn't bought
{
    if(code==1)
    {
    if(maprel[prevc_x][prevc_y].roflochelik_lvl==4)
    {
        return true;
    }
    std::vector< hex > defh = neighbour_hexes(maprel,klitx,klity);
    defh.push_back(maprel[klitx][klity]);
    for(int i=0;i<defh.size();i++)
    {
        if(maprel[klitx][klity].player==defh[i].player && ( defh[i].roflochelik_lvl>=maprel[prevc_x][prevc_y].roflochelik_lvl ||
                                                   (defh[i].tower>0 && defh[i].tower + 1>=maprel[prevc_x][prevc_y].roflochelik_lvl)
                                                   || maprel[klitx][klity].is_capital && maprel[prevc_x][prevc_y].roflochelik_lvl==1/*tbc*/ ) )
        {
                return false;
        }
    }return true;
    }
    else if(code==2)
    {
        if(roflochelik_status==4)
        {
            return true;
        }
        std::vector< hex > defh = neighbour_hexes(maprel,klitx,klity);
        defh.push_back(maprel[klitx][klity]);
        for(int i=0;i<defh.size();i++)
        {
            if(maprel[klitx][klity].player==defh[i].player && ( defh[i].roflochelik_lvl>=roflochelik_status ||
                                                       (defh[i].tower>0 && defh[i].tower + 1>=roflochelik_status)
                                                       || defh[i].is_capital && roflochelik_status==1 ) )
            {
                    return false;
            }
        }return true;
    }
}

bool mainrofl::hexcanbereached()
{    std::vector < hex >  kveve;
     kveve.push_back(maprel[prevc_x][prevc_y]);
     qDebug() << "HEXCANBEREACHED | Chechnya ";
     for(int i=0;i<4;i++)
     {int hi=kveve.size();
         for(int j=0;j<hi;j++)
         {
             std::vector < hex > bufe = neighbour_hexes(maprel,kveve[j].xcoor,kveve[j].ycoor);
             for(int k=0;k<bufe.size();k++)
             {   if(bufe[k].xcoor==klitx && bufe[k].ycoor==klity)
                 {
                     qDebug() << "HEXCANBEREACHED | kruto!\n";
                     return true;
                 }
                 if(bufe[k].player==current_player)
                 {
                     kveve.push_back(bufe[k]);
                 }qDebug() << "HEXCANBEREACHED | sz of kveva: " << kveve.size();
             }
         }
     }
      qDebug() << "HEXCANBEREACHED | kruto!\n";
      return false;
}

void mainrofl::mouse_obrabotchik(int i)
{
    if(i==2)
    {
        // slide, change center_x & center_y
        center_x+=enx-stx;
        center_y+=eny-sty;
    //redrawimg(); // uncom until 0.9.1
    }
    else{
        //click
        qDebug() << "MOB | Click!!!" << ctx << " " << cty << '\n';
        findklitynka(klitx,klity,ctx,cty);
        qDebug() << "MOB | Klitynka!!!" << klitx << " " << klity << '\n' << "prevc_x & y " << prevc_x << " " << prevc_y << '\n' <<
                     maprel[klitx][klity].player << " <- kl pl<> kl lvl -> " << maprel[klitx][klity].roflochelik_lvl << '\n'<<
                     maprel[prevc_x][prevc_y].player << " <- prvc pl<> prvc lvl -> " << maprel[prevc_x][prevc_y].roflochelik_lvl << "\n";



        // Depending on action chosen
        if( ((current_action==1 || current_action==3) && (!(NuClient) || is_it_my_turn ) ) //tbc
                || (NuClient && !is_it_my_turn))// no klitynka w/ unit or province chosen(1) or only province chosen(3) | is it the same?
        {
            if( maprel[klitx][klity].player==current_player && maprel[klitx][klity].roflochelik_lvl>0
                    && maprel[klitx][klity].roflochelik_active)
            {
                current_action=2;// Unit&province chosen
                prevc_x=klitx;
                prevc_y=klity;
            }
            else if((maprel[klitx][klity].player==current_player && ((NuClient && current_player==NuClient->mynum) || !NuClient))
                     )
                {currentprovince=emptyprovince;
                    //choose only province

                    //search through all provinces:
                    for(int i=0;i<allprov.size();i++)
                    {
                        if(allprov[i].player==current_player)
                        {
                            for(int j=0;j<allprov[i].hexes_x.size();j++)
                            {
                                if(klitx==allprov[i].hexes_x[j] && klity==allprov[i].hexes_y[j])
                                {
                                    currentprovince=allprov[i];
                                    current_action=3;
                                }
                            }
                        }
                    }
                }
            else if(NuClient && maprel[klitx][klity].player==NuClient->mynum)
            {
                //search through all provinces:
                for(int i=0;i<allprov.size();i++)
                {
                    if(allprov[i].player==NuClient->mynum)
                    {
                        for(int j=0;j<allprov[i].hexes_x.size();j++)
                        {
                            if(klitx==allprov[i].hexes_x[j] && klity==allprov[i].hexes_y[j])
                            {
                                currentprovince=allprov[i];
                                current_action=3;
                            }
                        }
                    }
                }
            }
            if(NuClient && !is_it_my_turn)
            {
                current_action=1;
            }
        }else

        if(current_action==2 && !( klitx==prevc_x && klity==prevc_y) && (!NuClient || is_it_my_turn))// Unit&province chosen here
        {   current_action=1;
            /*hex shpex;
            if(maprel[prevc_x][prevc_y].player != current_player){
            bool near_my_prov=false;
            // CHANGE HERE WITH ADDING PROVINCES!!!
            std::vector <hex> nbh = neighbour_hexes(maprel,klitx,klity);
            for(int i=0;i<nbh.size();i++)
            {
                if( nbh[i].player==current_player)
                {
                    near_my_prov=true;
                    shpex=nbh[i];
                }
            }} */ //USELESS? MB y
            if( (( maprel[klitx][klity].player==current_player && !maprel[klitx][klity].hatchery && !maprel[klitx][klity].is_capital &&
                   maprel[klitx][klity].roflochelik_lvl+maprel[prevc_x][prevc_y].roflochelik_lvl <= 4 && maprel[klitx][klity].tower==0)
                  || (maprel[klitx][klity].player!=current_player && hexcanbeattacked(1)  ))
                    && hexcanbereached()  // TO BE OPTIMISED LATER . ACTUALLY PATH FROM
                                                                 // (klitx,klity) to (prevc_x,prevc_y) must be <=4

                    && maprel[prevc_x][prevc_y].roflochelik_active
                    )
            {
                if(maprel[klitx][klity].player!=current_player)
                {   int attackedplayer= maprel[klitx][klity].player;
                    maprel[klitx][klity].player=current_player;
                    maprel[klitx][klity].hatchery=false;
                    maprel[klitx][klity].is_capital=false;
                    maprel[klitx][klity].tower=0;
                    maprel[klitx][klity].tree=0;
                    maprel[klitx][klity].roflochelik_lvl=maprel[prevc_x][prevc_y].roflochelik_lvl;
                    // what to do w/ capital? new fun resetcapital();
                    maprel[klitx][klity].roflochelik_lvl=maprel[prevc_x][prevc_y].roflochelik_lvl;
                    maprel[prevc_x][prevc_y].roflochelik_lvl=0;//redrawimg();
                    maprel[klitx][klity].roflochelik_active=false;
                    if(attackedplayer!=0){reformprovinces(attackedplayer);}
                }
                else
                {
                    if(maprel[klitx][klity].roflochelik_lvl==0)
                    {
                       maprel[klitx][klity].roflochelik_active=false;
                    }
                    //
                    if(maprel[klitx][klity].tree>0)
                    {
                        //find province to add +3$
                        for(int w=0;w<allprov.size();w++)
                        {
                            if(allprov[w].player==current_player)
                            {
                                for(int v=0;v<allprov[i].hexes_x.size();v++)
                                {
                                    if(klitx==allprov[w].hexes_x[v] && klity==allprov[w].hexes_y[v])
                                    {
                                        qDebug()<<"MOB | +3 4 3!";
                                        allprov[w].curmoney+=3;
                                        currentprovince=allprov[w];
                                    }
                                }
                            }
                        }

                    }
                    //
                    maprel[klitx][klity].roflochelik_lvl+=maprel[prevc_x][prevc_y].roflochelik_lvl;
                    maprel[prevc_x][prevc_y].roflochelik_lvl=0;
                    maprel[klitx][klity].tree=0;//redrawimg();
                }
            }

        } // THERE'S A DOT!!!
        else if(current_action==4 && (!NuClient || is_it_my_turn)) // roflochelik market is active
        {
            current_action=1;
            if(maprel[klitx][klity].player==current_player)
            {
            for(int i=0;i<allprov.size();i++)
            {
                if(allprov[i].player==current_player)
                {
                    for(int j=0;j<allprov[i].hexes_x.size();j++)
                    {
                        if(allprov[i].hexes_x[j]==klitx && allprov[i].hexes_y[j]==klity)
                        {
                            if(10*roflochelik_status<=allprov[i].curmoney && roflochelik_status+maprel[klitx][klity].roflochelik_lvl<=4 &&
                                    !maprel[klitx][klity].is_capital && maprel[klitx][klity].tower==0 && !maprel[klitx][klity].hatchery)
                            {
                                if(maprel[klitx][klity].roflochelik_lvl==0 || maprel[klitx][klity].roflochelik_active)
                                {
                                    maprel[klitx][klity].roflochelik_active=true;
                                }
                                maprel[klitx][klity].roflochelik_lvl+=roflochelik_status;
                                allprov[i].curmoney-=10*roflochelik_status;
                                currentprovince=emptyprovince;

                                //
                                if(maprel[klitx][klity].tree>0)
                                {
                                    //find province to add +3$
                                    for(int w=0;w<allprov.size();w++)
                                    {
                                        if(allprov[w].player==current_player)
                                        {
                                            for(int v=0;v<allprov[i].hexes_x.size();v++)
                                            {
                                                if(klitx==allprov[w].hexes_x[v] && klity==allprov[w].hexes_y[v])
                                                {
                                                    qDebug()<<"MOB | +3 4 3!";
                                                    allprov[w].curmoney+=3;
                                                    currentprovince=allprov[w];
                                                }
                                            }
                                        }
                                    }

                                }
                                //

                            }
                        }
                    }
                }
            }
            }
            else //maprel[klitx][klity].player==current_player==false
            {   bool foundso=false;
                std::vector<hex> sosedis = neighbour_hexes(maprel,klitx,klity);
                for(int i=sosedis.size()-1;i>-1;i--)
                {
                    if(sosedis[i].player!=current_player)
                    {
                        sosedis.erase(sosedis.begin()+i);
                    }
                }
                for(int f=0;f<sosedis.size();f++)
                {
                    for(int i=0;i<allprov.size();i++)
                    {
                        if(allprov[i].player==current_player)
                        {
                            for(int j=0;j<allprov[i].hexes_x.size();j++)
                            {
                                if(allprov[i].hexes_x[j]==sosedis[f].xcoor && allprov[i].hexes_y[j]==sosedis[f].ycoor)
                                {
                                    if(10*roflochelik_status<=allprov[i].curmoney && hexcanbeattacked(2) && !foundso)
                                    {

                                        maprel[klitx][klity].roflochelik_active=false;
                                        maprel[klitx][klity].roflochelik_lvl=roflochelik_status;
                                        allprov[i].curmoney-=10*roflochelik_status;
                                        //currentprovince=emptyprovince;
                                        int attackedplayer= maprel[klitx][klity].player;
                                        maprel[klitx][klity].player=current_player;
                                        maprel[klitx][klity].hatchery=false;
                                        maprel[klitx][klity].is_capital=false;
                                        maprel[klitx][klity].tower=0;
                                        maprel[klitx][klity].tree=0;
                                        if(attackedplayer!=0){reformprovinces(attackedplayer);}
                                        foundso=true;
                                    }
                                }
                            }
                        }
                    }

            }
        }
        }
        else if(current_action==5 && (!NuClient || is_it_my_turn)) // hatki market is active
        {
            current_action=1;

            for(int i=0;i<allprov.size();i++)
            {
                if(allprov[i].player==current_player)
                {
                    for(int j=0;j<allprov[i].hexes_x.size();j++)
                    {
                        if(allprov[i].hexes_x[j]==klitx && allprov[i].hexes_y[j]==klity)
                        {
                            if(maprel[klitx][klity].roflochelik_lvl==0 && !maprel[klitx][klity].is_capital && !maprel[klitx][klity].hatchery) // hatka can physicaly stand here
                            {
                                currentprovince=allprov[i];
                                if(12+2*numof_hatcheries_in_current_province()<=currentprovince.curmoney && buildings_status==1
                                        && maprel[klitx][klity].tower==0 )
                                {
                                    allprov[i].curmoney-=12+2*numof_hatcheries_in_current_province();
                                    maprel[klitx][klity].hatchery=true;
                                    currentprovince=emptyprovince;
                                }
                                if(currentprovince.curmoney>=15 && buildings_status==2 && maprel[klitx][klity].tower==0 )
                                {
                                    allprov[i].curmoney-=15;
                                    maprel[klitx][klity].tower=1;
                                    currentprovince=emptyprovince;
                                }
                                if(currentprovince.curmoney>=35 && buildings_status==3 && maprel[klitx][klity].tower<2 )
                                {
                                    allprov[i].curmoney-=35;
                                    maprel[klitx][klity].tower=2;
                                    currentprovince=emptyprovince;
                                }
                            }
                        }
                    }
                }
            }

        }






        roflochelik_status=0;
        buildings_status=0;

       reformprovinces(current_player);





                    //redrawimg();
    }
redrawimg();
if(is_it_my_turn && NuClient)
{
    sendMap();
}
}

int mainrofl::klitynka_is_even(int klitynka_y)
{
    return ((klitynka_y) % 2);

}
// MAIN DRAWER FUNCTION -------------------------------------------------------------------------------------------------------
void mainrofl::redrawimg()
{
    qDebug()<<"REDRAW | BEFORE REDRAW!!!";
    QString outpt;
    outpt.clear();
    qDebug() << '\n';
    qDebug() << "REDRAW | Players: " << '\n';
        for(int i=0;i<sx;i++)
        {
            for(int j=0;j<sy;j++)
            {
                outpt+= QString::number(maprel[i][j].player) + QString(" ");
            }
            qDebug() << "REDRAW | " << outpt;
            outpt.clear();
        }
        qDebug()<<"REDRAW | Allprov size: "<<allprov.size();
        outpt.clear();
        qDebug() << '\n';
        qDebug() << "REDRAW | Capitals: " << '\n';
            for(int i=0;i<sx;i++)
            {
                for(int j=0;j<sy;j++)
                {
                    outpt+= QString::number(maprel[i][j].is_capital) + QString(" ");
                }
                qDebug() << "REDRAW | " << outpt;
                outpt.clear();
            }


    //mu1.lock();
    qDebug() << "REDRAW | STARTED! " << square_size << " " << sx <<" " << sy<<" "<<_wdth1 << " "<<_hght1<<'\n';
    //qDebug() << "CENTER OF SCREEN:" << center_x << " " << center_y;
    QPixmap NewPic(wdth1(),wdth1()*4/3);
    //QPixmap Pixmap1(q_tan_palace);
    QPainter NewPicPtr(&NewPic);
    //QPainter QPMD(& Pixmap1);
    //QPMD.drawPixmap(0,0,sx*square_size,sy*square_size,q_teal_palace);
    NewPicPtr.drawPixmap(0,0,wdth1(),wdth1()*4/3,background1);
    for(int var_x=0;var_x<sx;var_x++)
    {
        for(int var_y=0;var_y<sy;var_y++)
        {
            // IF IT'S STANDABLE KLITYNKA IT MAKES SENSE TO DRAW IT---------------------------------------------
            if(maprel[var_x][var_y].is_standable==1)
            {    //qDebug() << "dr!!!stnd" <<'\n';
                // IF IT'S NEUTRAL KLITYNKA
                if(maprel[var_x][var_y].player==0)
                {       //qDebug() << "dr!!!neutral" <<'\n';
                    NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_neutral_empty);
                    if(maprel[var_x][var_y].tree==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_neutral_tree);
                    }
                    else if(maprel[var_x][var_y].tree==2)
                    {
                       NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_neutral_palm);
                    }
                }
                // RED KLITYNKA
                if(maprel[var_x][var_y].player==1)
                {
                    if(maprel[var_x][var_y].is_capital)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_red_palace);
                    }
                    //UNIT1
                    else if(maprel[var_x][var_y].roflochelik_lvl==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_red_1);
                    }
                    //UNIT2
                    else if(maprel[var_x][var_y].roflochelik_lvl==2)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_red_2);
                    }
                    //UNIT3
                    else if(maprel[var_x][var_y].roflochelik_lvl==3)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_red_3);
                    }
                    //UNIT4
                    else if(maprel[var_x][var_y].roflochelik_lvl==4)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_red_4);
                    }
                    //HATCHERY
                    else if(maprel[var_x][var_y].hatchery)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_red_h);
                    }
                    //TOWER 1
                    else if(maprel[var_x][var_y].tower==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_red_t1);
                    }
                    //TOWER 2
                    else if(maprel[var_x][var_y].tower==2)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_red_t2);
                    }
                    else if(maprel[var_x][var_y].tree==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_red_tree);
                    }
                    else if(maprel[var_x][var_y].tree==2)
                    {
                       NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_red_palm);
                    }
                    // HERE DRAW TREE/HATCHERY/UNIT!
                    else
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_red_empty);
                    }
                }
                // BLUE KLITYNKA
                if(maprel[var_x][var_y].player==2)
                {
                    if(maprel[var_x][var_y].is_capital)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_blue_palace);
                    }
                    //UNIT1
                    else if(maprel[var_x][var_y].roflochelik_lvl==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_blue_1);
                    }
                    //UNIT2
                    else if(maprel[var_x][var_y].roflochelik_lvl==2)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_blue_2);
                    }
                    //UNIT3
                    else if(maprel[var_x][var_y].roflochelik_lvl==3)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_blue_3);
                    }
                    //UNIT4
                    else if(maprel[var_x][var_y].roflochelik_lvl==4)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_blue_4);
                    }
                    //HATCHERY
                    else if(maprel[var_x][var_y].hatchery)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_blue_h);
                    }
                    //TOWER 1
                    else if(maprel[var_x][var_y].tower==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_blue_t1);
                    }
                    //TOWER 2
                    else if(maprel[var_x][var_y].tower==2)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_blue_t2);
                    }
                    else if(maprel[var_x][var_y].tree==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_blue_tree);
                    }
                    else if(maprel[var_x][var_y].tree==2)
                    {
                       NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_blue_palm);
                    }
                    // HERE DRAW TREE/HATCHERY/UNIT!
                    else
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_blue_empty);
                    }
                }
                // TAN KLITYNKA
                if(maprel[var_x][var_y].player==3)
                {
                    if(maprel[var_x][var_y].is_capital)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_tan_palace);
                    }
                    //UNIT1
                    else if(maprel[var_x][var_y].roflochelik_lvl==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_tan_1);
                    }
                    //UNIT2
                    else if(maprel[var_x][var_y].roflochelik_lvl==2)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_tan_2);
                    }
                    //UNIT3
                    else if(maprel[var_x][var_y].roflochelik_lvl==3)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_tan_3);
                    }
                    //UNIT4
                    else if(maprel[var_x][var_y].roflochelik_lvl==4)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_tan_4);
                    }
                    //HATCHERY
                    else if(maprel[var_x][var_y].hatchery)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_tan_h);
                    }
                    //TOWER 1
                    else if(maprel[var_x][var_y].tower==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_tan_t1);
                    }
                    //TOWER 2
                    else if(maprel[var_x][var_y].tower==2)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_tan_t2);
                    }
                    else if(maprel[var_x][var_y].tree==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_tan_tree);
                    }
                    else if(maprel[var_x][var_y].tree==2)
                    {
                       NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_tan_palm);
                    }
                    // HERE DRAW TREE/HATCHERY/UNIT!
                    else
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_tan_empty);
                    }
                }
                // GREEN KLITYNKA
                if(maprel[var_x][var_y].player==4)
                {
                    if(maprel[var_x][var_y].is_capital)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_green_palace);
                    }
                    //UNIT1
                    else if(maprel[var_x][var_y].roflochelik_lvl==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_green_1);
                    }
                    //UNIT2
                    else if(maprel[var_x][var_y].roflochelik_lvl==2)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_green_2);
                    }
                    //UNIT3
                    else if(maprel[var_x][var_y].roflochelik_lvl==3)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_green_3);
                    }
                    //UNIT4
                    else if(maprel[var_x][var_y].roflochelik_lvl==4)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_green_4);
                    }
                    //HATCHERY
                    else if(maprel[var_x][var_y].hatchery)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_green_h);
                    }
                    //TOWER 1
                    else if(maprel[var_x][var_y].tower==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_green_t1);
                    }
                    //TOWER 2
                    else if(maprel[var_x][var_y].tower==2)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_green_t2);
                    }
                    else if(maprel[var_x][var_y].tree==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_green_tree);
                    }
                    else if(maprel[var_x][var_y].tree==2)
                    {
                       NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_green_palm);
                    }
                    // HERE DRAW TREE/HATCHERY/UNIT!
                    else
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_green_empty);
                    }
                }
                // ORANGE KLITYNKA
                if(maprel[var_x][var_y].player==5)
                {
                    if(maprel[var_x][var_y].is_capital)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_orange_palace);
                    }
                    //UNIT1
                    else if(maprel[var_x][var_y].roflochelik_lvl==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_orange_1);
                    }
                    //UNIT2
                    else if(maprel[var_x][var_y].roflochelik_lvl==2)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_orange_2);
                    }
                    //UNIT3
                    else if(maprel[var_x][var_y].roflochelik_lvl==3)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_orange_3);
                    }
                    //UNIT4
                    else if(maprel[var_x][var_y].roflochelik_lvl==4)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_orange_4);
                    }
                    //HATCHERY
                    else if(maprel[var_x][var_y].hatchery)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_orange_h);
                    }
                    //TOWER 1
                    else if(maprel[var_x][var_y].tower==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_orange_t1);
                    }
                    //TOWER 2
                    else if(maprel[var_x][var_y].tower==2)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_orange_t2);
                    }
                    else if(maprel[var_x][var_y].tree==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_orange_tree);
                    }
                    else if(maprel[var_x][var_y].tree==2)
                    {
                       NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_orange_palm);
                    }
                    // HERE DRAW TREE/HATCHERY/UNIT!
                    else
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_orange_empty);
                    }
                }
                // PURPLE KLITYNKA
                if(maprel[var_x][var_y].player==6)
                {
                    if(maprel[var_x][var_y].is_capital)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_purple_palace);
                    }
                    //UNIT1
                    else if(maprel[var_x][var_y].roflochelik_lvl==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_purple_1);
                    }
                    //UNIT2
                    else if(maprel[var_x][var_y].roflochelik_lvl==2)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_purple_2);
                    }
                    //UNIT3
                    else if(maprel[var_x][var_y].roflochelik_lvl==3)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_purple_3);
                    }
                    //UNIT4
                    else if(maprel[var_x][var_y].roflochelik_lvl==4)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_purple_4);
                    }
                    //HATCHERY
                    else if(maprel[var_x][var_y].hatchery)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_purple_h);
                    }
                    //TOWER 1
                    else if(maprel[var_x][var_y].tower==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_purple_t1);
                    }
                    //TOWER 2
                    else if(maprel[var_x][var_y].tower==2)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_purple_t2);
                    }
                    else if(maprel[var_x][var_y].tree==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_purple_tree);
                    }
                    else if(maprel[var_x][var_y].tree==2)
                    {
                       NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_purple_palm);
                    }
                    // HERE DRAW TREE/HATCHERY/UNIT!
                    else
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_purple_empty);
                    }
                }
                // TEAL KLITYNKA
                if(maprel[var_x][var_y].player==7)
                {
                    if(maprel[var_x][var_y].is_capital)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_teal_palace);
                    }
                    //UNIT1
                    else if(maprel[var_x][var_y].roflochelik_lvl==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_teal_1);
                    }
                    //UNIT2
                    else if(maprel[var_x][var_y].roflochelik_lvl==2)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_teal_2);
                    }
                    //UNIT3
                    else if(maprel[var_x][var_y].roflochelik_lvl==3)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_teal_3);
                    }
                    //UNIT4
                    else if(maprel[var_x][var_y].roflochelik_lvl==4)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_teal_4);
                    }
                    //HATCHERY
                    else if(maprel[var_x][var_y].hatchery)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_teal_h);
                    }
                    //TOWER 1
                    else if(maprel[var_x][var_y].tower==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_teal_t1);
                    }
                    //TOWER 2
                    else if(maprel[var_x][var_y].tower==2)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_teal_t2);
                    }
                    else if(maprel[var_x][var_y].tree==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_teal_tree);
                    }
                    else if(maprel[var_x][var_y].tree==2)
                    {
                       NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_teal_palm);
                    }
                    // HERE DRAW TREE/HATCHERY/UNIT!
                    else
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_teal_empty);
                    }
                }
                // PINK KLITYNKA
                if(maprel[var_x][var_y].player==8)
                {
                    if(maprel[var_x][var_y].is_capital)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_pink_palace);
                    }
                    //UNIT1
                    else if(maprel[var_x][var_y].roflochelik_lvl==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_pink_1);
                    }
                    //UNIT2
                    else if(maprel[var_x][var_y].roflochelik_lvl==2)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_pink_2);
                    }
                    //UNIT3
                    else if(maprel[var_x][var_y].roflochelik_lvl==3)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_pink_3);
                    }
                    //UNIT4
                    else if(maprel[var_x][var_y].roflochelik_lvl==4)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_pink_4);
                    }
                    //HATCHERY
                    else if(maprel[var_x][var_y].hatchery)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_pink_h);
                    }
                    //TOWER 1
                    else if(maprel[var_x][var_y].tower==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_pink_t1);
                    }
                    //TOWER 2
                    else if(maprel[var_x][var_y].tower==2)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_pink_t2);
                    }
                    else if(maprel[var_x][var_y].tree==1)
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_pink_tree);
                    }
                    else if(maprel[var_x][var_y].tree==2)
                    {
                       NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_pink_palm);
                    }
                    // HERE DRAW TREE/HATCHERY/UNIT!
                    else
                    {
                        NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,q_pink_empty);
                    }
                }




                // SAVING QPIXMAP
                //qDebug() << "REDRAW FINISHED! " <<'\n';

                //qDebug() << "REDRAWED IMAGE SAVED! " <<'\n';
            }
            //IF IT'S NOT STANDABLE KLITYNKA
           else
            {
                NewPicPtr.drawPixmap(var_x*square_size+center_x-wdth1()/2,var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,square_size,square_size,or_vodichka);
            }
        }
    }
    qDebug() << "REDRAW | FINISHED! " <<'\n';
    //Pixmap1.save(":/resources/q_final_image.png");
    //QFile filetosave(":/resources/q_final_image.png");
    //QFile filetosave("D:/Vova/testimage23.png");
    //filetosave.open(QIODevice::WriteOnly);
    //NewPic.save(&filetosave);
    //std::string valq= apppth() + "/curimage.png";
    qDebug() <<"REDRAW | " << q_red_palace.height() << " " << q_red_palace.width() << " " << NewPic.save(apppth() + QString("/curimage.png")) << '\n';
    qDebug() <<"REDRAW | " << NewPic.save(apppth() + QString("/curimage2.png")) << '\n';
    //qDebug() << "REDRAWED IMAGE SAVED! " << NewPic.save(":/resources/q_final_image.png") << NewPic.save(("D:/Vova/testimage23.png"))<<'\n';
    //mu1.unlock();
    qDebug()<<"REDRAW | AFTER REDRAW!!!";
    //QString outpt;
    outpt.clear();
    qDebug() << '\n';
    qDebug() << "REDRAW | Players: " << '\n';
        for(int i=0;i<sx;i++)
        {
            for(int j=0;j<sy;j++)
            {
                outpt+= QString::number(maprel[i][j].player) + QString(" ");
            }
            qDebug()<< "REDRAW | " << outpt;
            outpt.clear();
        }
        qDebug()<<"REDRAW | Allprov size: "<<allprov.size();
        outpt.clear();
        qDebug() << '\n';
        qDebug() << "REDRAW | Capitals: " << '\n';
            for(int i=0;i<sx;i++)
            {
                for(int j=0;j<sy;j++)
                {
                    outpt+= QString::number(maprel[i][j].is_capital) + QString(" ");
                }
                qDebug() << "REDRAW | " <<outpt;
                outpt.clear();
            }
            emit redrawFinishedtoQML();

}

QString mainrofl::moneycu()
{
    if(!(currentprovince.player==-1)) // empty province
    {
    return QString::number(currentprovince.curmoney)+"$";
    }else
    {
        return "";
    }
}

QString mainrofl::incomecu()
{
    if(!(currentprovince.player==-1)) // empty province
    {
    if(currentprovince.curincome<=0) {return QString::number(currentprovince.curincome) + "$";}
    else {return "+" + QString::number(currentprovince.curincome) + "$";}
    }else
    {
        return "";
    }
}
void mainrofl::scalepp(int times)//mb square_size/=step ? TBCF
{
    int prev_size=square_size;
    square_size+=10*times;
    if(square_size>300)
    {
        square_size=300;
    }
    redrawimg();
}
void mainrofl::scalemm(int times)//mb square_size*=step ? TBCF
{
    int prev_size=square_size;
    square_size-=10*times;
    if(square_size<10)
    {
        square_size=10;
    }
    redrawimg();
}

void mainrofl::findklitynka(int & klitynka_x,int & klitynka_y,int mouse_x,int mouse_y)
{
//var_x*square_size+center_x-wdth1()/2,
    //var_y*square_size+square_size/2*klitynka_is_even(var_x)+center_y-hght1()*2/3,
    //square_size,square_size
    for(int ix=0;ix<sx;ix++)
     {
         for(int iy=0;iy<sy;iy++)
         {
             if(ix*square_size+center_x-wdth1()/2 <= mouse_x && mouse_x < (ix+1)*square_size+center_x-wdth1()/2)
             {
                 if(iy*square_size+square_size/2*klitynka_is_even(ix)+center_y-hght1()*2/3 <= mouse_y)
                 {
                     if((iy+1)*square_size+square_size/2*klitynka_is_even(ix)+center_y-hght1()*2/3 > mouse_y)
                     {
                         klitynka_x=ix;
                         klitynka_y=iy;
                         return;
                     }
                 }
             }
         }
     }
}
// RAW next
void mainrofl::reformprovinces(int player) // it happens every microturn ! (by conception)
{
    //allprov.clear(); // tut bylo eto
    qDebug()<<"REF_PROV | player:" << player<<" ALLPROV vector SIZE: " << allprov.size();
    std::vector< hex > capitals;
    for(int i=0;i<sx;i++)
    {
        for(int j=0;j<sy;j++)
        {
            if(maprel[i][j].player==player && maprel[i][j].is_capital)
            {
                capitals.push_back(maprel[i][j]);
                qDebug()<<"REF_PROV | +cap";
            }
        }
    }
    std::vector<province> prevprov;
    std::vector<int> prevprov_indexes;
    for(int i=0;i<allprov.size();i++)
    {
        if(allprov[i].player == player)
        {
            allprov[i].curincome=0;
            prevprov.push_back(allprov[i]);
            prevprov_indexes.push_back(i);
            qDebug()<<"REF_PROV | +prevprov";
        }
    }
    std::vector<province> newprov;
    for(int i=0;i<capitals.size();i++)
    {
        newprov.push_back(formprovince(capitals[i],player));
    }
    //
    /* HERE WE NEED TO FIND ISOLATED PROVINCES!!! (and add capital here?)
     *
     */
    for(int i=0;i<sx;i++)
    {
        for(int j=0;j<sy;j++)
        {
            if(maprel[i][j].player==player && !isinanyprov(newprov,maprel[i][j]))
            {
                qDebug()<<"REF_PROV | POGCHAMP!";
                province brandnewprovince = formprovince(maprel[i][j],player);
                int capitalrand = rand()%brandnewprovince.hexes_x.size();
                maprel[brandnewprovince.hexes_x[capitalrand]][brandnewprovince.hexes_y[capitalrand]].is_capital=true;
                maprel[brandnewprovince.hexes_x[capitalrand]][brandnewprovince.hexes_y[capitalrand]].hatchery=false;
                maprel[brandnewprovince.hexes_x[capitalrand]][brandnewprovince.hexes_y[capitalrand]].tower=0;
                maprel[brandnewprovince.hexes_x[capitalrand]][brandnewprovince.hexes_y[capitalrand]].roflochelik_lvl=0;
                newprov.push_back(brandnewprovince);
            }
        }
    }//rdy   // cia shtuka perenesena!
    // : Cut off all of provinces with only 1 klitynka (from allprov)! Here?
    std::vector<int> postoer;
    for(int i=0;i<allprov.size();i++)
    {
        if(allprov[i].hexes_x.size()==1)
        {
            postoer.push_back(i);
        }
    }
    for(int i=postoer.size()-1;i>-1;i--)
    {
        qDebug()<<"REF_PROV | del(allprov): " <<allprov[postoer[i]].hexes_x[0]<<" , "<<allprov[postoer[i]].hexes_y[0];
        //then delete all of units,houses,capitals from this single hex & set trees over roflocheliks
        if(maprel[allprov[postoer[i]].hexes_x[0]][allprov[postoer[i]].hexes_y[0]].roflochelik_lvl>0)
        {
             maprel[allprov[postoer[i]].hexes_x[0]][allprov[postoer[i]].hexes_y[0]].tree=1;
        }
        if(maprel[allprov[postoer[i]].hexes_x[0]][allprov[postoer[i]].hexes_y[0]].roflochelik_lvl>2)
        {
             maprel[allprov[postoer[i]].hexes_x[0]][allprov[postoer[i]].hexes_y[0]].tree=2;
        }
        maprel[allprov[postoer[i]].hexes_x[0]][allprov[postoer[i]].hexes_y[0]].is_capital=false;
        maprel[allprov[postoer[i]].hexes_x[0]][allprov[postoer[i]].hexes_y[0]].hatchery=false;
        maprel[allprov[postoer[i]].hexes_x[0]][allprov[postoer[i]].hexes_y[0]].roflochelik_lvl=0;
        maprel[allprov[postoer[i]].hexes_x[0]][allprov[postoer[i]].hexes_y[0]].tower=0;
        //then erase this province
        allprov.erase(allprov.begin()+postoer[i]);
    }
    postoer.clear();//do same w/ newly detected provinces
    for(int i=0;i<newprov.size();i++)
    {
        if(newprov[i].hexes_x.size()==1)
        {
            postoer.push_back(i);
        }
    }
    for(int i=postoer.size()-1;i>-1;i--)
    {
        qDebug()<<"REF_PROV | del(newprov) " <<newprov[postoer[i]].hexes_x[0]<<" , "<<newprov[postoer[i]].hexes_y[0];
        //then delete all of units,houses,capitals from this single hex & set trees over roflocheliks
        if(maprel[newprov[postoer[i]].hexes_x[0]][newprov[postoer[i]].hexes_y[0]].roflochelik_lvl>0)
        {
             maprel[newprov[postoer[i]].hexes_x[0]][newprov[postoer[i]].hexes_y[0]].tree=1;
        }
        if(maprel[newprov[postoer[i]].hexes_x[0]][newprov[postoer[i]].hexes_y[0]].roflochelik_lvl>2)
        {
             maprel[newprov[postoer[i]].hexes_x[0]][newprov[postoer[i]].hexes_y[0]].tree=2;
        }
        maprel[newprov[postoer[i]].hexes_x[0]][newprov[postoer[i]].hexes_y[0]].is_capital=false;
        maprel[newprov[postoer[i]].hexes_x[0]][newprov[postoer[i]].hexes_y[0]].hatchery=false;
        maprel[newprov[postoer[i]].hexes_x[0]][newprov[postoer[i]].hexes_y[0]].roflochelik_lvl=0;
        maprel[newprov[postoer[i]].hexes_x[0]][newprov[postoer[i]].hexes_y[0]].tower=0;
        //then erase this province
        qDebug()<<"REF_PROV | normas";
        newprov.erase(newprov.begin()+postoer[i]);
        qDebug()<<"REF_PROV | erased";
    }
    //rdy
    for(int i=0;i<capitals.size();i++)
    {
        for(int co=0;co<prevprov.size();co++) // COMPARING NEW PROVINCES W/ PREVIOUSLY EXISTING
        {
            if(newprov[i].player==prevprov[co].player && newprov[i].hexes_x== prevprov[co].hexes_x
                    && newprov[i].hexes_y== prevprov[co].hexes_y)
            { qDebug()<<"REF_PROV | Ya shos znayshov!";
                newprov.erase(newprov.begin()+i);
                prevprov.erase(prevprov.begin()+co);
                capitals.erase(capitals.begin()+i);
                prevprov_indexes.erase(prevprov_indexes.begin()+co);
            }else{qDebug()<<"REF_PROV | Ya nihuya ne znayshov!";}
        }
    }

    //rdy

    if(newprov.empty() && !prevprov.empty())// is it OK?
    {
        //Pohodu provincii pizda!
        qDebug()<<"REF_PROV | Pohodu provincii pizda!";
        allprov.erase(allprov.begin()+prevprov_indexes[0]); //correct according to T1 (?)

    }
    else


    if(newprov.empty())
    {
        qDebug() << "REF_PROV | ALL REMAINS THE SAME!";

    }
    else
    {
        qDebug() << "REF_PROV | YA BESHANIY BLYAT!";
        // CHANGE PROVINCE
        // START HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        if(newprov.size()==prevprov.size())
        {
            if(newprov.size()==1)
            {
             //EQUALITY
             qDebug() << "REF_PROV | Equality!";
             newprov[0].curmoney=prevprov[0].curmoney;
             allprov[prevprov_indexes[0]]=newprov[0]; //correct according to T1 (1)
            }
            else
            {
                // is it OK? TBC
                // taki smert
                //inEQUALITY <
                 qDebug() << "REF_PROV | Smert!";
                 int bufmoney=0;
                 for(int i=prevprov.size()-1;i>-1;i--)
                 {
                     allprov.erase(allprov.begin()+prevprov_indexes[i]); //correct according to T1 | is it?
                     bufmoney+=prevprov[i].curmoney;
                 }
                 newprov[0].curmoney=bufmoney;
                 allprov.push_back(newprov[0]);
                 //TBP : delete all of multicapitals (leaving one capital)
                 for(int times=0;times<prevprov.size()-1;times++)
                 {
                     for(int i=0;i<sx;i++)
                     {
                         for(int j=0;j<sy;j++)
                         {
                             if(maprel[i][j].player==player && maprel[i][j].is_capital)
                             {qDebug()<<"REF_PROV | Slava";
                                 if(hexinprovince(newprov[0],maprel[i][j]))
                                 {qDebug()<<"REF_PROV | Ukraini!";
                                 maprel[i][j].is_capital=false; // delete (previous number of regions)-1 capitals (leave 1 for new provinces)
                                 }
                             }
                         }
                     }
                 }//here it ends




            }
        }
        else if(newprov.size()>prevprov.size())
        {
            //inEQUALITY >
             qDebug() << "Rozmnozhennya!";
             allprov.erase(allprov.begin()+prevprov_indexes[0]);//correct according to T1 | is it?
             for(int i=0;i<newprov.size();i++)
             {
                 newprov[i].curmoney=0; // all money comes to firstborn province or firstly found on map(if capital destroyed)
             }
             newprov[0].curmoney=prevprov[0].curmoney;
             for(int i=0;i<newprov.size();i++)
             {
                 allprov.push_back(newprov[i]);
             }
        }
        else
        {   /*
            //inEQUALITY <*/
             qDebug() << "REF_PROV | Smert!";
             /*int bufmoney=0;
             for(int i=prevprov.size()-1;i>-1;i--)
             {
                 allprov.erase(allprov.begin()+prevprov_indexes[i]); //correct according to T1 | is it?
                 bufmoney+=prevprov[i].curmoney;
             }
             newprov[0].curmoney=bufmoney;
             allprov.push_back(newprov[0]);
             //TBP : delete all of multicapitals (leaving one capital)
             for(int times=0;times<prevprov.size()-1;times++)
             {
                 for(int i=0;i<sx;i++)
                 {
                     for(int j=0;j<sy;j++)
                     {
                         if(maprel[i][j].player==player && maprel[i][j].is_capital)
                         {qDebug()<<"Slava";
                             if(hexinprovince(newprov[0],maprel[i][j]))
                             {qDebug()<<"Ukraini!";
                             maprel[i][j].is_capital=false; // delete (previous number of regions)-1 capitals (leave 1 for new provinces)
                             }
                         }
                     }
                 }
             }//here it ends*/ //mb etot kusok useless | is it?
        }

    }

    //Calc income
    //std::vector<province> finprov;
    for(int i=0;i<allprov.size();i++) // Here some bugs! is it OK? here
    {
        if(allprov[i].player == player)
        {
            allprov[i].curincome=0;

            //NEW Economics calc system | is it OK? YES
            for(int q=0;q<allprov[i].hexes_x.size();q++)
            {
                int curx=allprov[i].hexes_x[q];
                int cury=allprov[i].hexes_y[q];
                hex curh=maprel[curx][cury];
                int curi = allprov[i].curincome;
                curi++;
                if(curh.roflochelik_lvl==1)
                {
                    curi-=2;
                }
                if(curh.roflochelik_lvl==2)
                {
                    curi-=6;
                }
                if(curh.roflochelik_lvl==3)//???
                {
                    curi-=18;
                }
                if(curh.roflochelik_lvl==4)//???
                {
                    curi-=36;
                }
                if(curh.tree!=0)
                {
                    curi--;
                }
                if(curh.tower==1)
                {
                    curi--;
                }
                if(curh.tower==2)
                {
                    curi-=6;
                }
                if(curh.hatchery)
                {
                    curi+=4;
                }
                allprov[i].curincome=curi;
            }


            //finprov.push_back(allprov[i]);
        }
    }
    /*for(int i=positionstoerase.size()-1;i>-1;i--)//
    {//
        allprov.erase(allprov.begin()+positionstoerase[i]);//
    }//
    for(int i=0;i<finprov.size();i++)
    {int curi=0;
        for(int q=0;q<finprov[i].hexes_x.size();q++)
        {
            int curx=finprov[i].hexes_x[q];
            int cury=finprov[i].hexes_y[q];
            hex curh=maprel[curx][cury];
            curi++;
            if(curh.roflochelik_lvl==1)
            {
                curi-=2;
            }
            if(curh.roflochelik_lvl==2)
            {
                curi-=6;
            }
            if(curh.roflochelik_lvl==3)//???
            {
                curi-=14;
            }
            if(curh.roflochelik_lvl==4)//???
            {
                curi-=36;
            }
            if(curh.tree!=0)                              // SOME REAL PROBLEMS W/ THAT PART
            {                                             // WHY DONT JUST EDIT EXISTING PROVINCES(that's why this part is commented)
                curi--;
            }
            if(curh.tower==1)
            {
                curi--;
            }
            if(curh.tower==2)
            {
                curi-=6;
            }
            if(curh.hatchery)
            {
                curi+=4;
            }
            finprov[i].curincome=curi;
        }allprov.push_back(finprov[i]);
    }*/
}

bool mainrofl::isinanyprov(std::vector<province> provs, hex h)
{
    for(int i=0;i<provs.size();i++)
    {
        if(hexinprovince(provs[i],h))
        {
            return true;
        }
    }return false;
}


bool mainrofl::hexinprovince(province prov,hex h)
{
    for(int i=0;i<prov.hexes_x.size();i++)
    {
        if(prov.hexes_x[i]==h.xcoor && prov.hexes_y[i]==h.ycoor)
        {
            return true;
        }
    }
    return false;
}


mainrofl::province mainrofl::formprovince(hex centralhex,int player)
{
    province thisprovince;
    thisprovince.hexes_x.clear();
    thisprovince.hexes_y.clear();
    thisprovince.curincome=0;
    thisprovince.curmoney=0;
    thisprovince.player=player;
    std::vector<hex> kveva;
    kveva.push_back(centralhex);
    std::vector<hex> visitedhexes;
    std::vector<int> hsx;
    std::vector<int> hsy;
    hsx.push_back(centralhex.xcoor);
    hsy.push_back(centralhex.ycoor);
    while(!kveva.empty())
    {
        std::vector<hex> sosedi = neighbour_hexes(maprel,kveva.front().xcoor,kveva.front().ycoor);
        visitedhexes.push_back(kveva.front());
        kveva.erase(kveva.begin());
        for(int i=0;i<sosedi.size();i++)
        {
            if(sosedi[i].player==player && notinkveva(kveva,sosedi[i]) && notvisited(visitedhexes,sosedi[i]))
            {
                kveva.push_back(sosedi[i]);
                hsx.push_back(sosedi[i].xcoor);
                hsy.push_back(sosedi[i].ycoor);
            }
        }
    }
    thisprovince.hexes_x=hsx;
    thisprovince.hexes_y=hsy;
    qDebug()<<"FORMPROV | BEFORE SORT!:";
    for(int i=0;i<thisprovince.hexes_x.size();i++)
    {
        qDebug() << thisprovince.hexes_x[i] << "<>" << thisprovince.hexes_y[i];
    }
    thisprovince = sortedprovince(thisprovince);
    qDebug()<<"FORMPROV | AFTER SORT!:";
    for(int i=0;i<thisprovince.hexes_x.size();i++)
    {
        qDebug() << thisprovince.hexes_x[i] << "<>" << thisprovince.hexes_y[i];
    }
    return thisprovince;
}

bool mainrofl::notinkveva(std::vector<hex> kveva, hex element)
{
    for(int i=0;i<kveva.size();i++)
    {
        if(element.xcoor==kveva[i].xcoor && element.ycoor==kveva[i].ycoor)
        {
            return false;
        }
    }return true;
}

bool mainrofl::notvisited(std::vector<hex> vec, hex element)
{
    for(int i=0;i<vec.size();i++)
    {
        if(element.xcoor==vec[i].xcoor && element.ycoor==vec[i].ycoor)
        {
            return false;
        }
    }return true;
}

mainrofl::province mainrofl::sortedprovince(province prov)
{
    province sprov;
    sprov.curincome=prov.curincome;
    sprov.curmoney=prov.curmoney;
    sprov.player=prov.player;

    std::vector<coordinates> coorv;
    for(int i=0;i<prov.hexes_x.size();i++)
    {
        coordinates bufcoor;
        bufcoor.x_c=prov.hexes_x[i];
        bufcoor.y_c=prov.hexes_y[i];
        coorv.push_back(bufcoor);
    }
    for(int i=0;i<coorv.size();i++)
    {
        for(int j=0;j<coorv.size();j++)
        {
            if(coorv[i].x_c>coorv[j].x_c || (coorv[i].x_c==coorv[j].x_c && coorv[i].y_c>coorv[j].y_c))
            {
                coordinates buf = coorv[i];
                coorv[i]=coorv[j];
                coorv[j]=buf;
            }
        }
    }
    sprov.hexes_x.clear();
    sprov.hexes_y.clear();
    for(int i=0;i<coorv.size();i++)
    {
        sprov.hexes_x.push_back(coorv[i].x_c);
        sprov.hexes_y.push_back(coorv[i].y_c);
    }
    return sprov;
}

int mainrofl::roflochelik_button_clicked()
{
    if(roflochelik_status==0)
    {
        current_action=4; // roflochelik buy menu is active
        roflochelik_status=1;
        buildings_status=0;
    }
    else
    {
        roflochelik_status++;
        if(roflochelik_status>4)
        {
            roflochelik_status=1;
            //current_action=1;
        }

    }return roflochelik_status;
}

QString mainrofl::buildings_button_clicked()
{
    if(buildings_status==0)
    {
        current_action=5; // hatchery buy menu is active
        buildings_status=1;
        roflochelik_status=0;
    }
    else
    {
        buildings_status++;
        if(buildings_status>3)
        {
            buildings_status=1;
        }
    }
    if(buildings_status==1 && currentprovince.player!=-1)
    {
        int numtoret= 12+ 2*numof_hatcheries_in_current_province();
        return QString::number(numtoret)+"$";
    }
    if(buildings_status==1)
    {
        return "";
    }
    if(buildings_status==2)
    {
        return "15$";
    }
    if(buildings_status==3)
    {
        return "35$";
    }
    return QString();
}

int mainrofl::numof_hatcheries_in_current_province()
{
    int counter=0;
    for(int i=0;i<currentprovince.hexes_x.size();i++)
    {
        if(maprel[currentprovince.hexes_x[i]][currentprovince.hexes_y[i]].hatchery)
        {
            counter++;
        }
    }return counter;
}

//----------------SMTH MP!---------------
void mainrofl::host(int numofplayers)
{
    qDebug() << "HOST | server creation, numofplayers: "<<numofplayers;
    NuServ = new multiplayer_server(1234,numofplayers,this);
    //NuServ-();
    //NuClient = new multiplayer_client(QUrl("ws://"+ipAddress+"1234"),this);//join to ur own server |IMP is it needed?
    NuClient = new multiplayer_client(QUrl("ws://localhost:1234"),this);
}
void mainrofl::join(QString ip)
{
    qDebug() << "JOIN | Client creation ";
    //NuClient = new multiplayer_client(QUrl("ws://"+ipAddress+"1234"),this);
    if (NuClient)
        NuClient->deleteLater();
    NuClient = new multiplayer_client(QUrl("ws://"+ip+":1234"),this);

}
void mainrofl::exit_from_serv()
{
    if (NuClient)
    {
        NuClient->sendMess(QString("Goodbye, my lovaah"));
        delete NuClient;
    }
    if(NuServ)
    {   delete NuServ;}
    NuServ=0;
    NuClient=0;
}
int mainrofl::sendMap()
{
     QString Map;
     Map+="m "+QString::number(current_player)+QString(" ")+QString::number(firstturn)+QString(" ");
     Map+=QString::number(sx)+QString(" ")+QString::number(sy)+QString(" ");
     qDebug()<<"SENDMAP | numpgame -- "<<sx;

     for(int i=0;i<sx;i++)
     {
         for(int j=0;j<sy;j++)
         {
             Map+=QString::number(maprel[i][j].is_standable)+QString(" ")+QString::number(maprel[i][j].player)+QString(" ");
             Map+=QString::number(maprel[i][j].is_capital)+QString(" ")+QString::number(maprel[i][j].tree)+QString(" ");
             Map+=QString::number(maprel[i][j].hatchery)+QString(" ")+QString::number(maprel[i][j].tower)+QString(" ");
             Map+=QString::number(maprel[i][j].roflochelik_lvl)+QString(" ")+QString::number(maprel[i][j].roflochelik_active)+QString(" ");
         }
     }
     qDebug()<<"SENDMAP | numpgame **" << allprov.size();

     Map+=QString::number(allprov.size())+" ";
     for(int i=0;i<allprov.size();i++)
     {
         Map+=QString::number(allprov[i].player)+QString(" ")+
                 QString::number(allprov[i].curincome)+QString(" ");
         Map+=QString::number(allprov[i].curmoney)+QString(" ")+
                 QString::number(allprov[i].hexes_x.size())+QString(" ");
         //qDebug() << "SENDMAP | in for1 " << i << "  MAP:" << Map;
         qDebug() << "SENDMAP | Sizes x=" << allprov[i].hexes_x.size() << " y:" <<
                                                   allprov[i].hexes_y.size();
         for(int q=0;q<allprov[i].hexes_x.size();q++)
         {
             Map+=QString::number(allprov[i].hexes_x[q])+QString(" ")+
                     QString::number(allprov[i].hexes_y[q])+QString(" ");
             //qDebug() << "SENDMAP | in for2 " << i << " q " << q << " MAP:"<< Map;
         }
     }
     qDebug()<<"SENDMAP | transmission: size( "<< Map.size()<<" )";
     qDebug()<< Map;
     return (NuClient->sendMess(Map));
}

void mainrofl::sendMainInfo(QString size, int numofplayers, QString numofprovinces)
{
    //Here we send map info:
    NuClient->sendMess("i "+size+" "+QString::number(numofplayers)+" "+numofprovinces);
}

void mainrofl::start_mp_game(QString size, int numofplayers, QString numofprovinces)
{
    //qDebug()<<"numpgame";
    createmap(size,numofplayers,numofprovinces);
    qDebug()<<"START_MP | map created!";
    qDebug()<<"START_MP | transmission"<<sendMap();
    NuClient->sendMess("s");
}

int mainrofl::numof_players_inlobby()
{
    if(NuClient)
        return NuClient->cur_players();
    else
        return 0;
}

void mainrofl::sendNumOfPlayersToQMLf(int num)
{
    emit sendNumOfPlayersToQML(num);
}
void mainrofl::sendYourNumToQMLf(int num)
{
    emit sendYourNumToQML(num);
}
void mainrofl::sendMainInfoToQMLf(QString size,int players,QString provinces)
{
    numofplayers_=players;
    emit sendMainInfoToQML(size,players,provinces);
}
void mainrofl::startGameQMLf()
{
    game_started=true;
    is_it_my_turn=false;
    center_x = _wdth1/2;
    center_y = _wdth1*2/3;
    square_size=_wdth1/sx;
    emit startGameQML();
}
void mainrofl::sendMapQMLf(bool ismyturn)
{
    is_it_my_turn=ismyturn;
    if(ismyturn)
    {
        roflochelik_status=0;
        buildings_status=0;
        current_action=1;
    }
    emit sendMapQML(ismyturn);
}
void mainrofl::endgame(int winner)
{
    game_started=false;
    int status=0;
    if(NuClient)
    {
        if(winner==NuClient->mynum)
        {
            status=2;
        }
        else
        {
            status=1;
        }
    }
    emit endGameQML(winner,status);
}

//TREES
void mainrofl::setTrees(int id)
{
    qDebug()<<"setTrees, id: " << id;
    if(id==1) // turn goes to first player
    {
        srand(QDateTime::currentDateTime().toMSecsSinceEpoch());
        for(int i=0;i<sx;i++)
        {
            for(int j=0;j<sy;j++)
            {
                if(maprel[i][j].tree==1)
                {
                    int prob = rand()%100;
                    if(prob<12)
                    {
                        int hexn = rand()%neighbour_hexes(maprel,i,j).size();
                        hex chex = neighbour_hexes(maprel,i,j)[hexn];
                        if(!chex.hatchery && !chex.is_capital && chex.roflochelik_lvl==0
                                && chex.tower==0 && chex.tree==0)
                        {
                            maprel[chex.xcoor][chex.ycoor].tree=1;
                        }
                    }
                }
                if(maprel[i][j].tree==2)
                {
                    int prob = rand()%100;
                    if(prob<25)
                    {
                        int hexn = rand()%neighbour_hexes(maprel,i,j).size();
                        hex chex = neighbour_hexes(maprel,i,j)[hexn];
                        if(!chex.hatchery && !chex.is_capital && chex.roflochelik_lvl==0
                                && chex.tower==0 && chex.tree==0 && chex.xcoor<sx && chex.ycoor<sy)
                        {
                            maprel[chex.xcoor][chex.ycoor].tree=2;
                        }
                    }
                }
            }
        }
    }
    else if(id==2) // game creation
    {
        srand(QDateTime::currentDateTime().toMSecsSinceEpoch());
        int numofpalms=rand()%(sx/8)+1;
        int numoftrees=rand()%(sx/5)+2;
        qDebug()<<numoftrees<< " <~> " <<numofpalms;
        for(int i=0;i<numoftrees;i++)
        {
            treegen:
            int xtoput=rand()%sx;
            int ytoput=rand()%sy;
            hex hextop=maprel[xtoput][ytoput];
            if(hextop.player==0 && hextop.tree==0 && hextop.is_standable)
            {
                maprel[xtoput][ytoput].tree=1;
            }
            else
            {
                goto treegen;
            }
        }
        for(int i=0;i<numofpalms;i++)
        {
            palmgen:
            int xtoput=rand()%sx;
            int ytoput=rand()%sy;
            hex hextop=maprel[xtoput][ytoput];
            if(hextop.player==0 && hextop.tree==0 && hextop.is_standable)
            {
                maprel[xtoput][ytoput].tree=2;
            }
            else
            {
                goto palmgen;
            }
        }
    }

}

int mainrofl::dist_to_center(int x,int y)
{
    return abs( sqrt( (x-sx/2)*(x-sx/2) + (y-sy/2)*(y-sy/2) ) );
}

void mainrofl::rmg(QVector< QVector < hex > > & map) // generation goes from center
{
    qDebug() << "RMG | started";
    QVector< QVector < hex > > tt = map;
    // fill map.is_standable w/ 0 and 1 (making 1 island)
    for(int i=0;i<sx;i++)
    {
        for(int j =0 ;j<sy;j++)
        {
            tt[i][j].is_standable=true;
            map[i][j].is_standable=false;
        }
    }
    qDebug() << "RMG | init 0 1";

    std::vector < hex > kveva;
    kveva.push_back(map[sx/2][sy/2]);
    map[sx/2][sy/2].is_standable=true;
    //kveva[0].is_standable=true;
    while(!kveva.empty())
    {
        qDebug()<<"RMG | new cycle (!kveva.empty())";
        hex curhex = kveva[0];
        std::vector <hex> sosedisi = neighbour_hexes(tt,curhex.xcoor,curhex.ycoor);
        qDebug() << "RMG | get "<< sosedisi.size() <<" sosedis for curhex: ";
        for(int i=0;i<sosedisi.size();i++)
        {
            qDebug() << "RMG | #" << i << " : " << sosedisi[i].xcoor << " , " << sosedisi[i].ycoor;
        }
        for(int i=sosedisi.size()-1;i>-1;i--)// delete all ov already filled hexes
        {   qDebug()<<"RMG | sosed?: " << sosedisi[i].xcoor << " , " << sosedisi[i].ycoor;
            if(map[sosedisi[i].xcoor][sosedisi[i].ycoor].is_standable)
            {
                qDebug()<<"RMG | bad sosed";
                sosedisi.erase(sosedisi.begin()+i);
                qDebug()<<"RMG | bad sosed deleted";
            }
        }
        qDebug()<<"RMG | erased neighbours.";
        for(int i=0;i<sosedisi.size();i++)
        {
            qDebug() << "RMG | sosed";
            // less distance to center - bigger chance that hex will be filled
            int prob = (( 3 + rand()%2 ) * sx/ dist_to_center(sosedisi[i].xcoor,sosedisi[i].ycoor) )+rand()%41;
            if(prob>=37)
            {
                qDebug() << "RMG | queue push: " <<dist_to_center(sosedisi[i].xcoor,sosedisi[i].ycoor) << " " << prob;
                qDebug() << "RMG | queue size: " << kveva.size();
                map[sosedisi[i].xcoor][sosedisi[i].ycoor].is_standable=true;
                kveva.push_back(sosedisi[i]);
            }
            else
            {
                qDebug() << "RMG | no push: "<<dist_to_center(sosedisi[i].xcoor,sosedisi[i].ycoor) << " "<< prob;
            }
        }
        qDebug() << "RMG | queue pop(not yet) . queue size: " << kveva.size();
        kveva.erase(kveva.begin());
        qDebug() << "RMG | queue pop(done) . queue size: " << kveva.size();
    }
    qDebug() << "RMG | finished";



    /*for(int i=0;i<sx;i++) // UNCOMMENT 4 FLAT MAP
    {
        for(int j =0 ;j<sy;j++)
        {
            map[i][j].is_standable=true;
        }
    }*/
}

// to do later
void mainrofl::doComputerTurn()
{
    qDebug()<<"Computer turn";
     nextplayer();
}

//
void mainrofl::changeTextures()
{
    if(textures == QString("h"))
    {
        q_red_1 = QPixmap(":/resources/or_red_unit_1.png");
        q_red_2 = QPixmap(":/resources/or_red_unit_2.png");
        q_red_3 = QPixmap(":/resources/or_red_unit_3.png");
        q_red_4 = QPixmap(":/resources/or_red_unit_4.png");
        q_blue_1 = QPixmap(":/resources/or_blue_unit_1.png");
        q_blue_2 = QPixmap(":/resources/or_blue_unit_2.png");
        q_blue_3 = QPixmap(":/resources/or_blue_unit_3.png");
        q_blue_4 = QPixmap(":/resources/or_blue_unit_4.png");
        q_tan_1 = QPixmap(":/resources/or_tan_unit_1.png");
        q_tan_2 = QPixmap(":/resources/or_tan_unit_2.png");
        q_tan_3 = QPixmap(":/resources/or_tan_unit_3.png");
        q_tan_4 = QPixmap(":/resources/or_tan_unit_4.png");
        q_green_1 = QPixmap(":/resources/or_green_unit_1.png");
        q_green_2 = QPixmap(":/resources/or_green_unit_2.png");
        q_green_3 = QPixmap(":/resources/or_green_unit_3.png");
        q_green_4 = QPixmap(":/resources/or_green_unit_4.png");
        q_orange_1 = QPixmap(":/resources/or_orange_unit_1.png");
        q_orange_2 = QPixmap(":/resources/or_orange_unit_2.png");
        q_orange_3 = QPixmap(":/resources/or_orange_unit_3.png");
        q_orange_4 = QPixmap(":/resources/or_orange_unit_4.png");
        q_purple_1 = QPixmap(":/resources/or_purple_unit_1.png");
        q_purple_2 = QPixmap(":/resources/or_purple_unit_2.png");
        q_purple_3 = QPixmap(":/resources/or_purple_unit_3.png");
        q_purple_4 = QPixmap(":/resources/or_purple_unit_4.png");
        q_teal_1 = QPixmap(":/resources/or_teal_unit_1.png");
        q_teal_2 = QPixmap(":/resources/or_teal_unit_2.png");
        q_teal_3 = QPixmap(":/resources/or_teal_unit_3.png");
        q_teal_4 = QPixmap(":/resources/or_teal_unit_4.png");
        q_pink_1 = QPixmap(":/resources/or_pink_unit_1.png");
        q_pink_2 = QPixmap(":/resources/or_pink_unit_2.png");
        q_pink_3 = QPixmap(":/resources/or_pink_unit_3.png");
        q_pink_4 = QPixmap(":/resources/or_pink_unit_4.png");
        textures = "or";
    }
    else
    {
        q_red_1 = QPixmap(":/resources/q_red_unit1.png");
        q_red_2 = QPixmap(":/resources/q_red_unit2.png");
        q_red_3 = QPixmap(":/resources/q_red_unit3.png");
        q_red_4 = QPixmap(":/resources/q_red_unit4.png");
        q_blue_1 = QPixmap(":/resources/q_blue_unit1.png");
        q_blue_2 = QPixmap(":/resources/q_blue_unit2.png");
        q_blue_3 = QPixmap(":/resources/q_blue_unit3.png");
        q_blue_4 = QPixmap(":/resources/q_blue_unit4.png");
        q_tan_1 = QPixmap(":/resources/q_tan_unit1.png");
        q_tan_2 = QPixmap(":/resources/q_tan_unit2.png");
        q_tan_3 = QPixmap(":/resources/q_tan_unit3.png");
        q_tan_4 = QPixmap(":/resources/q_tan_unit4.png");
        q_green_1 = QPixmap(":/resources/q_green_unit1.png");
        q_green_2 = QPixmap(":/resources/q_green_unit2.png");
        q_green_3 = QPixmap(":/resources/q_green_unit3.png");
        q_green_4 = QPixmap(":/resources/q_green_unit4.png");
        q_orange_1 = QPixmap(":/resources/q_orange_unit1.png");
        q_orange_2 = QPixmap(":/resources/q_orange_unit2.png");
        q_orange_3 = QPixmap(":/resources/q_orange_unit3.png");
        q_orange_4 = QPixmap(":/resources/q_orange_unit4.png");
        q_purple_1 = QPixmap(":/resources/q_purple_unit1.png");
        q_purple_2 = QPixmap(":/resources/q_purple_unit2.png");
        q_purple_3 = QPixmap(":/resources/q_purple_unit3.png");
        q_purple_4 = QPixmap(":/resources/q_purple_unit4.png");
        q_teal_1 = QPixmap(":/resources/q_teal_unit1.png");
        q_teal_2 = QPixmap(":/resources/q_teal_unit2.png");
        q_teal_3 = QPixmap(":/resources/q_teal_unit3.png");
        q_teal_4 = QPixmap(":/resources/q_teal_unit4.png");
        q_pink_1 = QPixmap(":/resources/q_pink_unit1.png");
        q_pink_2 = QPixmap(":/resources/q_pink_unit2.png");
        q_pink_3 = QPixmap(":/resources/q_pink_unit3.png");
        q_pink_4 = QPixmap(":/resources/q_pink_unit4.png");
        textures = "h";
    }

}


