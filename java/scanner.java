import java.util.Scanner; //����ɨ����
public class scanner{
	public static void main(String[] args){
		Scanner a=new Scanner(System.in); //����һ���µ�ɨ���ǲ���ֵ
		System.out.println("������һ����������");
		int num=a.nextInt();
		int m=num%2;
		if(m==0){
			System.out.println(num +"��ż��");
		}else{
			System.out.println(num +"������");
		}
	}
}