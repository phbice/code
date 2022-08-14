/*
	���߼�����Ϸ����
	���ڡ�C++���Գ�����ơ��γ̣�ͨ���Ƚ�����ġ��׽��ܵķ�ʽ��ѧ��ȥ��ϰ�ṹ��������ƺͻ��ڶ����̡�

	����
	һ���˹������壬�����ڶ����Ŀռ��С�
	�����ߵĿռ��У����������������ƶ���ÿ���ƶ�һ�񣬲���ֱ�Ӵ�Խǽ�ڣ�
	������ĳһ���������һ�����ӡ�

	���ߵ�����ռ�
	������ǽ�ڣ��ڲ��ֳ������ݺ����еĿո�
	ÿ�����ӿ����ǿհ׵ġ�ǽ�ڡ����ӣ�
	��һ�����������ڴ˿ռ��ڡ�
	
	�� �� �ˣ�Zhang Hua
	����ʱ�䣺2011-02-20

	�޸ļ�¼��
	2017-09-19 ��XWawaSpace��Ĵ����Ƴ��������ڵ������ļ��С�
	2014-03-04 ȥ��Ч�����õ��ٶȵ��ڹ��ܡ�
	           ���������ƶ�����ͳ�ƹ��ܡ�
	2012-10-05 ��������������Ƶ�XWawaSpace�У�Ҫ��ѧ����ƺͶ����Լ���XWawa��
*/

#ifndef XWAWA_H
#define XWAWA_H

#include "XWawaSpace.h"

// ������Ķ���
class XWawa
{
private:
	int moveCount; // �ƶ�����

protected:
	XWawaSpace space; // �ռ�

public:
	XWawa();

	// �ƶ�
	void moveUp();				// ����
	void moveDown();			// ����
	void moveLeft();			// ����
	void moveRight();			// ����

	int GetMoveCount() { return moveCount; }

	// �ٵ�ǰλ�ü��ӺͷŶ���
	void pickupBean();				// ����
	void putdownBean();				// �Ŷ���

	// �ж���Χ����ǰλ�õ����ڸ��ӣ�����ǽ�ڣ��ϰ��
	bool leftIsClear();			// ���
	bool rightIsClear();		// �ұ�
	bool upsideIsClear();		// �ϱ�
	bool downsideIsClear();		// �·�

	// �жϵ�ǰλ�����޶���
	bool beanIsHere();

	// �����������Ҳ���Բο�XWawaSpace.h��XWawaSpace::build������˵����
	// ����0����ʾ
	// ����1�����ϰ�����ɽ����ɽ
	// ����2��Խ���̶��ϰ�
	// ����3��Խ���߶Ȳ�ȷ������ȹ̶����м��������ϰ�
	// ����4��Խ���߶ȡ���Ⱥͼ�඼��ȷ���������ϰ�
	void assignTask(int task);

	// ��������Ƿ�����ɣ�����ȫ�����ӣ�
	bool taskIsAccomplished();
};

#endif