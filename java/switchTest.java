//switch���
import java.util.Scanner;
public class switchTest{
	public static void main(String[] args){
		System.out.println("����һ��������1~3��");
		Scanner a = new Scanner(System.in);
		int num = a.nextInt();
		switch(num){
			case 1:
				System.out.println("Ҽ");
				break;
			case 2:
				System.out.println("��");
				break;
			case 3:
				System.out.println("��");
				break;
			default:
				System.out.println("Error!");
		}
	}
}
