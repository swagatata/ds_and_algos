package tree;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;

/**
 * Created by swagat on 17/02/15.
 */
public class BinaryTree<T> {
    private T data;

    public BinaryTree<T> left;
    public BinaryTree<T> right;

    BinaryTree() {

    }

    BinaryTree(T t) {
        data = t;
    }

    public T getData() {
        return data;
    }

    public void setData(T data) {
        this.data = data;
    }

    public static <Type extends Integer> BinaryTree<Integer> buildTree(int nNodes) {
        int nLeafNodes = (nNodes / 2) + 1;

        Random r = new Random();

        Queue<BinaryTree> levelQ = new LinkedList();

        //Creating leaf nodes
        BinaryTree<Integer> binaryTree = null;
        for (int i = 0 ; i < nLeafNodes ; ++i) {
            binaryTree = new BinaryTree<Integer>(r.nextInt() % nNodes);
            levelQ.add(binaryTree);
        }

        while (levelQ.size() > 1) {
            int nNodesInLevel = levelQ.size();

            for (int i = 0 ; i < nNodesInLevel ; ++i) {
                if ((i & 1) != 0) {
                    BinaryTree parent = new BinaryTree<Integer>(r.nextInt() % nNodes);
                    parent.left = levelQ.remove();
                    parent.right = levelQ.remove();

                    levelQ.add(parent);
                }
            }

            if ((nNodesInLevel & 1) != 0) {
                BinaryTree parent = new BinaryTree<Integer>(r.nextInt() % nNodes);
                parent.left = levelQ.remove();
                levelQ.add(parent);
            }
        }

        return levelQ.remove();
    }
}
