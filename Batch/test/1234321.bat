@echo off
:start
set /a var+=1
echo %var%
if %var% leq 9 goto start
:start2
set /a var-=1
echo %var%
if not %var% leq 1 goto start2
pause