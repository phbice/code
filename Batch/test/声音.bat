@echo off
echo 做好准备，响了啊！！
pause
mshta vbscript:createobject("sapi.spvoice").speak("Merry Christmas and Happy New Year!")(window.close)
pause