@echo off

REM 输出.dvi
latex --interaction=batchmode formular.tex

REM 输出.png
REM -T tight          去除白边
REM -D num            把水平分辨率和垂直分辨率均设为 num（单位：dpi）
REM -bg color_spec    指定背景色，transparent 或者 Transparent 为透明背景色
REM -o 文件名         指定输出文件名
dvipng -T tight -D 800 -bg transparent -o formular.png formular.dvi

del formular.aux
del formular.log
del formular.dvi
del formular.pdf
