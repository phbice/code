;设随机数是 4321；
;游戏者输入 5678，提示则为 ????；
;游戏者输入 5674，提示则为 ???X；
;游戏者输入 1234，提示则为 XXXX；
;游戏者输入 4321，提示则为 YYYY。

ASSUME   CS:CC, DS:QQ

QQ  SEGMENT

    MSG1  DB  13, 10, 'You have three time opportunity :'
          DB  13, 10, 13, 10, 36

    NNN   DW  3             ;默认猜数次数

    MSG2  DB  'The random is : ', 13, 10

    XXX   DB  0, 0, 0, 0    ;存放随机数
          DB  13, 10, 36

    YYY   DB  13, 10, '????', 13, 10, 13, 10, 36

QQ  ENDS
  
CC  SEGMENT
;------------------------------  
BG:
    MOV   AX, QQ
    MOV   DS, AX

    LEA   DX, MSG1
    MOV   AH, 9
    INT   21H

    CALL  RANDOM_4  ;生成四个互不相同的数字符号
;------------------------------
IN_LOOP:            ;循环输入四个字符
    MOV   SI, 0     ;分别和四个随机符号比较
IN_X:               ;根据比较结果写入?BA
    MOV   DI, 0
    MOV   AH, 1
    INT   21H       ;键入一个字符
IN_1:
    CMP   AL, XXX[DI]
    JZ    IN_2

    INC   DI
    CMP   DI, 4
    JNZ   IN_1
    MOV   YYY[SI + 2], '?'
    JMP   IN_NEXT

IN_2:
    CMP   SI, DI
    JNZ   IN_3
    MOV   YYY[SI + 2], 'A'
    JMP   IN_NEXT
IN_3:
    MOV   YYY[SI + 2], 'B'
IN_NEXT:
    INC   SI
    CMP   SI, 4
    JNZ   IN_X
;------------------------------
DISP:
    LEA   DX, YYY     ;显示提示
    MOV   AH, 9
    INT   21H

    CMP   YYY + 2, 'Y'
    JNZ   NEXT
    CMP   YYY + 3, 'Y'
    JNZ   NEXT
    CMP   YYY + 4, 'Y'
    JNZ   NEXT
    CMP   YYY + 5, 'Y'
    JNZ   NEXT

    JMP   EXIT       ;四个都是Y就提前结束

NEXT:
    DEC   NNN
    CMP   NNN, 0
    JNZ   IN_LOOP    ;不到次数就再次输入

    LEA   DX, MSG2   ;显示内定
    MOV   AH, 9
    INT   21H

EXIT:
    MOV   AH, 4CH    ;程序结束
    INT   21H
;------------------------------
RANDOM_4:
    MOV   DL, '8'
    MOV   DI, 0
RDM:
    MOV   CL, DL
    ADD   CL, 17
    MOV   CH, DH
    AND   CH, 1
    LOOP  $
    CALL  GET_RANDOM ;AL=0~9
    MOV   DL, AH
    ADD   DL, '0'

    MOV   SI, 0
CHK:
    CMP   DL, XXX[SI]
    JZ    RDM
    INC   SI
    CMP   SI, 4
    JNZ   CHK

    MOV   XXX[DI], DL
    INC   DI
    CMP   DI, 4
    JNZ   RDM
RET
;------------------------------
GET_RANDOM:
    MOV   AH, 2CH
    INT   21H
    MOV   AL, DL 
    MOV   AH, 0
    MOV   BL, 10
    DIV   BL
RET                  ;AL=0~9
;---------------------------------

CC  ENDS
    END   BG

;====================================

;本程序执行，有如下的显示：
;
;c:\masm510>RDM_4
;
;You have three time opportunity :
;
;1357
;X?X?
;
;5126
;XX?Y
;
;4516
;?YYY
;
;The random is :
;0516
;————————————————
;版权声明：本文为CSDN博主「baidu_知道」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
;原文链接：https://blog.csdn.net/baidu_33836580/java/article/details/50579215