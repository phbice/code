import java.util.Random;
public class random{
	public static void main(String[] args){
		Random x=new Random();
		int number=x.nextInt(10);//���0~9�������
		System.out.println(number);
	}
}