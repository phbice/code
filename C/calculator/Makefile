TARGET = calculator.exe
SOURCE = calculator.c list.c PreProcess.c infix2postfix.c
HEADER = list.h PreProcess.h infix2postfix.h

.PHONY : debug

$(TARGET) : $(SOURCE) $(HEADER)
	gcc $(SOURCE) -o $(TARGET)
	
debug : $(SOURCE) $(HEADER)
	gcc $(SOURCE) -o $(TARGET) -g