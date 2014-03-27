import java.util.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
//import java.math.BigInteger;
import java.math.BigDecimal;
import java.math.RoundingMode;

public class Main 
{
	private static final BigDecimal SQRT_DIG = new BigDecimal(150);
	private static final BigDecimal SQRT_PRE = new BigDecimal(10).pow(SQRT_DIG.intValue());

	/**
	 * Private utility method used to compute the square root of a BigDecimal.
	 * 
	 * @author Luciano Culacciatti 
	 * @url http://www.codeproject.com/Tips/257031/Implementing-SqrtRoot-in-BigDecimal
	 */
	private static BigDecimal sqrtNewtonRaphson  (BigDecimal c, BigDecimal xn, BigDecimal precision){
	    BigDecimal fx = xn.pow(2).add(c.negate());
	    BigDecimal fpx = xn.multiply(new BigDecimal(2));
	    BigDecimal xn1 = fx.divide(fpx,2*SQRT_DIG.intValue(),RoundingMode.HALF_DOWN);
	    xn1 = xn.add(xn1.negate());
	    BigDecimal currentSquare = xn1.pow(2);
	    BigDecimal currentPrecision = currentSquare.subtract(c);
	    currentPrecision = currentPrecision.abs();
	    if (currentPrecision.compareTo(precision) <= -1){
	        return xn1;
	    }
	    return sqrtNewtonRaphson(c, xn1, precision);
	}

	/**
	 * Uses Newton Raphson to compute the square root of a BigDecimal.
	 * 
	 * @author Luciano Culacciatti 
	 * @url http://www.codeproject.com/Tips/257031/Implementing-SqrtRoot-in-BigDecimal
	 */
	public static BigDecimal bigSqrt(BigDecimal c){
	    return sqrtNewtonRaphson(c,new BigDecimal(1),new BigDecimal(1).divide(SQRT_PRE));
	}
	
	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException
	{
		Scanner keyboard = new Scanner(new File("A.in"));
		PrintWriter writer = new PrintWriter("A.out", "UTF-8");
		
		//Scanner keyboard = new Scanner(System.in);
		//BigInteger TWO = BigInteger.ONE.add(BigInteger.ONE);
		BigDecimal TWO = BigDecimal.ONE.add(BigDecimal.ONE);
		BigDecimal FOUR = TWO.multiply(TWO);
		BigDecimal EIGHT = FOUR.multiply(TWO);
		BigDecimal SIXTEEN = FOUR.multiply(FOUR);
		int ncases = keyboard.nextInt();
		for (int i = 1; i <= ncases; i++)
		{
			//BigInteger r = BigInteger.valueOf(keyboard.nextLong());
			//BigInteger t = BigInteger.valueOf(keyboard.nextLong());
			//BigInteger start = r.multiply(TWO).add(BigInteger.ONE);
			BigDecimal r = BigDecimal.valueOf(keyboard.nextLong());
			BigDecimal t = BigDecimal.valueOf(keyboard.nextLong());
			BigDecimal start = r.multiply(TWO).add(BigDecimal.ONE);
			
			BigDecimal innerterm = (start.multiply(start).negate()).add(FOUR.multiply(start)).subtract(EIGHT.multiply(t));
			BigDecimal ringwidth = (FOUR.negate()).add(bigSqrt(SIXTEEN.subtract(FOUR.multiply(innerterm)))).divide(TWO);
			//System.out.println(ringwidth.doubleValue());
			double ans = (ringwidth.subtract(start).divide(FOUR)).add(BigDecimal.ONE).doubleValue();
			//System.out.println("Case #" + i + ": " + (long)ans);
			writer.println("Case #" + i + ": " + (long)ans);
		}
		keyboard.close();
		
		/* Derivation
		(s+e)*((e-s)/4)+1)/2 <= paint
		2*paint >= (s+e)*(.25e-.25s+1)
		8*paint >= (s+e)*(e-s+4)
		0 >= e^2 + 4e - s^2 + 4s - 8*paint
		e = (-4 + sqrt(16 - 4(-s^2 + 4s - 8*paint)))/2
		*/
	}
}
