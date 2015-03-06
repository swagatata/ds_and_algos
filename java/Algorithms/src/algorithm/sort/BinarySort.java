package algorithm.sort;

/**
 * Created with IntelliJ IDEA.
 * User: swagat
 * Date: 2/17/14
 * Time: 2:57 PM
 * To change this template use File | Settings | File Templates.
 */
public class BinarySort {
    int [] binaryArray;

    public BinarySort(int [] binaryArray) {
        this.binaryArray = binaryArray;
    }

    /*
    The assumption here is that there are a series of positive integers followed by a series of negative integers.
     */
    public void seggregatedSort() {
        int index, value;

        index = 0;
        value = binaryArray[index];

        int n = 0, p = 0;
        while(binaryArray[p] >= 0) {
            ++p;
        }

        while((p + n) < binaryArray.length) {
            ++n;
        }

        recursiveBSort(0, p, n);

        for (int ele : binaryArray) {
            System.out.print(String.valueOf(ele) + " ");
        }
    }

    private void recursiveBSort(int start_i, int p, int n) {
        int i = 0;
        if (p == n) {
             while(i < p) {
                 swap(binaryArray, start_i + i, start_i + p + i);
                 ++i;
             }
        }
        else if (n < p) {
            recursiveBSort(start_i + p - n, n, n);
            recursiveBSort(start_i, p -n, n);
        }
        else {
            recursiveBSort(start_i, p, p);
            recursiveBSort(start_i + p, p, n - p);
        }
    }

    private void swap(int [] arr, int a_i, int b_i) {
        int temp = arr[b_i];
        arr[b_i] = arr[a_i];
        arr[a_i] = temp;
    }
}
