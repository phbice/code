import java.util.Scanner;
public class and{
	public static void main(String[] args){
		Scanner a=new Scanner(System.in);
		System.out.println("������һ������5��С��10������");
		double num=a.nextDouble();
		if(num<5||num>10){ //�ж��Ƿ�������Ϊ��
			System.out.println("�������");
		}
	}
}
/*
&&  ����1&&����2  ��������ͬʱΪ��ʱ�����Ϊ��
||  ����1||����2  ��һ������Ϊ��ʱ�����Ϊ��
!      !����      ����Ϊ��ʱ�����Ϊ�٣�����Ϊ��ʱ�����Ϊ��
*/