@echo off
dir c:
rem �˳�����Ϊ>=1����������1��ִ�У�>=0����������0��ִ��
IF ERRORLEVEL 1 goto 1
IF ERRORLEVEL 0 goto 0
Rem ��������в��ɽ���λ�ã�����ʧ����Ҳ��ʾ�ɹ���
:0
echo ����ִ�гɹ���
Rem ����ִ�������������exit���˳�
goto exit
:1
echo ����ִ��ʧ�ܣ�
Rem ����ִ�������������exit���˳�
goto exit
:exit
pause