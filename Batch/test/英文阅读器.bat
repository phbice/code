@echo off
title Ӣ���Ķ���
:start
cls
set /p read=������Ӣ�ģ�
echo �Ķ��С���
mshta vbscript:createobject("sapi.spvoice").speak("%read%")(window.close)
goto start