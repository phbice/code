/*
调用方法示例
本程序将调用 print 方法和 add 方法
*/
public class TestMethod{

	public static void main(String[] args){
		System.out.println("这是main方法");
		System.out.println("即将调用 print 方法");
		int ret = print();
		System.out.println("调用 print 方法结束\n" + "返回值=" + ret);

		System.out.println("即将调用 add 方法");
		int ret1 = add(13,14);
		System.out.println("调用 add 方法结束\n" + "返回值=" + ret1);
	}

	public static int print(){
		int i;
		for(i = 1;i < 10;i++){
			System.out.print(i);
		}
		System.out.println();
		return i;
	}

	public static int add(int a,int b){
		return a + b;
	}

}