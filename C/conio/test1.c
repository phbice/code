# include <stdio.h>
# include <conio.h>
int main(void)
{
	clrscr();
	gotoxy(10,1);
	cprintf("�����ܣ�");
	highvideo(); /*��������ʾ*/
	cprintf("\r\n ��Ц�������ܣ�");
	lowvideo(); /*��������ʾ*/
	cprintf("\r\n ���󻨶����ڴ����");
	normvideo(); /*��ͨ������ʾ*/
	gotoxy(10,4); cprintf("���ڴ�����");
	cprintf("\r\n ���������������㣿");
	printf("\r\n ���Ц��������Ϥ��");
	gotoxy(10,20);printf("�����ɾȥ���������");
	gotoxy(18,3); getch();
	gotoxy(18,3);
	clreol(); /*ɾȥ�����ַ�*/
	gotoxy(10,20);printf("�����ɾȥ���е����� ");
	gotoxy(18,3); getch();
	delline(); /*ɾȥ����*/
	gotoxy(10,20);printf("������ڱ��в�һ���� ");
	gotoxy(18,3); getch();
	insline(); /*����һ����*/
	gotoxy(1,7);
} 