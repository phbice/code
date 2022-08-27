import java.util.Scanner; //引入扫描仪
public class scanner{
	public static void main(String[] args){
		Scanner a=new Scanner(System.in); //声明一个新的扫描仪并赋值
		System.out.println("请输入一个正整数：");
		int num=a.nextInt();
		int m=num%2;
		if(m==0){
			System.out.println(num +"是偶数");
		}else{
			System.out.println(num +"是奇数");
		}
	}
}