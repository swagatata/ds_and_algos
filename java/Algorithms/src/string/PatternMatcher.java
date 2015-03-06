package string;

/**
 * Created by swagat on 24/02/15.
 */
public class PatternMatcher {
    private final String text;
    private static final int ALPHABET_LENGTH = 256;

    public PatternMatcher(String text) {
        this.text = text;
    }

    /**
     * Assumes ASCII values in the string.
     *
     * @param pattern
     * @return
     */
    public int boyerMooreMatch(String pattern) {
        //Make last table
        int [] last = new int[ALPHABET_LENGTH];
        for (int i = 0 ; i < last.length ; ++i) {
            last[i] = -1;
        }

        int c;
        for (int i = 0 ; i < pattern.length() ; ++i) {
            c = (int) pattern.charAt(i);
            if (c >= 0 && c< 256){
                last[c] = i;
            }
            else {
                return -1;
            }
        }

        int[] goodSuffix = new int[pattern.length()];

        //Start matching
        int s, j;
        for (s = 0 ; s < (text.length() - pattern.length()) ; ) {
            j = pattern.length() - 1;
            while (j >= 0 && text.charAt(s + j) == pattern.charAt(j)) {
                j--;
            }
            if (j < 0) {
                return s;
            }
            int lastIndex = last[text.charAt(s + j)];
            s += Math.max(goodSuffix[j], j - lastIndex);
        }

        return -1;
    }

    public int kmp(String pattern) {
        /**
         * Preprocessing
         *
         * Generate the F[j] array. F[j] represents the length of the longest proper prefix of pattern[1...j] which is also a suffix of pattern[1...j].
         */
        int [] F = new int[pattern.length() + 1];
        F[0] = -1;
        F[1] = 0;
        for (int j = 2 ; j <= pattern.length() ; ++j) {
            int prev = j - 1;
            while(F[prev] > 0) {
                if (pattern.charAt(F[prev]) == pattern.charAt(j - 1)) {
                    F[j] = F[prev] + 1;
                    break;
                }
                else {
                    prev = F[prev];
                }
            }
            if (F[prev] <= 0) {
                if (pattern.charAt(0) == pattern.charAt(j - 1)) {
                    F[j] = 1;
                }
                else {
                    F[j] = 0;
                }
            }
        }

        /**
         * Create the state machine.
         *
         * Number of states = m + 1.
         * Number of symbols = |alphabet| or number of distinct characters in the pattern.
         *
         * Assuming pattern only has ASCII or extended ASCII.
         * Using # as the character representing every character not a part of pattern.
         */
        int nStates = pattern.length() + 1;
        boolean [] charInPattern = new boolean[256];
        int uniqueCharCount = 0;
        for (char c : pattern.toCharArray()) {
            if (!charInPattern[c]) {
                charInPattern[(int) c] = true;
                uniqueCharCount++;
            }
        }
        int [][] state = new int[nStates][256];
        for (int i = 1 ; i < pattern.length() ; ++i) {
            state[0][pattern.charAt(i)] = 0;
        }
        state[0][pattern.charAt(0)] = 1;
        for (int j = 1 ; j < pattern.length() ; ++j) {
            for (char c : pattern.toCharArray()) {
                if (c == pattern.charAt(j)) {
                    state[j][c] = j + 1;
                }
                else {
                    state[j][c] = state[F[j]][c];
                }
            }
            state[j]['#'] = 0;
        }
        for (char c : pattern.toCharArray()) {
            state[pattern.length()][c] = state[F[pattern.length()]][c];
        }
        state[pattern.length()]['#'] = 0;

        /**
         * Run the state machine.
         */
        int curState = 0;
        for (int i = 0 ; i < text.length() ; ++i) {
            char c = text.charAt(i);
            if (charInPattern[c]) {
                curState = state[curState][c];
            }
            else {
                curState = state[curState]['#'];
            }

            if (curState == pattern.length()) {
                System.out.println("Found match at : " + i);
            }
        }

        /*
        This is an alternative trivial-like approach.

        int s = 0;

        while (s <= (text.length() - pattern.length())) {
            int j = 0;
            while (j < pattern.length() && text.charAt(s + j) == pattern.charAt(j)) {
                ++j;
            }
            if (j == pattern.length()) {
                return s;
            }
            else {
                s += (j - F[j]);
            }
        }*/

        return -1;
    }
}
