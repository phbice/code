@echo off
echo 请输入密码（密码错误三次后程序将自动退出）
goto start
:b
cls
echo 密码错误,请重新输入
:start
set /p v=密码: 
if not "%v%"=="******" goto a
echo 密码正确
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
echo  程序正在初始化. . .
echo.
echo  ┌──────────────────────────────────────┐
set/p=  ■<nul
for /L %%i in (1 1 38) do set /p a=■<nul&ping /n 1 127.0.0.1>nul
echo   100%%
echo  └──────────────────────────────────────┘
pause