@echo off
echo ���������루����������κ�����Զ��˳���
goto start
:b
cls
echo �������,����������
:start
set /p v=����: 
if not "%v%"=="******" goto a
echo ������ȷ
pause
goto c
:a
set /a var+=1
if %var% leq 2 goto b
exit

:c
mode con cols=113 lines=15 &color 9f
cls
echo.
echo  �������ڳ�ʼ��. . .
echo.
echo  ��������������������������������������������������������������������������������
set/p=  ��<nul
for /L %%i in (1 1 38) do set /p a=��<nul&ping /n 1 127.0.0.1>nul
echo   100%%
echo  ��������������������������������������������������������������������������������
pause