
import algorithm.sort.BinarySort;
import recursion.ReverseStack;
import test.PatternMatchTest;

/**
 * Created with IntelliJ IDEA.
 * User: swagat
 * Date: 12/4/13
 * Time: 5:55 PM
 * To change this template use File | Settings | File Templates.
 */
public class Main {
    public static void main(String [] args) {
        PatternMatchTest test = new PatternMatchTest();
        test.lcsTest();
    }

    private static void testReverseStack() {
        ReverseStack r = new ReverseStack();

        r.test();
    }

    private static void testBSort() {
        System.out.println("Started!!");

        int [] bArr = {1, 2, 3, -1, -2, -3, -4};
        BinarySort bSort = new BinarySort(bArr);
        bSort.seggregatedSort();
    }
}
