import java.util.Random;
public class random{
	public static void main(String[] args){
		Random x=new Random();
		int number=x.nextInt(10);//输出0~9的随机数
		System.out.println(number);
	}
}