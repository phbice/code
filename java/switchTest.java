//switch语句
import java.util.Scanner;
public class switchTest{
	public static void main(String[] args){
		System.out.println("输入一个整数（1~3）");
		Scanner a = new Scanner(System.in);
		int num = a.nextInt();
		switch(num){
			case 1:
				System.out.println("壹");
				break;
			case 2:
				System.out.println("贰");
				break;
			case 3:
				System.out.println("叁");
				break;
			default:
				System.out.println("Error!");
		}
	}
}
