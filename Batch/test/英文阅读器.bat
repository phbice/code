@echo off
title 英文阅读器
:start
cls
set /p read=请输入英文：
echo 阅读中……
mshta vbscript:createobject("sapi.spvoice").speak("%read%")(window.close)
goto start