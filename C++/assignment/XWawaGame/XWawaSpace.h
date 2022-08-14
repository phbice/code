/*
	���ߵ�����ռ�
	������ǽ�ڣ��ڲ��ֳ������ݺ����еĿո�
	ÿ�����ӿ����ǿհ׵ġ�ǽ�ڡ����ӣ�
	��һ�����������ڴ˿ռ��ڡ�
	
	�� �� �ˣ�Zhang Hua
	����ʱ�䣺2011-02-20

	�޸ļ�¼��
	2019-03-01 �Ż���ʾЧ����������˸��
*/

#ifndef XWAWASPACE_H
#define XWAWASPACE_H

// �ռ�Ŀ�Ⱥ͸߶ȵ����ֵ����Сֵ
const int XWAWAROOM_WIDTH_MAX = 32;
const int XWAWAROOM_HEIGHT_MAX = 12;
const int XWAWAROOM_WIDTH_MIN = 16;
const int XWAWAROOM_HEIGHT_MIN = 8;

// �ռ���ÿһ���ֵ��/����ʾ״̬
const char XWAWAROOM_EMPTY = ' ';		// ��
const char XWAWAROOM_BEAN = '*';		// �ж���
const char XWAWAROOM_WALL = 'H';		// ǽ��
const char XWAWAROOM_WAWA = 'G';		// ����
const char XWAWAROOM_WAWAANDBEAN = '@';	// �ж��ӣ�������Ҳ�ڸõ�

// ����
const int XWAWAROOM_DIR_UP = 0;
const int XWAWAROOM_DIR_DOWN = 1;
const int XWAWAROOM_DIR_LEFT = 2;
const int XWAWAROOM_DIR_RIGHT = 3;

// �ռ���Ķ���
class XWawaSpace
{
private:
	int width, height; // �ռ��ʵ�ʿ�Ⱥ͸߶�
	char data[XWAWAROOM_HEIGHT_MAX][XWAWAROOM_WIDTH_MAX]; // �ռ��״̬

	int wawa_cx, wawa_cy; // ���ߵ�λ��
	int wawa_ox, wawa_oy; // �����ƶ�ǰ��λ��

public:
	XWawaSpace(int w=XWAWAROOM_WIDTH_MIN, int h=XWAWAROOM_HEIGHT_MIN);

	// ��ʼ��
	void init();

	// ��ָ����״̬���г�ʼ��
	void init(char data[XWAWAROOM_HEIGHT_MAX][XWAWAROOM_WIDTH_MAX]);

	// ��ջ���
	void clearAll();

	// ���ƿռ��е�һ����
	void paintPoint(int x, int y);

	// ���ƿռ�
	void paint();

	// ���»��ƿռ�
	void repaint();

	// ��ÿռ�ĳߴ�
	void getRect(int &width, int &height);

	// ���õ��״̬
	void setPoint(int x, int y, char value);

	// ��õ��״̬
	char getPoint(int x, int y);

	// �������ߵ�λ��
	void setWawaPos(int x, int y);

	// ������ߵ�λ��
	void getWawaPos(int &x, int &y);

	// ��ָ�������ƶ�����
	bool moveWawa(int dir);

	// ָ�����������λ���Ƿ���ǽ
	bool isClear(int dir);

	// �ռ��Ƿ��޶���
	bool isEmpty();

	// ���ݼ����������ߴ����½��ƶ����Ҳ࣬�������еĶ��Ӽ������������ռ�
	// ����0����ʾ
	// ����1�����ϰ�����ɽ����ɽ
	// ����2��Խ���̶��ϰ�
	// ����3��Խ���߶Ȳ�ȷ������ȹ̶����м��������ϰ�
	// ����4��Խ���߶ȡ���Ⱥͼ�඼��ȷ���������ϰ�
	void build(int task);

	// ��������Ƿ������
	bool check();
};

#endif