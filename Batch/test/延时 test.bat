@echo off
echo 延时前：%time%
for /l %%i in (1,1,3750) do echo %%i>nul
echo 延时后：%time%
pause