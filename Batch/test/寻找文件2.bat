@echo off
title 寻找文件
cls
set /p var=请输入文件名:
cls
echo 正在寻找%var%文件，请耐心等候……
for /r c:\ %%i in (%var%) do echo %%i>>%var%文件列表.txt
for /r d:\ %%i in (%var%) do echo %%i>>%var%文件列表.txt
for /r e:\ %%i in (%var%) do echo %%i>>%var%文件列表.txt
for /r f:\ %%i in (%var%) do echo %%i>>%var%文件列表.txt
echo 文件寻找完毕！
pause