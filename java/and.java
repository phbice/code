import java.util.Scanner;
public class and{
	public static void main(String[] args){
		Scanner a=new Scanner(System.in);
		System.out.println("请输入一个大于5且小于10的数：");
		double num=a.nextDouble();
		if(num<5||num>10){ //判断是否有条件为真
			System.out.println("输入错误");
		}
	}
}
/*
&&  条件1&&条件2  两个条件同时为真时，结果为真
||  条件1||条件2  有一个条件为真时，结果为真
!      !条件      条件为真时，结果为假；条件为假时，结果为真
*/