public class TestArray{
	public static void main(String[] args){
		int[] number = {2,3,5,7,11};
		/*
		int[] number = new int[5];
		number[0] = 2;
		number[1] = 3;
		number[2] = 5;
		number[3] = 7;
		number[4] = 11;
		*/
		
		//增强型for循环
		for(int c:number){
			System.out.print(c + " ");
		}
		System.out.print("\n");
	}
}