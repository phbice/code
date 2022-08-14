@echo off

REM ���.dvi
latex --interaction=batchmode formular.tex

REM ���.png
REM -T tight          ȥ���ױ�
REM -D num            ��ˮƽ�ֱ��ʺʹ�ֱ�ֱ��ʾ���Ϊ num����λ��dpi��
REM -bg color_spec    ָ������ɫ��transparent ���� Transparent Ϊ͸������ɫ
REM -o �ļ���         ָ������ļ���
dvipng -T tight -D 800 -bg transparent -o formular.png formular.dvi

del formular.aux
del formular.log
del formular.dvi
del formular.pdf
