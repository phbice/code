@echo off
set var=0
rem ************ѭ����ʼ��
:continue
set /a var+=1
echo ��%var%��ѭ��
if %var% lss 100 goto continue
rem ************ѭ��������
echo ѭ��ִ�����
pause