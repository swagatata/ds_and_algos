package math;

import java.math.BigInteger;

/**
 * Created by swagat on 17/02/15.
 */
public class Util {
    public static double pow(int a, int b) {
        if (b == 0) {
            return 1;
        }

        double base = a;
        if (b < 0) {
            base = 1 / base;
            b = b * -1;
        }

        double power = 1;
        double cur = base;
        while (b != 0) {
            if ((b & 1) != 0) {
                power *= cur;
            }

            cur = cur * cur;
            b = b >> 1;
        }

        return power;
    }

    private static BigInteger [][] mem = new BigInteger[1000][70000];

    public static BigInteger ackermann(BigInteger x, BigInteger y) {
        //System.out.println("In ackermann of " + x + " , " + y);
        if ((x.compareTo(BigInteger.valueOf(1000)) == -1) && (y.compareTo(BigInteger.valueOf(1000)) == -1)) {
            if (mem[x.intValue()][y.intValue()] != null) {
                return mem[x.intValue()][y.intValue()];
            }
        }

        if (x.compareTo(BigInteger.ZERO) == 0) {
            mem[0][y.intValue()] = y.add(BigInteger.valueOf(1));
            return mem[0][y.intValue()];
        }

        if (y.compareTo(BigInteger.ZERO) == 0) {
            mem[x.intValue()][0] = ackermann(x.subtract(BigInteger.ONE), BigInteger.ONE);
            return mem[x.intValue()][0];
        }

        mem[x.intValue()][y.intValue()] = ackermann(x.subtract(BigInteger.ONE), ackermann(x, y.subtract(BigInteger.ONE)));
        return ackermann(x.subtract(BigInteger.ONE), ackermann(x, y.subtract(BigInteger.ONE)));
    }
}
