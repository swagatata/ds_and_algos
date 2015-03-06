package algorithm.sort;

import java.util.ArrayList;
import java.util.List;

/**
 * Created with IntelliJ IDEA.
 * User: swagat
 * Date: 4/18/14
 * Time: 10:08 AM
 * To change this template use File | Settings | File Templates.
 */
public class BinarySearcher<T extends Comparable> {
    private T [] array;

    BinarySearcher(T [] sortedArray) {
        array = sortedArray;
    }

    public int searchKey(Comparable<T> key) {
        return searchKeyRecursive((T) key, 0, array.length);
    }

    /*
     * endIndex denotes 1 + the index of the last element.
     *
     * All indices are wrt the complete array.
     */
    private int searchKeyRecursive(T key, int startIndex, int endIndex) {
        int arraySize = endIndex - startIndex;

        int midIndex = startIndex + (arraySize / 2);

        //Works only for primitive types.
        if (array[midIndex] == key) {
            return midIndex;
        }

        if (arraySize == 1) {
            return -1;
        }

//        if (key.) {
//            return searchKeyRecursive(key, midIndex + 1, endIndex);
//        }


        return arraySize;
    }

    public int searchFirstIndexOfKey(T key) {

        return 0;
    }

    public int searchStrictlyGreater(T key) {
        //The first condition is for a specific linkedIn interview problem.
        if ((array.length == 1) ||
            (array[0].compareTo(key) == -1) ||
            (array[array.length - 1].compareTo(key) == 1)) {
            return 0;
        }

        int start = 0, end = array.length - 2;

        do {
            int mid = start + (end - start)/2;
            if (array[mid].compareTo(key) <= 0) {
                if (array[mid + 1].compareTo(key) > 0) {
                    return mid + 1;
                }
                else {
                    start = mid + 1;
                }
            }
            else {
                end = mid - 1;
            }
        }
        while (start <= end);

        return 0;
    }

    public static void searchStrictlyGreaterTest() {

        List<Character []> testCaseList = new ArrayList<>();
        List<Character> keyList = new ArrayList<>();
        List<Character> ansList = new ArrayList<>();

        testCaseList.add(new Character[]{'c', 'f', 'j', 'p', 'v'});
        keyList.add('a');
        ansList.add('c');

        testCaseList.add(new Character[]{'c', 'f', 'j', 'p', 'v'});
        keyList.add('c');
        ansList.add('f');

        testCaseList.add(new Character[]{'c', 'f', 'j', 'p', 'v'});
        keyList.add('k');
        ansList.add('p');

        testCaseList.add(new Character[]{'c', 'f', 'j', 'p', 'v'});
        keyList.add('z');
        ansList.add('c');

        BinarySearcher<Character> bs = null;
        Character [] testCase = null;
        Character key = null, ans = null;
        for (int i = 0 ; i < testCaseList.size() ; ++i) {
            System.out.println(i);

            testCase = testCaseList.get(i);
            key = keyList.get(i);
            ans = ansList.get(i);

            bs = new BinarySearcher<>(testCase);
            assert (testCase[bs.searchStrictlyGreater(key)] == ans);
        }
    }
}
