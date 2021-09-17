import QtQuick 2.3
import QtQuick.Controls 1.2
import com.ics.rofl 0.8
import QtMultimedia 5.0
ApplicationWindow {

    MediaPlayer{
        id:music_player
        source: "qrc:resources/ryoy3.mp3"
        autoPlay: true
        loops:MediaPlayer.Infinite
    }

    Connections
    {
        target:myClass
        onSendOptionsQML:
        {
            console.log("opt",textures);
            if(textures=="or")
            {
                txtr="or";
            }
            if(!soundStat)
            {
                    sound_text.text="Off";
                    music_player.stop();
            }

        }


        onSendNumOfPlayersToQML:
        {
            console.log("Numofplayers changed!");
            client_numofp_text.text="";
            lobby_host_numofp_text.text="";
            client_numofp_text.text=myClass.numof_players_inlobby()+"/"+appwin.maxps +" players here in lobby";
            lobby_host_numofp_text.text=myClass.numof_players_inlobby()+"/"+appwin.numofplayers +" players here in lobby";
            if(appwin.numofplayers==num)
            {
                lobby_host_ready.enabled=true;
                lobby_host_ready.visible=true;
            }
            else
            {
                lobby_host_ready.visible=false;
                lobby_host_ready.enabled=false;
            }
            if(ishost)
            {
                myClass.sendMainInfo(appwin.cursize,appwin.numofplayers,appwin.numofprovinces);
            }
        }
        onSendYourNumToQML:
        {
            console.log("Hold your color!");
            client_your_color_text.text="";
            lobby_host_your_color_text.text="";
            client_your_color_text.text="You are " + myClass.equalColor(num);
            lobby_host_your_color_text.text="You are " + myClass.equalColor(num);
        }
        onSendMainInfoToQML:
        {
            console.log("Main game info!");
            console.log(players);
            appwin.maxps=players;
            client_numofp_text.text="";
            lobby_host_numofp_text.text="";
            client_numofp_text.text=myClass.numof_players_inlobby()+"/"+appwin.maxps +" players here in lobby";
            lobby_host_numofp_text.text=myClass.numof_players_inlobby()+"/"+appwin.numofplayers +" players here in lobby";
            lobby_host_provinces_text.text="Provinces: " + appwin.numofprovinces;
            client_provinces_text.text="Provinces: "+provinces;
            lobby_host_size_text.text="Size: "+appwin.cursize;
            client_size_text.text="Size: "+size;
        }
        onStartGameQML:
        {
            ifhotseat=false;
            music_player.source="qrc:resources/ryoy1.mp3";
            if(sound_text.text=="Off")
            {
                music_player.stop();
            }
            client_rectangle.visible=false;
            client_rectangle.enabled=false;
            game_screen.visible=true;
            game_screen.enabled=true;
            console.log("Letas start");
            myClass.redrawimg();
            //main_image.source=mnimgpth;
        }
        onSendMapQML:
        {
            console.log("Map!");
            game_screen_playernames_turn_text.text=myClass.currentplayer()+" turn";
            if(ismyturn)
            {
                music_player.source="qrc:resources/fastbeat.mp3";
                if(sound_text.text=="Off")
                {
                    music_player.stop();
                }
                urturn=true;
                game_screen_playernames_turn_text.text=myClass.currentplayer()+"(your) turn";
            }
            myClass.redrawimg();
        }
        onRedrawFinishedtoQML:
        {
            console.log("Redraw finished!");
            if(main_image.source==mnimgpth)
            {
                main_image.source=mnimg2pth;
            }
            else
            {
                main_image.source=mnimgpth;
            }
        }
        onEndGameQML:
        {
            console.log("Game ended!");
            endgame_screen_lose_or_win.font.pixelSize=dw_w()/8;
            game_screen.visible=false;
            game_screen.enabled=false;
            endgame_screen.visible=true;
            endgame_screen.enabled=true;
            if(status==0)
            {
                //music
                music_player.source="qrc:resources/ryoy2.mp3";
                if(sound_text.text=="Off")
                {
                    music_player.stop();
                }
                //
                endgame_screen.source="qrc:resources/win_screen1.png";
                endgame_screen_lose_or_win.text=myClass.equalColor(winner)+" won";
            }else
            if(status==1)
            {
                //music
                music_player.source="qrc:resources/wtf.mp3";
                if(sound_text.text=="Off")
                {
                    music_player.stop();
                }
                //
                endgame_screen.source="qrc:resources/lose_screen1.png";
                endgame_screen_lose_or_win.text="You lost, "+myClass.equalColor(winner)+" won";
                endgame_screen_lose_or_win.font.pixelSize=dw_w()/13;
            }else
            if(status==2)
            {
                endgame_screen_lose_or_win.text="You won";
                //music
                music_player.source="qrc:resources/revutastognu.mp3";
                if(sound_text.text=="Off")
                {
                    music_player.stop();
                }
                endgame_screen.source="qrc:resources/win_screen1.png";
                //
            }else
            {
                //err
                console.log("ERR");
            }
        }


    }



//multiplayerinfo
    property bool ishost: false
    property int maxps: 0
//---------------
    property string cursize: "small"
    property int numofplayers: 2
    property string numofprovinces: "default"
    property bool ifhotseat: false
    property string mnimgpth: "file:///" + myClass.apppth+"/curimage.png"
    property string mnimg2pth: "file:///" + myClass.apppth+"/curimage2.png"


    property bool tstbl1: true

    property string curplayername: "MasterBiter"

    /*
     * New Thing!
     */
    property bool is_it_click: false
    property bool long_enough: false


    //opt
    property string txtr: "q"

    //MP
    property bool urturn: false


    property color coltos: "#00ff7f"
    property color coltoh: "#000000"
    property color colton: "#faebd7"

    function dw_w(){
        return myClass.wdth1;
    }
    function dw_h(){
        return myClass.hght1;
    }
    Timer{
        id:timer
    }

    function delay(delayTime, cb) {
        timer.interval = delayTime;
        timer.repeat = false;
        timer.triggered.connect(cb);
        timer.start();
    }
    /*signal fgb()
    onFgb:
        {
            enjgm.text = "Enjoy game"
            goodfood.text = "Some good fucking food";
            meetlove_text.text = "Meet love ov ur live";

        }*/
    function fgb()
            {
                enjgm.text = "Enjoy game"
                goodfood.text = "Some good fucking food";
                meetlove_text.text = "Meet love ov ur live";

            }

    visible: true
    width: dw_w();
    height: dw_h();
    id: appwin
//---------------------------------------------------------------------------------------------------------------------------------------
// CREDITS SCREEN -----------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------

    Image {
        visible: false
        enabled: false
        id: credits_image
        source: "qrc:resources/credits.png"
        width: dw_w()
        height: dw_h()
        Button{
            id: fuckgoback_credits_button
            x: dw_w()*6/9;
            y: dw_h()*13/16;
            width: dw_w()*2/9;
            height: dw_w()*2/9;
            Image {
                width: dw_w()*2/9;
                height: dw_w()*2/9;
                id: credits_strelka
                source: "qrc:resources/strelka.png"
            }
            onClicked: {
                music_player.source="qrc:resources/ryoy3.mp3";
                if(sound_text.text=="Off")
                {
                    music_player.stop();
                }


                menu_rectangle.enabled = true;
                menu_rectangle.visible = true;
                credits_image.enabled = false;
                credits_image.visible = false;
            }
        }
    }
//---------------------------------------------------------------------------------------------------------------------------------------
// CLICKBAIT SCREEN ---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------
    Image {
        visible: false
        enabled: false
        id: clickbait_image
        source: "qrc:resources/clickbait_normres.png"
        width: dw_w()
        height: dw_h()
        Button{
            id: fuckgoback_clickbait_button
            x: dw_w()/18;
            y: dw_w()/18;
            width: dw_w()/9;
            height: dw_w()/9;
            Image {
                width: dw_w()/9;
                height: dw_w()/9;
                id: clickbait_strelka
                source: "qrc:resources/strelka.png"
            }
            onClicked: {
                menu_rectangle.enabled = true;
                menu_rectangle.visible = true;
                clickbait_image.enabled = false;
                clickbait_image.visible = false;
            }
        }
    }


//---------------------------------------------------------------------------------------------------------------------------------------
// MAIN MENU SCREEN ---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------
Rectangle{
    id: menu_rectangle
    visible: true
    color: "red"
    width: dw_w();
    height: dw_h();

//---------------------------------------------------------------------------------------------------------------------------------------
// (UN)WORKABLE HOTSEAT BUTTON ------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------

    Button{
     id: hotseat_button
     x: dw_w()/9;
     y: dw_h()*3/16;
     width: dw_w()*7/9;
     height: dw_h()*1/8;
     Text{
         font.pixelSize: dw_w()/5;
         id: hotseat_text
         text: qsTr("Hotseat")
         anchors.centerIn: parent
     }
     onClicked: {
         menu_rectangle.enabled = false;
         menu_rectangle.visible = false;
         create_game_rectangle.visible = true;
         create_game_rectangle.enabled = true;
         ifhotseat = true;
         cursize = "small";
         numofplayers = 2;
         numofprovinces = "default";
     }
    }
    Text
    {
        x:dw_w()/9
        y: dw_h()*5/16
        font.pixelSize: dw_w()/10;
        text: qsTr("Music:")
    }


    Button
    {
        id:sound_button
        x: dw_w()*7/18
        y: dw_h()*5/16
        width:dw_w()*2/9
        height:dw_h()/16
        Text
        {
            id:sound_text;
            text:"On";
            font.pixelSize: dw_w()/9;
            anchors.centerIn: parent
        }
        onClicked:
        {
            if(sound_text.text=="On")
            {
                sound_text.text="Off";
                music_player.stop();
            }
            else
            {
                sound_text.text="On";
                music_player.play();
            }
        }
    }



    Button{
     id: credits_button
     x: dw_w()/9;
     y: dw_h()*5/8;
     width: dw_w()*7/9;
     height: dw_h()*1/8;
     Text{
         font.pixelSize: dw_w()/5;
         id: credits_text
         text: qsTr("Credits")
         anchors.centerIn: parent
     }
     onClicked: {
         music_player.source="qrc:resources/cnuckling.mp3";
         if(sound_text.text=="Off")
         {
             music_player.stop();
         }
         menu_rectangle.enabled = false;
         menu_rectangle.visible = false;
         credits_image.enabled = true;
         credits_image.visible = true;
     }
    }

    Button{
     id: exit_button
     x: dw_w()/9;
     y: dw_h()*13/16;
     width: dw_w()*7/9;
     height: dw_h()*1/8;
     Text{
         font.pixelSize: dw_w()/5;
         id: exit_text
         text: qsTr("Exit")
         anchors.centerIn: parent
     }
     onClicked: Qt.quit();
    }

    Rectangle{
        id: multidevice_rect
        color: "red"
        x: dw_w()/9;
        y: dw_h()*6/16;
        width: dw_w()*7/9;
        height: dw_h()*1/16;
        Text{
            font.pixelSize: dw_w()/10;
            id: multidevice_rect_text
            text: qsTr("Multidevice")
            anchors.centerIn: parent
        }
    }

    Button{
     id: hotseat_c_button
     x: dw_w()/9;
     y: dw_h()*7/16;
     width: dw_w()*7/18;
     height: dw_h()*1/8;
     Text{
         font.pixelSize: dw_w()/5;
         id: hotseat_c_text
         text: qsTr("Host")
         anchors.centerIn: parent
     }
     onClicked:{
         create_game_rectangle.visible=true;
         create_game_rectangle.enabled=true;
         menu_rectangle.visible=false;
         menu_rectangle.enabled=false;
         cursize = "small";
         numofplayers = 2;
         numofprovinces = "default";
         ifhotseat = false;
     }
    }

    Button{
     id: join_button
     x: dw_w()/2;
     y: dw_h()*7/16;
     width: dw_w()*7/18;
     height: dw_h()*1/8;
     Text{
         font.pixelSize: dw_w()/5;
         id: join_text
         text: qsTr("Join")
         anchors.centerIn: parent
     }
     onClicked: {
         myClass.join(ip_text_input.text);
         client_rectangle.visible = true;
         client_rectangle.enabled = true;
         menu_rectangle.enabled = false;
         menu_rectangle.visible = false;
     }
    }
    TextInput{
        id:ip_text_input;
        x:dw_w()/2
        y:dw_h()*9/16
        width: dw_w()*7/18
        height: dw_h()/8
        text:"Insert ip to join"
        font.pixelSize: dw_w()/24
    }

    Image{
     id: menu_rofloyoy_text
     x: 0
     y:0
     width: dw_w()
     height: dw_w()*134/480
     source: "qrc:resources/rofloyoy_text_menu.png"
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------
// CREATE GAME SCREEN -------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------
Rectangle{
    id: create_game_rectangle
    visible: false
    enabled: false
    color: "yellow"
    width: dw_w();
    height: dw_h();

    Image{
     id: create_game_text
     x: 0
     y:0
     width: dw_w()
     height: dw_w()*10/48
     source: "qrc:resources/creategame_text.png"
    }

    Text{
     id: create_game_size_text
     x: dw_w()/18
     y: dw_h()*3/16
     font.pixelSize: dw_w()/10
     text: qsTr("Size")
    }

    Text{
     id: create_game_current_size_text
     x: dw_w()/9
     y: dw_h()/4
     font.pixelSize: dw_w()/10
     text: cursize
    }

    Button{
        id:create_game_curent_size_pp
        x: dw_w()*6/9
        y: dw_h()/4
        width: dw_w()/9
        height: dw_w()/9
        Text{text: qsTr("+")
        anchors.centerIn: parent
        font.pixelSize: dw_w()/9
        }
        onClicked: {if(cursize=="small"){cursize="medium";}else
        if(cursize=="medium"){cursize="big";}else
        if(cursize=="big"){cursize="huge";}
        }
    }
    Button{
        id:create_game_curent_size_mm
        x: dw_w()*7/9
        y: dw_h()/4
        width: dw_w()/9
        height: dw_w()/9
        Text{text: qsTr("-")
        anchors.centerIn: parent
        font.pixelSize: dw_w()/9
        }
        onClicked: {if(cursize=="medium"){cursize="small"; if(numofplayers>5){numofplayers=5;}}else
            if(cursize=="big"){cursize="medium";  if(numofplayers>8){numofplayers=8;}}else
            if(cursize=="huge"){cursize="big";}}
    }





    Button{
        id: fuckgoback_create_game_button
        x: dw_w()*6/9;
        y: dw_h()*13/16;
        width: dw_w()*2/9;
        height: dw_w()*2/9;
        Image {
            width: dw_w()*2/9;
            height: dw_w()*2/9;
            id: create_game_strelka
            source: "qrc:resources/strelka.png"
        }
        onClicked: {
            menu_rectangle.enabled = true;
            menu_rectangle.visible = true;
            create_game_rectangle.enabled = false;
            create_game_rectangle.visible = false;
        }
    }




    Text{
     id: create_game_num_of_p_text
     x: dw_w()/18
     y: dw_h()*6/16
     font.pixelSize: dw_w()/10
     text: qsTr("Players")
    }

    Text{
     id: create_game_current_num_of_p_text
     x: dw_w()/9
     y: dw_h()/16*7
     font.pixelSize: dw_w()/10
     text: numofplayers
    }

    Button{
        id:create_game_curent_num_of_p_pp
        x: dw_w()*6/9
        y: dw_h()*7/16
        width: dw_w()/9
        height: dw_w()/9
        Text{text: qsTr("+")
        anchors.centerIn: parent
        font.pixelSize: dw_w()/9
        }
        onClicked: {
         if(cursize=="small" && numofplayers < 5){numofplayers++;}
         else if(cursize=="medium" && numofplayers < 7){numofplayers++;}
         else if(numofplayers < 8 && (cursize=="huge" || cursize=="big")){numofplayers++;}
        }
    }
    Button{
        id:create_game_curent_num_of_p_mm
        x: dw_w()*7/9
        y: dw_h()*7/16
        width: dw_w()/9
        height: dw_w()/9
        Text{text: qsTr("-")
        anchors.centerIn: parent
        font.pixelSize: dw_w()/9
        }
        onClicked: {if(numofplayers>2){numofplayers--;}}
    }





    Text{
     id: create_game_num_of_prov_text
     x: dw_w()/18
     y: dw_h()*9/16
     font.pixelSize: dw_w()/10
     text: qsTr("Provinces")
    }

    Text{
     id: create_game_current_num_of_prov_text
     x: dw_w()/9
     y: dw_h()/16*10
     font.pixelSize: dw_w()/10
     text: numofprovinces
    }

    Button{
        id:create_game_curent_num_of_prov_pp
        x: dw_w()*6/9
        y: dw_h()*10/16
        width: dw_w()/9
        height: dw_w()/9
        Text{text: qsTr("+")
        anchors.centerIn: parent
        font.pixelSize: dw_w()/9
        }
        onClicked: {
         if(numofprovinces=="default"){numofprovinces="1";}else
         if(numofprovinces=="1"){numofprovinces="2";}else
         if(numofprovinces=="2"){numofprovinces="3";}
        }
    }
    Button{
        id:create_game_curent_num_of_prov_mm
        x: dw_w()*7/9
        y: dw_h()*10/16
        width: dw_w()/9
        height: dw_w()/9
        Text{text: qsTr("-")
        anchors.centerIn: parent
        font.pixelSize: dw_w()/9
        }
        onClicked: {
            if(numofprovinces=="1"){numofprovinces="default";}else
            if(numofprovinces=="2"){numofprovinces="1";}else
            if(numofprovinces=="3"){numofprovinces="2";}
        }
    }
    Button{
     id:   create_game_ready
     x: dw_w()/9
     y: dw_h()*13/16
     width: dw_w()/9*4
     height: dw_h()/8
     Text{text: qsTr("Ready")
     anchors.centerIn: parent
     font.pixelSize: dw_w()/9
     }
     onClicked: {

         if(!ifhotseat)
         {
         ishost=true;
         myClass.host(numofplayers);
         lobby_host_rectangle.enabled = true;
         lobby_host_rectangle.visible = true;
         create_game_rectangle.enabled = false;
         create_game_rectangle.visible = false;
         myClass.sendMainInfoToQMLf(0,0,0);
         }
         else
         {
           music_player.source="qrc:resources/fastbeat.mp3";
             if(sound_text.text=="Off")
             {
                 music_player.stop();
             }
           myClass.createmap(cursize,numofplayers,numofprovinces);
           create_game_rectangle.enabled = false;
           create_game_rectangle.visible = false;
           game_screen.visible=true;
           game_screen.enabled=true;
           //myClass.redrawimg(); // until 0.9.1 uncom
           //main_image.source = "qrc:resources/strelka.png";
           //main_image.source = mnimgpth;
           game_screen_playernames_turn_text.text="Red turn";
         }
         }
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------
// LOBBY HOST SCREEN --------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------

Rectangle{
    id: lobby_host_rectangle
    visible: false
    enabled: false
    color: "purple"
    width: dw_w();
    height: dw_h();
    Text
    {
        id:lobby_host_numofp_text
        text:myClass.numof_players_inlobby()+" players here in lobby";
        x:0
        y:dw_h()/3
        font.pixelSize: dw_w()/12
    }
    Text
    {
        id:lobby_host_your_color_text
        x:0
        y:dw_h()*5/12
        font.pixelSize: dw_w()/12
    }
    Text
    {
        id:lobby_host_provinces_text
        x:0
        y:dw_h()*6/12
        font.pixelSize: dw_w()/12
    }
    Text
    {
        id:lobby_host_size_text
        x:0
        y:dw_h()*7/12
        font.pixelSize: dw_w()/12
    }

    Button{
     id:   lobby_host_ready
     x: dw_w()/9
     y: dw_h()*13/16
     width: dw_w()/9*4
     height: dw_h()/8
     enabled: false
     Text{text: qsTr("Ready")
     anchors.centerIn: parent
     font.pixelSize: dw_w()/9
     }



     onClicked:
     {
         console.log("call onClicked");
         music_player.source="qrc:resources/fastbeat.mp3";
         if(sound_text.text=="Off")
         {
             music_player.stop();
         }
         urturn=true;
         myClass.start_mp_game(cursize,numofplayers,numofprovinces);
         lobby_host_rectangle.enabled = false;
         lobby_host_rectangle.visible = false;
         game_screen.visible=true;
         game_screen.enabled=true;
         //main_image.source = "qrc:resources/strelka.png";
         //main_image.source = mnimgpth;
         game_screen_playernames_turn_text.text="Red(your) turn";
     }
    }

    Button{
        id: fuckgoback_lobby_host_button
        x: dw_w()*6/9;
        y: dw_h()*13/16;
        width: dw_w()*2/9;
        height: dw_w()*2/9;
        Image {
            width: dw_w()*2/9;
            height: dw_w()*2/9;
            id: lobby_host_strelka
            source: "qrc:resources/strelka.png"
        }
        onClicked: {
            ishost=false;
            lobby_host_rectangle.enabled = false;
            lobby_host_rectangle.visible = false;
            create_game_rectangle.enabled = true;
            create_game_rectangle.visible = true;
            myClass.exit_from_serv();
        }
    }
    Image{
     id: lobby_host_rofloyoy_text
     x: 0
     y:0
     width: dw_w()
     height: dw_w()*134/480
     source: "qrc:resources/rofloyoy_text_lobby_host.png"
    }

}

//---------------------------------------------------------------------------------------------------------------------------------------
// CLIENT SCREEN ------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------

Rectangle{
    id: client_rectangle
    visible: false
    enabled: false
    color: "orange"
    width: dw_w();
    height: dw_h();
    Text
    {
        id:client_numofp_text
        text:myClass.numof_players_inlobby()+" players here in lobby";
        x:0
        y:dw_h()/3
        font.pixelSize: dw_w()/12
    }
    Text
    {
        id:client_your_color_text
        x:0
        y:dw_h()*5/12
        font.pixelSize: dw_w()/12
    }
    Text
    {
        id:client_provinces_text
        x:0
        y:dw_h()*6/12
        font.pixelSize: dw_w()/12
    }
    Text
    {
        id:client_size_text
        x:0
        y:dw_h()*7/12
        font.pixelSize: dw_w()/12
    }


    Button{
        id: fuckgoback_search_button
        x: dw_w()*6/9;
        y: dw_h()*13/16;
        width: dw_w()*2/9;
        height: dw_w()*2/9;
        Image {
            width: dw_w()*2/9;
            height: dw_w()*2/9;
            id: client_strelka
            source: "qrc:resources/strelka.png"
        }
        onClicked: {
            client_rectangle.visible = false;
            client_rectangle.enabled = false;
            menu_rectangle.enabled = true;
            menu_rectangle.visible = true;
            myClass.exit_from_serv();
        }
    }
    Image{
     id: client_rofloyoy_text
     x: 0
     y:0
     width: dw_w()
     height: dw_w()*134/480
     source: "qrc:resources/rofloyoy_text_join.png"
    }

}
//---------------------------------------------------------------------------------------------------------------------------------------
// GAME SCREEN --------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------

Rectangle{
    id: game_screen
    visible: false
    enabled: false
    width: dw_w();
    height: dw_h();

    Rectangle{
        id:game_screen_playernames_turn_text_r
        x:0
        y:0
        width: dw_w()*8/9
        height: dw_h()/18
        color: "darkCyan"
        Text{
            id:game_screen_playernames_turn_text
            text: myClass.currentplayer() + " turn"
            font.pixelSize: dw_w()/9
            anchors.centerIn: parent

        }
    }
    Rectangle{
        id:game_screen_province_stats
        x:0
        y:dw_h()/18
        width: dw_w()*8/9
        height: dw_h()/12
        color: "darkCyan"
        Text{
            text:myClass.moneycu()
            font.pixelSize: dw_w()/9
            color: "#ffd700"
            id:moneycutext
        Text{
            text:myClass.incomecu()
            font.pixelSize: dw_w()/9
            x:dw_w()*4/9
            color: "#daa520"
            id:incomcutext
        }
        }
    }

    Button{
        id:toingamemenubutton
        x:dw_w()*8/9
        y:0
        width: dw_w()/9
        height: dw_h()/8
        Image {
            id: toinggamemenuimage
            source: "qrc:resources/ingamemenu_but.png"
            width: dw_w()/9
            height: dw_h()/8
        }
        onClicked:
        {
        ingamemenu_screen.visible=true;
        ingamemenu_screen.enabled=true;
        game_screen.enabled=false;

        }

    }

    Button{
     id:scalepp_b
     x:0
     y:dw_h()*7/8 // 7/8 TBC 13/16
     width: dw_w()/5
     height: dw_h()*1/8 // 1/8 TBC 3/16
     onClicked: {myClass.scalepp(1);
         //main_image.source = "qrc:resources/strelka.png";
         //main_image.source = mnimgpth;
     }
     Text
     {
         x:dw_w()/14
         y:0
         text:"+"
         font.pixelSize: dw_w()/12
     }
    }
    Button{
     id:scalemm_b
     x:dw_w()/5
     y:dw_h()*7/8 // 7/8 TBC 13/16
     width: dw_w()/5
     height: dw_h()*1/8 // 1/8 TBC 3/16
     onClicked: {myClass.scalemm(1);
         //main_image.source = "qrc:resources/strelka.png";
         //main_image.source = mnimgpth;
     }
     Text
     {
         x:dw_w()/14
         y:0
         text:"-"
         font.pixelSize: dw_w()/12
     }
    }

    Button{
     id:cheloveki_b
     x:dw_w()*2/5   // 2/5
     y:dw_h()*7/8 // 7/8 TBC 13/16
     width: dw_w()/5
     height: dw_h()*1/8 // 1/8 TBC 3/16
     Text{ //  it must be image, not text
         id:cheloveki_text
         text:""
         visible:true
         enabled:true
         font.pixelSize: dw_w()/24
         //color: "#ffd700"
     }

     Image{
         id:cheloveki_img
         width: dw_w()/8  // 1/5 TBC
         height: dw_h()/14 // 1/8 TBC
         x:dw_w()/16  // 0 TBC
         y:0
     }
     onClicked: //  here. same as 649
     {
         hatki_img.source=" ";
         hatki_text.text=" ";
         cheloveki_text.text = " ";
         cheloveki_text.text = myClass.roflochelik_button_clicked() + "0$";
         if(cheloveki_text.text=="10$")
         {
             cheloveki_img.source= "qrc:resources/" + txtr +"_noone_unit_1.png";
         }else
         if(cheloveki_text.text=="20$")
         {
             cheloveki_img.source= "qrc:resources/" + txtr +"_noone_unit_2.png";
         }else
         if(cheloveki_text.text=="30$")
         {
             cheloveki_img.source= "qrc:resources/" + txtr +"_noone_unit_3.png";
         }else
         if(cheloveki_text.text=="40$")
         {
             cheloveki_img.source= "qrc:resources/" + txtr +"_noone_unit_4.png";
         }

     }
    }
    Button{
     id:hatki_b
     x:dw_w()*3/5  // 3/5
     y:dw_h()*7/8 // 7/8 TBC 13/16
     width: dw_w()/5
     height: dw_h()*1/8 // 1/8 TBC 3/16
     Text{ //  it must be image, not text
         id:hatki_text
         text:""
         visible:true
         enabled:true
         font.pixelSize: dw_w()/24
         //color: "#ffd700"
     }
     Image{
         id:hatki_img
         width: dw_w()/8 // 1/5 TBC
         height: dw_h()/14 // 1/8 TBC
         x:dw_w()/16 // 0 TBC
         y:0
     }
     onClicked:
     {
         cheloveki_text.text=" ";
         cheloveki_img.source=" ";
         hatki_text.text=" ";
         hatki_text.text=myClass.buildings_button_clicked();
         console.info(hatki_text.text);
         if(hatki_text.text=="15$")
         {
             //console.info("fisting is 15$");
             //hatki_img.source= " ";
             hatki_img.source= "qrc:resources/tower1.png";
         }else
         if(hatki_text.text=="35$")
         {
             //console.info("fisting is 35$");
             //hatki_img.source= " ";
             hatki_img.source= "qrc:resources/tower2.png";
         }else
         if(hatki_text.text=="")
         {
             //console.info("fisting is 0$");
             hatki_text.text=" ";
             //hatki_img.source= " ";
             hatki_img.source= "qrc:resources/hatchery.png";
         }else
         {
             //console.info("fisting is ?");
             //hatki_img.source= " ";
             hatki_img.source= "qrc:resources/hatchery.png";
         }
     }

    }
    Button{
     id:next_turn_b
     x:dw_w()*4/5
     y:dw_h()*7/8 // 7/8 TBC 13/16
     width: dw_w()/5
     height: dw_h()*1/8 // 1/8 TBC 3/16
     Text
     {
         text: "Next\nturn"
         font.pixelSize: dw_w()/24
         anchors.centerIn: parent
     }

     onClicked:
     {
         if(ifhotseat)
         {
         myClass.nextplayer();
         game_screen_playernames_turn_text.text = "zabr";
         game_screen_playernames_turn_text.text = myClass.currentplayer() + " turn";
         moneycutext.text=" ";
         //moneycutext.text=myClass.moneycu();
         incomcutext.text=" ";
         //incomcutext.text=myClass.incomecu();
         cheloveki_text.text=" ";
         cheloveki_img.source=" ";
         hatki_img.source=" ";
         hatki_text.text=" ";
         }
         else
         {
             if(urturn)
             {
                 music_player.source="qrc:resources/ryoy1.mp3";
                 if(sound_text.text=="Off")
                 {
                     music_player.stop();
                 }
                 myClass.nextplayer();
                 urturn=false;
                 game_screen_playernames_turn_text.text = "zabr";
                 game_screen_playernames_turn_text.text = myClass.currentplayer() + " turn";
             }
         }
     }
    }


    // MAIN GAME INTERFACE

    Rectangle{
        id:main_game_interface
        x:0
        y:dw_h()/8
        width:dw_w()
        height:dw_h()*3/4 // 3/4 TBC 11/16




        MouseArea{
            Image {
                id: main_image
                //source: mnimgpth
                width:dw_w()
                height:dw_h()*3/4 // 3/4 TBC 11/16
                onStatusChanged: console.log('Img status: ',main_image.status);
                x:0
                y:0
            }
            id: main_mousearea
            x:0
            y:0
            width:dw_w()
            height:dw_h()*3/4 // 3/4 TBC 11/16

            //0.9.1 fresh
            // WORKS ONLY ON COMPUTER
            onWheel: {
                console.log("Wheel" , wheel.angleDelta.x ," ", wheel.angleDelta.y);
                if(wheel.angleDelta.y>0)//WheelUp
                {
                        myClass.scalepp(wheel.angleDelta.y/120);
                }
                if(wheel.angleDelta.y<0)//WheelDown
                {
                        myClass.scalemm(-wheel.angleDelta.y/120);
                }
            }

            // DOESN'T WORK EVEN ON ANDROID

            /*MultiPointTouchArea
            {
                minimumTouchPoints: 2
                maximumTouchPoints: 2
                x:0
                y:0
                width:dw_w()
                height:dw_h()*3/4
                TouchPoint{id:touch_point1}
                TouchPoint{id:touch_point2}
                property int st_x1:0;
                property int en_x1:0;
                property int st_y1:0;
                property int en_y1:0;
                property int st_x2:0;
                property int en_x2:0;
                property int st_y2:0;
                property int en_y2:0;
                property int cen_1:0;
                property int cen_2:0;
                property int numo_scales:0;
                onPressed:
                {
                    numo_scales=0;
                    console.log("Pressed: ",touch_point1.startX," ",
                                touch_point1.startY," ",touch_point2.startX," ",touch_point2.startY);
                    st_x1=touch_point1.startX;
                    st_x2=touch_point2.startX;
                    st_y1=touch_point1.startY;
                    st_y2=touch_point2.startY;

                }
                onReleased:
                {
                    numo_scales=0;
                    console.log("Released: ",touch_point1.x," ",
                                touch_point1.y," ",touch_point2.x," ",touch_point2.y);
                    en_x1=touch_point1.x;
                    en_x2=touch_point2.x;
                    en_y1=touch_point1.y;
                    en_y2=touch_point2.y;

                    cen_1=(st_x1+st_x2)/2;
                    cen_2=(st_y1+en_y2)/2;


                    //do one scale change for each


                }
            }*/


            //


            onClicked: {
                console.log("onClicked trigerred!");console.log(mouseX);console.log(mouseY);
                if(!long_enough)
                {
                myClass.test1(mouseX,mouseY);
                }/*if(tstbl1){myClass.redrawimg();tstbl1=false;}*/
                long_enough=false;
                is_it_click=true;
            }
            //onPressAndHold: {myClass.test2(mouseX,mouseY);is_it_click=false;}//!!! TBC commented since 1603(0.7.1)
            onReleased: {
                pressAndHoldTimer.stop();       // TBC 1603(0.7.1) addition
                console.log("onReleased trigerred!");console.log(mouseX);console.log(mouseY);
                if(!is_it_click){myClass.test3(mouseX,mouseY);}//myClass.redrawimg();
                //main_image.source = "qrc:resources/strelka.png";
                //main_image.source = mnimgpth;
                moneycutext.text=" ";
                moneycutext.text=myClass.moneycu();
                incomcutext.text=" ";
                incomcutext.text=myClass.incomecu();
                cheloveki_text.text=" ";
                cheloveki_img.source=" ";
                hatki_img.source=" ";
                hatki_text.text=" ";
                is_it_click=true;
            }
            //onPressedChanged: {myClass.redrawimg();}


            // TBC 1603(0.7.1) addition

            Timer {
                    id:  pressAndHoldTimer
                    interval: parent.pressAndHoldDuration
                    running: false
                    repeat: false
                    onTriggered: {
                        parent.myPressAndHold();
                    }
                }
            property int pressAndHoldDuration: 150 // TBC!
                signal myPressAndHold()
                //anchors.fill: parent
                onPressed: {
                    pressAndHoldTimer.start();
                }

                onMyPressAndHold: {
                    long_enough=true;
                    console.log("onMyPressAndHold trigerred!");console.log(mouseX);console.log(mouseY);
                    myClass.test2(mouseX,mouseY);
                    is_it_click=false;
                }



        }

    }




}

//--------------------------------------------------------
// ENDGAME SCREEN
//--------------------------------------------------------

Image{
    id: endgame_screen
    x:0
    y:0
    source:"qrc:resources/win_screen1.png"
    visible: false
    enabled: false
    width: dw_w()
    height: dw_h()
    Button{
        id: endgame_screen_to_menu_but
        x: dw_w()*6/9;
        y: dw_h()*13/16;
        width: dw_w()*2/9;
        height: dw_w()*2/9;
        Image {
            width: dw_w()*2/9;
            height: dw_w()*2/9;
            id: endgame_screen_to_menu_but_strelka
            source: "qrc:resources/strelka.png"
        }
        onClicked: {
            music_player.source="qrc:resources/ryoy3.mp3";
            if(sound_text.text=="Off")
            {
                music_player.stop();
            }
            endgame_screen.visible = false;
            endgame_screen.enabled = false;
            menu_rectangle.enabled = true;
            menu_rectangle.visible = true;
            console.log("ok!")
            myClass.exit_from_serv();
        }
    }
    Text
    {
        id: endgame_screen_lose_or_win
        font.pixelSize: dw_w()/8
        color: "#00bfff"
        text: "You @%#&@!"
        x:dw_w()/14
        y:0
    }
}

//--------------------------------------------------------
// INGAME MENU
//--------------------------------------------------------
Image{
    id: ingamemenu_screen
    width: dw_w()
    height: dw_h()
    source: "qrc:resources/ingamemenu_pic.png"
    visible: false
    enabled: false
    opacity: 0.956


    Button{
        Text
        {
            text:"Resume game"
            font.pixelSize: dw_w()/36
            anchors.centerIn: parent
        }
        width: dw_w()*2/5
        height: dw_h()/24
        x: dw_w()/6
        y: dw_h()*10/64

        onClicked:
        {
            game_screen.enabled=true;
            ingamemenu_screen.visible=false;
            ingamemenu_screen.enabled=false;
        }
    }

    Button{
        Text
        {
            id:thxsir
            text:"..."
            font.pixelSize: dw_w()/36
            anchors.centerIn: parent
        }
        width: dw_w()*2/5
        height: dw_h()/24
        x: dw_w()/6
        y: dw_h()*13/64
        onClicked:
        {
            thxsir.text = "Thanks, sir!";
            delay(1100,function()
            {
                thxsir.text = "...";

            });
        }
    }

    Button{
        Text
        {
            id:enjgm
            text:"Enjoy game"
            font.pixelSize: dw_w()/36
            anchors.centerIn: parent
        }
        width: dw_w()*2/5
        height: dw_h()/24
        x: dw_w()/6
        y: dw_h()*16/64
        onClicked:
        {
            enjgm.text = "spasibo!";
            delay(750,function()
            {
                enjgm.text = "Enjoy game"

            });
        }
    }

    Button{
        Text
        {
            text:"Music(truly original)"
            font.pixelSize: dw_w()/36
            anchors.centerIn: parent
        }
        width: dw_w()*2/5
        height: dw_h()/24
        x: dw_w()/6
        y: dw_h()*19/64

        onClicked:
        {
            if(sound_text.text=="On")
            {
                sound_text.text="Off";
                music_player.stop();
            }
            else
            {
                sound_text.text="On";
                music_player.play();
            }
        }
    }

    Button{
        Text
        {
            text:"1 ukrainian hryvna"
            font.pixelSize: dw_w()/36
            anchors.centerIn: parent
        }
        width: dw_w()*2/5
        height: dw_h()/24
        x: dw_w()/6
        y: dw_h()*22/64
    }

    Button{
        Text
        {
            id:meetlove_text
            text:"Meet love ov ur live"
            font.pixelSize: dw_w()/36
            anchors.centerIn: parent
        }
        width: dw_w()*2/5
        height: dw_h()/24
        x: dw_w()/6
        y: dw_h()*25/64
        onClicked:
        {
            meetlove_text.text = "AAHAHHAHAHAH.Cute, but no.";
            delay(825,function()
            {
                meetlove_text.text = "Meet love ov ur live";

            });
        }
    }

    Button{
        Text
        {
            text:"Change textures"
            font.pixelSize: dw_w()/32
            anchors.centerIn: parent
        }
        width: dw_w()*2/5
        height: dw_h()/24
        x: dw_w()/6
        y: dw_h()*28/64
        onClicked:
        {
            myClass.changeTextures();
            if(txtr == "or")
            {
                txtr = "q";
            }
            else
            {
                txtr = "or";
            }
            myClass.redrawimg();
        }
    }


    Button{
        Text
        {
            id:perftext
            text:"Find someone, who'll laugh at your dumb jokes"
            font.pixelSize: dw_w()/52
            anchors.centerIn: parent
        }
        width: dw_w()*2/5
        height: dw_h()/24
        x: dw_w()/6
        y: dw_h()*31/64
        onClicked:
        {
            perftext.text = "Hello,salute!";
            delay(650,function()
            {
                perftext.text = "Find someone, who'll laugh at memes w/ u"

            });
        }
    }

    Button{
        Text
        {
            id:goodfood
            text:"Some good fucking food"
            font.pixelSize: dw_w()/36
            anchors.centerIn: parent
        }
        width: dw_w()*2/5
        height: dw_h()/24
        x: dw_w()/6
        y: dw_h()*34/64
        onClicked:
        {
            goodfood.text = "finally";
            delay(1000,function()
            {
                goodfood.text = "Some good fucking food";

            });
        }
    }

    Button{
        Text
        {
            text:"Save game(it doesn't work)"
            font.pixelSize: dw_w()/36
            anchors.centerIn: parent
        }
        width: dw_w()*2/5
        height: dw_h()/24
        x: dw_w()/6
        y: dw_h()*37/64
    }


    Button{
        Text
        {
            text:"Load game(it doesn't work)"
            font.pixelSize: dw_w()/36
            anchors.centerIn: parent
        }
        width: dw_w()*2/5
        height: dw_h()/24
        x: dw_w()/6
        y: dw_h()*40/64
    }




    Button{
        Text
        {
            text:"Chat(it doesn't work)"
            font.pixelSize: dw_w()/32
            anchors.centerIn: parent
        }
        width: dw_w()*2/5
        height: dw_h()/24
        x: dw_w()/6
        y: dw_h()*43/64
    }



    Button{
        Text
        {
            text:"Main menu"
            font.pixelSize: dw_w()/22
            anchors.centerIn: parent
        }

        width: dw_w()*2/5
        height: dw_h()/24
        x: dw_w()/6
        y: dw_h()*23/32


    onClicked:{
    game_screen.visible=false;
    ingamemenu_screen.visible=false;
    ingamemenu_screen.enabled=false;
    menu_rectangle.enabled = true;
    menu_rectangle.visible = true;

    music_player.source="qrc:resources/ryoy3.mp3";
    if(sound_text.text=="Off")
    {
        music_player.stop();
    }

    ishost=false; // TBC!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!IMP
    }

    }

}



//--------------------------------------------------------
// ADDITIONAL CREATE GAME SETTINGS
//--------------------------------------------------------


}


