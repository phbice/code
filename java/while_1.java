import java.util.Scanner;
public class while_1{
	public static void main(String[] args){
		Scanner num=new Scanner(System.in);
		System.out.println("������һ����������");
		int number=num.nextInt();
		int i=2; //ѭ��������ʼ��
		int mark=0; //�������
		if(number==1){ //�ų�����1
			System.out.println("1�Ȳ���������Ҳ���Ǻ�����");
		}else{ //��Ҫ���ֿ�ʼ
			while(i<number){
				if(number%i==0){
					int number2=number/i;
					System.out.print(number + "�Ǻ�����");
					System.out.println(number2+" �� "+i+" = "+number);
					mark=1; //�ı���
					break;
				}
				i++;
			}
		}
		if(mark==0){ //��ȡ���
			System.out.println(number+"������");
		}
	}
}