/*
���÷���ʾ��
�����򽫵��� print ������ add ����
*/
public class TestMethod{

	public static void main(String[] args){
		System.out.println("����main����");
		System.out.println("�������� print ����");
		int ret = print();
		System.out.println("���� print ��������\n" + "����ֵ=" + ret);

		System.out.println("�������� add ����");
		int ret1 = add(13,14);
		System.out.println("���� add ��������\n" + "����ֵ=" + ret1);
	}

	public static int print(){
		int i;
		for(i = 1;i < 10;i++){
			System.out.print(i);
		}
		System.out.println();
		return i;
	}

	public static int add(int a,int b){
		return a + b;
	}

}