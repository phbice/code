//�˳������� �ֽ�������
import java.util.Scanner;
public class fjzys{
	public static void main(String args[]){

        Scanner shuru=new Scanner(System.in);
		int x;//�û��������

		System.out.println("==========�ֽ�������==========");

		do{
			System.out.println("������һ����������"); //�����ʾ
			x=shuru.nextInt(); //�����û��������������ֵ�� x ��

			if(x==1){
                System.out.println("1 = 1 �� 1");
			}else if(x<=0){
                System.out.println("������������");
			}else{ //�ų��쳣ֵ
				System.out.print(x +" = ");
				calculate(x);
			}
		}while(x!=1);//����1ʱ�˳�����
	}
	
	public static void calculate(int x){

		int i=2; //ѭ��������ʼ��&����
		boolean mark1=true, mark2=true; //�������

		do{
			for(i=2, mark1=true;i<x;i++){
				if(x%i==0){
					x/=i; //�� x �ֽ�Ϊ���� i ����һ����
					mark1=false;	mark2=false; //�ı���
					System.out.print(i +" �� "); //�������
					break;
					//x ���ֽ�� ���� for ѭ������ִ����һ�ֵ� do_while ѭ��
				}
			}

			if(mark2){ //�� mark2 Ϊ true ˵���û��������Ϊ����
				System.out.print("1 �� "); //�������
			}
			if(mark1){ //�� mark1 Ϊ true ˵�� x ���ܽ�һ���ֽ�ɸ�С������x Ϊ������
				System.out.print(x + "\n\n"); //������һ������
			}
		}while(!mark1); //�� mark1 Ϊ true ��˵�� x Ϊ���������ܼ����ֽ⣬���� do_while ѭ����
	}
}