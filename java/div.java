//�߾��ȳ���
import java.util.Scanner;
public class div{

	public static void main(String[] args){
		int dividend/*������*/,	divsor/*����*/,	times/*����*/;
	
		Scanner in = new Scanner(System.in);
		System.out.print("���뱻������");
		dividend = in.nextInt();
		System.out.print("���������");
		divsor = in.nextInt();
		System.out.print("��ȷ��С�����");
		times = in.nextInt();
		calculate(dividend,divsor,times);
	}

	public static void calculate(int dividend, int divsor, int times){
		int rem = dividend%divsor; //����
		int num = dividend/divsor; //��
		System.out.print(dividend + " �� " + divsor + " = " + num + ".");
	
		while(times>0){
			dividend = rem * 10;
			num = dividend/divsor;
			rem = dividend%divsor;
			System.out.print(num);
			times--;
		}

	}

}