@echo off

REM ���.dvi
latex --interaction=batchmode problem.tex

REM ���.png
REM -T tight          ȥ���ױ�
REM -D num            ��ˮƽ�ֱ��ʺʹ�ֱ�ֱ��ʾ���Ϊ num����λ��dpi��
REM -bg color_spec    ָ������ɫ��transparent ���� Transparent Ϊ͸������ɫ
REM -o �ļ���         ָ������ļ���
dvipng -T tight -D 800 -o problem.png problem.dvi

del problem.aux
del problem.log
del problem.dvi
del problem.pdf
