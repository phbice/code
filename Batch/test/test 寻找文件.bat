@echo off
set /p v=请输入文件名:
IF EXIST %v% echo 文件存在！
IF not EXIST %v% echo 文件不存在！
pause