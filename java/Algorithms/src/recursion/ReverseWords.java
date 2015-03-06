package recursion;

/**
 * Created by swagat on 17/02/15.
 */
public class ReverseWords {
    public static void printReverseWords(String s) {
        int firstWordEndIndex = recursivePrint(s, 0, 0, 0);
        recursivePrint(s, 1, 0, firstWordEndIndex);
    }

    private static int recursivePrint(String s, int mode, int start, int end) {
        //System.out.println(mode + " " + start + " " + end);

        if (mode == 0) {
            if (start >= s.length()) {
                return start;
            }
            if (s.charAt(start) != ' ') {
                return recursivePrint(s, mode, start + 1, end);
            }
            else {
                int wordEnd = recursivePrint(s, mode, start + 1, end);
                recursivePrint(s, 1, start + 1, wordEnd);
                System.out.print(" ");
                return start;
            }
        }
        else {
            if (start == end) {
                return -1;
            }
            else {
                System.out.print(s.charAt(start));
                recursivePrint(s, mode, start + 1, end);
            }
        }
        Boolean b = null;
try {
    return 0;
}finally {
    return 0;
}
    }

    public static void test() {
        String s = "What is this question";

        printReverseWords(s);
    }
}
