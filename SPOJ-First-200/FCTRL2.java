import java.math.BigInteger;
import java.util.Scanner;



public class Main {
	
	public static BigInteger factorial(BigInteger B){
		BigInteger ans = BigInteger.ONE;
		while(! B.equals(BigInteger.ONE)){
			ans = ans.multiply(B);
			B = B.subtract(BigInteger.valueOf(1));
		}
		return ans;
	}
	
	public static void main(String[] args) throws java.lang.Exception  {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while(T-->0){
			BigInteger B = BigInteger.valueOf(sc.nextLong());
			System.out.println(factorial(B).toString());
		}
		sc.close();
	}
}
