#ifndef MAINROFL_H
#define MAINROFL_H

#include <QObject>
#include <QApplication>
#include <vector>
#include <QPixmap>
#include <QImage>
#include <QDir>
#include <queue>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <qmutex>

#include "multiplayer_server.h"
#include "multiplayer_client.h"

extern QApplication *app;
class mainrofl : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int wdth1 READ wdth1)
    Q_PROPERTY(int hght1 READ hght1)
    int _wdth1,_hght1;
    Q_PROPERTY(QString apppth READ apppth)

//    Q_PROPERTY(int** maprel READ maprel)

    /* IMPORTANT!!! (T1)
     * functions reformprovinces(); is called every time roflochelik moves from one klitynka to other
     * so it means that from 0 to 3 provinces can be changed:
     * (1) 1 -> 1
     * (2) 2,3 -> 1
     * (3) 1 -> 2,3
     * (?) 1,2,3 -> 0
     */
    // IMPORTANT!!! TBC <=> To Be Changed
    // IMPORTANT!!! TBA <=> To Be Added
    // IMPORTANT!!! TBAF <=> To Be Added First of all
    // is it OK? - smth doubtful
    // is it - smth doubtful
    // IMPORTANT!!! TBP <=> To Be Checked
public:

    static QMutex mu1;
    struct hex
    {
        int player;
        int tree;
        bool hatchery;
        int tower;
        bool is_standable;
        bool is_capital;
        int roflochelik_lvl;
        int xcoor;
        int ycoor;
        bool roflochelik_active;
    };
    struct province
    {
        int player;
        int curincome;
        int curmoney;
        std::vector < int > hexes_x;
        std::vector < int > hexes_y;

        province()
        {
            player = -1;
            curincome = 0;
            curmoney = 0;
        }
    };
    Q_INVOKABLE void test1(int x,int y);
    Q_INVOKABLE void test2(int x,int y);
    Q_INVOKABLE void test3(int x,int y);
    Q_INVOKABLE void nextplayer();
    Q_INVOKABLE QString currentplayer();
    Q_INVOKABLE void scalepp(int times);
    Q_INVOKABLE void scalemm(int times);
    Q_INVOKABLE QString moneycu();
    Q_INVOKABLE QString incomecu();


    //OPTIONS-------------
    QString textures;
    bool soundStat;
    void readOptions();


    //MP------------------
    bool game_started;
    Q_INVOKABLE void start_mp_game(QString size, int numofplayers, QString numofprovinces);
    /*Q_INVOKABLE*/ int sendMap();
    Q_INVOKABLE void host(int numofplayers);
    Q_INVOKABLE void join(QString ip);
    multiplayer_server *NuServ;
    multiplayer_client *NuClient;
    Q_INVOKABLE void exit_from_serv();
    Q_INVOKABLE int numof_players_inlobby();
    int my_playernum;


    bool is_it_my_turn;

    QString ipAddress;
    //--------------------

    Q_INVOKABLE int roflochelik_button_clicked();
    Q_INVOKABLE QString buildings_button_clicked();
    int roflochelik_status;
    int buildings_status;

    std::vector<hex> neighbour_hexes(QVector< QVector< hex > > & map,int curhexx,int curhexy);
    int oldSx;
    explicit mainrofl(QObject *parent = 0);
    void getscr_geometry(int & w, int & h);
    Q_INVOKABLE  void createmap(QString size, int numofplayers, QString numofprovinces);
    int sx,sy;
    void intimap(QVector  < QVector  < hex > > & map, int sx, int sy);
    void setTrees(int id);

    //rmg
    int dist_to_center(int x,int y);
    void rmg(QVector< QVector < hex > > & map);
    //

    int wdth1()
    {
        return _wdth1;
    }
    int hght1()
    {
        return _hght1;
    }
    QString apppth()
    {
        return _apppth;
    }


    QString _apppth;


    bool clck;
    int klitynka_is_even(int klitynka_y);
    Q_INVOKABLE void redrawimg();
    //MOUSE PRESS INFO
    int stx,sty,enx,eny,ctx,cty;
    void mouse_obrabotchik(int i);
    void findklitynka(int & klitynka_x,int & klitynka_y,int mouse_x,int mouse_y);

    int klitx,klity;
    // MAIN GAME INFO
    QVector< QVector <hex> > maprel;
    std::vector<province> allprov;
    QPixmap mainpixmap;
    QImage mainimage;
    int center_x;
    int center_y;
    int square_size;
    bool firstturn; // kostyl for economics in 1st turn

    province currentprovince;

    province emptyprovince;


    bool hexinprovince(province prov,hex h);

    bool isinanyprov(std::vector<province> provs, hex h);

    int numof_hatcheries_in_current_province();


    void reformprovinces(int player);
    province formprovince(hex centralhex,int player);
    bool notinkveva(std::vector<hex> kveva, hex element);
    bool notvisited(std::vector<hex> vec, hex element);
    province sortedprovince(province prov);
    struct coordinates
    {
        int x_c;
        int y_c;
    };


    int numofplayers_;
    int current_player; // No function to assign or change this number!!!
    // ACTIONS INFO
    bool is_unit_chosen;
    int prevc_x;
    int prevc_y;
    int current_action;

    bool hexcanbeattacked(int code);
    bool hexcanbereached();



    // ALL QPIXMAPS
    QPixmap q_blue_empty;
    QPixmap q_red_empty;
    QPixmap q_tan_empty;
    QPixmap q_green_empty;
    QPixmap q_orange_empty;
    QPixmap q_purple_empty;
    QPixmap q_teal_empty;
    QPixmap q_pink_empty;
    QPixmap q_neutral_empty;

    QPixmap q_blue_palace;
    QPixmap q_red_palace;
    QPixmap q_tan_palace;
    QPixmap q_green_palace;
    QPixmap q_orange_palace;
    QPixmap q_purple_palace;
    QPixmap q_teal_palace;
    QPixmap q_pink_palace;

    QPixmap q_blue_1;
    QPixmap q_red_1;
    QPixmap q_tan_1;
    QPixmap q_green_1;
    QPixmap q_orange_1;
    QPixmap q_purple_1;
    QPixmap q_teal_1;
    QPixmap q_pink_1;

    QPixmap q_blue_2;
    QPixmap q_red_2;
    QPixmap q_tan_2;
    QPixmap q_green_2;
    QPixmap q_orange_2;
    QPixmap q_purple_2;
    QPixmap q_teal_2;
    QPixmap q_pink_2;

    QPixmap q_blue_3;
    QPixmap q_red_3;
    QPixmap q_tan_3;
    QPixmap q_green_3;
    QPixmap q_orange_3;
    QPixmap q_purple_3;
    QPixmap q_teal_3;
    QPixmap q_pink_3;

    QPixmap q_blue_4;
    QPixmap q_red_4;
    QPixmap q_tan_4;
    QPixmap q_green_4;
    QPixmap q_orange_4;
    QPixmap q_purple_4;
    QPixmap q_teal_4;
    QPixmap q_pink_4;

    QPixmap q_blue_t1;
    QPixmap q_red_t1;
    QPixmap q_tan_t1;
    QPixmap q_green_t1;
    QPixmap q_orange_t1;
    QPixmap q_purple_t1;
    QPixmap q_teal_t1;
    QPixmap q_pink_t1;

    QPixmap q_blue_t2;
    QPixmap q_red_t2;
    QPixmap q_tan_t2;
    QPixmap q_green_t2;
    QPixmap q_orange_t2;
    QPixmap q_purple_t2;
    QPixmap q_teal_t2;
    QPixmap q_pink_t2;

    QPixmap q_blue_h;
    QPixmap q_red_h;
    QPixmap q_tan_h;
    QPixmap q_green_h;
    QPixmap q_orange_h;
    QPixmap q_purple_h;
    QPixmap q_teal_h;
    QPixmap q_pink_h;

    QPixmap q_blue_tree;
    QPixmap q_red_tree;
    QPixmap q_tan_tree;
    QPixmap q_green_tree;
    QPixmap q_orange_tree;
    QPixmap q_purple_tree;
    QPixmap q_teal_tree;
    QPixmap q_pink_tree;
    QPixmap q_neutral_tree;

    QPixmap q_blue_palm;
    QPixmap q_red_palm;
    QPixmap q_tan_palm;
    QPixmap q_green_palm;
    QPixmap q_orange_palm;
    QPixmap q_purple_palm;
    QPixmap q_teal_palm;
    QPixmap q_pink_palm;
    QPixmap q_neutral_palm;


    QPixmap kvadrat_malevicha;
    QPixmap or_vodichka;


    QPixmap background1;

    //---------------------
    //MUSIC----------------
    QMediaPlayer * m_player;
    QMediaPlaylist * m_playlist;


    //---------------------
    //opt

    Q_INVOKABLE void changeTextures();



    //


    Q_INVOKABLE QString equalColor(int num)
    {
        if(num==1)
        {
            return "Red";
        }else
        if(num==2)
        {
            return "Blue";
        }else
        if(num==3)
        {
            return "Tan";
        }else
        if(num==4)
        {
            return "Green";
        }else
        if(num==5)
        {
            return "Orange";
        }else
        if(num==6)
        {
            return "Purple";
        }else
        if(num==7)
        {
            return "Teal";
        }else
        if(num==8)
        {
            return "Pink";
        }else
        {
            return "@%#!@";
        }
    }
    Q_INVOKABLE void sendMainInfo(QString size, int numofplayers, QString numofprovinces);

    // to do (computer)
    std::vector <int> computer_players;
    void doComputerTurn();
    //


/*    int** maprel()
    {
        return _maprel;
    }*/

    void endgame(int winner);

    void sendNumOfPlayersToQMLf(int num);
    void sendYourNumToQMLf(int num);
    void startGameQMLf();
    void sendMapQMLf(bool ismyturn);
    Q_INVOKABLE void sendMainInfoToQMLf(QString size,int players,QString provinces);


    void sendOptionsQMLf(QString textures,bool soundStat)
    {
        qDebug()<< "sendOptionsQMLf";
        emit sendOptionsQML(textures,soundStat);
        qDebug()<< "sentOptionsQMLf";
    }

signals:

    void sendOptionsQML(QString textures,bool soundStat);

    void sendNumOfPlayersToQML(int num);
    void sendYourNumToQML(int num);
    void sendMainInfoToQML(QString size,int players,QString provinces);
    void startGameQML();
    void sendMapQML(bool ismyturn);
    void redrawFinishedtoQML();
    void endGameQML(int winner,int status);// status = { 0<=>hotseat ; 1<=>MP lost ; 2<=>MP won }
public slots:

};

#endif // MAINROFL_H
