//高精度除法
import java.util.Scanner;
public class div{

	public static void main(String[] args){
		int dividend/*被除数*/,	divsor/*除数*/,	times/*精度*/;
	
		Scanner in = new Scanner(System.in);
		System.out.print("输入被除数：");
		dividend = in.nextInt();
		System.out.print("输入除数：");
		divsor = in.nextInt();
		System.out.print("精确到小数点后：");
		times = in.nextInt();
		calculate(dividend,divsor,times);
	}

	public static void calculate(int dividend, int divsor, int times){
		int rem = dividend%divsor; //余数
		int num = dividend/divsor; //商
		System.out.print(dividend + " ÷ " + divsor + " = " + num + ".");
	
		while(times>0){
			dividend = rem * 10;
			num = dividend/divsor;
			rem = dividend%divsor;
			System.out.print(num);
			times--;
		}

	}

}