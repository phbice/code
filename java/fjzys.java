//此程序被用来 分解质因数
import java.util.Scanner;
public class fjzys{
	public static void main(String args[]){

        Scanner shuru=new Scanner(System.in);
		int x;//用户输入的数

		System.out.println("==========分解质因数==========");

		do{
			System.out.println("请输入一个正整数："); //输出提示
			x=shuru.nextInt(); //接收用户输入的数，并赋值给 x 。

			if(x==1){
                System.out.println("1 = 1 × 1");
			}else if(x<=0){
                System.out.println("不是正整数！");
			}else{ //排除异常值
				System.out.print(x +" = ");
				calculate(x);
			}
		}while(x!=1);//输入1时退出程序
	}
	
	public static void calculate(int x){

		int i=2; //循环变量初始化&除数
		boolean mark1=true, mark2=true; //创建标记

		do{
			for(i=2, mark1=true;i<x;i++){
				if(x%i==0){
					x/=i; //将 x 分解为质数 i 和另一个数
					mark1=false;	mark2=false; //改变标记
					System.out.print(i +" × "); //输出因数
					break;
					//x 被分解后 跳出 for 循环，并执行新一轮的 do_while 循环
				}
			}

			if(mark2){ //若 mark2 为 true 说明用户输入的数为质数
				System.out.print("1 × "); //输出因数
			}
			if(mark1){ //若 mark1 为 true 说明 x 不能进一步分解成更小的数（x 为质数）
				System.out.print(x + "\n\n"); //输出最后一个因数
			}
		}while(!mark1); //若 mark1 为 true ，说明 x 为质数，不能继续分解，跳出 do_while 循环。
	}
}