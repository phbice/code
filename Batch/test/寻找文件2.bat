@echo off
title Ѱ���ļ�
cls
set /p var=�������ļ���:
cls
echo ����Ѱ��%var%�ļ��������ĵȺ򡭡�
for /r c:\ %%i in (%var%) do echo %%i>>%var%�ļ��б�.txt
for /r d:\ %%i in (%var%) do echo %%i>>%var%�ļ��б�.txt
for /r e:\ %%i in (%var%) do echo %%i>>%var%�ļ��б�.txt
for /r f:\ %%i in (%var%) do echo %%i>>%var%�ļ��б�.txt
echo �ļ�Ѱ����ϣ�
pause