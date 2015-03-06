package algorithm.sort;

import java.util.Random;
import java.util.stream.IntStream;

/**
 * Created by swagat on 21/02/15.
 */
public class RBGSort {
    public enum RGB {
        RED, GREEN, BLUE;
    }

    /**
     * Implementation of the 3-way partitioning solution to the Dutch National Flag problem.
     *
     * @param array
     */
    public static void rbgSortDNF(RGB[] array) {
        /*
            Explanation :

            i represents the index of the next RED slot.
            k represents the index of the next BLUE slot, starting from the right.

            j increases 1 by 1. if RED, swaps with i, if BLUE, swaps with k.
         */

        int i = 0, j = 0, k = array.length - 1;

        RGB temp = null;
        while(j <= k) {
            switch (array[j]) {
                case RED:
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                    i++;j++;
                    break;
                case BLUE:
                    temp = array[k];
                    array[k] = array[j];
                    array[j] = temp;
                    k--;
                    break;
                case GREEN:
                    j++;
                    break;
            }
        }
    }

    public static void rbgSort2(RGB[] array) {
        int rStart = 0, rIndex = 0;
        int bStart = array.length - 1, bIndex = bStart;

        while (array[rIndex] != RGB.RED && rIndex < array.length - 1) {
            rIndex++;
        }

        while (array[bIndex] != RGB.BLUE && bIndex > -1) {
            bIndex--;
        }

        RGB temp = null;
        while (rIndex < array.length && bIndex > -1) {
            temp = array[rStart];
            array[rStart] = array[rIndex];
            array[rIndex] = temp;

            temp = array[bStart];
            array[bStart] = array[bIndex];
            array[bIndex] = temp;

            rStart++; bStart--;

            if (rIndex <= rStart) rIndex = rStart + 1;
            while (rIndex < array.length - 1 && array[rIndex] != RGB.RED) {
                rIndex++;
            }

            if (bIndex >= bStart) bIndex = bStart - 1;
            while (bIndex > -1 && array[bIndex] != RGB.BLUE) {
                bIndex--;
            }
        }
    }

    public static void test() {
        RGB[] array = new RGB[10];

        RGB [] ref = {RGB.RED, RGB.GREEN, RGB.BLUE};

        Random r = new Random();
        IntStream.range(0, array.length).forEach(n -> array[n] = ref[r.nextInt(3)]);

        IntStream.range(0, array.length).forEach(n -> System.out.println(array[n]));
        System.out.println("-------------");
        rbgSortDNF(array);
        IntStream.range(0, array.length).forEach(n -> System.out.println(array[n]));
    }
}
