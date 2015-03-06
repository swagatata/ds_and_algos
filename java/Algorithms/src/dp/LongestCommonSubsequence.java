package dp;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

/**
 * Created by swagat on 26/02/15.
 */
public class LongestCommonSubsequence {
    private final List b;
    private final List a;

    public LongestCommonSubsequence(List a, List b) {
        this.a = a;
        this.b = b;
    }

    public List lcsDP() {
        if (a.size() == 0 || b.size() == 0) {
            return null;
        }

        //Build lcsLengths matrix.
        int [][] lcsLengths = new int[a.size() + 1][b.size() + 1];
        //initialize.
        for (int i = 0 ; i <= a.size() ; ++i) {
            lcsLengths[i][0] = 0;
        }
        for (int i = 0 ; i <= b.size() ; ++i) {
            lcsLengths[0][i] = 0;
        }
        for (int i = 1 ; i <= a.size() ; ++i) {
            for (int j = 1 ; j <= b.size() ; ++j) {
                if (a.get(i - 1).equals(b.get(j - 1))) {
                    lcsLengths[i][j] = lcsLengths[i-1][j-1] + 1;
                }
                else {
                    lcsLengths[i][j] = Math.max(lcsLengths[i-1][j], lcsLengths[i][j-1]);
                }
            }
        }

        int lcsLength = lcsLengths[a.size()][b.size()];
        System.out.println("Length of LCS : " + lcsLength);

        //Backtracking to find the longest common subsequence.
        List lcs = new ArrayList<>();
        int [] lcsAIndices = new int[lcsLength];
        int [] lcsBIndices = new int[lcsLength];
        int a_i = a.size(), b_i = b.size();
        int lcsLengthLeft = lcsLength;
        do {
            if (a.get(a_i - 1).equals(b.get(b_i - 1))) {
                lcs.add(0, a.get(a_i - 1));

                a_i--;
                b_i--;

                lcsLengthLeft--;
                lcsAIndices[lcsLengthLeft] = a_i;
                lcsBIndices[lcsLengthLeft] = b_i;
            } else {
                if (lcsLengths[a_i][b_i] == lcsLengths[a_i - 1][b_i]) {
                    a_i--;
                } else {
                    b_i--;
                }
            }
        }while (a_i < b_i);

        return lcs;
    }

    public List<List> allLCSs() {

        return null;
    }
}
