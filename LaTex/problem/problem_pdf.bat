@echo off

rungs -r800 -sDEVICE=pnggray -o problem.png problem.pdf

del problem.aux
del problem.log
del problem.dvi
del problem.pdf
del problem.synctex.gz