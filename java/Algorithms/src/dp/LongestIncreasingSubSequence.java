package dp;

import java.util.*;

/**
 * Created by swagat on 26/02/15.
 */
public class LongestIncreasingSubSequence {
    private final int[] array;

    public LongestIncreasingSubSequence(int[] array) {
        this.array = array;
    }

    /**
     * Assumes elements in array are unique.
     *
     * @return
     */
    public int [] efficientLSI() {
        //At any point in time, M[j] represents the index k of the smallest number where
        //a subsequence of length j ends.
        int [] M = new int[array.length];

        //prev[i] represents the index of the previous element in the LIS which ends at i.
        int [] prev = new int[array.length];

        //Number of correct values in M.
        int m;

        M[0] = -1; M[1] = 0;
        prev[0] = -1;
        m = 1;

        for (int i = 1 ; i < array.length ; ++i) {
            //Find a previous sequence to which, this could be added.
            //If no such sequence get -1.
            if (array[M[m]] < array[i]) {
                M[m + 1] = i;
                prev[i] = M[m];
                m++;
            }
            else {
                int start = 1, end = m - 1, mid = 0;
                while (start <= end) {
                    mid = start + (end - start) / 2;
                    if (array[M[mid]] < array[i]) {
                        if (array[M[mid + 1]] > array[i]) {
                            break;
                        }
                        else {
                            start = mid + 1;
                        }
                    }
                    else {
                        end = mid - 1;
                    }
                }
                if (start > end) {
                    if (array[i] < array[M[1]]) {
                        M[1] = i;
                    }
                    prev[i] = -1;
                }
                else {//Found a previous subsequence for ith element.
                    prev[i] = M[mid];
                    if (array[i] < array[M[mid + 1]]) {
                        M[mid + 1] = i;
                    }
                }
            }
        }

        int end = M[m];
        Stack<Integer> lis = new Stack<>();
        do {
            lis.add(end);
            end = prev[end];
        }
        while (end != -1);

        while (!lis.empty()) {
            System.out.print(array[lis.pop()] + " ");
        }

        return new int[0];
    }

    public static void test() {
        int [] arr = {5, 2, 8, 6, 3, 1, 9, 7};
        LongestIncreasingSubSequence lis = new LongestIncreasingSubSequence(arr);
        lis.efficientLSI();

        arr = new int[]{-5, 2, -8, 6, -3, 1, 9, 7};
        lis = new LongestIncreasingSubSequence(arr);
        lis.efficientLSI();
    }
}
