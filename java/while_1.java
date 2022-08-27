import java.util.Scanner;
public class while_1{
	public static void main(String[] args){
		Scanner num=new Scanner(System.in);
		System.out.println("请输入一个正整数：");
		int number=num.nextInt();
		int i=2; //循环变量初始化
		int mark=0; //创建标记
		if(number==1){ //排除数字1
			System.out.println("1既不是质数，也不是合数。");
		}else{ //主要部分开始
			while(i<number){
				if(number%i==0){
					int number2=number/i;
					System.out.print(number + "是合数，");
					System.out.println(number2+" × "+i+" = "+number);
					mark=1; //改变标记
					break;
				}
				i++;
			}
		}
		if(mark==0){ //读取标记
			System.out.println(number+"是质数");
		}
	}
}