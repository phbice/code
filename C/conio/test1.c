# include <stdio.h>
# include <conio.h>
int main(void)
{
	clrscr();
	gotoxy(10,1);
	cprintf("甜密密，");
	highvideo(); /*高亮度显示*/
	cprintf("\r\n 你笑得甜密密，");
	lowvideo(); /*低亮度显示*/
	cprintf("\r\n 好象花儿开在春风里，");
	normvideo(); /*普通亮度显示*/
	gotoxy(10,4); cprintf("开在春风里");
	cprintf("\r\n 在哪里，在哪里见过你？");
	printf("\r\n 你的笑容这样熟悉。");
	gotoxy(10,20);printf("任意键删去光标后的内容");
	gotoxy(18,3); getch();
	gotoxy(18,3);
	clreol(); /*删去光标后字符*/
	gotoxy(10,20);printf("任意键删去本行的内容 ");
	gotoxy(18,3); getch();
	delline(); /*删去本行*/
	gotoxy(10,20);printf("任意键在本行插一空行 ");
	gotoxy(18,3); getch();
	insline(); /*插入一空行*/
	gotoxy(1,7);
} 