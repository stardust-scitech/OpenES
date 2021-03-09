/**
*http.h
**/
#ifndef _USER_PAGE_H
#define _USER_PAGE_H

uint8_t http_head[] = {
		"HTTP/1.0 200 OK\r\n"\
		"Content-Type: text/html;charset=gbk\r\n"\
		"Cache-Control: private\r\n"\
		"Connection: close\r\n"\
		"\r\n"\
		"<!DOCTYPE html>"\
		"<html>"	\
		"<head>"	\
		"<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">"	\
		"<meta name=\"viewport\" content=\"width=device-width,height=device-height,inital-scale=1.0,maximum-scale=1.0,user-scalable=no;\">"	\
		"<meta name=\"renderer\" content=\"webkit|ie-comp|ie-stand\">"	\
		"<meta name=\"apple-mobile-web-app-capable\" content=\"yes\">"	\
		"<meta name=\"apple-mobile-web-app-status-bar-style\" content=\"black\">"	\
		"<meta name=\"format-detection\" content=\"telephone=no\">"	\
		"<meta content=\"email=no\" name=\"format-detection\" />"	\
		"<title></title>"	\
		"</head>"	\
		"<style type=\"text/css\">"	\
		"body{overflow-x:hidden;}"	\
		"img{width: 100%;display: block;}"	\
		"</style>"	\
		"<body>"	\
		"<a>点击按钮</a>"	\
		"<form action=\"\" method=\"post\">"	\
		"<button name=\"btn\" value=\"down\">下载</button>"	\
		"</form>"	\
		"</body>"	\
		"</html>"	\
		""
		};

uint8_t http_data[] = {
		"HTTP/1.1 200 OK\r\n"\
		"Content-Type:text/plain;charset=UTF-8\r\n"\
		"Content-Disposition:attachment;filename=1.txt\r\n"\
		"\r\n"\
		"get data"\
		"\r\n"
};

uint8_t Console_html[] = {
		"HTTP/1.0 200 OK\r\n"\
		"Content-Type: text/html;charset=UTF-8\r\n"\
		"Cache-Control: no-store\r\n"\
		"Connection: close\r\n"\
		"\r\n"\
		"<!DOCTYPE html>"
		"<html>"
		"    <head>"
		"        <link rel='icon' href='data:;base64,='>"
		"        <meta name='viewport' content='width=device-width, initial-scale=1.0'>"
		"        <title>星尘科技 智创未来</title>"
		"    </head>"
		"    <style type='text/css'>"
		"        html {"
		"            box-sizing: border-box;"
		"            font: 18px PT Mono;"
		"        }"
		""
		"        *, *::before, *::after {"
		"            box-sizing: inherit;"
		"        }"
		""
		"        body {"
		"            background-color: #FFEC8B;"
		"            display: flex;"
		"            align-items: center;"
		"            justify-content: center;"
		"            flex-direction: column;"
		"            height: 100vh;"
		"            color: #ffec8b;"
		"        }"
		""
		"        .box {"
		"            min-width: 150px;"
		"            display: block;"
		"            height: 50px;"
		"            position: relative;"
		"            border-radius: 5px;"
		"            background: linear-gradient(to right, #ffb466 35%, #ffec8b 100%);"
		"            margin-bottom: 40px;"
		"            padding: 15px 25px 0 40px;"
		"            color: darkslategray;"
		"            box-shadow: 1px 2px 1px -1px #777;"
		"            transition: background 200ms ease-in-out;"
		"            text-align: center;"
		"        }"
		""
		"        .box a {"
		"            color: #6d6d6d;"
		"            text-decoration: none;"
		"            font-weight: bold;"
		"        }"
		""
		"        .shadow {"
		"            position: relative;"
		"        }"
		""
		"        .shadow:before {"
		"            z-index: -1;"
		"            position: absolute;"
		"            bottom: 13px;"
		"            right: 7px;"
		"            width: 75%;"
		"            top: 0;"
		"            box-shadow: 0 15px 10px #777;"
		"            -webkit-transform: rotate(4deg);"
		"            transform: rotate(4deg);"
		"            transition: all 150ms ease-in-out;"
		"        }"
		""
		"        .box:hover {"
		"            background: linear-gradient(to right, #FF6633 0%, #FF6600 100%);"
		"        }"
		""
		"        .shadow:hover::before {"
		"            -webkit-transform: rotate(0deg);"
		"            transform: rotate(0deg);"
		"            bottom: 20px;"
		"            z-index: -10;"
		"        }"
		""
		"        .circle {"
		"            position: absolute;"
		"            top: 5px;"
		"            left: 5px;"
		"            border-radius: 50%;"
		"            box-shadow: inset 1px 1px 1px 0px rgba(0, 0, 0, 0.5), inset 0 0 0 25px antiquewhite;"
		"            width: 20px;"
		"            height: 20px;"
		"            display: inline-block;"
		"            text-align: right;"
		"            padding: 0 20px 0 0;"
		"        }"
		""
		"        input[type='checkbox'] {"
		"            -webkit-appearance: none;"
		"            /* Remove Safari default */"
		"            outline: none;"
		"            width: 120px;"
		"            height: 40px;"
		"            position: relative;"
		"            border-radius: 6px;"
		"            background-color: #000;"
		"            -webkit-background-clip: padding-box;"
		"            border: 0;"
		"            border-bottom: 1px solid transparent;"
		"            -webkit-perspective: 200;"
		"        }"
		""
		"        input[type='checkbox']:before, input[type='checkbox']:after {"
		"            font: bold 22px/32px sans-serif;"
		"            text-align: center;"
		"            position: absolute;"
		"            z-index: 1;"
		"            width: 56px;"
		"            height: 30px;"
		"            top: 4px;"
		"            border: 0;"
		"            border-top: 1px solid rgba(255,255,255,0.15);"
		"        }"
		""
		"        input[type='checkbox']:before {"
		"            content: attr(data-icon1);"
		"            left: 4px;"
		"            border-radius: 3px 0 0 3px;"
		"        }"
		""
		"        input[type='checkbox']:after {"
		"            content: attr(data-icon2);"
		"            right: 4px;"
		"            border-radius: 0 3px 3px 0;"
		"        }"
		""
		"        input[type='checkbox']:after {"
		"            background-image: -webkit-gradient(linear, 70% top, 40% bottom, from( hsl(0,0%,17%) ),to( hsl(0,0%,12%) ) );"
		"            border-right: 1px solid transparent;"
		"            -webkit-border-image: -webkit-gradient(linear, left bottom, left top, "
		"                from(rgba(255,255,255,0)), "
		"                color-stop(.2,rgba(255,255,255,0)), "
		"                color-stop(.4,rgba(255,255,255,.5)), "
		"                to(rgba(255,255,255,.05)) )10% 100%;"
		"            -webkit-box-shadow: rgba(0,0,0,.6) 8px 3px 10px;"
		"            -webkit-transform: rotateY(-30deg) scaleX(.9) scaleY(1.1) translateX(-8px);"
		"        }"
		""
		"        input[type='checkbox']:checked {"
		"            -webkit-border-image: -webkit-gradient(linear, 0% 0%, 100% 0%, "
		"                from(rgba(255,255,255,0)),"
		"                 to(rgba(255,255,255,0)), "
		"                 color-stop(.1,rgba(255,255,255,.05)), "
		"                 color-stop(.3,rgba(5,137,200,0.4)), "
		"                 color-stop(.45,rgba(255,255,255,.05)), "
		"                 color-stop(.9,rgba(255,255,255,.1)) )100% 100%;"
		"            background-image: -webkit-gradient( linear, left top, right top, color-stop( 0, hsl(0,0%,0%) ), "
		"                color-stop( 0.14, hsl(0,0%,50%) ), "
		"                color-stop( 0.15, hsl(0,0%,0%) ) );"
		"            -webkit-box-shadow: inset #000 7px 0 1px, inset #000 0 -5px 10px, inset #000 0 3px 3px;"
		"        }"
		""
		"        input[type='checkbox']:checked:before {"
		"            background-image: -webkit-gradient( linear, 30% top, 60% bottom, from( hsl(0,0%,17%) ),to( hsl(0,0%,12%) ) );"
		"            border-left: 1px solid transparent;"
		"            -webkit-border-image: -webkit-gradient(linear, left bottom, left top, from(rgba(255,255,255,0)), "
		"                color-stop(.2,rgba(255,255,255,0)), "
		"                color-stop(.4,rgba(255,255,255,.5)), "
		"                to(rgba(255,255,255,.05)) )10% 100%;"
		"            -webkit-box-shadow: rgba(0,0,0,.6) -8px 3px 10px;"
		"            -webkit-transform: rotateY(30deg) scaleX(.9) scaleY(1.1) translateX(8px);"
		"        }"
		""
		"        input[type='checkbox']:before, input[type='checkbox']:checked:after {"
		"            color: hsl(200,100%,50%);"
		"            text-shadow: rgba(0,0,0,.5) 0 1px 1px, #0589c8 0 0 10px;"
		"            -webkit-transform: none;"
		"            background-image: -webkit-gradient( linear, left top, left bottom, from( hsl(0,0%,20%) ), to( hsl(0,0%,15%) ) );"
		"            -webkit-border-image: none;"
		"            -webkit-box-shadow: none;"
		"            z-index: 2;"
		"        }"
		""
		"        input[type='checkbox']:after, input[type='checkbox']:checked:before {"
		"            color: #000;"
		"            text-shadow: rgba(255,255,255,.1) 0 -1px 0;"
		"            -webkit-box-reflect: none;"
		"            z-index: 1;"
		"        }"
		""
		"        input[type='checkbox']:hover {"
		"            cursor: pointer;"
		"        }"
		""
		"        input[type='checkbox']:hover:before {"
		"            background-image: -webkit-gradient( linear, left top, left bottom, from( hsl(0,0%,19%) ), to( hsl(0,0%,15%) ) );"
		"        }"
		""
		"        input[type='checkbox']:hover:after {"
		"            background-image: -webkit-gradient(linear, 70% top, 40% bottom, from( hsl(0,0%,16%) ),to( hsl(0,0%,11%) ) );"
		"        }"
		""
		"        input[type='checkbox']:checked:hover:before {"
		"            background-image: -webkit-gradient( linear, 30% top, 60% bottom, from( hsl(0,0%,16%) ),to( hsl(0,0%,12%) ) );"
		"        }"
		""
		"        input[type='checkbox']:checked:hover:after {"
		"            background-image: -webkit-gradient( linear, left top, left bottom, from( hsl(0,0%,19%) ), to( hsl(0,0%,15%) ) );"
		"        }"
		""
		"        .menu {"
		"            position: fixed;"
		"            z-index: 1;"
		"            top: 0;"
		"            width: 100%;"
		"            background: #868686;"
		"            display: flex;"
		"            height: 6%;"
		"        }"
		""
		"        .menu .center {"
		"            width: 100%;"
		"        }"
		""
		"        .menu .ul-list {"
		"            display: flex;"
		"            list-style: none;"
		"            padding: 0px;"
		"            margin-top: 0px;"
		"            height: 100%;"
		"        }"
		""
		"        .menu .ul-list > li {"
		"            flex: 1;"
		"            border-right: 1px solid #868686;"
		"            position: relative;"
		"        }"
		""
		"        .menu .ul-list > li > a {"
		"            height: 100%;"
		"            display: flex;"
		"            align-items: center;"
		"            justify-content: center;"
		"            text-decoration: none;"
		"            color: #ffffff;"
		"            background: #736e6e;"
		"        }"
		""
		"        .menu .ul-list > li:hover .ol-list {"
		"            display: block;"
		"        }"
		""
		"        .menu .ol-list {"
		"            display: none;"
		"            background: #736e6e;"
		"            padding: 0px;"
		"            list-style: none;"
		"            border-bottom-right-radius: 0.5em;"
		"            border-bottom-left-radius: 0.5em;"
		"            word-break: keep-all;"
		"        }"
		""
		"        .menu .ol-list > li > a {"
		"            text-decoration: none;"
		"            color: #fff;"
		"            height: 35px;"
		"            display: flex;"
		"            align-items: center;"
		"            border-top: 1px solid #868686;"
		"            justify-content: center;"
		"        }"
		""
		"        .menu .ol-list > li >font {"
		"            color: #fff;"
		"            height: 35px;"
		"            display: flex;"
		"            align-items: center;"
		"            border-top: 1px solid #868686;"
		"            justify-content: center;"
		"        }"
		""
		"        .menu .ol-list > li >div {"
		"            display: flex;"
		"            align-items: center;"
		"            justify-content: center;"
		"        }"
		""
		"        .menu .ol-list > li > a:hover {"
		"            background: black;"
		"            border-radius: 0.5em;"
		"        }"
		"    </style>"
		"    <body>"
		"        <div class='menu'>"
		"            <div class='center'>"
		"                <ul class='ul-list'>"
		"                    <li>"
		"                        <a href='#'>功能开关</a>"
		"                        <ol class='ol-list'>"
		"                            <li>"
		"                                <font>安全锁开关</font>"
		"                            <li>"
		"                            <li>"
		"                                <div>"
		"                                    <form action='Console.html' method='post' id='LockForm' target='nm_iframe'>"
		"                                        <input type='checkbox' data-icon1='关' data-icon2='开' name='lock' oninput=\"add('LockForm','lock')\" id='lock'/>"
		"                                        <input type='hidden' name='button' value='1'>"
		"                                        <input type='submit' name='argsubmit' style='display:none'/>"
		"                                    </form>"
		"                                </div>"
		"                            <li>"
		"                            <li>"
		"                                <font>箱内照明灯开关</font>"
		"                            <li>"
		"                            <li>"
		"                                <div>"
		"                                    <form action='Console.html' method='post' id='LightForm' target='nm_iframe'>"
		"                                        <input type='checkbox' data-icon1='关' data-icon2='开' name='light' oninput=\"add('LightForm','light')\" id='light'/>"
		"                                        <input type='hidden' name='button' value='2'>"
		"                                        <input type='submit' name='argsubmit' style='display:none'/>"
		"                                    </form>"
		"                                </div>"
		"                            <li>"
		"                        </ol>"
		"                    </li>"
		"                    <li>"
		"                        <a href='#'>设置</a>"
		"                        <ol class='ol-list'>"
		"                            <li>"
		"                                <a href='Login.html'>重设登录密码</a>"
		"                            </li>"
		"                            <li>"
		"                                <a href='Connect.html'>重设连接路由器</a>"
		"                            </li>"
        "							 <li>"
		"								 <a href='Check.html'>重设设备密码</a>"
        "							 </li>"
		"                        </ol>"
		"                    </li>"
		"                    <li>"
		"                        <a href='#'>NC</a>"
		"                    </li>"
		"                    <li>"
		"                        <a href='#'>NC</a>"
		"                    </li>"
		"                </ul>"
		"            </div>"
		"        </div>"
		"        <div>"
		"            <div class='box shadow'>"
		"                <a href='' id='temperature'>箱内温度:00℃</a>"
		"                <div class='circle'></div>"
		"            </div>"
		"            <div class='box shadow'>"
		"                <a href='' id='humidity'>箱内湿度:00%RH</a>"
		"                <div class='circle'></div>"
		"            </div>"
		"            <div class='box shadow'>"
		"                <a href='' id='carbon'>箱内二氧化碳浓度:000ppm</a>"
		"                <div class='circle'></div>"
		"            </div>"
		"            <div class='box shadow'>"
		"                <a href='' id='collision'>碰撞检测记录</a>"
		"                <div class='circle'></div>"
		"            </div>"
		"        </div>"
		"        <iframe id='id_iframe' name='nm_iframe' style='display:none;'></iframe>"
		"        <script type='text/javascript'>"
		"            function add(key, value) {"
		"                document.getElementById(key).submit();"
		"            }"
		"        </script>"
		"        <script type='text/javascript'>"
		"            var number = 0;"
		"            get('temperature');"
		"            get('humidity');"
		"            get('carbon');"
		"            get('collision');"
		"            setInterval('start()', 3000);"
		"            function start() {"
		"                get('temperature');"
		"                get('humidity');"
		"                get('carbon');"
		"                get('collision');"
		"            }"
		"            function get(value) {"
		"                var xmlHttp;"
		"                if (window.ActiveXObject) {"
		"                    xmlHttp = new ActiveXObject('Microsoft.XMLHTTP');"
		"                } else if (window.XMLHttpRequest) {"
		"                    xmlHttp = new XMLHttpRequest();"
		"                }"
		"                var url = 'CallBack.php';"
		"                xmlHttp.open('POST', url, true);"
		"                xmlHttp.onreadystatechange = function() {"
		"                    if (xmlHttp.readyState == 4 && xmlHttp.status == 200)"
		"                        document.getElementById(value).innerText = xmlHttp.responseText;"
		"                }"
		"                ;"
		"                xmlHttp.send(value);"
		"            }"
		"        </script>"
		"    </body>"
		"</html>"
};

uint8_t Login_html[] = {
		"HTTP/1.0 200 OK\r\n"
		"\r\n"
		"<!DOCTYPE html>"
		"<html>"
		"    <head>"
		"        <link rel='icon' href='data:;base64,='>"
		"        <meta charset='UTF-8'>"
		"        <meta name='viewport' content='width=device-width, initial-scale=0.6'>"
		"        <title>星尘科技 智创未来</title>"
		"        <style type='text/css'>"
		"            body {"
		"                background-color: #FFEC8B;"
		"            }"
		""
		"            #login {"
		"                background-color: #fff;"
		"                height: 240px;"
		"                width: 400px;"
		"                margin: -150px 0 0 -230px;"
		"                padding: 30px;"
		"                position: absolute;"
		"                top: 50%;"
		"                left: 50%;"
		"                z-index: 0;"
		"                -moz-border-radius: 3px;"
		"                -webkit-border-radius: 3px;"
		"                border-radius: 3px;"
		"                -webkit-box-shadow: 0 0 2px rgba(0, 0, 0, 0.2), 0 1px 1px rgba(0, 0, 0, .2), 0 3px 0 #fff, 0 4px 0 rgba(0, 0, 0, .2), 0 6px 0 #fff, 0 7px 0 rgba(0, 0, 0, .2);"
		"                -moz-box-shadow: 0 0 2px rgba(0, 0, 0, 0.2), 1px 1px 0 rgba(0, 0, 0, .1), 3px 3px 0 rgba(255, 255, 255, 1), 4px 4px 0 rgba(0, 0, 0, .1), 6px 6px 0 rgba(255, 255, 255, 1), 7px 7px 0 rgba(0, 0, 0, .1);"
		"                box-shadow: 0 0 2px rgba(0, 0, 0, 0.2), 0 1px 1px rgba(0, 0, 0, .2), 0 3px 0 #fff, 0 4px 0 rgba(0, 0, 0, .2), 0 6px 0 #fff, 0 7px 0 rgba(0, 0, 0, .2);"
		"            }"
		""
		"            #login:before {"
		"                content: '';"
		"                position: absolute;"
		"                z-index: -1;"
		"                border: 1px dashed #ccc;"
		"                top: 5px;"
		"                bottom: 5px;"
		"                left: 5px;"
		"                right: 5px;"
		"                -moz-box-shadow: 0 0 0 1px #fff;"
		"                -webkit-box-shadow: 0 0 0 1px #fff;"
		"                box-shadow: 0 0 0 1px #fff;"
		"            }"
		""
		"            h1 {"
		"                text-shadow: 0 1px 0 rgba(255, 255, 255, .7), 0px 2px 0 rgba(0, 0, 0, .5);"
		"                text-transform: uppercase;"
		"                text-align: center;"
		"                color: #666;"
		"                margin: 0 0 30px 0;"
		"                letter-spacing: 4px;"
		"                font: normal 26px/1 Verdana, Helvetica;"
		"                position: relative;"
		"            }"
		""
		"            fieldset {"
		"                border: 0;"
		"                padding: 0;"
		"                margin: 0;"
		"            }"
		""
		"            #inputs input {"
		"                padding: 15px 15px 15px 30px;"
		"                margin: 0 0 10px 0;"
		"                width: 353px;"
		"                /* 353 + 2 + 45 = 400 */"
		"                border: 1px solid #ccc;"
		"                -moz-border-radius: 5px;"
		"                -webkit-border-radius: 5px;"
		"                border-radius: 5px;"
		"                -moz-box-shadow: 0 1px 1px #ccc inset, 0 1px 0 #fff;"
		"                -webkit-box-shadow: 0 1px 1px #ccc inset, 0 1px 0 #fff;"
		"                box-shadow: 0 1px 1px #ccc inset, 0 1px 0 #fff;"
		"            }"
		""
		"            #submit {"
		"                -moz-border-radius: 3px;"
		"                -webkit-border-radius: 3px;"
		"                border-radius: 3px;"
		"                text-shadow: 0 1px 0 rgba(255,255,255,0.5);"
		"                border-width: 1px;"
		"                border-style: solid;"
		"                border-color: #d69e31 #e3a037 #d5982d #e3a037;"
		"                background-color: #FFF68F;"
		"                float: left;"
		"                height: 35px;"
		"                padding: 0;"
		"                width: 120px;"
		"                cursor: pointer;"
		"                font: bold 15px Arial, Helvetica;"
		"                color: #8f5a0a;"
		"            }"
		""
		"            a {"
		"                text-decoration: none"
		"            }"
		""
		"            #actions {"
		"                margin-top: 20px;"
		"                margin-bottom: 20px;"
		"            }"
		""
		"            #actions a {"
		"                color: #3151A2;"
		"                float: right;"
		"                line-height: 35px;"
		"                margin-left: 10px;"
		"            }"
		"        </style>"
		"    </head>"
		"    <body>"
		"        <form action='Login.html' method='post' id='login'>"
		"            <h1>Log In</h1>"
		"            <fieldset id='inputs'>"
		"                <input id='username' type='text' placeholder='用户名' name='username'/>"
		"                <input id='password' type='password' placeholder='密码' name='password'/>"
		"				 <input type='hidden' name='hidden' value='hidden'/>"
		"            </fieldset>"
		"            <fieldset id='actions'>"
		"                <input type='submit' id='submit' value='提交'/>"
		"                <a href='' title='点我刷新~'>刷新</a>"
		"            </fieldset>"
		"        </form>"
		"    </body>"
		"</html>"
};



uint8_t Connect_html[] = {
		"HTTP/1.0 200 OK\r\n"\
		"Content-Type: text/html;charset=UTF-8\r\n"\
		"Cache-Control: no-store\r\n"\
		"Connection: close\r\n"\
		"\r\n"\
		"<!DOCTYPE html>"
		"<html>"
		"    <head>"
		"        <link rel='icon' href='data:;base64,='>"
		"        <meta charset='UTF-8'>"
		"        <meta name='viewport' content='width=device-width, initial-scale=0.6'>"
		"        <title>星尘科技 智创未来</title>"
		"        <style type='text/css'>"
		"            body {"
		"                background-color: #FFEC8B;"
		"            }"
		""
		"            #login {"
		"                background-color: #fff;"
		"                height: 300px;"
		"                width: 400px;"
		"                margin: -150px 0 0 -230px;"
		"                padding: 30px;"
		"                position: absolute;"
		"                top: 50%;"
		"                left: 50%;"
		"                z-index: 0;"
		"                -moz-border-radius: 3px;"
		"                -webkit-border-radius: 3px;"
		"                border-radius: 3px;"
		"                -webkit-box-shadow: 0 0 2px rgba(0, 0, 0, 0.2), "
		"                    0 1px 1px rgba(0, 0, 0, .2), "
		"                    0 3px 0 #fff, 0 4px 0 rgba(0, 0, 0, .2), "
		"                    0 6px 0 #fff, 0 7px 0 rgba(0, 0, 0, .2);"
		"                -moz-box-shadow: 0 0 2px rgba(0, 0, 0, 0.2), "
		"                    1px 1px 0 rgba(0, 0, 0, .1), "
		"                    3px 3px 0 rgba(255, 255, 255, 1), "
		"                    4px 4px 0 rgba(0, 0, 0, .1), "
		"                    6px 6px 0 rgba(255, 255, 255, 1), "
		"                    7px 7px 0 rgba(0, 0, 0, .1);"
		"                box-shadow: 0 0 2px rgba(0, 0, 0, 0.2), "
		"                    0 1px 1px rgba(0, 0, 0, .2), "
		"                    0 3px 0 #fff, "
		"                    0 4px 0 rgba(0, 0, 0, .2), "
		"                    0 6px 0 #fff, "
		"                    0 7px 0 rgba(0, 0, 0, .2);"
		"            }"
		""
		"            #login:before {"
		"                content: '';"
		"                position: absolute;"
		"                z-index: -1;"
		"                border: 1px dashed #ccc;"
		"                top: 5px;"
		"                bottom: 5px;"
		"                left: 5px;"
		"                right: 5px;"
		"                -moz-box-shadow: 0 0 0 1px #fff;"
		"                -webkit-box-shadow: 0 0 0 1px #fff;"
		"                box-shadow: 0 0 0 1px #fff;"
		"            }"
		""
		"            h1 {"
		"                text-shadow: 0 1px 0 rgba(255, 255, 255, .7), 0px 2px 0 rgba(0, 0, 0, .5);"
		"                text-transform: uppercase;"
		"                text-align: center;"
		"                color: #666;"
		"                margin: 0 0 30px 0;"
		"                letter-spacing: 4px;"
		"                font: normal 26px/1 Verdana, Helvetica;"
		"                position: relative;"
		"            }"
		""
		"            fieldset {"
		"                border: 0;"
		"                padding: 0;"
		"                margin: 0;"
		"            }"
		""
		"            #inputs input {"
		"                padding: 15px 15px 15px 30px;"
		"                margin: 0 0 10px 0;"
		"                width: 353px;"
		"                /* 353 + 2 + 45 = 400 */"
		"                border: 1px solid #ccc;"
		"                -moz-border-radius: 5px;"
		"                -webkit-border-radius: 5px;"
		"                border-radius: 5px;"
		"                -moz-box-shadow: 0 1px 1px #ccc inset, 0 1px 0 #fff;"
		"                -webkit-box-shadow: 0 1px 1px #ccc inset, 0 1px 0 #fff;"
		"                box-shadow: 0 1px 1px #ccc inset, 0 1px 0 #fff;"
		"            }"
		""
		"            #submit {"
		"                -moz-border-radius: 3px;"
		"                -webkit-border-radius: 3px;"
		"                border-radius: 3px;"
		"                text-shadow: 0 1px 0 rgba(255,255,255,0.5);"
		"                border-width: 1px;"
		"                border-style: solid;"
		"                border-color: #d69e31 #e3a037 #d5982d #e3a037;"
		"                background-color: #FFF68F;"
		"                float: right;"
		"                height: 35px;"
		"                padding: 0;"
		"                width: 120px;"
		"                cursor: pointer;"
		"                font: bold 15px Arial, Helvetica;"
		"                color: #8f5a0a;"
		"            }"
		""
		"            #actions {"
		"                text-align: center;"
		"                vertical-align: middle;"
		"            }"
		"        </style>"
		"    </head>"
		"    <body>"
		"        <form action='Connect.html?connect=ture' method='post' id='login'>"
		"            <h1>Log In</h1>"
		"            <fieldset id='inputs'>"
		"                <input id='servername' type='text' placeholder='服务器地址' name='servername' value=''/>"
		"                <input id='serverport' type='text' placeholder='服务器端口' name='serverport' value=''/>"
		"                <input id='wifiname' type='text' placeholder='WiFi名称' name='wifiname'/>"
		"                <input id='wifipw' type='password' placeholder='WiFi密码' name='wifipw'/>"
		"                <input type='hidden' name='hidden' value='hidden'/>"
		"            </fieldset>"
		"            <fieldset id='actions'>"
		"                <input type='submit' id='submit' value='连接WiFi'/>"
		"            </fieldset>"
		"        </form>"
		"    </body>"
		"</html>"
};

uint8_t Check_html[] = {
		"<!DOCTYPE html>"
		"<html>"
		"    <head>"
		"        <link rel='icon' href='data:;base64,='>"
		"        <meta charset='UTF-8'>"
		"        <meta name='viewport' content='width=device-width, initial-scale=0.6'>"
		"        <title>星尘科技 智创未来</title>"
		"        <style type='text/css'>"
		"            body {"
		"                background-color: #FFEC8B;"
		"            }"
		""
		"            #login {"
		"                background-color: #fff;"
		"                height: 240px;"
		"                width: 400px;"
		"                margin: -150px 0 0 -230px;"
		"                padding: 30px;"
		"                position: absolute;"
		"                top: 50%;"
		"                left: 50%;"
		"                z-index: 0;"
		"                -moz-border-radius: 3px;"
		"                -webkit-border-radius: 3px;"
		"                border-radius: 3px;"
		"                -webkit-box-shadow: 0 0 2px rgba(0, 0, 0, 0.2), 0 1px 1px rgba(0, 0, 0, .2), 0 3px 0 #fff, 0 4px 0 rgba(0, 0, 0, .2), 0 6px 0 #fff, 0 7px 0 rgba(0, 0, 0, .2);"
		"                -moz-box-shadow: 0 0 2px rgba(0, 0, 0, 0.2), 1px 1px 0 rgba(0, 0, 0, .1), 3px 3px 0 rgba(255, 255, 255, 1), 4px 4px 0 rgba(0, 0, 0, .1), 6px 6px 0 rgba(255, 255, 255, 1), 7px 7px 0 rgba(0, 0, 0, .1);"
		"                box-shadow: 0 0 2px rgba(0, 0, 0, 0.2), 0 1px 1px rgba(0, 0, 0, .2), 0 3px 0 #fff, 0 4px 0 rgba(0, 0, 0, .2), 0 6px 0 #fff, 0 7px 0 rgba(0, 0, 0, .2);"
		"            }"
		""
		"            #login:before {"
		"                content: '';"
		"                position: absolute;"
		"                z-index: -1;"
		"                border: 1px dashed #ccc;"
		"                top: 5px;"
		"                bottom: 5px;"
		"                left: 5px;"
		"                right: 5px;"
		"                -moz-box-shadow: 0 0 0 1px #fff;"
		"                -webkit-box-shadow: 0 0 0 1px #fff;"
		"                box-shadow: 0 0 0 1px #fff;"
		"            }"
		""
		"            h2 {"
		"                text-shadow: 0 1px 0 rgba(255, 255, 255, .7), 0px 2px 0 rgba(0, 0, 0, .5);"
		"                text-align: center;"
		"                color: #666;"
		"                margin: 0 0 30px 0;"
		"                letter-spacing: 4px;"
		"                font: normal 26px/1 Verdana, Helvetica;"
		"                position: relative;"
		"            }"
		""
		"            fieldset {"
		"                border: 0;"
		"                padding: 0;"
		"                margin: 0;"
		"            }"
		""
		"            #inputs input {"
		"                padding: 15px 15px 15px 30px;"
		"                margin: 0 0 10px 0;"
		"                width: 353px;"
		"                /* 353 + 2 + 45 = 400 */"
		"                border: 1px solid #ccc;"
		"                -moz-border-radius: 5px;"
		"                -webkit-border-radius: 5px;"
		"                border-radius: 5px;"
		"                -moz-box-shadow: 0 1px 1px #ccc inset, 0 1px 0 #fff;"
		"                -webkit-box-shadow: 0 1px 1px #ccc inset, 0 1px 0 #fff;"
		"                box-shadow: 0 1px 1px #ccc inset, 0 1px 0 #fff;"
		"            }"
		""
		"            #submit {"
		"                -moz-border-radius: 3px;"
		"                -webkit-border-radius: 3px;"
		"                border-radius: 3px;"
		"                text-shadow: 0 1px 0 rgba(255,255,255,0.5);"
		"                border-width: 1px;"
		"                border-style: solid;"
		"                border-color: #d69e31 #e3a037 #d5982d #e3a037;"
		"                background-color: #FFF68F;"
		"                height: 35px;"
		"                padding: 0;"
		"                width: 120px;"
		"                cursor: pointer;"
		"                font: bold 15px Arial, Helvetica;"
		"                color: #8f5a0a;"
		"            }"
		""
		"            a {"
		"                text-decoration: none;float:right;"
		"            }"
		""
		"            #actions {"
		"                margin-top: 20px;"
		"                margin-bottom: 20px;"
		"            }"
		""
		"            #actions a {"
		"                color: #3151A2;"
		"                float: right;"
		"                line-height: 35px;"
		"                margin-left: 10px;"
		"            }"
		"        </style>"
		"    </head>"
		"    <body>"
		"        <form action='' method='post' id='login'>"
		"            <fieldset id='inputs'>"
		"                <br/>"
		"                <h2>设备编号：        </h2>"
		"                <br/>"
		"                <h2>随机密码：        </h2>"
		"		     <input type='hidden' name='renew' value='ture'>"
		"            </fieldset>"
		"            <fieldset id='actions' style='text-align: center;'>"
		"                <input type='submit' id='submit' value='重设密码'/>"
		"				 <a href='Console.html'>返回主页</a>"
		"            </fieldset>"
		"        </form>"
		"    </body>"
		"</html>"
};

#endif