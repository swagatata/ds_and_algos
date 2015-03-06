package math;

import java.math.BigInteger;

/**
 * Created by swagat on 17/02/15.
 */
public class Tests {
    public static void runTests() {
        ackermannTest();
    }

    private static void runPowerTest() {
        assert (Util.pow(1, 0) == 1d);
        assert (Util.pow(1, 2) == 1d);
        assert (Util.pow(2, 1) == 2d);
        assert (Util.pow(2, 10) == 1024d);
        assert (Util.pow(2, -2) == 0.25d);

        System.out.println("Done!");
    }

    private static void ackermannTest() {
//        for (int i = 0 ; i < 5 ; ++i) {
//            for (int j = 0 ; j < 5 ; ++j ) {
//                System.out.println("Ackerman (" + (i + 1) + ", " + (j + 1) + ") : " +
//                        Util.ackermann(BigInteger.valueOf(i + 1), BigInteger.valueOf(j + 1)));
//            }
//        }
        System.out.println(Util.ackermann(BigInteger.valueOf(4), BigInteger.valueOf(1)));
    }
}
